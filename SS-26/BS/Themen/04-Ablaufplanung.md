#bs **13.05.2026**

>[!info] Wiederhohlung
>- ***Prozesse:*** ==die== zentrale **Abstraktion** für Aktivitäten in heutigen betriebssystemen 
>	- *Konzeptionell unabhängig ve sequentielle Kontrollflüsse* (Folge von CPU- und E/A-Stößen)
>	- Tatsächlich findet ein **Multiplexing** der CPU statt
>- ***UNIX-Systeme*** stellen diverse **System Calls** zur verfügung, um Prozesse zu erzeugen, zu verwalten und miteinander zu verknüpfen 
>	- Moderne Betriebssysteme unterstützen darüber hinaus auch leicht- & federgewichtige Prozesse
>- Prozesse unterliegen der ***Kontrolle des Betriebssystems:***
>	- Betriebsmittel-Zuteilung / -Entzug

![[Pasted image 20260514150132.png]]

___
___
# Prozesszustände und Zustandsübergänge

## Prozesszustände vs. Einplanungsebene

Jeem Prozess ist in Abhängigkeit von der ***Einplanungsebene*** ein *logischer Zustand* zugeordnet, der den ***Prozesszustand*** zu einem Zeitpunkt angibt:

- **kurzfristig** *(short-term scheduling)* 
  ⤷ bereit, laufend, blockiert

- **mittelfristig** *(medium-term scheduling)*
  ⤷ ausgelagert bereit, ausgelagert blockiert

- **langfristig** *(long term scheduling)*
  ⤷ erzeugt, beendet

___
##### Kurzfristige Einplanung

- ***bereit*** *(READY)* zur Ausführung durch den Prozessor
	- Prozess ist auf der **Bereitliste** *(ready list)* für Einlastung
	- Listenposition bestimmt sich durch das Einplanungsverfahren

- ***laufend*** *(RUNNING)* Zuteilung des Betriebsmittels CPU ist erfolgt
	- Prozess fürt Berechnungen durch, er vollzieht seinen CPU-Stoß
	- Für jeden Prozessor gibt es **zu einem Zeitpunkt nur einen laufenden Prozess**
 
- ***blockiert*** *BLOCKED* auf ein bestimmtes Ereignis
	- Prozess führt "Ein-/Ausgabe" durch, er vollzieht seinen E/A-Stoß
	- Er erwartet die Erfüllung mind. einer Bedingung

___
##### Kurzfristige Einbplanung

**Prozess ist komplett ausgelagert**, d.h. der Inhalt seines gesamten Adressraums wurde in den Hintergrundspeicher verschoben (swap-out) und der von dem Prozess belegte Vordergrundspeicher wurde freigegeben.

Die **Einagerung** (swap-in) des Adressraums ist **abzuwarten**: 

- ***ausgelagert bereit*** *(READY SUSPEND)*
	- CPU-Zuteilung ("bereit") ist außer Kraft gesetzt
	- Prozess ist auf der Warteliste für die Speicherzuteilung 

- ***ausgelagert blockiert*** *(BLOCKED SUSPEND)*
	- Prozess erwartet weiterhin ein Ereignis ("blockiert")
	- Tritt das Ereignis ein, wird der Prozess **"ausgelagert bereit "**

___
##### Langfristige Einplanung

- ***erzeugt*** *(NEW)* und fertig zur Programmverarbeitung -`fork(2)`
	- **Prozess ist instanziiert**, ihm wurde ein Programm zugeordnet
	- Ggf. steht die Zuteilung des Betriebsmittels "Speicher" noch aus

- ***beendet*** *(EXIT)* und erwartet die Entsorgung - `exit(2)` / `wait(2)`
	- **Prozess ist termniert**, seine Betriebsmittel werden Freigegeben
	- Ggf. muss ein anderer Prozess den *"Kehraus"* vollenden (wie z.B. unter UNIX)

___
### Zustandsübergänge
![[Pasted image 20260514154632.png]]

- Jeder Übergang in den zustand **bereit** *(READY)* aktualisiert die CPU- Warteschlange:
	- Entscheidung über die EInreihung des Prozesskontrollblocks
	- Ergebnis hängt von Planungsstrategie ab

- ***Einplanung/Umplanung*** *((re-)scheduling)* erfolgt, ...
  1. nachdem ein Prozess erzeugt worden ist
  2. wenn ein Prozess freiwillig die Kontrolle über die CPU abgibt
  3. sofern das von von einem Prozess erwartete Ereignis eingetreten ist
  4. sobald ein ausgelagerter Prozess wieder aufgenomen wird

