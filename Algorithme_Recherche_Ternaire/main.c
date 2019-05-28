#include <stdio.h>
#include <stdlib.h>

int rechercheTernaire(int l, int r, int key, int tab[]);

int main() {
    int l, r, result, key;
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    l = 0;
    r = 9;
    key = 5;

    result = rechercheTernaire(l, r, key, tab);
    (result == -1) ? printf("L'objet recherche n'a pas ete trouve")
                   : printf("L'objet recherche a ete trouve a l'index %d",
                            result);
}

int rechercheTernaire(int l, int r, int key, int tab[]) {
    if (r >= l) {
        // On cherche mid1 and mid2 
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // On vérifie si l’element est présent à l’un des mid
        if (tab[mid1] == key) {
            return mid1;
        }
        if (tab[mid2] == key) {
            return mid2;
        }

        // Sinon si L'objet n’est pas présente à l’un des deux mid, 
        // On vérifie dans quelle partie l’element est present  
        // Puis on répète l’opération  
        // dans la partie ciblée 
        if (key < tab[mid1]) {
            // L'objet se trouve entre l et mid1 
            return rechercheTernaire(l, mid1 - 1, key, tab);
        }
        else if (key > tab[mid2]) {
            // L'objet se trouve entre mid2 et r 
            return rechercheTernaire(mid2 + 1, r, key, tab);
        }
        else {
            // L'objet se trouve entre mid1 et mid2 
            return rechercheTernaire(mid1 + 1, mid2 - 1, key, tab);
        }
    }

    // L'objet n’a pas été trouvé
    return -1;
}
