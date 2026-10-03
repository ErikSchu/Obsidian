#dap1
#### [[Algorithmus]]
## Was ist eine Datenstruktur?
- Form der Speicherung bzw. Organisation von Daten in einem Computer, so dass bestimmte Aufgaben (Algorithmen) schnell und/oder platzeffizient ausgeführt werden können.
	- Datenstrukturdesign geht Hand in Hand mit Algorithmendesign
	- Untersch. Algorithmen verlangen unterschiedliche Datenstrukturen
	- Oft eine Abwägung (**Tradeoff**) zw. **Platz** und **Zugriffszeit**
	- einfache Algorithmen brauchen keine Datenstruktur (→später)

## Was ist ein Programm?
- Nichts anderes als das Ausdrücken eines Algorithmus / die Definition einer Datenstruktur in einer Programmiersprache
- Zunächst nichts weiter als eine Textdatei (Der **Programmtext**)
	- in einer speziellen **Syntax**
	- **Compiler** übersetzt (aka kompiliert) dies in ein vom Computer ausführbares Programm
![[Pasted image 20251016143630.png]]![[Pasted image 20251016143655.png]]

___
# Vereinfachtes word-RAM-Modell
**(Random Access Machine)**
Vorstellung einer Computers (in dieser Vorstellung):
![[Pasted image 20251016143849.png]]
- Speicher bestehend aus $2^w$ vielen **Speicherzellen (Computerwörtern)** mit je $w$ Bits (z.B.: $w=32$)
	⤷ Inhalt unterschiedlich interpretierbar, z.B. als Ganzzahl zwischen $0$ und $2^w -1$
-  Prozessor (CPU) arbeitet das Programm prinzipiell Schritt für Schritt ab
- jede Programmanweisung (**Befehl**) kann eine Speicherzelle verändern
- Achtung: dieses Modell **ignoriert** (u.a.) die eigentlich byteweise Organisation des Arbeitsspeichers (auch Register werden ignoriert)

### Operationen im Word-RAM-Modell
- Speicherzellenwerte **lesen & schreiben**

- Elementare **Berechnungen** auf Speicherzellen:
	- Addition/Subtraktion, Multiplikation/Division/Modulo (+, -, /, %)
	- **Vergleichsoperationen** <, ≤, ≥, >, =
		- Ergebnis sind **Wahrheitswerte** *true* (≠0) und *false* (0)
	- **logische Operationen** auf Wahrheitswerten :
		- mit einem Operanden ¬ (nicht), mit zwei Operadnen ∨, ∧ (oder, und)
	- Ergebnis wird in beliebige Speicerzelle geschrieben

- Programm wird Befehl für Befehl abgearbeitet, außer:
	- **Sprünge:** gehe zu einem anderen Befehl und fahre dort fort
	- **Bedingte sprünge:** springe nur, falls in einer genannten Speicherstelle *true* (eigentleich: nicht 0) steht

### Erstes Beispiel für einen Algorythmus
**Eingabe:** $n$
**Ausgabe:** $n^2$
- Algorithmus:
	- in Worten: im das Quadrat einer Zahl n zu berechnen, multipliziere n mit sich selbst
	- Als Programm:
``` C++
int n = 25;
int nquadrat;  

nquadrat = n * n;
```

## Unser erstes "echtes" c++-Programm
```C++
#include <cstdio>

int main () { // Blockbeginn
int n = 25;
int nquadrat;  

nquadrat = n * n;
printf("%i zum Quadrat ist %i\n", n, nquadrat);
} // Blockende
```
![[Pasted image 20251016151706.png]]

- **wichtige Bestandteile**
	- **Funktion** int main() (Z. 3): Einsprungpunkt (s. später “Funktionen”) 
	- **Block** { ... } (Z. 4–10): Folge von Anweisungen in geschweiften Klammern – in diesem Fall Anweisungen zum Ausführen von int main() 
	- **Variablendeklaration** int n (Z. 4): reserviert Speicherzelle für die Variable n 
		- **Gültigkeitsbereich:** lokal im Block (inkl. aller Unterblöcke) 
		- außerhalb von allen Blöcken deklarierte Variablen heißen **globale** (auch: **freie**) Variablen (sind überall gültig) 
	- **Zuweisung** n = 42 (Z. 7): schreibt Wert 42 (rechts vom Gleichheitszeichen) in die Variable n (links vom Gleichheitszeichen) 
		- **wichtig:** keine Gleichheit im mathematischen Sinne (dafür “ == ” nehmen) 
	- **Ausdruck** n$*$n (hier: Multiplikation). 
		- i.A. Kombination aus Variablen, Konstanten, Operatoren und Rückgabewerten von Funktionen. Die Auswertung eines Ausdrucks ergibt einen Wert.

### Variablen & Datentypen
- Variablen haben einen **Typ**; wir benutzen zunächst: 
	- **int**: 32-Bit Ganzzahlen ( 
	- **char**: 8-Bit Ganzzahlen ( (nicht-negative Werte können als interpretiert werden (z.B. 65 = ‘A’)) ASCII-Zeichen 
	- **double**: 64-Bit Gleitkommazahl 
	- alle bisher genannten auch als **unsigned** 
		- z.B. **unsigned int**: Ganzzahlen aus {}
		- **unsigned char**: früher als *extended ASCII-Zeichen* verwendet (z.B. 154 = ‘Ü’) 
	- **bool**: *true* (1) oder *false* (0) 

- Variablen haben eine **Adresse:**
	- in C++ mit dem Adressoperator & herausfindbar
```C++
int x = 0; printf("%lu\n", &x); // print address of x
```

### Ein-/Ausgabe von Text, Zahlen

Mit `#include <cstudio>` werden Systemfunktionen zur Ein- und Ausgabe von Text "verfügbar gemacht"

- `printf("Text\n");`: Ausgaben von "Text" auf der Konsole
	- Das "\n" is der Zeilenumbruch (vgl. Entertaste oder java: System.outprintln();)

- Ausgabe von Variablen mittels folgender Platzhalter
	- `%i` für Ganzzahlen (*int*) (auch %d)
	- `%lf` `%lu` für Fließkommazahlen (*float/double*)
	- `%c` für Zeichen (*char*)
	- `%s` für String

- `scanf("%i", &n)`: **Eingabe** einer Ganzzahl über die Konsole/Tastatur, Wert wird in Variable `n` gespeichert

- Einzelne Variabken werden nach dem zu druchendne "Text" in der **gleichen Reihenfolge** angegeben, mit Kommata Abgetrennt
``` C++
int i = 1; char x = 68
printf("%cAP %i", x, i)

// Ausgabe: DAP 1
```

![[quadriere.cpp]] 