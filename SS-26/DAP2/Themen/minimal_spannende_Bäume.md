#dap2

→ Jeder zusammenhängende Graph besitzt einen spannenden Baum
→ In einem gewichteten Graphen sind wir interessert an einem *minimalen* spannenden Baum
→ dazu der ***Greedy-Algorithmus***

>[!def] Definition
>- ein **gewichteter Graph** ist ein Graph $G = (V, E)$ zusammen mit einer Funktion $c : E \to Q _{\ge_{0}}$.
>- das **Gewicht** einer Kantenmenge $F \subseteq E$ ist $$ \sum_{e \in F}  c (e)$$
>- ein **minimal spannender Baum** von $G$ ist ein spannender Baum $T = (V, E_{T})$ von $G$ mit $$c(E_{T}) = \text{min} \{ c(E_{B}) : B = (V, E_{B}) \text{ ist sp. Baum von } G  \}$$

- für algorithmische Zwecke nehmen wir stets an, dass die Gewichtungsfunktion $c$  rationale Werte annimmt 
	- diese rationalen Werte werden dann exakt eingegeben, d.h. als Paare ganzer Zahlen $$(\text{Zähler, Nenner})$$
- äquivalent können wir annehnen, dass alle Gewichte ganzzahlig sind

___

>[!note] ***Kruskalalgorithmus***
>1. prüfe, on $G$ zusammenhängend ist; wen nicht, gib eine Fehlermeldung aus 
>2. sortiere die Kanten $G$ aufsteigend nach Gewichten: $$c(e_{1}) \le c(e_{2}) \le \cdots \le c(e_{m})$$
>3. initialisiere $T = (V, \emptyset)$
>4. für $i = 1, \dots, m$
>	1. wenn $e_{i}$ verschiedene Komponenten von $T$ verbindet, füge $e_{i}$ zu $T$ hinzu
>5. gib $T$ aus

- Schritt 1 kann man mit Tiefensuche in Zeit $O(\lvert E \rvert + \lvert V \rvert)$ drurchgeführt werden
- für Schritt 2 verwenden wir ` Heapsort `; Laufzeut $O(\lvert E \rvert \log \lvert E \rvert)$
- für Schritte 5, 6 führen wir Buch über die Komponenten von $T$
	- dabei führen wir die Komponentengrößen mit 
	- jedes Mal, wenn eine Kante hinzugefügt wird, wird die *kleinere* Komponente zur größeren hinzugefügt

>[!tip] Satz 
>Sei $G, c$ ein Zusammenhängender gewichteter Graph (mit rationalen Gewichten).
>- Kruskal hat Laufzeit $O(\lvert E \rvert \log \lvert  E \rvert)$
>- gibt einen minimal spannenden Baum aus 

#### Laufzeit

- Die Menge $Q$ kann mit Hilfe einer PQ implementiert werden. 
- Schritt (2) fügt die Knoten in die min PQ ein; alle bis auf den Startknoten haben dassele Gewicht.
- Schritt (4) entfernt jewails das Minimum aus der Queue
- Schritt (6) reduziert das Gewicht einiger Nachbarn von $v$
- Laufzeit: $O(\lvert E(G) \rvert \log \lvert V(G) \rvert)$

#### **Anwendung:** metrisches TSP

- wir befassen uns mit einem **Spezialfall des TSP**
- sei $G, w$ ein vollständiger gewichteter Graph
- angenommen die *Gewichte erfüllen die Dreiecksungleichung*, d.h. für alle $x, y, z \in V(G)$ gilt $$w(\{ x, z \}) \le w(\{ x, y \}) + w (\{ y, z \})$$
- man spricht vom ***metrischen TSP***

>[!tip] Proposition
>Die Länge einer optialem metrischen TSP-Tour ist
>- mindestens so hoch wie das Gewicht eines optimalen Spannbaums von G, w
>- nicht mehr als doppelt so hochwie das Gewicht eunes optimalen Spannbaums von $G, w$

