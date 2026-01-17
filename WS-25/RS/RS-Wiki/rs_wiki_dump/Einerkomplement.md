
* **Idee:**
    * **Nicht-negative Zahlen:** Normale Binärdarstellung.
    * **Negative Zahlen:** Bitweises Komplement (Invertieren) der positiven Zahl (aus 0 wird 1, aus 1 wird 0).


> [!IMPORTANT] Eigenschaften (bei Länge $\ell$)
> * **Zahlenbereich:** $[-(2^{\ell-1}-1) \dots 2^{\ell-1}-1]$
> * **Vorteil:** Symmetrischer Zahlenbereich. Erstes Bit ist wie ein Vorzeichenbit.
> * **Nachteil:** Die **Null ist nicht eindeutig** ("+0" = `000...` und "-0" = `111...`). Ein Code wird verschwendet.


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
