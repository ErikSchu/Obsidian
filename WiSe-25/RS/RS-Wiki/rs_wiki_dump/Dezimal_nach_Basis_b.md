**Methode:** Der **Divisionsalgorithmus** (Methode mit Rest) wird verwendet.

1.  Teile die Dezimalzahl $n$ durch die Zielbasis $b$.

2.  Notiere den **Rest** $r$ (dies ist die Ziffer).

3.  Wiederhole den Vorgang mit dem **ganzzahlig abgerundeten Ergebnis** $\lfloor n/b \rfloor$.

4.  Mache dies, bis das Ergebnis 0 ist.

5.  Lies die Reste **von unten nach oben** ab.


> [!EXAMPLE] Beispiel: $(10)_{10} \rightarrow (?)_{2}$
> ```
> 10 / 2 = 5   Rest 0
>  5 / 2 = 2   Rest 1
>  2 / 2 = 1   Rest 0
>  1 / 2 = 0   Rest 1
> ```
> Ergebnis (von unten nach oben): **$(1010)_2$**
