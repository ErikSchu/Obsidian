#RS 

- Realisierung boolscher Funktionen in Hardware
- Technische Realisierung von *NAND* reicht aus für funktional vollständige Menge boolscher Funktionen

→ **Logische Gatter:** Bausteine für Negation, Konjunktion, Disjunktion, ...
⤷ *Eingänge* mit Variablen oder Konstanten, nur *Verbindungen* von Ausgängen zu Eingängen, *keine Kreise* (Rückkopplung)

> [!note] **Symbole für logische Gatter**
> ![[Pasted image 20251210102326.png]]
> ![[Pasted image 20251210102404.png]]

#### Beispiele

##### DNF
$f_{bsp} : B^3 \to B$, Wertevektor $(1, 0, 0, 0, 1, 1, 1, 1)$ $f_{bsp} = \overline{x_{1}} \ \overline{x_{2}} \ \overline{x_{3}} \lor x_{1} \ \overline{x_{2}} \ \overline{x_{3}} \lor x_{1} \ \overline{x_{2}} \ x_{3} \lor x_{1} \ x_{2} \ \overline{x_{3}} \lor x_{1} \ x_{2} \ x_{3}$
![[Pasted image 20251210103104.png]]

##### RNF
$f_{bsp} : B^3 \to B$, Wertevektor $(1, 0, 0, 0, 1, 1, 1, 1)$ $f_{bsp} = \overline{x_{1}} \ \overline{x_{2}} \ \overline{x_{3}} \oplus x_{1} \ \overline{x_{2}} \ \overline{x_{3}} \oplus x_{1} \ \overline{x_{2}} \ x_{3} \oplus x_{1} \ x_{2} \ \overline{x_{3}} \oplus x_{1} \ x_{2} \ x_{3}$
![[Pasted image 20251210103501.png]]

##### KNF
$f_{bsp} : B^3 \to B$, Wertevektor $(1, 0, 0, 0, 1, 1, 1, 1)$ $f_{bsp} = (\overline{x_{1}} \lor \overline{x_{2}} \lor \overline{x_{3}}) \land (x_{1} \lor \overline{x_{2}} \lor \overline{x_{3}}) \land (x_{1} \lor \overline{x_{2}} \lor x_{3}) \land (x_{1} \lor x_{2} \lor \overline{x_{3}}) \land (x_{1} \lor x_{2} \lor x_{3})$![[Pasted image 20251210104024.png]]

## Schaltnetzbewertung

-  **Schaltnetzgröße** (= Anzahl Gatter) wegen *Kosten*, *Stromverbrauch*, *Verlustleistung*, *Zuverlässigkeit*, ...

- **Schaltnetztiefe** (= Länge Länge längster Weg von Eingang zu Ausgang) wegen *Schaltgeschwindigkeit*

- **Fan-In** (= max. Anzahl eingehender Kanten) wegen *Realisierungsaufwand*

- **Fan-Out** ( = max. Anzahl ausgehender kanten) wegen *Realisierungsaufwand*

-  ... (z.B. Anzahl *Gattertypen*, *Testbarkeit*, *Verifizierbarkeit*)

⇒ Jede boolsche Funktion kann mit einem $\{ \lor \land \overline{} \}$- bzw. mit einem $\{ \oplus, \land \overline{} \}$-Schaltnetz der Tiefe 3 Realisiert werden, ABER:
	⤷ Fan-In des teifsten Gatters kann extrem Groß sein
	⤷ Größe des Schaltnetzes of inakzeptabel


## Multiplexer 
$$
MUX_{d}: B^{d+2^d} \to B \ MUX_{d}(y_{1}, y_{2}, \dots, y_{d}, x_{0}, x_{1}, \dots, x_{2^d-1}) = x_{(y_{1}, y_{2}, \dots, y_{d})_{2}}
$$
→ **Selektiert** aus vielen Eingängen einen speziellen (vgl. Drehschalter)
→ Kann **parallel** anliegende Daten in **serielle** Daten Verwandeln
→ **Mehrere Eingänge:** Signaleingänge // Sekeltionseingänge
	⤷ Immer ein Ausgang

| $y_1$ | $x_0$ | $x_1$ | $MUX_1(y_1, x_0, x_1)$ |
| ----- | ----- | ----- | ---------------------- |
| 0     | 0     | 0     | 0                      |
| 0     | 0     | 1     | 0                      |
| 0     | 1     | 0     | 1                      |
| 0     | 1     | 1     | 1                      |
| 1     | 0     | 0     | 0                      |
| 1     | 0     | 1     | 1                      |
| 1     | 1     | 0     | 0                      |
| 1     | 1     | 1     | 1                      |
⤷ Vollständige Darstellung $MUX_{1}$

| $y_1$ | $MUX_1(y_1, x_0, x_1)$ |
| ----- | ---------------------- |
| 0     | $x_0$                  |
| 1     | $x_1$                  |
⤷ Verkürzte Darstellung $MUX_{1}$

| $y_1$ | $y_2$ | $y_3$ | $MUX_3(y_1, y_2, y_3, x_0, x_1, ..., x_7$ |
| ----- | ----- | ----- | ----------------------------------------- |
| 0     | 0     | 0     | $x_0$                                     |
| 0     | 0     | 1     | $x_1$                                     |
| 0     | 1     | 0     | $x_2$                                     |
| 0     | 1     | 1     | $x_3$                                     |
| 1     | 0     | 0     | $x_4$                                     |
| 1     | 0     | 1     | $x_5$                                     |
| 1     | 1     | 0     | $x_6$                                     |
| 1     | 1     | 0     | $x_7$                                     |
⤷ Verkürzte Darstellung $MUX_{3}$

#### Vollständige (mathematische) Darstellung

- $MUX_{d}: B^{d+2^d} \to B$
- $MUX_{d}(y_{1}, y_{2}, \dots, y_{d}, x_{1}, \dots, x_{2^d-1})_{2}$

- $MUX_{3}: B^{3+2^3} \to B$
- $MUX_{3}: B^{11} \to B$ (diese Abbildung hat demnach in voööst#ndiger Darstellung $2^11 = 2048$ Zeilen)

Da die Hälfte der Indizes einschlägig ist, sind sowohl die DNF, als auch die KNF, riesig und würde zu sehr großen Schaltungen führen.


Trotzdem existiert eine überschaubarde Schaltung für $MUX_{3}$.
- $y_{i}$ und  $\overline{y_{i}}$ selektieren passende **UND-Gatter**
- Für jede Belegung der $y_{i}$ ist **genau ein** UND-Gatter ausgewählt
- **Bis auf einen** Eingang sind bei ausgewählten Gatter **alle Eingänge auf 1** gesetzt
- Eigenschaft des **Neutral-Elements** 1 für UND leitet sel. $x_{j}$ durch

![[Pasted image 20251210114347.png]]