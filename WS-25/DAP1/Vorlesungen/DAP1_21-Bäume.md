#dap1 

## Mengen

>[!example] Beispiel
>Wörterbuch der deutschen Sprache zur Rechtschreibkorrektur, aber mit Einfügen (z.B. neue, unbekannte Wörter). Ziele:
>- Muss Einfügungen (und Löschungen) "schnell" ermöglichen 
>- Muss "schnell" durchsucht werden können

⤷ teilweise kennen wir bereits Datenstrukturen :
- nur Einfügungen: resizable Arrays oder verkettete Listen
	- schnelles Einfügen durch `push_back`
- nur schnelles Durchsuchen: sortierte (resizable) [[Arrays]] 
	- schnelle Suche mit binärer Suche

	⤷ schnelles Löschen hängt mit schnellem Suchen zusammen
	- zu löschendes Element muss zunächst gefunden werden

⤷ Eine ***Menge*** (eng. *set*) über Objekte vom Typ $T$ hat folgende Operationen

- ` init(set_name, T) `: **initialisiert** eine *leere Menge* für Elemente vom Typ $T$

- ` insert(set_name, x) `: **fügt** das *Element $x$* (vom Typ $T$) **in die Menge ein**, falls noch nicht in `set_name` vorhanden

- ` erase(set_name, x) `: **löscht** das *Element $x$* (vom Typ $T$) in die Menge ein, falls noch nicht in `set_name` vorhanden

- ` find(set_name, x) `: gibt **wahr** zurück, *wenn $x$ in der Menge* ist 

- ` is_empty(set_name) `: gibt **wahr** zurück, wenn die *Menge leer* ist 

> [!question]
> Welche der folgenden Aussagen sind richtig?
> ___
> **\[A: Mengen lassen sich mit ResizableArrays implementieren\]**
> **\[B: Mengen lassen sich mit verketteten Listen (VKs) implementieren\]**
> *\[C: Mengen lassen sich mit VKs implementieren und das `Suchen` ist effizient\]* 
> *\[D: Mengen lassen sich mit VKs implementieren und das `Löschen` ist effizient\]* 

___

## Suchbaumknoten

``` cpp
// node class (doubly linked list):
template <typename T> struct Node {
	Node(T const& s) : prev_{nullptr}, cont_{s},
		next_{nullptr} {}
		
	Node* prev_;
	T const_;
	Node* next_;	
};
```
``` cpp
// node class (binary search tree):
template <typename T> struct BSTNode {
	BSTNode(T const& x) : prev_{nullptr}, cont_{s}, 
		next_{nullptr} {}
		
	BSTNode* left_;
	T cont_;
	BSTNode* right_;
};
```

___

## Bäume

- ***Nomenklatur Knoten:***
	- *Elter* (wer auf mich zeigt)
	- *Kinder* (auf wen ich zeige)
	- *interner Knoten* (min. 1 Kind)
	- *Blatt* (keine Kinder)
	- (Geschwister)

>[!TIP] **Definition** Bäume
>Ein (gewurzelter) **Baum $B$** ist eine Sammlung von *Knoten* und *Zeigern* (Verbindungen zwischen Knoten) mit den folgenden *Eigenschaften*
>
>- Falls $B$ nicht leer ist, gibt es genau einen Knoten, der keinen Elternknoten hat (die *Wurzel* von $B$)
>
>- Jeder andere Knoten hat genau einen Elternknoten
>
>- ***TODO***

___

#### Bäume in der Realwelt

- Stammbäume
- Verzeichnisbäume
- Organigramme
- Sportturniere

![[Pasted image 20260106125348.png]]

___

## Binäre Suchbäume

Ein **Teilbaum** $B_{v}$ eines Knotens $v$ besteht aus allen Knoten, die mit beliebig vielen (auch 0) Zeigern von $v$ aus *erreicht werden* können.

Die in den Knoten in ` cont_ ` *gespeicherten Werte* heißen **Schlüssel**.

