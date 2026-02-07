#dap1 

## Lempel-Ziv 77

>[!note] Wdh. LZ78
>In wieviele Paare zerlegt [[DAP1_29-Textkompession|LZ78]] den String $T = \text{aaaaaaaaaaaaaaa}$ (15 a's)? 
>⇒ *Antwort:* $z = 5$
>	⇒ Für $T = a^n$ *allgemein:*  $z \approx \sqrt{ n }$

>[!TIP] LZ77
>... gibt eine FOlge $l_{j}, d_{j}, c_{j}$ von $z$ Tripeln (Länge, Quelle, Buchstabe) aus, so dass $$T = \text{copy}(d_{1}, l_{1})c_{1} \ \cdot \ \text{copy}(d_{2},l_{2})c_{2} \ \cdots \ \text{copy}(d_{z}, l_{z})c_{z}$$

- **Annahme:** Es wurden bereits die ersten $i-1$ Buchstaben von $T$ dekodiert. Dann ist $$\text{copy}(d_{j}, l_{j}) = \begin{cases} T[i-d_{j}, i-d_{j}+l_{j}-1] &\text{falls } l_{j} > 0 \\  \end{cases}$$