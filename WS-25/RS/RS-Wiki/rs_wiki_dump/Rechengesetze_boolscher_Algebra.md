Für alle $x, y, z \in B$:

* **Kommutativität:**
    * $x \cup y = y \cup x$
    * $x \cap y = y \cap x$

* **Assoziativität:**
    * $(x \cup y) \cup z = x \cup (y \cup z)$
    * $(x \cap y) \cap z = x \cap (y \cap z)$

* **Distributivität:**
    * $x \cap (y \cup z) = (x \cap y) \cup (x \cap z)$
    * $x \cup (y \cap z) = (x \cup y) \cap (x \cup z)$

* **Neutralelemente:**
    * $x \cup 0 = x$
    * $x \cap 1 = x$

* **Nullelement (Dominanz):**
    * $x \cup 1 = 1$
    * $x \cap 0 = 0$

* **Idempotenz:**
    * $x = x \cup x$
    * $x = x \cap x$

* **Involution (Doppelte Negation):**
    * $x = \overline{\overline{x}}$

* **Komplementarität:**
    * $x \cap \overline{x} = 0$
    * $x \cup \overline{x} = 1$ (Tautologie $x \lor \neg x$)

* **Absorption:**
    * $(x \cup y) \cap x = x$
    * $(x \cap y) \cup x = x$

* **Resolution:**
    * $(x \cup y) \cap (\overline{x} \cup y) = y$
    * $(x \cap y) \cup (\overline{x} \cap y) = y$

* **De Morgan'sche Gesetze:**
    * $\overline{x \cup y} = \overline{x} \cap \overline{y}$
    * $\overline{x \cap y} = \overline{x} \cup \overline{y}$

$A \ xor \ B = (A \land \overline{B}) \lor (\overline{A} \land B)$
