---
kurs: DAP2
dozent: Amin Coja-Oghlan
themengebiet: Minimal spannende Bäume
tags: [dap2, kruskal, prim, greedy, metrisches-tsp]
---

#dap2 #kruskal #prim #greedy #metrisches-tsp

> [!summary] Klausur-Kurzfassung
> - **Kruskal:** Sortieren → Union-Find, $O(|E| \log |E|)$
> - **Prim:** Startknoten → PQ, $O(|E| \log |V|)$
> - **Greedy:** Funktioniert hier, aber nicht allgemein
> - **Metrisches TSP:** Tour ≥ MSB, Tour ≤ 2 · MSB

___

→ Jeder zusammenhängende Graph besitzt einen spannenden Baum
→ In einem gewichteten Graphen sind wir interessiert an einem *minimalen* spannenden Baum
→ dazu der ***Greedy-Algorithmus***

>[!def] Definition
>- ein **gewichteter Graph** ist ein Graph $G = (V, E)$ zusammen mit einer Funktion $c : E \to \mathbb{Q}_{\ge 0}$.
>- das **Gewicht** einer Kantenmenge $F \subseteq E$ ist $$ \sum_{e \in F}  c (e)$$
>- ein **minimal spannender Baum** von $G$ ist ein spannender Baum $T = (V, E_{T})$ von $G$ mit $$c(E_{T}) = \text{min} \{ c(E_{B}) : B = (V, E_{B}) \text{ ist sp. Baum von } G  \}$$

- für algorithmische Zwecke nehmen wir stets an, dass die Gewichtungsfunktion $c$  rationale Werte annimmt 
	- diese rationalen Werte werden dann exakt eingegeben, d.h. als Paare ganzer Zahlen $$(\text{Zähler, Nenner})$$
- äquivalent können wir annehnen, dass alle Gewichte ganzzahlig sind

___

## Kruskalalgorithmus

>[!note] Algorithmus
>1. prüfe, ob $G$ zusammenhängend ist; wenn nicht, gib eine Fehlermeldung aus 
>2. sortiere die Kanten $G$ aufsteigend nach Gewichten: $$c(e_{1}) \le c(e_{2}) \le \cdots \le c(e_{m})$$
>3. initialisiere $T = (V, \emptyset)$
>4. für $i = 1, \dots, m$
>	1. wenn $e_{i}$ verschiedene Komponenten von $T$ verbindet, füge $e_{i}$ zu $T$ hinzu
>5. gib $T$ aus

- Schritt 1 kann man mit [[Bäume_Wälder_Breiten-&Tiefensuche|Tiefensuche]] in Zeit $O(\lvert E \rvert + \lvert V \rvert)$ durchgeführt werden
- für Schritt 2 verwenden wir [[Heapsort_priority-queues|Heapsort]]; Laufzeit $O(\lvert E \rvert \log \lvert E \rvert)$
- für Schritt 4 führen wir Buch über die Komponenten von $T$
	- dabei führen wir die Komponentengrößen mit 
	- jedes Mal, wenn eine Kante hinzugefügt wird, wird die *kleinere* Komponente zur größeren hinzugefügt

>[!tip] Satz 
>Sei $G, c$ ein Zusammenhängender gewichteter Graph (mit rationalen Gewichten).
>- Kruskal hat Laufzeit $O(\lvert E \rvert \log \lvert  E \rvert)$
>- gibt einen minimal spannenden Baum aus 

>[!abstract] Korrektheitsbeweis (Skizze)
>1. **Kreisfreiheit:** Kruskal fügt nur Kanten hinzu, die verschiedene Komponenten verbinden → keine Kreise
>2. **Zusammenhang:** Da $G$ zusammenhängend ist, wird am Ende nur eine Komponente übrig bleiben
>3. **Minimales Gewicht:** Widerspruchsbeweis – annimme es gibt einen billigeren MSB → man kann eine Kante tauschen und ein contradictions

___

## Prim-Algorithmus

>[!note] Algorithmus
>1. Für alle $u \in V(G)$ setze $c(u) = \infty$, $p(u) = \emptyset$
>2. Setze $c(s) = 0$ und $Q = V(G)$
>3. Solange $Q \neq \emptyset$
>	1. finde $v \in Q$ mit minimalem $c(v)$ und entferne $v$ aus $Q$
>	2. für alle $u \in Q \cap \partial_G v$
>	3. falls $c(\{u, v\}) < c(u)$, setze $c(u) = c(\{u, v\})$ und $p(u) = v$
>4. Gib die Kantenmenge $\{\{v, p(v)\} : p(v) \neq \emptyset\}$ aus

>[!tip] Satz 
>Angenommen $G, c$ ist ein zusammenhängender gewichteter Graph. Dann gibt $\text{Prim}(G, c)$ die Kantenmenge eines minimalen Spannbaums von $G$ aus.

>[!tip] Laufzeit
>- Die Menge $Q$ kann mit Hilfe einer [[Heapsort_priority-queues|min Priority Queue]] implementiert werden
>- Schritt (2) fügt die Knoten in die PQ ein; alle bis auf den Startknoten haben dasselbe Gewicht
>- Schritt (3.1) entfernt jeweils das Minimum aus der Queue
>- Schritt (3.3) reduziert das Gewicht einiger Nachbarn von $v$
>- Laufzeit: $O(\lvert E(G) \rvert \log \lvert V(G) \rvert)$

___

## Anwendung: metrisches TSP

- wir befassen uns mit einem **Spezialfall des TSP**
- sei $G, w$ ein vollständiger gewichteter Graph
- angenommen die *Gewichte erfüllen die Dreiecksungleichung*, d.h. für alle $x, y, z \in V(G)$ gilt $$w(\{ x, z \}) \le w(\{ x, y \}) + w (\{ y, z \})$$
- man spricht vom ***metrischen TSP***

>[!tip] Proposition
>Die Länge einer optimalen metrischen TSP-Tour ist
>- mindestens so hoch wie das Gewicht eines optimalen Spannbaums von G, w
>- nicht mehr als doppelt so hoch wie das Gewicht eines optimalen Spannbaums von $G, w$

___

## Klausur-Checkliste

- [ ] Kann ich die Definition von gewichteten Graphen und MSB aufschreiben?
- [ ] Kann ich Kruskals 5 Schritte benennen?
- [ ] Kann ich die Laufzeiten von Kruskal und Prim herleiten?
- [ ] Kann ich den Korrektheitsbeweis von Kruskal skizzieren?
- [ ] Kann ich die Dreiecksungleichung beim metrischen TSP anwenden?
- [ ] Kann ich die Proposition zur 2-Approximation beweisen?
