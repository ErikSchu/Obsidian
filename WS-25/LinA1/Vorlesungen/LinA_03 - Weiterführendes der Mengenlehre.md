#lina1

### Wiederhohlung Potenzmengen
Def.: Sei A eine Menge. Die **Potentmenge** $\mathcal{P}(A)$ ist die Menge, deren Elemente die Teilmengen von A sind. 

**(a)** Es gilt immer $\{\} \in \mathcal{P}(A) \land A \in \mathcal{P}(A)$ 

**(b)** Potenzmenge der menge A = {a, b, c} mit drei Elementen ist:
![[Pasted image 20251023191520.png]]
Dabei ist {a} ≠ a. Es gilt $a \in A$ aber $\{a\} ⊂  A$ deshalb $\{a\} \in \mathcal{P}(A)$. 

**(c)** Potenzmenge der Leeren menge ist {{}}, besteht also aus einem elemet → **Potenzmenge einer Menge niemals leer**

**(d)** Elemente von $\mathcal{P}{(\mathbb{R}^n)}$ sind alle möglichen Mengen mit Vektoren. Darunter auch Geraden, aber auch unzähliche weitere Teilmengen

---

## Bildmenge
Es sei f: $X \to Y \ \ x \mapsto f(x)$ eine Abbildung. Für jede Teilmenge A $\subset$ X ist
![[Pasted image 20251023193513.png]]
die **Bildmenge** von A unter f.

## Urbild(-menge)
Für B c Y ist die **Urbildmenge** B unter f die Menge
![[Pasted image 20251023193857.png]]
Für y E Y heißt jedes Element der Menge
![[Pasted image 20251023194015.png]]
ein Urbild unter f.
→ Nicht zu verwechseln mit der Umkehrfunktion

### Operatoren
Während f jedem Element von X ein Element von Y zuordnet, findet die Zuordnung hier auf der Ebene der Teilengen von X und Y statt. Der **Bildoperator** und der **Urbildoperator** lassn sich als Abbildungen![[Pasted image 20251023195408.png]]
zwischen den Potenzmengen von X und Y auffassen, was allerdings sehr formal ausgedrückt ist.

![[Pasted image 20251023200051.png]]

---

## Injektive, surjektive & bijektive Abbildungen
Eine Abbildung f : X → Y heißt

- **injektiv (Injektion)**, wenn verschiedene Elemente von X auch verschiedene bilder unter f haben: (y E Zielmenge *höchstens* ein Urbild)![[Pasted image 20251023200321.png]]
	oder logisch äquivalente Formulierung (Kontraposition)![[Pasted image 20251023200515.png]]

- **surjektiv (Surjektion)**, wenn jedes Element von Y im Bild von f liegt. Die Bildmenge von f ist ganz Y: (y E Zielmenge *mindestens* ein Urbild) ![[Pasted image 20251023201622.png]]

- **bijektiv (Bijektion)**, wenn sie *injektiv und *surjekiv* ist. (*genau* ein Urbild)

![[Pasted image 20251023202455.png]]

#### Beispiele
![[Pasted image 20251023202602.png]]![[Pasted image 20251023202715.png]]

![[Pasted image 20251023202814.png]]


## Identität
Sind f: X → Y und g: Y → X zwei Abbildungen mit ![[Pasted image 20251023203118.png]] dann ist g surjektiv,
Dabei ist g nach f = id_x eine *Gleichheit zwichen Abbildungen:* der Wert ist für x E X derselbe, also g(f(x)) = (g nach f) (x) = id_x = x für alle x E X.
![[Pasted image 20251023203532.png]]

### 2.6 Satz 
Es seien 𝑓: 𝑋 → 𝑌 und 𝑔: 𝑌 → 𝑍 zwei Abbildungen.

**(a)** Sind 𝑓 und 𝑔 injektiv bzw. surjektiv bzw. bijektiv, dann hat auch 𝑔 ◦ 𝑓 die ent-
sprechende Eigenschaft.
**(b)** Ist 𝑔 ◦ 𝑓 injektiv, dann ist 𝑓 injektiv.
**(c)** Ist 𝑔 ◦ 𝑓 surjektiv, dann ist 𝑔 surjektiv.
**(d)** Ist 𝑔 ◦ 𝑓 bijektiv, dann ist 𝑓 injektiv und 𝑔 surjektiv.

