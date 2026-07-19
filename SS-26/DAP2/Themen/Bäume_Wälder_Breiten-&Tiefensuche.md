#dap2 

>[!info] Definition: Wege und Pfade in Graphen
>Bei einem Graphen $G = (V, E)$ gilt:
>- ein ***Weg*** in $G$ ist eine Folge $$v_{1}, \dots, v_{l}$$ von Knoten, so dass $\forall i \in \{ 1, \dots, l-1 \} : v_{i}v_{i+1} \in E$
> 	- dieser Weg hat die ***Länge*** $l-1$.
> 	- wir sprechen von einem *Weg von $v_{1}$ nach $v_{l}$*
> - ein ***Pfad*** in $G$ ist ein Weg $v_{1}, \dots, v_{l}$, dessen *Knoten alle verschieden* sind. 

>[!example] Beispiel
>![[Pasted image 20260704182057.png]]
>Die Folge $1, 2, 3, 4, 5, 2, 3$ ist ein Weg aber kein Pfad, weil $2$ und $3$ zweimal vorkommen. 

>[!info] Definition: Zusammenhangskomponenten
>Sei $G = (V,E)$ ein Graph und $u, v, w \in V$.
>- ***Relation $\sim_{G}$:*** Definiere $$u \sim_{G} v \Longleftrightarrow \text{ex. Weg von u nach v}$$
>- $\sim_{G}$ ist eine Äquivalenzrelation, d.h.:
>	- **Reflexiv:** $u \sim_{G} u$
>	- **Symmetrisch:** $v \sim_{G} u \Leftrightarrow u \sim_{G} v$
>	- **Transitiv:** $u \sim_{G} v \land v \sim_{G} w \implies u \sim_{G}w$
>- Nenne die Äquivalenzklassen von $G$ ***Zusammenhangskomponenten***
>	- Zwei Knoten liegen in derselben Zusammenhangskomponente, wenn es einen Weg vom einen zum anderen gibt

>[!example] Beispiel: zusammenhängende Graphen
>![[Pasted image 20260704184249.png]]
>- Ein Graph ist **zusammenhängend**, wenn er *nur eine Zusammenhangskomponente* hat, in diesem Beispiel ist:
>	- linker Graph zusammenhängend 
>	- rechte Graph unzusammenhängend & besteht aus drei Zusammenhangskomponetnen
>- Ein **isolierter Knoten** in einem Graphen ist eine *Zusammenhangskomponent*e, die nur aus *einem Knoten* besteht
>- Eine **isolierte Kante** ist eine *Zusammenhangskomponente*, die *nur eine Kante* enthält

#### Kreise in Graphen
- Ein ***Kreis*** in einem Graphen $G$ ist eine Kopie eines Kreises $C_{l}, l \ge 3$, die in $G$ enthalten ist
- Ein Kraph ist **kreisfrei**, wenn er keine Kreise enthält

>[!info] Definition Wald/Baum
>- ***Baum*** = *kreisfreier Graph*
>- ***Baum*** = *zusammenhängender Wald*

→ der Kleinst Wald besteht aus nur einem Knoten
→ der Graph, der nur aus einer Kante Besteht, ist ebenfalls ein Baum
→ jeder Pfad ist ein Baum
→ ein **Blatt** im Wald ist ein Knoten vom Grad 1

>[!tip] Lemma 
>Jeder Baum $G = (V, E)$ mti $E \ne \emptyset$ enthält *mind. 2 Blätter*

>[!tip] **Proposition**
>Die folgenden Aussagen sind äquivaltent: 
>1. Graph $G=(V,E)$ ist ein Baum 
>2. $G$ ist zusammenhängend und $\lvert E \rvert = \lvert  V \rvert -1$
>3. $G$ ist kreisfrei und ---
>4. $G$ ist kantenmaximal kreisfrei
>5. $G$ ist kantenmaximal zusammenhängend
>6. in $G$ gibt es zu je zwei Knoten $v, w$ genau einen Pfad von $v$ nach $w$

>[!info] Definition: spannender Baum
>***Spannender Baum*** eines Graphen $G = (V, E)$ ist ein Untergraph $G' = (V, E')$ von $G$ mit derselben Knotenmenge wie $G$, der ein Baum ist. 

