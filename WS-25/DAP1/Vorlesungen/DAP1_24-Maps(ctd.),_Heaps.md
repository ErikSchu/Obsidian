#dap1 
## Anwendung: Worthäufigkeiten

>[!example] .
>Schreibe ein Programm, das für einen Text $T$ eine Statistik über alle vorkommenden Wörter in $T$ erstellt, d.h. für alle Wörter $w \in T$ zählt, we oft $w$ in $T$ vorkommt-

- Beispiel
	- Eingabe:   ` T = To be or not to be, that is the question. `
	- Ausgabe:   ` TO : 1, be : 2, or : 1, not : 1, to: 1, ... `

##### Lösung mit Map
![[Pasted image 20260120133932.png]]
⤷ Zusatzaufgabe: die häufigsten 10 Wörter ausgeben
⤷ NB: ` std::map ` hat ein leicht anderes Interface

___

# Heaps & Priority Queues

## Abstrakte Datenstruktur Priority Queue ("Prioritätswarteschlange")

>[!note] Eine ***Prioritätswarteschlange*** (engl. *priority queue*, "PQ") mit Schlüsseln vom Typ $K$ und Werten vom Typ $V$ hat folgende Operationen:
>- `init(pq_name, capacity, K, V)`