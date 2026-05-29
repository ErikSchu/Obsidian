#rs

---

## Vorzeichen-Betrags-Darstellung (Sign-Magnitude)

- **Konzept:** Erstes Bit ist das Vorzeichen (`0`=+, `1`=−), der Rest (ℓ−1 Bits) ist der Betrag.
### Methoden

- **Dezimal → Binär:**
    1. Wandle den **Betrag** der Zahl in eine Binärzahl mit ℓ−1 Stellen um.
    2. Setze das **Vorzeichenbit** davor: `0` für positiv, `1` für negativ.

- **Binär → Dezimal:**
    1. Interpretiere das **erste Bit**: `0` bedeutet +, `1` bedeutet −.
    2. Wandle die restlichen ℓ−1 Bits (den Betrag) in eine Dezimalzahl um.
    3. Setze das Vorzeichen davor.

| **Dezimal** | **Binärdarstellung (5-Bit)** |
| ----------- | ---------------------------- |
| -7          | `10111`                      |
| -3          | `10011`                      |
| -1          | `10001`                      |
| **-0**      | **`10000`**                  |
| **+0**      | **`00000`**                  |
| 1           | `00001`                      |
| 3           | `00011`                      |
| 7           | `00111`                      |

---

## Exzess-Darstellung (Bias/Excess)

- **Konzept:** Eine Zahl z wird als die positive Zahl $z+b$ dargestellt. Der **Bias** ist meist $b=2ℓ−1$.
### Methoden

- **Dezimal → Binär:**
    1. Berechne den Wert $z+b$.
    2. Wandle dieses Ergebnis in eine Binärzahl mit ℓ Stellen um.

- **Binär → Dezimal:**
    1. Wandle die Binärzahl in eine Dezimalzahl um.
    2. Subtrahiere den Bias b vom Ergebnis.

|**Dezimal (z)**|**Binärdarstellung (5-Bit)**|
|---|---|
|-16|`00000`|
|-8|`01000`|
|-1|`01111`|
|**0**|**`10000`**|
|1|`10001`|
|7|`10111`|
|15|`11111`|

---

## Einerkomplement-Darstellung (One's Complement)

- **Konzept:** Negative Zahlen sind die bitweise Invertierung von positiven Zahlen.
- For a bit length of $\ell$, the range is from $-(2^{\ell-1}-1)$ to $2^{\ell-1}-1$.
### Methoden

- **Dezimal → Binär:**
    - **Positive Zahl:** Wandle sie normal in eine Binärzahl mit ℓ Stellen um
    - **Negative Zahl:** Wandle ihren **Betrag** in binär um und **invertiere dann alle Bits**.

- **Binär → Dezimal:**
    - **Erstes Bit ist `0`:** Wandle die Zahl normal in dezimal um.
    - **Erstes Bit ist `1`:** **Invertiere alle Bits**, wandle das Ergebnis in dezimal um und setze ein Minus davor.

| **Dezimal** | **Binärdarstellung (5-Bit)** |
| ----------- | ---------------------------- |
| -15         | `10000`                      |
| -7          | `11000`                      |
| -1          | `11110`                      |
| **-0**      | **`11111`**                  |
| **+0**      | **`00000`**                  |
| 1           | `00001`                      |
| 7           | `00111`                      |
| 15          | `01111`                      |

---

## Zweierkomplement-Darstellung (Two's Complement) ⇒ Standard

- **Konzept:** Negative Zahlen sind das Einerkomplement + 1. Dies vereinfacht die Arithmetik.
- For a bit length of $\ell$, the range is from $-2^{\ell-1}$ to $2^{\ell-1}-1$. There is one more negative number than positive numbers.
### Methoden

- **Dezimal → Binär:**
    - **Positive Zahl:** Wandle sie normal in eine Binärzahl mit ℓ Stellen um (das erste Bit muss `0` sein).
    - **Negative Zahl (-z):**
        1. Wandle den **Betrag** (z) in eine Binärzahl mit ℓ Stellen um.
        2. **Invertiere alle Bits** (Einerkomplement).
        3. **Addiere 1**.

- **Binär → Dezimal (Zwei Wege):**
    - **Weg 1 (Umkehroperation):**
        1. **Prüfe das erste Bit:** Wenn es `0` ist, wandle die Zahl normal in dezimal um.
        2. Wenn es `1` ist (negative Zahl): **Subtrahiere 1**, **invertiere dann alle Bits** und wandle das Ergebnis (den Betrag) in dezimal um. Setze ein Minus davor.
    - **Weg 2 (Direkte Formel - Theorem):** Nutze die Formel, die immer funktioniert, egal ob die Zahl positiv oder negativ ist:$$int(a)=-a_{\ell-1}*2^{\ell-1}+\sum_{i=0}^{\ell-2} a_i*2^i$$
        Das erste Bit ($a_{ℓ−1}$​) wird also negativ mit dem höchsten Stellenwert gewichtet, der Rest positiv.

**Example: Calculate the value of `11001` for $\ell=5$** $Wert = -1 \cdot 2^4 + 1 \cdot 2^3 + 0 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0$ $Wert = -16 + 8 + 0 + 0 + 1 = -7$

| **Dezimal** | **Binärdarstellung (5-Bit)** |
| ----------- | ---------------------------- |
| -16         | `10000`                      |
| -8          | `11000`                      |
| -1          | `11111`                      |
| **0**       | **`00000`**                  |
| 1           | `00001`                      |
| 7           | `01111`                      |
| 15          | `01111`                      |
