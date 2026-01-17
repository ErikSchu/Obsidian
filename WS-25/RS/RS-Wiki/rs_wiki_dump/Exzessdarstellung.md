* **Idee:** Man addiert eine feste Verschiebung **b (Bias)** zur Zahl $z$ und stellt $z+b$ binär dar.
* **Üblicher Bias:** $b = 2^{\ell-1}$ oder $b = 2^{\ell-1}-1$.
* Die gespeicherte Zahl ist also *immer* positiv.

> [!IMPORTANT] Eigenschaften (bei Länge $\ell$ und Bias $b$)
> * **Zahlenbereich:** $[-b \dots 2^\ell - 1 - b]$
> * **Vorteil:** **Null ist eindeutig**. Alle Codes werden genutzt.
> * **Vorteil:** Zahlenvergleich ist einfach (normaler Binärvergleich).
> * **Nachteil:** Zahlenbereich ist nicht symmetrisch.
> * **Nachteil:** Vorzeichenwechsel ist schwierig.

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
