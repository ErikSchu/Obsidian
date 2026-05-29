>[!TIP] **Satz**
> $$n! \sim \sqrt{ 2 \pi n } \left( \frac{n}{e} \right)^n$$

![[Pasted image 20260507141211.png]]

>[!TIP] Lemma
>$$\pi / 2 = \lim_{ n \to \infty } \prod^n _{i = 1} \frac{4i^2}{4i^2-1}$$

>[!note] Korollar
>$$\frac{(n!)^2 2^{2n}}{(2n)!\sqrt{ n }} \sim \sqrt{ \pi }$$

>[!def] Binomialkoeffizient
>... "n über k" ist definiert als $$\begin{pmatrix} n \\ k \end{pmatrix} = \frac{n!}{k! \cdot (n-k)!}$$
>- für $k > n$ definiert als $0$

##### Pascalsches Dreieck
Für jedes $0 < k < n$ gilt $$\begin{pmatrix} n \\k \end{pmatrix} = \begin{pmatrix} n-1 \\ k \end{pmatrix} + \begin{pmatrix} n-1 \\ k-1 \end{pmatrix}$$

##### Teilmengen
Der Binomialkoeffizient $\begin{pmatrix} n \\k\end{pmatrix}$ gibt die Zahl der $k$-elementigen TEilmengen von $[n]$ an. 


>[!TIP] **Binomischer Lehrsatz**
>Für alle $a, b \in \mathbb{R}$ und alle $n \in \mathbb{N}$ gilt $$(a+b)^n = \sum ^n _{k = 0} \begin{pmatrix} n \\ k \end{pmatrix} a^k b^{n-k}$$

>[!TIP] Korollar 
>Die menge $[n]$ hat genau $2^n$ Teilmengen.

___

→ Die Stirlingformel gibt eine Approximation für $n!$
→ Zusammen mit der informationstheoretischen unteren Schranke erhalten wir eine Untere Schranke von $\Omega  (n \log n)$ für vergleichsbasierte Sortieralgorithmen