- Ein Prozess kann dazu gedrängt werden die CPU abzugeben → **präemptive Ablaufplanung**

___
___
# Klassische Planungsstrategien
## FCFS
***First-Come First-Served***

Einfaches und "gerechtes" Verfahren: 
⤷ *"Wer zuerst kommt, mahlt zuerst."*
- Einreihungskriterium ist die **Ankunftszeit** eines Prozesses
- Arbeitet *nicht verdrängend* und setzt **kooperative Prozesse** voraus
- Minimiert die Zahl der Kontextwechsel 

##### Beispiel
 ![[Pasted image 20260515001629.png]]
⤷ Durchlaufzeit von $C$ steht in einem sehr schlechten Verhältnis zur Bedienzeit $T_{s}$
	⤷ Sehr hohe normalisierte Durchlaufzeit $\left( \frac{T_{r}}{T_{s}} \right)$

#### Der Konvoi-Effekt

- Problem betrifft immer **kurz laufende E/A-lastige Prozesse**, die auf lange CPU-lastige Prozesse folgen
	- Prozesse mit *langen CPU-Stößen* werden ***begünstigt***
	- Prozesse mit *kurzen CPU-Stößen* werden ***benachteiligt***

- Resultierender ***Konvoi-Effekt*** verursacht Probleme:
	- hohe Antwortzeit "schneller" Prozesse *(warten auf "langsame")*
	- niedriger E/A-Durchsatz *(Annnahme kurzer CPU → langer E/A-Stoß)*

- Bei einem *Mix von CPU- und E/A-lastigen Prozessen* ist **FCFS** daher **ungeeignet**
  ⤷ typisch in reinen ***Stapelverarbeitungssystemen***

___
## RR
***Round Robin***

Verringert die Benachteiligung kurzer CPU-Stöße:
⤷ *"Jeder gegen jeden"*
	Die **Prozessorzeit** wird in ***Zeitscheiben*** aufgeteilt (*time slicing*)

- Mit *Ablauf der Zeitscheibe* erfolgt ggf. ein **Prozesswechsel**:
	- Unterbrochener Prozess wird ans Ende der Bereitliste verdrängt
	- Nächster Prozess wird gemäß **FCFS** entnommen

- Zeitgeber bewirkt ***Unterbrechung*** am Ende der Zeitscheibe

- ***Zeitscheibenlänge*** bestimmt Effektivitet des Verfahrens
	- **zu lang:** Degenerierung zu *FCFS*; **zu kurz:** hohe *Verwaltungsgemeinkosten*
	- **FAUSTREGEL:** etwas länger als Dauer einer "typischen Interaktion"

#### Leistungsprobleme

- ***E/A-lastige Prozesse*** bennden ihren CPU-Stoß frühzeitig innerhalb ihrer Zeitscheibe
	- Sie **blockieren** und kommen mit Ende ihres E/A-Stoßes in die Bereitliste

- ***CPU-lastige Prozesse*** schöpfen dagegen ihre Zeitscheibe voll aus
	- sie werden **verdrängt** und kommen sofort wieder in die Bereitliste

- Die CPU-Zeit ist **zu Gunsten CPU-lastiger Prozesse** ungleich verteilt!
	- *E/A-lastige Prozesse* werden schlecht bedient und dadurch Geräte schlechter ausgelastet
	- *Varianz der Antwortzeit* E/A-lastiger Prozesse erhöht sich

### VRR
*Virtual Round Robin*

- ***Vermeidet*** die bei *RR* mögliche ***ungleiche Verteilung der CPU-Zeiten***
	- Prozesse kommen mit Ender ihrer E/A-Stöße in eine **Vorzugsliste**
	- Diese Liste wird *vor der Bereitliste abgearbeitet*

- VRR arbeitet mit ***Zeitscheiben unterschiedlicher Längen*** 
	- Prozesse der *Vorzugsliste* bekommen *keine volle Zeitscheibe zugeteilt:*
	  Ihnen wird die **Restlaufzeit ihrer vorher nicht voll genutzten Zeit** gewährt. 
	- Sollte ihr CPU-Stoß länger dauern, werden sie in die *Bereitliste* verdrängt.

- Die Prozessabfertigung ist dadurch *im Vergleich zu RR* ***etwas aufwändiger***. 

___
## SPN
***Shortest Process Next***

Verringert die auftretende Benachteiligung kirzer CPU-Stöße: 
*"Die Kleinen nach vorne*
	Grundlage dafür ist die **Kenntnis über die Prozesslaufzeiten**
	Verdrängung findet nicht statt

