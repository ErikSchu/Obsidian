#lina1

Dienstag, 28.10.2025

## Gauß'sches Eliminationsverfahren

### Elementare Zeilenumformungen
1. Vertauschen zweier Teilen
2. Multiplikation einer Zeile mit einer Konstanten ungleich 0
3. Addition des c-fachen einer Zeile ($c \in \mathbb{R}$) zu einer anderen.

### Zeilenstufenform
- Jede Zeile beginnt mit mehr Nulleinträgen als die vorige
- Erster Eintrag ungleich 0 ist immer 1 (außer in Nullzeile)
- $r$ ist die Anzahl der Stufen (wenn r=0 → Nullmatrix)
- $n_{0}, \dots, n_{r}$ sind die Stufenlängen
### 4.3 Satz
*Jede Matrix kann durch eine endliche Abfolge von elementaren Zeilenumformungen in Zeilenstufenform gebracht werden.*

### 4.4 Beispiel
Sei das LGS
![[Pasted image 20251031103349.png]]
Wir bringen die erweiterte Koeffizientenmatrix durhc Zeilenumformungen in Zeilenstufenform. Dabei deuten wir mit Pfeilen die vorgenommenen Umformungen an.
![[Pasted image 20251031103410.png]]
Damit ist die Zeilenstufenform erreicht. Schreiben wir das wieder als Gleichungssystem:
![[Pasted image 20251031103451.png]]
Es hat dieselben Lösungen wie das Ausgangssystem. Diese lassen sich direkt durch Rückeinsetzen bestimmen: Aus der zweiten Gleichung ehält man $x_{2}= 5x_{3} -3$ und einsetzen in die Erste ergibt: $$x_{1} = -\frac{4}{3}x_{2}-\frac{16}{3}x_{3}=-\frac{4}{3}(5x_{3}-3)-\frac{15}{3}x_{3}=-12x_{3}+4$$
$x_{3}$ kann nun zur bestimmung der Lösungen beliebig vorgegeben n werden: $$x_{1}=-12x_{3}+4,\ x_{2}=5x_{3}-3,\ x_{3}\ \text{beliebig}$$
Sei $x_{3}=1$ $$x_{1}=-8,\ x_{2}=2, x_{3}=1$$

## 4.3 Satz (Eliminationsverfahren/ Gaußalgorithmus)
**Jede Maatrix kann durch eine endliche Abfolge der drei elementaren Zeilenumformungen in Zeilenstufenform gebracht werden.**

Wenn alle Einträge 0 sind, tun wir garnichts.
Sonst suchen wir die erste Spalte mit einem eintraf ≠ 0. Der stehe an Stelle (k,l), wobei **l die Spalte** und **k die Zeile** beschreibt.

- Wende **Typ I** an und vertasche die k-te Zeile mit der ersten. Dann steht ein eintraf a ≠ 0 an der stellen (1,l).
- Wende **Typ II** an und multipliziere die erste Zeile mit $\frac{1}{a}$. Dann steht an jeder stelle (1,l) eine 1.
- Wende **Typ III** an: für jedes $j=2, \dots, m$ sei $b_{jl}$ der Eintrag der jetzigen Matrix an der Stelle $(j, l)$. Dann addieren wir das $-b_{jl}$-facheder ersten Zeile zur $j$-ten Zeile, um dirt den Eintrag an der Stelle $(j,l)$ zu 0 zu machen (*gleicher Effekt, wie die Gleichung für $x_{l}$ aus der ersten Gleichung der $j$-ten Gleichung einzuseetzen*).

Folgendes Schema Zeigt die bisherigen Schritte.
![[Pasted image 20251031105321.png]]
Jetzt wendne wir auf die verbleibenden m-1 Zeilen das selbe Vorgehen an. Nach spätestens m Schritten erhält man so die Zeilenstufenform.

Es ist nun einfach, die lösungsmengen zu bestimmen:
![[Pasted image 20251031105453.png]]
Das System ist also unlösbar, wenn die letzte Spalte der erw. K'mat. eine neue Stufe anfängt. Die entsprechende Gleichung würde dann lauten: $0\cdot x_{1}+\dots+0\cdot x_{n}=1$
Wenn diese unlösbar ist, ist auch das ganze LGS unlösbar.

