Eine **Boolesche Algebra** ist eine spezielle algebraische Struktur, welche die Eigenschaften von logischen Operatoren (UND, ODER, NICHT) verallgemeinert.

> [!abstract] Definition
> Wir nennen die Struktur $(B, \cup, \cap, \overline{\ })$ mit $B=\{0, 1\}$ eine **Boolesche Algebra**, wobei gilt:
> * **ODER:** $x \cup y = \max(x, y)$
> * **UND:** $x \cap y = \min(x, y)$
> * **NICHT:** $\overline{x} = 1 - x$

### Entsprechungen zur Aussagenlogik

| Aussagenlogik | Boolesche Algebra ($B=\{0, 1\}$) |
| :--- | :--- |
| FALSCH | 0 |
| WAHR | 1 |
| Konjunktion ($\land$) | $\cap$ (min) |
| Disjunktion ($\lor$) | $\cup$ (max) |
| Negation ($\neg$) | $\overline{\ }$ (1-x) |
