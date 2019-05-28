#include <stdlib.h>
#include <stdio.h>

int rechercheSequentielle(int arr[], int n, int x);

int main(void) {
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = rechercheSequentielle(arr, n, x);
    (result == -1) ? printf("L'objet recherche n'a pas ete trouve")
                   : printf("L'objet recherche a ete trouve a l'index %d",
                            result);
    return 0;
}

int rechercheSequentielle(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
