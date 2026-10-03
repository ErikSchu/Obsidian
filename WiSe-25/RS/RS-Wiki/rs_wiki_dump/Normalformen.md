Normalformen sind eine **eindeutige** Darstellung einer booleschen Funktion.

> [!abstract] Disjunktive Normalform (DNF)
> Die Darstellung einer Funktion $f$ als **Disjunktion (ODER-Verknüpfung)** all ihrer Minterme zu den **einschlägigen Indizes** (wo $f=1$) heißt DNF.
>
> $$f = \bigvee_{i \text{ ist einschlägig}} m_i$$

> [!abstract] Ringsummen-Normalform (RNF)
> Die Darstellung einer Funktion $f$ als **XOR-Verknüpfung** all ihrer Minterme zu den **einschlägigen Indizes** heißt RNF.
>
> $$f = \bigoplus_{i \text{ ist einschlägig}} m_i$$

> [!EXAMPLE] DNF & RNF für $f_6$ (XOR)
> * Wertetabelle $f_6 = (0, 1, 1, 0)$
> * Einschlägige Indizes: $i=1$ und $i=2$.
> * Minterme: $m_1 = \overline{x_1} x_2$ und $m_2 = x_1 \overline{x_2}$.
> * **DNF:** $f_6 = m_1 \lor m_2 = (\overline{x_1} \land x_2) \lor (x_1 \land \overline{x_2})$
> * **RNF:** $f_6 = m_1 \oplus m_2 = (\overline{x_1} \land x_2) \oplus (x_1 \land \overline{x_2})$

Während die DNF die Funktion über ihre **Einsen** (einschlägige Indizes) definiert, definiert die KNF die Funktion über ihre **Nullen** (nicht einschlägige Indizes).

Sie basiert auf **Maxtermen**.

> [!abstract] Maxterm ($M_i$)
> 
> Ein Maxterm ist eine ODER-Verknüpfung (Summenterm), die für genau eine Eingangskombination (beim Index $i$) den Wert 0 annimmt.
> 
> **Bildungsregel (Gegenteil von Minterm):**
> 
> - Variable = **0** $\rightarrow$ **normal** ($x$)
>     
> - Variable = **1** $\rightarrow$ **negiert** ($\overline{x}$)
>     

> [!EXAMPLE] Maxterme für $n=2$
> 
> | Index $i$ | $x_1$ | $x_2$ | Maxterm $M_i$ |
> 
> | :---: | :---: | :---: | :--- |
> 
> | 0 | 0 | 0 | $M_0 = (x_1 \lor x_2)$ |
> 
> | 1 | 0 | 1 | $M_1 = (x_1 \lor \overline{x_2})$ |
> 
> | 2 | 1 | 0 | $M_2 = (\overline{x_1} \lor x_2)$ |
> 
> | 3 | 1 | 1 | $M_3 = (\overline{x_1} \lor \overline{x_2})$ |
> 
> _Beachte: $M_0$ ist nur FALSCH (0), wenn $x_1=0$ und $x_2=0$._

### Erstellung der KNF

> [!abstract] Konjunktive Normalform (KNF)
> 
> Die Darstellung einer Funktion $f$ als Konjunktion (UND-Verknüpfung) all ihrer Maxterme zu den nicht einschlägigen Indizes (wo $f=0$) heißt KNF.
> 
> $$f = \bigwedge_{i \text{ ist nicht einschlägig}} M_i$$

**Schritte zur KNF:**

1. Finde alle Zeilen in der Wertetabelle, in denen die Funktion $f$ den Wert **0** hat (die "nicht einschlägigen Indizes").
    
2. Bilde für **jede** dieser Zeilen den entsprechenden **Maxterm** (nach der KNF-Bildungsregel).
    
3. Verknüpfe alle diese Maxterme mit **UND** ($\land$).
    

> [!EXAMPLE] KNF für $f_6$ (XOR)
> 
> - Wertetabelle $f_6 = (0, 1, 1, 0)$
>     
> - **Nicht einschlägige Indizes** (wo $f=0$): $i=0$ und $i=3$.
>     
> - **Maxterme bilden:**
>     
>     - Für $i=0$ ($x_1=0, x_2=0$): $M_0 = (x_1 \lor x_2)$
>         
>     - Für $i=3$ ($x_1=1, x_2=1$): $M_3 = (\overline{x_1} \lor \overline{x_2})$
>         
> - **KNF (mit UND verknüpfen):**
>     
>     - $f_6 = M_0 \land M_3 = (x_1 \lor x_2) \land (\overline{x_1} \lor \overline{x_2})$
>

---

### Funktionale Vollständigkeit

> [!abstract] Definition
> Eine Menge $F$ von booleschen Funktionen (z.B. $\{ \land, \overline{\ } \}$) heißt **funktional vollständig**, wenn sich *jede* boolesche Funktion nur durch Komposition von Funktionen aus $F$ darstellen lässt.

> [!TIP] Sätze zur Vollständigkeit
> * $F_1 = \{\land, \lor, \overline{\ }\}$ ist **funktional vollständig** (weil wir damit jede DNF bilden können).
> * $F_2 = \{\land, \overline{\ }\}$ ist funktional vollständig (weil $\lor$ durch $\land$ und $\overline{\ }$ darstellbar ist: $A \lor B = \overline{\overline{A} \land \overline{B}}$).
> * $F_3 = \{\lor, \overline{\ }\}$ ist funktional vollständig (weil $\land$ durch $\lor$ und $\overline{\ }$ darstellbar ist: $A \land B = \overline{\overline{A} \lor \overline{B}}$).
> * $F_4 = \{\text{NAND}\}$ ist funktional vollständig.
> * $F_5 = \{\text{NOR}\}$ ist funktional vollständig.
> * $F_6 = \{\text{XOR}, \land \}$ ist funktional vollständig (Basis für RNF).
> * $F_7 = \{\text{XOR}, \text{XNOR}\}$ ist **nicht** funktional vollständig.