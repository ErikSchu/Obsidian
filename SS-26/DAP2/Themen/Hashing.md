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
- wenn $\mathcal S$ "klein": Array fr