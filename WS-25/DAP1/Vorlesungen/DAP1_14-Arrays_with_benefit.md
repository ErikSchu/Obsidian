#dap1 

## Klassentemplates
⤷ Wie bein Funktion muss der Code nicht für alle Datemtypen neu geschrieben werden

```cpp
template<typename T>
class Array {
	public: //kann von aussergalb der Klasse gelesen/ zugegriffen werden
		Array(int size, T init) : n_{size} {
			for (int i = 0; i < n_; ++i) array_[i] = init;
		}
		
		T read(int i) {
			//index out of bounds
			if (i < 0 || i > n_ - 1) return 0; 
			return array_[i]
		}
		
		void write(int i, T x) {...}
};

int main() {
	Array<int> arr1(10, -1); // allokiere ein Array
	for (int i = 0; i < 10; ++i) {
		printf("%i\n", arr1.read(i));
	}
}
```

#### Bsp.: Arrays mit "Zusatzfunktionaltät"

> [!example] Wir wollen ein ADT implementieren, der Arrays mit 2 Zusatzfunltionalitäten  bietet:
> - beim Anlegen eines $n$-großen Arrays alle $n$ Einträge mit einem beliebigen Wert **initialisieren**
> - beim Arrayzugriff prüfen, ob der **Arrayindex innerhalb** von $[0, n-1]$ liegt

**template** <***typename T***\> **class MyArray** implementiert diesen ADT:
- *alloc* (array_name, n , initial Value, T):
	- in C++: `MyArray<T> array_name(n, initial_value);`
- *read* (array_name, i):
	- in C++: `T val_at_i = array_name.read(i);`
- *write* (array_name, i, expr):
	- in C++: `array_name.write(i, expr);`

Erzeugung eines solchen Arrays mit `Array<double> noten(8, 5.0f);`
- erzeugt ein  Objekt des Typs `Array<Double>`:
	- reserviert Speicher für die Membervariablen (im Beispiel *int n_* und *double\* array_*)
	- ruft den Konstruktor `Array<double>(int, double)` auf

![[Pasted image 20251226100950.png]]

---
## Member-Initialisierung mit Default-Parameter

- **Membervariablen** werden zwischen der *Konstruktordeklaration* und der *Konstruktordefinition* mit Parameterwerten initialisiert
	- `Klassenname(parameterliste) : member1_{expr2}, ..., memberx_{exprx} { ... }`
	- z.B. `array(int size, T init) : n_{size} { ... }`

	- **Default-Parameter** bei Konstruktoren:
	- z.B. `Array(int size = 1, T init = 0)`
		- Damit Erzeugung von Objekten mit `Array<double> noten(20)` (ruft Konstruktor mit *Array(int)* auf)   oder  `Array<double> noten` möglich (ruft Konstruktor `Array()` auf)

---

## Verwendung des Schlüsselwortes ***const***

Erinnerung: [[C++_Parameterübergabe_&_Const-Correctness]]

- **Variablen**, die nach erstmaliger Zuweisung nicht mehr verändert werden dürfen:
	- z.B. `int const n = read_size_from_terminal();`
	- Zuweisung *muss* im gleichen Statement stehen (`init const n; n = ...;` *nicht möglich* )
	- Erinnerung: ***constexpr*** stärker (zugewisener Wert muss zur Compilezeit feststehen)

- **Funktionsparameter**, die die Funktion nicht verändern darf
	- insb. wichtig vei der *Übergabe vo Arrays* (allg. Zeiger) and Funktionen 
		- z.B. `void f(int const array[])` oder `void f(int const * array)`

- ***Neu:*** **Memberfunktionen**, die die Membervariablen *nicht verändern*
	- z.B. `T read(int i) const { ... }`

---

## Datenklasse ***Stud***, "kombination" von Klassen 

Klassen werden auch oft zur **Aggregation zusammengehöriger Daten** verwendet

```cpp
class Stud {
	public:
		Stud(int nr = 0, double mark = 5.0, unsigned char semester = 1)
		: matr_nr_{nr}, note_{mark}, semester_{semester} {}
		
		int matr_nr_; // Matrikelnummer des Stud.
		double note_; // Note
		unsigned char semester_; // Semester
};
```

⇨ Da Klassen *neue Datentypen definieren*, können diese i.A. *wie elementare Datentypen* verwedet werden

-  z.B. als **Funktionsparameterryp** `bool is_equal(Stud other)` in der Klasse Stud

-  oder bei der **Template-Instanziierung** eines dynamischen Arrays: `ResizableArray<Stud> studierende;`
	- auch mit Konstruktorparametern, z.B zur Allokation unseres Arrays fester Größe: `MyArray<Stud> studierende(10, Stud());`

___

## Alle Primzahlen speichern

>[!example] .
>*Eingabe:* eine natürliche Zahk $n$.
>*Aufgabe:* erzeuge eun Array $A[0, p-1]$, dass alle $p$ Primzahlen $\le n$ enthält.

```cpp
int n;
scanf("%i", &n);
int p = ???;
int* primes = new int[p];
int j = 0;
for (int i = 2; i <= n; ++i) if (is_prime(i)) primes[j++] = i;
```

>[!question] Quiz 
>Wenn der Platz in einem Array `array[0, n-1]` nicht ausreicht (etwa um weitere Elemente ab der Position $n$ zu speichern), kann man $\dots$
>
>***\[A: Das Array vergrößern\]***
>***\[B: ein weiteres Array hinter dem ersten anfügen\]***
>***\[C: nichts davon tun\]*** **$\checkmark$**
>___
>![[Pasted image 20251226154145.png]]
>⤷ Arrays haben zugriff auf Elemente in konstanter Zeit!

---

## Namespaces
... gibt es um *namenskonflikte auflösen*

- Werden – getrennt mit 2 Doppelpunkten `::`  – vor den Funktions-/Klassen-/...-namen gestellt
	⤷ z.B. können wir unser ResizableArray in einen eigenen Namespace **`dap1`** "stecken":
```cpp
namespace dap1 {
	class ResizableArray {
		// ...
	};
}
```

- C++ stellt mit der **Standart Template Library** bereits eine Anzahl von Klassen zur Verfügung, die alle im ***Namespace `std::`*** sind
	⤷ z.B. **`std::random_device r`** nach `#include <random>` (Klasse, die einen Zufallsgenerator zur Verfügung stellt)