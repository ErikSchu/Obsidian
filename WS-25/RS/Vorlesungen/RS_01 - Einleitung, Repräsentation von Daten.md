#rs Siehe [[WS-25/Rs/Orga|Orga]]
https://rs.cs.tu-dortmund.de/RS1/V02-handout.html

![[Pasted image 20251016090115.png]]
![[Pasted image 20251014165924.png]]

## Räpresentation von Natürlichen Zahlen
Die Hardware von Computern **rechnet**
- 10 + 20
- 15 ⋅ 18

Zahlen werden **transportiert**, **verarbeitet**, und **weitergegeben**, wobei die Verarneitung elektronisch mit Leitungen und Halbleitern Erfolgt
- elektrische Spannung (0V, 5V, ...) liegt an Leitungen an
**ABER** Spannungslevel sind nicht komplett zuverlässig
- Schwankungen in der Spannungsversorgung
- Leckströme
- Verluste

#### Wie ordnen wir verschiedene Zahlen verschiedenen elektrischen Signalen zu?
- 0 = 0V?, 1 = 1V?, 2 = 2V? → problematisch!
- **Idee: Binäres Rechnen
	⤷** **Es gibt nur 2 Zahlen, z.B. 0 = 0V, 1 = 5V**

#### Warum Arbeiten moderne Rechner binär?
- technische Simplizität
	⤷ damit preisgünstig realisierbar
- hohe Genauigkeit
- leichte Programmierbarkeit

#### Problem
- Wie repräsentiert man mit nur zwei Grundzuständen…
    - … Zahlen? Natürliche Zahlen? Ganze oder reelle Zahlen?
    - … Texte?
    - … andere Daten?
- Wie repräsentieren wir eigentlich Zahlen?
	⤷ Was bedeutet überhaupt 2025?
    - 2025 = 2000 + 20 + 5
    - 2025 = $2 \cdot 1000 + 0 \cdot 100 + 2 \cdot 10 + 5 \cdot 1$

#### Lösung: Stellenwertsysteme
- 10 Ziffern {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}$_{10}$ oder 2 Ziffern {0, 1}$_{2}$
- Frage: Muss das Zahlensystem so aussehen?
- Behauptung: Es geht mit jeder Basis $(b \in \mathbb{N}\setminus \{1\})$

- **Basis b**
    - Ziffern {0, 1, …, **b-1**}
    - Schreibweise $(z_{\mathscr{l}-1} z_{\mathscr{l}-2} ... z_1 z_0)_b$
    - Beispiel (2 0 1 4)$_{10}$ = 2014
    - Bei Basis b > 10 reichen die Ziffern für die Darstellung nicht aus. Daher:
        - A für 10
        - B für 11
        - …
	    **⇨ Bei einer Basis b ist der Ziffernvorrat: {0, 1, …, b-1}**

___

## [[Umrechnung von Basen]]

#### Umrechnung: b=10 → b=10
$$ \begin{align*}
(3748)_{10}&= 3*10^3 + 7*10^2 + 4*10^1 + 8*10^0 \\
&= 3*1\ 000 + 7*100 + 4*10 + 8*1 \\
&= 3\ 000 + 700 + 40 + 8 \\
&= 3\ 748
\end{align*} $$

| Stelle          | 3    | 2   | 1   | 0   |
| --------------- | ---- | --- | --- | --- |
| Basis ^ Stelle  | 103  | 102 | 101 | 100 |
| Wert der Stelle | 1000 | 100 | 10  | 1   |
| Ziffer          | 3    | 7   | 4   | 8   |
| Wert            | 3000 | 700 | 40  | 8   |
|                 |      |     |     |     |

$$ 
\begin{align*}
(3748)_7 &= 2 \cdot 7^3 + 1 \cdot 7^2 + 6 \cdot 7^1 + 4 \cdot 7^0 \\
&= 2 \cdot 343 + 1 \cdot 49 + 6 \cdot 
\end{align*}
$$
| Stelle          | 3   | 2   | 1   | 0   |
| --------------- | --- | --- | --- | --- |
| Basis ^ Stelle  | 73  | 72  | 71  | 70  |
| Wert der Stelle | 343 | 49  | 7   | 1   |
| Ziffer          | 2   | 1   | 6   | 4   |
| Wert            | 686 | 49  | 42  | 4   |

**(1 0 1 1)2  
**\(= 1*2^3 + 0*2^2 + 1*2^1 + 1*2^0\) \(= 1*8 + 0*4 + 1*2 + 1*1\) \(= 8 + 0 + 2 + 1\)  
\(= 11\)

|Stelle|3|2|1|0|
|---|---|---|---|---|
|Basis ^ Stelle|23|22|21|20|
|Wert der Stelle|8|4|2|1|
|Ziffer|1|0|1|1|
|Wert|8|0|2|1|

**(1 2 A F)16  
**\(= 1*16^3 + 2*16^2 + 10*16^1 + 15*16^0\) \(= 1*4096 + 2*256 + 10*16 + 15*1\) \(= 4096 + 512 + 16 + 15\)  
\(= 4639\)

