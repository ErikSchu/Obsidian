#dap2

# Sortieren in linearer Zeit
##### Vergleichsbasierte Sortieralgorithmen
... benötigen $\boxed{\Omega  ( n \log n)}$ Vergleiche. Der Vorteil davon ist die **allgemeine Anwendbarkeit**.

## Sortieren vie Zählen. 
Gegeben sei ein Array $\mathbf{A} = (A_{1}, \dots, A_{n})$. Jedes Arrayelement ist mit einem **Schlüssel** Aus der menge $\mathcal S = \{ s_{1}, \dots, s_{n} \}$ versehen. Diese Schlüssel sind *vergleichbar*.
Die Arrayelemente sollen anhand der Schlüssel sortiert werden.
A
>[!def] `CountingSort(A)`
>1. Lege ein Hilfsarray $C = (C_{1}, \dots, C_{k})$ an, sodass $C_{i}$ die Zahl der Vorkommnisse von $s_{i}$ in $A$ enthält 
>2. Verwende das Hilfsarray, um die Gesamtzahlen $C'_{i}$ der Elemente mit Schlüsselm $s_{1}, \dots, s_{i}$ zu bestimmen.
>3. Reserviere Speicherplatz $\mathbf{B} = (B_{1}, \dots, B_{n})$ für das Ausgabearray
>4. Für j = n, ..., 1
>	1. ermittle den Schlüssel $\sigma$ von $A_{j}$
>	2. setze $B_{C'_{\sigma}} = A_{j}$
>	3. verringere $C'_{\sigma}$ um $1$

#### → Analyse
- Sortiert in Zeit $\boxed{O(n)+O(k)}$
- wenn $k = o(n \log n)$, ist `CountingSort` also *schneller als vergleichsbasierte Sortieralgorithmen*
- `CountingSort` ist ein **stabiler** Sortieralgorithmus (d.h. Elemente mit dem selben Schlüssel werden in ihrer *ursprünglichen Reihenfolge* ausgegeben)
	- die Stabilität wird dadurch sichergestellt, dass $Schritt \ 4$ die Elemente von hinten nach vorne durchgeht

___

## Radixsort 
Wir nehmen an, dass die Eingabeelemente mit einer Folge von $d$ Schlüsseln aus $\mathcal S$ versehen sind. 
**Beispiel:** Zahlen- oder Buchstabenfolge fester Längen
	direktes Anwenden von `CountingSort` benötigt $O(n) + O(k^d)$

>[!def] `RadixSort(A)`
>1. für $i = d, ..., 1$
>	1. sortiere $\mathbf{A}$ nach der $i$-ten Komponente des Schlüssels mit `CountingSort`

#### → Analyse
- funktioniet korrekt, da `CountingSort` **stabil**
- Laufzeit ist $\boxed{O(d\cdot n) + O(d \cdot k)}$
	- deutliche Verbesserung schon für moderate $d, k$

