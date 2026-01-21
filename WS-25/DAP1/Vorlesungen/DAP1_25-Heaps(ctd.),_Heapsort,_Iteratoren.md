#dap1 

# Heaps und Priority Queues

## ADT Priority Queue ("Prioritätswarteschlange")

Eine ***Prioritätswarteschlange*** (engl. priority queue, "PQ") mit Schlüsseln vom Typ $K$ und Werten vom Typ $V$ hat folgende Operationen:

- **`init`**: *initialisiert* eine *leere PQ* mit Namen $Q$ für bis zu $N$ viele key-value-Paare vom Typ $(K,V)$
- **`push`**: *fügt* den Wert $x$ (vom Typ $V$) mit Schlüssel $k$ (vom Typ $K$) in $Q$ ein, *falls die Kapazität noch nicht erschöpft ist*
- **`extract_min`**: *löscht* ein *key-value-Paar* $(k,x)$ mit *minimalem Schlüsselwert* aus der PQ und *gibt dessen Wert zurück*
- **`is_empty`**: *gibt wahr zurück* gdw. $Q$ *leer* ist
- **`size`**: *gibt die Anzahl* der *key-value-Paare* in $Q$ zurück

Wie eine *Queue*, aber `pop` liefert die Elemente *aufsteigend geordnet* nach **"Priorität"**
analog: *Maximum-PQs* (absteigend geordnet)

___

## Heaps

ein **Min-Heap** (dt. Haufen/Halde) ist ein *binärer Baum* für $n$ *key-value-Paare* mit den **2** folgenden *Eigenschaften*:

1. ***Heap-Ordnung***: *der Schlüssel aller Knoten $v$* (außer der Wurzel) ist *nicht größer* als *der Schlüssel ihres Vaters*
2. ***Vollständigkeit***: der **Baum $B$ ist vollständig**, d.h. *alle Tiefen* (bis auf die letzte) sind *voll besetzt*, und *die letzte Tiefe* ist ***"von links nach rechts" besetzt***

**Konsequenz:** ***minimaler Schlüssel an Wurzel***
*Heaps haben eine Höhe von* $O(\log n)$

![[Pasted image 20260122004528.png]]
![[Pasted image 20260122004558.png]]

___

## Array-Darstellung von Heaps

![[Pasted image 20260122004700.png]]

**"implizite Datenstruktur"**
- *Elter* von Knoten an Position $k$: $\lfloor k/2 \rfloor$
- *Kinder* von $i$ an Positionen $2k$ und $2k+1$ (falls vorhanden, d.h. $2i \leq n$)

___

## Heap-Implementierung

```cpp
namespace dap1 {
template <typename K, typename V>
class PQ {
  struct KVPair { // private "innere Klasse"
    K key_;
    V value_;

    KVPair(K const& key = {}, V const& val = {}) : key_{key}, value_{val} {}

    // implement operators to use keys:
    bool operator<(KVPair const& other) const { return key_ < other.key_; }
    bool operator==(KVPair const& other) const { return key_ == other.key_; }
  };

  KVPair* array_;
  int n_;

  // ...
};
}
```

⤷ **NB:** `KVPair` ist eine ***innere Klasse*** von `PQ` (ansonsten wie bei Map)
	⤷ d.h. kann *nur innerhalb von* `PQ` benutzt werden
	⤷ ist *generisch* (Typen $U,V$), aber *innerhalb von* `PQ ohne Template-Parameter benutzbar* (`KVPair` und nicht `KVPair<U,V>`)

___
## Heap-Operationen

durch *die Höhe* $O(\log n)$ implementieren *Heaps* den ADT PQ *schnell*:
- `push`: $O(\log n)$
- `extract_min`: $O(\log n)$

![[Pasted image 20260122004917.png]]

___

## PQ-Operationen mit Heaps in C++

```cpp
public:
PQ(int capacity) : array_{new KVPair[capacity + 1]}, n_{0} {} // Konstruktor

public:
void push(K const& k, V const& v) {
  // erzeuge "neuen Knoten" als neues letztes Blatt:
  array_[++n_] = KVPair(k, v);
  // jetzt Heap-Bedingung wiederherstellen:
  sift_up(n_);
}
private:
void sift_up(int k) {
  while (k > 1 && array_[k] < array_[k / 2]) {
    swap(k, k / 2);
    k = k / 2;
  }
}

