 https://sys-sideshow.cs.tu-dortmund.de/lehre/ss26/bs/decker/03-Prozesse-deck.html#/section 

==***Prozesse*** sind **Programme in Ausführung**==
→ nicht statisch sodern *dynamisch*
→ Abwechselnde Folge von *CPU-* und *E/A-Stößen*
→ benötigen **Betriebsmittel** des Rechners (CPU, Speicher, E/A)
→ haben Einen **Zustand** (*READY*, *RUNNING*, *BLOCKED*)
→ konzeptionell oft als nebenläufige Kontrollflüsse betrachtet
→ unterliegen der *Kontrolle* des **Betriebssystems** (Betriebsmittel-Zuteilung / -Entzug)![[Pasted image 20260504231201.png]]

___
# Das UNIX-Prozessmodell

***UNIX-Prozesse ...***
- sind **primäres Strukturierungskonzept** für Aktivitäten
  ⤷ Anwendungs- & Systemprozesse
  
- können leicht und schnell *weitere Prozesse erzeugen*
  ⤷ Eltern-prozess→ Kindprozess

![[2026-05-04-232418_hyprshot.png]]

## Shells und E/A

***Schale*** (**shell**), die den ***Kern*** (**kernel**) umgibt

**Textbasierte Nutzerschnittstelle** zum Starten von Kommandos, z.B. 
```shell
ulbricht@ios:~$ which emacs
/usr/bin/emacs

// zeigt, wo ein bestimmtes Kommando gefunden wird
```

- Jedes *ausgeführte Kommando* ist ein eigener ***Kindprozess***
- i.d.R. blockiert Shell bis Kommando terminiert
- Kommandos können auch gestoppt, fortgesetzt, im Hintergrund ausgeführt werden, usw. 

##### Bsp. *Job Control*
![[Pasted image 20260504233556.png]]

#### Standart-E/A-Kanäle von Prozessen
- ***Standart-Eingabe*** zum Lesen Von Benutzereingaben
- ***Standart-Ausgabe*** Textausgaben des Prozesses
- ***Standart-Fehlerausgabe*** seperater Kanal für Fehlermeldungen

##### Bsp. *Standart-E/A-Kanäle umleiten*
![[Pasted image 20260504233912.png]]

## UNIX-Philosophie
$$\begin{align} & \text{"Write programs that do one thing and do it well."} \\ & \text{"Write programs to work together."}  \\ & \text{"Write programs that handle text streams,} \\ & \ \ \ \text{because that is a universal interface."} \\ \\ & \implies \text{"Do one thing, do it well."} \end{align}$$
## Prozesserzeugung

##### Erste Systemaufrufe

| `getpid(2)`           | liefert PID des laufenden Prozesses                                                                                                                                                                                                                                               |
| --------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `getppid(2)`          | -\|\|- des Elternprozesses                                                                                                                                                                                                                                                        |
| `getuid(2)`           | liefert Benutzerkennung des laufenden Prozesses                                                                                                                                                                                                                                   |
| `fork(2)`             | erzeugt neuen Kindpozess<br>- DUPLIZIERT Laufenden Prozess<br>- Kinderprozess erbt Adressraum, Benutzerkennung, Std.-E/A-Kanäle, Prozessgruppe, Signaltabelle, offene Dateien, aktuelles Arbeitsverzeichnis<br>- aber nicht PID, PPID, anhängige Signale, Accounting-Dateien, ... |
| `exit(3)`, `_exit(2)` | beendet den laufenden Prozess                                                                                                                                                                                                                                                     |
| `wait(2)`             | wartet auf die Beendigung des Kindprozesses                                                                                                                                                                                                                                       |
| `execve(2)`           | lädt und startet ein PRogramm im Kontext des laufenden Prozesses                                                                                                                                                                                                                  |

### Kosten der Prozesserzeugung

 - **Kopieren des Adressraums** erzeugt hohe kosten 
	 - Speicher und Ausführungszeit 
	 - insb. bei direkt folgendem `exec`

