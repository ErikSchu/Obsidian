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

Wie bezeichnen mit $$\partial^+v = \partial ^+ _{G} v = \{ w \in V: (w, v) \in E(G) \}$$