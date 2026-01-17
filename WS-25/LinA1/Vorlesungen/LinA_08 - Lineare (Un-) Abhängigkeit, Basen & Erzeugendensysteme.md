#lina1

## §7.1 Lineare Unabhängigkeit

### 7.4 Satz (Kriterium für lineare Unabhängigkeit)

Genau dann ist ein System $(\vec{v}_1, \dots, \vec{v}_m)$ von Vektoren in $\mathbb{R}^n$ linear unabhängig, wenn das homogene LGS $A\vec{x} = \vec{0}$ mit $A = (\vec{v}_1 \dots \vec{v}_m)$ (als Spalten) nur die **triviale Lösung** (die Nulllösung, $\vec{x}=\vec{0}$) hat.

**Beweis-Ansatz:**
Die Gleichung $A\vec{x} = \vec{0}$ ist dasselbe wie $x_1\vec{v}_1 + \dots + x_m\vec{v}_m = \vec{0}$.
Eine "Lösung" $\vec{x}$ ist also exakt dasselbe wie eine "lineare Relation".
Das System ist linear unabhängig $\iff$ die einzige Relation die triviale ist ($c_i=0$ für alle $i$).
Das LGS hat nur die triviale Lösung $\iff$ die einzige Lösung $x_i=0$ für alle $i$ ist.

### 7.5 Beispiele

***(a)*** Die **Einheitsvektoren** $(\vec{e}_1, \dots, \vec{e}_n)$ sind linear unabhängig. Das zugehörige LGS ist $x_1=0, \dots, x_n=0$, was nur die triviale Lösung hat.

***(b)*** Ein System, in dem der **Nullvektor** vorkommt, ist **immer linear abhängig**.
    - Z.B. $(\vec{v}_1, \vec{v}_2, \dots, \vec{v}_m)$ mit $\vec{v}_1 = \vec{0}$.
	- Dann ist $1 \cdot \vec{v}_1 + 0 \cdot \vec{v}_2 + \dots + 0 \cdot \vec{v}_m = \vec{0}$ eine nicht-triviale Relation.

***(c)*** Ein System, in dem derselbe Vektor **mehr als einmal** vorkommt, ist **immer linear abhängig**.
	- Z.B. $\vec{v}_1 = \vec{v}_2$.
    - Dann ist $1 \cdot \vec{v}_1 + (-1) \cdot \vec{v}_2 + 0 \cdot \dots = \vec{0}$ eine nicht-triviale Relation.
***(d)*** Ein System aus zwei Vektoren $(\vec{v}, \vec{w})$ (beide $\neq \vec{0}$) ist genau dann linear abhängig, wenn sie **kollinear** sind (also $\vec{v} = c\vec{w}$).

### 7.6 Satz

***(a)*** Genau dann ist $(\vec{v}_1, \dots, \vec{v}_m)$ linear abhängig, wenn es einen Index $k$ gibt, sodass $\vec{v}_k$ eine Linearkombination der *anderen* Vektoren ist. Man kann $\vec{v}_k$ also weglassen, ohne den Spann zu ändern:
    $\text{Lin}(\vec{v}_1, \dots, \vec{v}_m) = \text{Lin}(\vec{v}_1, \dots, \vec{v}_{k-1}, \vec{v}_{k+1}, \dots, \vec{v}_m)$.

***(b)*** Sind $(\vec{v}_1, \dots, \vec{v}_m)$ linear unabhängig und ist $\vec{v}_{m+1}$ ein Vektor mit $\vec{v}_{m+1} \notin \text{Lin}(\vec{v}_1, \dots, \vec{v}_m)$, dann ist auch das System $(\vec{v}_1, \dots, \vec{v}_m, \vec{v}_{m+1})$ linear unabhängig.

---

## §7.2 Basen

### Definition
Es sei $U \subseteq \mathbb{R}^n$ ein linearer Unterraum.

***(a)*** Ein System $(\vec{v}_1, \dots, \vec{v}_m)$ von Vektoren aus $U$ mit $U = \text{Lin}(\vec{v}_1, \dots, \vec{v}_m)$ heißt ein **Erzeugendensystem** von $U$.

***(b)*** Eine **Basis** von $U$ ist ein **linear unabhängiges Erzeugendensystem** von $U$.

### 7.7 Beispiele
***(a)*** Die Einheitsvektoren $(\vec{e}_1, \dots, \vec{e}_n)$ sind eine Basis von $\mathbb{R}^n$. Sie heißt **Standardbasis**.
    * Sie sind ein Erzeugendensystem, da $\vec{x} = x_1\vec{e}_1 + \dots + x_n\vec{e}_n$.
    * Sie sind linear unabhängig (siehe 7.5a).

### 7.8 Satz (Basisauswahlsatz)
Seien $\vec{v}_1, \dots, \vec{v}_m \in \mathbb{R}^n$ und sei $U = \text{Lin}(\vec{v}_1, \dots, \vec{v}_m)$. Dann gibt es unter den Vektoren $\vec{v}_1, \dots, \vec{v}_m$ eine Basis von $U$.
**Beweis-Ansatz:**
* Wenn $(\vec{v}_1, \dots, \vec{v}_m)$ linear unabhängig sind, sind sie bereits eine Basis.
* Andernfalls sind sie linear abhängig. Nach Satz 7.6(a) können wir (mindestens) einen Vektor $\vec{v}_k$ weglassen, ohne den Spann $U$ zu ändern.
* Diesen Schritt wiederholen wir, bis das verbleibende System linear unabhängig ist. Dieses System ist dann eine Basis.

### 7.9 Satz (Charakterisierungen einer Basis)
Sei $U \subseteq \mathbb{R}^n$ ein linearer Unterraum und $(\vec{v}_1, \dots, \vec{v}_m)$ ein System von Vektoren aus $U$. Dann sind folgende Aussagen äquivalent:

(1) $(\vec{v}_1, \dots, \vec{v}_m)$ ist eine **Basis** von $U$.
(2) Jeder Vektor $\vec{u} \in U$ hat eine **eindeutige Darstellung** $\vec{u} = c_1\vec{v}_1 + \dots + c_m\vec{v}_m$ als Linearkombination.
(3) Das System ist ein **minimales Erzeugendensystem** (d.h. erzeugend und nicht verkürzbar; kein echtes Teilsystem erzeugt $U$).
(4) Das System ist **maximal linear unabhängig** (d.h. linear unabhängig und nicht verlängerbar; für jedes $\vec{w} \in U \setminus \{\vec{v}_1, \dots, \vec{v}_m\}$ ist das System $(\vec{v}_1, \dots, \vec{v}_m, \vec{w})$ linear abhängig).