public:
V extract_min() {
  KVPair result = array_[1];
  array_[1] = array_[n_];
  --n_;
  sift_down(1); // vertausche nach unten, bis Heap-Bed gilt
  return result.value_;
}
private:
void sift_down(int k) {
  while (2 * k < n_) {
    int j = 2 * k;                   // left child of k
    if (j < n_ - 1 && array_[j + 1] < array_[j])
      ++j;               // goto right child if smaller
    if (array_[k] <= array_[j]) return;
    swap(k, j);
    k = j; // continue at child
  }
}

// swap array_[i] with array_[j]
void swap(int i, int j) {
  T tmp = array_[i];
  array_[i] = array_[j];
  array_[j] = tmp;
}
```

___

## Sortieren mit PQs/Heaps

füge *alle Paare* in eine Min-PQ ein und *lösche sie anschließend* in *aufsteigend sortierter Reihenfolge*, z.B. *sortiere Studierende* nach Matr.-Nummern:

```cpp
int n = 100;
dap1::PQ<int, Stud> pq(n);

std::random_device rd; // create 100 students with random id (just testing)
for (int i = 0; i < n; ++i) {
  int nr = rd() % 1000000;
  pq.push(nr, Stud{nr, 25, 'd'});
}

Stud* sorted_students = new Stud[n];   // hier werden die Stud. sortiert eingefügt
int i = 0;
while (!pq.is_empty()) {
  Stud minimum = pq.extract_min();
  sorted_students[i++] = minimum;
}
```

Da *die Höhe* des entstehenden Heaps *max.* $O(\log n)$ ist, *sortiert Heap-Sort* ein *Array der Länge* $n$ mit $O(n \log n)$ Operationen.

___

# Iteratoren

## Iteratoren

Die **C++-STL** hat (wie viele Programmiersprachen) ein ***Iteratorenkonzept*** für *Container*

- ***Container***: *generische Datenstrukturen* zum *Speichern einer Sammlung von Objekten* (z.B. `ResizableArray<T>`, `MyStack<T>`, `BST<T>`, …)

Zugriff auf die einzelnen Objekte bisher:

- mit `[]` in `MyArray<T>`, `ResizableArray<T>`, `Map<K,V>`
- mit `pop()` in `MyStack<T>`
- usw.

**Iteratoren**: *einheitliche Schnittstelle* zum *Zugriff auf alle Objekte* des Containers:

- mit `begin()` erhält man das *erste Element*, `end()` zeigt auf das *Element direkt nach dem letzten*
- `++` geht zum *nächsten Element*
- `*` *dereferenziert* das Element, d.h. *gibt eine Referenz auf ein T-Objekt zurück*
- `!=` *vergleicht* 2 Iteratoren

___

## Am Beispiel von Heaps

```cpp
template <typename T> class PQ {
  T* array_;
  int n_;

public:
  class Iterator {   // an iterator for pq
    T* arr_;
    int current_;

  public:
    Iterator(T* arr = nullptr, int i = 0) : arr_{arr}, current_{i} {}

    T& operator*() {
      return arr_[current_];    // reference to element
    }

    Iterator& operator++() {
      ++current_;
      return *this;
    }
    bool operator!=(Iterator const& p) {
      return arr_ != p.arr_ || current_ != p.current_;
    }
  };

  Iterator begin() { return Iterator(array_, 1); }
  Iterator end() { return Iterator(array_, n_ + 1); }
  // ...
};

int main() {
  int n = 100;

  dap1::PQ<int> pq(n);

  for (int i = 0; i < n; ++i) pq.push(rand() % 100);

  for (dap1::PQ<int>::Iterator it = pq.begin(); it != pq.end(); ++it) {
    printf("%i,", *it);
  }
  printf("\n");

  // äquivalent mit "range based for":
  for (int i : pq) { // wird übersetzt wie oben
    printf("%i,", i);
  }
  printf("\n");
}
```

___

## Am Beispiel von Linked List

```cpp
template <typename T>
class LinkedList {
  Node<T>* head_; // Zeiger auf den Anfang der LL
  Node<T>* last_; // Zeiger auf das Ende der LL
  int size_;       // Anzahl der Elemente in LL

public:
  class Iterator { // an iterator for LL
    Node<T>* current_;

  public:
    Iterator(Node<T>* c = nullptr) : current_{c} {}

    T& operator*() {
      return current_->cont_;   // reference to element
    }

    Iterator& operator++() {
      current_ = current_->next_;
      return *this;
    }

    bool operator!=(Iterator const& p) { return current_ != p.current_; }
  };
  Iterator begin() { return Iterator(head_); }
  Iterator end() { return Iterator(nullptr); } // correct since last_->next = nullptr

  // ...
};
```

⤷ **NB:** *alle Aspekte rund um* `const` *hier nicht beachtet*

___

## Iterator für ResizableArray

(s. VSCode für die const-Variante)