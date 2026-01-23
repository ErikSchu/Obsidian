# Lernzettel Lineare Algebra 1 - Testat 6

## Kapitel 15: Vektorräume

### 15.1 Vektorräume - Grundlagen

**Definition (Vektorraum über K):**
Ein K-Vektorraum ist eine abelsche Gruppe (V, +) mit Skalarmultiplikation K × V → V, (a, v) ↦ a·v und den Axiomen:
- **(VA)** Assoziativität: ∀a,b∈K, v∈V: (ab)v = a(bv)
- **(VD)** Distributivität: ∀a,b∈K, v,w∈V: ((a+b)v = av + bv) ∧ (a(v+w) = av + aw)
- **(VE)** Einselement: ∀v∈V: 1·v = v

**Wichtige Rechenregeln:**
1. v + w = v ⇒ w = 0
2. v + w = 0 ⇒ w = -v
3. 0·v = 0 und a·0 = 0
4. av = 0 ⇒ a = 0 oder v = 0
5. -1·v = -v

**Beispiele:**
- Kⁿ mit komponentenweiser Addition/Multiplikation
- K^ℕ (Folgenraum)
- Mat_{m×n}(K) ≅ K^{mn}

### 15.2 Funktionenräume

Die Menge Abb(X,K) aller Abbildungen X → K ist ein Vektorraum mit:
- (f+g)(x) = f(x) + g(x)
- (a·f)(x) = a·f(x)

**Wichtige Unterräume:**
- C⁰(ℝ) = {stetige Funktionen}
- Cᵏ(ℝ) = {k-mal differenzierbare Funktionen}
- C^∞(ℝ) = {beliebig oft differenzierbare Funktionen}
- Polynomraum 𝕂[x]_{≤d}

### 15.3 Lineare Unabhängigkeit, Basen, Dimensionen

**Lineare Unabhängigkeit:**
System (v₁,...,vₘ) ist lin. unabh., wenn Σcᵢvᵢ = 0 ⇒ alle cᵢ = 0

**Basis:** System ist linear unabhängig UND erzeugend

**Satz 15.14 (wichtig für Testat!):**
1. Basisauswahl: Jedes Erzeugendensystem enthält eine Basis
2. Alle Basen haben dieselbe Länge
3. Äquivalenzen für n Vektoren in n-dimensionalem Raum:
   - Basis ⇔ eindeutige Darstellung ⇔ erzeugend und nicht verkürzbar ⇔ lin. unabh. und nicht verlängerbar
4. Jeder Unterraum ist endlichdimensional
5. Basisergänzung: Jede Basis eines Unterraums lässt sich zu einer Basis des Gesamtraums ergänzen

**Dimensionsformel für Unterräume:**
dim(U₁ + U₂) = dim(U₁) + dim(U₂) - dim(U₁ ∩ U₂)

**Korollar 15.17:**
In n-dimensionalem Raum sind für n Vektoren äquivalent:
- Basis
- Erzeugendensystem
- Linear unabhängig

**Direktes Produkt:**
dim(V × W) = dim(V) + dim(W)

### 15.4 Körpererweiterungen

ℂ als ℝ-Vektorraum: Basis {1, i}, dim = 2
ℝ als ℚ-Vektorraum: unendlichdimensional
1 und √2 sind über ℚ linear unabhängig

---

## Kapitel 16: Lineare Abbildungen

### 16.1 Grundlagen linearer Abbildungen

**Definition:**
φ: V → W ist linear, wenn:
- **(ADD)** φ(v₁+v₂) = φ(v₁) + φ(v₂)
- **(H)** φ(cv) = cφ(v)

**Zusammengefasst (LIN):**
φ(c₁v₁ + c₂v₂) = c₁φ(v₁) + c₂φ(v₂)

**Eigenschaft:**
φ(Σcᵢvᵢ) = Σcᵢφ(vᵢ)
φ(Lin(v₁,...,vₖ)) = Lin(φ(v₁),...,φ(vₖ))

**Beispiele:**
- Matrixabbildung: φ_A(x) = Ax
- Skalarmultiplikation: v ↦ av
- Nullabbildung: v ↦ 0
- Projektion: (v,w) ↦ v
- Differentialoperator: f ↦ f'

### 16.2 Kern und Bild

**Lemma 16.2:** φ(0) = 0

