Dienstag, 11. November 2025
#lina1 

### Wdh. 
**Def.** Es sei $U \subset \mathbb{R}^n$ ein Linearer Unterraum
	Ein System $\vec{u}_{1}, \dots, \vec{u}_{m}$ von Vektoren ist eine **Basis** von $U$ wenn geltern:
		**1)** $\vec{u}_{1}, \dots, \vec{u}_{m}$ ist linear unabhängig
		**2)** $\vec{u}_{1}, \dots, \vec{u}_{m}$ ist ein Erzeugungssystem (d.h. $U = Lin(\vec{u}_{1}, \dots, u_{m})$)


> [!TIP] 7.10 Satz
> Es sei $U = Lin(\vec{w}_{1}, \dots, \vec{w}_{m}), m \geq 1$.
Dann ist ein jedes System von Vektoren aus U, dessen Länge größer ist als m, linear abhängig.

**Beweis:**
	Sei $\vec{u}_{1}, \dots, \vec{u}_{k}$ ein System in U, mit k > m. Nach Voraussetzung hat jeder der Vektoren $\vec{u}_{1}, \dots, \vec{u}_{k}$ eine Darstellung $\vec{u}_{j} = \sum^m_{i=1}a_{ij} \vec{w}_{i} (j = 1, \dots, k)$.
	Dann ist $(a_{ij})_{i,j}$ eine $m \times k$ - Matrix.
	Wir betrachten das homgene LGS
		$\sum^k_{j=1} a_{ij}x_{j}=0 \ \ \ (i=1,\dots,m)$ in k Unbekannten $x_{1}, \dots x_{k}$. Dieses System ist unterbestimmt (k > m), hat also nach Satz 5.3 eine **nicht-triviale** Lösung $c_{1},\dots,c_{k}$ (nicht alle 0). Berechne: $$\sum_{j=1}^{k} c_{j} \vec{u}_{j} = \sum_{j=1}^k c_{j} \left( \sum_{i=1}^m a_{ij} \vec{w}i \right) = \sum_{i=1}^m \left( \sum_{j=1}^k a_{ij} c_{j} \right) \vec{w}_{i} = \vec{ 0}$$
		Also sind $\vec{u}_{1},\dots,\vec{u}_{k}$ linear abhängig. $$\tag*{$\blacksquare$}$$

> [!note] 7.11 Korollar
> Jeder lineare Unterraum in $\mathbb{R}^n$ besitzt eine Basis


**Beweis:**
	Es sei $U \subset \mathbb{R}^n$ ein linearer Unterraum. Da $\mathbb{R}^n$ eine Basis $\vec{e}_{1},\dots,\vec{e}_{n}$ der Länge n hat, hat jedes unabhängige System in U höchstens die Länge n. 
	Unter allen l.u. Systemen un U können wir ein System $\vec{u}_{1},\dots,\vec{u}_{m}$ von größtmöglicher Länge wählen- Dieses ist nicht verkürzbar, also eine Basis nach Satz 7.9. $$\tag*{$\blacksquare$}$$

>[!note] 7.12 Korollar (Invarienz der Basislänge)
>Ist $U \subset  \mathbb{R}^n$ ein linearer Unterraum und sind $\vec{u_{1}}, \dots \vec{u}_{k}$ und $\vec{w_{1}}, \dots, \vec{w}_{m}$ zwei Basen von $U$, dann gilt $k = m$.
>D.h. *Die Basislänge steht fest*

**Beweis:**
Da $\vec{u_{1}}, \dots , \vec{u}_{k}$ ein Erzeugendensystem ist und $\vec{w_{1}}, \dots, \vec{w_{m}}$ linear unabhängig, folgt daraus $m \leq k$ aus dem vorangegangenen Sazt. Indem man die Rolle der beiden Systeme vertauscht, folgt also $k \leq m$, also insgesamt $k=m$$$\tag*{$\blacksquare$}$$

---

> [!TIP] 7.13 Satz (Basisergänzungssatz)
> Es seien $U, V \subset \mathbb{R}^n$ zwei lineare Unterräume mit $U \subset V$. Ist $\vec{u_{1}}, \dots \vec{u_{m}}\in U$ eine Basis von U, dann gibt es $k \in \mathbb{N}_{0}$ derart, dass das System $\vec{u_1}, \dots, \vec{u_{m}}, \vec{v_{1}}, \dots, \vec{v_m}$ eine Basis von $V$ ist. 

**Beweis:**
![[Pasted image 20251118215932.png]]

**Beispiel:** 
$v_{1} = (1,2,3), v_{2} = (1,0,-1)$. $\vec{v_{1}},\vec{v_{2}}$ linear unabhänhig, also eine Basis von $U = Lin(\vec{v_{1}}\vec{v_{2}})$. Ist $\vec{v}_{3} \in \mathbb{R}^3$ aber nicht in $U$, dann ist $v_{1}, v_{2}, v_{3}$ eine Basis von $\mathbb{R}^3$, z.B. $\vec{v_{3}} = (0,0,-1)$.

