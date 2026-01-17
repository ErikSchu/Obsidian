#dap1
#### Details Klasse MyString - mit C-style 0-Terminierung

```cpp
class MyString : public ResizableArray<char> {

public:

MyString(char const c_string[]) {

for (int i = 0; c_string[i] != 0; ++i) ResizableArray::push_back(c_string[i]);

ResizableArray::push_back(0); // C-style 0-Terminierung von Strings

}

  

void push_back(char x) { // Überladen der Funktion push_back

pop_back(); // 0-Byte am Ende löschen

ResizableArray::push_back(x); // neues Zeichen anfügen

ResizableArray::push_back('\0'); // C-style 0-Terminierung von Strings ('\0' == 0)

}

  

void append(char const c_string[]) {

pop_back(); // loesche 0-Byte am Ende

for (int i = 0; c_string[i] != 0; ++i) ResizableArray::push_back(c_string[i]);

ResizableArray::push_back(0); // C-style 0-Terminierung von Strings

}

  

MyString& operator+=(char const c_string[]) { // Variante von append

append(c_string);

return *this;

}

  

MyString operator+(char const c_string[]) { // erzeuge Konkatenation vom aktuellen String mit c_string

MyString result = MyString(*this); // erzeugt Kopie vom aktuellen Objekt über Kopierkonstruktor

result.append(c_string);

return result;

}

  

char* c_str() { return array_; } // wie std::string::c_str()

};
```

___
## Weitere Details Vererbung

