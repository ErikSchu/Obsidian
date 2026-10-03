#dap2 

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
  Um ein neues Element e mit Schlüssel s in die Hashtabelle einzufügen, berechnen wir zunächst den *Hash* $\mathcal H (s)$. Dann wird das Element in die *Liste* $L_{\mathcal H (s)}$ eingefügt. Diese Operationen kann in *Laufzeit* $O(1)$ durchgeführt werden (*wenn wir die Berechnung der Hashfunktion* als eine Operation zählen). 

- **Search:** 
  Um ein Element mit einem gegeben Schlüssel s zu finden, bestimmen wir den *Hash* $\mathcal H (s)$. Anschließend *durchsuchen* wir die Liste $L_{\mathcal H(s)}$ nach einem Element mit Schlüssel $s$. Die *Laufzeit* für diese Operation ist die *Länge der Liste* $L_{\mathcal H(s)}$.

- **Delete:** 
  Auch diese Operation kann in Zeit L H (s ) ausgeführt werden, wenn s der Schlüssel des zu löschenden Elements ist.

### Hashfunktionen
- deterministische Hashfunktion kann die Hashtabelle schlimmstenfalls zu verketteter Liste degradieren
- dennoch oft verwendet, da schnell zu berechnen
- zufällige Hashfunktionen beweisbar gut

##### Multiplikationsmethode
- *Annahme:* $s_{i} \in \mathbb{N}$
- Wähle $\alpha \in \mathbb{R}, 0 < \alpha < 1$, z.B. $$\alpha = \frac{\sqrt{ 5 }-2}{2}$$und definiere $$\mathcal H(s) = \lceil m \cdot (s \alpha - \lfloor s \alpha \rfloor ) \rceil \in \{ 1, \dots, m \}$$⮩ **nicht heuristisch**

>[!tip] Universelle Hashfunktion
>Eine Folge $\mathcal h = (\mathcal H_{1}, \dots, \mathcal H_{l})$ von Hashfunktionen $\mathcal H_{i} : S \to [m]$ heißt ***universell***, falls für jeden Schlüssel $s, s' \in \mathcal S, s \ne s'$ gilt $$|\{ i \in [l] : \mathcal H _{i} (s') \}| \le \frac{l}{m}$$

>[!TIP] **Satz**
>- Annahme $n$ Elemente werden in Hashtabelle gespeichert
>- Annahme $\mathcal h$ ist eine universelle Folge von Hashfunktionen
>Wenn $\mathcal H$ ein zufälliges Element von $\mathcal h$ ist, hat für jeden Schlüssel $k \in \mathcal S$ die Liste $\mathbf{L}_{h(k)}$ die Erwartete Länge $\frac{n}{m} + O(1)$

[[12.3_Der-euklidische-Algorithmus]]

### Konstruktion universeller Hashfunktion 
- sei $m > 1, m \in \mathbb{N}$ und $p > m$ prim
- für $a, b \in \mathbb Z, a \le a < p, o \le b < p$ definiere $$\mathcal H _{a, b}: \begin{cases} \{ 0, \dots, p-1 \} \to \{ 0, \dots, m -1 \} \\ k \mapsto ((ak + b) \text{ mod } p ) \text{ mod } m \end{cases}$$
- sei $\mathcal h _{p, m} = (\mathcal H_{a, b})_{a, b.}$

>[!tip] **Satz**
>Die Menge $\mathcal h_{p, m}$ von Hashfunktionen $\{ 0, 1, \dots, p-1 \} \to \{ 0, 1, \dots, m \}$ ist universell.

