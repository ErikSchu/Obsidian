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

## `insert`

>[!note] Einfügen eines neuen Knotens
>- zunächst genau wie beim "gewöhnlichen" BST
>- der neue Knoten wir **rot** gefärbt
>- die $\emptyset$-Pointer werden auf das $\emptyset$-Objekt gesetzt
>- ***Vorsicht:*** *RB2* oder *RB4* könnten verletzt sein 

#### Wiederstellen von *RB2* und *RB4*

- solange der Elternknoten des eingefügten Knotens $v$ *rot* ist, betrachten wir drei Fälle
  1. die "Tante" $w$ von $v$ ist rot
  2. $w$ ist schwarz und $v$ ist ein rechtes Kind
  3. $w$ ist schwarz und $v$ ist ein linkes Kinder 

##### Fall 1: 
![[Pasted image 20260716132058.png]]
- färbe Elternknoten und die Tante schwarz
- färbe die Großeltern $u$ ror 
- führe die Wiederherstellung rekursiv für $u$ aus 

##### Fall 2:
![[Pasted image 20260716132114.png]]
- führe eine *Linksrotation* um $v$ durch
- weiter mit Fall 3

##### Fall 3:
![[Pasted image 20260716132209.png]]
- färbe den Elternknoten von $v$ *schwarz* und den Großelternknoten $u$ rot
- dann *Rechtsrotation* um den Großelternknoten $u$ 