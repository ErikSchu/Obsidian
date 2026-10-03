## Wechselspannung & Wechselstrom

- **Drossel "L"** (Induktivität) \[L\] = *Henry* (H)
- **Kondensator "C"** (Kapazität) \[C\] = *Farad* (F)
- **WIederstand R / Leitwert G** \[R\] = *Ohm* ($\Omega$) \[G\] = *Simens* (S)

___

![[Pasted image 20260529141553.png]]
⮩ Weiterhin aber auch berücksichtigen:
	⮕ **Nichtlinearitäten** (Temperatur, Sättigungserscheinung, Laufzeiten, ...)
	⮕ **Schaltungsaufbau** (induktive-, kapazitive-, galvaanische- & Strahlungskopplung)
	⮕ Mit zuehmender Frequenz nimmt die bedeutung der **"parasitären Effekte"** zu.

___

Die Elektromagnetische Welle breitet sich (im Vakuum) mit *endlicher* ***Lichtgeschwindgkeit $c$*** aus.
Innerhalb eines betrachteten Systems mit ausgedehnten räumlichen Abmessungen (***Länge $L$***) sind unterschiedliche Phasenlagen zu beobachten:
$$\boxed{c = \lambda \cdot f}$$
***Quasistationäre Betrachtung:***
⮕ Phasenunterschiede werden vernachlössigt im *"elektrisch kurzen" System* (also $L \ll \lambda$)
⮕ zeitliche Änderungen finden innerhalb des betrachteten Systems gleichzeitig statt
![[Pasted image 20260529142012.png]]

___

*Einschub* für ***sinusförmige Kenngrößen***: $$U(x, t) = \boxed{ \hat{U} \cdot \begin{bmatrix} \omega t - \frac{w}{c} \cdot x + \varphi_{0} \end{bmatrix}} = \hat{U} \cdot \sin(\varphi(t, x))$$
- **Frequenz** $\boxed{f = f}$
- **Periodendauer** $\boxed{T = \frac{1}{f}}$
- **Kreisfrequenz** $\boxed{\omega = 2 \pi \cdot f}$
- **Vakuumwellenlänge** $\boxed{\lambda = \frac{c}{f}}$

___

>[!example] Bei Welcher *Frequenz* sind die Phasendifferenzen innerhalb der Schaltung $(l = 20 \text{cm}) \space 5°$?
> $$\frac{l}{\lambda} = \frac{\nabla \varphi}{2 \pi} \text{ und } \lambda = \frac{c}{f}$$
> $$\implies f = \frac{c \cdot \nabla \varphi}{l \cdot 2\pi}$$
> $$f = \frac{3\cdot 10^8 \frac{m}{s} \cdot \frac{5°}{360°} \cdot 2\pi}{0,2m \cdot 2\pi} = 20,8 \cdot 10^6 \frac{1}{s} = 20,8 \text{Mhz}$$

___

Alle zur hinreichend genauen Beschreibung Komponenten $R, L$ und $C$ sind inklusive der parasitären Eigenschaften und der Einflüsse des Aufbaus (z.B. Messgeräte) im *Ersatzschaltbild erfasst*.

Die **zeitliche Änderung der Ströme und Spannungen** finden überall in der Schaltung praktisch *gleichzeitig* statt
⮩ ***"elektrische kurze"*** Schaltung
	⮩ die räumliche Ausdehnung der Schaltung ist *"sehr klein" im Vergleich zur Wellenlänge*; Laufzeiten und Phasenverzögerung werden vernachlässigt

___

- ***Ortsunabhängigkeit*** innerhaln der Schaltung: $$u(\not x, t) \text{ und } i(\not x, t)$$
- $R, L$ und $C$ als **konzentrierte Bauelemete**
- Schaltungsanalyse nur bezüglich *Ersatzschaltbild*
- ***Kirchhoff'sche Gesetze*** gelten weiterhin (ebenso Regeln bzgl. der Reihen- & Parallelschaltung)
- ***Überlagerungssatz*** gilt weiterhin (lineare Bauteile)

___


Im eingeschwungenen Zustand lassen sich zeitveränderliche Spannunt / Ströme ***sinusförmig*** darstellen und durch Berücksichtugung der Amplitude und der Phase. Keine Ahnung was er meint.
![[Pasted image 20260529144309.png]]

***Spitzenwert*** 
= höchste Amplitude einer Wechselgröße während einer Periode


***Efektivwert***
- Quadratischer Mittelwert einer Wechselgröße, der angibt, welche Gleichspannund oder welcher Gleichstrom die gleiche Wärmeleistung an einem ohmschen Verbraucher erzeugt. 
- $230 V$ Netzt bezieht sich auf Effektivwert → Spiezenwert $\hat{u} = 235V$
- bei harmonischen (sin, cos) Spannungne sind Spitzenwert $\hat{u}$ und Effektivwert $U$ mit $\sqrt{ 2 }$ verknüpft $$\hat{u} = U \sqrt{ 2 }$$
- ... und analog gilt dies auch für Ströme

