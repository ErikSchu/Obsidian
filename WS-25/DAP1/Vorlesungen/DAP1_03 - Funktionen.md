#dap1

Dienstag, 21.10.2025

#### Ein-/Ausgabe von Text, Zahlen (ctd.)
Siehe [[DAP1_02 - Einführung (CDT); erste Algorithmen]] (§ Ein-/Ausgabe von Text, Zahlen)

### Regeln für Variablennamen in C(++)

- Beliebig lange Zeichenketten aus folgenden Zeichen:
	- Groß-/Kleinbuchstaben
	- Ziffern
	- Unterstrich _
	- **keine** Leerzeichen, Umlaute, Sonderzeichen, ...
	- Variablennamen in `snake_case` (zunächst) oder CamelCase (später für **selbstdefinierende Typen**)

- dürfen **nicht mit einer Ziffer** beginnen
- keine **Schlüsselwörter** verwenden, z.B. int
- andere "bereits belegte" Namen ungünstig, z.B. main, printf (lesteres insbesondere aus der [C-Standart-IO-Library](https://en.cppreference.com/w/cpp/io/c.html)

- **Konvention:** Variablen mögl. aussagekräftig nemennen
	- englische/deutsche Wörter, die die **Semantik** der Variable verdeutlichen
	- Ausnahme: "standartisierte Semantiken" wie z.B. `i` als Zähler bei Wiederholungsanweisungen

- pro Block darf der gleiche Variablenname nur einmal in einer Deklaration verwendet werden

### Variablensichtbarkeit in C(++)

- Sichtbarkeitsbereich (**Scope**)
	- Deklarierte Variablen sind ab diesem Zeitpunkt **sichtbar** (d.h. können verwendet werden)
		- bis zum Ende des Blocks
		- demnach auch in evtl. folgenden **untergeordneten** Blöcken
		- d.h. zusätzlich sind alle Variablen in **untergeordneten Blöcken** sichtbar

- wenn Variablenname nicht eindeutif auflösbar
	- (möglich bei gleichem Variablenname in verschachtelten Blöcken)
		⤷ dann Zugriff immer **so lokal wie möglich**
	- eher **vermeiden**

### Beispiel $x^2$ 
``` C++
#include <cstdio> 

int square(int x) { // computes x^2 
	int xsquare = x*x; 
	return xsquare; 
}

int main() { 
	printf("42 zum Quadrat ist %i\n", square(42)); 
}
```
- `int square ...` (Z. 3): **Rückgabetyp** (`int`) und Name (`square`) der Funktion

- `... (int x)` (Z. 3): **Parametertyp** `int`) und **Parametername** der Funktion
    - mehrere Parameter mit Kommata trennen (z.B. `int pow(int n, int x)`)

- Block Zeile 4–6: Anweisungen zum Ausführen der Funktion (**Funktionskörper**)

- `return xsquare` (Z. 5) beendet Funktion und gibt `xsquare` als **Funktionsergebnis** zurück

- `// Kommentar` (Z. 3): menschenlesbarer **Kommentar**, wird vom Compiler ignoriert

## Warum Funktionen?

- Strukturierung von Codde in **logische und in sich geschlossene Teile**
	⤷ längere Programme werden so lesbarer

- Wiederherstellbarkeit von Code
	- Funktionen können beliebig oft aufgerufen werden, mit unterschiedlichen Paramern
	- sinnvoll, wenn Funktionskörper länger als Code

- Unterscheidung des **WIE** und **WAS**
	- gut geschriebene und dokumentierte Funktion erlaubt Trennung von **Funktionalität** (Was tut die Funktion?) und **Implementierung** (Wie tut die Funktion das?)
	- **Code-Faltung** in VS Code
	- **Kapselung** (auch aus der Objektorientierung bekannt)



### Beispiel einer Funktion
``` C++ 
int main() {
	char nase = 0;
	print_gesicht(nase);
} 

void print_gesicht(char nase) { 
	printf("o o\n"); // Augen 
	printf(" %c \n", nase); // Nase
	printf("---\n"); // Mund
}
```
```
    o o      o o      o o      o o      o o   
     |        *        .        ^        J
    ---      ---      ---      ---      ---
```
Main Funktion immer von Typ int → `Code 0`

## Erste Coding-Standarts

- **Zeilenumbrüche** sinnvoll verwenden
    - i.A. eine Anweisung pro Zeile; maximal 80 Zeichen pro Zeile

- **Einrückungen** sinnvoll (mit tabulator oder Leerzeichen):
    - Anweisungen in Blöcken eine Stufe einrücken
    - bei Verwendung von geeigneten Editoren/Programmierumgebungen meist automatisch

- Variablen und Funktionen **aussagekräftig benennen** (zunächst im snake_case)

- **Leerzeilen** zwischen funktional abgeschlossenen Einheiten
    - z.B. zwischen 2 Funktionen
    - aber auch innerhalb von (etwas längeren) Funktionen

- **Kommentare** verwenden (mindestens bei Funktionen beschreiben, was diese tun; aber auch **Teilziele** benennen und einzelne Anweisungen kommentieren)