>[!tip] Lemma
>Jeder zusammenhängende Graph enthält einen spannenden Baum.

___

## Breiten- & Tiefensuche
- in einem Graphem $G$ ist der **Abstand** von $v, w \in V(G)$ definiert als $$\text{dist}_{G}(v, w) = \text{min }_{l \ge 0} \exists \text{ Weg der Länge } l \text{ von } v \text{ nach } w$$
- falls $v, w$ in verschiedenen Zusammenhangskomponenten liegen, verwenden wir die Konvention $$\text{dist}_{G}(v, w) = \infty$$

>[!note] ***`BFS(G, s)`***
>1. Färbe alle Knoten $v \in V(G) \setminus \{ s \}$ *grün* und färbe $s$ *gelb*
>2. Setze $d(v) = \infty$ für alle $v \in V(G) \setminus \{ s \}$ und setze $d(s) = 0$
>3. Setze $p(v) = \emptyset$ für alle $v \in V$
>4. Lege eine Warteschlange $Q$ an und füre $s$ in $Q$ ein 
>5. Solange $Q$ nicht leer ist 
>	1. entnehme $v$  aus $Q$
>	2. färbe $v$ *rot* 
>	3. für alle $u \in \delta v$ mit farbe *grün*
- $d(v)$: Die Distanz (Anzahl der Kanten) vom Startknoten $s$ zum Knoten $v$. Wird initial auf $\infty$ gesetzt, da wir noch keine Wege kennen.
- $p(v)$: Der Vorgängerknoten. Startet bei $\emptyset$ (leer). Das brauchst du zwingend, wenn du am Ende nicht nur die Distanz wissen, sondern den genauen Pfad im Graphen zurückverfolgen willst.
- $\delta v$: Die Menge der direkten Nachbarn (Adjazenzliste) des Knotens $v$.

- **Grün:** Knoten ist unentdeckt. Der Algorithmus war noch nie dort.    
- **Gelb:** Knoten wurde entdeckt und liegt in der Warteschlange $Q$. Seine eigenen Nachbarn wurden aber noch nicht geprüft.
- **Rot:** Knoten ist komplett abgearbeitet. Er wurde aus $Q$ entnommen und seine Kanten wurden untersucht.

>[!tip] **Satz**
>**BFS** hat de Laufzeit $O(\lvert V(G) \rvert + \lvert E(G) \rvert)$. Bei Beendigung des Algorithmus gilt 
>1. Die Zusammenhangskomponente des Startknotens $s$ besteht aus genau den Knoten, für die $d(v) < \infty$
>2. Für alle $v \in V(G)$ gilt $d(v) = \text{dist}_{G}(s, v)$
>3. Der Untergraph $$(\{ v \in V(G) : d(v) < \infty, \{ \{ v, p(v) \} : v \in V(G) , p(v) \ne \emptyset \} \})$$ist ein Spannender Baum der Zusammenhangskomponente von $S$ in $G$

>[!tip] Lemma
>Für jeden Graphen $G$ gilt $$\sum_{v \in V(G)} d_{v}(G) = 2\lvert E(G) \rvert $$

>[!tip] Lemma
>Während der gesamten Ausführung von **BFS** gilt für alle Knoten $v$ $$d(v) \ge \text{dist}_{G}(s, v)$$

>[!tip] Lemma 
>Enthält die Warteschlange $Q$ die Knoten $q_{1}, \dots, q_{l}$, dann gilt $$d(q_{1}) \le \cdots \le  d(q_{l}) \le d(q_{1}) + 1.$$
>___
>Wird ein Knoten $u$ vor einem anderen Knoten $u'$ in $Q$ eingefügt, gilt $$d(u) \le d(u')$$



>[!note] ***`DFS(G)`***
>1. Färbe alle Knoten $v \in V(G)$ *grün*
>2. Setze $c(v) = 0$ und $p(v) = \emptyset$ für alle $v \in V$
>3. Setze $j = 1$
>4. Für alle $v \in V(G)$
>	1. falls $v$ *grün* ist
>		1. führe `DFSLoop(G, v, j)` aus
>		2. erhöhe $j$ um 1

