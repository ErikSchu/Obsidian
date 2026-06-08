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