**Lemma 16.3:** Urbilder und Bilder von Unterräumen sind wieder Unterräume

**Definition:**
- **Kern:** Kern(φ) = {v ∈ V | φ(v) = 0} ⊂ V
- **Bild:** Bild(φ) = φ(V) ⊂ W
- **Rang:** dim(Bild(φ))

**Satz 16.4:**
1. φ injektiv ⇔ Kern(φ) = {0}
2. φ surjektiv ⇔ Bild(φ) = W

**BEISPIEL:** Differentialoperator: Kern = konstante Funktionen → nicht injektiv

**Satz 16.6 - Dimensionsformel:**
dim(V) = dim(Bild(φ)) + dim(Kern(φ))
Insbesondere: dim(Bild(φ)) ≤ dim(V)

### 16.3 Isomorphismen

**Lemma 16.7:** Umkehrung einer bijektiven linearen Abbildung ist wieder linear

**Definition:**
Isomorphismus = bijektive lineare Abbildung
V und W isomorph ⇔ ∃ Isomorphismus V → W

**Beispiele:**
- ℝ → Lin(w), c ↦ cw (w ≠ 0) ist Isomorphismus
- ℝᵐ ≅ ℝⁿ nur für m = n
- 𝕂[x]_{≤d} ≅ 𝕂^{d+1} (Koeffizientenvektor)

**Lemma 16.9:** Isomorphe Vektorräume haben dieselbe Dimension

### 16.4 Räume linearer Abbildungen

**Satz 16.10:**
Für lineare φ, ψ, a ∈ K:
- φ + ψ ist linear
- a·φ ist linear
- ψ∘φ ist linear

**Schreibweise:** 𝒫(V,W) = {φ: V → W | φ linear}
Auch: Hom(V,W) = ***Homomorphismen***

**Korollar 16.11:**
- 𝒫(V,W) ist ein Vektorraum (mit + und ·)
- 𝒫(V,V) ist ein Ring mit Verknüpfung ∘ (Endomorphismenring)

**Definition:** Endomorphismus = lineare Abbildung V → V

### 16.5 Prinzip der linearen Ausdehnung

**Satz 16.12 - Lineare Ausdehnung:**
V sei endlichdimensional mit Basis v₁,...,vₙ. Dann existiert zu jedem W und jeder Wahl w₁,...,wₙ ∈ W GENAU eine lineare Abbildung φ: V → W mit φ(vᵢ) = wᵢ.

**Korollar 16.13:** Zwei endlichdimensionale Räume sind isomorph ⇔ gleiche Dimension

**Korollar 16.14:**
Betrachte φ: Kⁿ → V, (x₁,...,xₙ) ↦ Σxᵢvᵢ
1. φ injektiv ⇔ v₁,...,vₙ lin. unabh.
2. φ surjektiv ⇔ v₁,...,vₙ erzeugend
3. φ Isomorphismus ⇔ v₁,...,vₙ Basis

**Korollar 16.16:** Jeder n-dimensionale K-Vektorraum ist isomorph zu Kⁿ

---

## Prüfungsrelevante Formeln

| Konzept | Formel |
|---------|--------|
| Dimensionsformel | dim(V) = dim(Bild) + dim(Kern) |
| Unterraum-Dimension | dim(U₁+U₂) = dim(U₁)+dim(U₂)-dim(U₁∩U₂) |
| Produkt-Dimension | dim(V×W) = dim(V)+dim(W) |
| Isomorphie-Kriterium | V ≅ W ⇔ dim(V) = dim(W) (endlichdim.) |

---

## Typische Testat-Aufgaben

1. **Vektorraum nachweisen:** Axiome VA, VD, VE zeigen
2. **Unterraum zeigen:** NL, ADD, SKM oder LK
3. **Lineare Unabhängigkeit:** Koeffizienten gleich 0 setzen
4. **Basis ergänzen/auswählen:** Aus Erzeugendensystem Basis extrahieren
5. **Lineare Abbildung definieren:** Mit Basis und Prinzip der linearen Ausdehnung
6. **Kern/Bild berechnen:** LGS lösen
7. **Dimensionsformel anwenden:** Zusammenhang zwischen dim V, dim Bild, dim Kern
8. **Isomorphismus nachweisen:** Bijektivität + Linearität oder dim-Vergleich
