#include <stdio.h>

//prototype des fonctions
int min(int a, int b);
int rechercheBinaire(int tableau[], int l, int r, int x);
int rechercheExponentielle(int tableau[], int n, int x);

//programme principal
int main()
{
   int n = 10; //taille du tableau
   int tableau[n], i;
   int x; //entier à rechercher
   printf("Entrer 10 entiers dans l'ordre croissant: \n", n);
   for(i = 0; i < n; i++)
        scanf("%d", &tableau[i]); //l'utilisateur rentre les valeurs du tableau
   printf("Entrer l\'entier a chercher: \n");
   scanf("%d", &x); //l'utilisateur définit l'entier à rechercher
   int resultat = rechercheExponentielle(tableau, n, x);
   if (resultat == -1)
        printf("%d n\'est pas present dans le tableau\n", x);
   else
        printf("%d est present a l'index %d \n", x, resultat);
   return (0);
}

int min(int a, int b){
    return (a < b ? a : b);
}
int rechercheBinaire(int tableau[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (tableau[mid] == x)
            return (mid);
        if (tableau[mid] > x)
            return (rechercheBinaire(tableau, l, mid - 1, x));
         return (rechercheBinaire(tableau, mid + 1, r, x));
    }
    return (-1);
}
int rechercheExponentielle(int tableau[], int n, int x){
    if (tableau[0] == x)
        return (0);
    int i = 1;
    while (i < n && tableau[i] <= x)
        i = i*2;
    return (rechercheBinaire(tableau, i / 2, min(i, n), x));
}
