#dap1 

## Graphenexplotation - Depth First Seach (DFS)
⤷ siehe [[DAP1_26-Graphen]]

### DFS iterativ

```text
- s.push(startknoten)
- solange s nicht leer ist:
	- v <- s.pop()
	- falls v unmarkiert ist
		- markiere v
		- für alle zu v adjazenten Knoten w:
			- s.push(w)
```
```cpp
void dfs_iter(int startknoten) {
	bool* visited = new bool[n_])() // store nodes already stacked
	
	dap1::MyStack<GraphNode*> s;
	s.push(notes_[startknoten]); // start at startknoten ...
	while (!s.is_empty()) {
		GraphNode* v = s.pop(); // go to next node
		if(!visited[v->node_nr_]) {
			visited[v->node_nr_] = true;
			for (GraphNode* w : v->adj_list_) {
				s.push(w);
			}
		}
	}
	
	delete[] visited;
}
```

### DFS rekursiv

```cpp
class Graph {
	// ...
	public: 
		void dfs() {                         // Tiefensuche rekursiv
			bool* visited = new bool[n_] {}; // Stand.-Init. mit 'false'
			dfs(nodes_[0], visited);         // starte rek. Aufruf
			delete[] visited;
		}
	
	private:
		void dfs(GraphNode* v, bool* visited) {
			if (!visited[v->node_nr_]) {
				visited[v->node_nr_] = true;
				for (GraphNode* w : v->adj_list_) {
					dfs(w, visited);
				}
			}
		}
}
```

___

## Spannbaum

Jede **Graphenexploration** ("-traversierung") *berechnet implizit* einen ***Spannbaum***
	Jeder Knoten kann von jedem anderen Knoten auf ***exakt einem Weg*** erreicht werden

![[Pasted image 20260127125636.png]]

___

## Graphenexploration - Breadth First Search (BFS)

Statt zuerst immer weiter in die Tiefe zu gehen: 
1. besuche **zunächst alle Nachbarn** vom Startknoten (und markiere sie)
2. dann besuche **alle noch unmarkierten Nachbarn** der in Schritt 1 *besuchten Knoten*
3. usw. *bis alle Knoten markiert*

Gute Nachricht: in ` dfs_iter() ` muss nur der *Stack* durch eine **Queue** ersetzt werden!

___

## Minimaler Spannbaum

Betrachten wir nun ***gewichtete Graphen***
	z.B. Reisezeit zwischen Stationen an den Kanten

Modifikation bei der Tiefen-(oder Breiten-)suche:
	ersetze den *Container* durch eine **Priority Queue** ` dap1::PQ<inr, std::pair<GraphNode*, int>>q(m) `
		`std::pair` ist eine (einfache) *Klasse zum Speichern zweier Elemente*
	beim Einfügen von w ist die Priorität der Summe aus 
		Distanz zum Aktuellen Knoten ` v(v.second) `
		Kantengewicht von ` (v,w) ` (in `v.first->edge_weights_`)

___

# Hashing
## Wdh.: der [[DAP1_21-Bäume|Mengen-ADT]] 

***Bisherige Lösung:*** Binärer Suchbaum (*vergleichsbasiert*!)
	***jetzt:*** direkt mit den **Werten** *der Schlüssel* arbeiten

## Hashing
Annahme $T$ = `int` 

>[!TIP] Idee
>hätten wir ein Array $H$ der Größe ` INT_MAX `, könnten wir ein Element $x$ in $H[x]$ speichern
- das ist unrealistisch ...

- daher ***Hashfunktion*** $h :$ `int->[0, m - 1]` $= \{ 0, 1, \dots, m-1 \}$ für einen **nicht zu großen** Wert $m$ ($m$ ist die *Größe* der Hashtabelle)
- dann ` insert(set_namem x) ` :  füge $x$ in $H[h(x)]$ ein 


#### Kollision

Anforderungen an die Hashfunktion $h$:
- soll mögl. *gleichmäßig* übre $[0, m-1]$ **streuen**
- soll mögl. **zufällig** sein 
- wir nutzen: $h(x) = ((a \cdot x) \text{ mod } p) \text{ mod } m$ für eine Primzahl $p \ge m$ und ein zufälliges $a \in [1, p-1]$

Trotzdem: ***Kollisionen** unvermeidbar* $(h(x) = h(y) \text{ für } x \ne y)$

Was ist, wenn in $H[h(x)]$ bereits ein Element steht?
- ***Linear Probing:*** wenn die Stelle $h(x)$ bereits belegt, dann gehe so lange nach 'rechts' ($h(x)+1, h(x)+2, \dots$), bis eine freie Stelle erreicht wird

Wir nutze ein zsl. `bool`-Array ` Used[0, m - 1] `, um belegte Stellen zu markieren


##### Implementierungstrick

Um bei dem **linear Probing** nicht immer '$\text{mod } n$' rechnen zu müssen, kann die Hashtabelle einen ***Overflow-Buffer*** erweitert werden.
- z.B. 1% der Gesamtgröße
- im Code ` overflow_buffer_size_ `


## Generische Hashtabelle: C++ 

Die **Hashtabelle** soll ***templatisiert*** über `<K,V>` sein 
	aber Hastfunktion vom Typ $K$ abh.
		hierfür bieten sich **Template-Spezialisierungen** an

```cpp
template <typename K>
int hash_value(K const& x, int m); // generische Funktionsdeklaration

unsigned in const p = (1u << 31) - 1; // Mersenne prime
unsi
```