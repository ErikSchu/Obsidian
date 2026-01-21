#dap1

### Wdh. [[DAP1_04-Bedingte Anweisungen]]

- **if** (Ausdruck) { Block1 }: Block 1 wird nur ausgefüht, falls der Ausdruck zu wahr (true bzw. != 0) ausgwertet wird.
- else { Block2 }: Block2 wird nur ausgeführt, falls der ausdruck falsch (false bzw. = 0) ist. → optional
- Block aus nur 1 Anweisung: geschweiftes Klammerpaar (meistens) optional

Beispiel mit While-Schleife
![[Pasted image 20251028132448.png]]
![[Pasted image 20251028132529.png]]

## Wiederholungsanweisung

- **while (Bedingung) { Block }**
    1. es wird zunächst geprüft, ob die Bedingung erfüllt ist (Wahrheitswert `true`)
        - eigentlich: ob die Auswertung des Ausdrucks `Bedingung` einen Wert $\neq 0$ ergibt
    2. falls ja, wird der `Block` ausgeführt und danach zu 1. gesprungen
        - sonst wird die nächste Anweisung nach der schließenden geschweiften Klammer des Blocks ausgeführt
        - 
- **In der Bedingung:**
    - binäre logische “Verknüpfung” mit ‘und’ `&&` bzw. ‘oder’ `||`
        - z.B. `while (wert >= 0 && wert < 10) { ... }`
    - unäre logische Verknüpfung mit ‘nicht’ `!`
        - z.B. `while (!(f(x) == 5)) { ... }` bzw. `while (f(x) != 5) { ... }` als Kurzschreibweise
    - kombinierbar!

#### For-Schleife 

- Allgemein: `for` und `while` sind äquivalent
- `init`, `condition` und `increment` können beliebige Ausdrücke sein
    - Ausdruck = (syntaktisch korrekte) Kombination von Operatoren, Variablen, Konstanten und Funktionsaufrufen; Auswertung liefert **Wert**
    - `while(true)` erzeugt **Endlosschleife**
    - in `for` darf sogar `condition` leer sein  `for( ; ; )` erzeugt auch Endlosschleife
- Dies kann, bei “Missbrauch”, zu sehr schwer zu lesendem Code führen
    - wir versuchen, dies zu vermeiden (Benutzung wie auf der vorherigen Folie)

- Funktionsargumente werden in C++ **immer** als **Kopie** übergeben (d.h. Verändern in der Funktion möglich, **ohne** den Wert im aufrufenden Teil zu verändern).

## Zusammenfassung

- im wordRAM-Modell: es gibt nur Sprünge und bedingte Sprünge, aber:
- (bedingte) Sprünge werden in C++ **nicht direkt** ausgedrückt, sondern über
    - Wiederholungsanweisungen (`for`, `while`)
    - und die bedingte Anweisung (`if ... else`).
- **Weglassen** der geschweiften Klammern von Blöcken bei **einer einzelnen** Anweisung immer möglich!
    - `if (x < 10) printf("OK\n");` und `if (x < 10) { printf("OK\n"); }` sind äquivalent
    - `for (int i = 1; i < 10; ++i) printf("%i\n", i*i);` auch möglich
- Daher ist auch `else if` **kein** neues Konstrukt


# Weiteres Beispiel: Quadratwurzel approximieren nach Heron

![[Pasted image 20251028142458.png]]
![[Pasted image 20251028142545.png]]


# FORfreude

Apple pencil