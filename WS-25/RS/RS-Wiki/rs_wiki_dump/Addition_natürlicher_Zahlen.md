#rs
#### Addition von Binärzahlen  - Schulalgorithmus

![[Pasted image 20251210114846.png]]
⤷ `1+1` erzeugt Übertrag
⤷ `0+0` eliminiert Übertrag
⤷`1+0`/`0+1` reichen vorhandenen Übertrag weiter
⤷ max. Übertrag: 1

##### Als boolesche Funktion
- **Summenbit**s und **Übertrag** *c* (engl. "carry")
- $f_{HA}:B^2 \to B^2$ realisiert die Forderungen z.T.
	⤷ realisiert einen...

## Halbaddierer
- Berechnet **Übertrag** *c* aus der Addition
- Berücksichtigt keinen **Übertrag**, der schon vorher entstanden ist
	 ⤷ *Größe:* 2 || *Tiefe:* 1

![[Pasted image 20251210115555.png]]
![[Pasted image 20251210115505.png]]

## Volladdierer
$f_{VA}: B^3 \to B^2$
- Berechnet auch **Übertrag** *c* aus der Addition
- Berücksichtigt **Übertrag** *c_alt*, der schon vorher entstanden ist

⇒ **Beobachtung für *s***
- $s = 1 \Leftrightarrow$ Anzahl ungerade 1en
- $s = x_{alt} \oplus x \oplus y$

⇒ **Beobachtung für *c***
- $c = 1 \Leftrightarrow$ Anzahl 1en $\ge 2$
- *DNF:* $c = \overline{c_{alt}}xy \lor c_{alt} \overline{x}y \lor c_{alt}x \overline y \lor c_{alt}xy$
- *Resolution:* $\overline {c_{alt}}xy \lor c_{alt}xy = xy; \ c_{alt} \overline x y \lor c_{alt}xy = c_{alt} y; \ c_{alt}x \overline y \lor c_{alt}xy = c_{alt}x$
	⇒ $c = xy \lor c_{alt}y \lor c_{alt}x$

| $c_{alt}$ | $x$ | $y$ | $c$ | $s$ |
| --------- | --- | --- | --- | --- |
| 0         | 0   | 0   | 0   | 0   |
| 0         | 0   | 1   | 0   | 1   |
| 0         | 1   | 0   | 0   | 1   |
| 0         | 1   | 1   | 1   | 0   |
| 1         | 0   | 0   | 0   | 1   |
| 1         | 0   | 1   | 1   | 0   |
| 1         | 1   | 0   | 1   | 0   |
| 1         | 1   | 1   | 1   | 1   |
- Verbessert die Realisierung für den Übertrag $c$ durch Wiederverwenden von Teilergebnissen 

#### Schaltnetz Volladdierer

- $s = c_{alt} \oplus x \oplus y$
- $c = c_{alt}(x \oplus y) \lor xy$
- Größe 5 || Tiefe 3
 ![[Pasted image 20251210122543.png]]

Hintereinandergeschaltet mit einem *Halbaddierer*...

## Ripple-Carry Addierer

- **Größe:** $5n-3$ ⇒ *sehr klein*
- **Tiefe:** $3n - 2$ ⇒ *viel zu tief*

![[Pasted image 20251210123008.png]]

- Verbesserungsidee: Überträge früh berechnen

---
## Carry Look-Ahead Addierer

**Notatiom**
- $f_{HA}: B^2 \to B^3, f_{HA}(x_{i}, y_{i})= (u_{i}, v_{i)}$
	- $u_{i}$ = 1 *generierter* Übertag; $v_{i} = 1$ *reicht* Übertrag *weiter*
-  **Vorausberechnung der Überträge** $c_{i} = u_{i-1} \lor c_{i-1}v_{i-1}$
$$
c_{i} = \bigwedge^{i-1}_{j=0}(u_{j} \land \bigwedge^{i-1}_{k=j+1}v_{k})
$$
⇒ **Gesamttiefe** 4
	- Halbaddierer
	- Undgatter
	- Odergatter
	- Gatter für korr. Summenbits

![[Pasted image 20251210124023.png]]
![[Pasted image 20251210124043.png]]

⤷ Es lassen sich beliebig lange Zahlen in Tiefe 4 addieren.
	⤷ Aber *sehr großer Fan-In* → technisch schwer realisierbar

#### Vermeidung großer Fan-In
→ Verallgemeinerung
	⤷ **Größe:** Bei jeder Stufe halb so viele Gatter wie in der Stufe davor
		$\frac{n}{2}+\frac{n}{4}+\frac{n}{8}+\dots+1 \approx n$
	⤷**Tiefe:** So oft halbieren, bis man bei einem Gatter ist
		$\approx \log_{2}(n)$ 
![[Pasted image 20251210125633.png]]
⤷Baumartiges Schaltnezu ersetzt Gatter mit großem Fan-In

#### Bezug auf CLA
- Fokus auf AND-Gatter: $$\sum^n_{i=1} \sum^i_{j=1}(j-1)$$
- **Größe** $\approx \frac{n^3}{6}$ ⇒ *ziemlich groß*
- **Tiefe** $\approx 2\log_{2}(n)$ ⇒ *ziemlich flach*

### Vergleich RCA - CLA
|**n**|Ripple-Carry Größe|Ripple-Carry Tiefe|Carry Look-Ahead Größe|Carry Look-Ahead Tiefe|
|---|---|---|---|---|
|8|37|22|170|6|
|16|77|46|1365|8|
|32|157|94|10922|10|
|64|317|190|87381|12|
![[Pasted image 20260106161608.png]]

