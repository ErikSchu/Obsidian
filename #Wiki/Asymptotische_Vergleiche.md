### Fakultäten
Laut [[Sterling-Formel]] gilt $$n! \sim \sqrt{ 2 \pi n } \left( \frac{n}{e} \right)^n = \sqrt{ 2 \pi n } \cdot n^n -e^n$$Dabei ist nur der Teil $n^n$ asymptotisch relevant.

### Vorgehen abh. von Position von $n$
- **nur in der Basis** ⇒ Exponenten Vergleichen oder mittels Grenzwert des Quotienten $$\lim_{ n \to \infty } = \frac{f(n)}{g(n)}$$
- **im Exponenten** ⇒ *logarithmieren* mit natürlichem Logarithmus und Anwendung der **[[Logarithmus|Logarithmusgesetze]]**

### Dominante Terme
Bei Summen ist nur der **am schnellsten wachsende Term** relevant. Dabei sind *konstante Vorfaktoren* irrelevant. Multiplikationen bleiben ansonsten erhalten.

### Wachstumshierarchie
$$1 \ \ < \ \ \log (\log (n)) \ \ < \ \ \log(n) \ \ < \ \ \log(n)^k \ \ < \ \ n^c (c < 1) \ \ < \ \ n \ \ < \ \ n \cdot \log(n) \ \ < \ \ n^k \ \ < \ \ n^{\log(n)} \ \ < \ \ c^n (c > 1) \ \ < \ \ n! \ \ < \ \ n^n$$
