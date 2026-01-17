#rs

---

## 1. Festkommadarstellung

**Konzept:** Die Position des Kommas ist fest vorgegeben. Eine Binärzahl mit $v$ Vorkommastellen und $m$ Nachkommastellen hat den Wert:

$$Wert = \sum_{i=-m}^{v-1} a_i \cdot 2^i$$

| **Eigenschaften** |                                                                                         |
| ----------------- | --------------------------------------------------------------------------------------- |
| **Vorteile (+)**  | Schnell, da nur Ganzzahl-Arithmetik benötigt wird, keine spezielle Fließkomma-Hardware. |
| **Nachteile (-)** | Unflexibel, sehr begrenzter Zahlenbereich, viele Zahlen nicht exakt darstellbar.        |

### Anwendbare Methoden

#### Binär (Festkomma) → Dezimal
Addiere die Stellenwerte $2^i$ für jede Position $i$, an der eine `1` steht.
**Beispiel:** $(101,11)_2$
- $1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0 + 1 \cdot 2^{-1} + 1 \cdot 2^{-2}$
- $= 4 + 0 + 1 + 0,5 + 0,25 = 5,75$
#### Dezimal → Binär (Festkomma)
1. **Vorkommateil:** Wandle den Teil vor dem Komma wie eine normale ganze Zahl in binär um.
2. **Nachkommateil:** Multipliziere den Teil nach dem Komma wiederholt mit 2. Die Ziffer vor dem Komma im Ergebnis ist die nächste Nachkommastelle. Wiederhole dies mit dem neuen Nachkommateil, bis das Ergebnis 0 ist oder die Genauigkeit erreicht ist.

**Beispiel:** $5,75$
1. **Vorkomma:** $5 \to (101)_2$
2. **Nachkomma:**
    - $0,75 \cdot 2 = \textbf{1},5$
    - $0,5 \cdot 2 = \textbf{1},0$
3. **Ergebnis:** $(101,11)_2$

---

## 2. Gleitkommadarstellung (nach IEEE 754) 🏆

Konzept: Eine Zahl wird in wissenschaftlicher Notation zur Basis 2 dargestellt:

$$z = (-1)^s \cdot m \cdot 2^e$$

Die Zahl wird in drei Teile zerlegt: Vorzeichen ($s$), Exponent ($e$) und Mantisse ($m$).

Struktur (z.B. 32-Bit "single precision"):
[ s | eeeeeeee | mmmmmmmmmmmmmmmmmmmmmmm ]
- 1 Bit Vorzeichen
- 8 Bit Exponent
- 23 Bit Mantisse

### Anwendbare Methoden
#### Dezimal → IEEE 754 (z.B. 32-Bit)
**Beispiel:** $z = -12,25$
1. **Vorzeichenbit (s):** Die Zahl ist negativ $\implies s = 1$.
2. **Betrag in Binär umwandeln:** $12,25 \to (1100,01)_2$.
3. **Normalisieren:** Verschiebe das Komma, bis nur noch eine `1` davorsteht. Zähle die Verschiebungen für den Exponenten.
    - $(1100,01)_2 = 1,10001 \cdot 2^3$.
    - Die Kommaverschiebung um **3 Stellen nach links** ergibt den Exponenten $e_{real} = 3$
4. **Mantisse (m) bestimmen:** Die Mantisse sind die Ziffern **nach dem Komma** in der normalisierten Form. Die führende `1` wird **nicht gespeichert** (implizite 1).
    - $m = 10001$.
    - Für 23 Bit wird mit Nullen aufgefüllt: `10001000000000000000000`.
5. **Exponent (e) kodieren:** Der Exponent wird in **Exzess-Darstellung** gespeichert.
    - Für 32-Bit ist der Bias $b = 2^{8-1}-1 = 127$.
    - $e_{gespeichert} = e_{real} + b = 3 + 127 = 130$.
    - $130$ in 8-Bit Binär umwandeln: $(10000010)_2$.
6. **Zusammensetzen:**
    - **s:** `1`
    - **e:** `10000010`
    - **m:** `10001000000000000000000`
    - **Ergebnis:** `1 10000010 10001000000000000000000`

#### IEEE 754 → Dezimal
**Beispiel:** `1 10000010 10001000000000000000000`
1. **Vorzeichen (s) ablesen:** `1` $\implies$ Die Zahl ist **negativ**.
2. **Exponent (e) dekodieren:**
    - Gespeicherter Exponent: $(10000010)_2 = 130$.
    - Realer Exponent: $e_{real} = e_{gespeichert} - b = 130 - 127 = 3$.
3. **Mantisse (m) rekonstruieren:**
    - Gespeicherte Mantisse: `10001...`
    - Rekonstruierte Mantisse (mit impliziter 1): $1,10001$.
4. **Zusammensetzen und umrechnen:**
    - $(-1)^1 \cdot (1,10001)_2 \cdot 2^3$
    - $= -1 \cdot (1100,01)_2$ (Komma um 3 Stellen nach rechts verschieben)
    - $= -(1 \cdot 2^3 + 1 \cdot 2^2 + 0 \cdot 2^1 + 0 \cdot 2^0 + 0 \cdot 2^{-1} + 1 \cdot 2^{-2})$
    - $= -(8 + 4 + 0 + 0 + 0 + 0,25) = -12,25$.

---

### Besondere Zahlen (nach IEEE 754)
Diese Werte werden durch spezielle Bitmuster im Exponenten reserviert.

|**Fall**|**Exponent**|**Mantisse**|**Bedeutung**|
|---|---|---|---|
|**Null**|alle `0`|alle `0`|$\pm 0$ (je nach Vorzeichenbit)|
|**Unendlich**|alle `1`|alle `0`|$\pm \infty$|
|**NaN** (Not a Number)|alle `1`|$\neq 0$|Ungültiges Ergebnis (z.B. $0/0$)|
|**Denormalisierte Zahlen**|alle `0`|$\neq 0$|Sehr kleine Zahlen nahe Null (implizite `0` statt `1`)|