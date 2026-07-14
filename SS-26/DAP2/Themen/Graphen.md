#dap2 

- ein Grundbaustein der Algorithmik und *diskreten Mathematik*
- **Anwendungen in der Modellierung:**
	- Straßen- Schiennetze
	- Kontaktnetzwerke
	- Prozessabhängigkeiten
	- Chip Verdrahtungspläne
	- Gehirne

>[!tip] Definition
>Ein ***Graph*** $G = (V, E)$ aus 
>- einer Menge $V$ von *Knoten* "Vertices" (z.B. $V = \{ \text{Anna, Ben, Clara} \}$und
>- einer Menge $E$ von *Kanten* "Edges" (z.B: $E = \{ \{ \text{Anna, Ben} \}, \{ Ben, Clara \} \}$), 
>sodass jede Kante $e \in E$ eine **zweielemtige Teilmenge** von $V$ ist.
>Graphisch stellen wir die Knoten als Punkte dar und die Kanten als ungerichtete Verbindungslinien.

$\lvert V \rvert$, $\lvert E \rvert$ beschreibt die **Kardinalität**, also die *Anzahl der Knoten bzw. Kanten* im Graphen. 

>[!note] **Konvention**
>Sei $G = (V, E)$ ein *Graph*. 
>Sofern nicht ausdrücklich anders angegeben, nehmen wir  an, dass die *Knotenmenge endlich* ist.
>Mit $V(G) = V, E(G) = E$ werden *Knoten- & Kantenmenge* eines Graphen bezeichnet.
>Für eine *Kante $\{ u, v \}$* verwenden wir die *Kurzschreibweise $uv$*.
>Per Def. erhalten Graphen *keine Mehrfachkanten* und *keine Schleifen*

>[!def] Definition
>Sei $G = (V, E)$ ein Graph.
>- Die ***Nachbarschaft*** von $v \in V$ ist **$\delta_{G}v = \{ u \in V : uv \in E \}$**.
>- Der ***Grad*** von $v$ ist **$d_{G}(v) = \lvert \delta_{G} v \rvert$**.
>- Die Knoten $v, w \in V$ sind ***adjazent*** / ***benachbart***, falls **$vw \in E$**.
>- Der Knoten $v$ und die Kante $e \in E$ sind ***inzident***, falls **$v \in e$**.
>- Der ***Maximalgrad*** von $G$ ist **$\Delta(G) = \text{max}_{v\in V} \ d_{G}(v)$**.
>- Der ***Minimalgrad*** von $G$ ist **$\delta (G) = \text{min}_{v \in V} \ d_{G}(v)$**.
>- Der Graph ist ***$k$-regulär***, falls **$\Delta(G) = \delta(G) = k$**.
>- Das ***Komplement $\overline G$ von $G$*** ist der Graph mit *Knotenmenge* **$V(\overline G) = V$** und *Kantenmenge* **$E(\overline G) = \{ uv : e, v \in V, u \ne v, uv \not \in E \}$**.

>[!tip] Lemma 
>Für einen Graphen $G$ gilt stets $$\sum_{v\in V (G)} d_{G}(v) = 2 \lvert E(G) \rvert.$$
>___
>![[Pasted image 20260623124518.png]]

>[!def] Definition
>Zwei Graphen $G = (V, E)$ und $G' = (V', E')$ sind **isomorph**, wenn es eine bijektive Abbildung $\phi : V \to V'$ gibt, sodass für alle $v, w \in V$ gilt $$vw \in E \ \Leftrightarrow \ \phi(v)\phi(w) \in E'$$

>[!def] Definition
>Der von $G = (V, E)$ auf $\mathcal S \subseteq V$ **induzierte Untergraph** ist der Graph $G[\mathcal S] = (\mathcal S, E (G[\mathcal S]))$ mit Kantenmenge $$E(G[\mathcal S]) = \{  vw : v, w \in \mathcal S, vw \in E \}$$
 
#### Löschen von Knoten und Kanten
Angenommen $G = (V, E)$ ist ein Graph. 
- Wenn $U \subseteq V$ eine Menge von Knoten ist, definiere $G-U=G[V \setminus U]$.
- Wenn $F  \subseteq E$ eine Menge von Kanten ist, definiere $G - F = (V, E \text{\\} F)$.

>[!def] Definition
>Ein Graph $G = (V, E)$ enthält
>- eine **induzierte Kopie** eines Graph $G' = (V', E')$, wenn  es eine Menge $\mathcal S \subseteq V$ gibt, sodass $G[\mathcal S]$ isomprph ist zu $G'$.
>- Eine **Kopie** von $G'$, wenn $G$ einen *Untergraphen* $H$ besitzt, der eine induzierte Kopie von $G'$ enthält. 

>[!def] Definition
>Eine **$\mathscr l$-Clique** in einem Graphen $G = (V, E)$ ist eine Menge $S \subseteq V$ von $\lvert  \mathcal S \rvert = \mathscr l$ Knoten, sodass für alle $u, v,  \in \mathcal S, u \ne v$ gilt $$uv \in E.$$Mit anderen Worten: eine $\mathscr l$-Clique ist eine *Kopie von $K_{\mathscr l}$ in $G$*.
>Bei einer **$\mathscr l$-stabilen Menge** gilt für $u, v \in \mathcal S$ $$uv \not \in E$$
>**Kliquenzahl:** $$\omega (G) = \text{max}\{ \lvert \mathcal S \rvert : \mathcal S \text{ ist eine Clique in } G \}$$
>**Stabilitätszahl:** $$\alpha (G) = \text{max}\{ \lvert \mathcal S \rvert : \mathcal S \text{ ist eine stabile Menge in } G \}.$$


## Datenstruktur Adjazenzmatrix 
![[Pasted image 20260625143619.png]]
- $A(G)$ ist eine $n \times n$-Matrix mit Einrägen $$A(G)_{uv} = \mathbb 1 \{ uv \in E \} (u, v \in V)$$
- die Zeilen/Spalten der Matrix sind durch die Knoten indiziert
- symmetrisch
- alle Nachbarn eines Knotens zu finen, benötigt $O(n)$ Zeit
- Speicherbedarf $\Theta(n^2)$

## Datenstruktur Adjazenzliste
$$\begin{align}
&1 & \mapsto & 2 & \mapsto & 2 \\
&2 & \mapsto & 1 & \mapsto & 3 & \mapsto & 4 & \mapsto & 5 \\
&3 & \mapsto & 1 & \mapsto & 2 & \mapsto & 5 \\
&4 & \mapsto & 2 & \mapsto & 5 \\
&5 & \mapsto & 2 & \mapsto & 3 & \mapsto & 4
\end{align}$$
- jeder Knoten wird durch eine Liste repräsentiert
- Liste enthält seine Nachbarn
- Reihenfolge ist beliebig 
- Speicherbedarf $O(n+m)$
- um herauszufinden, ob $uv \in E$, benötigen wir Zeit $O(\text{min}\{ d_{G} (u), d_{G}(v) \})$
- Graphen immer durch Adjazenzlisten angegeben, falls nicht anders angegeben!