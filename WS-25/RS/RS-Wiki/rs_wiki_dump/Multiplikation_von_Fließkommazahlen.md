#rs 

## Darstellung gemäß IEEE-754-1385
- ` s ` Vorzeichenbit
- ` m ` Mantisse (Binärdarstellung, inkl. impl. 1)
- ` e ` Exponent (Exzessdarstellung, $b=2^{l-1} -1$)
$$\begin{align}
&x=(-1)^{s_{x}} \cdot m_{x} \cdot 2^{e_{x}} \\
&y=(-1)^{s_{y}} \cdot m_{y} \cdot 2^{e_{y}} \end{align}$$
***Ergebnis*** $z = (-1)^{z_{z}} \cdot m_{z} \cdot 2^{e_{z}}$
***Vereinfachung***  Wir ignorieren das Runden.

>[!question] Es gilt 
$s_{z} = s_{x} \oplus s_{y}$

**Beobachtung:** $z = (-1)^{s_{x} \oplus s_{y}} \cdot (m_{x} \cdot m_{y}) \cdot 2^{e_{x} + e_{y}}$
**Vorgehen:**
1. $s_{z} := s_{x} \oplus s_{y}$
2. $m_{z} := m_{x} \cdot m_{y}$
	- Multiplikation von Betragszahlen wie gesehen
	- *Impliizte Einsen nicht vergessen!*
3. $e_{z} := e_{x} + e_{y}$
	- Addition, wegen Exzessdarstellung berechnen
	- $E_{x} := e_{x} + b$ (Binärrepräsentation von $e_{x}$ ist $E_{x}$)
	- $E_{y} := e_{y} + b$ (Binärrepresentation von $e_{y}$ ist $E_{y}$)

>[!question] Es gilt
>In welchem Bereich liegt $m_{z} = m_{x} \cdot m_{y}$?
>⤷ $1 \le m_{z} < 4$

>[!example] Beispiel Multiplikation von Fließkommazahlen
>$x \ \ \ 1 \ \ 1000 \ 0101 \ \ 101 \ 0000 \ 0000 \ 0000 \ 0000$
>$y \ \ \ 1 \ \ 1000 \ 0111 \ \ 110 \ 1000 \ 0000 \ 0000 \ 0000$
>**Vorzeichen:** $s_{z} = 1 \oplus 1 = 0$
>**Exponent**