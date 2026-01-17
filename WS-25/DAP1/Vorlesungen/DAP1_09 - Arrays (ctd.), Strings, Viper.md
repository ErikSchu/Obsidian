#dap1
## Wdh.

- Arrays bekannter und “kleiner” Größe  werden so allokiert:
  ``` CPP
    int arr[n];  // allokiert n int's arr[0],...,arr[n-1] --
    enthalten Zufallswerte (wie bei Variablendeklarationen)
    ```

- Bei der Parameterübergabe von Arrays an Funktionen mit `void f(int array[])` wird die Anfangsadresse des Arrays (als Kopie) übergeben
    -  Funktionen können übergebene Arrays verändern
    - verhindern mit dem Schlüsselwort `const`: `void f(int const array[])`

- Bei der Variablendeklaration mit `const`:
    - die Variable (oder Array) kann nur einmalig zugewiesen werden (und danach nur gelesen werden)

- `constexpr` ist stärker:
    - wie `const`, aber der zugewiesene Wert muss bereits zum Zeitpunkt der Kompilation berechnet werden können – laut C++-Standard muss  im obigen Code `constexpr` sein

---

## Sieb des Eratosthenes (VL07)

- **Eingabe:** $n \in \mathbb{N}$
- **Ausgabe:** alle Primzahlen $\leq n$ 

- **algorithmische Idee:**
	- besuche die Primzahlen der Reihe nach
		- beginne bei 2
	- wenn Prim. $i$ gefunden: markere alle Vielfachen ($2i, 3i, 4i, \dots$)
		- diese sind $keine$ Primzahlen → markieren

→ *Was tun, wenn $n$ sehr groß ist, oder wen $n$ erst zu Ausführungszeit bekannt ist*

##### Viper 

# Arrays unbekannter Gröte und "große Arrays" (Dynamisches Speichern)

- ist die Arraygröße zur Compilezeit nicht bekannt oder braucht man sehr viele Speucherzellen, werden arrays mit dem **new**-Operator erzeugt (in C: mit der Funktion `malloc()`)

- liefert einen **Zeiger** auf den Anfang des reservierten Speicherbereichs zu (abgespeuchert in einer **Zeigervariablen**)
	- werden mit einem `*` nach dem Datentyp gekennteichnet und speichren eine **Adresse**, an der ein ELement des entsprechenden Datentyps steht

``` cpp
int n;
scanf("%i", &n); // liest Arraygröße vom Terminal ein
int* array = new int[n]; // allokiere Array unbekannter Größe
```

- es kann sein, dass **new**/`malloc()` nicht genügend freien Speicher vorfinden;
	- abfragbar mit **if** (a == **nullptr**) printf("out of memory!\n"); ( in C: (a == 0))
- wird ein mit **new** allokiertes Array nicht mehr benötigt, **muss** der Speicher mit **delete[]** wieder freigegeben werden (in C: free())
	- fällt die Zeigrevariable *out of scope*, wird sonst nur die Speichervariable gelöscht

```cpp
// prints all the primes less than n (using Eratosthenes)
void print_all_primes(int n) {
prime = new int[n]; // allokiere genügend großes Array

// Code für das Sieb des Eratosthenes 

delete[] prime;
}
```


### Durchschnittliche Punktzahl (VL07)

![[Pasted image 20251113124437.png]]

--- 

# Strings

- Arrays vom Typ (**unsigned**) **char** []
``` cpp
int main() {
	char s[] = "Hallo!"; // allokiere Array der Länge 7 (+1 für 0 am Ende)
	s[1] = 'e'; // Strings können wie Arrays manipuliert werden
	
	printf("%s\n", s); // prints "Hello!"
	return 0;
}
```

- Strings sollen "**nullmetriert**" sein (das letzte char hat den Wert 0)
	-  wird bei Strings in doppelten Anführungsstrichen "automatisch" hinzugefügt
- wir bei Arrays auch **dynamische Allokation** mit dem `new`-Operator möglich

## Funktionen auf (nullterminierten Strings)
- für Strings s, t:
	- länge des Strings
```cpp
int str_len(char const s[]) { int i = 0; while (s[i] != 0) return 1; }
```
- Stringvergleich
![[Pasted image 20251113125806.png]]
- etc.

- Sind alle in der Bibliothek **cstring** implementiert (ohne die Unterstriche in den Namen)
- *merke:* **char**s sind letztendlich nur als Zahlen codierte **ASCII_Zeichen**