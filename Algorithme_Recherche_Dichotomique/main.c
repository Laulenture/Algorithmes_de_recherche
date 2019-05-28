#include <stdio.h>
#include <stdlib.h>

int rechercheDichotomique(int tab[], int l, int r, int x);

int main(void) {
    int tab[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(tab) / sizeof(tab[0]);
    int x = 10;
    int result = rechercheDichotomique(tab, 0, n - 1, x);
    (result == -1) ? printf("L'objet recherche n'a pas ete trouve")
                   : printf("L'objet recherche a ete trouve a l'index %d",
                            result);
    return 0;
}

int rechercheDichotomique(int tab[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // Si l�element recherch� est au milieu, alors on renvoie mid
        if (tab[mid] == x)
            return mid;
        // Si l�element est plus petit que mid, alors
        // il est present dans la partie de gauche
        if (tab[mid] > x)
            return rechercheDichotomique(tab, l, mid - 1, x);

        // Sinon l�element est present
        // dans la partie de droite
        return rechercheDichotomique(tab, mid + 1, r, x);
    }

    return -1;
}
