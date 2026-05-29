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

>[!example] Bei Welcher *Frequenz* sond die Phasendifferenzen innerhalb der Schaltung $(l = 20 \text{cm}) \space 5°$?
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
>**Kosinussatz:** $$ a^2 = b^2 +c^2 -2bc \cdot \cos(\alpha) $$