#lina1 Freitag, 14.11.2025

# 8.1 Länge & Normalformen
Vgl. Satz des Pythagoras: In $\mathbb{R}^2$ ist die Länge (eines Vektors $\vec{x}= \begin{pmatrix} x_{1} \\ x_{2} \end{pmatrix}$ die Zahl $\sqrt{ x_{1}^2 + x_{2}^2}$. 
![[Pasted image 20251120215507.png]]
> [!TIP] Definition (Norm eines Vektors)
Für einen Vektor $\vec{x} = (x_{1}, \dots, x_{n}) \in \mathbb{R}^n$ heißt folgendes die **Länge** oder **Norm** von $\vec{x}$. $$||\vec{x}|| = \sqrt{ x_{1}^2 + \dots + x_{n}^2}$$

Die Quadratwurzel ist dabei wie üblich die positive Quadratzahl einer positiven reellen Zahl. Insbesondere gilt $\forall x \in \mathbb{R} : \sqrt{ x^2 } = |x|$.

>[!note] 8.1 Lemma (Nullbetrag & Skalarmultiplikation der Norm)
>1. $\forall x \in \mathbb{R}^n: ||\vec{x}||  \ge 0, \ ||\vec{x}|| = 0 \Leftrightarrow \vec{x} = \vec{0}$
>2. $\forall \vec{x} \in \mathbb{R}^n, \ c \in \mathbb{R} : ||c \vec{x}|| = |c| \cdot ||\vec{x}||.$


Ein Vektor $\vec{x} \in \mathbb{R}^n$ heißt **normiert**, wenn er die länge $1$ hat. 
Jeden Vektor $\vec{x} \in \mathbb{R}^n$, der nicht der Nullvektor ist, kann man *normieren* und damit folgenden Vektor bilden: $$\frac{\vec{x}}{||\vec{x}||}$$

---
# 8.2 Das Skalarprodukt
Der Norm liegt ein weiterer Begriff zu Grunde.

>[!TIP] 8.2 Definition
>Für $\vec{x}, \vec{y} \in \mathbb{R}^n$  heißt $$\langle \vec{x}, \vec{y} \rangle = \sum_{i=1}^n x_{i} y_{i}$$
>das **Skalarprodukt** (Skalar, da aus zwei Vektoren ein Skalar wird) von $\vec{x}$ und $\vec{y}.$
>Es gilt $||\vec{x}|| = \sqrt{ \langle \vec{x}, \vec{x} \rangle }$ und damit $\langle \vec{x}, \vec{x} \rangle = ||\vec{x}||^2$.

## 8.2 Beispiel 
**Vektor-Einheitsvektor-Skalarprodukt:** Für jeden Vektor $\vec{x} \in \mathbb{R}^n$ gilt     $\langle \vec{x}, \vec{e}_{i} \rangle = \vec{x}_{i}$

>[!note] 8.3 Lemma (Rechenregeln für das Skalarürodukt)
>Das Skalarprodukt ist **bilinear**, **symmetrisch** und **positiv definiert**: Für alle $\vec{x}, \vec{y}, \vec{z} \in \mathbb{R}^n$ und $c \in \mathbb{R}$ gelten:
>1. $\langle \vec{x} + \vec{y}, \vec{z} \rangle = \langle \vec{x}, \vec{z} \rangle + \langle \vec{y}, \vec{z} \rangle$ *Vektoraddition*
>2. $\langle c \vec{x}, \vec{y} \rangle = \langle \vec{x}, c \vec{y} \rangle = c\langle \vec{x}, \vec{y} \rangle$ *Skalarmultipilkation*
>3. $\langle \vec{x}, \vec{0} \rangle = \langle \vec{0}, \vec{x} \rangle = 0$ *Nullvektor*
>4. $\langle \vec{x}, \vec{y} \rangle = \langle \vec{y}, \vec{x} \rangle$ *Kommutativität*
>5. $\langle \vec{x}, \vec{x} \rangle \geq 0, \text{wobei} \ \langle \vec{x}, \vec{x} \rangle = 0 \Leftrightarrow \vec{x} = \vec{0}$ *Nulllösung*

Das Skalarprodukt **lässt sich** umgekehrt wieder **aus der Norm berechnen**:  

> [!note] 8.4 Lemma **Polatisationsformel**
> Für alle $\vec{x}, \vec{y} \in \mathbb{R}^n$ gilt
> $$\langle \vec{x}, \vec{y} \rangle = \frac{1}{2}(||\vec{x} + \vec{y}||^2 - ||\vec{x}||^2 - ||\vec{y}||^2).$$


#### BEWEIS
$$
\begin{align}
||\vec{x} + \vec{y}||^2 - ||\vec{x}||^2 - ||\vec{y}||^2 &= \langle \vec{x} + \vec{y}, \vec{x} + \vec{y} \rangle - \langle \vec{x}, \vec{x} \rangle - \langle \vec{y}, \vec{y} \rangle \\
&= \langle \vec{x}, \vec{x} \rangle + \langle \vec{x}, \vec{y} \rangle + \langle \vec{y}, \vec{x} \rangle + \langle \vec{y}, \vec{y} \rangle - \langle \vec{x}, \vec{x} \rangle - \langle \vec{y}, \vec{y} \rangle \\
&= 2 \langle \vec{x}, \vec{y} \rangle \\
\end{align} 
$$
Somit gilt die Behauptung . 

---
# 8.3 Cauchy-Schwarz- & Dreiecksungleichung
Zwischen Normen und Skalarprodukten zweier Vektoren besteht die folgende wichtige ungleichung:
 >[!TIP] 8.5 Satz **Cauchy-Schwarz-Ungleichung**
 >Der Betrag des Skalarprodukts zweier Vektoren kann nie größer als die Summe der einzelnen Längen sein.
 > $$\forall \vec{x}, \vec{y} \in \mathbb{R}^n : | \langle \vec{x}, \vec{y} \rangle | \le ||\vec{x}|| \cdot ||\vec{y}||$$
#### BEWEIS
![[Pasted image 20251121102007.png]]
![[Pasted image 20251121102028.png]]

Aus der **CSU** folgt die **Dreiecksungleichung**.

>[!TIP] 8.6 Satz **Dreiecksungleichung**
> $$\forall \vec{x}, \vec{y} \in \mathbb{R}^n : || \vec{x} + \vec{y} || \le || \vec{x} || + || \vec{y} ||$$

#### BEWEIS
Nach *CSU* gilt:
![[Pasted image 20251121102601.png]]


Die Dreiecksungleichung ist deshalt wichtig, weil sie etwas über die *kürzeste Strecke zwischen zwei Punkten* aussagt. 

> Definition **euklidischer Abstand**
> 1. $||\vec{x}-\vec{y}|| \ge 0$ *positiver Betrag*
> 2. $|| \vec{x} - \vec{y} || = 0 \Leftrightarrow \vec{x} = \vec{y}$ *Vektorgleichheit*
> 3. $|| \vec{x} - \vec{y} || = || \vec{y} - \vec{x} ||$ *Symmetrie*
> 4. $|| \vec{x} - \vec{z} || \le ||\vec{x}-\vec{y} || + || \vec{y} - \vec{z}||$ *Dreiecksungleichung*

Dies gilt für alle $\vec{x}, \vec{y}, \vec{z} \in \mathbb{R}^n$. Die Variante der **Dreiecksungleichung** in *4.* folgt, indem nan die normale Dreiecksungleichung auf $||\vec{x}-\vec{z}||  = ||(\vec{x} - \vec{y}) + (\vec{y}-\vec{z})||$ angewendet. 
Sie besagt, dass die Entfernung zwischen $\vec{x}$ und $\vec{z}$ nicht kürzer werden kann, wenn man den Umweg über $\vec{y}$ nimmt.

##### Exkurs: Geometrie
Sei $x \in \mathbb{R}^n$ der *Mittelpunkt* und $r \gt 0$ der *Radius*.
Man unterscheidet in der **Elementargeometrie** zwischen der "Schale" (**Sphäre**) und dem "Vollen" (**Kugel**):
![[Pasted image 20251121114906.png]]
![[Pasted image 20251121115030.png]]

# 8.4 Winkelmessung
Mit dem **Skalarprodukt** lässt sich der Winkel zwischen Vektoren messen. 

### Trigonometrische Grundlagen
![[Pasted image 20251121115211.png]]
![[Pasted image 20251121115231.png]]

**Sinus** und **Cosinus** erfüllen nach dem Satz des Pythagoras die Identität $$\sin ( \alpha)^2 +  \cos(\alpha)^2 = 1$$
und bilden den Einheitskreis $$S^1 = \{ \vec{x} \in \mathbb{R}^2 \ | \\ \ ||\vec{x}|| = 1 \}$ = \{(\cos(\alpha), \sin(\alpha) \in \mathbb{R}^2 | \alpha \in [0, 2\pi])\}.$$
![[Pasted image 20251121115943.png]]

![[Pasted image 20251121121517.png]]

>[!TIP] Definition **Winkel zwischen Vektoren**
>Für $\vec{x}, \vec{y} \in \mathbb{R}^n$ mit $\vec{x}, \vec{y} \ne \vec{0}$ definieren wir den *Winkel* zwischen x und y als die eindeutig bestimmte Zahl $\alpha \in [0, 2 \pi]$ mit
>$$\cos(\alpha) = \frac{\langle \vec{x}, \vec{y} \rangle}{||\vec{x}|| \ ||\vec{y}||}$$
>Dabei hat der Winkel kein Vorzeichen, d.h. er hängt nicht von der Rihenfolge der Vektoren ab.

---

## 8.5 Orthogonale Vektoren
Für $\alpha$ gilt $\cos(\alpha) = 0$, genau für $\alpha = \frac{\pi}{2} = 90°$. Deshalb:

>[!TIP]  Definition **Orthogonalität**
>Zwei Vektoren $\vec{x}, \vec{y} \in \mathbb{R}^n$ sind *orthgnal* oder stehen *senktecht* aufeinander, wenn gilt: $$\langle \vec{x}, \vec{y} \rangle = 0$$

> [!note] **Beispiele**
> 1. $\vec{x}$ ist orthogonal zu $\vec{e}_{i}$, wenn $x_{i} = 0$ gilt. Insb. Stehen die Einheitsvektoren aufeinander senkrecht, d.h.: $$\langle \vec{e}_{i}, \vec{e}_{j} \rangle = 0 \ \text{für} \ i \ne j$$
> 2. $\vec{x}, \vec{y} \in \mathbb{R}^2$ sind genau dann orthogonal, wenn sie $x_{1}y_{1}+x_{2}y_{2}=0$ erfüllen. Insb. kann man zu gegebenem $(x_{1}, x_{2})$ sehr leicht einen orthogonalen Vektor $(x_{2}, -x_{1})$ angeben.
> 3. *Kreuzprodukt*

