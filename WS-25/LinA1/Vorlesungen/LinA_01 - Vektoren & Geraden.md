#lina1
### Was ist LinA?
*Algebra ist nichts als geschriebene Geometrie,
Geometrie nichts als gezeichnete Algebra.
Sophie Germain (1776–1831)*

- **Vektor- & Matritzenrechnung:** Die Rechentechniken der LinA werden die ganze Zeit geübt. Brsonders wichtig ist dabei das allgemeine rechnen mit Symbolen an Stelle konkreter Zahlen.

- **Lineare Gleichungssysteme:** = die einfachsten, die es gibt & fast der einzige Typ von Gleichungen, die sich prinzipiell immer lösen lassen. AUs diesem Grund sind sie grundlegend für alles Weitere.

- **Analytische Geometrie:** LinA ist als Vorlesung aus ihr entstanden. Diese Art der Geometrie hat nicht mehr den Stellenwert von früher. Es ist aber wichtig, mit der linearen Albegra zusammen auch due geometrische Anschauung zu entwickeln.

- **Stukturmathematik:** Kennzeichen moderner Mathematik ist der abstrakte Umgang mit Ihren Objekten. Bspw. sind Vektren nicht einfach als Liste von Zahlen, sondern werden zu "Elementen eines Vektorraums" **abstrahiert**, die bestimmten **Axiomen** genügen. Diese Abstraktionen sind erfahrungsgemäß schwierig und mit hohem Lernaufwand verbunden. Jedoch werden dadurhc grundlegende Ideen klarer und viele modernere Methoden überhaupt erst verständlich.

___

## Was ist ein Vektor?
Ein **Vektor** ist eine Liste $$\vec{x}=\begin{pmatrix}x_{1}\\x_{2}\\x_{3}\\\vdots\\x_{n}\end{pmatrix}$$von reellen Zahlen $x_{1},\dots,x_{n}$ reelle Zahlen sind, die **Einträge** (oder **Komponenten**) von $\vec{x}$ heißen. Sie sind in einer festen Reihenfolge eingetragen. 
Es gilt beispielsweise: $\begin{pmatrix}2\\-1\end{pmatrix}\ne\begin{pmatrix}-1\\2\end{pmatrix}$. Deshalb sind vektoren nicht Analog zu Mengen zu betrachten, da bei Mengen {2, -1} = {-1, 2} gilt. Vektoren werden meistens als Spalten !& als Zeilen geschrieben. 

Die Menge aller Vektoren mit $n$ reellen Eintrgen ist $\mathbb{R}^n$, der $n$-**dimensionale Zahlenraum**. Wir schreiben $$\vec{x}\in\mathbb{R}^n$$um auszudrücken, dass $\vec{x}$ ein Element der Menge $\mathbb{R}^n$ ist. Man kann sich $\mathbb{R}^1=\mathbb{R}$ als Zahlenstral $\mathbb{R}^2$ als Ebene und $\mathbb{R}^3$ als dreidimensionalen Raum Vorstellen. 
Die Vekroten sind die **kartesischen Koordinaten** (von René Descartes)
Der **Nullvektor** ist $\vec{0}=\begin{pmatrix}0\\\vdots\\0\end{pmatrix}$. Im Zahlenraum ist er der **Ursprung** oder **Nullpunkt**.

![[Pasted image 20251015215224.png]]
Vektoren als Punkte im $\mathbb{R}$, $\mathbb{R}^2$ und $\mathbb{R}^3$

#### Vektoraddition
$$\begin{pmatrix}x_{1}\\y_{1}\\z_{1}\end{pmatrix}+\begin{pmatrix}x_{2}\\y_{2}\\z_{3}\end{pmatrix}=\begin{pmatrix}x_{1}+x_{2}\\y_{1}+y_{2}\\z_{1}+z_{2}\end{pmatrix}$$
![[Pasted image 20251014142754.png]]

#### Skalarmultiplikation
$$a \cdot \vec{x}=
a \cdot \begin{pmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n}
\end{pmatrix} = \begin{pmatrix}
a \cdot x_{1} \\
a \cdot x_{2} \\
\vdots \\
a \cdot x_{n}
\end{pmatrix}
für\ \vec{x}\ und\ a \in \mathbb{R}$$
![[Pasted image 20251014142821.png]]
Die Zahl, mit der der Vektor multipliziert wirt heitß **Skalar**. Der Name ist in der Fuktion dieser Zahl wiederzufinden: Sie **skaliert** (→ steckt/staucht) den Vektor. 

### Zwei Interpretationen von Vektoren
Jeder Vektor $\vec{x}$ hat somit *zwei verschiedene geometrische Interpretationen:*
- Als **Punkt mit den kartesischen Koordinaten** $(x_{1}, \dots, x_{n})$. → *"Ortsvektor"*
- Als **Richtung & Länge**, was wir uns als Pfeil denken, der vom Ursprung zum Punkt $\vec{x}$ zeigt, oder auch von einem Punkt $\vec{y}$ zum Punkt $\vec{x}+\vec{y}$. → "*Richtungsvektor"*

