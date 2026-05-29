#bs **13.05.2026**

# Einführung und Begriffsbildung

#### Beispiel: einfach verkettete Liste in C

``` c
/* Datentyp für Listenelemente */
struct element {
    char payload;            /* eigentliche “Nutzlast” */
    struct element *next;    /* Verkettungszeiger */
};

/* Datentyp für die Verwaltung 
struct list {
    struct element *head;    /* er
    struct element **tail;   /* 'n
};

/* Funktion zum Anhängen eines neuen Elements */
void enqueue (struct list *list, struct element *item) {
    item->next  = NULL;
    *list->tail = item;
    list->tail  = &item->next;
}
```
⤷ **Diese Listenimplementierung ist besonders raffiniert.** Dadurch, dass `tail` nicht auf das letzte Element, sondern den `next`-Zeiger verweist, entfällt eine Sonderbehandlung für Einfügen in eine leere Liste.

##### Szenario
![[Pasted image 20260513172150.png]]

##### 1. Fall: Faden B ==nach== Faden A
![[Pasted image 20260513172243.png]]

##### 2. Fall: Faden 2 ==überlappt== Faden 1
![[Pasted image 20260513172342.png]]

### Wo kommt das sonst noch vor?

- ***Gemeinsamer Speicher*** zur Kommunikation zwischen Prozessen
	- Systeme mit **Shared Memory**-Dienst

- ***Leicht-*** oder ***federgewichtige*** Prozesse 
	- Nebenläufiger Zugriff auf dieselben Variablen 

- ***Betriebssystemdaten***, die gebraucht werden, um den Zugriff von Prozessen auf unteilbare Betriebsmittel zu koordinieren
	- Dateisystemstrukturen, **Prozesstabelle**, Speicherverwaltung, ...
	- **Geräte** (Terminal, Drucker, Netzwerkschnittstellen, ...)

- ***Ähnlicher Sonderfall: Unterbrechungssynchronisation***
	- *VORSICHT:* Verfahren, die sich für die Synchronisation von Prozessen eignen, funktionieren nicht notwendigerweise bei Unterbrechungen.

___

>[!note] ### Begriff: Race Condition
>... ist eine Situation, in der ***mehrere Prozesse konkurrierend auf gemeinsame Daten zugreifen und mind. einer diese manipuliert***.
>Der letzte Wert der gemeinsamen Daten häng bei einer *Race Condition* davon ab, in welcher Reihenfolge die Prozesse darauf zugreifen. 
>Das Ergenbnis ist also nicht vorhersagbar und **kann** im Fall von überlappenden Zugriffen sogar **inkorrekt** sein!
>	Um *Race Conditions* zu vermeiden, müssen konkurrierende Prozesse **synchronisiert** werden.

>[!note] ### Begriff: Synchronisation
>Die **Koordination der Kooperation und Konkurrenz zwiychen Prozessen** wird ***Synchronisation*** gnannt. 
>
>- Eine *Synchronisation* bringt die Aktivitäten verschiedener nebenläufiger Prozesse in eine Reihenfolge.
>- Durch sie erreicht man also prozessorübergreidend das, wofür innerhalb eines Prozesses die Sequentialität von Aktivitäten sorgt. 

>[!note] ### Begriff: Kritischer Abschnitt
>- Im Fall von *Race Conditions* streiten sich Prozesse um den Zugriff auf gemeinsame Daten. 
>  Die **Code-Fragmente, in denen auf diese kritischen Daten zugegriffen werden**, werden ***kritische Abschnitte*** genannt. 
>⤷ ***PROBLEM:*** Es muss sichergestellt werden, dass sich *immer nur ein Prozess* in einem kritischen Abschnitt aufhalten kann.

___

#### Lösungsansatz: Schlossvariablen
![[Pasted image 20260515231401.png]]
⤷ Derartige Implementierungen werden als **Schlossalgorithmen** bezeichnet

___

# Lösungsansätze

## Der "Bäckerei Algorithmus"

- Bevor ein Prozess den kritischen Abschnitt betreten darf, bekommt er eine **Wartenummer**
- Die ***Zulassung*** erfolgt in der **Reihenfolge der Nummern**, d.h. wenn der kritische Abschnitt frei ist, darf der nächste Prozess mit der niedrigsten Nummer den kritischen Abschnitt betreten. 
	- Beim Verlassen des kritischen Abschnittes verfällt seine Wartenummer 

***PROBLEM:***
Der Algorithmus *kann nicht garantieren*, dass seine *Wartenummer nur an einen Prozess vergeben wird*. 
	In diesem Fall entscheidet eine Prozess-ID die Priorität

```c
typedef struct { // Schlossvariable (initial alles 0)
	bool choosing[N]; int number[N];
} Lock;

void aquire (Lock *lock) { // K.A. betreten
	int j; int i = pid();
	
	lock -> choosing[i] = trueM
	lock -> number[i] = max(lock -> number[0], ... number [N-1]) +1;
	lock -> choosing[i] = false;
	
	for (j = 0; j < N, j++) {
		while (lock -> choosing[j]);
		while (lock -> number[j] != 0 && 
				(lock -> number[j] > lock -> number[i] ||
				(lock -> number[j] == lock -> number[i] &&
				j < i)));
	}
}

void release (Lock *lock) { // K_A. verlassen
	int i = pid(); lock -> number[i] = 0;
}
```

