#dap1 

## Graphen

Ein ***Graph*** ist eine Sammlung von $n$ **Knoten $V$** und $m$ **Kanten** (mit Verbindungen $E$ zwischen diesen Knoten)
- Knoten der Einfachkeit halber bezeichnet mit $V = \{ 0,\dots,n-1 \}$
  
- **gerichtete Graphen:** Kanten $(a,b)$ bedeuten Verbindung von $a \in V$ ==*nach*== $b \in V$:
	  $E \underline{\subset} V \times V$ 
	alternative Schreibweise: $a \to b$
- **ungerichtete Graphen:** Kanten $\{ a,b \}$ bedeuten Verbindungen ==*zwischen*== $a \in V$ und $b \in V$:
	  $E \underline{\subset} \{ \{ a,b \} : a,b \in V \}$
	alternative Schreibweisen: $a \leftrightarrow b$ oder $a - b$

- **gewichtete Kanten:** zusätzliche *Funktionen* $E \to U$ für einen *Gweichtstyp* $U$

>[!note] Beispiel: VRR-Netz
>![[Pasted image 20260122143459.png]]
>___
>**Graphenmodellierung** (ausschnitt)
>![[Pasted image 20260122143701.png]]

#### Computermodellierung Graphen

- ***Adjazenz==liste==:***
	- jeder Knoten $v$ speichert *in einem Container* seinen **Nachbarn**, also die *Knoten $w$*, für die $(v, w) \in E$  bzw. $\{ v,w \} \in E$ gilt-
		- `class Graphnode { ResizableArray<Graphnote*> adj_list_; }`

- ***Adjzenz==matrix==*** - für statische Graphen:
	- ganzer Graph wird in **$n \times n$ -Matrix** gespeichert
		- z.B. vom Grundtyp *`bool`* für *ungewichtete Graphen*: `bool adj[n][n]`
		- oder vom Grundtyp *`int`* für *gewichtete Graphen* mit $U =$ `int`

- Alternative für *statische Graphen*: ***Adjazenz==array==***
	- *Konkatenation der Adjazenzlisten* zu einem **großen Array** `edges[0, m - 1]`
		- ein z*usätzliches Array* `ngbhrs[0, n - 1]` speichert in `ngbhrs[i]` für jeden Knoten $i \in$ `[0, n - 1]` den Beginn in `edges[0, m - 1]`

---

### Graphenknoten in C++ (mit Adjazenzliste)

Wir betrachten beispielhaft *Graphen*, in denen die **Knoten** nur **3 Dinge speichern**:
- einen String als *"Label"*
- eine eindeutige *Knotennummer*
- eine *Adjazenzliste* mit Zeigern auf die Nachbarknoten

```cpp
struct GraphNode {
	GraphNode(dap1::Mystring label = "", int nr = -1)
		: label_{label}, node_nr_{nr} {}
	
	void add_directed_edge(GraphNode* neighbor) { 
		adj_list_.push_back(neihgbor); 
	}
	
	dap1::MyString label_;
	int node_nr_;
	dap1::ResizableArray<GraphNode*> adj_list_; // meine Nachbarn
};
```

### Graphklasse in C++
```cpp
class Graph {
	dap1::ResizableArray<GraphNode*> nodes_;
	
	public:
		int n_; // #Knoten
		int m_; // #Kanten
		
		void add_node(dap1::MyString const& label) {
			nodes_.push_back(new GraphNode(label, n_++));
		}
		
		// füre Kante von Knoten i zu Knoten j hinzu (ungerichtet)
		void add_undirected_edge(int i, int j) {
			nodes_[i]->add_directed_edge(nodes_[j]);
			nodes_[j]->add_directed edge(nodes_[i]);
			++m_;
		}
		
		Graph() : n_{0}, m_{0} {};
		
		//...
};
```

---

## Algorithmen auf Graphen

### Graphenexploration - Depth First Sea