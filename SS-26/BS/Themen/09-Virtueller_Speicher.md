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

## Ersetzungsstrategien 

- ***Referenzfolge***
	- **Speicherzugriffsverhalten** eines Prozesses → Folge von Seitennummern
	- Ermittlung von Referenzfolgen z.B. durch Aufzeichnung der zugegriffenen Adressen
		- Reduktion der aufgezeichneten Sequenz auf Seitennummern
		- Zusammenfassung von unmittelbar folgenden Zugriffen auf die Seite
	- *z.B.* $1, 2,3 , 4, 1, 2, 5, 1, 2, 3, 4, 5$

### FIFO

- **älteste Seite wird ersetzt**
- Notwendige Zustände:
	- Alter bzw. Einlagerungszeitpunkt für jeden Seitenrahmen
- Ablauf der Ersetzungen (9 Einlagerungen) ![[Pasted image 20260721091612.png]]
- Größerer Hauptspeicher mit 4 Seitenrahmen (10 Einlagerungen!)
- FIFO-Anomalie (Beledys Anomalie, 1969) ![[Pasted image 20260721092035.png]]


> [!note] ### Optimale Seitenersetzungsstrategie
>- ***Vorwärtsabstand***
>	- Ersetze die Seite die am längsten wnich referenziert **wird**
>	- Strategie OPT (oder MIN) ist optimal (bei fester Seitenrahmenzahl):
>	  →*Minimale Anzahl von Umlagerungen* (hier 7)
>		- Wähle die Seite mit dem größten Vorwärtsabstand![[Pasted image 20260723102603.png]]
>	- Verhrößerung des Hauptspeichers ($ Seitenrahmen)
>	  → *6 Einlagerungen*
>		- keine Anomalie ![[Pasted image 20260723102712.png]]
>___
>- Implementierung von OPT leider ***praktisch unmöglich***
>	- Referenzfolge müsste *vorher bekannt* sein
>	- OPT ist *nur zum Vergleich von Strategien* brauchbar
>	→ Suche nach Strategien , die **möglichst nahe an OPT kommen**
>		- z.B. Last Recently used (LRU)

### Last Recently Used (*LRU*)

- ***Rückwertsabstand***
	- Zeitdauer seit dem letzten Zugriff auf die Seite
- LRU-Strategie (*10 Einlagerungen*)
	- Wähle den Seitenrahmen mit dem größten Rückwertsabstand ![[Pasted image 20260723103734.png]]
- Vergrößerung des Hauptspeichers (4 Seitenrahmen):
  *8 Einlagerungen*  ![[Pasted image 20260723103809.png]]

- **Keine Anomalie**
	- Allgemein gilt: Es gibt eine Klasse von Algorithmen (*Stack Algorithmen*), bei denne keine Anomalie auftritt:
		- Bei den Stack-Algorithmen ist bei $k$ Rahmen zu jedem Zeitpunkt eine Teilmenge der seiten eingelagert, die bei $k+1$ Rahmen zum gleichen Zeitpunkt eingelagert wären
		- *LRU:* Es sind immer die letzten $k$ benutzten Seiten eingelagert.
		- *OPT:* Es sind die $k$ bereits benutzten Seiten eingelagert, die als nächstes zugegriffen werden 
- ***Problem:***
	- Implementation von LRU **nicht ohne Hardwareunterstütung** möglich. 
	- Es muss *jeder Speicherzugriff* berücksichtigt wede.

- **Hardwareunterstützung**
	- CPU besitzt einen Zähler, der bei jedem Speicherzugriff inkrementiert wird
	- bei jedem Zugriff wird der aktuelle Zählerwert in den jeweiligen Seitendeskriptor geschrieben
	- Auswahl der Seite mit dem kleinsten Zählerstand (→ Suche)
	  
	- **Aufwändige Implementierung:**
		- viele zusätzliche Speicherzugriffe
		- hoher SPeicherplatzbedarf
		- Minimum-Suche in der Seitenfehler-Behandlung

