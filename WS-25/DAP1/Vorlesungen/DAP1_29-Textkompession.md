#dap1 

#### Klausur

- Wir tragen die Studienleistung bald ein – dann können Sie sich anmelden
- Stud. mit **Nachteilsausgleich** Email an dap1.cs@tu-dortmund.de
    - ebenso Schülerstud.
- Weitere Infos zur Klausur folgen per Moodle-Ankündigung
- bitte bereits 10 Minuten vor Beginn am Hörsaal sein
- Mitbringen:
    - Lichtbildausweis
    - Klausurzettel **mit Matrikelnummer** (damit **Sie** sie wissen!!)
        - doppelseitiges, handbeschriebenes und ohne Hilfsmittel lesbares DIN-A4-Blatt
    - Stift: dunklen Kugelschreiber oder Fineliner
    - **keine Handys, Armbanduhren, oder sonstige mechanischen oder elektronischen Geräte**

# Textkompression

>[!example] Problemstellung
>Textdateien sind oft zu groß. Wie kann man diese ***komprimieren***?
>___
>⤷ Anwendungsszenarien
>- Platz auf Festplatte/SSD/... sparen
>	- zur Archivierung
>	- bei hochredundanten Daten, z.B. log-Files
>- Transport von Daten, insbes. über netzwerke

## Lempel-Ziv-78

Ein von *Abraham Lempel* und *jacob Ziv* 1978 entwickeltes **Kompressionsverfahren**
⤷ eingesetzt in GIF, PDF, compress, ...

***Idee:*** nutze aus, wenn sich Teilstrings wiederholen (z.B. $T = \text{anatanarivo}$ (Hauptstadt von Madagaskar))

Ein ***Trie*** ist ein gewurzelter Baum
- Knoten nummeriert
- Kanten mit *Buchstaben* beschriftet
- $s(v)=$ String, der sich aus der Kantenbeschriftung von der Wurzel zu $v$ ergibt

>[!note] Algorithmus zur Kompression von $T[0,n], T[n]= 0$:
>1. Starte mit Trie, der nur aus der Wurzel besteht (Nummer 0)
>2. Sei $T[0, i-1]$ bereits komprimiert (am Anfang $i = 0$)
>3. Suche das *längste Präfix* $T[i,j]$ von $T[i,n]$, für das es einen Knoten $v$ im Trie mit $s(v) = P$ ibt
>	- füge neuen Knoten $w$ als Kind von $v$ an
>		- $w$ erhält die kleinste noch nicht vergebene Nummer 
>		- beschrifte Kante $(v,w)$ mit $T[j+1]$
>	- gib Paar (Knotennummer von $v$, $T[j+1]$) aus; damit ist $T[0, j+1]$ komprimiert; gehe zurück zu 1.

>[!attention] .
>LZ78 gibt eine Folge $(n_{i}, c_{i})$ von $z$ Paaren (Knotennummer, Buchstabe) aus, so dass $$T = s(n_{1})c_{1} \ s(n_{2})c_{2} \ \dots \ s(n_{z})c_{z}$$


#### Ist das reversibel (d.h. dekomprimierbar)?

Ja! Einfach den Algorithmus simulieren!
>[!question] Quiz
>Welcher String wird durch $$$$

