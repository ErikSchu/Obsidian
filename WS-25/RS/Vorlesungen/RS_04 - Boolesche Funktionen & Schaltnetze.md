#rs Donnerstag, 23.10.2025
https://rs.cs.tu-dortmund.de/RS1/V03-handout.html

![[Pasted image 20251023093959.png]]

## Einleitung

### Boolesche Funktionen: Aussagenlogik (Propositional calculus)

- **Satz** ist eine Aussage mit eindeutigem Wahrheitswert
- Wahrheitswert → WAHR / FALSCH
- **Neue Aussagen** entstehen durch **Verknüpfungen** von Aussagen
- Verknüpfungen
	- **Negation** ($\neg$) "nicht"
	- **Konjunkrion** ($\land$) "und"
	- **Disjunktion** ($\lor$) "oder"


### Definition der Verknüpfungen
Seien A, B zwei Aussagen

**Definition Negation**

| A      | $\neg$ A |
| ------ | -------- |
| falsch | wahr     |
| wahr   | falsch   |

**Definition Konjunktion**

| A      | B      | A $\land$ B |
| ------ | ------ | ----------- |
| falsch | falsch | falsch      |
| falsch | wahr   | falsch      |
| wahr   | falsch | falsch      |
| wahr   | wahr   | wahr        |

**Definition Disjunktion**

| A      | B      | A $\lor$ B |
| ------ | ------ | ---------- |
| falsch | falsch | falsch     |
| falsch | wahr   | wahr       |
| wahr   | falsch | wahr       |
| wahr   | wahr   | wahr       |

Wie lässt sich der Aussagenlogische Ausdruck $x \lor \neg x$ auch darstellen?

---
## Boolesche Algebra

Eine **bolsche Algebra** ist eine spezielle algebraische Struktur
- Eigenschaften der **logischen Operatoren** **UND**, **ODER**, **NICHT** und die
- Eigenschaften der **mengentheoretischen Verknüpfungen** **Durchschnitt**, **Vereinigung**, **Komplement** verallgemeinert.

Wir nennen $(B, \cup, \cap, \overline{\ })$ mit $B=\{0, 1\}$ und
- $x \cup y = max(x, y)$
- $x \cap y = min(x, y)$
- $\overline{x} = 1 - x$
für alle \(x, y \in B\) eine **boolesche Algebra**.

#### Entsprechungen zur aussagenlogik
- Falsch $\Leftrightarrow$ 0
- Wahr $\Leftrightarrow$ 1
- $\land \Leftrightarrow \cap$
- $\lor \Leftrightarrow \cup$
- $\neg \Leftrightarrow \overline{\ }$

---
#### Satz
In der booleschen Algebra $(B, \cup, \cap, \overline{\ })$ für alle $x, y, z \in B$:

- **Kommutativität:**
    - $x \cup y = y \cup x$
    - $x \cap y = y \cap x$

- **Assoziativität:**
    - $(x \cup y) \cup z = x \cup (y \cup z)$
    - $(x \cap y) \cap z = x \cap (y \cap z)$

- **Distributivität:**
    - $x \cap (y \cup z) = (x \cap y) \cup (x \cap z)$
    - $x \cup (y \cap z) = (x \cup y) \cap (x \cup z)$

- **Neutralelement:**
    - $x \cup 0 = x$
    - $x \cap 1 = x$

- **Nullelement:**
    - $x \cup 1 = 1$
    - $x \cap 0 = 0$

- **Idempotenz:**
    - $x = x \cup x$
    - $x = x\cap x$

- **Involution:**
    - $x = \overline{\overline{x}}$

- **Absorption:**
    - $(x \cup y) \cap x = x$
    - $(x \cap y) \cup x = x$

- **Resolution:**
    - $(x \cup y) \cap (\overline{x} \cup y) = y$
    - $(x \cap y) \cup (\overline{x} \cap y) = y$

- **Komplementarität:**
    - $y \cap \overline{y} = 0 \Leftrightarrow x \cup (y \cap \overline{y}) = x$
    - $y \cup \overline{y} = 1 \Leftrightarrow x \cap (y \cup \overline{y}) = x$

- **De Morgan:**
    - $\overline{x \cup y} = \overline{x} \cap \overline{y}$
    - $\overline{x \cap y} = \overline{x} \cup \overline{y}$
---

### Wie beweist man einzelne Rechengesetze?
Wir stellen eine Wertetabelle auf.
**Beispiel: Absorption** $(x \cup y) \cap x = x$
![[Pasted image 20251105182234.png]]

### Kombinatorik
Seien $m, n \in \mathbb{N}$ und $B$ eine boolesche Algebra. Eine Funktion $f: B^n \rightarrow B^m$ heißt **boolesche Funktion**.

