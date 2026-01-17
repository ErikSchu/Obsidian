#dap1 
## Datenstruktur *Verkettete Liste*

- Jeder **Knoten** besteht aus einem
	- *Datenelement* (eines beliebigen Typs $T$)
	- *Zeiger* auf den folgenden Knoten

- Erweiterung: Die Datenstruktur ***Verkettete Liste*** verwaltet:
	- einen Zeiger auf en ersten (**Kopf**) ind den letzten (**Tail**) Knoten der Liste
	- die im ADT "Liste" genannten Operationen

---
#### Quiz  Verkettete Listen I
>[!question] Frage
>Welche Integer-Werte werden in `LinkedList<int> L` in der obigen Speichersituation gespeichert, falls `&L.head_ == 11` gilt?
>```cpp
>template <typename U> struct Node {
>	U cont_: //speichert das Datenelement
>	Note* next_: // Zeiger auf den nächsten Knoten
>	
>	Node(U const& x) : cont_{x}, next_{nullptr} {}
>}
>
––––––––––
>
>template <typename T>
>class LinkedList {
>	Node<T>* head; // Beginn der Liste
>	// ...
>}
>```
>![[Pasted image 20251216124348.png]]
>	**⤷ D \[$5, 2, 1, 3$\]**
>___
>![[Pasted image 20251229174045.png]]

#### Quiz verkettete Listen II
>[!question] Frage
>Welcher Zeiger aus dem obigen Bild einer verketteten Liste werden durch `push_front(2)` verändert?
![[Pasted image 20251216124908.png]]
	>**⤷ E: keiner**

#### Quiz Verkettete Listen III
>[!question] Frage
>Wo werden beim Aufruf von `push_front(x)` kopien von x erzeugt?
>```cpp
>template <typename T> class Node {
>	public:
>		T cont_; // eigentlicher Inhalt des Knotens
>		Node* next_; // Zeiger auf den nächsten Knoten
>		Node(T const& x) : cont_{x}, next_{nullptr} {}
>};
>
>template <typename T> class LinkedList {
>	public:
>		void push_front(T const& x) {
>			Node<T>* = new_node<T>(x); // erzeuge neuen Knoten mit Inhalt x 
>			if (head_ == nullptr) last_ = new_node; // Liste ist leer => setze last_
>			new_node->next_ = head_; // der neue Knoten zeig auf den bisher ersten ...
>			head = new_node; // ... und ist der neue erste Knoten
>		}
>	// ...
>}
>```
>**⤷ B: Zeile 5**

---

## Inplementierung der *get_size()*-Methode

- für `int get_size()` könnte einfach über die Liste iteriert (bis *next_* auf *nullptr*  zeigt) und mitgezählt werden
	⤷ ist *möglich*, *aber* **langsam**

- besser: füge **Membervariable** `size_` hinzu und führe über sie Buch
	- bei allen *Einfüge-Löschoperationen* `size_` *inkre-/dekrementieren*
	- dann: `int get_size() const { return size_; }`

---
## Sinnvolle Ergänzung zu Verketteten Listen

Kommuniziere Zeiger (auf Knoten von Typ Node\<T\>) in die Außenwelt. `const`-Zeiger erlauben z.B., "von außen" über die Liste zu **iterieren**:
```cpp
Node<T> const* Node<T>::begin() const { return head_; }
// ...

// in main(): iterate forward over the linked list my_ll:
for (Node<string> const* current = my_ll.begin(); current != nullptr; current = current->next_) {
	// do something with current->cont_, e.g. print it
}
```

Oder non-`const`-Zeiger:
```cpp
// find s in LL and return pointer to node:
Node<T>* find(T const& s) const { ... }
```
```cpp
// insert new node with contents s after node where:
void insert_after(Node<T>* where, T const& s) { ... }
```

In der **STL** wird dies *über iterationen durchgesetzt* (letztendlich eine Kapselung von Zeigern!)


![[Pasted image 20251229175506.png]]

___

>[!question] Quiz: Copy-Konstructor für Linked Lists
>```cpp
>LinkedList(LinkedList const& other) : head_{nullptr}, size_{0}, last_{nullptr} {
>for (Node<T>* current = other.head_;
>			current != nullptr;
>			current = current->next__) {
>		push_back(current-> cont_);
>	}
>}
>```
>___
>Was ist ein richtiger Copy-Konstruktor für die LinkedList?
>___
>___
>**\[A: mit push_back\] $\checkmark$**
>*\[B: mit push_front\]*
>___
>![[Pasted image 20251229180719.png]]

___

## Vergleich ***Arrays, ResizableArrays*** und ***Verkettete Listen***

|                         | **C-Arrays**     | **Resizable Arrays** | **Verkettete Listen** |
| ----------------------- | ---------------- | -------------------- | --------------------- |
| optimaler Speicherplatz | **$\checkmark$** | ***$\times$***       | ***$\times$***        |
| Cache-freundlich        | **$\checkmark$** | **$\checkmark$**     | ***$\times$***        |
| vergrößern möglich      | ***$\times$***   | (**$\checkmark$**)   | **$\checkmark$**      |
| Ein-/Anfügen effizient  | –                | (**$\checkmark$**)   | **$\checkmark$**      |
| Einfügen in der Mitte   | –                | ***$\times$***       | **$\checkmark$**      |
| Indexoperator effizient | **$\checkmark$** | **$\checkmark$**     | ***$\times$***        |
| lineare Suche möglich   | **$\checkmark$** | **$\checkmark$**     | **$\checkmark$**      |
| binäre Suche möglich    | **$\checkmark$** | **$\checkmark$**     | ***$\times$***        |
