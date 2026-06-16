#bs **10.06.2026**

>[!note] Wiederholung: ***Betriebsmittel*** 
>- Das Betriebssystem hat folgende Aufgaben:
>	- Verwaltung der Betriebsmittel des Rechners 
>	- Schaffung von Abstraktionen, die Anwendungen und einen einfachen und effizienten Umgang mit Betriebsmitteln erlauben
>- Bisher: **Prozesse**
>	- Konzept zur Abstraktion von der realen CPU
>- Nun: **Speicher** 
>	- Verwaltung von Haupt- und Hintergrundspeicher 
>![[Pasted image 20260610164040.png]]

>[!note] Wiederholung: ***Mehrprogrammbetrieb***
>- CPU-Auslastung unter Annahme einer bestimmten E/A-Wahrscheinlichkeit: $$A = 1 - p ^ n$$ ![[Pasted image 20260610164442.png]]
>→ Mehrprogrammbetrieb ist essentiell für eine hohe Auslastung
>- Beim Starten und Beenden der Prozesse muss dynamisch Speicher zugewiesen bzw. zurückgenommen werden

___

# Grundlegende Aufgaben der Speicherverwaltung 

## Anforderungen

**Mehrere Prozesse benötigen** Hauptspeicher
- Prozesse liegen *an verschiedenen Stellen* im Hauptspeicher
- *Schutzbedürfnis des Betriebssystems* und der Prozesse untereinander
- *Speicher reicht evtl. nicht* für alle Prozesse


![[Pasted image 20260616081502.png]]

→**Freie Speicherbereiche** kennen, verwalten & vergeben
→ **Ein-/Auslagern** von Prozessen
→ **Relokation** von Programmbefehlen
→**Hardwareunterstützung** ausnutzen

___

## Grundlegende Politiken/Strategien
***... auf jeder Ebene der Speicherhierarchie:***

- **Platzierungsstrategie** (*placement policy*)
	- ==Woher== soll benätigter Speicher genommen werden?
		- wo der Verschnitt am kleinsten/größten ist
		- egal, weil Verschnitt zweitrangig ist

- **Ladestrategie** (*fetch policy*)
	- ==Wann== sind Speicherinhalte einzulagern?
		- auf Anforderungen oder im Voraus

- **Ersetzungsstrategie** (*replacement policy*)
	- ==Welche== Speicherinhalte sind ggf. zu verdrängen, falls der Speicher knapp wird?
		- älteste, am seltensten genutzte
		- an längsten ungenutzte

![[Pasted image 20260616082054.png]]

___
___

# Speichervergabe

## Problemstellung

Verfügbarer (physischer) Speicher 
![[Pasted image 20260616082219.png]]

Belegung des Hauptspeichers durch ...
- **Benutzerprogramme**
	- Programmbefehle (*Text*)
	- Programmdaten (*Data*)
	- Dynamische Speicheranforderungen (*Stack*, *Heap*)
- **Betriebssystem**
	- Betriebssystemcode/-daten
	- Prozesskontrollblöcke
	- Datenpuffer für Ein-/Ausgabe
	- ...

→ ==Zuteilung des Speichers nötig==

___

### Statische Speicherzuteilung
**Feste Bereiche** für *Betriebssystem* und *Benutzerprogramme*
>[!caution] Probleme
>- Grad des Mehrprogrammbetriebs begrenzt
>- Begrenzung anderer Ressourcen (z.B. Bandbreite bei Ein-/Ausgabe wegen zu kleiner Puffer)
>- Ungenutzter Speicher des Betriebssystems kann von Anwendungsprogrammen nicht genutzt werden und umgekehrt. 

### Dynamische Speicherzuteilung
- **Segmente** → zusammenhängende Speicherbereiche (d.h. aufeinanderfolgende Adressen)
- **Allokation** (Belegung) und **Freigabe** von Segmenten 
- Ein Anwendungsprogramm besitzt üblicherweise folgende Segmente:
	- Textsegment
	- Datensegment
	- Stapelsegment (lokale Variablen, Parameter, Rüclsprungadressen, ...)
- Suche nach geeigneten Speicherbereichen zur Zuteilung
	- insbesondere bei Programmstart
> [!question] Platzierungsstrategien nötig
> Besonders wichtig dabei: ***Freispeicherverwaltung***

#### Freispeicherverwaltung
Freie (evtl. auch belegte) Segmente des Speichers müssen repräsentiert werden $\leadsto$ ***Bitlisten***
![[Pasted image 20260616161758.png]]
>[!attention] Probleme
>- Bitliste kostet u.U. viel Speicher
>- Bei der Freigabe muss man die Größe des freizugebenden Speichers kennen bzw. mit angeben

##### $\leadsto$  Verkettete Liste
![[Pasted image 20260616162031.png]]
>[!attention] Problem
>Für die Liste wird (dynamisch) Speicher benötigt.

##### $\leadsto$ Verkettete Liste ==im freien Speicher==
![[Pasted image 20260616162229.png]]
- zur Effizienzsteigerung eventuell Rückwertsverkettung nötig
- Repräsentation letztlich auch von der Vergabestrategie abhängig

***Verschmelzung von Lücken:***
![[Pasted image 20260616162458.png]]

## Platzierungsstrategien
... auf der Basis von unterschiedlich sortierten Löcherlisten:

- **First Fit** (Sortierung nach Speicheradresse)
	- erste passende Lücke wird verwendet

- **Rotating First Fit** / **Next Fit**