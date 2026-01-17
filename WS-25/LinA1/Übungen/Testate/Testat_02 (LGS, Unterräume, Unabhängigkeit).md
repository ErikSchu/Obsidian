#lina1
## 1. LGS Lösen mit Gaußalgorithmus

Zentrale Rechentechnik: LGS in Matrix und mit **drei elementaren Zeilenumformungen** auf **Zeilenstufenform** bringen.

### Typische Testat-Frage:

*Gegeben sei ein LGS (oft mit einem Parameter $a$):*
$$
\begin{align*}
x_1 + 2x_2 + ax_3 &= 1 \\
x_1 + x_2 - x_3 &= 2 \\
\dots
\end{align*} 
$$
*a) Bringen Sie die erweiterte Koeffizientenmatrix auf Zeilenstufenform.*
*b) Für welche Werte von $a$ ist das System unlösbar / eindeutig lösbar / mehrdeutig lösbar?*

### Lösungsweg (Algorithmus):

1.  **Aufschreiben:** LGS als **erweiterte Koeffizientenmatrix** notieren.

2.  **Umformen (Satz 4.3):** Wende die 3 Umformungen (Zeilen tauschen, Zeile skalieren, Zeilen addieren) an, bis du die Zeilenstufenform erreichst.

3.  **Ablesen (Die Fallunterscheidung):** Schau dir die **letzte(n) Zeile(n)** deiner fertigen Matrix an:
    * **(a) Keine Lösung:** Widerspruchszeile (Typ B) der Form `(0 0 ... 0 | c)` mit $c \neq 0$. Das ist die Gleichung $0 = c$, was unlösbar ist.
    * **(c) Unendlich viele Lösungen:** Du hast eine "Nullzeile" der Form `(0 0 ... 0 | 0)`. Das ist die Gleichung $0 = 0$, eine wahre Aussage, die keine Bedingung stellt. Die Spalten *ohne* Stufe (ohne führende 1) sind deine **freien Unbekannten**.
    * **(b) Genau eine Lösung:** Es gibt keine Widerspruchszeile und keine freien Unbekannten (d.h. $n$ Stufen für $n$ Unbekannte).

---
## 2. Matrix-Vektor-Produkt & Lösbarkeit 

→ Was bedeutet $A\vec{x} = \vec{b}$ ?

### Wichtig:

* **Matrix-Vektor-Produkt $A\vec{x}$:** Ist die Kurzschrift für ein LGS. Es gibt zwei Sichten:
    1.  **Algebraisch (Statisch):** Ein System, das man löst.
    2.  **Geometrisch (Dynamisch):** Eine **Abbildung** (Funktion), die einen Vektor $\vec{x}$ auf einen neuen Vektor $\vec{b}$ abbildet.

* **$A\vec{x}$ als Linearkombination:** Das Produkt $A\vec{x}$ ist dasselbe wie eine **Linearkombination der Spaltenvektoren von $A$**, mit den Einträgen von $\vec{x}$ als Koeffizienten.

* **Satz 6.5 (Lösbarkeit):** Das LGS $A\vec{x} = \vec{b}$ ist **genau dann lösbar**, wenn $\vec{b}$ eine Linearkombination der Spalten von $A$ ist (oder: $\vec{b}$ liegt im Spann der Spalten).

* **Lösungsraum $L$:** Ist die Menge aller $\vec{x}$, die $A\vec{x}=\vec{b}$ lösen. Er ist der **Durchschnitt ($\cap$)** der Lösungsmengen $L_i$ der einzelnen Gleichungen.

### Typische Testat-Frage:
*Gegeben sei $A = \begin{pmatrix} 1 & 2 \\ 2 & 4 \end{pmatrix}$ und $\vec{b} = \begin{pmatrix} 3 \\ 5 \end{pmatrix}$. Ist das LGS $A\vec{x} = \vec{b}$ lösbar? (Begründen Sie, ohne Gauß zu verwenden.)*

### Lösungsweg:

1.  **Satz 6.5 anwenden:** Die Frage ist, ob $\vec{b}$ im Spann der Spalten $\vec{s}_1 = \begin{pmatrix} 1 \\ 2 \end{pmatrix}$ und $\vec{s}_2 = \begin{pmatrix} 2 \\ 4 \end{pmatrix}$ liegt.

2.  **Spann analysieren:** $\text{Lin}(\vec{s}_1, \vec{s}_2) = \text{Lin}(\begin{pmatrix} 1 \\ 2 \end{pmatrix}, \begin{pmatrix} 2 \\ 4 \end{pmatrix})$.

3.  **Beobachten:** $\vec{s}_2$ ist $2 \cdot \vec{s}_1$ (sie sind kollinear). Der Spann ist also nur die Ursprungsgerade, die durch $\begin{pmatrix} 1 \\ 2 \end{pmatrix}$ geht.

4.  **Prüfen:** Liegt $\vec{b} = \begin{pmatrix} 3 \\ 5 \end{pmatrix}$ auf dieser Geraden? Gibt es ein $c$, sodass $c \cdot \begin{pmatrix} 1 \\ 2 \end{pmatrix} = \begin{pmatrix} 3 \\ 5 \end{pmatrix}$?
    * $c \cdot 1 = 3 \implies c = 3$
    * $c \cdot 2 = 5 \implies c = 2.5$

5.  **Fazit:** *Widerspruch.* $\vec{b}$ liegt nicht im Spann der Spalten. Laut Satz 6.5 ist das LGS **unlösbar**.

---
## 3. Lineare Unterräume

### Wichtig:
Eine Teilmenge $U \subseteq \mathbb{R}^n$ ist ein **linearer Unterraum**, wenn sie 3 Kriterien erfüllt:

1.  **(NUL):** $\vec{0} \in U$ (Der Nullvektor muss drin sein).

