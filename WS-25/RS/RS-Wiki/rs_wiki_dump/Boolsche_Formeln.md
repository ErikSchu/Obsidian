Jede beliebige boolesche Funktion kann als Formel ausgedrückt werden, indem man sie in "Teilfunktionen" zerlegt.

### Einschlägige Indizes
* Die **Indizes** sind die Zeilennummern (als Dezimalzahl) der Wertetabelle.
* Ein Index heißt **einschlägig**, wenn der Funktionswert $f$ für diese Zeile **1** ist.
* Ein Index heißt **nicht einschlägig**, wenn $f$ in dieser Zeile **0** ist.

### Min- & Maxterme

> [!abstract] Literal
> Ein **Literal** ist eine Variable (z.B. $x_1$) oder ihre Negation (z.B. $\overline{x_1}$).

Hier ist die grundlegende Unterscheidung, um eine Funktion aus einer Wertetabelle abzuleiten:

| Merkmal             | Minterm ($m_i$)                                                                                          | Maxterm ($M_i$)                                                                                          |
| :------------------ | :------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------- |
| **Logischer Typ**   | **Produktterm** (UND-Verknüpfung, $\land$)                                                               | **Summenterm** (ODER-Verknüpfung, $\lor$)                                                                |
| **Zielwert**        | Ergibt **1** für _genau eine_ Eingangskombination (Index $i$)                                            | Ergibt **0** für _genau eine_ Eingangskombination (Index $i$)                                            |
| **Nutzung**         | Für Zeilen, in denen die Funktion **f = 1** ist (einschlägige Indizes)                                   | Für Zeilen, in denen die Funktion **f = 0** ist (nicht einschlägige Indizes)                             |
| **Bildungsregel**   | Variable = 0 $\rightarrow$ **negiert** ($\overline{x}$) <br> Variable = 1 $\rightarrow$ **normal** ($x$) | Variable = 0 $\rightarrow$ **normal** ($x$) <br> Variable = 1 $\rightarrow$ **negiert** ($\overline{x}$) |
| **Ziel-Normalform** | **Disjunktive Normalform (DNF)**                                                                         | **Konjunktive Normalform (KNF)**                                                                         |
| **Verknüpfung**     | Alle Minterme werden mit **ODER** ($\lor$) verknüpft.                                                    | Alle Maxterme werden mit **UND** ($\land$) verknüpft.                                                    |

> [!EXAMPLE] Minterme für $n=2$
> | Index $i$ | $x_1$ | $x_2$ | Minterm $m_i$ |
> | :---: | :---: | :---: | :--- |
> | 0 | 0 | 0 | $m_0 = \overline{x_1} \land \overline{x_2}$ |
> | 1 | 0 | 1 | $m_1 = \overline{x_1} \land x_2$ |
> | 2 | 1 | 0 | $m_2 = x_1 \land \overline{x_2}$ |
> | 3 | 1 | 1 | $m_3 = x_1 \land x_2$ |