### Second chance (*Clock*)

- ***Einsazt von Referenzbits***
	- **im Seitendeskriptor** automatisch durch Hardware gesetzt, wenn die Seite zugegriffen wird
		- *einfacher* zu implementieren
		- *weniger* zusätzliche Speicherzugriffe
		- moderne Prozessoren bzw. MMUs unterstüzten Refeerenzbits (z.B. x86: access bit)

- ***Ziel:*** Annäherung von LRU
	- bei einer frisch eingelagerten Seite wird das Referenzbit zunächst auf 1 gesetzt
	- wird eine Opferseite gesucht, so werden die Seitenrahmen reihum inspiziert
		- ist das Referenzbit `1`, so wird es auf 0 gesetzt (zweite Chance)
		- ist das Referenzbit `0`, so wird die Seite ersetzt

-  ***Implementierung*** mit **umlaufendem Zeiger** (*Clock*)![[Pasted image 20260723105634.png]]
	- an der Zeigerposition wird das Referenzbit getestet
		- falls `1`, wird es gelöscht
		- falls `0`, wurde ersetzbare Seite gefunden
		- Zeiger wird weitergestellt; falls keine Seite gefunden: Wiederholung
	- falls alle Referenzbits auf $1$ stehen wird *Second Chance* → *FIFO*

- Ablauf bei drei Seitenrahmen (*9 Einlagerungen*) ![[Pasted image 20260723105742.png]]
- Vergrößerung des Hauptspeichers (4 Seitenrahmen): *10 Einlagerungen*![[Pasted image 20260723105842.png]]

- Es kann auch zur ***FIFO-Anomalie*** kommen:
	- alle Ref’bits `1` → Entscheidung nach FIFO
	→ Im Normalfall kommt man aber LRU nahe.

- **Erweiterung:**
	- ***Modifikationsbit*** kann zusätzlich berücksichtigt werden (*Dirty Bit*)
	- Drei Klassen: $(0,0), (1, 0), (1, 1)$ mit $(\text{Referenzbit}, \text{Modifikaitonsbit})$
	- Suche nach der niedrigsten Klasse (Einsatz in MacOS)

## Diskussion: ***Freiseitenpuffer***

***Freisetenpuffer*** beschleunigt die Seitenfehlerbehandlung

- Statt eine Seite zu ersetzen, wird permanent eine Menge freier Seiten gehalten
	- **Auslagerung geschieht im Voraus**
	- Effizienter: Ersetzungszeit besteht im Wesentlichen nur aus Einlagerungszeit

- Behalten der Seitenzahloordnung auch nach der Auslagerung 
	- Wird die Seite doch noch benutzt, bevor sie durch eine andere ersetzt wird, kann sie mit hoher Effizienz wiederverwendet werden.
	- Seite wird aus Freiseitenpuffer ausgetragen und wieder dem entsprechenden Prozesszugeordnet.

___

# Seitenzuordnung

## Zuordnung von Seitenrahmen zu Prozessen 

