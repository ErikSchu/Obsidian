#dap2 

>[!info] Definition: Wege und Pfade in Graphen
>Bei einem Graphen $G = (V, E)$ gilt:
>- ein ***Weg*** in $G$ ist eine Folge $$v_{1}, \dots, v_{l}$$ von Knoten, so dass $\forall i \in \{ 1, \dots, l-1 \} : v_{i}v_{i+1} \in E$
> 	- dieser Weg hat die ***Länge*** $l-1$.
> 	- wir sprechen von einem *Weg von $v_{1}$ nach $v_{l}$*
> - ein ***Pfad*** in $G$ ist ein Weg $v_{1}, \dots, v_{l}$, dessen *Knoten alle verschieden* sind. 

>[!example] Beispiel
>![[Pasted image 20260704182057.png]]
>Die Folge $1, 2, 3, 4, 5, 2, 3$ ist ein Weg aber kein Pfad, weil $2$ und $3$ zweimal vorkommen. 

>[!info] Definition: Zusammenhangskomponenten
>Sei $G = (V,E)$ ein Graph und $u, v, w \in V$.
>- ***Relation $\sim_{G}$:*** Definiere $$u \sim_{G} v \Longleftrightarrow \text{ex. Weg von u nach v}$$
>- $\sim_{G}$ ist eine Äquivalenzrelation, d.h.:
>	- **Reflexiv:** $u \sim_{G} u$
>	- **Symmetrisch:** $v \sim_{G} u \Leftrightarrow u \sim_{G} v$
>	- **Transitiv:** $u \sim_{G} v \land v \sim_{G} w \implies u \sim_{G}w$
>- Nenne die Äquivalenzklassen von $G$ ***Zusammenhangskomponenten***
>	- Zwei Knoten liegen in derselben Zusammenhangskomponente, wenn es einen Weg vom einen zum anderen gibt

>[!example] Beispiel: zusammenhängende Graphen
>![[Pasted image 20260704184249.png]]
>- Ein Graph ist **zusammenhängend**, wenn er *nur eine Zusammenhangskomponente* hat, in diesem Beispiel ist:
>	- linker Graph zusammenhängend 
>	- rechte Graph unzusammenhängend & besteht aus drei Zusammenhangskomponetnen
>- Ein **isolierter Knoten** in einem Graphen ist eine *Zusammenhangskomponent*e, die nur aus *einem Knoten* besteht
>- Eine **isolierte Kante** ist eine *Zusammenhangskomponente*, die *nur eine Kante* enthält

#### Kreise in Graphen
- Ein ***Kreis*** in einem Graphen $G$ ist eine Kopie eines Kreises $C_{l}, l \ge 3$, die in $G$ enthalten ist
- Ein Kraph ist **kreisfrei**, wenn er keine Kreise enthält

>[!info] Definition Wald/Baum
>- ***Baum*** = *kreisfreier Graph*
>- ***Baum*** = *zusammenhängender Wald*

→ der Kleinst Wald besteht aus nur einem Knoten
→ der Graph, der nur aus einer Kante Besteht, ist ebenfalls ein Baum
→ jeder Pfad ist ein Baum
→ ein **Blatt** im Wald ist ein Knoten vom Grad 1

>[!tip] Lemma 
>Jeder Baum $G = (V, E)$ mti $E \ne \emptyset$ enthält *mind. 2 Blätter*

>[!tip] **Proposition**
>Die folgenden Aussagen sind äquivaltent: 
>1. Graph $G=(V,E)$ ist ein Baum 
>2. $G$ ist zusammenhängend und $\lvert E \rvert = \lvert  V \rvert -1$
>3. $G$ ist kreisfrei und ---
>4. $G$ ist kantenmaximal kreisfrei
>5. $G$ ist kantenmaximal zusammenhängend
>6. in $G$ gibt es zu je zwei Knoten $v, w$ genau einen Pfad von $v$ nach $w$

>[!info] Definition: spannender Baum
>***Spannender Baum*** eines Graphen $G = (V, E)$ ist ein Untergraph $G' = (V, E')$ von $G$ mit derselben Knotenmenge wie $G$, der ein Baum ist. 

>[!tip] Lemma
>Jeder zusammenhängende Graph enthält einen spannenden Baum.

___

