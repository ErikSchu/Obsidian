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

⮕ ***Sender***
- Prozesse - mit hilfe des Systemaufrufs ` kill(2) `
- Betriebssystem - bei Auftreten bestimmter Ereignisse

⮕ ***Empfänger***-Prozess führ die *Signalbehandlung* durch:
- *Ignorieren*,
- Terminierung des Prozesses oder 
- Aufruf einer **Behandlungsfunktion**
	- Nach der Behandlung läuft Prozess an unterbrochener Stelle weiter.

- Mit Hilfe von Signalen können Prosesse **über Ausnahmesituationen informiert** werden (ähnlich wie Hardware Unterbrechungen)

- ***z.B.:***
	- ` SIGINT ` Prozess abbreichen (z.B bei CTRL + C)
	- ` SIGSTOP ` Prozess anhalten (z.B. bei CTRL + Z)
	- ` SIGWINCH ` Fenstergröße wurde geändert
	- ` SIGCHLD ` Kindprozess terminiert
	- ` SIGSEGV ` Speicherschutzverletzung des Prozesses
	- ` SIGKILL ` Prozess wird getötet
	- ...

- Die ***Standardbehandlung** (terminieren, anhalten, ... )* kann für diemeisten Signale überdefiniert werden.
	- siehe ` signal(2) `

#### Logische Sicht
![[Pasted image 20260608111813.png]]

#### Technische Sicht

- Signalbehandung erfolgt immer beim Übergang vom Kernel in ==***der***== User Mode.

- Was passiert, wenn der Zielprozess gerade ... 
	- läuft, also im Zustand `RUNNING` ist (z.B. Segmentation Fault, Bus Error)?
		- **unmittelbarer Start** der Behandlungsroutine
	- gerade nicht läuft, aber `READY` ist (z.B. Systemaufruf kill)?
		- Im Prozesskontrollblock wird das **Signal vermerkt** 
		- Wenn der Prozess die CPU zugeteilt bekommt, erfolgt die Behandlung
	- auf E/A wartet, also `BLOCKED` ist?
		- E/A-Systemaufruf (z.B. read) wird mit `EINTR` **abgebrochen**
		- Prozesszustand wird auf `READY` gesetzt
		- Dannach wie be 2. 
		- Ggf. wird der untrebrochene Systemaufruf neu ausgeführt (`SA_RESTART`)

>[!example] ##### Beispiel UNIX-Signale
>Auszug aus dem Handbuch des *Apache* HTTP-Servers:
>![[Pasted image 20260610105946.png]]

### UNIX *Pipes*

- ***Kanal*** zwischen zwei Kommunikationspartnern
	- unidirektional
	- gepuffert (feste Größe)
	- zuverlässig
	- stromorientiert

- Operationen: **Schreiben** & **Lesen**
	- Ordnung der Zeichen bleibt erhalten (Zeichenstron)
	- Blockierung bei voller *Pipe* (Schreiben) und leerer *Pipe* (Lesen)

![[Pasted image 20260610110745.png]]


#### Pipes → Programmierung

- ***Unbenannte Pipes***
	- *Erzeugen einer Pipe:* ` int pipe (int fdes[2]) `
	- Nach erfolgreichem Aufruf (Rückgabewert == 0) kann man ...
		- über ` fdes[0] ` aus der Pipe **lesen** (Systemaufruf `read`)
		- über ` fdes[1] ` in die Pipe **schrieben** (Systemaufruf `write`)
	- Nun muss man noch das eine Ende an einen anderen Prozess weitergeben

- ***Benannte Pipes***
	- Pipes können auch als **Spezialdateien ins Dateisystem** gelegt werden: ` int mkfifo (<Dateiname>, mode_t mode) `
	- Standartfunktion zum Öffnen, Lesen, Schreiben & Schließen können verwednet werden
		- Normale Dateizugriffsrechte regeln, wie die Pipe benutzt werden darf.

```c
enum { READ = 0, WRITE = 1 };

int main (int argc, char *argv[]) {
	int res, fd[2];
	if (pipe (fd) == 0) { // Pipe erzeugen
		res = fork ();
		if (res > 0) { // Elternprozess
			close (fd[READ]);
			dup2 (fd[WRITE], 1);
			close (fd[WRITE]);
			exclp (argv[1], argv[1], NULL);
		} else if (res == 0) { // Kindprozess
			close (fd[WRITE]);
			dup2 (fd[READ], 0);
			close (fd[READ]);
			execlp (argv[2], argv[2], NULL)
		}
	}
	// [Fehlerbehandlung]
}
```

`./connect ls wc` entspricht dem Shell-Kommando `ls|wc`
```shell
ulbrich@kos:~/V_BS/Vorlesung/code> ls
	connect connect.c excl.c fork.c orphan.c 
	wait.c

ulbrich@kos:~/V_BS/vorlesung/code> ls WC
	6   6   49
```

### Message Queues

- Rechnerweit **eindeutige Adresse** (*Key*) dient zur Identifikation 
	- Zugriffsrechte wie auf Dateien
	- Prozesslokale Nummer (`MsqID`) wird bei allen Operationen benötigt 

- **Ungerichtete M:N-Kommunikation**

- Gepuffert (einstellbare Größe pro *Queue*)

- Nachrichten haben einen Typ (*long-Wert*)

- Operationen zum Senden und Empfangen einer Nachricht
	- blockierend - nicht blockierend (aber nicht Asynchron)
	- Empfang aller Nachrichten - nur ein bestimmter Typ

![[Pasted image 20260610140956.png]]

>[!note]
>*Messege Queues* werden heute nut noch selten eingesetzt, da sie anders als *Sockets* auf lokale Kommunikation beschränkt sind.
>Zudem ist der Anwendungscode weniger portabel. 

___

# Rechnerübergreifende Interprozesskommunikation

## Sockets