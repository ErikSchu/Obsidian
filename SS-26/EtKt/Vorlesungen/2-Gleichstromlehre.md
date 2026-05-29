e#etkt

# Zählpfeilsysteme
## Zählpfeile
**Spannungsabfall U** über einem *Wiederstand R* ("Verbraucher"):
	Positive Spannung zeigt vom **+** zum **-** Pol
	**Merke:** Elektronen Bewegen sich *entgegen* der Potentialdifferenz von - nach + (niedriges- → hohes Potential)
	Strom hat **gleiche Zählrichtung** wie die *Spannung*
		→ Elektronen bewegen sich physikalisch ==entgegen== der technischen Zählpfeilrichtung des Stroms
	![[Pasted image 20260502001157.png]]

### Quellen
... sind **Energiewandler** wie z.B. *Batterien* (chemisch → elektrisch), *Generatoren* (mechanisch → elektrisch) oder *Kondensatoren* (elektrostatisch → elektrische Strömungen)

### Verbraucher
... wandeln elektrische Energie in andere Energieformen. 
	![[Pasted image 20260502001545.png]]
>[!TIP] Ohm'sches Gesetz
>Am Wiederstand gilt: $$\boxed {U = R \cdot I}$$
>- $R$ - Wiederstand (in Ohm)
>- $U$ - elektrische Spannung (in V)
>- $I$ - Stromstärke (in A)


### Ideale Spannungsquelle
- ... liefert eine **konstante Ausgangsspannung** unabh. vom angeschlossenen Verbraucher
	⤷ die **Stromstärke** gibt sich nach dem *Ohm'schen Gesetz* $$I = \frac{U}{R}$$![[Pasted image 20260502131518.png]]

- ... liefert einen **Konstanten Strom** unabh. vom angeschlossenen Verbraucher
	⤷ die **Spannungsamplitude** ergibt sich aus dem *Ohm'schen Gesetz* $$U = R \cdot I$$![[Pasted image 20260502131803.png]]

#### Ersatzschaltbilder für ideale Quellen
![[Pasted image 20260502131951.png]]
![[Pasted image 20260502132013.png]]

***Hinweis:*** 
**Reale elektrosche Quellen** werden modelliert als **ideale** Spannungs- oder Stromquellen mit Berücksichtugung von "Störeinflüssen" (→ *Innenwiederstand* der Quelle)

>[!note] **Zählpfeilsystem** für ***Quellen***
>- Generator- (oder Erzeuger-) Zählpfeilsystem
>- Zählpfeile von Strom und Spannung an der Quelle **entgegengesetzt**
>- Energie wird *erzeugt*
>![[Pasted image 20260502133647.png]]

>[!note] **Zählpfeilsystem** für ***Verbraucher***
>- Verbraucherzählpfeilsystem (s.o.)
>- Zählpfeile von Strom und Spannung an der Quelle **gleichgerichtet**
>- Verbraucher *nimmt Energie auf*
>![[Pasted image 20260502133916.png]]

---
# Berechnung linearer Netze

- ***Schaltung*** (oder Netz / Netzwerk / Stromkreis) aus 
	- Verknüpfung von **"Zweipolen"**
	- Bauelement mit 2 Anschlussklemmen
	- idealen **Strom- / Spannungsquellen**

***⇒ Ziel:*** Bestimmung unbekannter **Spannungen** an den einzelnen Zweipolen und **Ströme** dadurch

- ***Knoten:*** elektrische Verbindungen von mehreren Zweipolen

- ***Zweige:*** Verbindungen zweier Knoten
	- mehrere Zweige zwischen 2 Knoten möglich
	- nur Verbraucher, keine Quellen

- ***Maschen:*** geschlossene Leiterschleife (d.h. geschlossener Weg über mehrere Knoten, Zweige und Quellen)

![[Pasted image 20260502134736.png]]

>[!TIP] **Knotenregel** (1. Kirchhoff'sches Gesetz)
>$$\boxed{\sum_{\text{Knoten}} I = 0}$$
>___
>![[Pasted image 20260502134906.png]]
>$\implies I_{R_{1}} - I_{R_{3}} - I_{R_{5}} = 0$
>___
>Dabei kann die **Hüllfläche** beliebig gewählt werden
>![[Pasted image 20260502135344.png]]
>$\implies I_{R_{1}} + I_{R_{4}} = I_{R_{3}} + I_{R_{4}} + I_{R_{5}}$

>[!TIP] **Maschenregel** (2. Kirchhoff'sches Gesetz)
>$$\boxed{\sum_{\text{Masche}} U = 0}$$
>___
>![[Pasted image 20260502135841.png]]
>$\implies U_{R_{1}} + U_{R_{3}} - U_{R_{4}} = 0$

> [!attention] ㅤ
>![[Pasted image 20260502140339.png]]
>![[Pasted image 20260502140642.png]]

___

# ==TODO==


___

## Strom-Spannungskenlinie

#### Reale Spannungsquelle
![[Pasted image 20260508140551.png]]


#### Reale Stromquelle 
![[Pasted image 20260508140635.png]]


___

## Umwandlung von Spannungsquellen und Stromquellen

![[Pasted image 20260508140730.png]]

Due Umwandlung von realen Stromquellen in Spannungsquellen ist möglich, wenn die **Kennliniengleichung** erfüllt ist:
	Der *Strom $I$* ist duch den Verbraucher $R$ ist in beiden Fällen *gleich*
$$\begin{align} \\
& \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ U_{0} = I_{0} R_{i}
\\
&I = \frac{U_{0}}{R_{i} + R} \ \ \text{ bzw. } \ \ I =\frac{I_{0} \cdot R_{i}}{Ri + R}
\end{align}$$
___

## Zusammenschalen von Spannungsquellen

![[Pasted image 20260508141422.png]]
***⤷ Frage:***
	Welche Randbedingungen müssen beim **Parallelschalten von Spannungsquellen** mit gleichem Innenwiederstand berücksichtigt werden?
![[Pasted image 20260508141816.png]]
![[Pasted image 20260508141913.png]]

___

## Elektrische Leistung und Energie

***Welche Leistung gibt die Quelle an den Verbraucher ab?***
Die am Wiederstand $R_{L}$ abgegebene Leistung wird vom Verbraucher in *thermische Energie* umgewandelt (Energieerhaltung)
An einem ohmschen Verbraucher $R$ berechnet sich die abgegebene **elektrische Leistung $P$** gemäß: $$\begin{align} P &= U_{R} I_{r} \\ & = RI^2_{R} \\ & = \frac{U^2_{R}}{R} \\ [P] = W \end{align}$$Die in der Zeit zwischen $t_{1}$ und $t_{2}$ umgesetzte **elektrische Energie $W_e$** wird in der Einheit "$\text{Ws}$" (oder Joule $\text J$) bemessen und berechnet sich nach: $$W_{e} = \int ^{t_{2}} _{t_{1}} \text{P} \cdot dt$$
In einem ***linearen System*** (die Beziehungen zwischen den Strömen und Spannungen sind stets proportional zueinander) ergibt sich die Gesamtwirkung mehrerer Ursachen aus der Überlagerung der Teilwirkungen, die von den Einzelursachen herrühren.

![[Pasted image 20260512091437.png]]
![[Pasted image 20260512091458.png]]
![[Pasted image 20260512091647.png]]
![[Pasted image 20260512091708.png]]

![[Pasted image 20260512091742.png]]
![[Pasted image 20260512091800.png]]
![[Pasted image 20260512091844.png]]
![[Pasted image 20260512091902.png]]
![[Pasted image 20260512091919.png]]