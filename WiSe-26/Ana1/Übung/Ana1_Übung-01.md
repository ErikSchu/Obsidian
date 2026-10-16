---
datum: 16.10.2026
tags:
  - Ana1
smry: Induktionsbeweise, Beweisen/Wiederlegen
---
## Aufgabe 1
⤷ Induktion

Z.z. $\underline{\forall n \in \mathbb{N} : 2n > n}$
- **Indunktionsanfang:** Sei $n = 1$
  $\implies 2^n = 2^1 = 2 > 1 = n$
- **Induktionsschritt:** Wähle $n$ beliebig aber fest. Es gilt $2^{n+1} = 2^n \cdot 2$.
  $2^n \cdot 2 > n+1 > \text{nach IV } 2n = n + n \geq  n + 1 \ \forall n \in N. \space\blacksquare$

Z.z. $\underline{\forall n \in \mathbb{N} : \sum ^n _{k=1} k^2 = \frac{1}{3} n^3 + \frac{1}{2} n^2 + \frac{1}{6}n}$
- **Indunktionsanfang:** Sei $n = 1$
  $\implies \sum_{k = 1}^1 k^2 = k = 1 = \frac{1}{3} + \frac{1}{2} + \frac{1}{6} = \frac{1}{3} n^3 + \frac{1}{2} n^2 + \frac{1}{6} n$
- **Induktionsschritt:** Wähle $n$ beliebig aber fest. 
  $\sum_{k=1}^{n+1} k^2 = \sum_{k=1}^n k^2 + n^2 = \text{(IV) } \frac{1}{3}n^3+\frac{1}{2}n^2+\frac{1}{6}n+ (n+1)^2$
  ![[Pasted image 20261016105358.png|144]]
  $\frac{1}{3}(n+1)^3 + \frac{1}{2} (n+1)^2 + \frac{1}{6}(n+1)$ 
  $= \frac{1}{3} (n^3 + 3n^2 + 3n + 1) + \frac{1}{2}(n^2 + 2n + 1) + \frac{n+1}{6}$$
  $= \frac{1}{3} n^3 + \frac{3}{2}n^2 + \frac{13}{6}n + 1. \space \blacksquare$
  
  ___

## Aufgabe 2
⤷ beweise oder wiederlege

a) $\forall m \in \mathbb{N} : m \text{ ungerade} \implies m^2 \text{ gerade}.$ $$m \text{ ungerade} \implies m = 2n +1 (n \in \mathbb{N}) \\ m^2 = (2n+1)^2 = 4n^2 + 4n + 1 \\ \text{Der Ausdruck ist nicht zwangsläufig gerade, die Aussage stimmt nicht.} \\ \text{ Gegenbeispiel: } 3^2 = 9, \text{3 und 9 sind beide ungerade.}$$
b) $\forall m \in \mathbb{N} : m^2 \text{ ungerade} \implies m \text{ ungerade}.$ $$m^2 \text{ ungerade} \implies m^2 = 2n + 1 (n \in \mathbb{N}) \\ m = \sqrt{ m^2 } = \sqrt{  }$$