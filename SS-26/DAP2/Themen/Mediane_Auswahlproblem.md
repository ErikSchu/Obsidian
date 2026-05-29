#dap2 

## Das Auswahlproblem 
Gegeben ist ein Array $\mathbf{A} = (A_{1}, \dots, A_{n})$ mit vergleichbaren Elementen und eine Zahl $1 \le l \le n$.
**Ziel** ist es das $l-$te Element von $\mathbf{A}$ in aufszeigender Reihenfolge zu finden

#### Lösung via Sortieren
... in der Zeit $O (n \log n)$ und $l$-ten EIntrag ausgeben.
- aber für $l = 1$, $l = n$ kann das Problem in $O(n)$gelöst werden 
  ⮩ gaht das auch für allgemeine $l$?

>[!tip] Definition
>Ein ***Median*** eines Arrays $\mathbf{A} = (A_{1}, \dots, A_{n})$ ist ein Element $A_{i}$ von $\mathbf{A}$, so dass $$\lvert \{ i \in [ n ] : A_{i} < m \} \rvert \le \frac{n}{2} \text{   und   } \lvert \{ i \in [ n ] : A_{i} > m \} \rvert \le \frac{n}{2}.$$
- wenn man Arrays sortiert, ist das Element in $\left\lceil  \frac{n+1}{2}  \right\rceil$ ein Median
- wenn $n$ ungerade und alle elemente verschieden, ist der **Median eindeutig**
- wenn $n$ gerade ist, gibt es *mind. zwei Mediane*

>[!code] `Select(A, l)`
>1. Falls $n = 1$, gib $A_{1}$ aus.
>2. Unterteile $\mathbf{A}$ in $k = \left\lfloor  \frac{n}{5}  \right\rfloor$ Teilarrays $T_{1}, \dots, T_{\left\lfloor  \frac{n}{5}  \right\rfloor}$ zu $5$ Elementen und, falls $n$ nicht durch $5$ teilbar, weiteres Teilarray $T_{\left\lfloor  \frac{n}{5}  \right\rfloor + 1}$.
>3. Setze $N = \left\lfloor  \frac{n}{5}  \right\rfloor$, falls $n$ durch $5$ teilbar ist, und sonst $N = \left\lfloor  \frac{n}{5}  \right\rfloor+1$.
>4. Finde in jedem dieser Teilarray $T_{i}$ den Median $m_{i}$.
>5. Wende `Select` rekursiv an, um einen Median $m$ von $\mathbf{m} = (m_{1}, \dots, m_{N})$ zu finden.
>6. Bestimme $\mathbf{K} = (K_{1}, \dots, K_{n'}); \ \mathbf{M} = (M_{1}, \dots, M_{n''}); \ \mathbf{G} = (G_{1}, \dots, G_{n'''})$, die die Elemente von $\mathbf{A}$ kleiner/gleich/größer $m$ enthalten.
>7. Falls $n' \ge l$, führe `Select(K, l)` aus;
>8. sonst, falls $n' + n'' \ge l$, gib$m$ aus;
>9. sonst führe `Select(G, l-n'-n'')` aus.

>[!tip] Satz 
>`Select(A, l)` hat die **Laufzeit $O(n)$**.

$\implies$ `Select` bestimmt das $l$-te Element in linearer Zeit
$\implies$ es gibt einen eineacheren randomisierten Algorithmus für dieses Problem, der dem [[Quicksort]] ähnelt, aber nur "einen Zweig verfolgt".

$$\text{Probleme}^{n^{n^{n}}}$$
$$\mathbf{\boxed{67}}$$
$$\begin{pmatrix} B & I & T & T & E \\ H & I & L & F & E \end{pmatrix}$$
$$\lim_{ n \to \infty } \int_{0} ^{\infty^2} \text{Janiß} \ d\text{dick} = \sum_{\text{Eichel}} ^\text{Holzbrett} \text{Fabienne <3}$$
$$\begin{align}
\text{ ElectroBoom} = O(\emptyset) & \Longleftrightarrow \sqrt{ \text{Benji Haase} } = e^\text{Pferdeschwanz} \space | \space \boxed{}^2 \\
& \Longleftrightarrow \text{Benji Haase} = (e^\text{Pferdeschwanz})^2
\end{align}$$
Sei $A \in \mathbb{S}_{n}(\mathbb{R})$ symmetrisch mit $$A = \begin{pmatrix}  a_{1} & a_{2} & \cdots & a_{n} \\a_{2} & a_{1} & & \vdots \\ \vdots & & \ddots & \vdots \\ a_{n} & \cdots & \cdots & a_{1} \end{pmatrix}.$$Es gilt $\mathbb{S}_{n} (\mathbb{R})\subset \text{Mat}_{n \times n}(\mathbb{R})$.
Analog gilt für $B \in \mathbb{T}_{n} (\mathbb{R})$ schiefsymmetrisch mit $$B = \begin{pmatrix}  0 & b_{2} & \cdots & b_{n} \\ -b_{2} & 0 & & \vdots \\ \vdots & & \ddots & \vdots \\ a_{n} & \cdots & \cdots & a_{1} \end{pmatrix}.$$