#rs Dienstag, 25.11.2025

# 6.4 Algorithmus von Quine und McCluskey

- **Eingabe:** $f$ als Liste aller Minterme zu einschlägigen Indizes
- **Ausgabe:** Minimalpolynom zu $f$

## Verfahren 
1. Berechne PI, Menge aller Primimplikanten von $f$.
2. Berechne miniamale $f$ übredeckende Auswahl aus PI.

## Algorithmus 
=
**Eingabe $L_{0}$:** Liste aller Minterme zu einschlägigen Indizes von $f$

**Ausgabe:** PI: Menge aller Primimplikationen zu $f$
1. $i := 0; PI := \emptyset$
2. Solange $L_{i} \ne \emptyset$
3. $L_{i+1} := \{m \ | \ \exists x: \{mx, m \overline x \} \subseteq L_{i} \}$
4. $PI := PI \cup \{ m \in L_{i} \ |  \text{m hat keine echte Verkürzung in} \ L_{i+1} \}$ 
5. $i := i+1$
6. Ausgabe PI

**Korrektheit**
1. $i := 0 ⇒ PI := \emptyset$
2. So lange $L_{i} \ne \emptyset$
3.  $L_{1} := \{ m \ | \ \exists x : \{ mx, m \overline{x} \} \subset L_{i}\}$
4. $PI := PI \cup \{ m \in L_{i} \ | \ \text{m hat keine echte Verkürzung in } L_{i+1} \}$

> [!note] **Beweis**
> ![[Pasted image 20251125163609.png]]
> ![[Pasted image 20251125163704.png]]

**Terminierung**
*Wir haben:* $L_{i}$ ist Liste Implikanten der Länge $n-i$
*Es gilt:* Algorithmus 11 terminiert
*denn:* spätestens $L_{n+1} = \emptyset \ \checkmark$ 

⤷ **Beobachtung**
- Am Ende enthält PI alle *Primimplikanten*
- denn jeder Primimplikant ist Implikant, also in einer Liste vorhanden
- und Ürimimplikant hat keine Verkützung, die auch Implikant ist
- *wird deshalb zu PI hinzugefügt.*

**also** Berechnung der PI nach Quine/McCluskey korrekt $\checkmark$
![[Pasted image 20251125170253.png]]