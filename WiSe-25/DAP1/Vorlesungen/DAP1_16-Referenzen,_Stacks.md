#dap1 

## Parameterübergabe von Objekten an Funktionen

>[!example] Motivation
>Wir wollen die Funktion `print_arr(.)` (druckt alle Arrayeinträge) auf unser `ResizableArray<int>` anwenden.


```cpp
void print_arr(dap1::ResizableArray<int> a) {
	for (int i = 0; i < a.get_size(); ++i) {
		printf("%i", a[i]);
	}
	printf("\n");
}

int main() {
	dap1::ResizabeArray<int> my_array;
	//...
	print_array(my_array);
}
```
```cpp
// class implementing a resizable array (aka std::vector):
template <typename T> class ResizableArray {
	int capacity_; // max. Kapazität
	int n_; // Anzahl Elemente im Array
	T* array_; // Zeiger auf das Array an sich
	
	public:
		ResizableArray() // Konstruktor
			: capacity_{4}, n_{0}, array_{new T[capacity_]} {}
		
		~ResizableArray() { delete[] array_; }
}
```
>[!fail] "mallock: double free for ptr 0x..."
>Was geht hier schief?

![[Pasted image 20251227154626.png]]
⤷ Wie bei allen Funktionsparameter werden ***Kopien** der Variablen* erzweugt!

- Kopie **nur** der **Membervariablen** , also für das Array nur die **Zeigervariable** an sich: ***flache Kopie** (shallow copy)* des Objektes `my_array`
	- *für Profis:* der von C++ automatisch erzeugte **Standart-Copy-Konstruktor** – dieser reicht manchmal aus


- Beim Verlassen von `print_arr` fällt eine Kopie $a$ **aus dem Gültigkeitsbereich** $\leadsto$ der *Destruktor* `~ResizableArray()` wird aufgerufen und *löscht* mit `delete[]` das *originale Array **`:(`***

>[!success] Um das Problem zu lösen:
>1. Entweder die Funktion `T print_arr(ResizableArray<T> a)` so ändern, dass ein ==***Zeiger***== auf das übergebene Objekt *(hier das `ResizableArray`)* übergeben wird
>   `void print_arr(dap1::ResozableArray<int>* a) {}`
>   - nur der Zeiger wird kopiert $\leadsto$ vgl. Parameterübergabe von Arrays $\leadsto$ **Destruktor wird *nicht* aufgerufen**, wenn die (kopierte) Zeigervariable out of scope fällt
>   - Für ***Zeigervariablen*** auf Objekte gilt:
> 	  - um das Objekt selbst anzusprechenm muss sie mit n ***⋆-Operator*** dereferenziert** werden
> 		  - z.B. `(*a).get_size()` für Zugriff auf Memberfunktion `get_size()`
> 	- hierfür gibt es die ***Kurzschreibweise `a->get_size()`***
> 		- bei Arrayzugruff *(allg. Indexoperator)* immer noch `(*a)[i]` **(Operatorpräzedenz)**
> ___
> 2. oder einen ==***Kopierkonstruktor***==*(copy constructor)* implementieren
> - müsste auch **Speicher neu allokieren**: ***tiefe Kopie*** *(deep copy)*
> - machen wir aber (vorerst) nicht – in unserem Beispiel braucht man das nicht
> 	⤷ Kopieren **kostet Zeit** & **Platz**!
> ___
> 1. oder ==***Referenzen***== (s.u.)


---

 >[!TIP] **Operatorpräzedenz** (neu: `->`, `*`)
>- `::` 
>- `()` `[]` `.` `->` **(Dereferenzierung + Memberzugriff)**
>- `!` `++` `--` `&` **(Dereferenzierungsoperator)**
>- `*` `/` `%`
>- `+` `-`
>- `<` `<=` `>` `>=`
>- `==` `!=`
>- `&&`
>- `||`
>- `=` `+=` `-=` `*=` `/=` `%=` `&=` `|=`
>
>*(Operatoren in der gleichen Zeile haben die gleiche Präzedenz)*

___

>[!question] ***Quiz***  *Pointer-Dereferenzierung*
>Was wird in der `main()`-Funktion ausgegeben?
>___
>```cpp
>struct Stud {
>	int matr_nr_;
>	double note_dap1_;
>	unsigned char semester_;
>	
>	Stud(int ma = 0, double note = 5.0, char s = 1)
>		: matr_nr_{ma}, note_dap1_{note}, semester_{s} {}
>};
>```
>```cpp
>int main() {
>	Stud peter(234567, 4.0, 1);
>	
>	Stud* holger = &peter;
>	peter.note_dap1: = 2.0;
>	
>	if (peter.note_dap1_ == (*holger).note_dap1_) printf("YES\n");
>	else printf("NO\n");
>} 
>```
>___
>___
> **\[A: 'YES'\] $\checkmark$** → `holger` ist ein Zeiger auf das Objekt `peter`, speichert also die Adresse von `peter`
> *\[B: 'NO'\]*
> *\[C: keine Ahnung\]*

---

#### Referenzen ***(aka Zeiger)***

Obige methoden führen immernoch zu *hässlichem code*, deshalb gibt es ***Referenzen***.

```cpp
void print_arr(dap1::ResizableArray<int>* a) // a = Zeigervariable 
```
```cpp
void print_arr(dap1::ResizableArray<int>& a) // a = Referenz 
```

Damit kann der Parameter $a$ **wie ein "normales" Objekt behandelt** werden (z.B. mit Memberzugriff `.` statt `->`).
- der Mechanismus ist der gleiche wie die *Übergabe von Zeigern*
- es wird **keine Kopie des Objektes erzeugt** – nur die Zeigervariable wird koüiert

