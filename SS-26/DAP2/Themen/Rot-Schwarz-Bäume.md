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

##### Abschluss
- am  Ende der Wiederherstellungsoperation wird die Wurzel schwarz gefärbt
	- dadurch wird **RB2** garantiert

>[!tip] Proposition
>Die Einfügeoperationen inkl. Wiederherstellung hat Laufzeit $O(\log n)$ und stellt die Eigenschaften **RB1** - **RB5** her.


___

#### Entfernen eines Knotens $z$

- verfahre wie beim Löschen von $z$ in einem BST
- sei $y$ der Knoten, der die Stelle von $z$ einnimmt
- $y$ übernimmt die *Farbe* von $z$
- sei $v$ das Kind von $y$, bzw. $\emptyset$, falls $y$ kein kind hat
- dabei identifizieren wir  $\emptyset$ mit dem $\emptyset$-Objekt des Baums

***Wenn $y$ schwarz war, können Verletzungen von `RB1` - `RB5` eintreten***
- möglicherweie war $y$ die Wurzel; das Kind $v$ tritt an die Stelle von $y$, wird somit die neue Wurzel, ist aber womöglich rit; also `RB2` verletzt
- wenn $v$ und der Elternknoten $u$ und $z$ rot sind, ist `RB4` verletzt
- die Pfade, die vormals $y$ enthalten haben, enthalten jetzt einen schwarzen Knoten weniger; somit ist `RB5` verletzt
- wir können uns $v$, der an die Stelle von $y$ tritt, als einen "doppelt schwarzen" Knoten vorstellen
- wir unterscheiden vier Fälle, de nach der Farbe des Schwesterknotens $w$ von $v$ und den Farben der Kinder von $w$ unterscheiden
	- dabei  nehmen wir an, dass $v$ ein linkes Kind ist; andernfalls ist "links" und "rechts" zu vertauschen

##### Fall 1: roter Schwesterknoten $w$
![[Pasted image 20260716145729.png]]
- vertausche die Farben von $w$ und $u$
- führe eine Likstotation vor
- Fortfahren mit Fall $1/2/3$, wobe $w = a$ der neue Schwesterknoten ist 

##### Fall 2: schwarzer Schwesterknoten $w$, beide Kinder von $w$ sind schwarz
![[Pasted image 20260716150039.png]]
- färbe den Schwesterknoten $w$ *rot*
- fahre rekursiv mit $v = u$ fort
	- (der Knoten $u$ kann rot oder schwarz sein)


##### Fall 3: schwarzer Schwesterknoten $w$, linkes Kind von $w$ rot, rechtes Kind schwarz
![[Pasted image 20260716150252.png]]
- vertausche die Farben von $w$ und seinem linken Kind 
- Rechtsrotation um $w$
- fahre fort mit **Fall 4**, mit neuem Schwesterknoten $w = a$

##### Fall 4: schwarzer Schwesterknoten $w$, rechtes Kind von $w$ rot
- Linksrotation um $u$
- Farben anpassen $\leadsto$ Bedingung `RB5` nun erfüllt; setze $v$ auf die Wurzel des Baums 

