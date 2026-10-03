#rs
# Ctd. KV-Diagramme
![[Pasted image 20251120101849.png]]
![[Pasted image 20251120101940.png]]
![[Pasted image 20251120102002.png]]
![[Pasted image 20251120102021.png]]
![[Pasted image 20251120102811.png]]
![[Pasted image 20251120102835.png]]

## Minimalpolynomberechnung

### Idee
1. Berechne alle Primomlikanten von f.
2. Berechne günstigste

"Überdeckung" von f mit diesen Monomen.

⇒ **Beobachtung:**
	Der Ansazu ist *sicher schlecht*, wenn das Minimalpolynom zu f klein ist, aber f zu viele Primimplikanten hat.
	Wir verfolgen diesen Ansatz dennoch.

### Behauptung
Wir haben mit KV-Diagrammen Minimalpolynome berechnet.
⇒ Wir haben günstigste Überdeckung von f gesucht.

*Entsprechen maximale Rechtecke mit Zweierüptenzlängen genau Primimplikanten?*

**Es gilt:** Für $f:\{0,1\}^4 \rightarrow \{0,1\}$ gibt es Monome der Längen 0,1,2,3,4. 
Wir schauen uns die Situation für jede mögliche Monomalänge an.

#### Beispiele

**Primimplikation der Lönge 0**
![[Pasted image 20251120105349.png]]

**Primimplikation der Länge 1**
![[Pasted image 20251120110159.png]]
![[Pasted image 20251120110249.png]]

**Primimplikation der Länge 2**
![[Pasted image 20251120110317.png]]

**Primimplikation der Länge 3**
![[Pasted image 20251120110949.png]]

**Primimplikation der Länge 4**
![[Pasted image 20251120111212.png]]

**Beispielaufgabe
![[Pasted image 20251120111508.png]]

### Minimalpolynombestimmung mit KV-Diagramm 
**Aufgabe:** Bestimme für $f:\{0,1\}^4 \rightarrow \{0,1\}$  
...

---

# 6.4 Algorithmus von Quine und McCluskey

- **Eingabe:** $f$ als Liste aller Minterme zu einschlägigen Indizes
- **Ausgabe:** Minimalpolynom zu $f$

## Verfahren 
1. Berechne PI, Menge aller Primimplikanten von $f$.
2. Berechne miniamale $f$ übredeckende Auswahl aus PI.

## Algorithmus 

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
2. waihl $L_{i} \ne \emptyset$
3. 