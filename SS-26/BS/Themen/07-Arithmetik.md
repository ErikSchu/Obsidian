#dap2 **28.05.2026**

##### ggT
von $x, y \in \mathbb{Z}$, $x \ne 0$, ist die größte Zahl $z \in \mathbb{N}$, mit $z|x$ und $z|y$.

>[!def] `Euclid(a,b)`
>1. falls $a < b$, vertausche $a$ und $b$
>2. setze $a_0 = a, a_1 = b, i = 1$
>3. solange $a_i > 0$
>	4. berechne $q_i \in \mathbb{Z}, a_{i+1} \in \{ 0, 1, \dots, a_{i}-1 \}$, sodass $a_{i-1} = q_{i} a_{i} + a_{i+1}$
>	5. erhöhe $i$ um 1
>4. gib $a_{i-1}$ aus

>[!tip] Satz
>`Euclid(a,b)` gibt $ggT(a, b)$ aus und führt $O(\log \lvert a  \rvert  + \lvert b \rvert)$ Divisionen aus .

>[!tip] Korollar
>Für je zwei Zahlen $a, b \in \mathbb{N}$ gibt es Zahlen $u, v \in \mathbb{Z}$, sodass $ggt(a,b) = au + bv$.


>[!note] Definition
>- eine Zahl $z \in \mathbb{Z} \text{\\} \{ -1, 1 \}$ heißt **irreduzibel**, falls $y \not{|} z$ für alle $1 < y < \lvert z \rvert$
>- Mit $\mathbb P$ wird die Menge aller Primzahlen bezeichnet
>___
>$\to$ jede Primzahl ist irreduzibel
>$\to$ jede Zahl $z > 1$ besitzt einen irreduziblen Teiler
>$\to$ jede irreduzible Zahl ist eine Primzahl


>[!tip] **Theorem**
>Zu jeder Primzal $p \in \mathbb{P}$ gibt es eine Abbildung $w_{p} : \mathbb{N} \to \mathbb{N}_{0}$, sodass für jedes $z \in \mathbb{N}$ gilt $$Z = \prod _{ p \in \mathbb P } p^{w_{p}}(z)$$ 
