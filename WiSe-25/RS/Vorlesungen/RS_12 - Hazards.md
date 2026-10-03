#rs
## Hazards
sind Abweichungen zwischen Modell und Realität // ärgerlich, aber unvermeidlich // auch für technisch Realisierte Schaltnetze gültig

**Zentrale Frage:** Was passiert, wenn die Eingabe wechselt? → Die Ausgabe kann wechseln.

**Wunsch:**
- Wenn $f$ die Ausgabe wechselt, wechselt das Schaltnetz *genau einmal* die Ausgabe
- Wenn $f$ die Ausgabe *nicht* wechselt, wechselt das Schaltnetz seine Ausgabe *nicht*
	⤷ Schaltnetz kann keine Ausgabe "zwischendurch" wechseln → **Hazard**

#### BEGRIFFE
- **statisch**
	⤷ Ausgabewert soll gleich bleiben, ändert sich aber.
- **dynamisch**
	⤷ Ausgabewert soll sich änder, ändert sich aber mehrfach
- **Funktionshazard**
	⤷ schon in der Fuktionsdefinition enthalten
- **Schaltungshazard**
	⤷ Hazard, der kein Funktionshazard ist, sondern durchdie Wahl der Schaltung entsteht


### Statisch || Dynamisch

> [!TIP] Definition **Statischer Funktionshazard**
> $f : \{ 0, 1 \}^n \rightarrow \{ 0, 1 \}$ hat **statischen Funktionshazard**, wenn es $a = a_{1} a_{2} \dots a_{n} \in \{ 0, 1 \}^n$ und $b = b_{1} b_{2} \dots b_{n}$ mit $a \ne b$ und $f(a) = f(b)$ gibt, sowie $c = c_{1} c_{2} --- c_{n} \in \{ 0, 1 \}^n$ mit $c_{i} \in \{ a_{i}, b_{i} \}$ für alle $i \in \{ 1, 2, \dots, n \}$ und $f(c) \ne f(a)$.
>
>---
> ![[Pasted image 20251127104459.png]]

> [!TIP] Definition **Dynamischer Funktionshazard**
> $f: \{ 0, 1 \}^n \rightarrow \{ 0, 1 \}$ hat **dynamischen Funktionshazard**, wenn es $a, b \in \{ 0, 1 \}^n$ mit $a \ne b$ und $f(a) \ne f(b)$ gibt, sowie $c = c_{1} c_{2} \dots c_{n} \in \{ 0, 1 \}^n$
 und $c' = c'_{1} c'_{2} \dots c'_{n} \in \{ 0, 1 \}^n$ mit $c_{i} \in \{ a_{i}, b_{i} \}, c'_{i} \in \{ c_{i}, b_{i} \}$ für alle $i \in \{ 1, 2, \dots, n \}$ und $f(c) \ne f(a) \ \land \ f(c) \ne f(c')$.
 >
 > ---
 > ![[Pasted image 20251127105256.png]]
 
 Wie haben ein korrektes Schaltnestz $S$ für $f$.
 Wir betrachten Eingabewechsel von $a$ auf $b$.
 
**1. Funktionswert bleibt gleich: $f(a) = f(b)$**
	⤷ Am Ausgang von $S$ liegt **kurzzeitig** ein *anderer Wert* an.
		⤷ *statischer Hazard*

**2. Funktionswert ändert sich: $f(a) \ne f(b)$**
	⤷ Am Ausgang von $S$ ändert sich der Wert *mehrfach*.
		⤷ *dynamiscer Hazard*


### Funktionsh. || Schaltungsh.

**Wie kommt es zum Funktionshazard?** Eingabewechsel von $a$ nach $b$ mit 
	*entweder $f(a) = f(b)$ statisch*
	*oder $f(a) \ne f(b)$ dynamisch*.

Es gibt :
	- **Statisch:** 1 andere eingabe c
	- **Dynamisch:** 2 andere Eingaben c, c'
zwischen a und b, so dass der Funktionswert beim Weg von a nach b
- **statisch** über c wechselt
- **dynamisch** über c und c' mehrfach wechselt

