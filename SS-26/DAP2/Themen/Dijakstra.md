
- Ermittlung kürzester Pfade
- effiziente Implementation mittels *priority queues*
- Expliziter Algorithmus für das travelling salesman problem

>[!info] Das kürzeste-Pfade-Problem
>- Gegeben ein *gewichteter Graph* $G, c$
>	- d.h. $c : E(G) \to \mathbb Q \ge 0$
>- ferner sind zwei Knoten $s, t$ gegeben
>- Ziel ist, einen kürzesten Pfad von $s$ nach $t$ zu finden 
>- die ***Länge*** des Pfades $p = (v_{0}, \dots, v_{l})$ ist dabei definiert als $$\boxed{ c(p) = \sum^L_{I = 1} c(v_{i-1}v_{i}) }$$

## Der Dijakstra-Algorithmus
- Basiert auf dem **Paradigma der dynamischen Programmierung**
- Algorithmus baut us lösungen kleinerer Teilprobleme die Lösungen immer größerer Teilprobleme zusammen, bis schließlich das Gesamtproblem gelöst ist
- im fall des kürzeste-Pfade-Problems liegt die Beobachtung zugrunde, dass ein kürzester Pfad von $s$ nach $t$ aus kürzeren Teilpfa[[08-Speicherverwaltung]]den besteht

>[!note] Algorithmus Dijakstra
>1. Für alle $v \in V(G)$ setze $\delta(v) = \infty$ und $p(v) = \emptyset$
>2. Setze $\delta(s) = 0, p(s) = s, S = \emptyset$ und $U = \{ s \}$
>3. Solange $U \ne \emptyset$
>	1. finde $u \in U$ mit $\delta(u) = min_{v \in U} \delta(v)$
>	2. entferne $u aus U$ und füge $u$ zu $S$ hinzu
>	3. für alle $w \in \partial u\setminus S$
>		1. füge $w$ zu $W$ hinzu
>		2. falls $\delta(w) > \delta(u) + c(uw)$
>			1. setze $\delta(w) = \delta(u) + c(uw)$ und $p(w) = u$
>4. Gib $p, \delta$ aus

___

>[!tip] Satz
>Sei $G, c$ ein zusammenhängender gewichteter Graph, $s \in V(G)$ und $\delta, p$ die Ausgabe von *Dijakstra*.
>- Laufzeit: $O(\lvert V \rvert^2)$
>- $\delta(v)$ ist für jeden Knoten $v \in V(G)$ der **gewichtete Abdtand** von $s$ nach $v$ und $$v, p(v), \dots, p^l(v) \text{ mit } l = \text{min}_{j \ge 0} p^j(v) = s$$ist ein ***kürzester Pfad***

#### I