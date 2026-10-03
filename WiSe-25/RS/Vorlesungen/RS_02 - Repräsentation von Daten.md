#rs 16.10.2025
https://rs.cs.tu-dortmund.de/RS1/V02-handout.html

*Alles, was wir wissen, können wir aufschreiben. → Repräsentation von Texten ist zentral.*
## Räpresentation von Texten
### Naiver Ansatz
- Codierung A → 0, B →1, ... ⇨ Dannach Binärcodierung
	**⤷ Probleme**
	- Welche Zeichen sollen codiert werden?
	- Wie kann man daten mit anderen tauschen?
	**⇨ Standartisierung**

-  Text = Zeichenfolgen aus Buchstaben & Satzzeichen
	- Darstellung mittels Bitfolgen
	- Codierung jedes Buchstabens/Zeichens durch Bitfolge

- **ASCII:** *American Standart for Information Interchange*
	- 7 Bit (max. 128 Zeichen), Tabelle mit Nummerierung aller Zeichen
	- z.B. "a" = Nr.97, "A" = Nr. 65, ...
	- Klein-/Großbuchstaben alphabetisch durchnummeriert
	- übliche Erweiterung auf PC: 8bit → weitere Sonderzeichen, z.B. Umlaute
	- Erweiterung in Europa: Latin-1 (nach Norm ISO 8859-1)
```
 _____      _ _    __________  
| ____|_ __(_) | _|___ /___  |
|  _| | '__| | |/ / |_ \  / /
| |___| |  | |   < ___) |/ /
|_____|_|  |_|_|\_\____//_/
```
![[Pasted image 20251021111539.png]] *ASCII-Tabelle (7 Bit)* 

**ISO 8859-1 (8 Bit)**
- International Organization for Standardization (gegründet 1947)
- ISO Latin 1
    - 8 Bit Code
    - Enthält viele Sonderzeichen für westeuropäische Sprachen  
        (z.B. Umlaute “ä, ö, ü”)
    - Enthält nicht alle gewünschten Zeichen  
        (z.B. fehlen japanische und asiatische Schriftzeichen und mehr)
![[Pasted image 20251021111626.png]]
*ISO 8859-1 (8 Bit)*

- **Unicode:** z.B. von Java verwendet
	- Aktueller Standart: Unicode 17.0 (Stand: 09.09.2025)
	- 16 Bit (max. 65536 Zeichen)
	- Verwaltet vom Unicode-Konsortium: http://www.unicode.org
	- als Obermenge weltweit geläufiger Zeichen
	- Unterstützt verschiedenen Codierungsformate (Unicode Translation Format) → längere Formate erweitern kützere Formate:
		- UTF-8
		- UTF-16
		- UTF-32
	- Vereinbart auche weitere Informationen
		- Schreibrichtung
		- Kombination von Zahlen
		- ...
![[Pasted image 20251021120003.png]]
*Unicode*
___
# [[Repräsentation ganzer Zahlen]]

### Wunsch
Ganze Zahlen $z \in \mathbb{Z}$ repräsentieren zu können

### Vereinbarung
Feste Repräsentationslänge $\mathscr{l}$

### Wie viele verschiedene Zahlen kann man so höchstens repräsentieren?
- $\mathscr{l}$ Positionen, jeweils zwei Möglichkeiten pro Position
	⤷ $2^{\mathscr{l}}$ verschiedene Bitmuster der Länge $\mathscr{l}$

### Fragen
- Wie kann man **Zahlenbereiche** verwenden?
- Wie könne nwir **positive & negativ**e Zahlen unterscheiden?
	- Vorzeichenbetragsdarstellung
	- Exzessdarstellung
	- Einerkomplement
	- Zweierkomplement 

### Vorzeichenbetragsmethode/-darstellung
- erstes Bit vorziehen
- Restliche Bits als Betragszahl in Binär
- Vorzeichenbits $s = 1 \Leftrightarrow$ Vorzeichen negativ, da $Zahl = (-1)^s * Betragszahl$ gilt
	⤷ Es gilt:
	- Kleinste darstellbare Zahl: $-(2^{\mathscr{l}-1}-1)$
	- Größte darstellbare Zahl: $2^{\mathscr{l}-1}-1$
		⤷ **Eigenschaften**
		- + Symmetrie
		- + Einfacher Vorzeichenwechsel
		- - Null nicht eindeutig codiert → Ein Binärcode verschwedndet
		- - Vergleich von Zahlen schwierig

| Zahl | In Binär | Dezimal |
| :--- | :------: | ------: |
| -3   |   0101   |       5 |
| -2   |   0110   |       6 |
| -1   |   0111   |       7 |
| 0    |   1000   |       8 |
| 1    |   1001   |       9 |
| 2    |   1010   |      10 |
| 3    |   1011   |      11 |

