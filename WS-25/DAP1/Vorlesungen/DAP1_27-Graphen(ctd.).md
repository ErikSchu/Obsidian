#dap1 

## Graphenexplotation - Depth First Seach (DFS)
⤷ siehe [[DAP1_26-Graphen]]

### Tiefensuche iterativ
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
			visited[v->node_nr_]
		}
	}
}
```