Auf der linken Seite dagegen können wir die Unbekannten, die nicht am Anfang einer Stufe stehen, beliebig vorgeben und die übrigen Unbekannten von unten nach oben durch einsetzen ausrechnen.

Unbekannten, die wirn in der Zeilenstufenform beliebig wählen dürfen, nennen wir **freie Unbekannte**.

#### Fakten
- **Carl Friedrich Gauss (1777-1855)** war der erste, der dieses allgemeine Verfahren systematisch beschrieben hat.
	⤷ Ähnliche Rechentechniken sind allerdings lange vorher bekannt gewesen (z.B. *Fangcheng* als frühe Form der Matritzenrechnung im Chinesischen Altertum)
- LGS sind fas die einzigen Gleichungssysteme in der ganzen Mathematik, die sich immer exakt lösen lassen, weshalb man versucht, möglichs viele andere Rechenprobkee auf das lösen linearer Gleichungssysteme zurückzuführen

### Beispile
#### 4.5
![[Pasted image 20251031111254.png]]

![[Pasted image 20251031111311.png]]

Damit das Löeichungssystem eine Lösung in $x_{1},x_{2},x_{3}$ hat, muss $b_{3}+\frac{2}{3}b_{2}-\frac{1}{3}b_{1}=0$ gelten. Das ist jetzt wieder eine lineare Gleichung in $b_{1}, b_{2}, b_{3}$.

#### 4.6
Einfache Fragen über Geraden im $\mathbb{R}^n$ führen unverweigerlich auf LGS: Gegeben seien die Vektoren
![[Pasted image 20251031112353.png]]
im $\mathbb{R}^3$, welche die beiden Geraden $$L = \{\vec{v}+t\vec{w}\ |\ t \in \mathbb{R}\}\ \text{und}\ \{\vec{v}'+t\vec{w}'\ |\ t \in \mathbb{R}\}$$bestimmen. Wir wollen wissen, ob sich L und L' in einem Punkt scheude und, falls ja, den Schnitttpunkt berechnen.
Die Frage ist, ob es Skalare s und t gibt, für die Folgende Gleichheit erfüllt ist: $$\vec{v}+s\vec{w}=\vec{v}'+t\vec{w}'$$Die Parameter sind unterschiedlich, da der zurückgelegte Weg auf der Geraden i.d.R. nicht gleich sind. Das Bedeutet: 
![[Pasted image 20251031113507.png]]
Daraus erhält man für due drei Einträge die drei Gleichungen
![[Pasted image 20251031113604.png]]
![[Pasted image 20251031113648.png]]

Die zweite Gleichung sagt nun t=1 und Einsetzen in die erste regibt s=-3. Es gibt also einen Schnittpunkt von L und L', nämlich
![[Pasted image 20251031113758.png]]
Wenn man den Fußpunkt $\vec{v}$ von L stattdessen beispielsweise durch den Vektor
$$
\begin{pmatrix}
2 \\
0 \\
-1
\end{pmatrix}
$$ ersetzt, ändert sich die Gleichung zu $-1=2-t$, was t=3 ergibt. Da aus den Ersten beiden Gleichungen t=1 folgt, wird das LGS unlösbar. Die beiden Geraden im $\mathbb{R}^3$ gehen aneinander vorbei, es gilt $L \cap L' = \emptyset$.

---
# 5. Lösungsräume
## 5.1 Das Matrix-Vektor-Produkt
Ein LGS mit **m Gleichungen** und **n Unbekannten** können wie unnter Verwendung von Summenzeichen und Indizes schreiben.
### Def.
Ist **A** eine **m mal n -Matrix** mit reellen Einträgen $a_{ji}$ und ist $\vec{v} \in \mathbb{R}^n$ ein Vektor, dann heißt der Vektor in $\mathbb{R}^m$ mit den Einträgen$$
\sum_{j=1}^n a_{ij}x_{j}=b_{i} \ (i=1, \dots, m)$$ als das **Matrix-Vektor-Produkt** von A und $\vec{v}$ geschrieben $$ Av \cdot\vec{v} \text{ / } A\vec{v}.$$
Damit das Matrix-Vektor-Produkt definiert ist, muss der **Spaltenvektor** $\vec{v}$ also **genauso hoch sein, wie die Matrix a breit ist**.

