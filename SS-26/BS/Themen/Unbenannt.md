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

>[]

## (nicht-) konsumierbare Betriebsmittel

