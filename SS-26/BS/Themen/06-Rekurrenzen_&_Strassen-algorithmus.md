#dap2 **26.05.2026**

>[!question] Motivation
>- Bei der Analyse von Algorithmen begegnen häufig **Rekurrenzen**
>	- z.B. erfüllt die Laufzeit von `Quicksort` mit dem `Select`-Algorithmus die Rekurrenz $$\mathcal T_{n} = O(n) + 2 \mathcal{T}_{\left\lfloor  \frac{n}{2}  \right\rfloor }$$
>⮩ das ***"Master-Baiter-Theorem"*** erlaubt es, Rekurrenzen bequem Abzuschätzen

>[!tip] ***Master_Theorem***
>Seien $a \ge 1, b > 1 \in \mathbb{R}$ und $T: \mathbb{R}_{\ge 0} \to \mathbb{R}_{\ge 0}$ und $f: \mathbb{R}_{\ge 0} \to \mathbb{R}_{\ge 0}$ Funktionen, so dass $$\forall x \in \mathbb{R}_{\ge 0} : T(x) = aT\left( \frac{x}{b} \right) + f(x)$$
>1. falls 
>   $\exists \epsilon > 0 :  f(x) = O(x^{\log_b (a) - \epsilon}) \implies T(x) = \Theta(x^{\log_{b}(a)})$
>   ___
>2. falls 
>   $\exists \Theta (x^{\log_{b}(a)} \log^k(x)) \implies T(x) = \Theta (x^{\log _{b}(a)\log^{k+1}(x)})$
>   ___
>3. falls 
>   $\exists \epsilon, x_{0} > 0, c < 1 : af( \frac{x}{b}) \le cf(x)$ mit $x > x_{0} \implies T(x) = \Theta(f(x))$

>[!tip] Lemma 
>Seien $a \ge 1, b > 1 \in \mathbb{R}, f : \mathbb{R}_{\ge 0} \to \mathbb{R}_{\ge 0}, T: \mathbb{R}_{\ge 0} \to \mathbb{R}_{\ge 0}$ , s.d. $$T(x) = \begin{cases} \Theta (1) & \text{falls} 0 \le x \le 1, \\ aT( \frac{x}{b}) + f(x) & \text{sonst.} \end{cases}$$ Dann gilt $$T(x) = \Theta(x^{\log_{b}(a)}) + \sum _{0 \le j \le \log_{b}(x)} a^j f\left( \frac{x}{b^i} \right).$$ 

>[!tip] Lemma
>Seien $a \ge 1, b > 1 \in \mathbb{R}, f: \mathbb{R}_{\ge 0} \to \mathbb{R}_{\ge 0}$ und $$g(x) = \sum _{0 \le j \le \log_{b}(x)} a^j f\left( \frac{x}{b^i} \right) \space (x \ge 1).$$
>1. falls 
>   $\exists \epsilon > 0 :  f(x) = O(x^{\log_b (a) - \epsilon}) \implies T(x) = \Theta(x^{\log_{b}(a)})$
>   ___
>2. falls 
>   $\exists \Theta (x^{\log_{b}(a)} \log^k(x)) \implies T(x) = \Theta (x^{\log _{b}(a)\log^{k+1}(x)})$
>   ___
>3. falls 
>   $\exists \epsilon, x_{0} > 0, c < 1 : af( \frac{x}{b}) \le cf(x)$ mit $x > x_{0} \implies T(x) = \Theta(f(x))$

## Matrixmultiplikation mit dem Strassen-Algorithmus

Für zwei $n \times n$-Matrizen $A = (a_{ij})_{i, j = 1, \dots, n}, \space B = (b_{ij})_{i, j = 1, \dots, n}$ benötigt der *naive Algorithmus* für das Produkt $C = A \cdot B$  mit den Einträgen $$c_{ij} = \sum ^n _{ l = 1} a_{il} b_{lj} \space (i, j = 1, \dots, n)$$ $$O(n^3)$$ Multiplikationen.

**Angenommen** $n = 2^t (t  \in \mathbb{N})$
⮩ *divide & conquer:* zerlege $A, B, C$ in Untermatrizen der Göße $\frac{n}{2} \times \frac{n}{2}$: $$A = \begin{pmatrix} A_{11} & A_{12} \\ A_{21} & A_{22}\end{pmatrix} \ \ \ B = \begin{pmatrix} B_{11} & B_{12} \\ B_{21} & B_{22} \end{pmatrix} \ \ \ C = \begin{pmatrix} C_{11} & C_{12} \\ C_{21} & C_{22} \end{pmatrix}$$
⮕ berechnen nun *rekursiv* die sieben Produkte $$\begin{align}
& P_{1} = (A_{11} + A_{22})(B_{11} + B_{22}) \\
& P_{2} = (A_{21} + A_{22})B_{11} \\
& P_{3} = A_{11} (B_{12}- B_{22}) \\
& P_{4} = A_{22} (B_{21} - B_{11}) \\
& P_{5} = (A_{11} + A_{12}) B_{22} \\
& P_{6} = (A_{21} - A_{11}) (B_{11} + B_{12}) \\
& P_{7} = (A_{12} - A_{22})(B_{21} + B_{22})
\end{align}$$dann erhalten wir $$\begin{align} & C_{11} = P_{1} + P_{4} - P_{5} + P_{7}  \\ & C_{12} = P_{3} + P_{5} \\ & C_{21} = P_{2} + P_{4} \\ & C_{22} = P_{1} + P_{3} - P_{2} + P_{6} \end{align}$

>[!tip] Satz 
>Der **Strassenalgorithmus** benötigt $T(n) = \Theta(n^{\log_{2} 7})$ Rechenoperationen
>___
>die Laufzeit erfüllt die Rekurrenz $$\rceil T \left( \frac{n}{2} + O(n^2) \right)$$
>Daher folgt die Behauptung aus dem Master-Theorem