## Breiten- & Tiefensuche
- in einem Graphem $G$ ist der **Abstand** von $v, w \in V(G)$ definiert als $$\text{dist}_{G}(v, w) = \text{min }_{l \ge 0} \exists \text{ Weg der Länge } l \text{ von } v \text{ nach } w$$
- falls $v, w$ in verschiedenen Zusammenhangskomponenten liegen, verwenden wir die Konvention $$\text{dist}_{G}(v, w) = \infty$$

>[!note] `***BFS(G, s)***`
>1. Färbe alle Knoten $v \in V(G) \setminus \{ s \}$ *grün* und färbe $s$ *gelb*
>2. Setze $d(v) = \infty$ für alle $v \in V(G) \setminus \{ s \}$ und setze $d(s) = 0$
>3. Setze $p(v) = \emptyset$ für alle $v \in V$
>4. Lege eine Warteschlange $Q$ an und füre $s$ in $Q$ ein 
>5. Solange $Q$ nicht leer ist 
>	1. entnehme $v$  aus $Q$
>	2. färbe $v$ *rot* 
>	3. für alle $u \in \delta v$ mit farbe *grün*
- $d(v)$: Die Distanz (Anzahl der Kanten) vom Startknoten $s$ zum Knoten $v$. Wird initial auf $\infty$ gesetzt, da wir noch keine Wege kennen.
- $p(v)$: Der Vorgängerknoten. Startet bei $\emptyset$ (leer). Das brauchst du zwingend, wenn du am Ende nicht nur die Distanz wissen, sondern den genauen Pfad im Graphen zurückverfolgen willst.
- $\delta v$: Die Menge der direkten Nachbarn (Adjazenzliste) des Knotens $v$.

- **Grün:** Knoten ist unentdeckt. Der Algorithmus war noch nie dort.    
- **Gelb:** Knoten wurde entdeckt und liegt in der Warteschlange $Q$. Seine eigenen Nachbarn wurden aber noch nicht geprüft.
- **Rot:** Knoten ist komplett abgearbeitet. Er wurde aus $Q$ entnommen und seine Kanten wurden untersucht.

>[!tip] **Satz**
>**BFS** hat de Laufzeit $O(\lvert V(G) \rvert + \lvert E(G) \rvert)$. Bei Beendigung des Algorithmus gilt 
>1. Die Zusammenhangskomponente des Startknotens $s$ besteht aus genau den Knoten, für die $d(v) < \infty$
>2. Für alle $v \in V(G)$ gilt $d(v) = \text{dist}_{G}(s, v)$
>3. Der Untergraph $$(\{ v \in V(G) : d(v) < \infty, \{ \{ v, p(v) \} : v \in V(G) , p(v) \ne \emptyset \} \})$$ist ein Spannender Baum der Zusammenhangskomponente von $S$ in $G$

>[!tip] Lemma
>Für jeden Graphen $G$ gilt $$\sum_{v \in V(G)} d_{v}(G) = 2\lvert E(G) \rvert $$

>[!tip] Lemma
>Während der gesamten Ausführung von **BFS** gilt für alle Knoten $v$ $$d(v) \ge \text{dist}_{G}(s, v)$$

>[!tip] Lemma 
>Enthält die Warteschlange $Q$ die Knoten $q_{1}, \dots, q_{l}$, dann gilt $$d(q_{1}) \le \cdots \le  d(q_{l}) \le d(q_{1}) + 1.$$
>___
>Wird ein Knoten $u$ vor einem anderen Knoten $u'$ in $Q$ eingefügt, gilt $$d(u) \le d(u')$$



>[!note] ***`DFS(G)`***
>1. Färbe alle Knoten $v \in V(G)$ *grün*
>2. Setze $c(v) = 0$ und $p(v) = \emptyset$ für alle $v \in V$
>3. Setze $j = 1$
>4. Für alle $v \in V(G)$
>	1. falls $v$ *grün* ist
>		1. führe `DFSLoop(G, v, j)` aus
>		2. erhöhe $j$ um 1

>[!note] `DFSLoop(G, v, j)`
>1. Färbe $v$ *gelb* und setze $c(v) = j$
>2. Für alle $u \in \delta_{G}v$
>	1. Falls $u$ *grün*
>		1. Setue $p(u) = v$
>		2. führe `DFSLoop(G, v, j)` aus 
>3. Färbe $v$ *rot*

>[!tip] **Satzc^{-1}(j)**
>- **DFS** hat die Laufzeit $O(\lvert V(G) \rvert + \lvert E(G) \rvert)$
>- Die Mengen $c^{-1}(j)$ für $j \ge 1$ bilden genau die Zusammenhangskomponenten von $G$.