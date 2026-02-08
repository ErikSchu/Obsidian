#dap1

### Zusammenfassung Wiederhulungsanweisungen

- **while** (Bedungung) { ... }
- **for** (Init-Anweisung; Bedingung; Blockend-Anweisung) { ... }
	- äquivalent zur Init Anweisung: **while** (Bedingung) { ... Blockend-Anweisung; }
- bei Blöcken aus nur einer Anweisung können geschweifte Klammern wggelassen werden
- $i$-te Ausführung des Blocks wird auch **$i$-te Iteration** (/$i$-ter Durchlauf) genannt


## Beispiel: Binärdarstellung im 2er-Komplement

**Eingabe:** ein $a \in \mathbb{N}$
**Ausgabe:** Binärdarstellung ($a_{l-1}, \dots, a_{1}, a_{0}$) von $a$ im $l$-Bit Zweierkomplement
Es muss also gelten: $a=-a_{l-1}2^{l-1}+\sum_{i=0}^{l-2}a_{i}2^i$, uns somit auch $-2^l \leq a < 2^{l-1}$

- drucke zunächst das "Vorzeichenbit" $a_{l-1}$ unt transferiere $a$ ggf. ins Nichtnegative
- Drucke restliche Bits der Reiche nach ($i=l-1, \dots, 1, 0$):
	- Teste, ob 0/1 gedruckt werden, durch ganzzahlige Division durch $2^i$
		- Falls 1 Gedruckt: ziehe $2^i$ vom aktuellen $a$ ab
- Also die $\sum$ummation der Formel oben "rückgängig machen".

``` c++
//funktioniert nur für -2^{bits-1} <= zahl < 2^{bits-1}
void print_twos_complement(int zahl, int bits) {
	int upper limit = pow (2, bits - 1);
	if (zahl < 0) {
		printf("1");
		zahl = upper_limit + zahl;
	} else
	printf ("0");
	
	for (int i = bits, two_to_the_i = upper_limit; i >= 0, i--) {
		two_to_the_i /= 2;
		if (zahl / two_to_the_i) {
			printf ("1")
		} else
		printf("0");
	}
	printf("/n");
}
```


### Einfacher Primzahltest

**Eingabe:** Eine ganze Zahl $n$
**Ausgabe:** `true`, falls $n$ prim ist; sonst `false`
*Eine Natürliche Zahl $n$ ist genau dann prim, wenn sie nicht das Produkt von 2 natürlichen Zahlen kleiner als $n$ ist.

- überprüfe für alle Zahlen $i$ mit $2 \leq i < n$, ob $i$ die Zahl $n$ teilt:
	- falls $i$ eine Teiler von $n$ ist: Ergebnis `false`; beende Algorithmus
- falls keines der getesteten $i$ ein Teiler von $n$ ist: Ergebnis ist true

- es reicht, alle Zahlen $2 \leq i \leq \sqrt{n}$ zu testen

```c++
int main {

return 0;
}

bool is_prime(int n) {
	if (n < 2) return false;
	if (n % 2 == 0) return false;
	for (int i = 2, i + i <= i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}
```


## Zusammenfassung C++ Sprachelemente

- `int main()`: Einstiegspunkt, “Main-Funktion”
- **Variablen**deklaration (`int x`), Zuweisungsoperator “=” (`x = Ausdruck`)
- Datentypen `int` (Ganzzahlen) und `double` (Kommazahlen) mit:
    - arithmetischen Operatoren (`+`,`-`,`*`,`/`,`%`)
    - Kurzschreibweisen Inkrementieren (`++x`) und Dekrementieren (`--x`)
        - `x++` und `x--` auch möglich; Unterschied ist Wert des Ausdrucks
        - `n = 5; n = x++;` setzt n auf 5; `n = 5; n = ++x;` setzt n auf 6; x in beiden Fällen danach 6
    - Vergleichsoperatoren (`<=`,`<`,`>=`,`>`,`==`), Ergebnis sind Wahrheitswerte `true, false`
- Datentyp `bool` (für Wahrheitswerte) mit
    - logischen Operatoren (`&&`,`||`,`!`)
- **Ausdrücke**: syntaktisch korrekte Kombination aus Variablen, Konstanten, Operatoren und Rückgabewerten von Funktionen; liefert Wert
- **Blöcke**: zwischen `{` und `}`
    - u.a. für Sichtbarkeits-/Gültigkeitsbereich von Variablen!
- **Bedingte Anweisung** `if ( Bedingung ) { Block }`: führe `Block` nur aus, falls `Bedingung` wahr (eigentlich: Wert des Ausdrucks `Bedingung` nicht 0) ist
- **Wiederholungsanweisungen** `while (...)`, `for (...)`
- **Funktionen**, Parameterübergabe, Rückgabewerte
- Ein-/Ausgabe (`printf()`, `scanf()`) nach `#include <cstdio>`
    - Für Ein-/Ausgabe von Variablen **Platzhalter** benutzen (`%i`, `%lf`, `%c`)

## Operatorpräzendenz (absteigende Reohenfolge)

- `()` (Funktionsaufruf)
- `! ++ -- &` (Adressoperator)
- `* / %`  
- `+ -`  
- `< <= > >=`  
- `== !=`  
- `&&`
- `||`
- `= += -= *= /= %= &= |=`

Außer bei `&& ||` (**short-circuit evaluation von links nach rechts**) ist nicht festgelegt, in welcher Reihenfolge die **Operanden** ausgewertet werden. Z.B. ist bei `x = f() + g()` nicht festgelegt, ob `f()` oder `g()` zuerst ausgewertet wird.