>[!note] `DFSLoop(G, v, j)`
>1. Färbe $v$ *gelb* und setze $c(v) = j$
>2. Für alle $u \in \delta_{G}v$
>	1. Falls $u$ *grün*
>		1. Setue $p(u) = v$
>		2. führe `DFSLoop(G, v, j)` aus 
>3. Färbe $v$ *rot*

>[!tip] **Satz**
>- **DFS** hat die Laufzeit $O(\lvert V(G) \rvert + \lvert E(G) \rvert)$
>- Die Mengen $c^{-1}(j)$ für $j \ge 1$ bilden genau die Zusammenhangskomponenten von $G$.

___

# Implementation

```c
#include<stdio.h> /* include commands for reading/writing to standard input/output */

#include<stdlib.h> /* standard library */

#include<ctype.h> /* functions such as isspace, isdigit for processing input */

  

char *input=NULL; /* pointer to input (text) */

  

struct vertex { /* data structure to represent a vertex */

struct entry *first; /* pointer to the first entry of the adjacency list */

int comp; /* id of the component of the vertex */

enum colour {green,yellow,red} col; /* color: green, yellow, red */

struct vertex *p; /* p-field for DFS */

};

  

struct entry { /* entry of the adjacency list */

struct vertex *v; /* pointer to the adjacent vertex */

struct entry *next; /* pointer to the next entry */

};

  

struct graph {

int n; /* number of vertices */

struct vertex *v; /* pointer to the vertices */

};

  

struct graph G; /* the input graph */

  

int vertex_number(struct vertex *u) {return u?u-G.v:-1;} /* return the number of a vertex; ranges from 0 to n-1 */

  

int read_input(void) { /* this function reads standard input and stores the contents under the input pointer */

int len=0; /* len is the size of memory block */

int cur=0; /* cur is the number of memory cells currently occupied */

int c; /* variable to hold the next character read */

while((c=getchar())!=EOF) { /* read the next character while there is one */

if(cur>=len-1) { /* enlarge the memory block if necessary */

int i,newlen;

char *buffer;

  

newlen=2*(len+1); /* size of the enlarged memory block */

buffer=(char *)malloc(sizeof(char)*newlen); /* allocate memory */

if(!buffer) return -1; /* if not enough memory available, report error */

for(i=0;i<len;i++) buffer[i]=input[i]; /* copy old contents over to new memory block */

if(input) free(input); /* free the old memory block if necessary */

input=buffer;

len=newlen;

}

input[cur++]=(char)c; /* store the input character */

}

input[cur]=0; /* store a zero character to mark the end of file */

return cur; /* return the number of characters read */

}

  

char *convert_to_int(char *str,int *num) { /* convert the characters under str to an integer, return the position after the chars processed; in case of an error, return NULL */

*num=0; /* number of integers read */

  

while(isdigit(*str)) { /* so long as we're reading digits */

(*num)*=10; /* shift current value one decimal digit to the left */

(*num)+=*str-'0'; /* add value of the current digit */

str++;

}

  

if(isspace(*str) || *str==0) return str; /* if the next char is space or EOF, return the pointer to the next unprocessed symbol */

return NULL; /* otherwise return "error" */

}

  

/* input file format: first line contains the number of vertices */

/* the following lines contain the edges in the format v1 v2 */

/* here v1,v2 are vertex numbers 0,...,n-1 */

  

char *skip_whitespace(char *str) { /* skip over non-newline whitespace */

while(*str && isspace(*str)) str++;

return str;

}

  

int read_graph(char *str) { /* read graph from str; returns -1 in event of error, and 0 otherwise */

int i,m;

char *tmp;

struct entry *edges;

  

/* determine the number of vertices and allocate enough space */

str=skip_whitespace(str); /* skip over any leading whitespace */

if((str=convert_to_int(str,&G.n))==NULL) return -1; /* read number of vertices; report error unless correct number read */

G.v=malloc(sizeof(struct vertex)*G.n); /* allocate memory for the vertices */

if(G.v==NULL) return -1; /* if there's not enough memory available, return an error */

for(i=0;i<G.n;i++) G.v[i].first=NULL; /* initialise adjacency list pointers to NULL */

  

/* now count the number of remaining lines of the input file, which equals the number of edges */

for(tmp=str,m=0;*tmp;tmp++) if(*tmp=='\n') m++;

  

edges=malloc(2*(1+m)*sizeof(struct entry)); /* allocate memory for the edges */

if(edges==NULL) return -1; /* if we're out of memory, return error code */

if(m==0) return 0; /* if there's no edges to be read, we're done */

for(m=0;*str;m+=2) { /* now read the edges one by one */

int v,w;

str=skip_whitespace(str); /* skip over any leading whitespace */

if(!*str) break; /* if we're at the end of the file, stop */

if((str=convert_to_int(str,&v))==NULL) return -1; /* read number of the first vertex; abort in case of syntax error */

str=skip_whitespace(str); /* skip over any whitespace */

if((str=convert_to_int(str,&w))==NULL) return -1; /* read number of the second vertex; abort in case of syntax error */

str=skip_whitespace(str); /* skip over any whitespace */

if(v<0||v>=G.n) return -1; /* if the first vertex number doesn't make sense, abort */

if(w<0||w>=G.n||w==v) return -1; /* if the second vertex number doesn't make sense, abort */

  

edges[m].v=G.v+w; /* set the vertex that the edge points to */

edges[m+1].v=G.v+v; /* set the vertex that the next edge points to */

edges[m].next=G.v[v].first; /* insert the edge at the begining of the adjacency list of v */

G.v[v].first=edges+m;

edges[m+1].next=G.v[w].first; /* insert the edge at the begining of the adjacency list of w */

G.v[w].first=edges+m+1;

}

return 0; /* report success */

}

  

void print_graph(void) { /* print the graph in the form of an adjacency list */

struct entry *next;

int i,*comps,total=0;

  

if(!(comps=calloc(G.n,sizeof(int)))) return; /* reservere memory for the component size counters */

  

printf("n=%d\n",G.n); /* print the total number of vertices */

for(i=0;i<G.n;i++) {

comps[G.v[i].comp]++; /* increase the respecitive component counter */

printf("v%d, c%d, p%d: ",i,G.v[i].comp,vertex_number(G.v[i].p)); /* for each vertex print its number and the id of its component */

for(next=G.v[i].first;next;next=next->next) /* iterate over the adjacency list */

printf("%d ",vertex_number(next->v)); /* print the number of the neighbour */

puts(""); /* output a newline */

}

puts("Component sizes"); /* write out component sizes */

for(i=0;i<G.n;i++)

if(comps[i]) { /* online write out non-empty components */

printf("c%d: %d\n",i,comps[i]);

total++;

}

printf("%d\n",total); /* print total number of components */

}

  

void dfs_loop(struct vertex *v,int j) { /* expects a pointer to a vertex of G and the number of a component j=0,...,n-1 */

struct entry *u;

  

v->col=yellow; /* set vertex colour to yellow */

v->comp=j; /* set component number to j */

for(u=v->first;u;u=u->next) { /* iterate over adj list of v */

if(u->v->col==green) { /* if current neighbour green */

u->v->p=v; /* set parent pointer to v */

dfs_loop(u->v,j); /* recurse on u */

}

}

v->col=red; /* colour v red */

}

  

void dfs(void) { /* run dfs on G */

int i,j;

  

for(i=0;i<G.n;i++) G.v[i].comp=-1,G.v[i].col=green,G.v[i].p=NULL; /* initialise component numbers, colours, parents */

for(i=j=0;i<G.n;i++) /* iterate over all vertices */

if(G.v[i].col==green) /* if green, then call dfs_loop */

dfs_loop(G.v+i,j++); /* increase component counter */

}

  

int main(int argc,char **argv) {

if(read_input()<=0) {fputs("Error: could not read input",stderr); return 1;} /* if reading the input fails, report error and abort */

if(read_graph(input)<0) {fputs("Error: graph syntax not correct",stderr); return 1;} /* if reading the graph fails, report error and abort */

dfs();

print_graph();

return 0; /* report "success" */

}
```
