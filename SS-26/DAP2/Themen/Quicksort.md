*14.04.2026*
#dap2
https://ls2-web.cs.tu-dortmund.de/~mamicoja/dap2/slides/lec_quicksort.pdf

**Ziel:** Eine Liste $L = (l_{1}, \dots, l_{n})$ *vergleichbarer* Elemente aufsteigend sortieren.
	⤷ *Vergleichbarkeit:*
- für je 2 Elemente $l_{i}, l_{n}$ → entweder **<**, **=** oder **>**
- **transitiv:** $l_{h} \le l_{i}$ und $l_{i} \le l_{j} \implies l_{h} \le l_{i}$
- **antisymmetrisch:** $l_{i} \leq l_{j}$ und $l_{j} \leq l_{i} \implies l_{i} = l_{j}$
- Zugriff auf eine **Funktion, die zwei Elemente vergleicht
 
*z.B.:* genze, rationale oder reelle Zahlen mit der gewöhnlichen Ordnung // Zeichenketten in alphabetischer Ordnung, //  Punkte im $\mathbb{R}²$  mit lexikographischer Ordnung // ...

- **Laufzeit** ist hier die *Anzahl der Vergleiche*  → Algorithmus darf dabei Elemente nur miteinander vergelchen ⇒ anwendbar auf beliebige vergleichbare Objekte


>[!TIP] Algorithmus
>1. Für $i = 1, \dots, n$
>	1. falls $l_{i}<l_{1}$, füge $l_{i}$ der Liste *K* hinzu.
>	2. falls $l_{i}>l_{1}$, füge $l_{i}$  der Liste *G* hinzu.
>	3. falls $l_{i}=l_{1}$, füge $l_{i}$  der Liste *M* hinzu.
>2. Wende Quicksort rekursiv an, um *K* und *G* zu sortieren.
>3. Gib *K* , *M* , *G* aus.

⤷ *rekursiv* und nontschalant

___

## Dijkstra's Partitionierungsverfahren 
Partitionierung in einem Array "in place"

>[!note] Dijkastra-Partitionierung
>1. setze $i = j = 0, \  k = n-1$
>2. solange $j \le k$
>	1. falls $A[j] <$ pivot
>		1. vertaische $A[i]$ und $A[j]$
>		2. erhöhe $i$ und $j$ umd $1$
>	2. sonst, wenn $A[j] >$ pivot
>		1. vertausche $A[j]$ und $A[k]$
>		2. verringere $k$ um $1$
>	3. sonst erhöhe $j$ um $1$   


>[!example] Beispiel
>![[Pasted image 20260416140747.png]]

## Laufzeit
$$n + (n-1) + (n-2) + \cdots + 1 = \sum^n_{i = 1} \frac{n(n+1)}{2} \approx \sum^n_{i=1} \frac{n²}{2}$$⤷ im schlimmsten Fall $\frac{n(n+1)}{2}$

- schlechteste Laufzeit ergont sich, wenn Eingabe bereits sortiert
	⤷ Pivot wird mit allen Elementen verglichen