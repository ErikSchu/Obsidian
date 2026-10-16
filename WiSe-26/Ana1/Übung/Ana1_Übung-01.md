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
- **Induktionsschritt:** Wähle $n$ beliebig aber fest. Es gilt nach Vorschrift $2^n > n$.  Ferner gilt $2^{n+1} = 2^n \cdot 2$. 
  $2^n \cdot 2 > n+1 \iff \frac{2^n \cdot 2}{n+1} > 0$, was der fall ist, da $2^n$ exponentiell wächst. Daher folgt $2^{n+1} > n+1 \space\blacksquare$ 

Z.z. $\underline{\forall n \in \mathbb{N} : \sum ^n _{k=1} k^2 = \frac{1}{3} n^3 + \frac{1}{2} n^2 + \frac{1}{6}n}$
- **Indunktionsanfang:** Sei $n = 1$
  $\implies \sum_{k = 1}^1 = k = 1 = \frac{1}{3} +$