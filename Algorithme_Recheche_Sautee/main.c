#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int rechercheSautee(int nTab[], int nTaille, int key);

int main()
{
    //Initialisation du tableau dans lequel la recherche seras faite
    int tab[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
                  24, 33, 35, 42, 47};
    int n = sizeof(tab)/sizeof(tab[0]);

    int x = 16; //Objet recherche
    int index = rechercheSautee(tab, n, x);

    if (index != -1)
        //Si l'objet recherche est trouve
        printf("Objet trouve a l'index %d", index);
    else
        //Si l'objet recherche n'est pas trouve
        printf("Objet pas trouve");
    return 0;
}

int rechercheSautee(int nTab[], int nTaille, int key) {
    int nI = 0;
    int nDebut = 0;
    int nFin = sqrt(nTaille); //La taille du bloc est la racine quarre de la longueur du tableau

    //On verifie si on a le bon bloc
    while(nTab[nFin] <= key && nFin < nTaille) {
        nDebut = nFin; //ce n'est pas le bon bloc, alors on le deplace
        nFin += sqrt(nTaille);
        if(nFin > nTaille - 1){
            nFin = nTaille; //Si la fin du bloc depasse la taille du tableau alors on la corrige
        }
    }

    //Recherche sequentielle dans le bloc selectionne
    for(int nI = nDebut; nI < nFin; nI++) {
        if(nTab[nI] == key){
            return nI; //On retourne l'index de l'objet trouve
        }
    }

    return -1;
}
