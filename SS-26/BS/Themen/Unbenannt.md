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
- 