>[!example] Beispiel
>Hier zeitlich-konstanter Phasenanteil $\left( = \varphi_{U} + \frac{\pi}{2} \right)= 0$
>![[Pasted image 20260529144803.png]]
>___
>2 Ströme mit derselben Kreisfrequenz $\omega$
>![[Pasted image 20260529144852.png]]
>*Phase von Strom 2  mit Bezug zu Strom 1* = Differenz der Absoluten Phasen von Strom 2 und Strom 1: $$(\omega t + \varphi_{2})-(\omega t + \varphi_{1}) = \varphi_{2} - \varphi_{1} = \varphi_{2}$$

Strome und Spannungen können ...
... subtrahiert und addiert werden → Maschen- bzw. Knotenregel $$I = I_{1} + I_{2} \to \text{Zeigeraddition (auch grafisch)}$$
... multipliziert / dividiert werden → Leistungsberechnung, Impedanzberechnung $$\underline{Z} = \frac{\underline{U}}{\underline{I}} = \frac{\lvert \underline{U} \rvert }{\lvert  {\underline{I}} \rvert} e^{j(\varphi_{u}-\varphi _{i})}$$
**Wichtig:** für die quasistationäre Rechnung vereinfacht sich die Rechnung mittels Zeigern erheblich gegenüber dem Zeitbereich. Im fomgenden wird daher nur der Bildbereich betrachtet.

___

>[!example] Addition von Zeigern
>![[Pasted image 20260529145705.png]]
>**Kosinussatz:** $a^2 = b^2 +c^2 -2bc \cdot \cos(\alpha)$![[Pasted image 20260529145810.png]]
>![[Pasted image 20260529145834.png]]
>![[Pasted image 20260529145910.png]]
>![[Pasted image 20260529145926.png]]

___
___

## Komplexe Wechselstromrechnung

##### Bisher
- Wechselstromschaltungen können vollständig mit den *zeitabhängigen Beschreibungen über Sinus/Cosinus* durchgeführt werden
- Die Anwendung der *Additionstheoreme* sowie die Handhabung von *Differentialgleichungen* sind schlecht handhabbar
- Vereinfachte Vorgehensweise mit *Zeigerdiagramm* (Lösungsweg über geometrische betrachtung)

##### Neuer Weg
Einführung der Rechnung mit **komplexen Zahlen**:
⮩ Verwendung von komplexen Zeigern zur *Darstellung von Betrag und Phasenlänge einer zeitabh. Größe*

>[!note] Darstellungformen komplexer Zahlen
>- Komplexe Zahl in der **komplexen Ebene:** $$\underline{z} = x + jy$$
>- Komplexe Zahl in der **Exponentialform:** $\underline{z} = re^{j \varphi}$; *Sonderfälle:* $$\begin{align} & e^{j0} = e^{j2\pi} = 1 \\ & e^{j\frac{\pi}{2}} = j \\ & e^{j \pi} = -1 \\ & e^{\frac{j3\pi}{2}} = -j = \frac{1}{j} \end{align}$$
>- Komplexe Zahl in **trigonometrischer Form:** $\underline{z} = r \cos(\varphi) + jr \sin(\varphi)$
>
>- **Betrag** $r = \lvert \underline{z} \rvert = \sqrt{ x^2 + y^2 }$
>- **Phase** $\varphi = \arctan\left( \frac{y}{x} \right)$ (nur Werte für $\varphi \in (-\frac{\pi}{2}, \frac{\pi}{2})$ → *Vierquadrantenarctan*) 
>⤷ $r \ge 0; 0 \le \varphi \le 2\pi$
>![[Pasted image 20260609084824.png]]


### komplex konjugierte Zahl
$\underline{ z } = x + ji = r ( \cos ( \varphi ) + j \sin (\varphi ) ) = r e^{j+\varphi}$
$\underline{z}* = x - jy = r ( \cos ( \varphi ) - j \sin ( \varphi ) ) = r e^{-j \varphi}$
$\underline{ z } \cdot \underline{ z } = \lvert \underline{z} \rvert^2$

### Addition / Subtraktion
$\underline{z_{1}} \pm \underline{ z_{2}} = x_{1} \pm x_{2} + j ( y_{1} \pm y_{2} )$

### Multiplikation
$\underline{z_{1}} \cdot \underline{z_{2}} = r_{1} r_{2}  (\cos(\varphi_{1} + \varphi_{2}) + j \sin (\varphi_{1} + \varphi_{2}))$
$j \cdot \underline{z} = re^{j(\varphi + \frac{\pi}{2})}$

### Division
$\frac{\underline{z_{1}}}{\underline{z_{2}}} = \frac{r_{1}}{r_{2}}(\cos(\varphi_{1} - \varphi_{2}) + j \sin (\varphi_{1}-\varphi_{2}))$
$\frac{\underline{z}}{j} = re^{j(\varphi - \frac {\pi} {2})}$

### Potenzen
$\underline{z}^n = r^n \cdot (\cos(n \varphi) + j\sin(n \varphi))$
$\sqrt[n] { \underline{z} } = \underline{z}_{k} = \sqrt[n]{ r } e^{j \frac{(\varphi + k 2 \pi)}{n}} \text{ mit } k = 0, \dots, n-1$