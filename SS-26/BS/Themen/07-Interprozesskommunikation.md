#bs **04.06.2026**

## Wdh.

- Prozesse können **miteinander intaragieren**
	- aufeinander warten (*Synchronisation*)
	- Dateien austauschen (*Kommunikation*)

- **Wartemechanismen**
	- sind notwendig für kontrollierte Kommunikation
	- können zu Verklemmungen führen

___

# Grundlagen der Interprozesskommunikation

## Inter-Process Communication (IPC)

- Mehrere Prozesse bearbeiten ***eine*** Aufgabe:
	- gleichzeitiges Nutzen von zur Verfügung stehender Information durch mehrere Prozesse
	- Verkürzung der Bearbeitungszeit durch *Parallelisierung*
	- Verbergen von Bearbeitungszeiten durch Ausführung "im Hintergrund"

 - **Kommunikation** durch ***gemeinsamen Speicher***
	 - Datenaustausch nebenläufiges Schreiben in bzw. Lesen aus einem gemeinsamen Speicher
	 - Es muss auf Synchronisation geachtet werden

- ***Kommunikation durch Nachrichten***
	- Nachrichtenaustausch zwischen Prozessen
	- gemeinsamer Speicher nicht erforderlich

## Nachrichtenbasierte Kommunikation
... basierend auf zwei *Primitiven*:

```
send (Ziel, Nachricht)
recieve (Quelle, Nachricht)
```

⮩ **Unterschiede** in
- Synchronisation 
- Adressierung
- diverse andere Eigenschaften

##### Synchronisation bei nachrichtenbasierter Kommunikation

Synchronisation bei ***Senden/Empfangen***
- **Synchroner Nachrichtenaustausch** (auch ==Rendezvous==)
	- *Empfänger blockiert* bis Nachricht eingetroffen
	- *Sender blockiert* bis Ankunft der Nachricht bestätigt
- **Asynchroner Nachrichtenaustausch**
	- *Sender* gibt *Nachricht dem Betriebssystem* & arbeitet weiter
	- *Blockierung* auf beiden Seiten *optional*
	- *Pufferung* immer erforderlich

**Häufig anzutreffen:**
*Asynchroner* Nachrichtenaustausch mit *potentiell Blockierendem* Senden und Empfangen

##### Adressierung bei nachrichtenbasierter Kommunikation

- **Direkte Adressierung**
	- Prozess-ID (Signale)
	- Kommunikationsendpunkt eines Prozesses (Port, Socket)

- **Indirekte Adressierung**
	- Kanle (Pipes)
	- Briefkasten (Mailboxes), Nachrichtenpuffer (Message Queues)

⮕ Zusätzliche Dinemsion **Gruppenadressierung**
- *Unicast* - an genau einem
- *Multicast* -  an eine Auswahl
- *Broadcast* - an alle

##### Diverse andere Eigenschaften bei nachrichtenbasierter Kommunikation 

- ***Nachrichtenformat***
	- Strom-/ Nachrichtenorientiert
	- Feste / variable Länge
	- Un- / Getypt

- ***Übertragung***
	- Uni- / Bidirektional (halb- / voll-duplex)
	- Un- / Zuverlässig
	- Reihenfolge bleibt (nicht) erhalten

___

# Lokale Interprozesskommunikation unter UNIX

## UNIX-Signale

 Signale sind in Software **nachgebildete Unterbrechungen**
- ähnlich denen eines Prozessors durch E/A-Geräte
- minimale Form der Interprozesskommunion (Übertragung der Signalnummer)

- 