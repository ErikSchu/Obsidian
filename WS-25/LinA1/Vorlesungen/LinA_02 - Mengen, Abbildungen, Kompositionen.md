#lina1

Freitag, 17.10.2025

### Wdh. 
#### Def.
Eine **Gerade** im $\mathbb R^n$ ist gegeben durch $\vec{x}, \vec{y} \in \mathbb R^n$ mit $\vec{x} \not= \vec{y}$ als $$L = \{ \vec{x} + t \vec{w} \mid t \in \mathbb R \}$$
#### Satz 1.3
Seien $\vec v$, $\vec v '$, $\vec w$, $\vec w' \in \mathbb R^n$, $\vec w$, $\vec w' \not = \vec 0$, $$L = \{ \vec{v} + t \vec{w} \mid t \in \mathbb R \}, L' = \{ \vec{v}' + t \vec{w}' \mid t \in \mathbb R \}.$$ Genau dann gilt $L=L'$, wenn es $\vec v' \in L$ gibt und es $c \in \mathbb R$ gibt mit $\vec w' = c \cdot \vec w$.

#### Korollar 1.4
Für $L$ wie oben gilt $L = \{ \vec{x} + t \vec{w} \mid t \in \mathbb R \}$ für jeden Vektor $\vec x \in L$.

---
## Satz 1.5 (Vektorengerade)

![[Pasted image 20251017110937.png]]

Sind $\vec{x}, \vec{y} \in \mathbb R^n$ mit $\vec{x} \not= \vec{y}$ gibt es genau eine gerade in $\mathbb R^n$, welche $\vec{x}$ und $\vec{y}$ enthält. 

**Beweis:**
- **Existenz:** Setze $\vec{w} = \vec{y} - \vec{x}$. Da $\vec{x} \not= \vec{y}$, gilt $\vec{w} \not= \vec{0}$ und die Gerade $$L = \{ \vec{x} + t \vec{w} \mid t \in \mathbb R \}$$Es gilt somit $\vec{x} \in L \ (für \ t \not= 0)$ und $\vec{y} = \vec{x} + \vec{w} = L \ (für \ l = 1)$.

- **Eindeutigkeit:** Sei $$L' = \{ \vec{v}' + t \vec{w}' \mid t \in \mathbb R \}$$ eine weitere Gerade mit $\vec{x}, \vec{y} \in L$. Definiere L wie oben, dann ist $L=L'$ zu zeigen. Nach Kor. 1.4 gilt wegen $\vec x \in L$ auch $$L' = \{ \vec{v}' + t \vec{w}' \mid t \in \mathbb R \}$$ Wegen $\vec{y} \in L'$ gibt es nun $t_0 \in \mathbb R$ mit $\vec{y} = \vec{x} + t_{o} \vec{w}$. Woraus folgt $$\vec{w}' = \frac{1}{t_{0}} \cdot (\vec{y}-\vec{x}) = \frac{1}{t_{0}} \cdot \vec{w}$$ und damit $L=L'$ nach Satz 1.3. $$\tag*{$\blacksquare$}$$
### 1.6 Korollar
Es seien $\vec{x}, \vec{y} \in \mathbb R$, $\vec{x} \not = \vec{y}$ und $\vec{y} \not = \vec{0}$. Dann sind die folgenden aussagen **äquivalent:**
1. Die Verbindungsgerade von $\vec{x}$ und $\vec{y}$ geht durch den Ursprung $\vec{0}$
2. Es gibt $c \in \mathbb{R}$ mit $\vec{x} = c \cdot \vec{y}$ 
Wenn diese Bedingungen erfüllt sind, heißen die beiden Vektoren **kollinear**.
$$\tag*{$\blacksquare$}$$

---
---

## Mengenlehre
Mathe ist systemstisch auf [[1.3_Mengen]] aufgebaut → alles ist "irgendwie eine Menge"

---
---

## Abbildungen (=Funktionen)

### Einführung
Es seien X, Y zwei Mengen. Eine Abbildung $f: X \to Y$ ordnet jedem Element x in der **Quelle** X (Definitionsbereich) ein Element $f(x)$ im **Ziel** Y (Wertebereich) zu.
(Zuordnungsdefinition)
Beispiel: $$f: \begin{cases} \mathbb{R} \to \mathbb{R} \\ x \mapsto 3x^2 + 7 \end{cases}$$oder kurz: $f(x)=3x^2 + 7$

![[Pasted image 20251020155233.png]]

### Vektorwertige Funktionen
![[Pasted image 20251020155403.png]]
Die Vektorwertige Abbildung,welche die Gerade L *parametrisiert*. Sie weist also jedem Wert des Marameters t den entsprechenden Punkt auf L zu.
Die Gerade L ist die **Bildmenge** oder kurz das **Bild** der abbidung $\varphi$:
![[Pasted image 20251020155956.png]]

Für n > 3 lässt sich der Graph einer vektorwertigen Funktion nicht mehr zeichnen.

Abbildungen lassen sich auch **einschränken**
![[Pasted image 20251020160348.png]]
![[Pasted image 20251020160337.png]]

Ist das n der Quelle höher, als das des ZIels, spricht man bei der Abbildung von einer **Koordinatenprojektion**, die mit $\pi$ bezeichnet wird:
![[Pasted image 20251020160730.png]]
![[Pasted image 20251020160808.png]]

## Kompositionen
Man kann Abbildungen kombinieren, d.h. hintereinander ausführen (exemplarisch $\pi, \varphi$)
![[Pasted image 20251020164931.png]]

Das bild von $\pi \circ \varphi$ ist die Projektion der Geraden $L = \varphi(\mathbb{R})$ in $\mathbb{R}^3$ in die Ebeneund damit eine Gerade in $\mathbb{R}^2$, sofern der Vektor $\pi(\vec{w}) \not= \vec{0}$.

![[Pasted image 20251020165757.png]]

### Definition
Sind $f:X \to Y$ und $g:Y \to Z$ zwei Abbildungen, bei denen die Quelle von g mit dem Ziel von f übereinstimmt, dann ist die Komposition von f und g definiert durch
![[Pasted image 20251020170203.png]]

Dabei steht die Abbildung, die zuerst an der Reihe ist, rechts, wieil das Argument, auf das die Funktion angewendet wird, immer rechts geschrieben wird.![[Pasted image 20251020170753.png]]

$\varphi \circ \pi$ hingegen ist nicht definiert.

## Teil- & Potenzmengen
Es lässt sich nicht nur die Parametrisierung $\varphi$ wie oben bilden, sondern auch die Zuordnung $(\vec{v}, \vec{w}) \mapsto L$. Dies ist ein **völlig anderer Typ von Abbildiung**. Ihre Quelle ist die Menge
![[Pasted image 20251020172231.png]]
und ihr Ziel ist die Menge $\mathcal{P}(\mathbb{R}^n) = \{ T \subset {R}^n \}$ deren Elemente die Deilmengen der dReellen Zahlen hoch n sind. Man kann also
![[Pasted image 20251020172938.png]]
schreiben und bekommen eine Abbildung $\Phi$, die dem Paar ($\vec{v}, \vec{w}$) die Gerade mit Fußpunkt mit $\vec{v}$ und Richtung $\vec{w}$ zugeordnet. Sie ist *mengenwertig*.

![[Pasted image 20251020173240.png]]
![[Pasted image 20251020173835.png]]
^
- Induktion?