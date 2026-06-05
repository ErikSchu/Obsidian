#bs

>[!info] Problem
>Wartemechanismen führen zu Verklemmungsproblemen

# Ursachenforschung
![[Pasted image 20260601231833.png]]
![[Pasted image 20260601232041.png]]
![[Pasted image 20260601232117.png]]

---

# Verklemmungen von Prozessen

Der **Begriff "Verklemmung"** bezeichnet in der Informatik $$\begin{align}
& \text{"[...] einen Zustand, in dem die beteiligten Prozesse} \\ & \text{wechselseitug auf den Eintritt von Bedingungen warten, die} \\ & \text{nur duch andere Prozesse in dieser Gruppe selbst hergestellt} \\ & \text{werden können."}
\end{align}$$
1. Variante: ***Deadlock***
	- *passives* Warten
	- Prozesszustand: **BLOCKED**

2. Variante: ***Livelock***
	- *aktives* Warten (("lazy") buisy waiting)
	- Prozesszustand **beliebig** (auch RUNNING), aber kein Fortschritt

⮩ *Deadlocks* sind das vergleichsweise **geringe Übel:**
- Zustand eindeutig erkennbar → Basis zur "Auflösung" gegeben
- Estrem hohe Systembelastung durch aktives Warten

>[!note] Bedingungen für eine Verklemmung
>Damit es zu einer Verklemmung kommen *kann*, müssen *alle* folgenden ***notewndigen Bedungungen*** erfüllt sein:
>1. Exklusive Belegung von Betriebsmitteln (**mutual exclusion**) 
> 	  umstrittene Betriebsmittel nur unteilbar nutzbar
>2. Nachforderung von Betriebsmitteln (**hold and wait**)
> 	  umstrittene Betriebsmittel nur schrittweise belegbar
>3. Kein Entzug von Betriebsmitteln (**no preemption**)
> 	  umstrittene Betriebsmittel nicht rückforderbar
>___
>Erst wenn zur Laufzeit die ***hinreichende Bedungung*** eintritt, liegt tatsächlich eine Verklemmung vor:
>4. Zirkuläres Warten (==**circular wait**==)
> 	  geschlossene Kette wechselseitig wartender Prozesse


## (nicht-) konsumierbare Betriebsmittel

**Betriebsmittel** werden vom Betriebssystem verwaltet und denProzessen zugänglich gemacht. Man unterscheidet zwei Arten:

***Wiederverwendbare Betriebsmittel***
- von Prozessen für bestimmte Zeit belegt und anschließend wieder freigegeben
- **Bsp.:** CPU, sämtlicher Speicher, E/A-Geräte, Systemdatenstrukturen wie Dateien, Prozessortabelleneinträge, ...
- Typische Zugriffssynchronisation: *gegenseitier Ausschluss*

***Konsumierbare Betriebsmittel***
- häufig im Laufenden system erzeugt (produziert) und zerstört (konsumiert)
- **Bsp.:** Unterbrechungsanforderungen, Signale, Nachrichten, Daten von Eingabegeräten
- Typische Zugriffssynchronisation: *einseitige Synchronisation*

#### Wiederverwendbare Betriebsmittel

- Es kommt zu einer ***Verklemmung***, wenn zwei Prozesse ein wiederverwendbares Betriebsmittel belegt haben, das *vom jeweils anderen* ***nachgefordert*** wird. 
- 
- **Bsp.:** EIn Rechnersystem hat $200 \text{ GByte}$ Hauptspeicher. Zwei Prozesse belegen den selben Speicher *schrittweise*. Die Belegung erfolgt *blockierend*.![[Pasted image 20260601234919.png]]

#### Konsumierbare Betriebsmittel

- Es kommt zu einer ***Verklemmung***, wenn zwei Prozesse auf ein konsumierbares *Betriebsmittel* ***warten***, das *vom jeweils anderen produziert* wird

- **Bsp.:** Synchronisationssignale werden mit Hilfe der Semaphoroperatoren *wait* und *signal* zwischen zwei Prozessen "verschickt". ![[Pasted image 20260601235248.png]]

## Modellierung durch Betriebsmittelbelegungsgraphen 

***engl. resource allocation graphs*** werden benutzt, um **Verklemmungssituationen zu visualisieren** und *automatisch zu erkennen*.

⮩ Beschreiben einen aktuellen Systemzustand
⮩ *Knoten:* Prozess & Betriebsmittel
⮩ *Kanten:* zeigen Aufforderung oder Belegung an 

![[Pasted image 20260603165106.png]]

**Frage:** Liegt zurkuläres Warten vor? Wer ist beteiligt? (Prozesse A-b, Betriebsmittel R-W)
![[Pasted image 20260603164719.png]]
![[Pasted image 20260603165252.png]]

___

# Ein klassisches Verklemmungsproblem

 >[!def] ## 5 Philosophen
 >![[Pasted image 20260603165515.png]]
 >⮩ **Prozess** → Pilosoph
 >⮩ **Betriebsmittel** → Gabel (unteilbar)
 >___
 >***3 NB:***
 >- **mutual exclusion:**
 >  Philosophen dürfen sich keine Gabeln teilen 
 >- **hold and wait:**
 >  Gabeln werden nicht gleichzeitig gegriffen; können nocht wieder weggelegt werden
 >- **ne preemttion**
 >  Gabeln werden nicht entrissen
