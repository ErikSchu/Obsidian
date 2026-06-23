- ein Grundbaustein der Algorithmik und *diskreten Mathematik*
- **Anwendungen in der Modellierung:**
	- Straßen- Schiennetze
	- Kontaktnetzwerke
	- Prozessabhängigkeiten
	- Chip Verdrahtungspläne
	- Gehirne

>[!tip] Definition
>Ein ***Graph*** $G = (V, E)$ aus 
>- einer Menge $V$ von *Knoten* und
>- einer Menge $E$ von *Kanten*, 
>sodass jede Kante $e \in E$ eine **zweielemtige Teilmenge** von $V$ ist.
>Graphisch stellen wir die Knoten als Punkte dar und die Kanten als ungerichtete Verbindungslinien.

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
>- Das ***Komplement $\overline G$ von $G$*** ist der Graph mit *Knotenmenge* **$V(\overline G) = V$** und *Kantenmenge* ** $E(\overline G) = \{ uv : e, v \in V, u \ne v, uv \not \in E \}$**.

