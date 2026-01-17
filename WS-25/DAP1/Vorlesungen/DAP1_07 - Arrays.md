#dap1

Dienstag, 04.11.2025

## [[Arrays]]
**Eingabe:** ein $n \in \mathbb{R}$
**Ausgabe:** $\leq n$
- algoritgmische **Idee:**
	- besuche Primzahlen der Reihe nach
		- Beginn bei 2
	- wenn Primzahl $i$ gefunden: besuche alle Vielfachen $2i, 3i, 4i, \dots$
		- diese sind **keine** Primzahlen → markieren
- Wir brauchen also $n$ **bool**-Variablen $p_{1}, p_{2}, \dots, p_{n}$ mit $p_i$ = **true** gdw. $i$ prim ist
- Hierfür gibt es **Arrays**
	- **bool** `p[n];` deklariert $n$ **bool**-Variablen `p[0], p[1],..., p[n-1]` 

#### Def.
- **Zusammenhängendner Speicherbereich** für $n$ Werte **gleichen Typs** (z.B. int, double, bool)
``` c++
int a[10]; // allokiere 10 ints, ansprechbar durch a[0], a[1], ..., a[9]
```
- Jedes element kann so wie sein Typ verwendet werden.
	- z.B. `a[3] = square(25);` `printf("%i\n", a[3]);`
	- Greift man bspw. `a[i]` aud dem $i$-ten Eintraf des Arrays a der Größe $n$ zu, heißt $i$ auch **Array-Idex**
		- es muss vom Programm  $0 \leq i < \text{Arraygröße}$ sichergestellt werden. 

- Nach **Allokation** grundsätzlich **nicht initialisiert** (enthalten Zufallswärte)
- Können direkt mit Werten initialisiert werden, z.B.:
``` c++
double noten[5] = {2.7, 1.3, 2.0, 2.0, 1.0};
```
- **Standartinitialisierung:**
	- Standartwert für **int**'s ist 0; mit **int** `array[100] = {}` wird das **int**-Array mit 100 Nullen initialisiert
	- beim Initialisieren mit **bool** `prime[100] = {true}` wird nur der 1. Wert auf true gesetzt, alle anderen auf den **Standartwert für bool's** (dieser ist *false*)

- **Wichtig:**
	- bei dieser Art von Array-Allokation **muss** ihre Größe eine (zur Compilezeit bekannte) Konstante sen (eine **constexpr**)
	- Compiler erlauben uft auch **const**
``` c++
constexpr int n = 10*10;  // constexpr means: the value can be computed at compile time
int a[n];

oder

int m;
scanf("%i", &m); 
int const n = m; // const means: after initilization (here with m), the value cannot be changed [](https://dap1.cs.tu-dortmund.de/teil2/vl07-deck.html#cb7-4)
int a[n]; // warning: variable length arrays are a C99 feature
```

### Beispiel
![[Pasted image 20251104132442.png]]


## Funktionen mit Rückgabeparametern
- Funktionen können **i.A. nur einen Rückgabewert** haben
	- z.B. `int f()` gibt Ganzahl zurück
- Lösungsmöglichkeit
	- **Rückgabeparameter:** Parametertyen mit einem `&` markieren, z.B. `void f(int& rückgabeparam)`
		- beim Aufruf von f(x) wird **keine Kopie** des Wertes von x erzeugt → es wird die **Adresse** von x übergeben
		- Funktion f kann Zuweisungen an die Variable **rückgabeparam** machen, so dass beim Programmaufruf darauf zugegriffen werden kann
			- Dies nennt sich ***Übergabe als Referenz**


## Einlesen von Daten aus einer Datei
- Mit `FILE* datei; datei = fopen("marks.txt", "r");` wird eine Datei zum Lesen **geöffnet**
    - liefert `nullptr`, falls fehlgeschlagen (z.B. weil Datei nicht existiert)
- `rewind(datei)` geht zum **Anfang** der Datei
- `fgetc(datei)` liefert ein einzelnen `char` (und geht in der Datei 1 Zeichen weiter)
- `fscanf(datei, "%lf", &x)` liest ein `double` aus der Datei aus, speichert den Wert in x (vgl. scanf) und geht eine Zeile weiter
- Am Schluss sollte die Datei mit `fclose(datei)` **geschlossen** werden
- Details in der [Beschreibung von cstdio](https://en.cppreference.com/w/cpp/header/cstdio)

