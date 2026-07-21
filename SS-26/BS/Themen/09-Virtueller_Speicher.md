#bs 

>[!note] #### Wiederholung
>- Bei der Speicherverwaltung arbeitet das Betriebssystem eng mit der Hardware zusammen
>	- **Segmentierung** und/oder **Seitenadressierung**
>	- Durch implizite Indirektion beim Speicherzugriff können Programme und Daten unter Kontrolle des Betriebssystems im laufenden Betrieb beliebig verschoben werden
>___
>- Zusätzlich zu treffende strategische Entscheidungen:
>	- ***Platzierungsstrategie** (First Fit, Best Fit, Buddy, …)*
>		- Unterschiede in Verschnitt, Belegungs- / Freigabeaufwand
>		- Strategieauswahl abhängig vom *erwarteten* Anwendungsprofil
>	- Bei Ein-/Auslagerung von Segmenten oder Seiten:
>		- **Logische** bzw. **virtuelle Seiten** und **physische Seiten** *(Kacheln)*
>		- Ladestrategie
>		- Ersetzungsstrategie

# Motivation
## Lokalität der Speicherzugriffe

- Instruktionen benötigen nur wenige Speicherseiten
- **Lokalität** auch über längere Zeiträume
	- Instruktionen werden *z.B.* eine nach der anderen ausgeführt
	- kann ausgenutzt weden, falls Speicher nicht reicht
		- *z.B.* “Overlay-Technik”

## Idee “Virtueller Speicher”

- ***Entkopplung*** Speicherbedarf $\Longleftrightarrow$ verfügbarer Hauptspeicher
	- Prozesse benötigen nicht alle Speicherstellen **gleich häufig**
		- bestimmte Befehle werden selten oder gar nicht benutzt (*z.B.* Fehlerbehandlungen)
		- bestimmte Datenstrukturen werden nicht voll belegt
	- Prozesse benötigen evtl. mehr Speicher als im Hauptspeicher vorhanden

- ***IDEE:***
	- **Vortäuschen** eines größeren *Arbeitsspeichers*
	- **Einblenden** aktuell benötigter Speicherbereiche
	- **Auslagern** nicht benötigter Bereiche
	- Abfangen von Zugriffen auf nicht eingeblendete Bereiche, **einlagern** der benötigten Bereiche auf Anforderung

___

# Demand Paging

#### Seitenumlagerung
Bereitstellung von Seiten auf Anforderung
![[Pasted image 20260721082405.png]]

#### Seitenfehler
Reaktion auf Seitenfehler *(page fault)*
![[Pasted image 20260721082617.png]]
![[Pasted image 20260721082542.png]]
![[Pasted image 20260721082641.png]]
![[Pasted image 20260721082658.png]]

## Kosten der Seitenumlagerung 

- ***Performanz von Demand Paging***
	- **ohne Seitenfehler**
		- effektive Zugriffszeit zwischen 10 und 200 Nanosekunden
	- **mit Seitenfehler**
		- $p$ sei Wahrscheinlichkeit für Seitenfehler
		- *Annahme:* 
		  Zeit zum Einlagern einer Seite vom Hintergrundspeicher entspricht 25 ms (8 Latenz + 15 ms Positionierung + 1 ms Übertragung),
		  normale Zugriffszeit: 100 ns
		- *effektive Zugriffszeit:* $$(1-p) \cdot 100 + p \cdot 25000000 = 100 + 24999900 \cdot p$$
- **Seitenfehlerrate muss extrem niedrig sein**

## Weitere Eigenschaften

- ***Prozesserzeugung***
	- **Copy-on-Write**
		- auch bei *paging* MMU leicht zu realisieren
		- feinere Granulatität als Segmentierung
	- Programmausführung und Laden erfolgen verschränkt
		- benötigte Seiten werden erst nach und nach geladen

- ***Sperren von Seiten***
	- notwendig bein E/A-Operationen 

## Segmentumlagerung
Prinzipiell möglich, hat aber Nachteile 

- **Grobe Granularität**
	- z.B. Code-, Daten-, Stack-Segment
- **Schwierige Hauptspeicherverwaltung**
	- Alle freien Seitenrahmen gleich gut für ausgelagerte Seiten.
	  Bei der Einlagerung von Segmenten ist die Speichersuche schwieriger.
- **Schwierigere Hintergrundspeicherverwaltung**
	- Hintergrundspeicher ist wie Seitenrahmen in Blöche strukturiert (2er-Potenzen)
$\implies$ ***In der Praxis hat ich Demand Paging durchgesetzt***

___

# Seitenersetzung 

- Eine **Seite muss verdrängt** werden, falls *kein freier Seitenrahmen* vorhanden
	- Auswahl von Seiten, die nicht geändert wurden (*dirty bit* in der ST)
	- Veränderung erfordert **Auslagerung, falls Seite geändert** wurde 

- ***Vorgang:***
	- Seitenfehler (*page fault*): Trap in das Betriebssystem
	- Auslagern einer Seite, falls kein freier Seitenrahmen verfügbar 
	- Einlagerung der benötigten Seite
	- Wiederholung des Zugriffs

- ***Problem:*** Welche Seite soll ausgewählt werden?

#### Ersetzungsstrategien 

- ***Referenzfolge***
	- **Speicherzugriffsverhalten** eines Prozesses → Folge von Seitennummern
	- Ermittlung von Referenzfolgen z.B. durch Aufzeichnung der zugegriffenen Adressen
		- Reduktion der aufgezeichneten Sequenz auf Seitennummern
		- Zusammenfassung von unmittelbar folgenden Zugriffen auf die Seite
	- *z.B.* $1, 2,3 , 4, 1, 2, 5, 1, 2, 3, 4, 5$

## FIFO

- **älteste Seite wird ersetzt**
- Notwendige Zustände:
	- Alter bzw. Einlagerungszeitpunkt für jeden Seitenrahmen 
