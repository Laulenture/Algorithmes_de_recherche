#include <stdio.h>
#include <stdlib.h>

/**
    i : int             :nVar
    f : float           :flVar
    d : double          :dblVar
    c : char            :cVar
    l : long int        :lnVar
    ll: long long int   :llnVar
    L : double long     :ldblVar
    h : short int       :srVar
    ui: unsigned int    :unVar
    uf: unsigned float  :unfVar
    s : *STRING*
    * : *POINTEUR*      :pVar
*/

int rechercheInterpolation(int tab[], int n, int x);

int main()
{
    //Initialisation du tableau dans lequel la recherche seras faite
    int tab[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
                  24, 33, 35, 42, 47};
    int n = sizeof(tab)/sizeof(tab[0]);

    int x = 18; //Objet recherche
    int index = interpolationSearch(tab, n, x);

    if (index != -1)
        //Si l'objet recherche est trouve
        printf("Objet trouve a l'index %d", index);
    else
        //Si l'objet recherche n'est pas trouve
        printf("Objet pas trouve");
    return 0;
}

///Si l'objet recheche est trouve alors la fonction retourne la position de l'objet, sinon elle retourne -1
int interpolationSearch(int tab[], int n, int x) {
    //Initialisation des index de debut et fin
    int debut = 0, fin = (n - 1);

    while (debut <= fin && x >= tab[debut] && x <= tab[fin])
    {
        if (debut == fin){
            if (tab[debut] == x) return debut;
            return -1;
        }
        //Recherche de la position de l'objet recherché avec une formule d'interpolation
        int pos = debut + (((double)(fin-debut) / (tab[fin]-tab[debut]))*(x - tab[debut]));

        //Si l'objet recherche est trouve
        if (tab[pos] == x)
            return pos;

        //Si l'objet est supperieur, alors il est danss la partie supperieure
        if (tab[pos] < x)

        if (tab[pos] < x)
            debut = pos + 1;

        // Si l'objet est inferieur, alors il est danss la partie inferieure
        else
            fin = pos - 1;
    }
    return -1;
}