- Durch die **public**-Vererbung bleibt die Sichtbarkeit von Membern (**public**/**protected**) *wie in der Oberklasse* (aka Basisklasse)

- explizites Ansprechen der Member aus der Oberklasse mit dem **Class-Scope**-Operator `::`, z.B. bei Überladung* von Memberfunktionen:
```cpp
class InformatikStud : public Stud {
	public:
		InformatikStud(int matr_nr, double mark, unsigned char sem, int pg_nr) : Stud(matr_nr, mark, sem), pg_nr_{pg_nr} {}
		
		// Überladung is_equal
		bool ist_equal(IntormatikStud other) { 
			return Stud::is_equal(other) && pg_nr_ == other.pg_nr_;
		}
		
		int pg_nr_; // Nummer der Projektgruppe
}
```

- es lassen sich auch Member-Variablen überladen (jedoch eher unüblich)

- zum Vererbungs-Mechanismus gibt es noch viele weitere Details ...


### Finale Änderungen MyString

>[!example] Ziel 1
>Konstruktor stellt benötigte Größe fest, allokiert gleich ausreichend Speicher

⤷ **Lösung:** ändere Konstruktor von MyString mit variabler initialer Größe, rufe diesen Konstruktor bei der Iitialisierung von MyString explizit auf.

>[!example] Ziel 2
>Das 0-Byte sollte bei get_size() nicht mitgezählt werden

⤷ **Lösung:** überschreibe Funktion get_size()

>[!example] Ziel 3
>Die Funktionen sollten nicht nur C-Strings engtegen nehmen können, sondern auch MyStrings

⤷ **Lösung:** ändere Kopierzuweisungsoperator, *operator+*
	⤷ gut: Funktionen funktionieren auch "wie bisher" (automatische Objekterzeugung von C++)

___
## Header-Guards

```cpp
#include "MyString.hpp"
#include "Stack.hpp"

int main() {
	dap1::Stack<dap1::MyString> webseiten;
	webseiten.push("www.tagesschau.de");
	//...
}
```
⤷ **ResizableArray.hpp** wird 2 mal eingebunden:
	1. durch *\#include* "MyString.hpp"
	2. durch *\#include* "Stack.hpp"
	- Führt zu einer **doppelten Definition** der Klasse `ResizableArray`
		- error: redefinition od 'ResizableArray'
	- Um dies zu vermeiden, werden **Header-Guards** verwendet (in `ResizableArray.hpp`):
```c++
#ifndef RESIZABLE_ARRAY_HPP
#define RESIZAABLE_ARRAY_HPP

// ... hier kommt der ursprüngliche Inhalt (klassendefinition)

#endif // RESIZABLE_ARRAY_HPP
```

- Dies sollte bei allen Header-Dateien geacht werden
	- mit entsprechender Namensanpassung
- mit # beginnende Zeilen heißen ***Compiler-Directive***

---

## Einschub: Konstruktorenaufrufe

#### Wann werden Konstruktoren (von Stud) aufgerufen?
- ***Konstruktor:***
	- beim **Anlegen** eines Objekts:
		- `Stud x;` oder `Stud x(12345, 1.0, 'f');` oder `Stud* x = new Stud();`
		  
	- passiert auch wenn das Objekt ein **Member einer anderen Klasse** ist:
		- `class A { Stud x; }; ... A a;`
		  
	- bem **Anlegen eines Arrays**:
		- `Stud* = new Stud[10]` ruft 10 mal Konstruktor auf
		  
	- beim Anlegen eines Objektes einer **erbenden Klasse**:
		- `class A { Stud x; }; class B : public A {}; ... B b;`

- ***Kopierkonstruktor***
	- bei **erzeugung expliziter Kopien**:
		- `Stud x;` ` Stud y(x);` oder `Stud y = x;`
		  
	- bei **Übergabe als Parameter** an eine Funktion (nicht als Referenz bzw. Zeiger)
		- `void f(Stud s) { ... } ... f(Stud(12345, 1.0, 'f'));`
		  
	- bei **Rückgabe von Funktionswerten** (nicht als Referenz bzw. Zeiger)

#### Defaultkonstruktoren
Bei der Definition einer Klasse **ohne** Konstruktoren werden sogenannte **Defaultkonstruktoren** implizit angelegt:
- *Standart-Konstruktyor* (ohne Argumente)
- *Standart-Kopierkonstruktor*(const-Referenz auf Opjekt als einziger Parameter)
	Diese initialisieren/kopieren bestimmte Member
``` cpp
class Stud {
	public:
		int matr_nr_; // wird nicht immer initialisiert
		dap1::MyString name_; // wird immer intitialisiert
}; // Diese Klasse hat u.a. einen Default-Standartkonstruktor 'Stud()', der std::string() für name_ aufruft
```
Der **Default-Standardkonstruktor** wird **nicht angelegt**, sobald ein *eigener Konstruktor* geschrieben wird
⤷ Widerherstellung mit `= default`

---
# Verkettete Listen

>[!question] Quiz
>- Die Einträge eines (Resizable-)Arrays liegen **im speicher immer konsekutiv**.
>- Unser ResizableArray **kann nach hinten verlängert werden**

## Listen

>[!example] ***Nachteile*** unseres ResizableArrays (aka `std::vector`):
>- kann zwar nach hinten wachsen, aber nicht nach vorn.
>- beim Einfügen von Daten "in der Mitte" müsste bei jeder Einfügeoperation alles danach "um 1 nach hinten" verschoben werden
>- selbst die `push_bach()`-Methode hat manchmal "Schluckauf" (dauert z.T. sehr lange)'
>  ___
>![[Pasted image 20251211152623.png]]

⤷ **Gesucht:** Flexiblere Alternative zu Arrays zur Speicherung von Sequenzen

>[!note] ***Abstrakter Datentyp Liste***
>- Eine **Liste** (*T*=`int`, `double`, …) verwaltet Objekte vom Typ *T* und hat folgende Operationen:
>    - `init(list_name, T)`: initialisiert eine leere Liste für Elemente vom Typ T
>    - `push_back(list_name, x)`: füge Element  vom Typ T an das Ende der Liste an
>    - `pop_back(list_name)`: gib das letzte Element (vom Typ T) aus list_name zurück und lösche es
>    - `push_front(list_name, x)`: füge Element  vom Typ T an den Anfang der Liste an
>    - `pop_front(list_name`: gib das erste Element (vom Typ T) aus  zurück und lösche es
>    - `is_empty(list_name)`: gibt wahr zurück gdw. die Liste  leer ist
>    - `size(list_name)`: gib die Anzahl der Elemente in der Liste  zurück
>    - weitere möglich, z.B.:
>        - `find(list_name, x)`: gib wahr zurück gdw. $x$ in  ist
>        - `insert_after(list_name, x, y)`: füge  hinter dem ersten Vorkommen von  in die Liste  ein (falls $x$  in der Liste ist)
>        - `concat(list_name1, list_name2)`: füge alle Elemente aus  and an das Ende der Liste  an
>        - `begin(list_name)`: gib einen Zeiger (“Iterator”) auf den Beginn der Liste zurück
>        - $\dots$
>  ___
>![[Pasted image 20251229172554.png]]

#### Datenstruktur Verkettete Liste

- Jeder **Knoten** besteht aus einem
	- *Datenelement* (eines beliebigen Typs $T$)
	- *Zeiger* auf den folgenden Knoten

(eigentlich definiert das schon eine verkettete Liste)

- Wir erweitern trotzdem: Die Datenstruktur ***Verkettete Liste*** verwaltet:
	- einen *Zeiger* auf den *ersten* (**Kopf**) und den *letzten Knoten* (**Tail**) der Liste
	- die im ADT "Liste" genannten Operationen