#### Rechenregeln für Vektoraddition & -multiplikation
Für alle $\vec{x}, \vec{y}, \vec{z} \in \mathbb{R}$ und alle Skalare $a, b \in \mathbb{R}$ gilt:
![[Pasted image 20251014143114.png]]

### Was wenn n ≥ 4?
- Für $n$ ≥ 4 kann der **n-Dimensionale Raum** (früher auch "Hyperraum") nicht mehr visuell erfasst werden. 
- In solchen fällen erscheint es zunächst unsinnig, sich Vektoren als Pfeile in einem Raum größer der dritten Dimension vorzustellen. 
- Dennoch ist die Geometrische Vorstellung oft hilfreich, um abstrakte Aussagen besser zu verstehen.
⤷ Vektoren sind lezttendlich nichts anderes als einfache Listen von Zahlen und können sehr allgemeine **Daten** mit denkbar vielen Einträgen repräsentieren.

___
## Geraden
#### Definition
Eiene **Gerade** im $\mathbb{R}^n$ ist gegegeben durch zwei Vektoren $\vec{v},\vec{w}\in\mathbb{R}^n$ mit $\vec{v},\vec{w}\in\mathbb{R}^n$ als die Menge: 
$$L = \{\vec{v} + t \vec{w} \mid t \in \mathbb{R} \}$$
	 **Mengenschreibweise:** Im **Ausdruck** $\vec{v} + t \vec{w}$ ist $t$ ein **Parameter**, der alle reellen Werte durchläuft (gekennzeichnet durch $t \in \mathbb{R}$ hinter dem Querstrich). Die beiden Vektoren dind fest gewählt und verändern sich nicht.
	 
![[Pasted image 20251014143718.png]]

Es gilt andererseits (1, 2) ∉ L: (1, 2) = v + tv = (-3 + 2t, 1 + t). So ein t existiert nicht.

### Beispiel
![[Pasted image 20251015224239.png]]
![[Pasted image 20251015224407.png]]

### Beschreibung mit [[Quantoren]]
- Die Gerade L enthält die Vektoren $\vec{v}+t\vec{w}$ **für alle** Werte des Parameters. Das kann mit dem **Allquantor $\forall$** schrieben werden:
$$
\forall t \in \mathbb{R}: \vec{v} + t \vec{w} \in L
$$
- Außerdem liegt der Vektor $\vec{x}$ genau dann auf der Geraden L, wenn **eine** reelle Zahl t mit $\vec{x} = \vec{v} + t \vec{w}$ existiert, was mit dem **Existenzquantor $\exists$**  schreiben kann:
$$
L = \{ \vec{x} \in \mathbb{R}^n \mid \exists t \in \mathbb{R}: \vec{x} = \vec{v} + t \vec{w} \}
$$

Auch verschiedene Vektoren können dieselbe Gerade bilden:

---
# Beweisen zweier allgemeiner Aussagen

### Satz 1.3 (Zeigen der Gleichheit zweier Mengen)

Wir betrachten die Vektoren
![[Pasted image 20251016192337.png]]

Auch wenn die vier Vektoren verschieden sind, stimmem die beiden Geraden $L$ und $L'$ überein. Das liegt daram, dass die Richtungsvektoren such nur um jewails einen skalaren Faktor unterscheiden, nämlich $\vec{w'}=-2\vec{w}$. Somit sind sie kollinear. Des weiteren liegen die beiden Fußpunkte jewails auf beiden Geraden.

![[Pasted image 20251014151350.png]]

### Beweis einer allgemeinen Aussage

![[Pasted image 20251016192937.png]]
![[Pasted image 20251014151804.png]]
⇒ = Implikationspfeil
⇐ = umgekehrter Implikationspfeil
![[Pasted image 20251014152940.png]]
⤷ [[Äquivalenzbeweis]]

### 1.4 Korollar
Ein Korollar ist eine Aussage, die sich direkt oder mit einem kurzen Beweis aus einer anderen ergibt. Das Wort kommt aus dem Lateinischen und bedeutet "Kränzchen". 
Es steht damit für so etwas wie ein kleines Geschenk.

![[Pasted image 20251014153601.png]]

---
### Satz (Verbindungsgerade)

Sind $\vec{x}, \vec{y} \in \mathbb{R}^n$ zwei verschiedene Vektoren, dann *existiert genau eine Gerade* im R^n, die x und y enthält.
- ("existiert genau eine" → 1. Beweis der Existenz und 2. Beweis der Eindeutigkeit ⇒ zweiteiliger Beweis)

![[Pasted image 20251014154219.png]]
![[Pasted image 20251014154449.png]]