- **Histroische Lösung `vfork()
	- Elternprozess wird *suspendiert*, bis Kindprozess `exec` aufruft oder mit `_exit()` terminiert
	- Kindprozess *benutzt Code & Daten des Elternprozesses* (→ kein Kopieren)
	- Kindprozess *darf keine Daten verändern*
		→ kein `exit()` sondern `_exit`

- ***Heutige Lösung: ==copy on write==***
	- Mit Hilfe der *MMU* teilen sich Eltern- & Kindprozess dasselbe Code- & Datensegment
	- Erst wenn Kindprozess die Daten ändert, wird das Segment kopiert
	- Wenn dem `fork()` direkt ein `exec` folgt, kommt das nicht vor 
	- `fork()` ==mit== copy-on-write *kaum langsamer* als `vfork()`

>[!def] ***Der `_exit()` Systemaufruf***
>*System Call:* `void _exit (int)`
>- **Terminiert den laufenden Prozess** und übergibt das Argument als *exit status* an den Elternprozess 
>	- Aufruf kehrt nicht zurück
>- Gibt die belgten Ressourcen des Prozesses frei 
>	- offene Dateien, belegter Speicher, ...
>- Sendet dem eigenen Elternprozess das Signal `SIGCHLD`
>- Die Bibliotheksfunktion `exit(3)` räumt zusätzlich noch die von `libc` belegten Ressourcen auf
>	- Gepufferte Ausgaben werden bspw. herausgeschrieben 
>	- Normale Prozese sollen `exit(3)` benutzen, nicht `_exit`

### Verwaiste Prozesse (orphan processes)

- Ein UNIX-Prozess wird zum **Waisenkind**, wenn sein Elternprozess terminiert
- Was passiert mit der Prozesshierarchie?![[Pasted image 20260506105626.png]]

>[!def] ***Der `wait()` Systemaufruf***
>*System Call:* `pid_t wait (int*)`
>- Der aufrufende Prozess **blockiert bis ein Kinderprozess terminiert**
>- Rückgabewert ist dessen ***PID***
>- Zeigerargument (`wstatus`) liefert u.a. den Exit-Status
>	- Wert kann per Makro geprüft werden (z.B.  `WIFEXITED(wstatus)`)
>- Kehrt sofort zurück, falls bereits ein Kindprozess terminiert ist

### Zombies

- *Bevor der Exit-Status eines terminierten Prozesses* mit Hilfe von `wait` abgefragt wird, ist er ein ***Zombie***

- Die Ressourcen solcher Prozesse können freigegeben werden, aber die Prozessverwaltung muss sie noch kennen
	- insb. der exit status muss gespeichert werden

```shell
ulbricht@ios:~$ ./wait &
ulbricht@ios:~$ ps
  PID TTY            TIME CMD
 4014 pts/4     00:00:00 bash
