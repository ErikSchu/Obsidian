#dap1 

## Klassen & Objekte

Zur *Beschreibung neuer Datentypen* eignen sich **Klassen** ( `class ClassName` )
⤷ Bündelung von ==Daten== (**Membervariablen**) und  ==Funktionen== (**Memberfunktionen**)

Um *neue Datentypen zu verwenden*, werden mit **`ClassName onj_name(...);`** **Objekte** des Typs erstellt
- analog zu *int x*
- ruft Konstruktor `ClassName(...);` auf (Existenz mehrerer Konstruktoren möglich)

**Member-Access-Operator `.`** 
- um auf die *öffentlichen* Daten oder Funktionen zuzugreifen
- z.B. `obj_name.n_`, falls n_ in Klasse `ClassName` eine *public*-Membervariable ist
- oder `obj_name.write(i, x)`, falls `write(int, T)` eine *public*-Memberfunktion ist
- ==kombinierbar==, z.B. `my_stud.read(1).matr_nr_`, falls read ein(e Referenz auf ein) Objekt zurückgibt

>[!TIP] **Operatorpräzedenz** (neu: `::`, `.`)
>- `::` **(Auflösung von Namespaces)**
>- `()` `[]` `.` **(member access)**
>- `!` `++` `--` `&`
>- `*` `/` `%`
>- `+` `-`
>- `<` `<=` `>` `>=`
>- `==` `!=`
>- `&&`
>- `||`
>- `=` `+=` `-=` `*=` `/=` `%=` `&=` `|=`
>
>*(Operatoren in der gleichen Zeile haben die gleiche Präzedenz)*

****

# Dynamische Arrays

*Erinnerung:* Array vergrößern oder weiteres Array anhängen nicht möglich

## Abstrakter Datentyp ***Dynamisches Array***

>[!note] ... vom Typ $T$ ($T$ = int, double, ... ) hat folgende Operationen:
>- `init(array_namem, T)`: **initialisiere ein leeres Array** vom Typ $T$; setze $n=0$ (Anzahl Elemente)
>___
>- `write(array_name, i, x)`: falls $0 \le i < n$, **überschreibe** den $i$-ten Wert mit $x$
>___
>- `T read(array_name, i)`: falls $0 \le i < n$, **gib** den $i$-ten Wert (vom Typ $T$) **zurück**
>___
>- `push_back(array_name, x)`: **füge** $x$ **an das Ende** des Arrays an; erhöhe $n$ um 1
>___
>- `get_size(array_name)`: gib die **Anzahl der Elemente** zurück
>- `pop_back(array_name)`: **lösche** das Element vom **Ende des Arrays**  und **gib es zurück**; erniedrige $n$ um 1
>___
>___
>alle Operationen benötignen konstant viele Rechenoperationen (*Ausnahme: `push_back` "amortisiert konstant" viele Ops $\leadsto$ DAP2*)

##### Algorithmische Idee
- verwalte immer ein **zusammenhängendes Array** der Größe $capacity$
	⤷ initial ist z.B. $capacity = 4$
- `push_back(array_name, x)`:
	- falls $n = capacity$:
		- *verdopple* $capacity$
		- allokiere $capacity$ *zusammenhängende* Speicherzellen vom Typ $T$ (*neues Array*)
		- *kopiere* die $n$ alten Werte an den Anfang des neuen Arrays
		- *lösche* das alte Array (speicher Freigeben)
		- arbeite mit folgendem neuen Array weitere
	- speichere $x$ (vom Typ $T$) an der $n$-ten Stelle des Arrays
	- erhöhe $n$ um 1
	![[Pasted image 20251226172451.png]]

```cpp
template <typename T> class ResizableArray { 
    T* array_;       // Zeiger auf den Anfang des Arrays 
    int n_;          // aktuelle Anzahl der Elemente im Array 
    int capacity_;   // Anzahl der momentan belegten Speicherzellen 
    
public: 
    ResizableArray() : n_{0} { // Konstruktor 
        int initial_capacity = 4; // fange mit Minimalgröße 4 an 
        array_ = new T[initial_capacity]; // allokiere Platz 
        capacity_ = initial_capacity; 
    } 
	
    void push_back(T value) { // füge value an das Ende vom Array an 
        if (n_ == capacity_) { 
            capacity_ *= 2; // verdoppele Kapazität 
            T* new_array = new T[capacity_]; // allokiere mehr Platz 
            for (int i = 0; i < n_; ++i) 
                new_array[i] = array_[i]; // kopiere Elemente 
            delete[] array_; // gib alten Speicher frei 
            array_ = new_array; // biege Zeiger um 
        } 
        array_[n_++] = value; 
    } 
    // ... 
};
```

##### ResizableArrays in der C++ STL 
- ***Standart Template Library*** (STL) stellt häufig benötigte Datenstrukturen und Algorithmen zur verfügung
- Unser **dap1::ResizableArray** heißt dort **std::vector**
	⤷ benutzbar über `#include <vector>`
- unser (rudimentär) implementiertes *Array* heißt **std::array**

##### Quiz dynamische Arrays
> [!question] Quiz
> Ein Dynamisches Array, das $n$ elemente speichert, belegt zu jedem Zeitpunkt maximal so viele speicherzellen (wählen Sie die genaustmögliche Abschätzung):
> ___
> *\[A: $3$\]*
> *\[B: $\frac{n}{2}$\]*
> *\[C: $n$\]*
> **\[D: $2n$\] $\checkmark$**
> *\[E: $3n$\]*
> ___
> ___
> ****
> ![[Pasted image 20251226210107.png]]

##### Profiling: *Zeit (in s) für einzelne push_back's*
![[Pasted image 20251226210221.png]]
- **Laufzeit-Realität:** Die flache Linie zeigt den Normalfall ($O(1)$, einfache Zuweisung), die Spitzen zeigen das teure Resizing ($O(N)$, Allokation + Kopieren aller Elemente).
    
- **Exponentielle Ruhephasen:** Durch die Verdopplungsstrategie (`capacity *= 2`) werden die Abstände zwischen den teuren "Umzügen" immer größer.
    
- **Amortisierte Komplexität:** Obwohl einzelne Operationen teuer sind, ist der **Durchschnitt** über viele Operationen konstant ($O(1)$), da die Spitzen immer seltener auftreten.

---
## Operatoren

Klassen können neben Funktionen auch ***Operatoren*** implementieren
- z.B. **Indexoperator** `operator[]`
	- `T operator[](int i) { return array_[i]; }`
		- damit *lesender Zugriff* möglich ist `my:array[i]` statt `my_array.read(i)`
	
	- **Wichtig:** Operatoren sind ***nichts anderes als Funktionen***
		- äquivalente (aber sinnlose) Schreibweise: `my_array.operator[](i)`

Es gibt eine Reihe **weitere**r **Operatoren**
- z.B. der *Klammeroperator* `operator()`
	- vgl. `std::random_device rd; random_nr = rd();`
- oder *arithmetische Operatoren* `+` `–` `*` `/` `%`