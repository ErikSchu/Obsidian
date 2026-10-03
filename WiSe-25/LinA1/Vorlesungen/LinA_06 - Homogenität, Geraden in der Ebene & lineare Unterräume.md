#lina1

Freitag, 31.10.2025

## Def. Homogenität
LGS $A \vec{x} = \vec{b}$ heißt **homogen, wen b der Nullvektor** ist. Andernfalls heißt es **inhomogen**

Ein homogees LGS ist immer lösbar, da es die **triviale Lösung / Nullösung** $\vec{x} = \vec{0}$ besitzt.
Des Eliminationsverfahren findet hier aber **alle Löungen**, ausgedrückt durch freie Unbekannte.

## 5.3 Satz (Unterbestimmtes LGS)
Es sei $A \in Mat_{m \times n}(\mathbb{R})$ mit m < n. Dan hat der **Lösungsraum homogenen LGS $A \vec{x} = \vec{0}$ mind. die Dimension** n-m > 0.
#### Beweis
Das System ist nicht unlösbar, da es Homogen ist.
Nach [[Satz 4.3]] können wir A in Zsf. bringen, was den Lösungrraum nicht ändert. 
Da es nut m Zeilen gibt, gibt es höchstens m Stufen, also n-m Spalten, in denen Keine Stufe anfängt. $$\tag*{$\blacksquare$}$$
## 5.3 Geraden in der Ebene
Für eine **Teilmenge** $L \subset \mathbb{R}^2 = 0$ sind folgende Aussagen **äquivalent:**
	(1) Die Menge $L$ ist eine Gerade durch den Ursprung ($\vec{0} \in L$)
	(2) Die Menge $L$ ist der Lösungsraum einer homogenen linearen Gleichung $$a_{1}x_{1}+a_{2}x_{2}=0$$ mit den Koeffizienten $a_{1}, a_{2} \in \mathbb{R}$, die nicht beide  Null sind.

#### Beweis
**(2) ⇒ (1)**
Wenn $a_{1} \ne 0$ gilt, ist ein $\vec{x} = \begin{pmatrix} x_{1}  \\ x_{2} \end{pmatrix}$ genau dann eine Lösung von $a_{1}x_{1}+a_{2}x_{2} = x_{1}$, wenn $x_1 = - \frac{a_{2}}{a_{1}}$ gilt. Dann also	![[Pasted image 20251103205422.png]]
Das bedeutet, dass $\vec{x}$ auf der Geraden mit Fußpunkt $\vec{0}$ und der Richtungsvektor $\left( - \frac{a_2}{a_2} , 1 \right)$ liegt.	Ist andererseits $a_{1} = 0$, muss $a_{2} \ne 0$ sein.
Derlösungsraum ist dann die Gerade mit Fußpunkt $\vec{0}$ und Richtungsvektor $(1, 0)$.	

**(1) ⇒ (2)**
Sei $L$ eine Gerade mit $\vec{0} \in L$. Dar Korollar 1.4 können wir den Nullvektor als Fußpunkt nehmen und $$L = \{ t \vec{w} \ | \ t \in \mathbb{R} \}$$für $\vec{w} = (w_{1}, w_{2}) \in \mathbb{R}^2$,mit $\vec{v} \ne \vec{0}$schreiben. 
Wir setzen $a_{1} = w_{1}$ und $a_{2} = -w_{1}$. Das sit so gewählt, dass $a_{1}w_{1}=a_{2}w_{2}$ gilt. BEtrachten wir den Lösungsraum ![[Pasted image 20251103212402.png]]
Wie wir in der anderen Beweisrichtung gesehen haben, ist $M$ eine Gerade. Da $L$ und $M$ beide $\vec{0} \land \vec{w}$ enthalten, simmen sie nach [[Satz 1.5]] überein.

### 5.6 Satz
Für eine Teilmenge $L \subset \mathbb{R}^2$ sind äquivalent:
(1) L ist eine **Gerade**
(2) L ist **Lösungsraum einer linearen Gleichung** $a_{1}x_{1} + a_{2}x_{2}=b$ mit a, b Elenemt RR, wobe **nicht beide a Null sind**.
![[Pasted image 20251104085334.png]]

#### Zwei verschiedene Beschreibungen einer Graden
1. **parametrische** (oder **explizite**) Beschreibung $\{\vec{v}+t \vec{w}\ | \ t \in \mathbb{R}\}$
2. **implizite** Beschreibung als Lösungsraum einer linearen Gleichung  $a_{1}x_{1} + a_{2}x_{2}=b$ in zwei Unbekannten


## 5.4 Gleichungssysteme in zwei Unbekannten
Eine LG in zwei Unbekannten, deren Koeffizienten nicht beide Null sind, beschreibt nach Satz 5.6 eine Gerade. ist nun $$
\begin{align}
& a_{11}x_{1} + a_{12}x_{2}=b_{1} \\
& a_{21}x_{1} + a_{22}x_{2}=b_{2}
\end{align}
$$ein System von zwei solchen LG, dann liefert die erste Gleichung eine Gerade $L_{1}$ und die zweite eine Gerade $L_{2}$. Der Lösungsraum des Systems ist der Durchschnitt $L_{1} \cap L_{2}$ der beiden eraden. Wenn wir die erw. Koeffizientenmatrix  $$
\begin{pmatrix} 
a_{11} \ a_{12} \ | \ b_{1} \\
a_{22} \ a_{22} \ | \ b_{2}
\end{pmatrix}
$$in Zeilenstufenform bringen, dann gibt es füe due Gestalt dieser im Wesentlichen drei Möglichkeiten, nämlich
![[Pasted image 20251104090846.png]]

Wie wir wissen hat der erste Typ eine eindeutige Lösung, der zweite unendlich viele und der dritte ist unlösbar. für beide Geraden entspricht das geometrisch den Fällen
1. $L_{1} \ne L_{2}$ und $L_{1} \cap L_{2} \neq \{\}$; **Schnittpunkt**
2. $L_{1}= L_{2}$ und $L_{1} \cap L_{2}$; **Geraden sind gleich**
3. $L_{1} \ne L_{2}$  $L_{1} \cap L_{2} = \{\}$; **Parallellität**


## Lineare Unterräumge im $\mathbb{R}^2$
Gegeben sei ein homogenes LGS
$$
A \vec{x} = \vec{0}
$$
aus m gleichungen in n Unbekannten. Sind $\vec{u}, \vec{v} \in \mathbb{R}^n$ zwei Lösungen des Systems, dann ist auch $\vec{u} +  \vec{v}$ eine Lösung, denn es gilt
![[Pasted image 20251105114612.png]]
Außerdem ist für jede Lösung $\vec{u}$ und jedes $c \in \mathbb{R}$ auch $c \vec{u}$ wieder eine Lösung. Denn es gilt
![[Pasted image 20251105114755.png]]
Damit ein **Lösungsraum** auch ein **linearer Unterraum** ist, muss er diese drei Eigenschaften haben.

Eine Teilmenge $U \subset \mathbb{R}^n$ ist ein (linearer) Unterraum mit den Eigenschaften:
- **(NL)** $U \ne \emptyset$
- **(ADD)** $\forall \ \vec{u}, \vec{v} \in U : \vec{u} + \vec{v} \in U$
- **(SKM)** $\forall \ \vec{u} \in U \land \forall \ a \in \mathbb{R} : a \cdot \vec{u} \in U$

(ADD) und (SKM) sagen, dass U *abgeschlossen* under ter Vektoraddition und unter Skalarmultiplikation ist. Das lässt sich auch in einer einzigen Eigenschft zusammenfassen:
- **(LK)** $$