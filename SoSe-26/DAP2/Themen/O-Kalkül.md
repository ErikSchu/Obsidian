  *16.04.2026*
  #dap2
https://ls2-web.cs.tu-dortmund.de/~mamicoja/dap2/slides/lec_O.pdf
→ [[Asymptotische_Vergleiche]]
→ [[Logarithmus]]

| **Symbol**           | **Intuition**                 | **Übersetzung**                                                                  |
| -------------------- | ----------------------------- | -------------------------------------------------------------------------------- |
| ***$O(g(n))$***      | Höchstens so schnell wie $g$  | Finde ein $C$ und ein $n_0$, so dass $f(n) \le C \cdot g(n)$ für alle $n > n_0$. |
| ***$\Omega(g(n))$*** | Mindestens so schnell wie $g$ | Finde ein $c$ und ein $n_0$, so dass $f(n) \ge c \cdot g(n)$ für alle $n > n_0$. |
| ***$\Theta(g(n))$*** | Genau so schnell wie $g$      | Zeige, dass sowohl $f(n) = O(g(n))$ als auch $f(n) = \Omega(g(n))$ gilt.         |
| ***$o(g(n))$***      | Echt langsamer als $g$        | Zeige, dass der Grenzwert $\lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$ ist.       |
| ***$\sim$***         | Fast identisch                | Zeige, dass der Grenzwert $\lim_{n \to \infty} \frac{f(n)}{g(n)} = 1$ ist.       |

## Ziel
- es gilt, die Laufzeit von Algorithmen auf großen Eingaben zu analysieren
- wir interessieren uns als für “Größenordnungen”
- dazu führen wir einen geeigneten Formalismus ein
	⬇⬇⬇⬇

>[!TIP] Definition $O(\cdot)$
>Angenommen $f: \mathbb{N} \to \mathbb{R}, g: \mathbb{N} \to \mathbb{R}$ sind zwei Funktionen.
>Wir schreiben $f(n) = O(g(n))$, falls es eine natürliche Zahl $n_{0} \in \mathbb{N}$ und eine reelle Zahl $C > 0$ gibt, sodass $$\boxed{\lvert f(n) \rvert \le C \lvert g(n) \rvert} \text{   für all} n > n_{0}.$$


**Bedeutung:** f(n) wächst höchstens um einen konstanten Faktor C schneller als g(n), sobald die Eingabe n groß genug ist (n0​). Es definiert das Worst-Case-Verhalten eines Algorithmus.

#### Beispiel $I$
$f(n) = 10n² +100n + 1$          $g(n) = n²$
$f(n) = O(g(n))$

*Denn*  setze  $n_{0} = 100$. Für $n>n_{0}$
	$f(n) \le 10n² + n\cdot n +n²$
	$f(n) \le 12n² \le C \ g(n)$ mit $C =12 \checkmark$

#### Beispiel $II$
$f(n) = 100n + \sqrt{ n } + \frac{1}{n²}$          $g(n) = n²$
$f(n) = O \ g(n)$     $f(1) = 102 \ \ \ \ \ g(1) = 1$

*Denn*  setze $n_{0} = 100$
$\implies f(n) \le 100n + n + 1 \le 102n$
	$\ g(n)  = n³ \ge 100²\cdot n = 10000n$
	$\implies f(n)  \le g(n)$ *ABER* es gilt nicht $g(n) = O(f(n))$

___

>[!TIP] Definition $o(\cdot)$
>Angenommen $f: \mathbb{N} \to \mathbb{R}, g: \mathbb{N} \to \mathbb{R}$ sind zwei Funktionen.
>Wir schreiben $f(n) = o(g(n))$, falls es zu jeder reellen Zahl $\mathcal E > 0$ eine natürliche Zahl $n_{0} > 0$ gibt, sodass $$\boxed {\lvert f(n) \rvert \le \mathcal E \lvert g(n) \rvert} \text{ für alle } n>n_{0}.$$

**Bedeutung:** f(n) wächst _echt_ langsamer als g(n). Egal wie winzig klein du die Zahl ϵ (Epsilon) wählst (z. B. 0.0001), g(n) wird f(n) ab einem bestimmten Punkt n0​ immer dominieren.

#### Beispiel $III$
$f(n) = n² \ \ \ g(n) = n³ \implies f(n) =o(g(n))$

*Denn*  gegeben $\epsilon > 0$ wähle $n_{0} > \frac{1}{\epsilon}$
 $\implies \epsilon g(n)=\epsilon n_{0} \cdot n^2 =  \epsilon \dots$

#### Beispiel $IV$

___


>[!TIP] Definition $\Omega (\cdot)$
>Angenommen $f: \mathbb{N} \to \mathbb{R}, g: \mathbb{N} \to \mathbb{R}$ sind zwei Funktionen.
>Wir schreiben $f(n) = O(g(n))$, falls es eine natürliche Zahl $n_{0} \in \mathbb{N}$ und eine reelle Zahl $c > 0$ gibt, sodass $$\boxed{ f(n) \ge c \cdot g(n) \ge 0 } \text{   für alle } 
n > n_0.$$

**Bedeutung:** f(n) wächst mindestens so schnell wie g(n), skaliert um einen Faktor c. Das definiert das Best-Case-Verhalten eines Algorithmus.

#### Beispiel $V$




___

>[!TIP] Definition $\Theta(\cdot)$
>Angenommen $f: \mathbb{N} \to \mathbb{R}, g: \mathbb{N} \to \mathbb{R}$ sind zwei Funktionen.
>Wir schreiben $f(n) = \Theta (g(n))$, falls $\boxed{ f(n) = \Omega(g(n)) \text{ und } g(n) = \Omega (f(n)) }$

___
## Idiomatische Spezialfälle
- $O(1) \leadsto$ *beschränkter* Ausdruck
- $o(1) \leadsto$ Ausdruck, der für $n \to \infty$ *gegen Null* geht
- $\Omega(1) \leadsto$ Ausdruck, der für $n \to \infty$ von der Null weg beschränkt bleibt
- $\Theta(1) \leadsto$ Ausdruck der beschränkt und von der Null weg beschränkt bleibt

___

>[!TIP] $\cdot \sim \cdot$
>Für zwei Funktionen $f(n), g(n)$ schreiben wir $f(n) \sim g(n)$, falls $$\boxed{ f(n) = (1+o(1))g(n) }.$$


**Bedeutung:** f(n) und g(n) verhalten sich für sehr große n identisch. Der Term o(1) steht für eine Funktion, die gegen null konvergiert, wenn n gegen unendlich geht. Es bleibt also 1⋅g(n) übrig.
