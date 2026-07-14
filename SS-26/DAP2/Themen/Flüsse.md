#dap2 

- Ein Netzwerk ist ein *gerichteter Graph mit Kantenkapazitäten*
	- Welche maximale Ladung kann von einer Quelle zu einer Senke transportiert werden?
	*⮩ Anwendung:* Matchings in bipatiten Graphen

>[!infp] Definition
>ein (endlicher) **gerichteter Graph** $G$ besteht aus
>- einer endlichen Menge $V(G)$ von ***Knoten***
>- einer Menge $G(G) \subseteq V(G) \times V(G)$ von ***gerichteten Kanten***
>$\leadsto$ eine Kante der Form $(v, v)$ nennt man **Schleife**

## Netzwerkflüsse

#### Notation

Wie bezeichnen die *eingehende* und die *ausgehende Nachbarschaft* von $v$ mit$$\begin{align} & \partial^+v = \partial ^+ _{G} v = \{ w \in V: (w, v) \in E(G) \} \\ & \partial ^-v = \partial^-_{G} v = \{ w \in V : (v, w) \in E(G) \} \end{align}$$
Ferner definiere folgendes als den *eingehenden* und den *ausgehenden Grad* von $v$$$\begin{align} & d^+_{G} (v) = \lvert  \partial^+_{G} v \rvert \\ & d^-_{G} (v) = \lvert  \partial^-_{G} v \rvert  \end{align}$$
#### Breitensuche

- wir haben `BFS` für ungerichtete Graphen kennengelernt
- der Algorithmus überträgt sich auf gerichtete Graphen indem in der Hauptschleife (8) nur $u \in \partial^-v$ in die Warteschlange eingefügt werden
- der Algorithmus bestimmt dann kürzeste *gerichtete* Pfade in $G$

___

>[!info] Definition ***Netzwerk***
>$N = (G, c, s, t)$ besteht aus
>- einem *gerichteten Graphen* $G$
>- einer *Kapazitätsfunktion* $c : V \times V \to \mathbb{R}_{\ge 0}$, s.d. $c(v,w) = 0$ falls $(v, w) \not \in E(G)$
>- einer *Quelle* $s \in V(G)$
>- einer *Senke* $t \in V(G) \setminus \{ s \}$
>___
>Ein **Fluss** in einem Netzwerk $N$ ist eine Fuktion $f: V \times V \to R$, s.d.
>- $f(v, w) \le c(v, w)$ für alle $v, w \in V(G)$
>- $f(v, w) + f(w, v) = 0$ für alle $v, w \in V(G)$
>- $\sum_{w \in V(G)} f(v, w) = 0$ für alle $v, \in V(G) \setminus \{ s, t \}$
>
>Der **Wert** von $f$ ist definiert als $$\lvert f \rvert = \sum_{w \in V(G)} f(s, w)$$

#### Notation

Für eine Funktion $f: V \times V \to R, v \in V$ und $A, B \subset V$ definieren wir $$\begin{align}
& f(v, A) = \sum_{w \in A} f(v, w) \\
& f(A, v) = \sum_{w \in A} f(v, w) \\
& f(A, B) = \sum_{v \in A} \sum _{w \in B} f(v, w)
\end{align}$$
>[!tip] Lemma
>Sei $N$ ein Netzwerk und $f$ ein Fluss. Für alle $A, B, W \subseteq V$ gilt
> $$\begin{align} f(A, A) & = 0 \\ f(A, B) + f(B, A) & = 0 \\ f(A \cup B, C) & = f(A, C) + f(B, C) \\ f(C, A \cup B) & = f(C, A) + f(C, B)\end{align}$$
> sofern $A \cap B = \emptyset$


#### Das Max Flow-Problem

- gegeben ist ein Netzwwerk $N$
- das Ziel ist, einen Fluss mit maximalem Wert (einen *"maximalen Fluss"*) zu bestimmen
- die Idee ist, ausgehend vom Nullfluss den Fluss immer weiter zu "aufmentierten"

#### Restflüsse

Sei $N$ ein Netzwerk und $f$ ein Fluss
- die **Restkapazität** von $f$ in $N$ ist definiert als $$c_{f}(v, w) = c(v, w) - f(v, w) \space (v, w \in (G))$$
- das **Restnetzwerk** von $f$ in $N$ ist das Netzwerk mit Kantenkapazitätsfunktion $c_{f}$ und Kantenmenge $$E_{f} = \{ (v, w) \in V(G) : c_{f} (v, w) > 0 \}$$ 
>[!tip] Lemma 
>Sei $N$ ein Netzwerk, $f$ ein Fluss in $N$ und $g$ ein Fluss in $N_{f}$.
>Dann ist $f + g$ ein Fluss in $N$ mit Wert $\lvert f + g \rvert = \lvert f \rvert + \lvert g \rvert$.