- ***Problem:*** Aufteilen der Seitenrahmen auf die Prozesse
	- Wie viele eingelagerte Seiten soll man einem Prozess zugestehen?
	- **Maximum:** begrenzt durch Anzahl der (physischen) Seitenrahmen? 
	- **Minimum:** abh. von Prozessorarchitektur (mind # Seiten nötig, die theoretisch bei einem Maschienenbefehl benötigt werden (z.B. zwei Seiten für den Befehl, vier Seiten für die adressierten Daten))

- **Gleiche Zuordnung**
	- \# Prozesse bestimmt die Menge, die ein Prozess bekommt

- **Größenabhängige Zuordnung**
	- Größe des Programms fließt in die zugeteilte Menge der Seitenrahmen ein

- ***Anforderung von Seiten***
	- **Lokal:** Prozess ersetzt nur immer seine eigenen Seiten
		- Seitenehler-Verhalten liegt nur in der Verantwortung des Prozesses
		- Keine Interferenz zwischen Prozessen
		- Auslagerung unter Umständen unnötig (global ungenutze Seiten)
	- **Global:** Prozess ersetzt auch Seiten anderer Prozesse
		- Ungenutzte Seitenrahmen anderer Prozesse können verwendet werden
		- Interferenz zwischen Prozessen (Seitehfehler-Verhalten)

## Seitenflattern (***Thrashing***)

- Ausgelagerte Seite wird gleich wieder angesprochen: 
	- Prozess verbringt mehr Zeit mit dem Warten auf das Beheben von Seitenfehlern, als mit der eigentlichen Ausführung. ![[Pasted image 20260723113218.png]]

- ***Ursachen:***
	- Prozess ist nahe am Seitenminimum 
	- Zu viele Prozesse gleichzeitig im System
	- Schlechte ersetzungsstrategie 

→ **Lokale Seitenanfrooorderung** behebt *Thrashing* zwischen Prozessen
→ Zuteilung einer genügend großen Zahl von Rahmen behebt Prozess-lokales *Thrashing* → **Begrenzung der Prozessanzahl**

#### 1. Lösung: *Auslagerung von Prozessen*
- inaktiver Prozess benötigt keinen Seitenrahmen
	- Seitenrahmen teilt sich auf weniger Prozesse auf
	- Verbindung mit *Scheduling* nötig 
		- Verhindern von Aushungerung 
		- Erzielen kurzer Reaktionszeiten ![[Pasted image 20260723113624.png]]

#### 2. Lösung: *Arbeitsmengenmodell*
- Seitenmenge , die ein Prozess wirklich Braucht (**Working Set**)
	- Kann nur angenähert werden, da üblicherweise nicht vorhersehbar
- Annäherung durch Betrachten der letzten $\Delta$ Seiten, die Angesprochen wurden 
	- geeignete Wahl von $\Delta$
		- *zu groß:* Überlappung von lokalen Zugriffsmustern
		- *zu klein:* Arbeitsmenge enthält nicht alle nötigen Seiten ![[Pasted image 20260723113940.png]]
	- *Hinweis:* $\Delta >$ Arbeitsmenge, da Seiten i.d.R. mehrfach hintereinander angesprochen werden 
>[!example] Beispiel: Arbeitsmengen bei verschiedenen $\Delta$
>![[Pasted image 20260723114124.png]]

##### Diskussion
- Annäherung der Zugriffe durch die Zeit
	- Bestimmtes Zeitintervall ist ungefähr Proportional zur Anzahl von Speicherzugriffen 
- Virtuelle Zeit des Prozesses muss gemessen werden
	- Nur die Zeit relevant, in der der Prozess im Zustand `RUNNING` ist
	- Verwalten virtueller Uhren pro Prozess

##### Arbeitsmengenbestimmung mit Zeitgeber
- Annäherung der Arbeitsmenge mit
	- Referenzbit
	- Altersangabe pro Seite (Zeitintervall ohne Benutzung)
	- Timer-Interrupt (durch Zeitgeber)
- **Algorithmus:**
	- durch regelmäßugen Interrupt wird mittels Ref’bit die Altersangabe fortgeschrieben:
		- ist Ref’bit gesetzt (Seite wurde benutzt), wird das Alter auf Null gesetzt;
		- ansonsten wird Altersangabe erhöht.
		- Es werden nur die Seiten des gerade laufenden Prozesses “gealtert”
	- Seiten mit Alter $> \Delta$ sind nicht mehr in der Arbeitsmenge des jeweiligen Prozesses.

→ ***Ungenau***
- System ist aber nicht emfindlich gegen diese Ungenauigkeit
- Verringerung der Zeitintervalle: höhere Aufwannd, genauere Messung

→ ***Ineffizient***
- große Mengee von Seiten zu betrachten

##### Arbeitsmengenbestimmung mit WSClock
- **Algorithmus** WSClock (working set clock)
	- Arbeitet wie Clock
	- Seite wird nur dann ersetzt