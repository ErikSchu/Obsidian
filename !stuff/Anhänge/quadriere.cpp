#include <cstdio>

int n;  // globale Variable

int main() {
  int nquadrat;  // lokale Variable (nur innerhalb von main() sichtbar)

  printf("Welche Zahl moechtest du quadrieren? ");
  scanf("%i", &n);  // speichere eingegebene Ganzzahl an der Adresse von n

  nquadrat = n * n;
  printf("%i zum Quadrat ist %i\n", n, nquadrat);

  printf("Die Variable nquadrat ist an %lu gespeichert.\n",
         &nquadrat);  // print address of x (lu=long unsigned)
}