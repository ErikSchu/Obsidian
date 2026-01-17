#lina1
## 1. Linearer Unterraum
Ein **Linearer Unterraum** $U$ (auch Vektorraum genannt) ist eine Teilmenge des $\mathbb{R}^n$, die drei fundamentale Eigenschaften erfüllt. Man kann darin beliebig addieren und skalieren, ohne die Menge zu "verlassen".

**Definition:** Eine Teilmenge $U \subseteq \mathbb{R}^n$ heißt linearer Unterraum, wenn gilt:
1. **(NUL) $\vec{0} \in U$** (Der Nullvektor ist enthalten. In deinen Notizen steht $\vec{u} \neq \emptyset$, aber Lemma 6.1 stellt klar, dass $\vec{0}$ immer drin sein muss). 
2. **(ADD)** Abgeschlossenheit bzgl. Addition: Für alle $\vec{u}, \vec{v} \in U$ gilt auch $(\vec{u} + \vec{v}) \in U$. 
3. **(SKM)** Abgeschlossenheit bzgl. Skalarmultiplikation: Für alle $\vec{u} \in U$ und alle $c \in \mathbb{R}$ gilt auch $(c\vec{u}) \in U$. 

**Kompakte Bedingung:** (ADD) und (SKM) sind äquivalent zu einer einzigen Bedingung:

**(LK)** Für alle $\vec{u}, \vec{v} \in U$ und $a, b \in \mathbb{R}$ gilt $(a\vec{u} + b\vec{v}) \in U$. 

---

## 2. Linearkombination & Lineare Hülle (Spann)

### Definition: Linearkombination
Eine **Linearkombination** ist ein Vektor, der durch das gewichtete Addieren (Skalieren und Addieren) einer Gruppe von Vektoren entsteht.
Gegeben seien Vektoren $\vec{v}_1, \dots, \vec{v}_m \in \mathbb{R}^n$ und Skalare $c_1, \dots, c_m \in \mathbb{R}$ (die Koeffizienten).

Der Vektor $$\vec{x} = c_1\vec{v}_1 + c_2\vec{v}_2 + \dots + c_m\vec{v}_m$$
heißt Linearkombination von $\vec{v}_1, \dots, \vec{v}_m$.

### Definition: Lineare Hülle (Spann)
Die **Lineare Hülle** (oder der **Spann**) ist die Menge _aller_ möglichen Linearkombinationen, die man aus einer gegebenen Menge von Vektoren bilden kann. 
$$\text{Lin}(\vec{v}_1, \dots, \vec{v}_m) = \{ c_1\vec{v}_1 + \dots + c_m\vec{v}_m \mid c_1, \dots, c_m \in \mathbb{R} \}$$
Man sagt auch: Der Raum wird von diesen Vektoren **aufgespannt**. 

### Wichtige Eigenschaften des Spanns
- **Lemma 6.3:** Der Spann $\text{Lin}(\vec{v}_1, \dots, \vec{v}_m)$ ist immer der **kleinste lineare Unterraum**, der die Vektoren $\vec{v}_1, \dots, \vec{v}_m$ enthält. 
- **Beispiele:**
    - $\text{Lin}(\vec{w})$ (mit $\vec{w} \neq \vec{0}$) ist eine **Ursprungsgerade**. 
    - $\text{Lin}(\vec{v}, \vec{w})$ ist eine **Ursprungsebene**, _falls_ $\vec{v}$ und $\vec{w}$ nicht kollinear sind.
    - Die Einheitsvektoren $\vec{e}_1, \dots, \vec{e}_n$ spannen den gesamten $\mathbb{R}^n$ auf: $\text{Lin}(\vec{e}_1, \dots, \vec{e}_n) = \mathbb{R}^n$. 

---

## 3. Verbindung zu Linearen Gleichungssystemen (LGS)

### A $\vec{x}$ als Linearkombination
Das Matrix-Vektor-Produkt $A\vec{x}$ kann man als Linearkombination der **Spaltenvektoren** von $A$ (hier $\vec{s}_1, \dots, \vec{s}_n$ genannt) mit den Koeffizienten aus $\vec{x}$ lesen: 15

$$A\vec{x} = \begin{pmatrix} | & & | \\ \vec{s}_1 & \dots & \vec{s}_n \\ | & & | \end{pmatrix} \begin{pmatrix} x_1 \\ \vdots \\ x_n \end{pmatrix} = x_1\vec{s}_1 + \dots + x_n\vec{s}_n$$

### Satz 6.5 (Lösbarkeit eines LGS)
Ein LGS $A\vec{x} = \vec{b}$ ist **genau dann lösbar**, wenn der Vektor der rechten Seite $\vec{b}$ eine Linearkombination der Spaltenvektoren von $A$ ist. 17Oder anders gesagt: $A\vec{x} = \vec{b}$ ist lösbar $\iff \vec{b} \in \text{Lin}(\vec{s}_1, \dots, \vec{s}_n)$.

---

## 4. Affine Unterräume

**Definition:** Ein **affiner Unterraum** $W$ ist ein "verschobener" linearer Unterraum $U$. 
$$W = \vec{v} + U = \{ \vec{v} + \vec{u} \mid \vec{u} \in U \}$$
Dabei ist $\vec{v}$ ein beliebiger Stützvektor. 

- **Lösungsraum eines LGS:** Der Lösungsraum $L$ eines LGS $A\vec{x} = \vec{b}$ ist immer ein affiner Unterraum. 21Er hat die Form $L = \vec{v} + L_0$, wobei $\vec{v}$ eine beliebige spezielle Lösung ist und $L_0$ der Lösungsraum des _homogenen_ Systems $A\vec{x} = \vec{0}$ ist. 22

- **Lemma 6.7:** Ein affiner Unterraum ist genau dann auch ein linearer Unterraum, wenn er den Nullvektor $\vec{0}$ enthält. 23

---

## 5. Lineare Unabhängigkeit

**Motivation:** Manchmal sind Vektoren in einer Menge "überflüssig". 24Z.B. wenn $\vec{v}_3 = \frac{1}{2}(\vec{v}_1 + \vec{v}_2)$, dann ist $\text{Lin}(\vec{v}_1, \vec{v}_2, \vec{v}_3) = \text{Lin}(\vec{v}_1, \vec{v}_2)$. 

### Definition: Lineare Relation

Eine Darstellung des Nullvektors als Linearkombination:
$$c_1\vec{v}_1 + \dots + c_m\vec{v}_m = \vec{0}$$

- **Triviale Relation:** Die offensichtliche Lösung, bei der alle Koeffizienten $c_1, \dots, c_m = 0$ sind.
- **Nicht-triviale Relation:** Eine Lösung, bei der **mindestens ein** Koeffizient $c_i \neq 0$ ist. 

### Definition: Lineare (Un-)Abhängigkeit

- **Linear ABHÄNGIG:** Ein System von Vektoren heißt linear abhängig, wenn eine **nicht-triviale** lineare Relation existiert. (Mindestens ein Vektor ist "überflüssig", da er als LK der anderen darstellbar ist).

- **Linear UNABHÄNGIG:** Ein System heißt linear unabhängig, wenn die **einzige** lineare Relation die **triviale** ist. 


#### Anwendbare Formel für Unabhängigkeit:

Um $(\vec{v}_1, \dots, \vec{v}_m)$ auf lineare Unabhängigkeit zu prüfen, löst man die Gleichung:

$$c_1\vec{v}_1 + \dots + c_m\vec{v}_m = \vec{0}$$

Wenn die **einzige** Lösung $c_1 = \dots = c_m = 0$ ist, sind sie linear unabhängig.