2.  **(ADD):** $U$ ist abgeschlossen bzgl. Addition (Wenn $\vec{u}, \vec{v} \in U$, muss auch $\vec{u}+\vec{v} \in U$ sein).

3.  **(SKM):** $U$ ist abgeschlossen bzgl. Skalarmultiplikation (Wenn $\vec{u} \in U$ und $c \in \mathbb{R}$, muss auch $c\vec{u} \in U$ sein).

* **WICHTIG:** Der Lösungsraum $L_0$ eines **homogenen** LGS ($A\vec{x} = \vec{0}$) ist **immer** ein linearer Unterraum.

### Typische Testat-Frage:
*Ist $U = \{\begin{pmatrix} x_1 \\ x_2 \end{pmatrix} \in \mathbb{R}^2 \mid x_1 - x_2 = 0\}$ ein linearer Unterraum? Beweisen Sie es.*

### Lösungsweg:
1.  **Prüfe (NUL):** Liegt $\vec{0} = \begin{pmatrix} 0 \\ 0 \end{pmatrix}$ in $U$?
    * Setze ein: $x_1 - x_2 = 0 - 0 = 0$. Die Gleichung ist erfüllt.
    * **Ja, $\vec{0} \in U$.**

2.  **Prüfe (ADD):** Seien $\vec{u} = \begin{pmatrix} u_1 \\ u_2 \end{pmatrix} \in U$ und $\vec{v} = \begin{pmatrix} v_1 \\ v_2 \end{pmatrix} \in U$.
    * Was weißt du? $u_1 - u_2 = 0$ (A) und $v_1 - v_2 = 0$ (B).
    * Was musst du zeigen? Gilt $\vec{u}+\vec{v} = \begin{pmatrix} u_1+v_1 \\ u_2+v_2 \end{pmatrix} \in U$?
    * Prüfe die Bedingung: $(u_1+v_1) - (u_2+v_2) = (u_1-u_2) + (v_1-v_2)$.
    * Setze (A) und (B) ein: $= 0 + 0 = 0$.
    * **Ja, (ADD) ist erfüllt.**

3.  **Prüfe (SKM):** Sei $\vec{u} \in U$ und $c \in \mathbb{R}$.
    * Was weißt du? $u_1 - u_2 = 0$.
    * Was musst du zeigen? Gilt $c\vec{u} = \begin{pmatrix} cu_1 \\ cu_2 \end{pmatrix} \in U$?
    * Prüfe die Bedingung: $(cu_1) - (cu_2) = c \cdot (u_1 - u_2)$.
    * Setze ein: $c \cdot (0) = 0$.
    * **Ja, (SKM) ist erfüllt.**

4.  **Fazit:** *Da alle drei Kriterien erfüllt sind, ist $U$ ein linearer Unterraum.*

---
## 4. Lineare Unabhängigkeit
### Begriffe
* **Lineare Relation:** Eine Gleichung der Form $c_1\vec{v}_1 + \dots + c_m\vec{v}_m = \vec{0}$.
* **Triviale Relation:** Die offensichtliche Lösung, bei der alle $c_i = 0$ sind.
* **Linear Unabhängig:** Ein System von Vektoren ist l.u., wenn die triviale Relation die **einzige** Lösung ist. (Kein Vektor ist "überflüssig").
* **Linear Abhängig:** Ein System ist l.a., wenn es eine **nicht-triviale** Relation gibt (mind. ein $c_i \neq 0$). (Mindestens ein Vektor ist "überflüssig").

### Typische Testat-Frage (Satz 7.4):
*Sind die Vektoren $\vec{v}_1 = \begin{pmatrix} 1 \\ 1 \\ 0 \end{pmatrix}$, $\vec{v}_2 = \begin{pmatrix} 0 \\ 1 \\ 1 \end{pmatrix}$, $\vec{v}_3 = \begin{pmatrix} 1 \\ 0 \\ -1 \end{pmatrix}$ linear unabhängig?*

### Lösungsweg:

1.  **Ansatz:** Prüfe, ob die Relation $c_1\vec{v}_1 + c_2\vec{v}_2 + c_3\vec{v}_3 = \vec{0}$ nur die triviale Lösung $c_1=c_2=c_3=0$ hat.

2.  **LGS aufstellen (Satz 7.4):** Das ist ein **homogenes LGS**, bei dem die Vektoren die Spalten bilden:
$$
\begin{pmatrix}
1 & 0 & 1 \\
1 & 1 & 0 \\
0 & 1 & -1
\end{pmatrix}
\begin{pmatrix} c_1 \\ c_2 \\ c_3 \end{pmatrix} =
\begin{pmatrix} 0 \\ 0 \\ 0 \end{pmatrix}
$$

3.  **Lösen (Gauß):** Bringe die Matrix auf Zeilenstufenform.
    $\begin{pmatrix} 1 & 0 & 1 \\ 1 & 1 & 0 \\ 0 & 1 & -1 \end{pmatrix} \to \begin{pmatrix} 1 & 0 & 1 \\ 0 & 1 & -1 \\ 0 & 1 & -1 \end{pmatrix} \to \begin{pmatrix} 1 & 0 & 1 \\ 0 & 1 & -1 \\ 0 & 0 & 0 \end{pmatrix}$

4.  **Lösung ablesen:** Du hast eine Nullzeile! $c_3$ ist eine **freie Variable**. Das System hat unendlich viele Lösungen (z.B. $c_3=1, c_2=1, c_1=-1$).

5.  **Fazit:** Es existiert eine nicht-triviale Relation (z.B. $-1\vec{v}_1 + 1\vec{v}_2 + 1\vec{v}_3 = \vec{0}$). Die Vektoren sind **linear abhängig**.