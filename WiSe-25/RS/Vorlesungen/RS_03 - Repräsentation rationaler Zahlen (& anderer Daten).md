#rs
## Rationale Zahlen

**Ziel:** Rationale Zahlen $q \in \mathbb{Q}$ repräsentieren können mit
- fester Repräsentationslänge von **$l$ Bits**
- fester Position des Kommas (**Festkommadarstellung**)

Bispiele für **$l$ = 8** bei **3 Nachkommastellen**
- 10,34 → 00010,340
- 93847,123 → 93847,123
- 0 → 00000,000
- 123456,78 → nicht darstellbra (zu viele Stellen vor dem Komma)
- 12.345678 → nicht darstellbar (aber runden denkbar)

→ **Beobachtung**
- Basis 10 im Bereich der Digitalen Rechner nur bedingt brauchbar
- Idee ist aber übertragbar auf Basis 2

**z.B.:**
![[Pasted image 20251021162659.png]]

### Allgemein gilt
- bei $v$ **Vorkommastellen**
- und $m$ **Nachkommastellen**
![[Pasted image 20251021162831.png]]

**ABER**
- nicht alle Zahlen darstellbar (z.B. π; 0,2)
	- Im Dezimalsystem ist $\frac{1}{3}$ nicht darstellbar

**VORTEILE**
- Abbildung von Rechenoperationen auf Ganzzahlenoperationen
- keine Fließkommahardware nötig
- Schnelle Ausführung
- Einsatz im Bereich digitale Signalverarbeitung

**NACHTEILE**
- feste Kommaposition
- unflexibel

### Andere Idee: Fließ-/Gleitkommadarstellung

![[Pasted image 20251021163211.png]]$$
2025 = 2.025 \cdot 10^3
$$
- Vorzeichenbit $s \in \{ 0, 1 \}$
- Mantisse $m \in \mathbb Q$
- Exponent $e \in \mathbb{Z}$ (bestimmt Kommaposition)$$also: \ \ z = (-1)^s \cdot m \cdot 10^e$$↓
**Normalisierte Gleitkommazahl** mit $1 \leq m \leq 10$
	⤷ z.B.: $2,025 \cdot 10^3$

### Übertragung auf Basis 2
- Vorzeichenbit $s \in \{ 0, 1 \}$
- Mantisse $m \in \mathbb Q$
- Exponent $e \in \mathbb{Z}$ (bestimmt Kommaposition)$$also \ hier: \ \ z = (-1)^s \cdot m \cdot 2^e$$↓
**Normalisierte Gleitkommazahl** mit $1 \leq m \lt 2$

**BEOBACHTUNG** Erste Ziffer der Mantisse ist **immer** 1, somit ist 0 nicht darstellbar

---
### IEEE-754 (1985) Standart

- **Vorzeichenbit** $s \in \{ 0, 1 \}$
- **Mantisse** $m \in \mathbb Q$
- **Exponent** $e \in \mathbb{Z}$
-  $1 \leq m \lt 2$ $$z = (-1)^s \cdot m \cdot 2^e$$
**Festlegung**
- Führende 1 der Mantisse wird nicht mit abgespeichert: **Implizite 1**
- Mantisse in Binärkodierung als _Festkommazahlen_ mit Ziffern **ausschließlich hinter dem Ko=(0001 \ 0101)_{2} = mma**
- Exponent in Exzessdarstellung mit Bias $b=2^{le-1}+1$
c.f. (Klasse **Formatter** von Java oder **printf** von C)

![[Pasted image 20251021165314.png]]

**Besonderheiten beim Exponenten**
- $e_{min} = -b +1 = -(2^{le-1})+1$
- $e_{max}= 2^{le} -1 -b -1 = 2^{le-1}-1$

**Beispiel**
![[Pasted image 20251021165742.png]]

Mit einem 32-Bit Integer lassen sich größere Zahlen darstellen als mit einer 32-Bit Fließkommazahl.

Aufgrund von Rundungsfehlern ist (a+b)+c nicht immer gleich a+(b+c).

#### Besondere Zahlen
![[Pasted image 20251021171153.png]]

![[Pasted image 20251021171805.png]]
![[Pasted image 20251021171836.png]]
![[Pasted image 20251021171920.png]]

![[Pasted image 20251021172239.png]]
![[Pasted image 20251021172300.png]]
![[Pasted image 20251021172321.png]]

![[Pasted image 20251021172644.png]]

![[Pasted image 20251021172705.png]]
![[Pasted image 20251021172741.png]]

---
---

## Repräsentation anderer Daten
Andere Daten sind z.B. Bilder, Audiodaten, Videodaten; Objekte, Flder, ...
=> Für uns interessant primitive Daten (Datentypen, die direkt von der Hardware unterstützt werden)

**Programme**
- Bitmuster fester Länge (z.B. 32 Bit, 64 Bit)
    - Befehl
    - Operanden

**Problem: Was repräsentiert ein Byte im Speicher?**
- Typbits höchstens für große Bereiche (Programm, Daten)
- Bei Daten sorgt der Compiler für richtige Interpretation
- Typisierung wichtig!

**Repräsentation von Datenfolgen**
Speicher oft in **Worten** organisiert
- Wort je nach Rechner 2 Bytes, 4 Bytes

**Heterogene Daten**
- Werden hintereinander in den Speicher geschrieben
- Dabei manchmal Wortgrenzen beachten
- Dann leere Zellen (Bytes) möglich

**Homogene Daten**
- Arrays
- Problem: Wie erkennt man das Ende der Folge?
    - Feste Anzahl vereinbaren
    - Länge am Anfang speichern
    - Spezielles Endezeichen verwenden