#### Augmentierte Pfade

- ein **f-augmentierender Pfad** iste $N$ ist ein $s-t$-Pfad $N_{f}$
- die **Kapazität** eines solchen Pfades $p$ ist $$c_{f}(p) = \text{min}\{ c_{f} (u, v) : (u, v) \text{ ist eine Kante auf } p \} > 0$$

>[!example] Beispiel
>![[Pasted image 20260714102435.png]]
>⮩ ein Netzwerkfluss $f$
>___
>![[Pasted image 20260714102525.png]]
>⮩ das Restnetzwerk $N_{f}$
>___
>![[Pasted image 20260714102607.png]]
>⮩ eun augmentierter Pfad mit der Kapazität $2$

>[!tip] Lemma 
>Sei $N$ ein Netzwerk, $f$ ein Fluss, $p$ ein augmentierender Pfad. Dann ist $f_{p} : V \times V \to \mathbb{R}$ mit $$f_{p}(v, w) = (\mathbb 1 \{ (v,w) \text{ ist eine Kante von } p \}- \mathbb 1 \{ (w, v) \text{ ist Kante von } p \}) c_{f}(p)$$ein Fluss mit Wert $c_{f}(p)$ in $N_{f}$.

>[!tip] Korollar
>Angenommen $N$ ist ein Netzwerk, $f$ ein Fluss und $p$ ein augmentierender Pfad. Dann ist $f + f_{p}$ ein Fluss in $N$ mit Wert $\lvert f \rvert +  c_{f}(p) > \lvert f \rvert$.


>[!note] **Algorithmus** `FordFulkerson`
>1. setze $f(v, w) = 0$ für alle $v, w \in V$
>2. solange es einen augmentierenden Pfad $p$ in $N_{f}$ gibt
>	1. setze $f = f + f_{p}$
>3. gib $f$ aus

>[!tip] Lemma
>Sei $N$ ein Netzwerk und $f$ ein Fluss. Für jeden Schnitt $S$ gilt $$\lvert f \rvert = f(S, V \setminus S)$$

>[!tip] Korollar
>Wen $N$ ein Netzewrk, f ein Fluss und $S$ ein Schnitt ist, gilt $\lvert f \rvert \le c(S)$


>[!tip] **Theorem** *"Max flow min cut theorem"*
>Für jedes Netzwerk $N$ gilt $$\text{max}\{ \lvert f \rvert : f \text{ ist ein Fluss in } N \} = \text{min} \{ c(S) : S \text{ ist ein Schnitt in } N \}$$

>[!tip] Korollar
>Wenn `FordFulkerson` terminiert, ist die Ausgabe ein maximaler Fluss. 

⮩ Anmerkung: `FordFulkerson` ist nicht *effizient*

___

#### `EdmindsKarp` Algorithmus

- werwende in `FordFulkerson` Beritensuche, um den augmentierenden Pfad zu finden
	  finde also jewails den *kürzesten* augmentierten Pfad 

>[!tip] Monotonielemma
>Seien $f_{1}, f_{2}, \dots$ die Flüsse, die `EdmondsKarp` konstruiert, $\text{dist}_{N_{f_{i}}} (s, v)$ der Abstand von $s, v$ im Restnetzwerk $N_{f_{i}}$. 
>Dann gilt $$\text{dist}_{N_{f_{i}}}(s, v) \le \text{dist}_{N_{f_{j}}} \space \text{ für alle } i \le j, v \in V(G)$$

>[!tip] **Satz**
>`EdmondsKarp` hat die Laufzeit $O(\lvert V(G) \rvert \cdot \lvert E(G) \rvert^2)$

___

#### Matchings

- Ein ***Matching*** in einem ungerichteten Graphen $G = (V, E)$ ist eine Menge $M \subseteq E$ von Kanten, s.d. $$e \cap f = \emptyset \space \text{ für alle } e, f \in M, e \ne f$$
- mit $v(G)$ wird die maximale Größe eines Matchings in $G$ bezeichnet ("Matchingzahl von $G$")
- $G$ heißt **bitpartit**, falls $_{\chi}(G) = 2$
- eine **Bitpartition** von $G$ ist ein Paar $(S, T)$ von stabilen Mengen, s.d. $S \cup T = V(G)$ und $S \cap T = \emptyset$

>[!tip] **Satz** von Hall
>Sei $G$ ein nitpariter Graph mit Bitpartition $(S, T)$. Es gilt 
>$$v(G) = \lvert  S \rvert \Longleftrightarrow \lvert \partial U \rvert \ge \lvert U \rvert \space \text{ für alle }  $$