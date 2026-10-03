#dap2 **12.05.2026**

⤷ effizient und deterministisch

>[!def] Heaps
>- Datenstruktur in i.F.v. einem **gewurzelten Baum** 
>- **Knoten** von $1$ bis $n$ durchnumeriert
>- $1.$ Knoten ist die **Wurzel**
>- **Kinder von Knotnen $i$** siind *$2i$* und *$2i+1$*, (falls diese werte $\le n$)
>- jeder Knoten hat **höchstens zwei Kinder**
>- der **Elternknoten von $i \ge 2$** ist *$\left\lfloor  \frac{i}{2}  \right\rfloor$*

>[!example] Beispiel
>Heap mit 6 Knoten und Knoten 1 als Wurzel
>![[Pasted image 20260521141740.png]]

#### Repräsentation im Speicher
- Darstellung als ***Array*** $A = (A_{1}, \dots, ,A_{n})$ der Länge $n$
- **Indizierung** der Eltern / Kinder mit den Seicherstellen des Arrays identifiziert

### Max-Heaps (unt Min-Heaps)
- in den Knoten des Heaps speichern wir *vergleichbare Werte*
- ein ***Max-Heap*** hat die Eigeschaft, dass der Wert eines Kindknotens **niemals größer** ist als der Wert des Elternknotens
- ein ***Min-Heap*** hat die Eigeschaft, dass der Wert eines Kindknotens **niemals kleiner** ist als der Wert des Elternknotens
	  werden im Folgenden nicht weiter betrachtet

#### Erzeugen eines Max-Heaps
- ***Aufgabe:*** ein Array $A = (A_{1}, \dots, A_{n})$ soll in einen Max-Heap überführt werden
- `BuildMaxHeap(A)` löst das Problem
- *Hilfsfunktion* `MaxHeapify(A, i)`: die Nachkommen von Knoten $i$ sind bereits Max-Heaps, aber möglicherweise ist der Wert $A_{i}$ kleiner als der Wert eines Kindes

>[!note] `MaxHeapify(A, i)`
>1. Falls $A_{i}$ nicht kleiner als seie Kinder (oder kein Kind vorhanden), halte.
>2. Sonst bestimme das größere Kind $A_{j}$
>3. Vertausche die Werte $A_{i}, A_{j}$
>4. `MaxHeapify(A,j)`

>[!tip] Definition
>Die ***Höhe*** eines Knotens $i$ ist der maximale direkte Abstand von einem Blatt

>[!tip] Lemma
>Die Höhe der Wurzel ist ***$O(\log(n))$***.

>[!tip] Proposition
>Wenn der Knoten $i$ Höhe $h$ hat, benötigt `MaxHeapify(A, i)` ***Laufzeit $O(h)$***.

>[!tip] Korollar
>`MaxHeapify` hat ***Laufzeit $O(\log n)$***.


#### Aufbau eines max-heaps aus einem Array
- aus beliebigen gegebenen Array $A$ soll ein max-heap werden
- dazu arbeitet man *"von hinten nach vorne"*
- die letzte hälfte der Einträge werden **in jedem fall Blätter**
- auf die anderen Einträge wenden wir `MaxHeapify` an


>[!note] `BuildMaxHeap(A)`
>1. Für $i = \left\lfloor  \frac{n}{2}  \right\rfloor , \dots, 1$
>2. `MaxHeapify(A, i)`

>[!tip] Proposition
>`BuildMaxHeap` hat ***Laufzeit $O(n)$***


> [!note] `Heapsort(A)`
> 1. `BuildMaxHeap(A)`
> 2. Für $i = n, n-1, \dots, 2$
> 	1. vertausche $A_{1}$ und $A_{i}$
> 	2. `MaxHeapify((A1, ..., Ai - 1), 1)`

>[!tip] Satz
>`Heapsort` sortiert ein gegebenes Array in der ***Zeit $O(n \log n)$***

___

>[!def] Priority queues 
>- max-heaps haben weitere Anwendungen
>- Weitere Operationen:
>	- `extractMax` (findet und) entfernt das maximale Element
>	- `IncreaseKey` erhöht den wert eines Elements
>	- `Insert` fügt ein neues Element mit einem gegebenen Wert ein

>[!note] `ExtractMax(A)`
>1. falls $n = 0$, abbrechen; falls $n = 1$ gib $A_{1}, \emptyset$ aus
>2. vertausche $A_{1}$ und $A_{n}$
>3. `MaxHeapify((A1, ..., An-1), 1)`
>4. gib $A_{n}$ und $(A_{1}, \dots, A_{n-1})$ aus 

>[!note] `IncreaseKey(A, i, a)`
>1. Fallls $a < A_{i}$, brich ab
>2. setze $A_{i} = a$
>3. solange $i > 1$
>	1. setze $j = \left\lfloor  \frac{i}{2}  \right\rfloor$ // j = Elternknoten von $A_{i}$
>	2. falls $A_{j}  \ge a$, halte
>	3. falls $A_{j} < a$, vertausche $A_{j}$ und $a$
>	4. setze $i = j$

>[!note] `Insert(A, a)`
>1. füge ein Element $A_{n+1} = - \infty$ zu $A$ hinzu
>2. wende `IncreaseKey((A1, ..., An+1), n+1, a)` an

>[!tip] Proposition
>Die obigen Operationen haben ***Laufzeit $O (\log n)$***.

