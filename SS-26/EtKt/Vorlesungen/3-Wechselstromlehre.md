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
	⮩ die räumliche Ausdehnung der Schaltung ist "sehr klein" im Vergleich zur Wellenlänge; Laufzeiten und Phasenverzögerung werden vernachläs