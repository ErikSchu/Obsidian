
> [!IMPORTANT] Regel
> $16 = 2^4$. Das bedeutet: **1 Hex-Ziffer $\leftrightarrow$ 4 Bits**


---

**Binär $\rightarrow$ Hex:**

1.  Gruppiere die Binärzahl von **rechts nach links** in 4er-Blöcke.

2.  Fülle den vordersten Block ggf. mit Nullen auf.

3.  Ersetze jeden 4er-Block durch die entsprechende Hex-Ziffer.

> [!EXAMPLE] Beispiel: $(1010101011)_2 \rightarrow (?)_{16}$
> * Gruppieren: `10` `1010` `1011`
> * Auffüllen: `0010` `1010` `1011`
> * Ersetzen:
>     * $0010_2 = 2_{16}$
>     * $1010_2 = A_{16}$
>     * $1011_2 = B_{16}$
> * Ergebnis: **$(2AB)_{16}$**


---

**Hex $\rightarrow$ Binär:**

1.  Ersetze jede Hex-Ziffer durch ihren 4-Bit-Binärcode.

> [!EXAMPLE] Beispiel: $(3EC9)_{16} \rightarrow (?)_{2}$
> * $3_{16} = 0011_2$
> * $E_{16} = 1110_2$
> * $C_{16} = 1100_2$
> * $9_{16} = 1001_2$
> * Ergebnis: **$(0011111011001001)_2$**