#### Notation
- $B^n =$ Menge aller n-stelligen Tupel über B
- Beispiel $B^1 = B = \{(0), (1)\}$
- Beispiel $B^2 = \{(0, 0), (0, 1), (1, 0), (1, 1)\}$
- Beispiel $B^3 = ...$

#### Anzahl boolescher Funktionen
- Boolesche Funktion $f: B^n \rightarrow B^m$ als Wertetabelle darstellbar, mit
- $|B^n| = 2^n$ **Zeilen**
- $|B^m| = 2^m$ **Funktionswerten pro Zeilen**  

$\rightarrow 2^{m^{2^n}} = 2^{m * 2^n}$ boolesche Funktionen für $f: B^n \rightarrow B^m$

#### Grundfunktion aus dem Bereich der booleschen Funktionen

| $x = 0$ | $x = 1$ | Funktion | Name             |                 |
| ------- | ------- | -------- | ---------------- | --------------- |
| $f_0$   | 0       | 0        | Konstante 0      | **Kontraktion** |
| $f_1$   | 0       | 1        | \(x\)            | **Identität**   |
| $f_2$   | 1       | 0        | \(\overline{x}\) | **Negation**    |
| $f_3$   | 1       | 1        | Konstante 1      | **Tautologie**  |

oder andere Sicht

| $x$      | $f_0$ | $f_1$          | $f_2$ | $f_3$ |
| -------- | ----- | -------------- | ----- | ----- |
| 0        | 0     | 1              | 0     | 1     |
| 1        | 0     | 0              | 1     | 1     |
| **Name** | 0     | $\overline{x}$ | $x$   | 1     |

#### Alle zweistelligen booleschen Grundfunktionen
![[Pasted image 20251023110503.png]]

|\(x_1\)|\(x_2\)|\(f_0\)|\(f_1\)|\(f_2\)|\(f_3\)|\(f_4\)|\(f_5\)|\(f_6\)|\(f_7\)|\(f_8\)|\(f_9\)|\(f_{10}\)|\(f_{11}\)|\(f_{12}\)|\(f_{13}\)|\(f_{14}\)|\(f_{15}\)|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|0|0|0|1|0|1|0|1|0|1|0|1|0|1|0|1|0|1|
|0|1|0|0|1|1|0|0|1|1|0|0|1|1|0|0|1|1|
|1|0|0|0|0|0|1|1|1|1|0|0|0|0|1|1|1|1|
|1|1|0|0|0|0|0|0|0|0|1|1|1|1|1|1|1|1|

### Im Folgenden werden wir diese Symbole verwenden:

- **Konjunktion (und):** $\land$
- **Disjunktion (oder):** $\lor$

- **Negation (nicht):** $\overline{\ }$
- **Antivalenz (XOR):** $\oplus$

I.d.R. abkürzende Notation der Konjunktion, z.B.: $\overline{x_1} \land x_2 \rightarrow \overline{x_1}x_2$  
  
Feste Folge der Funktionswerte, entsprechend des Wertes der Binärzahl:  
Beispiel: $f_6 = (0, 1, 1, 0)$ korrespondiert zu (siehe Tabelle)

| x   | y   | $f_6$ |
| --- | --- | ----- |
| 0   | 0   | 0     |
| 0   | 1   | 1     |
| 1   | 0   | 1     |
| 1   | 1   | 0     |

**Vorsicht bei der Notation**
$\overline{x_1x_2} \ne \overline{x_1}\ \overline{x_2}$ 

| $x_1$ | $x_2$ | $\overline{x_1x_2}$ | $\overline{x_1}\ \overline{x_2}$ |
| ----- | ----- | ------------------- | -------------------------------- |
| 0     | 0     | 1                   | 1                                |
| 0     | 1     | 1                   | 0                                |
| 1     | 0     | 1                   | 0                                |
| 1     | 1     | 0                   | 0                                |

# Skript "Jannis M." $\checkmark$ 

#### Übersetzung einer Wertetabelle in einer Formel

| Index | \(x_1\) | \(x_2\) | \(f\) |
| ----- | ------- | ------- | ----- |
| 0     | 0       | 0       | 0     |
| 1     | 0       | 1       | 1     |
| 2     | 1       | 0       | 0     |
| 3     | 1       | 1       | 1     |

$\rightarrow f(x_1, x_2) = (\overline{x_1} \land x_2) \lor (x_1 \land x_2)$

***Aber Wie?***
Funktion in Teilfunktionen zerlegen und Teilfunktionen verbinden

