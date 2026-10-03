#rs Dienstag, 28.10.2025

# Ordered Binary Decision Diagrams
### Motivation
Eigene **Datenstruktur** für **boolsche Funktionen**
⤷ Darstellung für $f: B^n \rightarrow B^1$ 
 
**Wünsche:**
- Zu einer Belegung $x_{1}, x_{2}, \dots, x_{n}$ schnell den Funktionswert $f(x_{1}, x_{2}, \dots, x_{n})$ ausrechnen können
- Funktionen schnell auf Gleichheit testen können
- Funktionen schnell manipulieren (z.B. eine Variable konstant setzen) können
- Schnell eine Null-/Eins-Eingabe finden können
- Funktionen möglichst klein repräsentieren
- …

## Erstellung

1. Festlegung einer **Variablenordnung $\pi$** 
   z.B. $(x_{3}, x_{1}, x_{2}, x_{4})$ bei 4-stelluger Funktion
   
2. OBDD bauen aus
	- **Knoten** für Varieblen & Konstanten
	- **Kanten**, die zwei Knoten verbinden

>[!info] Regeln
> - **Knoten mit Variablen** ODER 0 oder 1 markiert
> - **Kanten** mit 0 oder 1 Markiert
> - **Variablen-Knoten** mit je einer ausgehenden 0- und 1-Kante 
> - **Kontstanten-Knoten** ohne ausgehende Kante 
> - Genau ein Knoten ohne eingehende Kanten 
> - Kante zwischen Variablenknoten beachten $\pi$


### Beispiel

$\pi = (x_{1}, x_{2}, x_{3})$

| Index | $x_1$ | $x_2$ | $x_3$ | $f_{bsp}$ |
| ----- | ----- | ----- | ----- | --------- |
| 0     | 0     | 0     | 0     | 1         |
| 1     | 0     | 0     | 1     | **0**     |
| 2     | 0     | 1     | 0     | **0**     |
| 3     | 0     | 1     | 1     | **0**     |
| 4     | 1     | 0     | 0     | 1         |
| 5     | 1     | 0     | 1     | 1         |
| 6     | 1     | 1     | 0     | 1         |
| 7     | 1     | 1     | 1     | 1         |
![[Pasted image 20251118204620.png]]

**Auswertung** $f(1,0,1) = 1$
- $x_{1}=1$
- $x_{2}=0$
- $x_{3}=1$

## OBDD-Reduzierung

>[!TIP] Satz
>**Redunktion** zu reduziertem $\pi$OBDD durch
>- **Verschmelzungsregel** Knoten mit gleicher Markierung und gleichen Nachfolgern können verschmolzen werde
>- **Eliminationsregel** Ein Koten mit gleichem Null- und Einsnachfolger kann entfernt werden

## OBDD in boolsche Funktionen umwandeln

- Diskunkive Form, d-h- Disjunktion von Termen, die nur Negation und Konjunktion enthalten

- Wir berücksichtige nnur Kanten, die zu Konstantenknoten mit 1 führen

- Folgen wir für eine Variable x einer 1-Kante, setzen wir x als Literal in den Terme 

- Literale werden mit der Konkunktion $(\land)$ verknüpft

- Jeder Pfad zu einem konstatnen Knoten mit 1 ergibt enen Termen

- Alle entstandenen Terme werden mit der Disjunktion ($\lor$) verknüpft

→ hier: $f_{bsp} = \overline{x_{1}} \ \overline{x_{2}} \ \overline{x_{3}} \ \lor x_{1}$


---

# Schaltnetze

## Logische Gatter

- Einfache **logische Bauteile**  mit Bausteinen für 
	- Negation 
	- Konjunktion
	- Disjunktion

- **Regeln**
	- Eingänge mit Variablen oder Konstanten belegt
	- Nur Verbindungen von Ausgängen zu Eingängen
	- Keine Kreise

### Symbole

![[Pasted image 20251118211103.png]]
![[Pasted image 20251118211151.png]]

>[!INFO] Beispiele
>![[Pasted image 20251118211631.png]]
>![[Pasted image 20251118211657.png]]
>![[Pasted image 20251118211737.png]]


### Schaltnetzbewertung

Kriterien:
- **Größe:** (= Anzahl der Gatter) wegen *Kosten, Stromverbrauch, Verlustleistung, Zuverlässigkeit, ...*
- **Tiefe:** (= Länge des längsten Weges von Eingang zu Ausgang) wegen *Schaltgeschwindigkeit*
- **Fan-In/-Out** (= max. Anzahl ein-/ausgehender Kanten) wegen *Realisierungsaufwand*
- ... (z.B. Anzahl Gattertypen, Testbatkeit, Verifizierbarkeit)