## 2.7 Satz: Umkehrabbildung

Sei $f: X \to Y$ eine Abbildung. Genau dann ist f bijektiv,  wenn es eine Abbbildung $g: Y \to X$ gibt mit $$
g \circ f = id_{X} \ \ und \ \ f \circ g = id_{Y}.
$$Die Abbildung g durch f ist hiermit eindeutig bestimmt.

![[Pasted image 20251024102601.png]]

**Def.:** Es sei $f: X \to Y$ eine *Bijektion*. Die eindeutig bestimmte Abbildung $g:X\to Y$ aus 2.7 heißt **Umkehrabbildung** oder **Inverse** von $f$ und wird mit $f^{-1}$ bezeichnet. Sie erfüllt also $$
f^{-1} \circ f = id_{X} \ \ und \ \ f \circ f^{-1} = id_{Y}.
$$
### Unterschied Umkehrabbildung - Urbildoperator

| **Eigenschaft** | **Umkehrabbildung (f−1)**             | **Urbildoperator (f−1)**                                               |
| --------------- | ------------------------------------- | ---------------------------------------------------------------------- |
| **Existenz**    | **Nur**, wenn $f$ bijektiv ist.       | **Immer**, für jede Funktion $f$.                                      |
| **Input**       | Ein **Element** $y \in Y$             | Eine **Teilmenge** $B \subseteq Y$                                     |
| **Output**      | Ein eindeutiges **Element** $x \in X$ | Eine **Teilmenge** von $X$ (kann leer sein, ein oder hohe Mächtigkeit) |

#### Beispiel
![[Pasted image 20251024104310.png]]
![[Pasted image 20251024104341.png]]

---
## Bemerkungen
#### 1. Wohldefiniertheit von Abbildungen

- **Grundsatz:** Eine Abbildung (Funktion) ist nur dann korrekt definiert, wenn sie jedem Element aus der Startmenge (Quelle) **genau ein** Element aus der Zielmenge zuordnet. Man nennt dies **wohldefiniert**.
    
- **Problembeispiel:** Der Versuch, eine Abbildung `f` von den rationalen Zahlen (ℚ) zu den ganzen Zahlen (ℤ) zu definieren, die einem Bruch `a/b` einfach den Zähler `a` zuordnet.
    
    - Dies scheitert, da eine rationale Zahl unendlich viele Darstellungen hat (z. B. ist `1/2 = 2/4 = 3/6`).
        
    - Die Abbildung wüsste nicht, welchen Wert sie zuordnen soll (1, 2 oder 3?).
        
    - **Fazit:** Eine solche Vorschrift ist nicht wohldefiniert und somit keine gültige Abbildung.


#### 2. Paradoxa der Mengenlehre (Russellsches Paradoxon)

- **Grundproblem:** Bildet man sorglos "Mengen von Mengen", kann dies zu logischen Widersprüchen führen.
    
- **Beispiel: Die "Menge aller Mengen"**
    
    1. Man definiert die Menge `B` als die "Menge aller Mengen, die sich nicht selbst als Element enthalten".
        
    2. Die paradoxe Frage lautet: Enthält sich die Menge `B` selbst als Element (`B ∈ B`)?
        
        - **Fall 1: Angenommen, `B` enthält sich selbst.** Dann erfüllt `B` die Bedingung, sich nicht selbst zu enthalten, nicht mehr. Es müsste also `B ∉ B` gelten. → **Widerspruch**.
            
        - **Fall 2: Angenommen, `B` enthält sich nicht selbst.** Dann erfüllt `B` die Bedingung für die Aufnahme in `B`. Es müsste also `B ∈ B` gelten. → **Widerspruch**.

- **Analogie (Barbier-Paradoxon):** "Ein Barbier rasiert genau die Männer, die sich nicht selbst rasieren." Wer rasiert den Barbier? Dasselbe logische Problem.
    
- **Konsequenz:** Dieses als **Russellsches Paradoxon** bekannte Problem führte zur "Grundlagenkrise" der Mathematik. Moderne Axiomensysteme wie die **Zermelo-Fraenkel-Mengenlehre** lösen dies, indem sie unter anderem verbieten, dass eine Menge sich selbst enthalten kann.