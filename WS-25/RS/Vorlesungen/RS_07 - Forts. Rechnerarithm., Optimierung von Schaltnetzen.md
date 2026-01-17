#rs Donnerstag, 06.11.2025

**z.E:**
- Carry-Lookahead-Addierer
- Carry-Save-Addierer
- Ripple-Carry-Addoerer

## Multiplikation: Addition vieler Zahlen

### Wallace-Tree
- **Carry Save Adder** CSA
- $m_{i}$ sind $n$-bit Zahlen
- Sinnvoll wenn CSA flacher als CLA-Addierer
![[Pasted image 20251106101833.png]]

### Multiplikation: Carry Save Adder
**Gesucht:** Addierer, mit drei Eingängen und zwei Ausgängen, für die gilt:

**Gefunden:** **Volladdierer**, der für   folgendes Resultat liefert
- $s$ ist das Summenbit
- $2c$ ist das Übertragsbit, bezogen auf seine Stelle 1 Position weiter links

- Parallelschaltung von $n$ Volladdierern
- Liefern jeweils die **Summenbits**

$\vdots$

#### Berechnung von drei n-Bit Zahlen
- Zum einsatz komen $n$ Volladdierer
- Größe: 5$n$
- Tiefe: 3
	⮱ Der Carry (große) Look-Ahead Addierer wird in einem Wallace-Tree erst als letzte Operation benötigt
	- Er hat somit für die Addition von n Zahlen folgende Eigenschaften
		- Größe $\approx \dots$


![[Pasted image 20251106102957.png]]

# Addition ganzer Zahlen

**Addition positiver, ganzer Zahlen**
- Einerkomplement
- Zweierkomplement
- Vorzeichenbetragsdarstellung    
-  Addition einfach, da Zahlen binär dargestellt werden, evtl. Überträge beachten

**Addition von Zahlen in Exzessdarstellung**
- Für Exzessdarstellung funktioniert Addierer selbst bei positiven Zahlen **nicht** $$x+y=(b+x)+(b+y)= (b+x+y)+b$$
→ Exzessdarstellung fürs Rechnen **weitgehend ungeeignet**, nur günstig für Vergleiche.

# Addition ganzer Zahlen

**Warum ist die Addition ganzer Zahlen wichtig?**
**Beobachtung** Niemand muss subtrahieren!
- Statt “x-y” einfach “x + (-y)” rechnen!
- **Idee** **Ersetze** Subtraktion durch
    1. Vorzeichenwechsel
    2. **Addition** einer eventuell negativen Zahl  

**Bleibt noch zu untersuchen**
1. Wie schwierig ist der Vorzeichenwechsel?
2. Wie funktioniert die Addition von negativen Zahlen?

**Vorzeichenwechsel**

|Repräsentation|Vorgehen|Kommentar|
|---|---|---|
|Vorzeichen-Betrag|Vorzeichen-Bit invertieren|Sehr einfach|
|Einerkomplement|Alle Bits invertieren|Einfach|
|Zweierkomplement|Alle Bits invertieren, 1 addieren|Machbar|

**Grundsätzlich ist ein Vorzeichenwechsel machbar**

#### Addition negativer, ganzer Zahlen
**Beobachtung**
- Ripple-Carrier Addierer
- Carry Look-Ahead Addierer
- Sind für Betragszahlen entworfen worden  

Muss die Hardware für die Addition negativer, ganzer Zahlen neu entworfen werden?
- **Exzessdarstellung** Betrachten wir gar nicht, weil wir damit nicht einmal addieren können
- **Vorzeichen-Betrag** Positive und negative fast gleich dargestellt, darum neuer Schaltnetzentwurf erforderlich

#### Addition negativer Zahlen ($l$ bit) im Zweierkomplement
Notation Ȳ ist Komplement von y

**Beobachtung**                
![[Pasted image 20251106104438.png]]

**Rechnung**
![[Pasted image 20251106104505.png]]
                 
**Beobachtung**
- Darstellungslänge → $2^l$ “passt nicht” (Überlauf)
- Überlauf ignorieren → **Rechnung korrekt**
- Addierer rechnet **richtig** auch für negative Zahlen
→ Wir benötigen keine neue Hardware, nur ein paar Regeln.

### Überträge bei Addition im Zweierkomplement

**Wann ist das Ergebnis korrekt und wann nicht darstellbar?**

1. Addition zweier positiver Zahlen
    - Ergebnis positiv
    - Kein Überlauf möglich
    - **Ergebnis korrekt, wenn es positiv ist**

2. Addition einer positiven und einer negativen Zahl
    - Ergebnis kleiner als größte darstellbare Zahl
    - Ergebnis größer als kleinste darstellbare Zahl
    - **Ergebnis immer korrekt**

3. Addition zweier negativer Zahlen
    - Überlauf entsteht (ignorieren)
    - Ergebnis muss negativ sein
    - **Ergebnis korrekt, wenn es negativ ist**

---

# Addition von FLießkommazahlen

#### Fließkommazahlen
**Darstellung gemäß IEEE 754-1985**

$$\begin{align}
&x = (-1)^{s_x} * m_x * 2^{e_x} \\
&y = (-1)^{s_y} * m_y * 2^{e_y} \\
&z = x + y = (-1)^{s_z} * m_z * 2^{e_z}
\end{align}
$$

- **s**       → Vorzeichenbit
- **m**      → Mantisse (Binärdarstellung, **inklusive** impliziter 1)
- **e**       → Exponent (Exzessdarstellung, $b = 2^{\ell_e-1}-1$)

**Beobachtung**
- Beobachtung ist einfach, wenn $e_x = e_y = e$$ und $s_x = s_y = s$ gilt: $z = (-1)^s * (m_x + m_y) * 2^e$

### Algorithmus zur Addition
**Ziel:** Berechne \(z = x + y\)
Ohne Beschränkung der Allgemeinheit: Sei \(e_x \ge e_y\)  
→ Sonst werden x und y vertauscht  

Wir unterscheiden zwei Fälle:
1. $s_x = s_y$: Beide Zahlen haben das gleiche Vorzeichen
2. $s_y \ne s_y$: Die Zahlen haben unterschiedliche Vorzeichen  

**Generelles Problem:** Bei der Addition können signifikante Bits verloren gehen!

**Fall 2:** $s_x \ne s_y$ (unterschiedliche Vorzeichen)

$z = x + y = (-1)^{s_z}[m_x2^{e_x} - m_y2^{e_y}]$ $= (-1)^{s_x} * 2^{e_x} [m_x - m_y2^{e_y - e_x}]$

**Angenommen es gibt 2 IEEE 754-1985 Zahlen \(x\) und \(y\) und wir berechnen \(z=x+y\);**
Wenn $s_x≠s_y$ und $e_x=e_y$, welche Werte kann $m_x-m_y$ (Mantisse $m_x \geq m_y$) annehmen?

### Beispiel Addition von Fließkommazahlen

x      1       1001 0101 111 0010 0000 0000 0000 0000  
y      1       1001 0100 110 0001 1000 0000 0000 0000

$e_x \ge e_y$, Vorzeichen gleich, also zunächst nur $s_z := 1$

Mantisse $(m_y$ um $e_x - e_y = 1$ Stelle/-n nach rechts verschieben  
→ 0,111000011

Mantissen addieren
