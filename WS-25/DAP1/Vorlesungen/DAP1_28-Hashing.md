#dap1
## Wdh.: der [[DAP1_21-Bäume|Mengen-ADT]] 

***Bisherige Lösung:*** Binärer Suchbaum (*vergleichsbasiert*!)
	***jetzt:*** direkt mit den **Werten** *der Schlüssel* arbeiten

## Hashing
Annahme $T$ = `int` 

>[!TIP] Idee
>hätten wir ein Array $H$ der Größe ` INT_MAX `, könnten wir ein Element $x$ in $H[x]$ speichern
- das ist unrealistisch ...

- daher ***Hashfunktion*** $h :$ `int->[0, m - 1]` $= \{ 0, 1, \dots, m-1 \}$ für einen **nicht zu großen** Wert $m$ ($m$ ist die *Größe* der Hashtabelle)
- dann ` insert(set_namem x) ` :  füge $x$ in $H[h(x)]$ ein 


#### Kollision

Anforderungen an die Hashfunktion $h$:
- soll mögl. *gleichmäßig* übre $[0, m-1]$ **streuen**
- soll mögl. **zufällig** sein 
- wir nutzen: $h(x) = ((a \cdot x) \text{ mod } p) \text{ mod } m$ für eine Primzahl $p \ge m$ und ein zufälliges $a \in [1, p-1]$

Trotzdem: ***Kollisionen** unvermeidbar* $(h(x) = h(y) \text{ für } x \ne y)$

Was ist, wenn in $H[h(x)]$ bereits ein Element steht?
- ***Linear Probing:*** wenn die Stelle $h(x)$ bereits belegt, dann gehe so lange nach 'rechts' ($h(x)+1, h(x)+2, \dots$), bis eine freie Stelle erreicht wird

Wir nutze ein zsl. `bool`-Array ` Used[0, m - 1] `, um belegte Stellen zu markieren

![[Pasted image 20260129143215.png]]


##### Implementierungstrick

Um bei dem **linear Probing** nicht immer '$\text{mod } n$' rechnen zu müssen, kann die Hashtabelle einen ***Overflow-Buffer*** erweitert werden.
- z.B. 1% der Gesamtgröße
- im Code ` overflow_buffer_size_ `


>[!note] Einfügen mit linear Pobing
>- ` insert(set_name,x): `
>	- berechne $p \leftarrow h(x) \in [ 0, m-1 ]$
>	- solange $H[p]$ belegt:
>		- inkrementiere $p$ um $1$
>		- falls $p == m$:
>			- $p \leftarrow 0$
>```cpp
>// operator[] for put:
>V& operator[](K const& key) {
>	int pos = hash(key);
>	while (used_[pos] && array_[pos].key_ != key) {
>		++pos;
>		if (pos == m) pos = 0;
>	}
>	if (!used_[pos]) {
>		array_[pos].key_ = key; // store key if insert
>		used_[pos] = true;
>		++n_;
>	}
>	return array_[pos].value_;
>}
>```


## Generische Hashtabelle: C++ 

Die **Hashtabelle** soll ***templatisiert*** über `<K,V>` sein 
	aber Hastfunktion vom Typ $K$ abh.
		hierfür bieten sich **Template-Spezialisierungen** an

```cpp
template <typename K>
int hash_value(K const& x, int m); // generische Funktionsdeklaration

unsigned int const p = (1u << 31) - 1; // Mersenne prime
unsigned int const a = rand() % (p - 1) + 1;
template <> int hash_value<int>(int const& x, int m) {
	return (a * x) % p % m;
}

int const p_str = 257
int const a_str = rand() % (p_str - 1) +1;
template<> int hash_value<MyString>(MyString const& x, int m) {
	int result = a_str;
	for (char c : x) result = (result * p_str + x) % m;
	return result;
}

// Implements a hast table with linear probing
template <tyename K, typename V> class HashMap {
	// ...
	private:
		int hash(K const& x) const { return hash_value(x, m_); }
};
```

