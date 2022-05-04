#include <stdio.h>
#include <math.h>
#include <iostream.h>

using namespace std;

/* Niz (A_n) realnih brojeva zadan je rekurzivnom relacijom oblika:            A_n+2 = 𝜆1 * A_n+1 + 𝜆2 * A_n  
   i početnim članovima A_0 i A_1.

   Za zadane 𝜆1 i 𝜆2, vrijednosti A_0 i A_1 prvih dvaju članova tog niza te 𝑛∈𝐍, napišite program koji
   računa vrijednost 𝑛-tog člana toga niza, A_n, na dva načina:
      
      1. pomoću formule za opće rješenje homogene rekurzivne relacije,
      2. računanjem odgovarajućeg člana niza rekurzivno.

   NAPOMENA: Možete pretpostaviti da će koeficijenti 𝜆1 i 𝜆2 biti takvi da su obje nultočke
   karakterističnog polinoma nužno realne!                                                                 */

double formula_za_opce_rjesenje(double l1, double l2, double a0, double a1, int n) {
   if (pow(l1, 2) == -4 * l2) {
      double x;
      x = l1 / 2;
      return (a0 * pow(x, n)) + ((a1 - a0 * x) * n * pow(x, n-1));
   }
   else {
      double y, z;
      y = (l1 + sqrt(pow(l1, 2) + 4 * l2)) / 2;
      z = (l1 - sqrt(pow(l1, 2) + 4 * l2)) / 2;
      return ((a0 * z - a1) / (z - y)) * pow(y, n) + ((a1 - a0 * y) / (z - y)) * pow(z, n);
   }
}   

double rekurzivna_funkcija(double l1, double l2, double a0, double a1, int n) {
   if (n == 0) return a0;
   else if (n == 1) return a1;
   else return l1 * rekurzivna_funkcija(l1, l2, a0, a1, n-1) + l2 * rekurzivna_funkcija(l1, l2, a0, a1, n-2);
}

int main() {
   int n;
   double l1, l2, a0, a1;

   cout << "Unesite prvi koeficijent λ1 rekurzivne funkcije: " << endl;
   cin >> l1;
   cout << "Unesite drugi koeficijent λ2 rekurzivne relacije: " << endl;
   cin >> l2;
   cout << "Unesite vrijednost nultog clana niza a0: " << endl;
   cin >> a0;
   cout << "Unesite vrijednost prvog clana niza a1: " << endl;
   cin >> a1;
   cout << "Unesite redni broj n trazenog clana niza: " << endl;
   cin >> n;

   printf("%d.clan niza preko opce formule je %f.", n, formula_za_opce_rjesenje(l1, l2, a0, a1, n));
   printf("%d.clan niza preko rekurzija je %f.", n, rekurzivna_funkcija(l1, l2, a0, a1, n));

   return 0;
}