- ***Hauptproblem:*** Vorhersage der Laufzeiten
	- **Stapelbetrieb:** Programmierer geben das erforderliche *time limit* vor
	- **Dialogbetrieb:** Schätzung aus früheren Stoßlängen des Prozesses

- Antwortzeiten werden verkürzt und die Gesamtleisung steigt. 
	Dafür: Gefahr der **Aushungerung** (*starvation*) CPU-lastiger Prozesse 

##### CPU-Stoßdauer
Basis für die ***Schätzung*** ist die *Mittelwertbildung* über alle bisherigen CPU-Stoßlänfen eines Prozesses: $$S_{n+1} = \frac{1}{n}\sum^n_{i=1}T_i = \frac{1}{n}T_{n} + \frac{n-1}{n}S_{n}$$
- ***Problem:*** gleiche **Gewichtung** aller CPU-Stöße
	- *Jüngere CPU-Stöße* sind jedoch von größerer Bedeutung als ältere und sollten daher auch mit größerer Gewichtung berücksichtigt werden!

- Ursache ist das ***Lokalitätsprinzip*** 
	- Daten und Instruktionen sind anfangs nicht im CPU-nahem Speicher verfügbar

##### Stoßgewichtung
Zurückliegende CPU-Stöße sollen weniger Gewicht erhalten: $$S_{n+1} = \alpha T_{n}+(1-\alpha)S_{n}$$Für den konstanten Gewichtungsfaktor $\alpha$ gilt dabei $0 < \alpha < 1$. Er drückt die relative Gewichte einzelner CPU-Stöße der Zeitreihe aus.

- Rekursive Einsetzung führt zu ... $$\begin{align} S_{n+1} & = \alpha + (1 - \alpha)\alpha T_{n-1} + \cdots + (1 - \alpha)^i\alpha T_{n-1} + \cdots + (1-\alpha)^n S_{1} \\ & = \alpha \sum^{n-1}_{i = 0} (1-\alpha)^i T_{n-i} + (1-\alpha)^n S_{1} \end{align}$$
  ⤷ dieses statistische Verfahren nennt man auch **exponentielle Angleichung**

___
## SRTF
***Shortest Remaining Time First***

Erweitert den *SPN*-Ansatz um ***Verdrängung***
	Dadurch geeignet für den Dialogbetrieb
	Führt zu besseren Durchlaufzeiten

- Der laufende ***Prozess wird verdrängt**,* wenn gilt: $T_{\text{erw}} < T_{\text{rest}}$
	- $T_{\text{erw}}$ ist die **erwartete CPU-Stoßlänge** eines *eintreffenden* Prozesses
	- $T_{\text{rest}}$ ist die **verbleibende CPU-Stoßlänge** des *laufenden* Prozesses
	- In der Folge selektiert der Scheduler immer den Prozess mit der kürzesten verbleibenden Ausführungszeit

- Anders als RR basiert SRTF ***nicht auf Zeitgeberunterbrechungen***, ist aber **präemptiv**
	- Dafür müssen allerdings Stoßlängen festgelegt werden. 

- WIe SPN kann auch SRTF *Prozesse zum **Verhungern** bringen*.

___
## HRRN
***Highest Response Ratio Next***

- Vermeidet das bei *SRTF* mögliche Verhungern von CPU-lastigen Prozessen
	- Das ***Altern** (Aging)*,d.h. **Wartezeit von Prozessen**, wird berücksichtigt $$R = \frac{w+s}{s}$$⤷ $w$ ist die bisherige *Wartezeit des Prozesses*
	  ⤷ $s$ ist die *erwartete Bedienzeit*

- Ausgewählt wird immer der Prozess mit dem **größten Verhältniswert $R$**.

#### Feedback -FB

- ***Begünstigt kurze Prozesse***, ohne die relativen Längen der Prozesse abschätzen zu müssen.
	- Grundlage ist die **Bestrafung** (*penaltization*) **von "Langläufern"** 
	- Prozesse unterliegen dem *Verdrängingsprinzip*

 - ***Mehrere Bereitlisten*** kommen zum Einsatz, *je nach Anzahl von Prioritätsebenen*:
	 - Wenn ein Prozess **erstmalig** eintrifft, läuft er auf **höchster Ebene**
	 - Mit **Ablauf der Zeitscheibe** kommt er in die **nächst niedrigere Ebene**
	 - Die unterste Ebene arbeitet nach *RR*.

