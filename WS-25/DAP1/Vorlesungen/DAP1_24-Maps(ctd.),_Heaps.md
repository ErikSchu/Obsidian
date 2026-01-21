#dap1 
## Anwendung: Worthäufigkeiten

>[!example] .
>Schreibe ein Programm, das für einen Text $T$ eine Statistik über alle vorkommenden Wörter in $T$ erstellt, d.h. für alle Wörter $w \in T$ zählt, we oft $w$ in $T$ vorkommt-

- Beispiel
	- Eingabe:   ` T = To be or not to be, that is the question. `
	- Ausgabe:   ` TO : 1, be : 2, or : 1, not : 1, to: 1, ... `

## Map auf Basis von BST

```cpp
template <typename U, typename V> struct Map : public BST<KVPair<U, V>> {
	// operator[] for put:
	V& operator[](U const& key) {
		BSTNode<KVPair<U, V>>* where = BST<KVPair<U, V>>::find(KVPair<U, V>(key));
		if (!where) {
			where = BST<KVPair<U, V>>::insert(KVPair<U, V>(key));
		}
		return where->cont_.value_;
	}
	// read-only access:
	V at(U const& key) const {
		BSTNode<KVPair<U, V>>* where = BST<KVPair<U, V>>::find(KVPair<U, V>(key));
		if (where)
			return where->cont_.value_;
		else
			return {}; // Grund für 'return by value' (nicht Referenz)
	}
	bool find(U const& key) const {
		BSTNode<KVPair<U, V>>* where = BST<KVPair<U, V>>::find(KVPair<U, V>(key));
		if (where)
			return true;
		else
			return false;
	}
	void insert(KVPair<T, U>) = delete; // so können geerbte Funktionen gelöscht werden, falls gewünscht
};
```

___
## Anwendung: Worthäufigkeiten

>[!example] 
>Schreibe ein Programm, das für einen Text eine Statistik über alle vorkommenden Wörter in erstellt, d.h. für alle Wörter zählt, wie oft in vorkommt.

- Beispiel
	- Eingabe: `To be or not to be, that is the question.`
	- Ausgabe: `To be or not to that`

##### Lösung mit Map

```cpp
dap1::Map<dap1::MyString, int> freq; // map words to their frequencies

// walk through file and parse/count words:
FILE* in_file = fopen("faust.txt", "r");
dap1::MyString word;
for (unsigned char ch = fgetc(in_file); !feof(in_file); ch = fgetc(in_file)) {
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		word.append(ch); // word has more chars -- requires (simple) new member function void append(char) in MyString
	else { // finished reading word
		if (word.get_size() > 0) freq[word]++;
		word = "";
	}
}
fclose(in_file);
// print statistics:
int n = freq.get_size();
printf("File contains %i different words\n", n);
// print all using vector:
dap1::ResizableArray<dap1::KVPair<dap1::MyString, int>> sorted_alph = freq.get_sorted();
for (int i = 0; i < sorted_alph.get_size(); ++i)
	printf("%s: %i\n", sorted_alph[i].key_.c_str(), sorted_alph[i].value_);
```

⤷ Zusatzaufgabe: die häufigsten 10 Wörter ausgeben
⤷ ***Schwierigkeit:*** Paare nach Wert sortieren

// inherited from dap1::BST

___
## NB: `std::map` hat leicht anderes Interface

``` cpp
		return where->cont_.value_;
	}
	// read-only access:
	V at(U const& key) const {
		BSTNode<KVPair<U, V>>* where = BST<KVPair<U, V>>::find(KVPair<U, V>(key));
		if (where)
			return where->cont_.value_;
		else
			return {}; // Grund für 'return by value' (nicht Referenz)
	}
	bool find(U const& key) const {
		BSTNode<KVPair<U, V>>* where = BST<KVPair<U, V>>::find(KVPair<U, V>(key));
		if (where)
			return true;
		else
			return false;
	}
	void insert(KVPair<T, U>) = delete; // so können geerbte Funktionen gelöscht werden, falls gewünscht
};
```

___
## Anwendung: Worthäufigkeiten

>[!example] 
>Schreibe ein Programm, das für einen Text eine Statistik über alle vorkommenden Wörter in erstellt, d.h. für alle Wörter zählt, wie oft in vorkommt.

- Beispiel
	- Eingabe: `To be or not to be, that is the question.`
	- Ausgabe: `To be or not to that`

##### Lösung mit Map

```cpp
dap1::Map<dap1::MyString, int> freq; // map words to their frequencies

// walk through file and parse/count words:
FILE* in_file = fopen("faust.txt", "r");
dap1::MyString word;
for (unsigned char ch = fgetc(in_file); !feof(in_file); ch = fgetc(in_file)) {
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		word.append(ch); // word has more chars -- requires (simple) new member function void append(char) in MyString
	else { // finished reading word
		if (word.get_size() > 0) freq[word]++;
		word = "";
	}
}
fclose(in_file);
// print statistics:
int n = freq.get_size();
printf("File contains %i different words\n", n);
// print all using vector:
dap1::ResizableArray<dap1::KVPair<dap1::MyString, int>> sorted_alph = freq.get_sorted();
for (int i = 0; i < sorted_alph.get_size(); ++i)
	printf("%s: %i\n", sorted_alph[i].key_.c_str(), sorted_alph[i].value_);
```

⤷ Zusatzaufgabe: die häufigsten 10 Wörter ausgeben
	⤷ ***Schwierigkeit:*** Paare nach Wert sortieren

