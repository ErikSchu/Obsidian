#dap1 

## Doppelt verkettete Listen

Aus unserer bisherigen verketteten Liste *können keine Elemente am Ende* **gelöscht** werden
⤷was wäre der neue letzte Knoten

Wir *erweitern* dazu die **Knoten-Klasse** um ein ***zusätzliches Feld***
⤷`Node<T>* prev_:` Zeiger auf das **vorherige** Elemente

```cpp
// Node class storing objects of type T in a doubly linked list 
template <typename T> 
class Node {
	public:
		Node(T const& s) : cont_{s} {}
		
		Node* prev_ = nullptr;
		T cont_;
		Node* next_ = nullptr;
};
```

___

>[!question]
>Was ist der Inhalt der `LinkedList<int> L` in der obigen Speichersituation, falls `&L.last_ == 5` gilt?
>___
>```cpp
>// Node class storing objects of type T in a doubly linked list 
>template <typename T> 
>class Node {
>	public:
>		Node(T const& s) : cont_{s} {}
>		
>		Node* prev_ = nullptr;
>		T cont_;
>		Node* next_ = nullptr;
>};
>```
>```cpp
>template <typename T>
>class LinkedList {
>	Node<T>* head_; // 1. Element
>	Node<T>* last_; // letztes Element
>	int size_; // count nr of elements of list
>} 
>```
>___
>___
>![[Pasted image 20251229183011.png]]
>___
>*\[A: 0, 7\]*
>*\[B: 1, 7\]*
>**\[C: 0, 5, 2\] $\checkmark$**
>*\[D: 0, 5, 2\]*
>*\[E: 10, 5, 7, 11, 7\]*

___
___

## Queues

##### Problem "Warteschlange"
![[Pasted image 20251229183707.png]]

### ADT Queue (deutsch: Warteschlange)

>[!note] ***Eine Queue vom Typ $T$ ($T$ =  int, double, ... ) hat folgende Operationen:***
>`init(queue_name, T)`: **initialisiert** eine *leere Queue* für Elemente vom Typ $T$
>___
>`push_back(queue_name, x)`: legt das *Element $x$*  (vom Typ $T$) **ans Ende** der Queue
>___
>`pop_front(queue_name)`: falls die *Queue nicht leer* ist: gibt das **erste Element** (vom Typ $T$) **zurück** und **löscht es** aus der Queue 
>___
>`is_empty(queue_name)`: *gibt wahr zurück* gdw. die **Queue leer** ist 

⤷lässt sich miet einer `LinkedList<T>` implementieren `(:`

---

## Erinnerung `Stack`
![[Pasted image 20251229184713.png]]

## `Code` Stacks mit verketteten Listenm

```cpp
template <typename T>
class MyStackLL {
	public:
		MyStackLL() : list_() {}
		
		void push(T const& x) { list_.push_front(x); }
		T pop() { return list_.pop_front(); }
		bool is_empty() const { return list_.is_empty(); }
		
	private:
		LinkedList<T> list_;
};
```
⤷die *Vor- und Nachteile* werden *von den zugrundeliegenden Datenstrukturen* Linked List / Resizable Array *übernommen* $\leadsto$ nächste Rolle

> [!note] Ergebnis `Profiling Stacks`
> ![[Pasted image 20251229185400.png]]
> ___
> ![[Pasted image 20251229185719.png]]

![[Pasted image 20251229185748.png]]


## Vergleich Queue/Stacks

-  `Queue:` ***FIFO*** *(first in first out)*
	- Funktionalität, die man von einer **fairen** **Warteschlange** erwartet

- `Stack:` ***LIFO*** *(last in first out)*
	- *nicht "fair"*, aber hat trotzdem **viele Anwendungen**:
		- Webbrowser
		- Rechnerarchitektur (Funktionsaufrufe)
		- Algorithmik, z.B. Graphen, Bäume $\leadsto$ später in `DAP1/2`
		- Parsing $\leadsto$ GTI


___

## ***`Deque`*** (Doubly Ended Queue)

Der **ADT/die Datenstruktur** mit den **Operationen** `push_back()`, `push_front()`, `pop_back()`, `pop_front()`, `begin()` und `end()` wird auch als ***Deque*** bezeichnet.

```cpp
template <typename T> 
class Deque { 
	LinkedList<T> list_; // benötigt *doppelt* verkettete Listen 
	
public: 
	Deque() : list_() {} 
	
	void push_front(T const& x) { list_.push_front(x); } 
	void push_back(T const& x) { list_.push_back(x); } 
	T pop_front() { return list_.pop_front(); } 
	T pop_back() { return list_.pop_back(); }
	// assuming head_ is public 
	Node<T> const* begin() { return list_.head_; } 
	// assuming last_ is public
	Node<T> const* end() { return list_.last_; } 
	bool is_empty() const { return list_.is_empty(); }
};
```

___
___

>[!note] ***STL-Containers im Vergleich zu unseren Klassen***
>![[Pasted image 20251229191204.png]]


___
___


>[!TIP] X-mas Bonus: **Linked List mit Move-to-Front**
>![[Pasted image 20251229191322.png]]
>___
>___
>![[Pasted image 20251229191351.png]]
>___
>___
>![[Pasted image 20251229191410.png]]
