* **Idee:** Erstes Bit ist das Vorzeichenbit $s$. Restliche $\ell-1$ Bits sind der Betrag. 
* **Formel:** $Zahl = (-1)^s \cdot Betragszahl$ * Vorzeichenbit $s=1 \Leftrightarrow$ negativ. 

> [!IMPORTANT] Eigenschaften (bei Länge $\ell$)
> * **Zahlenbereich:** $[-(2^{\ell-1}-1) \dots 2^{\ell-1}-1]$ 
> * **Vorteil:** Symmetrischer Zahlenbereich, einfacher Vorzeichenwechsel (nur 1 Bit flippen). 
> * **Nachteil:** Die **Null ist nicht eindeutig** codiert ("+0" = `000...` und "-0" = `100...`). Ein Code wird verschwendet. 
> * **Nachteil:** Rechnen (Addition/Subtraktion) ist kompliziert.


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