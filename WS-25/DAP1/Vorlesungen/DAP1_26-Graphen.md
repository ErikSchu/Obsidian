#dap1 

## Graphen

Ein ***Graph*** ist eine Sammlung von $n$ **Knoten $V$** und $m$ **Kanten** (mit Verbindungen $E$ zwischen diesen Knoten)
- Knoten der Einfachkeit halber bezeichnet mit $V = \{ 0,\dots,n-1 \}$
  
- **gerichtete Graphen:** Kanten $(a,b)$ bedeuten Verbindung von $a \in V$ ==*nach*== $b \in V$:
	  $E \underline{\subset} V \times V$ 
	alternative Schreibweise: $a \to b$
- **ungerichtete Graphen:** Kanten $\{ a,b \}$ bedeuten Verbindungen ==*zwischen*== $a \in V$ und $b \in V$:
	  $E \underline{\subset} \{ \{ a,b \} : a,b \in V \}$
	alternative Schreibweisen: $a \leftrightarrow b$ oder $a - b$

- **gewichtete Kanten:** zusätzliche *Funktionen* $E \to U$ für einen *Gweichtstyp* $U$

>[!note] Beispiel: VRR-Netz
>![[Pasted image 20260122143459.png]]
>___
>**Graphenmodellierung** (ausschnitt)
>![[Pasted image 20260122143701.png]]

#### Computermodellierung Graphen

- ***Adjazenzliste:***
	- jeder Knoten $v$ speichert in einem Container seinen **Nachbarn**, also die Knoten $w$, für die $(v, w) \in E$  bzw. $\{ v,w \} \in E$ gilt-
	- `class Graphnode {`