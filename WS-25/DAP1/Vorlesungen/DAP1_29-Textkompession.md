#dap1 

#### Klausur

- Wir tragen die Studienleistung bald ein – dann können Sie sich anmelden
- Stud. mit **Nachteilsausgleich** Email an dap1.cs@tu-dortmund.de
    - ebenso Schülerstud.
- Weitere Infos zur Klausur folgen per Moodle-Ankündigung
- bitte bereits 10 Minuten vor Beginn am Hörsaal sein
- Mitbringen:
    - Lichtbildausweis
    - Klausurzettel **mit Matrikelnummer** (damit **Sie** sie wissen!!)
        - doppelseitiges, handbeschriebenes und ohne Hilfsmittel lesbares DIN-A4-Blatt
    - Stift: dunklen Kugelschreiber oder Fineliner
    - **keine Handys, Armbanduhren, oder sonstige mechanischen oder elektronischen Geräte**

# Textkompression

>[!example] Problemstellung
>Textdateien sind oft zu groß. Wie kann man diese ***komprimieren***?
>___
>⤷ Anwendungsszenarien
>- Platz auf Festplatte/SSD/... sparen
>	- zur Archivierung
>	- bei hochredundanten Daten, z.B. log-Files
>- Transport von Daten, insbes. über netzwerke

## Lempel-Ziv-78

Ein von *Abraham Lempel* und *jacob Ziv* 1978 entwickeltes **Kompressionsverfahren**
⤷ eingesetzt in GIF, PDF, compress, ...

***Idee:*** nutze aus, wenn sich Teilstrings wiederholen (z.B. $T = \text{anatanarivo}$ (Hauptstadt von Madagaskar))

Ein ***Trie*** ist ein gewurzelter Baum
- Knoten nummeriert
- Kanten mit *Buchstaben* beschriftet
- $s(v)=$ String, der sich aus der Kantenbeschriftung von der Wurzel zu $v$ ergibt

>[!note] Algorithmus zur Kompression von $T[0,n], T[n]= 0$:
>1. Starte mit Trie, der nur aus der Wurzel besteht (Nummer 0)
>2. Sei $T[0, i-1]$ bereits komprimiert (am Anfang $i = 0$)
>3. Suche das *längste Präfix* $T[i,j]$ von $T[i,n]$, für das es einen Knoten $v$ im Trie mit $s(v) = P$ ibt
>	- füge neuen Knoten $w$ als Kind von $v$ an
>		- $w$ erhält die kleinste noch nicht vergebene Nummer 
>		- beschrifte Kante $(v,w)$ mit $T[j+1]$
>	- gib Paar (Knotennummer von $v$, $T[j+1]$) aus; damit ist $T[0, j+1]$ komprimiert; gehe zurück zu 1.

>[!attention] .
>LZ78 gibt eine Folge $(n_{i}, c_{i})$ von $z$ Paaren (Knotennummer, Buchstabe) aus, so dass $$T = s(n_{1})c_{1} \ s(n_{2})c_{2} \ \dots \ s(n_{z})c_{z}$$


#### Ist das reversibel (d.h. dekomprimierbar)?

Ja! Einfach den Algorithmus simulieren!
>[!question] Quiz
>Welcher String wird durch $$(0,m), (0,i), (0,s), (3,i), (3,s), (2,p), (0, p), (2, 0)$$LZ78-komprimiert (Eingabe ohne das 0-Byte am Ende)?
>⇒ `mississippi`


___

## Code Kompression
```cpp
struct TrieNode {
  dap1::Map<char, TrieNode*> children_;
  int node_nr_;

  TrieNode(int nr = -1) : node_nr_{nr} {}
};

class LZTrie {
  TrieNode* root_;
  int nr_nodes_;

 public:
  LZTrie() : root_{new TrieNode(0)}, nr_nodes_{1} {}

  int size() const { return nr_nodes_; }

  TrieNode* get_root() const { return root_; }

  // insert new child of where with char c:
  TrieNode* insert(TrieNode* where, char c) {
    TrieNode* new_node = new TrieNode(nr_nodes_++);
    where->children_[c] = new_node;
    return new_node;
  }
};
```
```cpp
int main() {
  FILE* file = fopen("faust.txt", "r");
  FILE* out_file = fopen("faust.lz8", "w");
  LZTrie trie;
  TrieNode* current = trie.get_root();
  for (char c = fgetc(file); feof(file) == 0; c = fgetc(file)) {
    TrieNode* child = current->children_.at(c);
    if (child) {
      // next character already in trie => descend:
      current = child;
    } else {
      // phrase finished => write phrase to file:
      fwrite(&current->node_nr_, sizeof(int), 1, out_file);
      fwrite(&c, sizeof(char), 1, out_file);
      trie.insert(current, c);
      current = trie.get_root();
    }
  }
  if (current) {
    // write last phrase
    fwrite(&current->node_nr_, sizeof(int), 1, out_file);
    char c = 0;
    fwrite(&c, sizeof(char), 1, out_file);
  }
  printf("Done. Trie contains %i nodes\n", trie.size());
  fclose(file);
  fclose(out_file);
}
```

## Code Dekompression
```cpp
struct TrieNode {
  dap1::Map<char, TrieNode*> children_;
  TrieNode* parent_;
  char c_;
  int node_nr_;

  TrieNode(int nr = -1, TrieNode* parent = nullptr, char c = 0)
      : parent_{parent}, c_{c}, node_nr_{nr} {}
};

class LZTrie {
  TrieNode* root_;
  int nr_nodes_;

 public:
  LZTrie() : root_{new TrieNode(0)}, nr_nodes_{1} {}

  TrieNode* get_root() const { return root_; }

  TrieNode* insert(TrieNode* where, char c) {
    TrieNode* new_node = new TrieNode(nr_nodes_++, where, c);
    where->children_[c] = new_node;
    return new_node;
  }

  int size() const { return nr_nodes_; }
};
```
```cpp
void write_phrase(TrieNode* node, FILE* out_file) {
  if (!node || node->node_nr_ == 0) return;

  // recurse to root to output in correct order
  write_phrase(node->parent_, out_file);
  fwrite(&node->c_, sizeof(char), 1, out_file);
}

int main() {
  FILE* file = fopen("faust.lz8", "r");
  FILE* out_file = fopen("faust_dec.txt", "w");

  LZTrie trie;

  dap1::ResizableArray<TrieNode*> nodes;
  nodes.push_back(trie.get_root());  // node 0

  while (true) {
    int index;
    char c;

    if (fread(&index, sizeof(int), 1, file) != 1) break;
    if (fread(&c, sizeof(char), 1, file) != 1) break;

    TrieNode* parent = nodes[index];

    // output phrase
    write_phrase(parent, out_file);
    if (c != 0) {
      fwrite(&c, sizeof(char), 1, out_file);
      TrieNode* node = trie.insert(
```