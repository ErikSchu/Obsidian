---
datum: 12.10.2026
tags:
  - Logik
smry:
---
# 1. Einführende Beispiele
## Gründe für Formale Logik
>[!bsp] Präzision
![[Pasted image 20261012105543.png]]
> - Formale Logik hat eine eindeutige Semantik, was erlaubt Zusammenhänge präzise zu beschreiben.
> - (1), (2): *Prädikatenlogik*, (3): *[[Aussagenlogik]]*

>[!example] Struktur von Zusammenhängen
> ![[Pasted image 20261012112300.png]]
> - Die Argumentation ist unabhängig vom Inhalt der Aussagen (1) - (3)
> - Es kommt nur auf den logischen Zusammenhang an

>[!example] Problemlösen
>![[Pasted image 20261012112529.png]]
>- Logische Formalisierung erlaubt die Anwendung systematischer Methoden zur Lösung von Problemen

___
# 2. Syntax und Semantik der Aussagenlogik

### Aussagen und Aussagenvariablen
Abstraktion ***"Aussage"***: **etwas, das ==wahr== oder ==falsch== sein kann**
	⤷ **Aussagenvariablen** können dabei die Werte `wahr` oder `falsch` annehmen

### Syntax
Verwendung ***aussagenlogischer Variablen*** der Art $A, B, C$ sowie $A_{i}$ für alle $i \in \mathbb{N}$.
$AV$ bezeichnet die Menge aller aussagenlogischer Variablen.

>[!def] **Syntax** Aussagenlogischer Formeln 
>Die Menge $AL$ der **aussagenlogischen Formeln** ist die kleinste Menge, die die folgenden Eigenschaften hat:
>1. $\top$ *(wahr)* und $\bot$ *(falsch)* sind in $AL$
>2. Jede Variable aus $AV$ ist in $AL$
>3. Sind $\varphi_{1}, \varphi_{2}$ in $AL$, so auch
>	- $\neg \varphi_{1}$  *(Negaytion)*
>	- $(\varphi_{1} \land \varphi_{2})$ *(Konjunktion)*
>	- $(\varphi_{1} \lor \varphi_{2})$ *(Diskunktion)*
>
>(dabei sind (1) und (2) **atomar**)



...

### Semantik
entspr. Bedeutung einer Formel.
*Wenn* jeder Variable ein Wahrheitswert zugewiesen ist, *dann* kann auch einer aussagenlogischen Formel ihr Wahrheitswert zugewiesen werden

>[!def] Wahrheitsbelegung
>- Eine **Wahrheitsbelegung** ist eine partielle Funktion $\alpha: AV \to \{ 0,1 \}$
>- Eine Belegung $\alpha$ heißt **passend** für eine Formel $\varphi$, wenn $\alpha(X)$ für alle in $\varphi$ vorkommenden Variablen $X$ definiert ist. 

$X$ ist hier eine "Meta-Variable", die für eine beliebige aussagenlogische Variable steht. 
Die Semantik von $\varphi$ ordnet jeder passenden Bekegung $\alpha$ einen Wahrheitswert  

>[!def] Semantik aussagenlogischer Formeln

TODO

>[!bsp] Beispiel

Implikationen/Äquivalenzen