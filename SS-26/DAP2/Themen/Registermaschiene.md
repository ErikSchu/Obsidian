#dap2

## Aufbau
- Register $(r_{i})_{i \ge 0}$; jedes speichert eine **ganze Zahl**, *initialisiert auf Null*
- $r_{0}$ ist der **Akkumulator**
- ferner werden in Register $r_{0}$ *Ein- und Ausgabe* placiert
- **Programmzähler** $z$
- Programm aus Zeilen, die jeweils einen Befehl enthalten

>[!note] Befehle
>![[Pasted image 20260524000629.png]]

#### Eingabecodierung
- Eingabe wird als **Zahl** codiert
- mit geeigneter Codierung können beliebige Zeichenkennten eingegeben werden
- diese können wiederum kombinatorische Strukturen beschreiben

#### Laufzeit
- **Laufzeit** $T_{M}(e)$ einer Registermaschiene $M$ auf eine Eingabe $e \in \mathbb{Z}$ ist die *Zahl der ausgeführten Befehle*
- also $T_{M}(e) \in \mathbb{N} \cup \{ \infty \}$
- **Eingabelänge** einer Zahl $e \in \mathbb{Z}$ ist $\lceil \log_{2} (2  + \lvert e \rvert) \rceil$
- Anzahl Bits, um $e$ zu schreiben

### Effiziente Algorithmen
- $\tau_{M}(n)$ ist die *maximale Laufzeit* vom $M$ auf einer Eingabe der Länge $\le n$: $$\tau_{M}(n) = \text{max} \{ \tau_{m} (e) : \log_{2}(2 + \lvert e \rvert ) \le n \}$$
- Der **Algorithmus** $M$ ist *effizient*, wenn es eine Zahl $l > 0$ gibt, sodass $$\tau_{M}(n) = O(n^l)$$

>[!tip] Die Klasse $P$
>- $f : \mathbb{Z} \to \mathbb{Z}$ heißt ***effizient berechenbar***, wenn es einen effizienten Algorithmus gibt, der für alle $e \in \mathbb{Z}$ bei Eingabe $e$ den wert $f(e)$ ausgibt
>- $P$ ist die Menge aller effizient berechenbaren Funktionen $f: \mathbb{Z} \to \{ 0, 1 \}$

