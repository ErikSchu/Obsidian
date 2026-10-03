### Methode: 
Jede **Ziffer** wird mit ihrem **Stellenwert** (Potenz der Basis) **multipliziert** und die Ergebnisse werden **addiert**.

> [!EXAMPLE] Beispiel: Binär (Basis 2) $\rightarrow$ Dezimal
> **$(1011)_2$**
> $= 1 \cdot 2^3 + 0 \cdot 2^2 + 1 \cdot 2^1 + 1 \cdot 2^0$
> $= 1 \cdot 8 + 0 \cdot 4 + 1 \cdot 2 + 1 \cdot 1$
> $= 8 + 0 + 2 + 1 = (11)_{10}$

> [!EXAMPLE] Beispiel: Hexadezimal (Basis 16) $\rightarrow$ Dezimal
> **$(12AF)_{16}$** (Achtung: $A=10, F=15$)
> $= 1 \cdot 16^3 + 2 \cdot 16^2 + 10 \cdot 16^1 + 15 \cdot 16^0$
> $= 1 \cdot 4096 + 2 \cdot 256 + 10 \cdot 16 + 15 \cdot 1$
> $= 4096 + 512 + 160 + 15 = (4783)_{10}$

$$
Ziffer \cdot Basis^{Stelle \ von \ Rechts \ nach \ Links}
$$
$$Wert = \sum_{i=0}^{n-1} z_i \cdot b^i$$