- ***Kurze Prozese*** laufen *relativ schnell* durch, ***lange Prozesse*** können *verhungern*.
	- Wartezeit kann berücksichtigt werden, um wieder höhere Ebenen zu erreichen (**anti-aging**)

![[Pasted image 20260513163430.png]]

>[!question] Diskussion: Prioritäten 
>- **Prozess-"Vorrang"**, der Zuteilungsentscheidungne maßgeblich beeinflusst
>___
>- **Statische Prioritäten** werden zum *Zeitpunkt der Prozesserzeugung* festgelegt:
>	- Wert kann im Nachhinein nicht mehr verändert werden 
>	- erzwingen *deterministische Ordnung* zwischen Prozessen
>___
>- **Dynamische Prioritäten** werden während der Prozesslaufzeit aktualisiert:
>	- Aktualisierung erfolgt im Betriebssystem, aber auch vom Benutzer aus 
>	- SPN, SRTF, HRRN und FB sind Spezialfälle dieses Verfahrens


## Kombinationen - Multilevel Scheduling

- Mehrere Betriebsformen lassen sich nebeneinander betreiben
	- z.B. gleichzeitige Unterstützung von {Dialog- & Hintergrundbetrieb, Echtzeit- & sonstigem Betrieb}
	- Dialogorientierte bzw. zeitkritische Prozesse werden bevorzugt bedient.

- Die Umsetzung erfolgt typischerweise über mehrere Bereitlisten.
	- Jeder Bereitliste ist eine bestimmte Zuteilungsstrategie zugeordnet
	- Listen werden typischerweise nach Priorität, FCFS oder RR vrearbeitet
	- Ein höchst komplexes Gebilde → multi-level feedback (MLFB)

- FB kann als Spezialfall dieses Ferfahrens aufgefasst werden

  ![[Pasted image 20260513164519.png]]

___
___

# Bewertungskriterien & Vergleich

### Ziele = Bewertungskriterien

- ***Benutzerorientiert*** → Penis (Grüße an Rahul)
	  
	- **Durchlaufzeit:** Zeit zwischen Eingang und Abschluss eines Prozesses einschl. der Wartezeit(en) → *Stapelverarbeitung* 
	  
	- **Antwortzeit:** Zeit zwischen Benutzereingabe und Antwort → *interaktive Systeme*
	  
	- **Termineinhaltung:** Für die Interaktion mit äußeren physikalischen Prozessen sollten Termine eingehalten werden → *Exhtzeitsysteme* 
	  
	- **Vorhersagbarkeit:** Prozesse werden unabhängig von der Last immer gleich bearbeitet → *harte Echtzeitsysteme*

- ***Systemorientiert***
	
	- **Durchsatz:** mögl. viele Prozesse pro Zeiteinheit abarbeiten 
	  
	- **Auslastung:** CPU immer beschäftigen → *Verwaltungsallgemeinkosten (Overhead)* (z.B. Scheduling, Kontextwechsel) vermeiden
	  
	- **Fairness:** Kein Prozess soll benachteiligt werden (z.B. Aushungern)
	  
	  - **Lastausgleich:** Auch E/A-Geräte sollen gleichmäßig ausgelastet werden.

##### Gegenüberstellung - quantitativ
![[Pasted image 20260513170009.png]]

##### Gegenüberstellung - qualitativ
![[Pasted image 20260513170115.png]]

___

# Beispiele

#### UNIX
![[Pasted image 20260513170153.png]]

##### 4.3 BSD
![[Pasted image 20260513170232.png]]
![[Pasted image 20260513170243.png]]


#### Windows NT - Prioritätsklassen & -anpassung
![[Pasted image 20260513170439.png]]
![[Pasted image 20260513170502.png]]

___
___

>[!note] ***Zusammenfassung***
>- **Betriebssysteme treffen Planungsentscheidungen auf drei Ebenen:**  
> 	 1. *Long-Term Scheduling:* Zulassung von Prozessen zum System
> 	 2. *Medium-Term Scheduling:* Aus- & Einlagerung von Prozessen
> 	 3. *Short-Term Scheduling:* kurzfristige CPU-Zuteilung
>___
>- **Alle hier betrachteten Verfahren werden dem Short-Term Scheduling zugerechnet.**
>	- Es gibt diverse benutzer- & systemorientierte Kriterien für die Beurteilung der Eigenschaften eines CPU-Zuteilungsverfahrens
>	- Die Auswahl kommt einer Gratwanderung gleich
>	- Das "beste" Verfahren lässt sich nur nach einer Analyse des typischen Anwendungsürpfils und aller Randbedingungen finden. 

