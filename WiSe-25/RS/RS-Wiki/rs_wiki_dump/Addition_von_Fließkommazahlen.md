#rs 

##### Darstellung gemäß [[Repräsentation Rationaler Zahlen|IEEE 754-1985]]
- ` s `   **Vorzeichenbit**
- ` m `   **Mantisse** (Binärdarstellung, *inklusive* impliziter $1$)
- ` e `   **Exponent** (Exzessdarstellung, $b=2^{l_{e}-1}-1$)

$$\begin{align}
& x & =(-1)^{s_{x}} \cdot m_{x} \cdot 2^{e_{x}}y \\
& & = (-1)^{s_{y}} \cdot m_{y} \cdot 2^{e_{y}}z  \\
& & = x+y  \\
& & = (-1)^{s_{z}} \cdot m_{z} \cdot 2^{e_{z}}
\end{align}$$⤷ ***Beobachtung*** ist einfach, wenn $e_{x}= e_{y}=e$ und $s_{x} = s_{y} = s$ gilt $z = (-1)^s \cdot (m_{x} + m_{y}) \cdot_{2}^e$

>[!question] Quiz
>Angenommen ist gibt 2 IEEE 754-1985 Zahlem $x$ und $y$ und wir berechnen $z=x+y$;
>Wenn $s_{x} =s_{y}$ und $e_{x} = e_{y}$, welche Werte kann $e_{z}$ annehmen?
>___
>*1. $e_x$*
>**2. $e_x+1 \checkmark$**
>*3. $e_x-1$*
>*4. beliebig*

___

## Algorithmus zur Addition

- ***Fall 1: $s_{x} = s_{y}$ (gleiches vorzeichen)*** $$z = x+y = (-1)^{s_{z}}[m_{x}2^{e_{x}}+ m_{y}2^{e_{y}}] = (-1)^{s_{x}} \cdot 2^{e_{x}}[m_{x}+m_{y}2^{e_{y}-e_{x}}]$$**Für $z$ gilt:**
  1. $s_{z} := s_{x}$
  2. $e_{z} := e_{x}$
  3. $m_{z} := m_{x}+m_{y}2^{2_{y}-e_{x}}$
    
    Falls $m_{z} \ge 2$: *Ergebnis normalisieren*
    1. $e_{z} := e_{z} + 1$
    2. $m_{z} := \frac{m_{z}}{2}$

- ***Fall 2: $s_{x} \ne s_{y}$ (unterschiedliche Vorzeichen)*** $$z = x+y = (-1)^{s_{z}} [m_{x}2^{e_{x}}-m_{y}2^{e_{y}}] = (-1)^{s_{x}} \cdot [m_{x}-m_{y}2^{{e_{y}-e_{x}}}]$$**Für $z$ gilt:**
  1. $s_{z} := s_{x}$
  2. $e_{z} = e_{x}$
  3. $m_{z} := m_{x} - m_{y} 2^{e_{y}-e_{x}}$
     
     Falls $m_{z}= 0: (e_{z}:= e_{min}-1)$
     Sonst: $1 \le m_{z} \cdot 2^q <2$ für eine ganze Zahl $q$
     $e_{z} := e_{z} - q$ und $m_{z} := m_{z} \cdot 2^q$
     
     $s_{x} = s_{y} \implies x-y \implies$ Umwandlung von $y$ ins [[Zweierkomplement]]
>[!example] Beispiele
>$m_{y} = 1.01010000000000000000000$
>Vorzeichenerweiterung: $01.01010000000000000000000$
>Einerkomplement + $10.10110000000000000000000$
>___
>Wie berechnen wir $-m_{y}2^{e_{y}-e_{x}}$?
>⤷ Mantisse verschieben, vorne mit Einsen füllen
>z.B.: $-m_{y} \cdot 2^{-5}= 11,111 0101 1000 0000 0000 000$
>⤷ $m_{y} \cdot 2^{-5} = 00,0001010100000000000000$
>	$-(m_{y}\cdot 2^{-5}) = 11,111 0101 1000 0000 0000 000$
>___
>$$
>\begin{align}
>x = 1 \ 1001 0101 111 0010 0000 0000 0000 0000 \\
>y = 1 \ 1001 0100 110 0001 1000 0000 0000 0000
\end{align}
>$$
>$e_{x} \ge e_{y}$, Vorzeichen gleich, also zunächst nur $s_{z} := 1$
>Mantisse $m_{y}$ um $[e_{x}-e_{y} = 1]$ Stelle(n) nach rechts verschieben 
>→ $0,111000011$
>Mantisse addieren
>![[Pasted image 20260108122510.png]]
>Normalisieren
>- Komma um eine Stelle nach links verschieben → $1001\ 0110$
>$$Z \ 1 \ 1001 0110 011 0001 0110 0000 0000 0000$$
  
>[!question] Quiz
>Angenommen es gibt 2 IEEE 754-1985 Zahlen $x$ und $y$ undwir berechnen $z=x+y$;
>Wenn $s_{x} \ne s_{y}$ und $e_{x} = e_{y}$, welche Werte kann $m_{x}-m_{y}$ (Mantisse $m_{x} \ge m_{y}$) annehmen?
>___
>*1. $m_{x}-m_{y} > 1$*
>**2. $m_{x}-m_{y} < 1 \ \checkmark$**
>**3. $m_{x}-m_{y} > 0 \ \checkmark$**
>**4. $m_{x}-m_{y} = 0 \checkmark$**
>*5. $m_{x}-m_{y} < 0$* 