| Index | $x_1$ | $x_2$ | $m_1$ | $m_2$ |
| ----- | ----- | ----- | ----- | ----- |
| 0     | 0     | 0     | 0     | 0     |
| 1     | 0     | 1     | 1     | 0     |
| 2     | 1     | 0     | 0     | 0     |
| 3     | 1     | 1     | 0     | 1     |

$$\leftarrow \ Funktionen, \ die \ genau \ an \ einer \ Stelle \ 1 \ sind  \
\ f(x_1, x_2) = m_1(x_1, x_2) \lor m_3 (x_1, x_2)$$

### Einschlägige und nicht einschlägige Indizes
- Wir tragen die Werte der Argumente gemäß ihrer natürlichen Ordnung **(Index)** in eine Wertetabelle ein
- Ist der Funktionswert für einen Index = 1, nennen wir den Index **einschlägig**
- Ist der Funktionswert für einen Index = 0, nennen wir den Index **nicht einschlägig**

![[Pasted image 20251023111905.png]]

Ein **Minterm** ist nur mit Negationen und Konjunktionen darstellbar:
- Ist die Eingangsbelegung an der Stelle $x_{i} = 0$ setzen wir $\overline{x_{i}}$
- Ist die Eingangsbelegung an der Stelle $x_{i} = 1$ setzen wir $x_{i}$
- Und bilden dann die Konjunktion der Literale
	⤷ **Literal:** In der mathematischen Logik ist ein **Literal** eine atomare Aussage (Atom) oder die Negation einer atomaren Aussage. Hier also eine Variable oder die negierte Variable.

**Definition**
Die boolesche Funktion $x_{i}$ , für die nur der Index i einschlägig ist, heißt **Minterm** zum Index i.

![[Pasted image 20251023112327.png]]

|**Merkmal**|**Minterm (m)**|**Maxterm (M)**|
|---|---|---|
|**Logischer Typ**|**Produktterm** (UND-Verknüpfung, $\land$)|**Summenterm** (ODER-Verknüpfung, $\lor$)|
|**Zielwert des Terms**|Ergibt **1** für genau _eine_ Eingangskombination.|Ergibt **0** für genau _eine_ Eingangskombination.|
|**Nutzung (Wertetabelle)**|Für Zeilen, in denen die Funktion **f = 1** ist.<br><br>  <br><br>(sog. "einschlägige Indizes")|Für Zeilen, in denen die Funktion **f = 0** ist.<br><br>  <br><br>(sog. "nicht einschlägige Indizes")|
|**Bildungsregel** (für Index _i_)|Variable = **0** $\rightarrow$ **negiert** ($\overline{x}$)<br><br>  <br><br>Variable = **1** $\rightarrow$ **normal** ($x$)|Variable = **0** $\rightarrow$ **normal** ($x$)<br><br>  <br><br>Variable = **1** $\rightarrow$ **negiert** ($\overline{x}$)|
|**Standard-Normalform**|**Disjunktive Normalform (DNF)**|**Konjunktive Normalform (KNF)**|
|**Verknüpfung der Terme**|Alle Minterme werden mit **ODER** ($\lor$) verknüpft.|Alle Maxterme werden mit **UND** ($\land$) verknüpft.|

---

### Hinführung zu Normalformen
Für wie viele Eingaben liefert ein Minterm 1? Wie soeben gesehen für genau 1 Eingabe.

**Folgerungen**
- **Disjunktion** aller **Minterme** zu einschlägigen Indizes einer booleschen Funktion f ist wieder f
- **XOR-Verknüpfung** aller **Minterme** zu einschlägigen Indizes einer _booleschen Funktion_* f ist wieder f

*Minterme sind gesuchte Teilfunktionen*

#### Definition
Die Darstellung einer booleschen Funktion f als Disjunktion all ihrer Minterme zu einschlägigen Indizes heißt **Disjunktive Normalform (DNF).**

Die Darstellung einer booleschen Funktion f als XOR-Verknüpfung all ihrer Minterme zu einschlägigen Indizes heißt **Ringsummen-Normalform (RNF).**

**Anmerkung:** Normalformen sind **eindeutig**.

![[Pasted image 20251023112757.png]]

**Definition**
Eine Menge F von booleschen Funktionen heißt **funktional vollständig**, wenn sich jede boolesche Funktion durch Einsetzen und Komposition von Funktionen aus F darstellen lässt.
  
**Satz**
$F = \{\land, \lor, \overline{\ }\}$ ist **funktional vollständig.**

![[Pasted image 20251023113006.png]]![[Pasted image 20251023113041.png]]

- XOR und XNOR funktional unvollständig


![[Pasted image 20251023113328.png]]