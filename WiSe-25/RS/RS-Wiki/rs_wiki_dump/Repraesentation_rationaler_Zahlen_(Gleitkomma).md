 
**Idee:** Ähnlich zur wissenschaftlichen Notation (z.B. $2025 = 2.025 \cdot 10^3$), aber auf Basis 2.

**Allgemeine Form (Basis 2):**
$$
z = (-1)^s \cdot m \cdot 2^e
$$
* **$s$**: Vorzeichenbit (0 = positiv, 1 = negativ)
* **$m$**: **Mantisse** (der Wert bzw. die "Ziffern")
* **$e$**: **Exponent** (bestimmt die Kommaposition)

---

## Normalisierung

Um Eindeutigkeit zu gewährleisten, wird die Mantisse normalisiert.
* **Basis 10:** $1 \le m < 10$ (z.B. $2.025 \cdot 10^3$)
* **Basis 2:** $1 \le m < 2$ (z.B. $1.011... \cdot 2^e$)

> [!IMPORTANT] Die implizite 1
> Bei einer normalisierten Binärzahl (außer der Null) ist die Ziffer *vor* dem Komma **immer** eine 1.
> Da sie immer da ist, muss man sie nicht extra speichern. Man spart 1 Bit.

---

## IEEE-754 Standard

Der weltweite Standard (von 1985) zur Implementierung von Gleitkommazahlen.

### Aufbau (z.B. 32-Bit "Single Precision")

Eine 32-Bit-Zahl wird aufgeteilt in:
1.  **Vorzeichen $s$** (1 Bit)
2.  **Exponent $E$** (8 Bit)
3.  **Mantisse $m$** (23 Bit)

|  $s$  | Exponent $E$ | Mantisse $m$ |
| :---: | :----------: | :----------: |
| 1 Bit |    8 Bits    |   23 Bits    |

### Berechnung des Werts

**1. Exponent (Exzessdarstellung):**
* Der gespeicherte 8-Bit-Exponent $E$ ist eine vorzeichenlose Zahl (0-255).
* Um negative Exponenten zu erlauben, wird ein **Bias** (eine Verschiebung) verwendet.
* Bias (für 32-Bit): $b = 2^{8-1} - 1 = 127$
* Der *tatsächliche* Exponent $e$ ist: **$e = E - Bias$** (also $e = E - 127$)

**2. Mantisse (Implizite 1):**
* Die gespeicherten 23 Bits $m$ sind nur die Ziffern *nach* dem Komma.
* Die *tatsächliche* Mantisse ist: **$1.m$** (die implizite 1 wird davor gesetzt).

**Gesamtformel (Normalisierter Fall):**
$$
z = (-1)^s \cdot (1.m) \cdot 2^{E - 127}
$$

---

## Besondere Zahlen im IEEE-754

Der Standard reserviert spezielle Werte für Exponent $E$ und Mantisse $m$, um Sonderfälle darzustellen.

![[Pasted image 20251021171153.png]]

> [!WARNING] Rundungsfehler
> * Nicht alle Zahlen (selbst $0.2$) sind exakt darstellbar.
> * Dies führt zu Rundungsfehlern.
> * Das **Assoziativgesetz gilt nicht** mehr: `(a + b) + c` ist nicht notwendigerweise gleich `a + (b + c)`!