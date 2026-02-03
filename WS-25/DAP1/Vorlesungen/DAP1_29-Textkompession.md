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