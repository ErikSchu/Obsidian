#rs
##### Direkt mit Binärzahlen multiplizieren
- Nullen passend schreiben
- Zahlen passend verschoben kopieren
- Viele Zahlen [[addieren|Addition_natürlicher_Zahlen]]
![[Pasted image 20260106161848.png]]


## Mpl. als [[Schaltnetz|Schaltnetze]]

- **Nullen** schreiben *einfach* & *kostenlos*
- Zahlen **verschieben** *einfach* & *kostenlos*
	- **Viele Zahlen** addieren *nicht* ganz so einfach

#### Erster Ansatz: ***serielle Addition***

⤷ Tiefe ` n-1 `
⤷ in jeder Ebene zsl. *Tiefe des Addierwerks*
	⤷ Tiefe = ` n-1 * Tiefe der Addierer `  $\leadsto$ zu tief!

![[Pasted image 20260106162442.png]]

___
#### Besserer Ansatz ***paarweise Addition***

⤷ **Anzahl Addierer** $= \frac{n}{2} + \frac{n}{4} + \frac{n}{8} + \dots + 1 \approx n$ 
⤷ **Gesamtgröße** $\approx n \cdot \text{Größe der Addierer}$
⤷ **Tiefe** $\approx \log_{2}(n)$ Ebenen
	⤷ **Gesamttiefe** $\approx lof_{2}(n) \cdot 2\log_{2}(n) = \underline{2(\log_{2}(n))^2}$

![[Pasted image 20260106163104.png]]

___
#### Noch besserer Ansatz: ***Wallace-Tree***

-  [[Addition_natürlicher_Zahlen|Carry Safe Adder]] **CSA**
- $m_{i}$ sind $n$-Bit-Zahlen
	- Sinnvoll, wenn **CSA** flacher ist aös **CLA**

![[Pasted image 20260106163644.png]]
⤷ ***Volladdierer***, der fpr $x, y, z \in \{ 0, 1 \}$ folgendes Resultat liefert $$x + y + z = a + b$$
- $s$ ist das **Summenbit**
- $2 \cdot c$ ist das **Übertragsbit**, bezogen auf seine Stelle $1$ Position weiter links
- *Parallelschaltung* von $n$ Volladdierern
	⤷ liefern jewails die *Summenbits* und die *Übertragsbits*
- *Summe* aus dem *Summen-* und dem *Carry-Wort* bildet das **Resultat**

---

>[!example] Multiplikation: ***Beispiel*** für **Carry Safe Adder**
>Wir addieren
>- $x = 001001$
>- $y = 001111$
>- $z = 001100$
>___
>![[Pasted image 20260106165124.png]]
>___
>$$
>\begin{align}
>&\text{Summen-Wort} & = (0)001010 & = 0001010 \\
>&\text{Carry-Wort} & = 001101(0) & = 0011010
\end{align}
>$$
>___
>![[Pasted image 20260106165834.png]]
>___
>⤷ $3$ **Schritte**, um $c$ und $s$ zu berechnen
>⤷ zum Einsatz kommen $n$ **Volladdierer**
>⤷ **Größe:** $5n$
>⤷**Tiefe:** $3$
>___
>***Beobachtung***
>- Der Carry (große) Look-Ahead Addierer wird *in einem Wallace-Tree* *erst als letzte Operation* benötigt
>- Der **Wallace-Tree** hat somit für die Addition von $n$ Zahöen folgende Eigenschaften
>	- *Größe:* $\approx \frac{n^3}{3}$ (proportional, bedingt durch den *CLA*)
>	- *Tiefe:* $\approx 3\log_{\frac{3}{2}}(n) + 2\log_{2}(n) \approx 7.13\log_{2}(n)$
>___
>___
>***FAZIT***
>Multiplikation nicht wesentlich teurer oder langsamer als die Addition.


___
___

>[!TIP] **Zusammenfassung** Multiplikation
>1. **Serielle Addierer**
>	Tiefe $= (n-1) \cdot \text{Tiefe(Addierer)}$
>	Tiefe $=  (n-1) \cdot 2\log_{2}(n)$ 
>	![[Pasted image 20260106173019.png]]
>___
>2. **Paarweise Addierer**
>	Tiefe $= \log_{2}(n) \cdot \text{Tiefe(Addierer)}$
>	Tiefe $= 2(\log_{2}(n))^2$
>	![[Pasted image 20260106173315.png]]
>___
>3. **Wallace-Tree mit Carry-Safe Addierern**
>	Tiefe $\approx 3\log_\frac{3}{2}(n)+2\log_{2}(n)\approx 7.13\log_{2}(n)$
>	![[Pasted image 20260106173650.png]]

# Zusammenfassung

| **Serielle Addierer** | Paarweise Addierer |     |
| --------------------- | ------------------ | --- |
|                       |                    |     |



![[Pasted image 20260107134404.png]]

