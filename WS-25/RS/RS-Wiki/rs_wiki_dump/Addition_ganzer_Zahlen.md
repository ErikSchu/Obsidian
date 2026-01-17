#rs
## Addition *positiver* [[Repräsentation ganzer Zahlen|ganzer Zahlen]] 
- Einerkomlement
- Zweierkomplement
- [[Vorzeichenbetragsdarstellung]]
	⤷ Addition einfach, da Zahlen binär dargestellt werden, evtl. Überträge beachten

##### Addition von Zahlen in [[Exzessdarstellung]]
Für Exzessdarstellung funktioniert Addierer *selbst bei positiven Zahlen **nicht***. $$x+y=(b+x)+(b+y)=(b+y+x)+b$$→ Exzessdarstellung fürs Rechnen **weitgehend ungeeignet**, nur günstig für Vergleiche.

___

## Vorzeichenwechsel

| **Repräsentation**               | **Vorgehen**                        | **Kommentar** |
| -------------------------------- | ----------------------------------- | ------------- |
| [[Vorzeichenbetragsdarstellung]] | Vorzeichen-Bit invertieren          | Sehr Einfach  |
| [[Einerkomplement]]              | Alle Bits invertieren               | Einfach       |
| [[Zweierkomplement]]             | Alle Bits invertieren, $1$ addieren | Machbar       |
⤷ grundsetzlich ist ein *Vorzeichenwechsel machbar*

___

## Addition *negativer* ganzer Zahlen

- Ripple-Carry Addierer
- Carry Look-Ahead Addierer
	- Sind *für Betragszahlen entworfen worden*.

→ Muss die Hardware für die Addition negativer, ganzer Zahlen neu entworfen werden?
- **Exzessdarstellung** beachte nwir gar nicht, weil wir damit überhaupt nicht addieren können
- **Vorzeichen-Betrag**: Positive und negative fast gleich dargestellg, darum neuer Schaltnetzentwurf erforderlich.

___

## Addition negativer Zahlen ($l$ bit) im [[Zweierkomplement]]

Notation: $\overline{Y}$ its das Komplement von $y$
⤷ **Beobachtung** $$\begin{align} & &y+\overline{Y} = 2^l-1 \\ &\Leftrightarrow &\overline{Y} = 2^l -1-y \end{align}$$
Rechnung $x-y=x+(-y)=x+\overline Y +1 = x + 2^l -1 -y +1 = 2^l + (x-y)$
⤷ **Beobachtung**
- *Darstellungslänge* → $2^l$ "passt nicht" ($\leadsto$ Überlauf)
- *Überlauf ignorieren* → **Rechnung korrekt**
	- Addierer rechnet *richtig*, auch für negative Zahlen
		⤷ wir *benörigen keine neue Hardware*, nur ein paar **Regeln**

>[!question] Quiz
>Angenommen Zahlen sind $8$ bit lang und $y$ ist eine positive Zahl. Was ist richtig, wenn wir die Zweierkomplementdarstellung benutzen?
>___
>*1. A: $y+(-y)=(00000000)_{2}$ und das Übertragsbit an Stelle neun ist $0$. $\times$*
>**2. $y+(-y) = (00000000)_{2}$ und das Übertragsbit an Selle neun ist $1$. $\checkmark$**
>**3. $y +$ eine negative Zahl ist immer gültig. $\checkmark$** 
>*3. $y +$ eine positive Zahl ist immer gültig. $\times$*

___

## Überträge beu Addition im [[Zweierkomplement]]

##### Wann ist das Ergebnis korrekt und wann nicht darstellbar?

1. **Addition zweier positiver Zahlen**
	- Ergebnis positiv
	- Kein Überlauf möglich
	- *Ergebnis korrekt, wenn es positiv ist*

2. **Addition einer positiven und einer negativen Zahl**
	- Ergebnis kleiner als größte darstellbare Zahl
	- Ergebnis größer als kleinste darstellbare Zahl
	- *Ergebnis immer korrekt*

3. **Addition zweier negativer Zahlen**
	- Überlauf entsteht ($\leadsto$ ignorieren)
	- Ergebnis muss negativ sein
	- *Ergebnis korrekt, wenn es negativ ist*