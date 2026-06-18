>[!attention] Problemstellung
>- Arrays sind zusammenhängende Speicherblöcke, die *direkt adressiert* werden
>- auch Datenstrukturen benötigt, deren Elemente **durch Schlüssel adressiert** werden können
>- *z.B. Matrikelnummern, Wörterbücker, Telefonverzeichnisse, ...*
>- Wie nehmen an, dass verschiedene Elemente auch verschiedene Schlüssel haben
>- ***Hashtabellen*** stellen entsprechende Datenstruktur bereit

>[!tip] Einfach verkettete Listen
>- jeder Listeneintrag enthält einen *Zeiger auf den nächsten Eintrag*
>- Abwesenheit eines Nachvolgers gekennzeichnet durch ` NULL `
>- neue Elemente einfügen, Elemente löschen und Listen vereinigen in $O(1)$
>- Durchsuchen in $\Theta(n)$

>[!tip] Doppelt verkettete Listen
>- zusätzlicher Zeiger auf den Vorgänger für jeden Eintrag
>- Aufteilen an bestimmte Stelle in $O(1)$
>- allerdings immer noch $\Theta(n)$ Zeit notwendig, um Einträge zu finden


### Direkte Adressierung
- $\mathcal S = \{ s_{1}, \dots, s_{k} \}$ ist die Menge der **Schlüssel**
- wenn $\mathcal S$ "klein": Array für jeden möglichen Schlüssel mit seinem Eintrag
- Wenn Eintrag nicht vorhanden, speichere `NULL`
- ***Speicherbedarf:*** $\Theta(k)$
- ***Zugriffszeit:*** $O(1)$ (speichern/abrufte/löschen)

## Hashtabellen
- **Hashing** mit ***Hashfunktion***, $$\mathcal H : \mathcal S \to [m] = \{ 1, \dots, m \}$$die die Schlüssel auf eine *klenere* Menge $[m]$ abbildet
- Mit $1, \dots, n$ wird ein Array adressiert
- **Kollisionen** möglich falls $m < |\mathcal S|$
	- deshalb $m$ in ***einfach verkettete Liste*** $\mathbf{L} = (L_{1}, \dots, L_{m})$
	- $\mathbf{L}_{i}$ Speichert **Element mit Hash $i$**
		⮩ Operationen
		` Insert ` ` Search ` ` Delete `

- **Insert:** 
  Um ein neues Element e mit Schlüssel s in die Hashtabelle einzufügen, berechnen wir zunächst den Hash $\mathcal H (s)$. Dann wird das Element in die Liste L H (s ) eingefügt. Diese Operationen kann in Laufzeit O (1) durchgeführt werden (wenn wir die Berechnung der Hashfunktion als eine Operation zählen). 

- **Search:** 
  Um ein Element mit einem gegeben Schlüssel s zu finden, bestimmen wir den Hash H (s). Anschließend durchsuchen wir die Liste L H (s ) nach einem Element mit Schlüssel s. Die Laufzeit für diese Operation ist die Länge der Liste L H (s ) .

- **Delete:** 
  Auch diese Operation kann in Zeit L H (s ) ausgeführt werden, wenn s der Schlüssel des zu löschenden Elements ist.