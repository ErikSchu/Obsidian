#dap1

### Erste Coding-Standarts

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

## Bedingte Anweisung

Entwickeln Sie eine Funktion, die Gesichter dieser Art im Terminal ausgibt:
```
    o o      o o      . .      o o      o o   
     |        *        .        ^        J
    ---      ---      ---      ---      ---
```

Also: nur, wenn die Nase ein Punkt ist, sollen auch die Augen ein Punkt sein; sonst sind die Augen ein o.
``` C++
void print_gesicht(char nase) {
  if (nase == '.') {  // falls Nase ein Punkt:
    printf(". .\n");  // dann Augen ein Punkt
  } else {            // sonst:
    printf("o o\n");  // Augen ein 'o'
  }
  printf(" %c \n", nase);  // Nase
  printf("---\n");         // Mund
}
```

#### Verschachtelung
Entwicklen Sie eine Funktion, die folgendes Verhalten hat:
**Eingabe:** Eine ganze Zahl $n$.
**Rückgabe:** Das Zeichen “-”, falls $n<0$ , sonst das Zeichen “+”
``` C++
char sign(int n) {
    if (n < 0) {
        return '-';
    }
    else {
        return '+';
    }
}
```

- **if** ( Ausdruch ) { Block }: Block1 wird nur ausgeführt, falls derAusdruck zu wahr (**true**) ausgewertet wird (egtl. $\neq$ 0).
- **else** { Block2 } : Block2 wird nur ausgeführt, falls der Ausdruck **falsch** (false)
	⤷ optional

``` C++
Heutige schrebweise:

if (Bedingung) {
    // Block 1
}
else {
    // Block 2
}
// hier geht es weiter
```

``` C++
Was der Computer intern macht (analog zum word-Ram Modell(bedingte & unbedingte Sprünge)):

if (Bedingung) goto 6;
{
	// Block 2
}
goto 9;
{
	// Block 1
}
// hier geht es weiter mit dem Melken
```

#### Beispielalgorithmus: Exponenzieren

Schreiben sie eine Funktion mit forlgedem Verhalten:
**Eingabe:** Ein $n, x \in \mathbb{N}$ 
**Rückgabe:** $n^x$
In **Pseudocode:**
1. $r$ ← 1
2. Wiederhohle $x$ mal: $r$ ← $r * n$ 
3. gib $r$ als Ergebnis zurückg