17892 pts/4     00:00:00 wait
17895 pts/4     00:00:00 wait <defunct>
17895 pts/4     00:00:00 ps
ulbrich@io:~$ Exit Status: 42
```

##### Verwendung von `wait()`
```c
... /* includes, main() { ... */
pid = fork(); /* Kinderprozess erzeugen */
if (pid > 0) {
	int status;
	sleep(5); /* Bibliotheksfunktion: 5 Sek. schlafen */
	if (wait(&status) == pid && WIFEXITED(status))
		printf ("Exit Status: %d\n", WEXITSTATUS(status));
	}
	else if (pid == 0) {
		exit(42);
	}
}
```
![[Pasted image 20260506124221.png]]

>[!def] UNIX-Prozesse im Detail: execve()
>*System Call:* `int execve (const char *kommando, const char *args[], const char *envp[])`
>
>- Lädt und *startet das angegebene Kommando*
>- Der Aufruf kehrt nur im Fehlerfall zurück 
>- Der komplette Adressraum wird ersetzt
>- Es handelt sich aber weiterhin um denselben Prozess!
>	- Selbe PID, PPID, offene Dateienm, ...
>- Die **libc** bietet Hilfsfuntionen, die intern execve aufrufen:
>	- `execl`, `execv`, `execlp`, `execvp`
>	- Unterscheiden sich in Argumenten, Umgebungsvariablen, Suchpfad

##### Verwendung von `exec()`
![[Pasted image 20260506125023.png]]

#### Diskussion: Warum kein `forkexec()`?
- Durch Trennung von `fork` und `execve` hat der Elternprozess **mehr Kontrolle: 
	- Operationen im Kontext des Kindprozesses ausführen
	- Voller Zugriff auf die Daten des Elternprozesses 
- Shells nutzen diese Möglichkeit z.B. zur ...
	- Umleitung der Standart-E/A-Kanäle
	- Aufsetzen von Pipes

## Prozesszustände

![[Pasted image 20260506125446.png]]


___

# Leichtgewichtige Prozessmodelle
## "Gewicht" von Prozessen

... ist ein *bildlicher Ausdruck* für die Größe des Kontextes des Prozesses und damit die **Zeit, die für eine Prozesswechsel benötigt wird**.

- CPU-Zuteilungsentscheidung
- alten Kontext sichern
- neunen Kontext laden

	⇒ klassische UNIX-Prozesse sind ***schwergewichtig***

## Leichtgewichtige Prozesse 

- Die 1:1-Beziehung zwischen Kontrollfluss und Adressraum wird aufgebrochen
	- Eng kooperierende **Threads**
	- **Adressraum teilen** (code + data + bss + heap, aber ==nicht== stack!)

>[!check] 
>- **Auslagreung aufwändiger Operationen** in einen leichtgewichtigen Hilfsprozess, während der Elternprozess erneut auf Eingabe reagieren kann
>	- typisches Beispiel: Webserver
>- Programme, die aus mehreren Kontrollflüssen bestehen, profitieren unmittelbar von Multiprozessor-Hardware
>- schnellerer Kontextwechsel, wenn man im selben Adressraum bleibt
>- Je nach *Scheduler* eventuell mehr Rechenzeit 

>[!fail] Nachteil
>- **Programmierung ist schwierig:**  Zugriff auf gemeinsame Daten muss koordiniert werden.

## Federgewichtige Prozesse
⤷ **"User-Level Threads"**

- Werdem komplett ***auf der Anwendungsebene implementiert***. Das *Betriebssystem weiß nichts davon*.
	- Realisiert durch **Bibliothek:** `User-Level Thread Package`
	- Im Gegensatz zu *Kernel-Level Threads*

>[!check]
>- Extrem schneller Kontextwechsel: Nur wenige Prozessregister sind aus zutauschen; Ein **==Trap== in den Kern entfällt**
>- Jede Anwendung kann sich das Passende `Thread-Package` wählen.

>[!fail] Nachteile
>- Blockierung eines federgewichtigen Psozesses führt zur *Blockierung des ganzen Programms*.
>- Kein Gewichtsvorteil durch Multi-Prozesoren
>- kein zusätzlicher Rechenzeitanteil

___

# Systeme mit leichtgewichtigen Prozessen 
## Windows
![[Pasted image 20260512082746.png]]
⤷ Ein Prozess enthölt $1$ bis $N$ Threads, die auf denselben Globalen Daten operieren.

- ***Prozess:*** Umgebung und Adressraum für **Threads**
	- Ein `Win32`-Prozess enthält immer mind. $1$ **Thread**
	  
- ***Thread:*** Code-ausführende Einheit
	- Jeder **Thread** verfügt über einen *eigenen Stack* und *Registersatz* (insbes. Instruktionszeiger / PC = program counter)
	- **Threads** bekommen vom *Scheduler* Rechenzeit zugeteilt
	  
- Alle **Threads** sind ***Kernel-Level Threads***
	- User-Level Threads möglich (*"Fibers"*), aber unüblich
	  
- Strategie: Anzahl Threads gering halten
	- Überlappte (asynchrone) E/A

## Linux

Linux implementiert **POSIX-Threads** in Form der `pthread`-Bibilothek. Möglich mach das ein *Linux-spezifischer System Call*
``` c
  int _clone (int (*fn)(void*), void *stack, int flags, void *arg, ...)
```

Universelle Funktion, parametrisiert durch ***flags***
- `CLONW_VM` **Addressraum** gemeinsam nutzen
- `CLONE_FS` Information über **Dateisystem** teilen
- `CLONE_FILES` **Dateideskriptoren** (*offene Dateien*) teilen
- `CLONE_SIGHAND` Gemeinsame **Signalbehandlungstabelle**

Für Linux sind alle Threads und Prozesse ***intern Tasks***:
	⤷ Der Scheduler macht also keinen Unterschied

___

>[!note] ***Zusammenfassung***
>- Prozesse sind die zentralen Abstraktion für Aktivitäten in heutigen Betriebssystemen
>- UINIX-Systeme stellen diverse System Calls zur Verfügung, um Prozesse zu erzeugen, zu verwalten und miteinander zu verknüpfen
>  ⤷ *"Do one thing, do it well."*
>- Leichtgewichtige Fadenmodelle haben ihre Vorteile 
>	- in UNIX-Systemen bis in die 90er Jahre nicht verfügbar
>	- in Windows von Beginn an (ab NT) integraler Bestandteil