**Man schreibt** $Mat_{m \times n}(\mathbb{R})$ für die Menge aller reellen m mal n Matrizen. 

Für alle $A, B \in Mat_{m \times n}$ und alle $\vec{v}, \vec{ w} \in \mathbb{R}^n$ und $c \in \mathbb{R}$ gelten die **Rechenregeln:**
1. $A \cdot (\vec{v} + \vec{w}) = A\vec{v} + A\vec{w}$
2. $(A+B) \vec{v} = A \vec{v} +  B \vec{F}$
3. $A(c \vec{v}) = (cA) \vec{v} = c(A \vec{v})$


Bilden wir nun aus einem LGS die **Koeffitzentenmatrix** $A \in Mat_{m \times n}(\mathbb{R})$ und den **Vektor der Rechten Seite** $\vec{b} \in \mathbb{R}^m$, dann können wir umgekehrt die **Unbekannten** $x_{1}, \dots, x_{n}$ in einen Vektor $\vec{x}$ schreiben und das LGS **kurz in folgender Form** Notieren: $$A \vec{x} = \vec{b}$$Gesucht ist also ein Vektor $\vec{x} \in R^n$, der sich mit $A$ zum gegebenen Vektor $b \in R^m$ multipliziert.
#### Beispiel
Es gilt $$
\begin{pmatrix}
1 \ 2 \ 3 \\
0 \ 1 \ 2
\end{pmatrix}
\begin{pmatrix}
1 \\
2 \\
3
\end{pmatrix}
= \begin{pmatrix}
1 \cdot 1 + 2 \cdot 2 + 3 \cdot 3 \\
0 \cdot 1 + 1 \cdot 2 + 2 \cdot 3
\end{pmatrix}
=\begin{pmatrix}
14 \\
8
\end{pmatrix}.
$$

#### Interpretation
Das MVP ist eine **Kurzschrift für ein LGS**. Diese erlaubt zwei Sichtweisen:
1. **Algebraisch:** $A\vec{x} = \vec{b}$ ist ein statisches System, das wir lösen wollen.
2. **Geometrisch:** Die Matrix $A$ ist eine **Funktion (Abbildung)**, die den Vektor $\vec{x}$ in einen neuen Vektor $A\vec{x}$ transformiert.

---
## 5.2 Löungsraum eines LGS

### Def.
Es sei $A \in Mat_{m \times n}(\mathbb{R})$ und $\vec{b} \in \mathbb{R}^m$. Der **Lösungsraum** des LGS $A \vec{x} = \vec{b}$ ist die **Menge $$L = \{\vec{x} \in \mathbb{R}^n \text{ | } A \vec{x} = \vec{b}\}$$aller Lösungen** des Systems, falls $l \neq \emptyset$ gilt. Dann nennen wir die Anzahl der freien Unbekannten des Systems die **Dimension** der Lösungsraums.
Die Anzahl dieser **freien Unbekannten** können wir ableden, nachdem wir die Matrix $A$ in Zeilenstufenform gebracht haben (die Anzahl der Spalten, in denen keine Stufe anfängt).
⤷ *vorläufige Definition!*

Besteht das LGS $A \vec{x} = \vec{b}$ aus $m$ Gleichungen (Anzahl der Zeilen von $A$), dann hat jede einzelne dieser Gleichungen einen Lösungsraum $L_{i}$. Der L**ösungsraum $L$ ist des ganzen Systems** ist dann der **Durchschnitt der einzelnen Lösungsräume** $$L = L_{1} \cap \dots \cap L_{m}.$$

#### Beispiel
Geg. sei das LGS → Zeilenstufenform → Rückeinsetzung $$
\begin{align*}
x_{1} + 2x_{2} + 3x_{3} + 4x_{4} = 5 \\
x_{1} + 2x_{2} + 4x_{3} + 6x_{4} = 8
\end{align*}
$$![[Pasted image 20251102174100.png]]$$\begin{align}
& x_{1} = -2x_{2} + 2x_{4} - 4 \\
& x_{3} = 3 - 2x_{4}
\end{align}$$Dies sind die Lösungen des LGS **in den Freien Unbekannten** $x_2$ und $x_4$. Der Lösungsraum hat die **Dimension 2**.