okular
# Beispieltest Lineare Algebra 1

**Zeit:** 15 Minuten | **Punkte:** 8

---

## Aufgabe 1 (3 Punkte)

Es sei V der Vektorraum ℝ³ mit der Standardbasis e₁, e₂, e₃. Gegeben seien die Vektoren w₁ = (1,2,0)ᵀ, w₂ = (0,1,1)ᵀ, w₃ = (1,0,1)ᵀ in ℝ³.

Geben Sie die eindeutig bestimmte lineare Abbildung φ: ℝ³ → ℝ³ mit
φ(e₁) = w₁, φ(e₂) = w₂, φ(e₃) = w₃
in Form einer Matrix an.

---

## Aufgabe 2 (3 Punkte)

Es sei T: ℝ³ → ℝ³ die lineare Abbildung mit Matrix
$$A = \begin{pmatrix} 1 & 1 & 1 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{pmatrix}$$

a) Bestimmen Sie Kern(T) und Bild(T).

b) Überprüfen Sie die Dimensionsformel.

---

## Aufgabe 2 (2 Punkte)

Es sei V = ℝ² und U ⊂ ℝ² die Menge
$$U = \left\{ \begin{pmatrix} x \\ y \end{pmatrix} \in \mathbb{R}^2 \ \middle|\ x + y = 0 \right\}$$

Zeigen Sie, dass U ein linearer Unterraum von ℝ² ist.

---

# Lösungen

---

## Aufgabe 1 (3 Punkte)

**Lösung:**

Nach dem Prinzip der linearen Ausdehnung (Satz 16.12) ist die lineare Abbildung durch ihre Werte auf der Basis eindeutig bestimmt.

Für einen beliebigen Vektor x = (x₁, x₂, x₃)ᵀ ∈ ℝ³ gilt:
$$x = x_1 e_1 + x_2 e_2 + x_3 e_3$$

Da φ linear ist:
$$\varphi(x) = \varphi(x_1 e_1 + x_2 e_2 + x_3 e_3) = x_1 \varphi(e_1) + x_2 \varphi(e_2) + x_3 \varphi(e_3)$$

Einsetzen der Bilder:
$$\varphi(x) = x_1 \begin{pmatrix} 1 \\ 2 \\ 0 \end{pmatrix} + x_2 \begin{pmatrix} 0 \\ 1 \\ 1 \end{pmatrix} + x_3 \begin{pmatrix} 1 \\ 0 \\ 1 \end{pmatrix} = \begin{pmatrix} x_1 + x_3 \\ 2x_1 + x_2 \\ x_2 + x_3 \end{pmatrix}$$

In Matrixform:
$$\varphi(x) = \begin{pmatrix} 1 & 0 & 1 \\ 2 & 1 & 0 \\ 0 & 1 & 1 \end{pmatrix} \cdot x$$

Die Matrix hat als Spalten die Bilder der Basisvektoren: φ(e₁) = w₁, φ(e₂) = w₂, φ(e₃) = w₃.

$$\boxed{M_\varphi = \begin{pmatrix} 1 & 0 & 1 \\ 2 & 1 & 0 \\ 0 & 1 & 1 \end{pmatrix}}$$

---

## Aufgabe 2 (3 Punkte)

**Lösung a):**

**Kern(T):** Lösungen von T(x) = 0, also Ax = 0.

$$\begin{pmatrix} 1 & 1 & 1 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \\ 0 \end{pmatrix}$$

Aus der dritten Zeile: x₃ = 0

ile: x₂ + x₃ = 0 ⇒Aus der zweiten Ze x₂ = 0

Aus der ersten Zeile: x₁ + x₂ + x₃ = 0 ⇒ x₁ = 0

$$\text{Kern}(T) = \{0\} \quad (\text{eindimensionaler Nullraum})$$

**Bild(T):** Spalten der Matrix A (da T(x) = Ax)

$$\text{Bild}(T) = \text{Lin}\left( \begin{pmatrix} 1 \\ 0 \\ 0 \end{pmatrix}, \begin{pmatrix} 1 \\ 1 \\ 0 \end{pmatrix}, \begin{pmatrix} 1 \\ 1 \\ 1 \end{pmatrix} \right)$$

Die drei Spaltenvektoren sind linear unabhängig (obere Dreiecksmatrix mit Einsen auf der Diagonale ⇒ voller Rang), also:
$$\text{Bild}(T) = \mathbb{R}^3 \quad (\text{dim} = 3)$$

---

**Lösung b):**

**Dimensionsformel:** dim(V) = dim(Bild(T)) + dim(Kern(T))

- dim(V) = dim(ℝ³) = 3
- dim(Bild(T)) = 3
- dim(Kern(T)) = 0

Rechte Seite: 3 + 0 = 3 = dim(V)

$$\boxed{3 = 3 + 0 \quad \text{(Formel erfüllt)}}$$

---

## Aufgabe 3 (2 Punkte)

**Lösung:**

Wir zeigen die Unterraumkriterien (NL), (ADD) und (SKM):

**(NL) Nichtleer:**
0 = (0,0)ᵀ erfüllt 0 + 0 = 0, also 0 ∈ U. U ≠ ∅ ✓

**(ADD) Abgeschlossen unter Addition:**
Seien u = (x₁, y₁)ᵀ ∈ U und v = (x₂, y₂)ᵀ ∈ U.

Dann gilt: x₁ + y₁ = 0 und x₂ + y₂ = 0.

Für die Summe: u + v = (x₁+x₂, y₁+y₂)ᵀ

Prüfe: (x₁+x₂) + (y₁+y₂) = (x₁+y₁) + (x₂+y₂) = 0 + 0 = 0

Also u + v ∈ U. ✓

**(SKM) Abgeschlossen unter Skalarmultiplikation:**
Sei u = (x, y)ᵀ ∈ U und a ∈ ℝ.

Dann gilt: x + y = 0.

Für das skalare Vielfache: a·u = (ax, ay)ᵀ

Prüfe: ax + ay = a(x + y) = a·0 = 0

Also a·u ∈ U. ✓

Da alle drei Kriterien erfüllt sind, ist U ein linearer Unterraum von ℝ².

Alternative mit dem LK-Kriterium:
Seien u, v ∈ U und a, b ∈ ℝ.

Dann: a·u + b·v = (ax₁+bx₂, ay₁+by₂)ᵀ

(ax₁+bx₂) + (ay₁+by₂) = a(x₁+y₁) + b(x₂+y₂) = a·0 + b·0 = 0

Also a·u + b·v ∈ U. ✓

---

# Bewertungshinweise

| Aufgabe | Punkte | Typische Fehler |
|---------|--------|-----------------|
| 1 | 3 | Matrix nicht transponiert, Vorzeichenfehler |
| 2a | 2 | Kern falsch berechnet, Bild nicht als Span geschrieben |
| 2b | 1 | Dimensionsformel nicht korrekt angewandt |
| 3 | 2 | Ein Kriterium vergessen, Rechnungsfehler |

**Gesamt:** 8 Punkte
