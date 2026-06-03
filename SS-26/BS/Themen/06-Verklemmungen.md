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
 >![[Pasted image 20260603170511.png]]
 >⤷ Mit Hilfe eines Semaphors wird *gegenseitiger Ausschluss* beim Zugriff auf die Gabeln garantiert. Jeder Philosoph nimmt erst seine rechte und dann seine linke Gabel.
 >⮩
 
 
 