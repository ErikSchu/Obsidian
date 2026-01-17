
  #dap1

>[!note] **Asserts**
>- mit `#include <cassert>` werden **Funktionen zum Überprüfen der Programmkorrrektheit** eingebunden
>- damit aufrufe wie `assert(x>=5 && x<=10);` möglich
>	- im Prinzip `if(!(x>=5 && x <= 10)) { schreibe Fehlermeldung und beende Programm }`
>- manchmal nützlich zum **debuggen**
>	- man kann die Asserts im Code lassen und mit `#define  NDEBUG` vor `#include <cassert>` einfach deaktivieren

---
## Generische Programmierung

- Viele Funktionen sollten für untersch. Datentypen existieren

- Generell könne Funktionen mit dem gleichen Namen und unterschiedlichen Signaturen existieren → **Polymorphie**
	-  `int find(array[], int length, int x)` und
	- `int find(double array[], int length, dpuble x)`

- Statt den Code zu kopieren und nur den Datentyp zu ändern, bietet C++ einen Mechanismus zur **Templatisierung von Funktionen** an:

``` c++
// lineare Suche: suche Element x vom Typ T in array[0,length-1]
// vom Typ T:
template <templatename T>
int find(T const array[], int length, T x) {
	for (int i = 0; i < length; ++i) {
		// definierter Gleichheitsoperator wichtig
		if (array[i] == x) return x; 
	}
	return -1;
}
```

---
---
## Sortieren von [[Arrays]]

#### Einfaches Sortierverfahren: [[Selection Sort]]

>[!note] Problem
>**Eingabe:** Ein Array$[0, n-1]$ (mite Elementen auf denen eine totale Ordnung Existiert, z.B. `int`, `double`)
>**Aufgabe:** Sortiere das Array, z.B. in aufsteigender Reihenfolge

- *Algorithmische Idee:*
	**1.** Setze $i \leftarrow 0$
	**2.** wiederhole, solange $i < n$ :
		**2.1.**  finde das Minimum in `Array[i, n-1]`: sei $j$ die Position dieses Minimums
		**2.2.**  vertaische `Array[i]` mit `Array[j]` - nun enthält `Array[0, i]` die kleinsten Werte im Array in sortierter Reihenfolge
		**2.3.**  erhöhe $i$ um 1

```cpp
int min_pos(int a[], int n, int j) {
	int min_pos_so_far = j;
	for (int i = j +1; i < n; ++i) {
		if (a[i] < a[min_pos_so_far]) min_pos_so_far = i;
	}
	return min_pos_so_far;
}

void sort(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		int j = min_pos(array, length, i) // Minimum im Array 
		
		//swap array[i] with array[j]:
		int tmp = array[i]; // Sicherung Wert array[i]
		array[i] = array[j]; // Überschreiben
		array[j] = temp; // ürsprüngliches array[i] nach array[j]
	}
}
```
⤷ **Laufzeit (hier Anzahl der Vergleiche mit x):** $$(n-1)+(n-2)+(n-3)+\dots+1 = \sum_{n-1}^i i = \frac{(n-1)n}{2}= \ \ \ \ \ \ \frac{n^2-n}{2}$$

---

## Laufzeitanalyse

- wir haben uns bis jeztt die Frage nach der Anzahl der *Vergleichsoperatoren* gestellt

- hierbei handelt es sich um eine Anweiszbgm die sich zur Analyse der *Laufzeit des Gesamtprogramms* eignet
	- Laufzeit wird hier mit der **Anzahö der Word-RAM-Operationen** gleichgesetzt (#Schritte)
	- pro Vergleichopseration werden (bei Selection Sort) maximal konstant viele andere elementare Word-RAM-Operationen ausgeführt
		- z.B. *Zuweisungen* (`min_pos_so_far = 1`), *Erhöhung von Zählern* (`++i`), weitere *Vergleiche* (`i < length`), *Sprünge* (versteckt bei den Wiederholungsanweisungen / bedingten Anweisungen)
	- da Selection Sort $\frac{n^2-n}{2}$ viele Vergleichsoperationen macht, macht der gesamte Algorithmus C mak so viele Schritte (Für eine Konstante C, die uns nicht näher interessiert).

> [!TIP] Operationsanzahl
>  Selection-Sort sortiert ein Array der Länge $n$ mit $C \cdot n^2$ Operationen (für eine nicht näher bestimmte Konstnatne $C$).


#### Short Circuit Evaluation 

- im Ausdruck `a && b`  wird der Ausdruck b nur ausgewertet, falls die Auswertung von a den Wert *true* (eigentlich einen Wert  ≠ 0) ergibt, da andernfalls Ergebnis schon vogher sicher *false*

- Analog: Im Ausdruck `b || b` wird der Ausdruck b nur ausgewertet, dalls die Auswertung bon a den Wert *false* (0) ergibt, da andernfalls Ergebnis schon sicher true
## Schnelleres Sortierverfahren: Mergesort

>[!note] Problem
>**Eingabe:** Ein Array$[0, n-1]$ (mite Elementen auf denen eine totale Ordnung Existiert, z.B. `int`, `double`)
>**Aufgabe:** Sortiere das Array, z.B. in aufsteigender Reihenfolge

- Algorithmische Idee:
	- Das Verschmelzen ("**"Mergen"**) zweier (aufsteigend) sortierter Arrays `a [ 0, l - 1 ]` und b\[ b, 0 - l \] isr leicht: 

>
>1. `left` , `right` 
>2. Allokiere ein Array `c` der Größe ; setze `idx`  (`c` enthält später das verschmolzene=sortierte Ergebnis)
>3. Solange `left` <  und `right` < :
    1. kopiere das **Minimum** aus `a[left]` und `b[right]` nach `c[idx]`
    2. erhöhe `idx` und `left/right` (je nachdem, wo was Minimum war) jeweils um 1
>3. kopiere die verbliebenen Elemente aus `a` oder `b` an das Ende von `c`
>

![[Pasted image 20251125122240.png]]

#### Laufzeitanalyse Mergen

- Die Frage auf der vorherigen Folie wurde so gestellt, da die Anzahl der Zuweisungen nach c  die Gesamtzahl der ausgeführten Operationen bestimmt: 
	- in beiden Wiederholungsanweisung**en** (`for` bzw. `while`) wird jede Zuweisung von konstant vielen anderen Word-RAM-Operationen "begleitet"
- Daher eignet sich diese Anzahl für folgende Aussage über die Anzahö der insgesamt durchgeführten Operationen:

> [!TIP] Operationsanzahl
>  Der Merge-Algorithmus berechnet aus 2 jewails $l$- langen sortierten Arrays ein sortiertes Gesamtarray der Länge $2l$ mit insgesamt $C \cdot l$ Operationen (für eine nicht näher bestimmte Konstante C).

**Implementieungsdetails**
- Zum Aufruf der Funktion `merge` nutzen wir die *Pointerarithmetik*:
	- `array` + `start` isit die Anfangsadresse von `array[start]`
	- das gleiche wie `&array[start]`
- Das "temporäre" Array `c[]` muss nicht vollständig neu allokiert und gelöscht werden
- da das (jeweils pro Level) letzte Teilarray aus dem Gesamtarray "herausfallen kann", erweitern wir merge um einen weiteren Parameter 1_b und nennen 1 in 1_a um.
``` cpp
// mrege a[0, 1_a+1] with b[9, 1_b-1], both of which are sorted and store result in c[0, 1_a+1, 1_b-1]
void merge (int const a[], int const b[], int 1_a, int 1_b) { ... }
```