*ZENTRAL* andere Eingaben echt **"dazwischen"**
	im Bezug auf Eingabewechsel
		- Wertänderung einiger Eingabebits (alle Bits mit $a_{i} \ne b_{i}$)
		- nicht völlig gleichzeitig
		- *also* "dazwischen" = kann als Zwischenschritt bei Wertänderung der Eingagebits vorkommen
	beim Blich auf  KV-Diagramm
		- auf einem kürzesten Weg von a nach b

![[Pasted image 20251127110755.png]]
⤷ 3 Bits verschieben // Kützeste Wege haben Länge 3 // (i.a.: n untersch. Bits ⇒ kürzeste Weglänge = n)

⇒ Funktionshazards für uns weniger interessant als Schaltungshazards, da nicht vermeidbar. 

> [!TIP] Definition **Schaltunghazard**
> Funktion hat bzgl. **a, b** keinen Hazard, Schaltnetz aber schon

> [!TIP] Definition **statischer Schaltungshazard**
> Schaltnetz $S$ für $f$ hat einen **statischen Schaltungshazard**, wenn es $a, b \in \{ 0, 1 \}^n$ gibt, so dass $f$ bzgl $a, b$ keinen statischen Funktionshazard har, aber beim Eingabewechsel von $a$ nach $b$ am Ausgang von $S$ *nicht notwendig stabil* $f(a)$ anliegt. 

> [!TIP] Definition **dynamischer Schaltungshazard**
> Schaltnetz $S$ für $f$ hat einen **statischen Schaltungshazard**, wenn es $a, b \in \{ 0, 1 \}^n$ gibt, so dass $f$ bzgl $a, b$ keinen dynamischen Funktionshazard hat, aber beim Eingabewechsel von $a$ nach $b$ am Ausgang von $S$ *mehr als ein Funktionswertwechsel auftreten kann*.
> ⤷ Aufrteten nicht garantiert! 
> z.B.:
> ![[Pasted image 20251127111914.png]]

#### Vermeidung von Schaltungshazards
Wir konzentrieren uns auf *Schalrungshazards* und Schaltnetze , die *direkt Polynome realisieren*
	⤷ Schaltungshazards sing vollständig vermeidbar, jedoch nicht kostenlos:

> [!TIP] **SATZ von Eichelberger (1965)**
> Ein ZWeistufiges Schaltnetz $S$ für eine boolsche Funktion $f$ in disjunktiver Form ist frei von **statischen Schaltungshazards** ,wenn die *UND-Gatter*  in einer *1:1-Korrespondenz* zu den Primimplikanten stehen, d.h.:
> 1. Jedes UND-Gatter von $S$ realisiert einen Primimplikanten von $f$
> 2. und jedem Primimplikanten von $f$ entspricht ein UND-Gatter in $S$.


##### BEWEIS
![[Pasted image 20251127112754.png]]
![[Pasted image 20251127112825.png]]
![[Pasted image 20251127112851.png]]

#### BEISPIEL
> [!note] **Statischer Schaltungshazard**
> ![[Pasted image 20251127113110.png]]
> *Aufgestellte Regel:* Minimale Menge von PI, die alle 1en überdecken reicht. Glingt leider nut in der Theorie.
> ![[Pasted image 20251127123052.png]]

#### ZUSAMMENFASSUNG: Hazards
⤷ Die sind ärgnerlich.

**Wann liegt der richrige Funktionswert vor?**
- Funktionshazards sind son nicht vermeidbar.
- Statische Schaltungshazards können mit zusätzlichem Aufwand vermieden werden.
- Eine grundsätzliche Lösung ist Wünschenswert.
	⤷ Mögl. Lösung: *Taktung der Schaltung (Später)*
		⤷ Alternative Lösung:
			- Falls Hazards nur aufgrund von Laufzeitdifferenten der Gatter entstehen können Verlängerungen von Verbindungen diese Untercshiede Ausgleichen
			![[Pasted image 20251127123713.png]]

---
---

v06 ->