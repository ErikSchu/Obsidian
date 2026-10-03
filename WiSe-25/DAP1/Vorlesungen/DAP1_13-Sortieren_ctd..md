#dap1

## Verglech Selection Sort und Mergesort

|                                      | **Selection Sort**                   | **Mergesort**                        |
| ------------------------------------ | ------------------------------------ | ------------------------------------ |
| # Operationen                        | ca. $n^2$                            | ca. $n \cdot \log n$                 |
| in place                             | ja                                   | nein                                 |
| ![[Pasted image 20251202123343.png]] | ![[Pasted image 20251202123401.png]] | ![[Pasted image 20251202123418.png]] |

> [!def.] Wissensstand
> - die jetztigen Kenntnisse von C/C++ reichen, um alles zu programmieren
>- es gibt eine Reihe weiterer Konzepte/[Schlüsselwörter](https://en.cppreference.com/w/cpp/keywords.html) mit unterschiedlichen Zielen:
    >	- Code kürzer/lesbarer machen (z.B. `switch`, `enum`, `? : ;`, `break`, `continue`)
    >	- das Programmieren vereinfachen (z.B. `auto`)
    >	- Code sicherer machen (z.B. `reinterpret_cast`, `const_cast`)
	> 	- Ausführungszeit optimieren (z.B. `register`, `inline`, Bit-Operationen `& | <<` etc.)
    >	- Platzeffizienz erhöhen (z.B. [Datentypen fixer Länge](https://en.cppreference.com/w/cpp/types/integer.html) wie `uint16_t`)
    >	- Entwicklung großer Projekte vereinfachen, z.B. mit Mitteln der **Objektorientierung** (`class`, …)
>- als dies kann man (böswillig) als “syntaktischen Zucker” auffassen
    >	- wir werden einigen davon bei Bedarf kennenlernen
>- im weiteren Verlauf der Vorlesung Fokus auf **Datenstrukturen**

---
---

# Teil 3 - Lineare Dynamische Datenstrukturen; Einstieg in die Objektorientierung


## Abstrakter Datentyp (ADT) [[Arrays]]

- Es ist oft sinnvoll, Datenstrukturen über ihre nach außen hin sichtbare **Funktionalität** zu beschreiben.

- z.B. Array mit N einträgen vom Typ T (T = int, double, ...):
	- `alloc(array_name, n, T)`: allokiere n **zusallemhängende** Speicherzellen vom Typ T
		- *in C++:* `array_name[n];` (keine Intitialisierung, sondern zufälllige Werte!)
	- `read(array_name, i);`: gib den i-ten Wert (vom Typ T) zurück
		- *in C++:* `array_name[i]` in Ausdrücken (keine Bereichsüberprüfung!)
	- `write(array_name, i, expr)` überschreibe den i-ten Wert mit dem Ergebnis des Ausdrucks expr (Typ T)
		- *in C++:* `array_name[i] = ... ` (als Ziel von Zuweisungen

- oft zusätzlich mit Laufzeitgarantien, z.B. "alle Operationen laufen mit **"konstant vielen  elementaren Operationen"**


## Klassen 

- Zur Beschreibung neuer Datentypen eignen ich **Klassen** (`class Klassenname`)
	- Bündelung von Daten (*Membervariablen*) und Funktionen (*Memberfunktioenen* oder *methoden*), die diese Daten bearbeiten
	
	- Konstruktion über eine spezielle Funktion **Konstruktor**, die den Namen der Klasse trägt und keinen Rückgabewert hat: `Klassenname(parameterliste) { ... }`
		- dieser wird bei der Erstellung eines **Objekts** dieer Klasse (=dieses Datentyps) einmalig aufgerufen
		- Erstellung von Objekten über Klassenname `object(param1, param2, ...)` - Vergleiche *int x*
	
	- Analog: **Destruktor** (`~Klassenname()`)
		- beim Löschendes Objektes aufgerufen (auch, wenn Objekt aus *Sichtbarkeit* fällt)
	
	- kontrollierter Zugriff auf die Daten über **public**-Funktionen (auch für Var. mögl.)
	
	- geschützte Daten/Funktionen über **private**
	
	- **Coding-Konvention:** für Klassennamen *CamelCase*, Membranvariablen mit "\_" beenden