>[!TIP] **Definition** Binäre Suchbäume
>- Jeder knoten hat *maximal 2 Kinder*, die mit ` left_ ` und ` right_ ` bezeichnet werden.
>- Der Schlüssel (` T cont_ `) in *jedem* Knoten $v$ ist *größer* als alle Schlüssel im lingen Teilbaum $B_{\text{left\_}}$ und *kleiner* als alle Schlüssel im Rechten Teilbaum $B_{\text{right\_}}$.

___
#### Tiefe & Höhe

- ***Knotentiefe*** von $v$: *Anzahl der Kanten* (Zeiger `left_` und `right_`) auf dem Wurzel-zu-$v$-Pfad
	- **Wurzel** hat die Teife $0$
	- Definition **Baumtiefe**: *Maximum aller Knotentiefen*
	- Baumtiefe = Baumhöhe

- **Obacht:** Bei Knoten sind Tiefe und Höhe unterschiedlich definiert:
	- **Knotenhöhe** von $v$: Höhe des in $v$ gewurzelten Teilbaums

___

>[!question] Quiz Binärer Suchbaum ` BST<dap1::MyString> `
>![[Pasted image 20260106131027.png]]
>___
>Welche der folgenden Aussagen sind richtig?
>1. Der Baum hat die Höhe $5$. **$\checkmark$**
>2. "ZUM" wäre rechtes Kind von "ZIG". *$\times$*
>3. Das linke Kind von "ENG" ist "EIN". **$\checkmark$**
>4. "EIN" ist ein Blatt. **$\checkmark$**
>5. Die Wurzel ist "WOK". **$\checkmark$**
>6. Der Elter von "WWW" ist "ZOO" *$\times$*

___
## Höhe eines Baums

***Def. Höhe/Tiefe eines Baums:*** maximale Länge (**#Kanten**) aller Wurzel-zu-Blatt-Pfade
⤷ **Einfüge-/Suchzeit** davon *abhängig!*

***Rekursive Definition***
- Ein **leerer Baum** hat die *Höhe $-1$*.
- Die Höhe eines **nichtleeren Baums** mit Wurzel ist *eins mehr* als das *Maximum der Höhe* des *linken* und *rechten Teilbaum*s der Wurzel:

``` cpp
int get_height(BSTNode<T>* node) {
	if (node == nullptr) return -1; // leerer
									// (Teil)baum
	// 1. rekursiver Aufruf
	int linke_TB_Hoehe = get_height(node->left_);
	// 2. rekursiver Aufruf
	int rechte_TB_Hoehe = get_height(node->right_);
	
	if (linke_TB_Hoehe > rechte_TB_Hoehe) return 
		linke_TB_Hoehe + 1;
	else return rechte_TB_Hoehe + 1:
}
```

___

>[!question] Quiz
>Wenn alle Wörter in (alphabetisch) sortierter Reihenfolge eingefügt werden, dann führt dies mit hoher Wahrscheinlichkeit zu einer größeren Baumtiefe, als wenn man sie in zufälliger Reihenfolge einfügen würde.
>**\[A: wahr\] $\checkmark$**
>*\[B: falsch\]*
>*\[C: kann man nicht sagen\]*

___

#### Code zur Bestimmung der Höhe
```cpp
public:
	// return height of tree
	int getHeight() const { return getHeight(root_); }
	
private:
	// recursion
	int hetHeight(BSTNode<T>* current) const {
		if (current == nullptr) return -1; // height of empty BST 
		int lHeight = getHeight(curent->left_) + 1; // left subtree
		int rHeight = getHeight(current->right_) + 1; // right subtree
		return lHeight > rHeight ? lHeight : rHeight
	}
```
![[Pasted image 20260106133120.png]]

___

## [[Rekursion]]

Funktionen können *sich selbst aufrufen* ("**rekursive Funktionen**")
- in jedem Funktionsaufruf *neue lokale Variablen* (auch die Rückgabewerte!)
- Rückgabewerte werden (wie gewohnt) vom Aufrufer verarbeitet

- WICHTIG **Abbruchbedingung** für *Basisfall*/*Basisfälle*, damit die Rekursion endet
	- z.B. ` if (node == nullptr) return -1; `

![[Pasted image 20260106133506.png]]
