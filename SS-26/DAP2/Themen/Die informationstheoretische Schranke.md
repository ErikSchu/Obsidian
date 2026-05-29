*05.05.2026*
https://ls2-web.cs.tu-dortmund.de/~mamicoja/dap2/slides/lec_inf.pdf

>[!note] **Vergleichbarkeit**
>- für je zwei Elemente $l_{i}, l_{j}$ gilt entweder $l_{i} < l_{j}$, $l_{i} = l_{j}$ oder $l_{i} > l_{j}$
>- die Ordnung ist *transitiv*: $l_{h} \le l_{i} \land l_{i} \le l_{j} \implies l_{h} \le l_{j}$
>- die Ordnung ist *antisymmetrisch*: $l_{i} \le l_{j} \land l_{j} \le l_{i} \implies l_{i} = l_{j}$
>- wir haben Zugruff auf eine Funktion, die zwei Elemente $l_{i}, l_{j}$ vergleicht 

>[!question] Frage
>Quicksort hat eine Laufzeit von $O(n \log n)$
> ⤷ geht es besser?


***Vergleichsbasierte Algorithmen***

- deGuten Tag,

mein Name ist Erik Schulze und ich hatte mein Fahrzeug (ein schwarzer Ford Fiesta, Baujahr 2017, altes Modell) bereits vor ein paar Monaten bei Ihnen zum TÜV und Zahnriemenwechsel.
Gerne würde ich auch meine Reifen bei Ihnen wechseln lassen, was Sie laut Ihrer Internetseite ja auch anbieten.
Allerdings wäre es mir wichtig, dass ich meine Winterreifen bei Ihnen einlagern kann, da ich selbst keine Lagerungsmöglichkeit habe.
Ist das möglich bzw. bieten Sie das an?

LG Erik Schulzer Algorithmus greift auf seine Eingabe *nur* durch Vergleichsanfragen zu
- die Eingabe einer solchen Anfrage ist in Paar von Listenelementen
- die Antwort ist entweder < oder = oder >
- **Beispiele:** Quick-, Merge-, Heapsort


>[!TIP] **Satz**
>Angenommen $\mathcal A$ ist ein deterministischer vergleichsbasierter Sortieralgorithmus.
>Für die erwartete Zahl $X_{n}(\mathcal A)$ von Vergleichen, die $\mathcal A$ zum Sortieren einer zufälligen $n$-Permutation benötigt gilt $$\boxed {X_{n} (\mathcal A) = \Omega (\log(n!))}$$

