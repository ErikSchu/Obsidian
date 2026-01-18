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