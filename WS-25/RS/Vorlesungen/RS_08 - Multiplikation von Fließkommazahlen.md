#rs
### Darstellung nach IEEE-754
- $s$ Vorzeichenbit
- $m$ Mantisse (Binärdarstellung, inkl. impliziter 1)
- $e$ Exponent (Exzessdarstellung, $b = 2^{l-1}-1$)
$$
\begin{align}
& x = (-1)^{s_x} * m_x * 2^{e_x} \\
& y = (-1)^{s_y} * m_y * 2^{e_y}
\end{align}
$$
**Ergebnis**                   $z = (-1)^{s_z} * m_z * 2^{e_z}$  
**Vereinfachung**         Wir ignorieren das Runden.

$x = (-1)^{s_x} * m_x * 2^{e_x} \ \ \ \ \ \ \ \ y = (-1)^{s_y} * m_y * 2^{e_y}$

**Vorgehen**
1. $s_z := s_x \oplus s_y$
2. $m_z := m_x * m_y$
    - Multiplikation von Betragszahlen wie gesehen,
    - **Implizite Einsen nicht vergessen!**
3. $e_z := e_x + e_y$
    - Addition, wegen Exzessdarstellung berechnen
    - $E_x := e_x + b$ _(Binärrepräsentation von $e_x$ ist $E_x$)_
    - $E_y := e_y + b$ _(Binärrepräsentation von $e_y$ ist $E_y$)

#### Beispiel
Skript

## Floating Point

*Hinweis:* Die meisten reellen Zahlen können nicht exakt dargestellt werden, z.B. $\pi$ oder $\frac{1}{10}$.
→ Rundungsfehler entstehen nicht aus intuitivem Verhalten.
![[Pasted image 20251113104759.png]]

*Beispiel aus der Finanzwelt:*
Die Gebüren eines Telefonanrufes (50 Pauls) sollen um 9 Pauls erhöht werden. 
→ Paul'sches Runden:![[Pasted image 20251113105136.png]]

![[Pasted image 20251113105207.png]]

### Auslöschung
![[Pasted image 20251113105444.png]]
![[Pasted image 20251113105518.png]]

![[Pasted image 20251113105552.png]]

**Beispiel** Evaluierung von $fl(x)$ für $x = 1.1 \cdot 10^{-8}$.
- *Math.cos(x)* = **0.99999999999999999**888977238710923
- 1.0 - Math.cos(x) = 1.1102 $\cdot 10^{-16}$
- $\frac{1.0-Math.\cos(x)}{x \cdot x}$ = 0.9175
Unter *Auslöschung* (bzw. cancellation) versteht man in der Numerik den Verlust an Genauigkeit bei der Subtraktion fast gleicher Kommazahlen

## LGS

![[Pasted image 20251113111003.png]]

**Grundlegende Problee in den Natur- und Ingenieurswissenschaften:**
- chemisches Gleichgewicht
- lineare und nicht lineare Optimierung
- Kirschhoffsche Regeln 
- Hooksches Gesetz
- Numerische Lösungen für Differenzialgleichungen

#### Für die obere Dreiecksmatrix gilt:
![[Pasted image 20251113111416.png]]
... Skript


# Optimierung von Schaltnetzen

## Einleitung & Systematischer Entwurf

**Schaltnetz-Entwurf bisher**
- ad hoc
- Normalformen

**Wunsch**
- Systematisierung
- Strukturierung

**Hoffnungen**
- Einfacher zu guten Entwürfen
- Schaltnetze verständlicher
- Schaltnetze besser verifizierbar

### Systematisierung Schaltnetz-Entwurf