### Exzessdarstellung (Darstellung mit Bias)
- Feste **Verschiebung b (Bias)**
- z wird als z + b als Binärzahl dargestellt
- Übliche Werte für Bias $b=2^{\mathscr{l}-1}$ oder $b=2^{\mathscr{l}-1}-1$
- Beispiel $\mathscr{l} = 5 \rightarrow b = 16$ oder $b=15$
	⤷ Es gilt: 
	-  Kleinste darstellbare Zahl: $-b$
	- Größte darstellbare Zahl: $2^{\mathscr{l}}-1-b$
		⤷ **Eigenschaften**
		- + 0 eindeutig & alle Codes ausgenutzt
		- + Vergleich von Zahlen einfach
		- + Bei üblichem Bias erstes Bit vorzeichenbitanalog
		- − Nicht symmetrisch
		- − Vorzeichenwechsel schwierig

| Zahl | In Binär | Dezimal |
| :--- | :------: | ------: |
| -3   |   0101   |       5 |
| -2   |   0110   |       6 |
| -1   |   0111   |       7 |
| 0    |   1000   |       8 |
| 1    |   1001   |       9 |
| 2    |   1010   |      10 |
| 3    |   1011   |      11 |

### Einerkomplementdarstelliung
- Nicht-negative Zahlen: **Binärdarstellung**
- Negative Zahlen: **Komplement** der Binärdarstellung (1→0, 0→1)
	⤷ Es gilt:
	- Kleinste darstellbare Zahl: $-(2^{\mathscr{l}-1}-1)$
	- Größte darstellbare Zahl: $2^{\mathscr{l}-1}-1$
		⤷ **Eigenschaften**
		- + Symmetrisch
		- + Erstes Bit wie Vorzeichenbit
		- - 0 ist nicht eindeutig
		- - Verschwendung eines Codes
		- - Vergleich von Zahlen schwierig

### Zweierkomplementdarstellung ⇨ Standard
- Nicht-negative Zahlen: **Binärdarstellung**
- Negative Zahlen: **Komplement der Binärdarstellung + 1**
	⤷ Es gilt:
	- Kleinste darstellbare Zahl: $-(2^{\mathscr{l}-1})$
	- Größte darstellbare Zahl: $2^{\mathscr{l}-1}-1$
		⤷ **Eigenschaften**
		- + 0 eindeutig repräsentiert & alle Codes ausgenutzt
		- + Erstes Bit wie Vorzeichenbit
		- - Vergleich von Zahlen schwierig (nicht so leicht wie In Exzess)
**⇨Standard**

| Zahl | In Binär | Dezimal |
| :--- | :------: | ------: |
| -3   |   1101   |      13 |
| -2   |   1110   |      14 |
| -1   |   1111   |      15 |
| 0    |   0000   |       0 |
| 1    |   0001   |       1 |
| 2    |   0010   |       2 |
| 3    |   0011   |       3 |
- Umrechnung: Betragszahl berechnen +1
- Achtung: Positive Zahlen werden nicht +1 gerechnet sondern die Binärstellen werden einfach in eine Dezimalzahl umgewandelt
- 4-Bit-Format: Bei 5-Stelligen Binärzahlen wird die 1. Stelle ignoriert (Beim Rechnen um positiven und im negativen Raum) → Overflow/Überlauf
## Theorem
**Geschlossene Form zur Berechnung des Zweierkomplements:**
Ein Bitvektor $a=(a_{\ell-1}, a_{\ell-2}, \ldots a_0)$ repräsentiert bei einer Kodierung im Zweierkomplement die Zahl $$int(a)=-a_{\ell-1}*2^{\ell-1}+\sum_{i=0}^{\ell-2} a_i*2^i$$
**Beispiel** $int(1101_2) = -1*2^3+(1*2^2+0*2^1+1*2^0) = -8_{10} + 5_{10} = -3_{10}$
→ Keine Fallunterscheidung bei Addition und Subtraktion

![[Pasted image 20251016112804.png]]
![[Pasted image 20251016113705.png]]![[Pasted image 20251016113726.png]]Überflussbit ignorieren

### Alles verstanden?
Wir haben:
- $\mathscr{l} = 5$
- Bias $b=2^{\mathscr{l}-1} = 2^4 = 16$

Welche Zahl wird \(z=10010\) nun repräsentiert?

**Vorzeichenbetragsdarstellung**

|\(1\)|\(0010_2\)|
|---|---|
|Vorzeichenbit|Binärdarstellung|
|\(-1^1\)|\(0*2^3 + 0 * 2^3 + 1*2^1+0*2^0 = 2\)|

**\(\rightarrow 10010_2=-1*2=-2

Z.B. Int = 32 Bit nach 2er Komplement