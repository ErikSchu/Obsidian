## Zweierkomplementdarstellung (Standard)

* **Idee:**
    * **Nicht-negative Zahlen ($z \ge 0$):** Normale Binärdarstellung.
    * **Negative Zahlen ($z < 0$):**
        1.  Nimm den Betrag $|z|$.
        2.  Stelle ihn binär dar.
        3.  Invertiere alle Bits (Einerkomplement).
        4.  Addiere 1.

> [!EXAMPLE] Beispiel: $z = -3$ mit $\ell = 4$
> 1.  Betrag: $|-3| = 3$
> 2.  Binärdarstellung von 3: `0011`
> 3.  Invertieren (Einerkomplement): `1100`
> 4.  Addiere 1: `1100 + 1 = 1101`
>
> $\rightarrow -3_{10} = 1101_{2K}$

> [!IMPORTANT] Eigenschaften (bei Länge $\ell$)
> * **Zahlenbereich:** $[-(2^{\ell-1}) \dots 2^{\ell-1}-1]$
> * **Vorteil:** **Null ist eindeutig** (`000...`). Alle Codes werden genutzt.
> * **Vorteil:** Erstes Bit funktioniert wie ein Vorzeichenbit (0=positiv, 1=negativ).
> * **Vorteil:** **Addition und Subtraktion funktionieren ohne Fallunterscheidung!** (Hardware ist einfach).
> * **Nachteil:** Zahlenbereich ist *nicht* symmetrisch (es gibt eine negative Zahl mehr).


### Methoden

- **Dezimal → Binär:**
    - **Positive Zahl:** Wandle sie normal in eine Binärzahl mit ℓ Stellen um (das erste Bit muss `0` sein).
    - **Negative Zahl (-z):**
        1. Wandle den **Betrag** (z) in eine Binärzahl mit ℓ Stellen um.
        2. **Invertiere alle Bits** ([[Einerkomplement]]).
        3. **Addiere 1**.

- **Binär → Dezimal:**
    1. **Prüfe das erste Bit:** Wenn es `0` ist, wandle die Zahl normal in dezimal um.
    2. Wenn es `1` ist (negative Zahl): **Subtrahiere 1**, **invertiere dann alle Bits** und wandle das Ergebnis (den Betrag) in dezimal um. Setze ein Minus davor.


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


## Theorem

Ein Bitvektor $a=(a_{\ell-1}, a_{\ell-2}, \ldots a_0)$ im Zweierkomplement repräsentiert die Zahl:
$$
int(a) = -a_{\ell-1} \cdot 2^{\ell-1} + \sum_{i=0}^{\ell-2} a_i \cdot 2^i
$$
Das vorderste Bit $a_{\ell-1}$ hat also einen **negativen Stellenwert**.

> [!EXAMPLE] Beispiel: $int(1101_{2K})$ mit $\ell = 4$
> $= -1 \cdot 2^3 + 1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0$
> $= -8 + 4 + 0 + 1$
> $= -3_{10}$

### Überlauf (Overflow)
* Findet statt, wenn das Ergebnis einer Rechnung nicht mehr in die $\ell$ Bits passt.
* Beim Rechnen mit Stift und Papier (siehe Bilder) wird ein "Überflussbit" (das $\ell+1$-te Bit) einfach ignoriert.