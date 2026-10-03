#dap1

> [!info] Info
>- 2 (patielle) Probeklausuren in Moodle
>	- bei Fragen: Helpdesk
>- Ende 1. Semesterhälfte
>	- Unter 30p = schlecht

- **Vorteil Stack gegenüber resizable Array:** Ist letztenendes das selbe, jedoch als elementarer Datentyp. Das *resizable Array ist eine mögliche Implementierung* des Stacks. 

- Kopien von Variablen werden so erzeugt:
	```cpp
	int x = 10; int y = x; // kopiere x
	```


![[Pasted image 20251209122217.png]]
⤷ Kompilierfehler & ***Double free***


___

## Kopieren

### Kopierkonstruktor

Diesen muss man implementieren, damit **Objekte kopierbar** sind
⤷ erhält als Argument eine *const*-Referenz auf ein Objekt der gleichen Klasse

```cpp
// copy constructor
ResizableArray(ResizableArray const& other) {
	n_ = other.n_;
	capacity_ = other.capacity_;
	array_ = new T[capacity_];
	for (int i = 0; i < n_; ++i) array[i] = other.array_[i];
}
```

 explizite Erzeugung von Kopien durch
```cpp
ResizableArray<Stud> studierende(19); // füllt Array studierende
ResizableArray<Stud> studierende2(studierende); //erzeugt Kopie
ResizableArray<Stud> studierende3 = studierende; // "
```


___

### Copy-Zuweisungsoperator

wir die Zuweisung auf ein **bereits bestehendes Objekt** vorgenommen, wird der **Copy-Zuweisungsoperator** (*copy assignment operator*) aufgerufen
```cpp
ResizableArray<Stud> studierende(19); // füllt Array studierende
//erzeugt leeres array
ResizableArray<Stud> studierende2(studierende);
// ruft Copy-Assignment-Operator auf
ResizableArray<Stud> studierende3 = studierende;
```

**Unterschied:** das Objekt existiert bereits $\leadsto$ Speicher muss freigegeben werden!
``` cpp
// copy assignment operator
ResizableArray& operator = (ResizableArray const& other) {
delete[] array_; // free space for c-array of this object
n_ = other.n_;
capacity_ = other.capacity_;
array_ = new Z[capacity_];
for (int i = 0; i < n_; ++i) array_[i] = other.array_[i];
return *this; // returns reference to this object
}
```
⤷ im Gegensatz zu Kopierkonstruktor keine const-Referenz als Rückgabewert

___

> [!TIP] **Rule of 3** (Dreierregel)
>1. Destruktor
>2. Copy-Konstruktor
>3. Copy-Assignment-Operator

>[!question] Welche der folgenden aussagen ist **falsch**?
>*\[A: Der Copy-Konstruktor erhält als Argument eine const-Referenz\]*
>___
>*\[B: Der Copy-Konstruktor gibt keinen Rückgabewert\]*
>___
>*\[C: Der Copy-Assignment-Operator erhält als Argument eine const-Referenz\]*
>___
>**\[D: Der Copy-Assignment-Operator gibt als Rückgabewert eine const-Referenz\] $\checkmark$**

---
___

# Vererbung

## Strings
> [!example] Wir wollen eine Klasse `MyString` zum komfortablen Umgang mit Strings implementieren.

>[!todo] Abstrakter Datentyp ***Dynamischer String***:
>- `init(string_name, string)` → initialisiere einen String mit dem Inhalt string (string == " " möglich)
>  ___
>- `append(string_name, string)` → füre string an den String string_name hinten an
>  ___
>- `assign(string_name, string)` → ändere my_string auf den neuen Inhalt string
>  ___
>- `size(string_name)` → gib die Länge des Strings string_name zurück
>  ___
>- `read(string_name, i` → gibt das i-te Zeichen des Strings zurück, falls 0 <= i <= size(string_name)
>  ___
>- `write(string_name, i, c)` → schreibe das Zeichen an die i-te Stelle, falls 0 <= i <= size(string.name)
>  ___
>- `operator+(string_name, string)` → konkateniere string_name mit string  und gib das Ergebnis zurück
>  ___
>-  ...