>[!question] ***Quiz*** *Referenz & Operator*
>Warum ist mit `T operator[](int i) { return array_[i]; }` ==kein== schreibender Zugriff auf die Elemente in `ResizableArray` möglich?
>___
>___
>**\[A: Weil ein Wert von Typ T zurückgegeben wird.\] $\checkmark$** → ...und nicht eine Referenz (s.u.)
*\[B: Weil der Operator als konstant deklariert ist.\]*  
*\[C: Weil es generell nicht möglich ist.\]* 

Referenzen **können auch** von *Funktionen*/*Operatoren* **zurückgegeben werden**

⤷ z.B. in Klasse `ResizableArray`:
```cpp	
// returns reference to the i'th cell of the underlying array
T& operator[](int i) { return array_[i]; }
```


⤷ damit ist auch schreibendwer Zugriff auf das Array möglich
```cpp
dap1::ResizableArray<int> my_array;
//...
my_array[2] = -11111;
```

---
### Gute Programmierpraxis

- Wenn Memberfunktion mit Referenz **übergebenes Objekt nicht verändert**, sollten ***const-Referenzen*** verwendet werden.
	- z.B. `void print_arr(dap1::ResizableArray<int> const& a)`
	- vgl. `void print_arr(int const array[], int length)`
	- dann *muss sichergestellt werden*, dass **alle auf dem Objekt verwendeten Methoden** auch `const` sind
		- also: `T const& operator[](int i) const` muss ebenfalls implementiert werden

- um zu **signalisieren**, dass man *ein Objet nicht kopieren sollte* (weil z.B: eine tiefe Kopie nötig wäre), sollte man dies mit "`= delete;`" **beim Kopierkonstruktor angeben**
	- z.B. `ResizableArray(ResizableArray const&) = delete;`

___
>[!summary] ***Merkzettel*** *Objekte, Zeiger, Referenzen*
>Ein ==**Objekt**== namens `a` Wird so angelegt: `Stud a` (vgl. `int x`)
>- mit `a` *bezeichnen* wir das ganze objekt
>- über `a.matr_nr_` können die *Werte der Member-Variablen* angesprochen werden
>- das Objekt *beginnt* mit der **Speicheradresse** `&a`
>___
>___
>Eine ==**Zeigervarialbe**== `Stud* p` *enthält eine Speicheradresse*, an der ein Objekt vom Typ `Stud` liegt
>- um vom Objekt an sich zu sprechen, muss der Zeiger **dereferenziert** werden: `*p`
>- über `p->matr_nr_` / `(*p).matr_nr_` können die *Werte der Member-Variablen* angesprochen werden
>- der *Wert* von `p` ist die *Adresse* von `&(*p)`
>___
>___
>Eine ==**Referenz**== `Stud& r` verhält sich im **compilierten Code** *wie eine Zeigervariable*, aber wir können sie im **Quellcode** *wie ein Objekt* verwenden:
>- um vom *Objekt an sich* zu sprechen reicht `r`
>	- z.B. `Stud a; Stud& r = a` →  $r$ und $a$ bezeichnen _denselben_ Studierenden (da intern $r$ ein Zeiger auf $a$ ist)
>- **Funktionsaufrufe:** bei Übergabe vom Referenzparametern oder Rückgabe von Referenzen werden *keine Objektkopien erzeugt* (da Referenzen intern Zeiger!)

___
___

# Stacks

>[!example] Bespiel: Browser-History
>Ein Webbrowser speichert die URLs der (pro Tab) besuchten Webseiten. Beim Klicken auf `←` wird die zuletzt besuchte Seite aufgerufen.
>Gesucht ist eine Datenstruktur zur Funktionalität.

Ein **Stack vom Typ T** ($T = $ `int`, `double`, ... ) hat folgende Operationen: 
- `init(stack_name, T)`: *initialisiert* einen *leeren Stack* für Elemente vom Typ $T$
- `push(stack_name. x)`: legt das Element $x$ (vom Typ $T$) *'oben' auf den Stack*
- `pop(stack_name)`: falls der Stack nicht leer ist: *gibt oberstes Element* (vom Typ $T$) *zurück* und *löscht es* vom Stapel
- `is_empty(stack_name)`: gibt *wahr* zurück gdw. der *Stack leer* ist

>[!question] Quiz Stack
>Was ist der Inhalt des Stack $s$ nach folgenden Operation? 
>___
>`init(s,int); push(s,3), push(s,2); pop(s); push(s,7), push(s,1); pop(s); pop(s); push(s, 7)`
>___
>___
>*A:* $\begin{bmatrix} 7 \\ 1 \\ 3 \end{bmatrix}$
>**B:** $\begin{bmatrix} 7 \\ 3 \end{bmatrix}$ **$\checkmark$**
>*C:* $\begin{bmatrix} 7 \\ 1 \\ 7 \\ 2 \\ 3 \end{bmatrix}$
>*D:* $\begin{bmatrix} 7 \\ 7 \\ 2 \end{bmatrix}$
>*E:* Stack ist leer


##### Code für Stack
```cpp
template <typename T>
class MyStack {
	private:
		// wir nutzen ein Dynamisches Array, am den Stack zu 
		// implementieren 
		ResizableArray<T> array_;
	
	public:
		// Initialisierung der Membervariablen array_
		MyStack() : array_() {}
		
		void push(T, x) { array_.push_back(x); }
		T pop() { return array_.pop_back(); }
		bool is_empty() const { return array_.size == 0; }
} 
```

#### Komposition
**Erinnerung:** `MyStack` hat die *Membervariable* `array_` vom Typ `ResizableArray`
![[Pasted image 20251228134136.png]]
⤷Komposition von Klassen: MyStack nutzt intern ein Objekt des Typs ResizableArray
