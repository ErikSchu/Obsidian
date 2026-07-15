---
kurs: Datenstrukturen, Algorithmen & Programmierung 2
dozent: Prof. Amin Coja-Oghlan
themengebiet: /
datum: 14.07.2026
tags:
  - "#dap2"
---
- ein ***binärer Suchbaum*** ist eine Datenstruktur zur Speicherung von *Objekten*, die *durch einen Schlüssel gekennzeichnet* sind
- die Schlüssel sind total geordnet
- es seien alle Schlüssel verschieden
- **Operationen:** `Insert`, `Delete`, `Search`, `Minimum`, `Maximum`, `Predecessor`, `Successor`
- Laufzeit jeder Operation ist $O(\text{Baumhöhe})$

#### Binärbäume

- ein **Binärbaum** ist ein gewurzelter Baum, d.h. ein Baum $T$ mit einer ausgezeichneten Wurzel $r \in V(T)$
- Wurzel hat den Grad $d_{T}(r) \le 2$
- jeder andere Knoten $v \in V(T) \setminus \{ r \}$ hat Grad $\le 3$
- die **Kinder** eines Knotens $v$ sind die Nachbarn $w \in \partial v$, die nicht auf dem Kürzesten Pfad von $v$ nach $r$ liegen; jeder Knoten hat also max. 2 Kinder 
- der **Elternknoten** von $v$ ist der Nachbar auf dem kürzesten Pfad zu $r$, bzw. $\emptyset$, dalls $v = r$

#### Suchbäume

- Knoten tragen vergleichbare **Schlüssel $s(v)$** 
- sei $v$ ein Knoten
	- dann hat $v$ max. 1 Kind $x$ mit $s(x) < s(v)$
	- ferner hat $v$ max 1 Kind $y$ mit $s(y) > s(v)$
	- wir nennen $x$ der *linke Kind* und $y$ der *rechte Kind* von $v$

#### Suchbaumeigenschaft

- Knoten $x$ und seine Kinder bilden den **linken Unterbaum** von $v$
- Knoten $y$ und seine Kinder bilden den **rechten Unterbaum** von $v$
- ***Suchbaumeigenschaft:*** für alle Knoten $u$ im linken Unterbaum von $v$ gilt $s(u) < s(v)$; für alle Knoten $w$ im rechten Unterbaum von $v$ gilt $s(v) < s(w)$

#### Implementation

- jeder Knoten des Suchbaums enthält den Schlüssel und ggf. einen Zeiger auf das Objekt, das dieser Knoten repräsentiert
- 