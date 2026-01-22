# LinA1 - 15.4 Körpererweiterungen

**Datum:** 22.01.2026  
**Kapitel:** 15.4 Körpererweiterungen  
**Prüfungsvorbereitung WS 25/26

## Grundkonzept

Wenn ein Körper K in einem anderen Körper L enthalten ist, können wir L als Vektorraum über K betrachten. Dies nennt man **Körpererweiterung**.

## Wichtige Beispiele

### 1. Komplexe Zahlen über reellen Zahlen
- **Vektorraum:** ℂ (komplexe Zahlen)
- **Skalarkörper:** ℝ (reelle Zahlen)
- **Vektoren:** Komplexe Zahlen der Form 𝑎 + 𝑏𝑖 mit 𝑎, 𝑏 ∈ ℝ
- **Skalarmultiplikation:** Für 𝛼 ∈ ℝ gilt 𝛼 · (𝑎 + 𝑏𝑖) = 𝛼𝑎 + 𝛼𝑏𝑖
- **Grundlage:** ℝ² wird bei der Konstruktion von ℂ verwendet

### 2. Reelle Zahlen über rationalen Zahlen
- **Vektorraum:** ℝ (reelle Zahlen)
- **Skalarkörper:** ℚ (rationale Zahlen)
- **Vektoren:** Reelle Zahlen (normale Addition als Vektoraddition)
- **Skalare:** Rationale Zahlen (normale Multiplikation als Skalarmultiplikation)
- **Vektorraumaxiome:** Alle erfüllt ✅

## Beispiel 15.20 - Lineare Unabhängigkeit

**Satz:** √2 ist irrational (bereits bewiesen in Satz 13.3)

**Aufgabe:** Zeige, dass 1 und √2 über ℚ linear unabhängig sind.

**Beweis:**
Angenommen, es gibt eine lineare Relation:
𝑐₁ · 1 + 𝑐₂ · √2 = 0 mit 𝑐₁, 𝑐₂ ∈ ℚ

**Fallunterscheidung:**
- Wenn 𝑐₂ ≠ 0, dann:
  √2 = -𝑐₁/𝑐₂ ∈ ℚ (Widerspruch, da √2 irrational ist!)
  
- Also muss 𝑐₂ = 0 sein
- Dann folgt: 𝑐₁ · 1 + 0 = 0 → 𝑐₁ = 0

**Ergebnis:** Nur die triviale Linearkombination gibt 0 → linear unabhängig ✅

## Wichtige Erkenntnisse für die Klausur

1. **Körpererweiterung = Vektorraum:** Sobald K ⊂ L ist eine Körpererweiterung, können wir L als Vektorraum über K betrachten

2. **Typische Beispiele kennen:**
   - ℂ über ℝ
   - ℝ über ℚ
   - ℚ(√2) über ℚ

3. **Lineare Unabhängigkeit:** Beweistechnik durch Widerspruch mittels Irrationalität

4. **Algebraische Bedeutung:** Diese Methode, Zahlen wie Vektoren zu behandeln, ist fundamental für die Algebra

## Merksatz

*"Zahlen sind nur spezielle Vektoren, wenn der Skalarkörper kleiner ist als der Vektorraum!"*

---
**Status:** ✅ Gelernt | 📝 Wiederholen | 🎯 Klausurrelevant