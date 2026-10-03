#quellcode
``` C
#include<stdio.h> /* include commands for reading/writing to standard input/output */

#include<stdlib.h> /* standard library */

#include<ctype.h> /* functions such as isspace, isdigit for processing input */

#include<float.h> /* mathematical functions */

#include"bhk.h" /* custom declarations */

  
  

int n=0; /* number of cities */

dist_t *dist=NULL; /* pointer to the distance values */

int T_size=0; /* size of the dynamic programming table */

dist_t *T=NULL; /* dynamic programming table */

  

extern int read_distances(void); /* process input, read cities and compute distances */

  

dist_t get_distance(int i,int j) { /* look up distance of cities i and j */

return dist[i*n+j];

}

  

/* we represent a subset U of the vertex set [n] by the corresponding bit vector, with city i corresponding to the 1<<i bit */

/* with cities numbered 0,...,n-1, the start city s is always city n-1 */

  

dist_t *T_entry(int u,int U) { /* return pointer to table entry of pair (u,U); assume 0<=u<n-1 and U<(1<<(n-1)) */

return T+u+U*(n-1);

}

  

void iter_subsets(int m,int k,int u,int U) { /* generate k-subsets of 0,...,m that do not contain u with elements m+1,...,n prescribed by U */

if(k>m+1 || m+1<0 || k<0) return; /* if no subsets exist, cancel */

if(k==m+1) { /* if all remaining elements are required */

U|=(1<<m+1)-1; /* set them to one in U */

if(!(U&1<<u)) { /* check if the forbidden element is contained; if not, perform action */

int v;

  

for(v=0;v<n-1;v++) /* iterate on v */

if(U&1<<v) { /* if v is in U */

dist_t val=*T_entry(v,U&~(1<<v)); /* look up T(v,U\{v}) */

  

val+=get_distance(v,u); /* add the distance from v to u */

if(*T_entry(u,U)>val) *T_entry(u,U)=val; /* update min value if val is smaller than the current value */

}

}

return;

}

if(u!=m) iter_subsets(m-1,k-1,u,U|1<<m); /* recurse on smaller subsets as in Pascal's triangle */

iter_subsets(m-1,k,u,U);

}

  

dist_t bhk(void) { /* the BHK algorithm; returns min TSP length */

dist_t opt=DIST_MAX;

int N,u;

  

T_size=(n-1)*(1<<(n-1)); /* set the size of the dynamic programming table */

if(!(T=malloc(sizeof(dist_t)*T_size))) {fputs("Error: out of memory!",stderr); return 0;} /* return error if out of memory */

for(N=0;N<T_size;N++) T[N]=DIST_MAX; /* set all entries in T to +oo */

for(N=0;N<n-1;N++) *T_entry(N,0)=get_distance(N,n-1); /* initialise the singleton entries of T */

  

for(N=1;N<n-1;N++) /* for all sets of sizes i=1,...,n-2 */

for(u=0;u<n-1;u++) /* for all vertices other than s=n-1 */

iter_subsets(n-2,N,u,0); /* iterate over the respective subsets */

for(u=0;u<n-1;u++) { /* final minimisation */

dist_t val=*T_entry(u,((1<<(n-1))-1)&~(1<<u)); /* look up T(v,U\{v}) */

val+=get_distance(u,n-1);

if(val<opt) opt=val;

}

return opt;

}

  

int main(int argc,char **argv) {

dist_t opt;

  

if(read_distances()) return 1; /* attempt reading input; in the event of an error, abort */

if(n>MAX_CITIES) {fputs("Error: too many cities!",stderr); return 1;}

  

/* print_cities(); print_distances();*/

opt=bhk();

if(opt>0) printf("%d\n",(int)opt);

return 0; /* report "success" */

}
```

```C
#include<stdio.h> /* include commands for reading/writing to standard input/output */

#include<stdlib.h> /* standard library */

#include<ctype.h> /* functions such as isspace, isdigit for processing input */

#include<math.h> /* mathematical functions */

#include"bhk.h" /* custom declarations */

  

extern int n; /* number of cities */

extern dist_t *dist; /* pointer to the distance values */

extern dist_t get_distance(int i,int j); /* look up distance of cities i and j */

  

static char *input=NULL; /* pointer to input (text) */

static struct city *cities=NULL; /* pointer to the cities */

  

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

  

/* input file format: one line for each city; longitude and latitude as signed doubles separated by whitespace; followed by the name of the city */

  

char *skip_whitespace(char *str) { /* skip over whitespace */

while(*str && *str!='\n' && isspace(*str)) str++;

return str;

}

  

char *skip_to_whitespace(char *str) { /* skip to whitespace */

while(*str && !isspace(*str)) str++;

return str;

}

  

char *skip_to_newline(char *str) { /* skip to newline */

while(*str && *str!='\n') str++;

return str;

}

  

int read_cities(char *str) { /* read cities from str; returns -1 in event of error */

char *tmp;

int i;

  

for(tmp=str,n=0;*tmp;tmp++) /* count the number of cities by couting the total number of newline symbols */

n+=(*tmp=='\n');

if(n==0 || *(tmp-1)!='\n') return -1; /* report error if no newlines detected or if the last symbol of the input is not a newline */

  

if(!(cities=malloc(sizeof(struct city)*n))) return -1; /* allocate memory for the cities; report error if out of memory */

  

for(i=0;i<n && *str;i++) {

str=skip_whitespace(str);

cities[i].longitude=atof(str)*M_PI/180;

str=skip_to_whitespace(str);

str=skip_whitespace(str);

cities[i].latitude=atof(str)*M_PI/180;

str=skip_to_whitespace(str);

str=skip_whitespace(str);

cities[i].name=str;

str=skip_to_newline(str);

*str++=0;

}

return n;

}

  

dist_t compute_distance(double l1,double f1,double l2,double f2) { /* compute the distance of points given by latitute/longitude on the sphere */

double s1=sin((f2-f1)/2);

double s2=sin((l2-l1)/2);

  

s1*=s1;

s2*=s2;

s2*=cos(f1)*cos(f2);

s1+=s2;

s1=sqrt(s1);

s1=asin(s1);

return s1*CIRCUMFERENCE/M_PI;

}

  

int compute_distances(void) { /* compute the pairwise distances of all the cities; returns -1 in the event of an error, and 0 otherwise */

int i,j;

  

if(!(dist=malloc(sizeof(dist_t)*n*n))) return -1;

for(i=0;i<n;i++)

for(j=0;j<n;j++)

dist[i*n+j]=compute_distance(cities[i].latitude,cities[i].longitude,cities[j].latitude,cities[j].longitude);

  

return 0;

}

  

int read_distances(void) { /* process input, read cities and compute distances */

if(read_input()<=0) {fputs("Error: could not read input",stderr); return -1;} /* if reading the input fails, report error and abort */

if(read_cities(input)<=1) {fputs("Error: syntax not correct",stderr); return -1;} /* if reading the cities fails, report error and abort */

if(compute_distances()<0) {fputs("Error: cannot compute distances",stderr); return -1;} /* compute distances */

return 0;

}

  

void print_cities(void) { /* print the cities */

int i;

  

for(i=0;i<n;i++) printf("%+7.2lf %+7.2lf : %s\n",cities[i].longitude,cities[i].latitude,cities[i].name);

}

  

void print_distances(void) { /* print the distance matrix */

int i,j;

  

for(i=0;i<n;i++) {

for(j=0;j<n;j++) printf("%4d ",(int)get_distance(i,j));

puts("");

}

}
```