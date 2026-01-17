
**Ziel:** Rationale Zahlen $q \in \mathbb{Q}$ mit einer **festen Kommaposition** und einer festen Repräsentationslänge $\ell$ darzustellen.

## Aufbau

Man teilt die $\ell$ Bits auf in:

* **$v$ Vorkommastellen**
* **$m$ Nachkommastellen**
* (ggf. ein Vorzeichenbit, oft im [[Repräsentation ganzer Zahlen|Zweierkomplement]] gelöst)

**Formel (Basis 2):**
Ein Bitvektor $a = (a_{v-1} \dots a_0 , a_{-1} \dots a_{-m})$ hat den Wert:
$$
Wert = \sum_{i=-m}^{v-1} a_i \cdot 2^i
$$
Das entspricht einer normalen Binärzahl, die am Ende durch $2^m$ geteilt wird.

> [!EXAMPLE] Beispiel: $\ell=8$, $v=5$, $m=3$
> * Bitmuster: `00010.101`
>     * Vorkommateil: $00010_2 = 2_{10}$
>     * Nachkommateil: $101_2 \rightarrow 1 \cdot 2^{-1} + 0 \cdot 2^{-2} + 1 \cdot 2^{-3}$
>     * Wert: $2 + 0.5 + 0 + 0.125 = 2.625_{10}$

---

## Bewertung

> [!TIP] Vorteile
> * **Schnell:** Operationen (Addition, Subtraktion) können direkt auf Ganzzahl-Hardware (ALU) ausgeführt werden.
> * **Einfach:** Keine spezielle Fließkomma-Hardware (FPU) nötig.
> * **Einsatz:** Ideal für Digitale Signalverarbeitung (DSP), wo der Wertebereich bekannt und die Geschwindigkeit kritisch ist.

> [!WARNING] Nachteile
> * **Unflexibel:** Die Kommaposition ist fest.
> * **Begrenzter Wertebereich:** Kann weder sehr große noch sehr kleine Zahlen gut darstellen.
> * **Rundungsfehler:** Nicht alle Zahlen sind exakt darstellbar (z.B. $0.2_{10}$ ist im Binärsystem periodisch).