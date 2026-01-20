#dap1 
##### Vorstellung Viper
___

# Suchbäume (und [[Rekursion]])

>[!question] Quiz einfügen ` BST<int> `
>Betrachten Sie den binären Suchbaum links mit $5$ Knoten. Welcher Suchbaum ergibt sich, wenn die Elemente $11,3,i$ in dieser Reihenfolge eingefügt werden?
>___
>![[Pasted image 20260113122415.png]]
>___
>___
>*(a)*   *(b)*   **(c) $\checkmark$** *(d)*

## Einfügen in einen binären Suchbaum

Algorithmische Idee:
- eigentlich wie bei der **Suche** 
- wenn einzufügendes *Element $x$ nicht gefundnen* wurde (wir sind an einem Blatt), erzeuge **neuen Knoten** und setze den *richtigen Zeiger vom Elternknoten*

Kannn **rekursiv** formuliert werden, einfacher ist aber iterativ.

```cpp
// Insert x into this BST:
void insert(T const& x) {
	++size_; // increment size by one
	BSTNode<T>* new_node = new BSTNode<T>(x); // create new node w/ x
	if (!root_) { // tree previously empty => make new node the root
		root_ = new_node;
		return;	
	}
	
	BSTNode<T>*current = root_, *prev = nulllptr;
	bool fo_right; // true if going right, false if going left
	while (current) { // find correct insertion point
		prev = current;
		if (current->cint_ < x) { // x needs to go right
			current = current->right_;
			go_right = false;
		}
		else { // x needs to go left
			current = current->left_;
			go_right = false;
		}
	}
	
	// make correct pointer to the new right node:
	if (go_right) prev->right_=new_node;
	else prev->left_ = new_node
}
```

#### Weitere Aspekte in binären Suchbäumen
⤷ Destruktor, Copy-Konstruktor, Kopierzuweisungsoperator?
	⤷ Schreiben wir den Destruktor

## Kopien 
```cpp
template <typenameT> struct BSTNode {
	// ...
	
	// Kopierkonstruktor:
	BSTNode(BSTNode const& other) : 
		left_{nullptr}, right{nullptr} {
		*this = other; // nutze Kopierzuweisungsoperator
	}
	
	// Kopierzuweisungsoperator kopier den ganzen hier gewurzelten
	// Tilbaum
	NSTNode& operator=(BSTNode const& other) {
		delete left_;
		delete right_;
		if (other.left_) left_ = new BSTNode<T>(*other.left_);
		cont_ = other.cont_;
		if (other.right_)
			right_ = new BSTNode<T>(*other.rigt)
		return *this;
	}
}
```
``` cpp
template <typename T> class BST {
	// ...
	
	// Kopierkonstruktor ruft KopZuwOp auf
	BST(BST const& other) : root_{nullptr} { *this = other; }
	
	// Kopierzuweisungsoperator
	BST& operator=(BST const& other {
		delete root_;
		size_ = other_size_;
		if (other.root_)
			root_ = new BSTNode<T>(*other.root_);
		return *this;
	}
	
	// ...
};
```

___

## Schlüssel und Werte

Oft sind die zu verwaltenden Objekte komplexer:
- ***bisher:*** der **Inhalt** ` const_ ` **definiert** die **Ordnung** (z.B. bei binärer Suche, beim Sortieren, im Binärbaum)
- neben dem ***Schlüssel*** ("keys"; definieren Ordnung) und noch weiteren ***Daten*** ("values")
	- z.B. ` class Stud {public: int matr_nr; string name_}; `

Typische Lösung speichert ***Paare***
```cpp
template <typename U, typename V>
struct KVPair {
	U key_;
	V value_;
	
	KVPair(U key = {}, V val = {}) : key_{key}, value_{val} {}
	
	// Operatoren, die von BST für Schlüssel gebraucht werden
		bool operator<(KVPair const& other) const { return key_ <
			other.key_; }
		bool operator<(KVPair const& other) const { return key_ <
			other.key_; }
};
```

___

## Allgemein: Maps

![[Pasted image 20260120122602.png]]
Eine Map speichert Paare vom Typ ` KVPair<U, V> `, so dass sie über ihren **Schlüssel** 
($\text{Member key\_}$) aufgerufen werden können

___

## Allgemeiner Datentyp Map

>[!note] Eine ***Map*** über *Paare vom Typ ($U,V$)* hat folgende Operationen
>- `init(map_name, u, v)` **initialisiert** eine *leere Map*
>  ___
>- `put(map_name, u, v` *falls kein Eintrag* in der Map $\text{map\_name}$ *mit Schlüssel* $u \in U$ vorhanden ist, **füge Paar $(u,v)$ ein**; ansonsten **überschreibe** den Wert des Paares mit Schlüssel $u$ mit $v \in V$
>  ___
>- `erase(map_name, u)` **löscht** das *Paar mit dem Schlüssel $u \in U$* aus der Menge, falls in $\text{map\_name}$ vorhanden
>  ___
>- `at(map_name, u)` **gibt den Wert** des *Paares mit dem  Schlpssel $u \in U$* **zurück**, falls vorhanden
>  ___
>- `find(map_name, u)` **gibt true zurück** gdw. ein *Paar mit Schlüssel $u \in U$* vorhanden
>  ___
>- `is_empty(map_name)`**gibt true zurück** gdw. die *Map leer* ist
>  ___
>- ... weitere möglich

> [!note] Map auf Basis von [[DAP1_21-Bäume|BST]]
> ![[Pasted image 20260120132817.png]]

## Ergänzung zur Vorlesung

In ` BST.hpp `
- `find` muss Rückgabetyp `BSTNode<T>*` haben (nicht `T*`)
- `find` muss den neu erzeugten Knoten zurückgeben (und hat damit ebenfalls den Rückgabetyp `BSTNode<T>*`)