>___
>***Version 1***
 >![[Pasted image 20260603170511.png]]
 >⤷ Mit Hilfe eines Semaphors wird *gegenseitiger Ausschluss* beim Zugriff auf die Gabeln garantiert. Jeder Philosoph nimmt erst seine rechte und dann seine linke Gabel.
 >![[Pasted image 20260603171642.png]]
 >⮩ **leider verklemmungsgefährdet**
 >![[Pasted image 20260603171702.png]]
 >___
 >***Version 2***
 >![[Pasted image 20260603172019.png]]
 >___
 >***Version 3***
 >![[Pasted image 20260603171936.png]]
 >___
 >***Diskussion***
 >- **Im Speziellen:** Es gibt viele Möglichkeiten für Verklemmungsfreiheit zu sorgen
 >	- Lösungen unterscheiden sich im Grad der mögl. Nebenläufigkeit 
 >	- Bei einer zu restriktiven Lösung liefen Betriebsmittel zweiteilig unnötig brach
 >- **Im Allgemeinen:** Repräsentatives Beispiel für Verklemmungsprobleme bei der Verwaltung unteilbarer Betriebsmittel 
 >	- Geht auf E. Dijakstra zurück
 >	- Etabliertes Standardszenario für die Bewertung und Illustration von Betriebssystem- & Sprachmechanismen zur nebenläufigen Programmierung 
 
 ___

# Gegenmaßnahmen, Verklämmungsbekämpfung

## Vorbeugung *(deadlock prevention)*

***Indirekte Methoden*** entkräften *eine der Beingungen 1-3*
 1. nicht-blockierende Verfahren verwenden
 2. Betriebsmittelanforderungen unteilbar (atomar) auslagern
 3. Betriebsmittelentzug durch **Virtualisierung** ermöglichen
	 - virtueller Speicher / -Geräte / -Prozessoren

***Direkte Methoden*** entkräften *Bedingung 4*
4. lineare/totale Ordnung von Betriebsmittelklassen einführen:
	- Betriebsmittel $B_{i}$ ist nur dann erfolgreich vor $B_{j}$ belegbar, wenn $i$ linear vor $j$ angeordnet ist (d.h. $i < j$)

⮕ **Regeln, die das Eintreten von Verklemmungen verhindern**
- Methoden, die zur *Entwurfs- bzw. Implementierungszeit* greifen

## Verklemmungsvermeidung *(deadlock avoidance)*

Verhinderung von ***zirkulärem Warten*** *(im Laufenden System)* durch strategische Maßnahmen
- keiner der ersten drei n.B. wird entkräftet
- fortlaufende **Bedarfsanalyse** schließt zirkuläres Warten aus 

***Betriebsmittelanforderungen*** der Prozesse sind zu steuern:
- **sicherer Zustand** muss immer beibehalten werdnen:
	- ex. Prozessabfolge, bei der jeder Prozess seinen maximalen Betriebsmittelbedarf decken kann 
- **unsichere Zustände** werden umgangen:
	- Zuteilungsablehnung im Falle nicht abgedeckten Betriebsmittelbedarfs decken kann 
	- anfordernde Prozesse nicht bedienen bzw. frühzeitig suspendieren 
⮩ Problem: vorhinein Wissen über den maximalen Betriebsmittelbedarf erforderlich

### Sicherer/unsicherer Zustand
*am Beispiel der speisenden Philosophen*

- ***Ausgangspunkt:*** fünf Gabeln sind insg. vorhanden; jeder der fünf Philosophen braucht zwei Gabeln zum Essen

- ***Situation:*** $P_{0}$, $P_{1}$ und $P_{2}$ haben je eine Gabel und zwei Gabeln sind frei
	- $P_{3}$ fordert sich eine Gabel an → eine Gabel wäre dann noch frei 
		- **sicherer Zustand:** einer von drei Philosophen könnte essen
	- die Anforderung von $P_{3}$ wurd akzeptiert
	- $P_{4}$ fordert eine Gabel an → keine Gabel wäre dann mehr frei
		- **unsicherer Zustand:** keiner der Philosophen könnte essen
		- de Anforderung von $P_{4}$ muss warten
	- Haben vier Philosophen je eine Gabel, würde der fünfte gestoppt, bevor der erste die Gabel nimmt. 
	  ![[Pasted image 20260605103559.png]]


##### $\implies$Erkennung: **"Bankier-Algorithmus**"
- Verwaltung ***Prozess/Betriebsmittel-Matrizen*** für aktuelle Belegung und maximale Belegung
- Funktion zum ***Finden einer Prozessabfolge***, bei der die Betriebsmittel auch bei vollständiger Ausschöpfung des "Kreditlimits" nicht ausgehen
- ***Vorausschauende Anwendung*** dieser Funktion im Falle von Betriebsmittelanforderungen

## Verklemmungserkennung

- Verklemmungen werden in Kauf genmmen (*ostrich algorithm*) ...
	- nichts im System verhindert Auftreten von Wartezyklen 
	- Keine der vier Bedingungen wird entkräftet

- Ansatz: **Wartegraph** erstekken und Zyklen suchen $\leadsto O(n)$
	- Zu häufige Überprüfung verschwendet Betriebsmittel/Rechenleistung
	- Zu seltene Überprüfung lässt Betriebsmittel brach liegen

- **Zyklensuche** geschieht zumeist in großen Abständen, wenn ...
	- Betriebsmittelanforderungen zu lange andauern
	- die Auslastung der CPU trotz Prozesszunahme sinkt
	- die CPU bereits über einen sehr langen Zeitraum untätig ist


## Verklemmungsauflösung

