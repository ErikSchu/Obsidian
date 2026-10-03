#lina1 **Freitag**, 24.10.2025
## 1. Aussagenlogik

Jede mathematische Aussage hat einen Wahrheitswert: **wahr** oder **falsch**. Aussagen können logisch verknüpft werden.

|**Verknüpfung**|**Symbol**|**Bedeutung**|
|---|---|---|
|**Konjunktion**|$P \land Q$|"P **und** Q"|
|**Disjunktion**|$P \lor R$|"P **oder** R" (nicht-ausschließend)|
|**Negation**|$\neg P$|"**Nicht** P"|
|**Implikation**|$P \implies R$|"**Wenn** P, **dann** R"|
|**Äquivalenz**|$P \iff Q$|"P **genau dann, wenn** Q"|

### Wichtige Konzepte der Logik

#### Die Implikation ($P \implies Q$)

Ist **nur dann falsch, wenn die Prämisse (P) wahr ist, aber die Konklusion (Q) falsch ist**. 
In allen anderen Fällen (auch wenn die Prämisse falsch ist) ist die Implikation als Ganzes logisch wahr.


#### Kontraposition

Die Aussage $P \implies Q$ ist logisch äquivalent zu ihrer **Kontraposition** $\neg Q \implies \neg P$. Das ist eine extrem nützliche Beweistechnik.

- **Anwendungsbeispiel (Injektivität):**
    - **Definition:** $f$ ist injektiv, wenn $\forall x,x' \in X: (x \ne x' \implies f(x) \ne f(x'))$.
    - **Beweis mit Kontraposition:** Es ist oft einfacher zu zeigen: $\forall x,x' \in X: (f(x) = f(x') \implies x = x')$.

---

## 2. Prädikate und Quantoren

- **Allquantor ($\forall$):** "Für alle...".

- **Existenzquantor ($\exists$):** "Es existiert (mindestens) ein...".


#### Reihenfolge ist entscheidend!

Die Bedeutung einer Aussage ändert sich komplett, wenn man die Reihenfolge der Quantoren vertauscht.

- $\forall x \in \mathbb{R} \ \exists n \in \mathbb{N}: n > x$ (Wahr: Zu jeder reellen Zahl gibt es eine größere natürliche Zahl).

- $\exists n \in \mathbb{N} \ \forall x \in \mathbb{R}: n > x$ (Falsch: Es gibt keine natürliche Zahl, die größer als alle reellen Zahlen ist).


#### Negation von Quantoren

Beim Verneinen einer Aussage dreht sich der Quantor um und die innere Aussage wird negiert.

- $\neg(\forall x \in M: P(x)) \iff \exists x \in M: \neg P(x)$

- $\neg(\exists x \in M: P(x)) \iff \forall x \in M: \neg P(x)$

---

## 3. Lineare Gleichungssysteme (LGS)

### Lineare Gleichung

Eine einzelne lineare Gleichung hat die Form:

$$a_1x_1 + a_2x_2 + \dots + a_nx_n = b$$

wobei die $a_i$ und $b$ gegebene reelle Zahlen sind und die $x_i$ die Unbekannten.

#### Drei Lösungsfälle für eine Gleichung:

1. **(A) Lösbar:** Mindestens ein Koeffizient $a_k \ne 0$. Man kann nach $x_k$ auflösen. Alle anderen Variablen sind frei wählbar.

2. **(B) Unlösbar:** Alle Koeffizienten $a_i = 0$, aber die rechte Seite $b \ne 0$. Die Gleichung lautet dann $0 = b$, was ein Widerspruch ist.

3. **(C) Immer erfüllt:** Alle Koeffizienten $a_i = 0$ und auch $b=0$. Die Gleichung lautet $0=0$ und stellt keine Bedingung an die Variablen.


### Das Gaußsche Eliminationsverfahren

Dies ist der Standardalgorithmus zum Lösen von LGS. Man überführt die **erweiterte Koeffizientenmatrix** in **Zeilenstufenform**.

#### Erweiterte Koeffizientenmatrix

Das LGS wird als Matrix geschrieben, wobei die rechte Seite der Gleichungen durch einen Strich abgetrennt wird.

$$\begin{pmatrix} a_{11} & \dots & a_{1n} & | & b_1 \\ \vdots & \ddots & \vdots & | & \vdots \\ a_{m1} & \dots & a_{mn} & | & b_m \end{pmatrix}$$

#### Drei Elementare Zeilenumformungen

Diese Umformungen ändern die Lösungsmenge des LGS nicht.

- **(I)** Vertauschen zweier Zeilen.

- **(II)** Multiplikation einer Zeile mit einer Konstanten $c \ne 0$.

- **(III)** Addition des c-fachen einer Zeile zu einer anderen Zeile.

---

## 4. [[Beweistechniken]]