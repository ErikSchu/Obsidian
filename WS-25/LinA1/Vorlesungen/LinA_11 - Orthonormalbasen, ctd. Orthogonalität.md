#lina1
>[!TIP] 8.8 Satz **n-dimensionaler Pythagoras**
>Es seien $\vec{v}_{1}, \dots, \vec{v}_{n} \in \mathbb{R}^n$ paarweise aufeinander stehende Vektoren, also mit $\langle \vec{v_{i}}, \vec{v_{j}} \rangle = 0$ für alle $i \ne j$. Dann gilt $$||\vec{v_{1}} + \dots + \vec{v_{m}}||^2 = ||\vec{v_{1}}||^2 + \dots + ||\vec{v_{m}}||^2$$

#### BEWEIS
![[Pasted image 20251121124344.png]]

>[!TIP] Definition **Orthonormalsystem**
>Axiome
>1. $\langle  \vec{v_{i}}, \vec{v_{i}} \rangle = 1 : \forall i = 1, \dots m$
>2. $\langle  \vec{v_{i}}, \vec{v_{j}} \rangle = 0 : \forall i \ne j$
>*(1)* besagt, dass die Vektoren in einem Orthogonalsystem die Länge 1 haben.
>*(2)* besagt, dass die Vektorem im einem Orthogonalysytem Paarweise aufeinander senkrecht stehen 

Zur Fallunterscheidung verwendet man folgende abkürzende Notation,
![[Pasted image 20251121125309.png]]
das **Kronecker-Delta**.

>[!note] **Beispiel**
>Für jedes $k \le n$ bilden die ersten $k$ Einheistvektoren in $\mathbb{R}^n$ ein Orthonormalsystem.

---

## Orthonormalbasen

>[!tip] 8.10 Satz
>Es sei $\vec{v_{1}}, \dots, \vec{v_{m}}$ ein Orthonormalsystem in $\mathbb{R}^n$. Für die Orthonormalbasis des aufgespannten Unterraums gilt:
>**(a)** Das System ist linear unabhängig
>**(b)** Für jedes $\vec{u} \in Lin(\vec{v_{1}}, \dots, \vec{v_{n}})$ gilt $$\vec{u} = \sum_{i=1}^m \langle \vec{v_{i}}, \vec{u} \rangle \cdot \vec{v_{i}}.$$

Nach (b) sind die Koordinaten eines Vektors in einer Orthonormalbasis die Skalarprodukte mit den Basisvektoren, genau wie in der Standartbasis.
![[Pasted image 20251121130325.png]]

#### BEWEIS 
![[Pasted image 20251121130356.png]]

> [!TIP] 8.11 Satz **Gram-Schmitdt-Verfahren**
> Sei $\vec{v_{1}}, \vec{v_{m}}$ ein l.u. System von Vektoren im $\mathbb{R}^n$. Dann gibt es ein Orthonormalsystem $\vec{u_{1}}, \dots, \vec{u_{m}}$ mit
> $$Lin(\vec{v_{1}}, \dots, \vec{v_{k}}) = Lin(\vec{u_{1}}, \dots, \vec{u_{k}})$$
> für alle $k = 1, \dots, m.$ 
> Insbes. besizt geder lin. UR von $\mathbb{R}^n$ eine Orthonormalbasis.

>[!note] **GSV** Beispiel
>![[Pasted image 20251121132448.png]]
>![[Pasted image 20251121132519.png]]

---
## Das orthogonale Komplement

>[!TIP] 8.7 Definition
>Ist $A \subset \mathbb{R}^n$ eine Teilmenge, dann schreiben wir: $$A^{\perp} = \{ \vec{v} \in \mathbb{R}^n \ | \ \forall \ \vec{a} \in A : \langle \vec{a}, \vec{v} \rangle = 0 \}.$$

> [!note] 8.13 Lemma
> Für jede Teilmenge $A \subset \mathbb{R}^n$ ist $A^\perp$ ein lin. Unterraum von $\mathbb{R}^n$.

#### BEWEIS 
![[Pasted image 20251124211701.png]]

Für beliebige $A, B  \subset \mathbb{R}^n$ gilt außerdem $$A \subset B \Rightarrow B^\perp \subset A^\perp .$$
> [!note] 8.14 Beispiel
> Für einen einzelnen Veltor $\vec{a} \in \mathbb{R}^n, \vec{a} \ne \vec{0},$ ist ![[Pasted image 20251124212459.png]]
> die Lösungs,emge einer homogenen Gleichung, also einer *Hyperebene*  im $\mathbb{R}^n$. Hat der Vektor $\vec{a}$ zusätzlich die Länge 1, dann nennt man ihn einen **Notmalenvektor** der Hyperebene $\{ \vec{a} \}$
> ![[Pasted image 20251124214304.png]]

Ist $U \subset \mathbb{R}^n$ ein *linearer Unterraum*, $\vec{u_{1}}, \dots, \vec{u_{n}}$ eine *Basis*  von $U$ und $v \in \mathbb{R}^n$, dann gilt $$\vec{v} \in U^\perp \Leftrightarrow \langle \vec{u_{j}}, \vec{v} \rangle = 0 \text{ für } j = 1, \dots, m$$
> [!TIP] **8.15 Satz**
> Ist $U \subset \mathbb{R}^n$ ein lin Unterraum, dann gelten
> 1. $U + U^\perp = \mathbb{R}^n$ und
> 2. $U\cap U^\perp =  \{ \vec{0} \}$.
> 
> Außerdem gilt $din(U) + dim(U^\perp) = n.$

#### BEWEIS
![[Pasted image 20251124214325.png]]![[Pasted image 20251124214344.png]]

> [!note] **8.16 Korollar**
> Für jeden lin. Unterraum $U \subset \mathbb{R}^n$ gilt $(U^{\perp})^{\perp} = U.$
> ![[Pasted image 20251124214611.png]]