#### Diskussion
Der Algorithmus ist eine **nachweisbar korrekte Lösung** für das Problem der kritischen Abschnitte, aber ...
- i.d.R. *weiß man vorab nicht, wieviele Prozesse* um den Eintritt in einen kritischen Abschnitt *konkurrieren werden*.
- *Prozess-IDs* liegen nicht im Wertebereich von $0$ bis $N-1$.
- die Funktion `aquire()`  hat eine *große Laufzeit*, auch wenn der kritische Abschnitt frei ist $\to O(N)$

___
# Hardwareunterstützung

## Unterbrechungen unterdrücken
Nur durch den Unterbrechungsmechanismus der CPU kann es dazu kommen, dass einem Prozess innerhalb eines kritischen Abschnitts die CPU entzogen wird. 

```c
/* K.A. betreten */
void aquire (Lock *lock) {
	asm ("cli");
}

/* K.A. verlassen */
void release (Lock *lock) {
	asm ("sti");
}
```
> **`cli`** und  **`sti`** werden bei *Intel-x86-Prozessoren* zum ***Sperren*** und ***Erlauben*** von Unterbrechungen verwendet.

⮩ Durch diese Lösung werden ==alle== Prozesse und das Betriebssystem selbst (Gerätetreiber) beeinträchtigt.
	⮩ `sti` und `cli` dürfen daher nicht im *User-Mode* benutzt werden.


## Schloss mit **Atomaren Operationen**

Viele CPUs unterstützen **unteilbare** (*atomare*) Lese-/Modifikations-/Schreibzyklen, mit denen sich ***Schlossalgorithmen*** implementieren lassen:

- Motorola 68K: **TAS** (*Test-and-Select*): 
  Setzt Bit 7 des Zieloperanden und liefert den vorherigen Zusand in Condition Code Bits 
- Intel x86: **XCHG** (*Exchange*):
  Tauscht den Inhalt eines Registers mit dem einer Variabken im Speicher
- PowerPC: **LL/SC** (*Load Linked/Store Conditional)
-  . . .

>[!note] *Diskussion:* ***Aktives Warten***
>Unzulänglichkeit der bisher gezeigten Schlossalgorithmen:
>**Der aktiv wartende Prozess ...**
>- kann selbst *keine Änderung* der Bedingung herbeiführen, auf die er wartet
>- *behindert* daher unnütz Prozesse, die sinnvolle Arbeit leisten könnten
>- schadet letztendlich auch sich selbst:
>	- Je länger der Prozess den Prozessor für sich behält, umso länger muss er darauf waretn, dass andere Prozesse die Bedingung erfüllen, auf die er selbst wartet.
>	- Nur bei Multiprozessorsystemen tritt dieses Problem nicht auf.

___

# Betriebssystemunterstützung

- **Prozesse geben die Kontrolle über die CPU ab**, während sie auf Ereignisse warten
	- im *Konfliktfall blockierrt* sich ein Prozess auf ein Eregnis 
		- PCB des Prozesses in eine Warteschlange eingereiht

- Die Wartephase eines Prozesses ist als Blockadephase ("E/A-Stoß") ausgelegt:
	- der Ablaufplan für diese Prozesse wird aktualisiert (*scheduling*)
	- ein anderer, lauffähiger Prozess wird plangemäß abgefertigt (*dispatching*)
	- ist kein Prozess mehr lauffähig, läuft die CPU "leer" (*idle-phase*)

- Mit Beginn der Blockadephase endet der CPU-Stoß des Prozesses. 

## Semaphor ***(semaphore)***
⮩ eine *nicht-negative ganze Zahl*, die für **zwei unteilbare Operationen** definiert sind:

##### ==**P**== (niederländisch prolaag, "erniedrige"; auch down, wait)
- hat der Semaphor den Wert 0, wird der laufende Prozess blockiert
- ansonsten wird der Semaphor um 1 dekrementiert

##### ==**V**== (niederländisch verhoog, "erhöhe"; auch up, signal)
- auf den Semaphor ggf. blockierter Prozess wird deblockiert
- ansonsten wird der Semaphor um 1 dekrementiert

⮕ Eine **Betriebssystemabstraktion** zum Austausch von Synchronisationssignalen zwischen nebenläufig arbeitenden Prozessen. 