---

# Dimensionen

> [!TIP] Definition
> Die **Dimension** eines linearen Unterraums $U \in \mathbb{R}^n$ ist die Länge einer Basis von U und wird mit $dim(U)$ bezeichnet.

**Beispiele:**

1. Der Ganze Raum $\mathbb{R}^n$ hat die Basis $\vec{e_{1}}, \dots, \vec{e_{n}}$ und damit die Dimension $n$.

2. Für den **Nullraum** ist das Leere System der Länge 0 eine Basis. Er hat also die Dimension 0.

3. Jede **Gerade** $Lin(\vec{w})$ mit $\vec{w} \ne \vec{0}$ in $\mathbb{R}^n$ jat die Dimension 1. 

4. Sind $\vec{v_{1}}, \vec{v_{2}} \in \mathbb{R}^n$ zwei linear unabhängige Vektoren, dann har der lineare Unterraum $U = Lin (\vec{v_{1}}, \vec{v_{2}})$ die Dimension 2. Es ist eine **Ebene**.

5. Allgemeiner nennt man jeden linearen Unterraum der Dimension $n-1$ in $\mathbb{R}^n$ eine **Hyperebene**.

>[!note] Summen- & Schnitträume
>- $U_{1} \cap U_{2}$ ist ein linearer Unterraum, der in den linearen Unterräumen $U_{1}, U_2$ enthalten ist. 
>- Die **Summe** ist ebenfalls ein linearer Unterraum, der nun $U_{1}$ und $U_{2}$ beide enthält. $U_{1} + U_{2} = \{  \vec{u_{1}} \in U_{1}, \vec{u_{2}} \in U_{2}  \} \subset \mathbb{R}^n$


> [!TIP] 7.16 Satz (Dimensionsformel für Unterräume)
> Es seien $U_{1}$ und $U_{2}$ zwei lineare Unterräume von $\mathbb{R}^n.$
> 1. Falls $U_{1} \subset U_{2}$, dann gilt $dim (U_{1}) \le dim(U_{2})$. Dabei ist $dim(U_{1}) = dim(U_{2})$ genau dann, wenn $U_{1}$ = $U_{2}$ gilt.
> 2. Es gilt $dim(U_{1}+U_{2}) = dim(U_{1}) + dim(U_{2})-dim(U_{1}\cap U_{2})$

#### Beweis
![[Pasted image 20251119144039.png]]
![[Pasted image 20251119144132.png]]

---

# §7.4 Lösungsäume
Wichtigster Fall: der Unterraum ist der Lösungsraum eines homogenen LGS $A \vec{x} = \vec{0}$ ist. Wenn die Koeffizientenmatrix A in Zeilenstufenform vorliegt, kann jeder Spalte, in der keine Stufe anfängt, die Zugehörige Unbekannte freu gewählt werden, was sich genauer ausdrücken lässt:

>[!TIP] 7.17 Satz (Basis des Lösungsraums)
>Gegeben sei ein homgenes LGS $A\vec{x}=\vec{0}$ mit $A$ in Zeilenstufenform. Man erhält eine Basis des Lösungsraums, indem man jeweils eine der freien Unbekannten gleich 1 setzt und die anderen gleich 0. Wenn es keine freien Unbekannten gibt, ust der Lösungsraum der Nullraum

**Beweis**
Wenn es $k$ freie Unbekannte gibt, dann erhalten wir in dieser Weise $k$ verschiedene Lösungsvektoren $u_{1}, \dots, u_{k}$. Diese sind lnear unabhängig, denn in jedem von ihnen gibt es einen Eintrag, der gleich 1 ist, in allen anderen aber 0 (wie Beispiel 7.5(e)). Jede Lösung entsteht, indem man den freien Unbekannten Werte zuweist. Sind diese Werte $a_{1}, \dots, a_{k}$, dann ist die Linearkombination $$a_{1} \vec{u}_{1} + \dots + a_{k} \vec{u}_{k}$$ die zugehörige Lösung. Also sind $\vec{u_{1}}, \dots, \vec{u_{k}}$ eine Basis des Lösungsraums. $$\tag*{$\blacksquare$}$$
**Beispiel**
![[Pasted image 20251119145902.png]]
![[Pasted image 20251119145933.png]]


>[!note] 7.19 Korollar
>Die Dimension des Lösungsraums eines homogenen linearen Gleichungssystems stimmt mit der Anzahl der freien Unbekannten überein.

**Beweis**
Der vorangehende Satz sagt gerade, dass wir für jede freie Unbekannte einen Basisvektore erhatlen, so dass die Behuptung folgt.$$\tag*{$\blacksquare$}$$
