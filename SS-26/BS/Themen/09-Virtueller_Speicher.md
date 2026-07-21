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

