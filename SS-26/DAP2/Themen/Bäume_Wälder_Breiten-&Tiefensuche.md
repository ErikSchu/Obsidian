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

>[!info] Dfinition: Zusammenhangskomponenten
>Sei $G = (V,E)$ ein Graph und $u, v, w \in V$.
>1. ***Relation $\tilde{}$***