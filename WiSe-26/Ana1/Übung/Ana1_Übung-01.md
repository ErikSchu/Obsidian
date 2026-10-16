---
datum: 16.10.2026
tags:
  - Ana1
smry:
---
## Aufgabe 1
⤷ Induktion

Z.z. $\underline{\forall n \in \mathbb{N} : 2n > n}$
- **Indunktionsanfang:** Sei $n = 1$
  $\implies 2^n = 2^1 = 2 > 1 = n$
- **Induktionsschritt:** Wähle $n$ beliebig aber fest. Es gilt $2^{n+1} = 2^n \cdot 2$.
  $\implies 2^n \cdot 2 > n+1 > \text{nach IV } 2n = n + n \geq  n + 1 \ \forall n \in N. \space\blacksquare$

Z.z. $\underline{\forall n \in \mathbb{N} : \sum ^n _{k=1} k^2 = \frac{1}{3} n^3 + \frac{1}{2} n^2 + \frac{1}{6}n}$
- **Indunktionsanfang:** Sei $n = 1$
  $\implies \sum_{k = 1}^1 k^2 = k = 1 = \frac{1}{3} + \frac{1}{2} + \frac{1}{6} = \frac{1}{3} n^3 + \frac{1}{2} n^2 + \frac{1}{6} n$
- **Induktionsschritt:** Wähle $n$ beliebig aber fest. 
  $\implies \sum_{k=1}^{n+1} k = \sum_{k=1}^n + n = \text{(IV) } $