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
>- ***Baum*** = *zu*