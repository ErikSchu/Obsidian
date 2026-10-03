#lina1
## 9.1 Liniarität
Jede $m \times n$ - Matrix können mit einem Vektor aus $\mathbb{R}^n$ multiplizieren und erhalten einen Vektor aus $\mathbb{R}^m$. Jedes $A \in Mat_{m \times n}(\mathbb{R})$ definiert die Abbildung $$\varphi_{A}: \mathbb{R}^n \rightarrow \mathbb{R}^m, \vec{x} \mapsto A \vec{x}.$$
Ist $A \vec{x} = \vec{b} \in \mathbb{R}^m$ ein LGS mit Koeffizientenmatrix $A$, dann ist eine Lösung des Systems ein Vektoren in $\mathbb{R}^n$, ver von $\varphi_A$ auf $\vec{b}$ abgebildet wird. 
Die Lösungen sind also die *Urbilder* von $\vec{b}$ unter der Abbildung $\varphi_A$.

Nach den Regel für das Matrix-Vektor.Produkt gilt 
![[Pasted image 20251124215826.png]]
und außerdem ![[Pasted image 20251124215848.png]]
für alle $\vec{x}, \vec{y} \in \mathbb{R}^n$ und alle $c \in \mathbb{R}$. Das führt zu folgender Definition:

>[!TIP] **9.1 Definition**
>Eine Abbildung $\varphi: \mathbb{R}^n \rightarrow \mathbb{R}^m$ heißt *linear*, wenn sie die folgenden Eigenschaften besitzt:
>1. $\forall \ \vec{x}, \vec{y} \in \mathbb{R}^n: \varphi(\vec{x} + \vec{y}) = \varphi(\vec{x}) + \varphi (\vec{y})$ **(Additivität)**
>2. $\forall \ \vec{x} \in \mathbb{R}^n, c \in \mathbb{R}: \varphi(c \vec{x}) = c \cdot \varphi(\vec{x})$ **(Homogenität)**

Ist $\varphi:\mathbb{R}^n \rightarrow \mathbb{R}^m$ eine lineare Abbildung und $c_{1}\vec{v_{1}} + \dots + c_{k}\vec{v}_{k}$ eine Linearkombination von Vektoren $v_{1}, \dots, \vec{v_{k}} \in \mathbb{R}^n$, dann können wir die Liniarität von $\varphi$ mehrfach anwendne und bekommen
![[Pasted image 20251124221049.png]]

Man kann die lineare Abbildung $\varphi$ also *aus der Linearkombination herausziehen* und in sie*hineinziehen*.

>[!note] **9.1 Lemma**
>Jede lineare Abbildung $\varphi: \mathbb{R}^n \rightarrow \varphi (\vec{0}) = \vec{0}$

>[!note] **9.2 Lemma**
>1. Ist $A \in Mat_{m \times n} (\mathbb{R})$ mit Spaltvektoren $\vec{b_{1}}, \dots \vec{b_{n}} \in \mathbb{R}^m$, dann gilt $$\varphi_{A} (\vec{e_{i}}) = \vec{b_{i}}.$$Die Spalten von $A$ sind also die Bilder der Einheitsvektoren. Für jedes $\vec{x} \in \mathbb{R}^m$ gilt dann $$\varphi_A(\vec{x}) = x_{1} \vec{b_{1}} + \dots + x_{n} \vec{b_{n}}$$
>2. Jede lineare Abbildung kommt von einer Matrix, d.h. für jede lineare Abbildung $\varphi: \mathbb{R}^n \rightarrow \mathbb{R}^m$ existiert eine Matrix $A \in Mat_{m \times n} (\mathbb{R})$ mit   $\varphi = \varphi_{A}$

> [!def] 9.3 Korollar **Lineare Ausdehnung**
> Zu jeder Wahl von $n$ Vektoren $\vec{v_{1}}, \dots, \vec{v_{n}} \in \mathbb{R}^m$  gibt es genau eine lineare Abbildung $\varphi: \mathbb{R}^n \rightarrow \mathbb{R}^m$ mit $$\varphi(\vec{e_{1}}) = v_{1}, \dots, \varphi(\vec{e_{n}}) = \vec{v_{n}}.$$