NB: `std::map` hat leicht anderes Interface

___
# Heaps & Priority Queues

## ADT Priority Queue ("Prioritätswarteschlange")

Eine ***Prioritätswarteschlange*** (engl. priority queue, "PQ") mit Schlüsseln vom Typ $K$ und Werten vom Typ $V$ hat folgende Operationen:

- **`init(pq_name, capacity, K, V)`**: *initialisiert* eine *leere PQ* mit Namen $Q$ für bis zu $N$ viele key-value-Paare vom Typ $(K,V)$
- **`push(pq_name, <k, v>)`**: *fügt* den Wert $x$ (vom Typ $V$) mit Schlüssel $k$ (vom Typ $K$) in $Q$ ein, *falls die Kapazität noch nicht erschöpft ist*
- **`extract_min(pq_name)`**: *löscht* ein *key-value-Paar* $(k,x)$ mit *minimalem Schlüsselwert* aus der PQ und *gibt es zurück* $((k,x))$
- **`is_empty(pq_name)`**: *gibt wahr zurück* gdw. $Q$ *leer* ist
- **`size(pq_name)`**: *gibt die Anzahl* der *key-value-Paare* in $Q$ zurück

Wie eine *Queue*, aber `pop` liefert die Elemente *aufsteigend geordnet* nach **"Priorität"**
analog: *Maximum-PQs* (absteigend geordnet)

> [!question] Quiz PriorityQueue
> In welcher Reihenfolge werden die Elemente durch folgende Operationen ausgegeben:
> ```
> - init(pq, 10, int, std::string)
> - push(pq, <2, hallo>)
> - push(pq, <1, du>)
> - gib den Wert von extract_min(pq) aus
> - push(pq, <2, da>)
> - gib den Wert von extract_min(pq) aus
> ```
> **A:** hallo du du 
> **B:** du hallo  
> **C:** hallo du  **$\checkmark$**
> **D:** du da  
> **E:** nicht eindeutig

___
## Heaps

ein **Min-Heap** (dt. Haufen/Halde) ist ein *binärer Baum* $B$ für $n$ *key-value-Paare* mit den **2** folgenden *Eigenschaften*:

1. ***Heap-Ordnung***: *der Schlüssel aller Knoten $v$* (außer der Wurzel) ist **nicht kleiner** als *der Schlüssel ihres Elters*
2. ***Vollständigkeit***: der **Baum $B$ ist vollständig**, d.h. *alle Tiefen* (bis auf die letzte) sind *voll besetzt*, und *die letzte Tiefe* ist ***"von links nach rechts" besetzt***

**Konsequenz:** ***minimaler Schlüssel an Wurzel***
*Heaps haben eine Höhe von* $\approx \log n$

___

## Array-Darstellung von Heaps

![[Pasted image 20260120134001.png]]

*"implizite Datenstruktur"*
- *Elter* von Knoten an Position $i$: $\lfloor i/2 \rfloor$
- *Kinder* von $i$ an Positionen $2i$ und $2i+1$ (falls vorhanden, d.h. $\leq n$)

___

> [!question] Quiz: Inhalt von `PQ<int> pq` mit `&pq=2` ?
> ```cpp
> template <typename T> class PQ {
> 	T* array_; int n_;
> public: PQ(int max_size) : array_ = new T[max_size + 1], n_{0} {}
> };
> ```
> **A:** (a)  
> **B:** (b)  
> **C:** (c)  
> **D:** (d)  
> **E:** nicht eindeutig

___

## Heap-Implementierung

```cpp
namespace dap1 {
template <typename K, typename V>
class PQ {
	struct KVPair { // private "innere Klasse"
		K key_;
		V value_;
		KVPair(K const& key = {}, V const& val = {}) : key_{key}, value_{val} {}
		// implement operators to use keys:
		bool operator<(KVPair const& other) const { return key_ < other.key_; }
		bool operator==(KVPair const& other) const { return key_ == other.key_; }
	};
	KVPair* array_;
	int n_;
	// ...
};
```

⤷ **NB:** `KVPair` ist eine ***innere Klasse*** von `PQ` (ansonsten wie bei Map)
⤷ d.h. kann *nur innerhalb von* `PQ` benutzt werden
⤷ ist *generisch* (Typen $U,V$), aber *innerhalb von* `PQ ohne Template-Parameter benutzbar* (`KVPair` und nicht `KVPair<U,V>`)

___

## Heap-Operationen

durch *die Höhe* $O(\log n)$ implementieren *Heaps* den ADT PQ *schnell*:
- `push`: $O(\log n)$
- `extract_min`: $O(\log n)$

___

## PQ-Operationen mit Heaps in C++

```cpp
public:
PQ(int capacity) : array_{new KVPair[capacity + 1]}, n_{0} {} // Konstruktor
```

```cpp
public:
void push(K const& k, V const& v) {
	// erzeuge "neuen Knoten" als neues letztes Blatt:
	array_[++n_] = KVPair(k, v);
	// jetzt Heap-Bedingung wiederherstellen:
	sift_up(n_);
}
private:
void sift_up(int k) {
	while (k > 1 && array_[k] < array_[k / 2]) {
		swap(k, k / 2);
		k = k / 2;
	}
}
```

```cpp
public:
V extract_min() {
	// nächste VL
}
```

```cpp
// swap array_[i] with array_[j]
void swap(int i, int j) {
	T tmp = array_[i];
	array_[i] = array_[j];
	array_[j] = tmp;
}
```

