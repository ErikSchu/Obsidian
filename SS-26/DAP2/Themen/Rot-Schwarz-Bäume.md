#dap2
## Worum geht es?
- binäre Suchbäume sind nur dann effizient, wenn sie von geringer Höhe sind
- red black trees sind eine Variante, die sich selbst "trimmt"
- die Höhe bei $n$ Elementen ist dabei stets $O(\log n)$
- wir müssen dabei die Operationen `Insert` und `Delete` verändern

## Red black Regeln
- **RB1** - jeder Knoten ist entweder rot/schwarz gefärbt
- **RB2** - Wurzel ist schwarz 
- **RB3** - jeder ∅-Zeiger auf ein Kind zählt als schwarzer Knoten (Blatt)
- **RB4** - rote Knoten haben nur schwarze Kinder
- **RB5** - jeder Pfad von der Wurzel zu einem Blatt enthält dieselbe Zahl Schwarzerknoten 

![[Pasted image 20260715140443.png]]

#### Implementation
- Jeder Knoten benötigt ein *zusätzliches Bit für die Farbe*
- Wir speichern *einen* zusätzlichen Knoten als $\emptyset$-Knoten ab
	- dessen Elternzeiger ist also nicht korrekt gesetzt

>[!tip] Lemma
>Ein red black tree mit *$n$ Knoten* hat die ***Höhe $O(\log n)$***.


### Rotationen

![[Pasted image 20260715140826.png]]
⮩ **Linksrotation** um einen Knoten $v$
⮩**Rechtsrotation** um einen Knoten $w$