Um Klassen um zusätzkiche Funktionalität zu **erweitern**, gibt es den Mechanismus der ==***Vererbung***==:
```cpp
class MyString : public ResizableArray<char> {
	// ...
}
```

- das definiert einen neuen Datentyp `MyString`, der alle Member (Funktionen und Variablen) von `ResizableArray<char>` übernummt
	- das **public** `ResizableArray<char>` heißt, dass MyString alle **public**-Member von ResizableArray erbt (Zugriff inner- *und* außerhalb der Klasse)
	- um auch klasseninternen Zugriff auf die anderen (bisher als *private* deklarierten) Membern zu erhalten, müssen diese in class *class* ResizableArray als **protected** markiert werden:
		- alle *public*-erbenden Klassen haben Zugriff auf diesen Member
		- für alles andere wie *private*


#### Details Klasse MyString - mit C-style 0-terminierung
```cpp
class MyString : public ResizableArray<char> {
 public:
  MyString(char const c_string[]) {
    for (int i = 0; c_string[i] != 0; ++i) ResizableArray::push_back(c_string[i]);
    ResizableArray::push_back(0);  // C-style 0-Terminierung von Strings
  }

  void push_back(char x) {  // Überladen der Funktion push_back
    pop_back();                       // 0-Byte am Ende löschen
    ResizableArray::push_back(x);     // neues Zeichen anfügen
    ResizableArray::push_back('\0');  // C-style 0-Terminierung von Strings ('\0' == 0)
  }

  void append(char const c_string[]) {
    pop_back();  // loesche 0-Byte am Ende
    for (int i = 0; c_string[i] != 0; ++i) ResizableArray::push_back(c_string[i]);
    ResizableArray::push_back(0);  // C-style 0-Terminierung von Strings
  }

  MyString& operator+=(char const c_string[]) {   // Variante von append
    append(c_string);
    return *this;
  }

  MyString operator+(char const c_string[]) {  // erzeuge Konkatenation vom aktuellen String mit c_string
    MyString result = MyString(*this);  // erzeugt Kopie vom aktuellen Objekt über Kopierkonstruktor
    result.append(c_string);
    return result;
  }

  char* c_str() { return array_; }  // wie std::string::c_str()
};
```

### Grafische Darstellung von Vererbung
![[Pasted image 20251209133045.png]]
⤷ Vererbung von Klassen: `MyString` erbt alle Member von `ResizableArray<char>`


>[!question] Quiz Vererbung
>Die Klasse `MyString` hätte auch durch eine Membervariable des Typs `ResizableArray<char>` in `MyString` implementiert werden können:
>___
>```cpp
>class MyString {
>	// ... (Code für die Methoden)
>	private:
>		ResizableArray<char> array_;
>}
>```
>```cpp
>class MyString : public ResizableArray<char> {
>	// ... (Code für die Methoden)
>}
>```
>___
>___
>*\[A: nein, das ginge nicht\]*
>*\[B: ja, der code bliebe gleich\]*
>**\[C: ja, aber alle Methoden hätten neu implementiert werden müssen\] $\checkmark$**

## Weitere Details

- duch **public**-Vererbung bleibt sichtbarkeit von Membern (public/protected) wie in der **Oberklasse** (oder Basisklasse)
  
- explizites Ansprechen der Member aus der Oberklasse mit dem **Class-Scope**-Operator `::`, z.B. bei **überladung** von Memberfunktionen
```cpp
class IformatikStud : public Stud {
	public:
		InformatikStud(int mat_nr, double mark, unsigned char sem, int pg_nr) 
			: Stud(mat_nr, mark, sem), pg_nr_(pg_nr) {}
		
		bool is_equal(InformatikStud other) { // Überladung von is_equal
			return Stud::is_equal(other) && pg_nr_ == other.pg_nr_;
		}
		
		int pg_nr_; // Nummer der Projektgruppe (Masterveranstaltung)
}
```

- es lassen sich auch Member-Variablen überladen (eher unüblich)

- zum Vererbungsmechanismus gibt es noch viele weitere Details ...