#### Semaphor - Implementierung
```c
/* Implementierung aus OO-StuBS */
class Semaphore : public WaitingRoom { // WaitingRoom ist eine Liste von 
									   // PCBs mit den Zugriffsmethoden 
									   // enqueue und dequeue
	int counter;
public: 
	Semaphore(int c) : counter (c) {}
	void wait () {
		if (counter == 0) {
			Customer *life = (Customer*)scheduler.active();
			equeue(live);
			scheduler.block(live, this); 
		} else couter--
	}
	void sigal() {
		Customer *customer = (Customer*)dequeue)();
		if (customer) schedule.wakeup(customer);
		else counter--
	}
};
```
>Der **Scheduler** muss drei Operationen zur Verfügung stellen: 
>- *`active`* liefert PCB des laufenden Prozesses
>- *`block`* versetzt einen Prozess in den Zustand BLOCKED
>- *`wakeup`* setzt einen blockierten Prozess wieder auf die Bereit-Liste

#### Semaphor - Anwendung
```c
Semaphore lock; /* = 1; Semaphor als Schlossvariable  */
void enqueue (struct list *list, struct elemet *item) {
	item->next = NULL;
	
	wait (&lock);
	
	*list->tail = item; 
	list->tail = &item->next;
	
	signal (&lock);
}
```


### Semaphor - einfache Interaktionen

- ***Einseitige Synchronisation*** ![[Pasted image 20260526093406.png]]

- ***Betriebsmittelorientierte Synchronisation*** ![[Pasted image 20260526093454.png]]

>[!note] *Diskussion:* ***Semaphore***
>- **Erweiterungen/Varianten**
>	- Binäre Semaphore oder *Mutex*
>	- nicht-blockierendes *`wait()`*
>	- *Timeout*
>	- Felder von Zählern
>- **Fehlerquellen**
>	- Gefahr von ***Verklämmungen***
>	- Koplexere Synchronisationsmuster schwierig
>		- jeder muss die Protokolle exakt einhalten 
>	- Semaphorbenutzung wird nicht erzwungen
>  ⮕ Unterstützung durch die Programmiersprache

___

# Sprachunterstützung

## Monitor *(Hoare 1974, Hansen 1975)*
⮩ ein **abstrakter Datentyp** mit impliziten Synchronisationseigenschaften:
1. ***mehrseitige Synchronisation*** an der Schnittstelle zum Monitor 
	- gegenseitiger Ausschluss der Ausführung aller Methoden 
2. ***einseitige Synchronisation*** innerhalb des Monitors mit Hilfe von **Bedingungsvariablen** *(condition variables)*
   - `wait` blockiert einen Prozess auf das Eintreten eines Signals/einer Bedingung an und deblockiert ggf. ( genau einen oder alle) darauf blockierte Prozesse 
   - `signal` zeigt das Eintreten eines Signals/einer Bedingung an und deblockiert ggf. (genau einen oder alle) darauf blockierte Prozesse 

- Sprachgestützter Mechanismus:
  Concurrent Pascal, PL/I, CHILL, ..., **Java**.

##### Beispielcode
```Pseudo-Code
/* Eine synchronisierte Warteschlange */
monitor SyncQueue {
	Queue queue;
	condition not_empty;
	
public:
	/* Element Einhängen */
	void enqueue(Element element) {
		queue.enqueue(element);
		not_empty.signal();
	}
	
	/* Element aushängen */
	Element dequeue() {
		while (queue.is_empty())
			not_empty.wait();
		return queue.dequeue();
	}
};
```
⮩ Sprache garantiert pro *SyncQueue*-Objekt gegenseitigen Ausschluss der Zugriffsmethoden 
⮩ *enqueue* signalisiert, dass die Queue nicht mehr leer ist. Wenn kein Prozess wartet, passiert nichts.
⮩ *dequeue* wartet zunächst darauf, dass mind. ein Element in der Queue ist.


#### Signalisierungssemantik

- im Falle wartender Prozesse sind **als Anforderungen zwingend zu erfüllen**:
	- *mind. ein Prozess* debkockiert an der Bedingungsvariablen
		  ***UND***
	- *max. ein Prozess* rechnet nach der Operation im Monitor weiter

- Es ex. versch. Lösungsvarianten mit je **unterschiedlicher Semantik**
	- *\# befreiter Prozesse* (d.h. alle oder nur einer)
		- Wenn nur einer, dann welcher?
		  Konflikte mit der CPU-Zuteilungsstrategie sind möglich.
	- *Basiswechsel* des Monitors, kein Basiswechsel (Basiswahrung)
		- Wenn kein sofortiger Basiswechsel erfolgt, muss die Wartebedingung erneut überprüft werden.

## in [[Java]]

- Schlüsselword **`synchronized`** für **gegenseitigen Ausschluss**
- *Eine* implizite Bedingungsvariable
	- `notify` oder `notifyAll` statt signal, kein basiswechsel 

```java
/* Eine synchronisierte Warteschlange */
class SyncQueue {
	private Queue queue;
	
	/* Element einhängen */
	publich synchronized void enqueue(Element element) {
		queue.enqueue(element);
		notifyAll();
	}
	
	/* Element aushängen */
	public synchronized Element dequeue() {
		while (queue.empty()) wait();
		return queue-dequeue()
	}
};
```


![[Pasted image 20260527012151.png]]