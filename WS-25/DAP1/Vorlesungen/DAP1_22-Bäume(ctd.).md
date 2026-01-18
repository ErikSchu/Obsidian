#dap1 
## Suchbäume und [[Rekursion]]

> [!warning] Wiederholung
> Ein **binärer Suchbaum** über *Schlüssel* vom Typ $T$ ist ein Baum für den gilt:
> - Jeder knoten hat maximal 2 Kinder, die mit ` left_ ` und ` right_ ` bezeichnet werden.
> - Der Schlüssel ` T cont_ ` in *jedem* Knoten $v$ ist *größer* als alle Schlüssel im linken Teilbaum $B_{\text{left\_}}$ und *kleiner* als alle Schlüssel im rechten Teilbaum $B_{\text{right\_}}$.

⇒ Siehe [[DAP1_21-Bäume]].

>[!question] Quiz
>Wenn alle Wörter in (alphabetisch) sortierter Reihenfolge eingefügt werden, dann führt dies mit hoher Wahrscheinlichkeit zu einer größeren Baumtiefe, als wenn sie in zufälliger Reihenfolge eingefügt würden.
>**⤷WAHR $\checkmark$**
>___
>![[Pasted image 20260118121302.png]]

___

## Suchen in einem Binären Suchbaum

>[!bug] Algorithmische Idee
>1. starte an der Wurzel des Baums ` currrent = root_ `
>2. falls ` current == nullptr `: gib **false** zurück
>3. sonst: vergleiche gesuchten Wert $x$ mit ` current->cont_ `
>4. falls ` x = current->cont_ `: gib **true** zurück
>5. falls ` x < current->cont_ `: setze ` current = current->left_` und gehe zu 2. (suche weiter im *linken Teilbaum*)
>6. sonst: setze ` current = current->right_ ` und gehe zu 2. (suche weiter im *rechten Teilbaum*)
>___
>Oder ***rekursiv*** formuliert als $\text{find}(x,B_{current})$:
>	1. falls ` current == nullptr`: gib **false** zurück (baum leer ⇒ nicht gefunden)
>	2. falls ` x = current->cont_ `: gib **true** zurück (gefunden!)
>	3. falls ` x < current->cont_ `: gib das Ergebnis von $\text{find}(x, B_{current->left\_})$ zurück
>	4. sonst: gib das Ergebnis von $\text{find}(x, B_{current->right\_})$ zurück

#### Suchbäume enthalten eine Sortierung

Die Sortierung der Schlüssel ist leicht, obwohl die Baumknoten nicht linear angeordnet sind. 

>[!TIP] Es gilt **für jeden Knoten** ` node ` im Baum:
>- `other->cont_ < node->cont_` **für jeden Knoten** $\text{other}$ im Teilbaum mit Wurzel $\text{node.left\_}$
>- `other->cont_ > node->cont_` **für jeden Knoten** $\text{other}$ im Teilbaum mit Wurzel $\text{node.right\_}$
> ___
> $\leadsto$ das *Minimum* steht "ganz links", das *Maximum* "ganz rechts"

- Sortierte Reihenfolge als **rekursiver** Algorithmus
	- gib die sortierte Reihenfolge des *linken Teilbaums* der Wurzel aus (falls linker Teilbaum existiert)
	- gib den Schlüssel der *Wurzel* aus
	- gib die sortierte Reihenfolge des *rechten Teilbaums* der Wurzel aus (falls rechter Teilbaum existiert)

___
## Inorder, Preorder, Postorder

- der **Algorithmus zur sortierten Ausgabe** nenn sich auch ***Inorder-Traversierung*** des Baums:
	- linker Teilbaum, *Wurzel*, rechter Teilbaum

- Es gibt auch andere Traversierungen:
	- ***Preorder:*** *Wurzel*, linker Teilbaum, rechter Teilbaum
	- ***Postorder:*** linker Teilbaum, rechter Teilbaum, *Wurzel*

- Diese Traversierungen sind auch für allgemeine Bäume (ohne Suchbaumeigenschaft) definitert
	- dann impliziert Inorder *keine* Sortierung