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
1. 