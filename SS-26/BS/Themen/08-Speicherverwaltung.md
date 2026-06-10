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
- 