| Stelle          | 3    | 2   | 1   | 0   |
| --------------- | ---- | --- | --- | --- |
| Basis ^ Stelle  | 163  | 162 | 161 | 160 |
| Wert der Stelle | 4096 | 256 | 16  | 1   |
| Ziffer          | 1    | 2   | 10  | 15  |
| Wert            | 4096 | 512 | 16  | 15  |

**Besonderheit der Basis b=16**
(0)10 = (0)16 = (0000)2  
(1)10 = (1)16 = (0001)2  
(2)10 = (2)16 = (0010)2  
(3)10 = (3)16 = (0011)2  
(4)10 = (4)16 = (0100)2  
(5)10 = (5)16 = (0101)2  
(6)10 = (6)16 = (0110)2  
(7)10 = (7)16 = (0111)2

(8)10 = (8)16 = (1000)2  
(9)10 = (9)16 = (1001)2  
(10)10 = (A)16 = (1010)2  
(11)10 = (B)16 = (1011)2  
(12)10 = (C)16 = (1100)2  
(13)10 = (D)16 = (1101)2  
(14)10 = (E)16 = (1110)2  
(15)10 = (F)16 = (1111)2

**(3 E C 9)16  
**\(= 3*16^3 + E*16^2 + C*16^1 + 9*16^0\) \(= 3*4\ 096 + 14*256 + 12*16 + 9*1\) \(= 12\ 288 + 3\ 584 + 192 + 9\)  
\(= 16\ 073\)

|Stelle|3|2|1|0|
|---|---|---|---|---|
|Basis ^ Stelle|163|162|161|160|
|Wert der Stelle|4096|256|16|1|
|Ziffer|3|14|12|9|
|Wert|12288|3548|192|9

#### Namenskonventionen
- **Basis 10**    Dezimaldarstellung
- **Basis 2**    Binärdarstellung (Ziffern werden Bits genannt)
- **Basis 16**    Hexadezimaldarstellung (eigentlich Sedezimaldarstellung)

### Umrechnung in beliebige Basis
- - Jetzt müssen wir durch die Basis b teilen
	- (1 0)10 = (1 0 1 0)2
	- 10 / 2 = 5 Rest 0
	- 5 / 2 = 2 Rest 1
	- 2 / 2 = 1 Rest 0
	- 1 / 2 = 0 Rest 1

### ⇒ Divisionsalgorythmus
**Algorithmus 1**

**Eingabe** Basis \(b \in \mathbb{N} \setminus \{1\}\), Betragszahl \(n \in \mathbb{N}\)  
**Ausgabe** Repräsentation \((n_{\mathscr{l}} n_{\mathscr{l}-1} n_{\mathscr{l}-2} ... n_1 n_0)_b\)

> 1. \(\mathscr{l} := -1\)    // \(\mathscr{l}\) ist die Repräsentationslänge
> 2. So lange \(n > 0\) gilt
> 3.     \(\mathscr{l} := \mathscr{l}+1\)
> 4.     \(n_{\mathscr{l}} := n - b * \lfloor n/b \rfloor\)
> 5.     \(n := \lfloor n/b \rfloor\)


![[Pasted image 20251014173456.png]]


## Historische Entwicklung von Rechnern

### 1. Generation: Vakuumröhren (1945-1955)
- **John von Neumann** konzipierte einen speicherprogrammierten Digitalrechner mit 
	- Speicher
	- Reicheneinhaiten
	- Steuereinheiten
	- E-/A-Einheiten.
- Der **IBM 701** (1951) war der eiste wissenschaftliche Rechner. Er arbeitete nach dem *Von-Neumann-Modell*

### 2. Generatiom: Transistoren (1955-1965)
- **TX-0** als erster transistor-basierter Rechner am **M.I.T** entwickelt
- **Gründung der Digital Equipment Corporation** (1957)
	- **PDP-1:** Erster Mini-Computer
	- **PDP-8:** Nutzt erstmals ein Bus-System
- **Control Data Corporation** (CDC, Seymour Cray)
    - **Modell 6600** (1964)
        - Erster **Supercomputer**
        - 10x schneller als IBM-Top-Modell
        - **Parallele** Funktionseinheiten
        - Speziell für **Number Crunching**
- **Burroughs B5000** Rechner
    - Speziell für ALGOL 60

### 3. Generation: Integrierte Schaltungen (1965-1980)
- IBM führt mit System/360 eine einzige Produktlinie ein
    - Mehrprogrammbetrieb
    - Emulation anderer Rechner
- PDP-11 Erfolgreichster Rechner im wissenschaftlichen Bereich
    - 16 Bit Wortbreite
    - Offenes Bus-System

### 4. Generation: VLSI-Integration (seit 1980)
**Höhere Integrationsdichte** macht **persönliche Rechner** möglich
- Erster PC als Bausatz auf Basis des **Intel 8080**
- CP/M Betriebssystem für 8080-Rechner (Diskettenbasiert)
- **Steve Jobs & Steve Wozniak** bauen den Apple

**Pervasive / Ubiquitous Computing (heute)**
**Extreme Integrationsdichte** ermöglicht die Einbettung von Rechnern in quasi beliebige Artefakte des täglichen Lebens
- **Mobiltelefone** und persönliche Assistenten
- Kraftfahrzeuge Ca. 100 Steuergeräte (=1 Rechner) in Oberklasse-Fahrzeug