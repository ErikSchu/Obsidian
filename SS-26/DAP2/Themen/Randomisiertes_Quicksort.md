*****21.04.2026*
#dap2
https://ls2-web.cs.tu-dortmund.de/~mamicoja/dap2/slides/lec_rquicksort.pdf

[[Quicksort]] ctd. 

# Permutationen
- eine $n-\text{Permutation}$  ist eine *bijektive Abbildung* $$\{ 1, \dots, n \} \to \{ 1, \dots, n \}$$
- wir schreiben $\begin{bmatrix} n \end{bmatrix} = \{ 1, \dots, n \}$
- die Menge aller $n-\text{Permutationen}$  wird mit $\mathbb{S}_{n}$ bezeichnet
- insgesamt gibt es $$| \mathbb S _n | = n! = \prod^n _{i = 1} i$$ $n - \text{Permutationen}$
- mit $\mathbf{\sigma} \in \mathbb S_{n}$ wird eine **zufällige** Permutation bezeichnet
- wir interessieren uns für die *erwartete* und *durchschnittliche* Laufzeit
- dazu führen wir die **n-te harmonische Zahl** ein: $$H_{n} = \sum^n _{ i = 1} \frac{1}{i}$$
- wir erinnern uns an die Definition des **natürlichen Logarithmus**: $$\log(x) = \int ^x _{1} \frac{1}{z} \ dz$$
>[!TIP] Satz
>Angewand auf die zufällige Permutation $\mathbf{\sigma}$ hat Quicksort eine erwartete Laufzeit von $$\le 2(n+1)H_{n}$$ Vergleichen, bzw.  $$\le 2(n+1) \sum ^n _{i=1} \frac{1}{i}.$$ 

___
### Die Euler-Mascheroni-Zahl
Ein wenig Analysis zeigt, dass $$ \lim_{ n \to \infty } H_{n} - \log n = \gamma \approx 0.57721\dots$$Aus dem Satz folgt also, dass Quicksort auf Eingabe $\mathbf{\sigma}$ nur $O(n \log n)$ vergleiche in Erwartung benötigt.

___
# Zufällige Wahl des Pivots
- Analyse von Quicksort auf *zufälligen Permutaitonen* basiert **nur** auf der Annahme, dass das Pivot zufällig ist
- wenn wir statt des ersten Elements also ein **zufälliges Element als Pivot** verwenden, erzielen wir auf *jeder* Eingabe eine Laufzeit von $O(n \log n)$
- man spricht von einem **Las Vegas-Algorithmus**
