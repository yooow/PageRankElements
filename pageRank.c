#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* pageRank,  powerMethod A -> MA 
éviter les puits (aucune sortie possible) 
et les spider traps (cycle infini entre noeuds)
poids = 1/degré sortant

*/

// ce code ne présente pas l'algorithme pageRank, uniquement les recherches pour faire une structure avec les degrés de chaque noeud


#define TAILLE 400

int graphe[TAILLE][TAILLE];	
int tableauDegres[TAILLE] = {0};
int cluster_size = 100;
float p = 0.3;
float q = 0.1;



void initialise_graphe_list(void)
{
  int i;
  int j;
  srand (time(0)); //seed 

  for(i=1; i<TAILLE; i++)
  {
    graphe[i][0] = i;
    for(j = i+1; j<= (((i/100)+1)*100);j++){
      if (((rand () * 1.0) / RAND_MAX) <= p){
        tableauDegres[i]++;
        graphe[i][tableauDegres[i]] = j;
        tableauDegres[j]++;
        graphe[j][tableauDegres[j]] = i; 
      }
    }
    for(j; j<= TAILLE;j++)
    {
      if (((rand () * 1.0) / RAND_MAX) <= q)
      {
        tableauDegres[i]++;
        graphe[i][tableauDegres[i]] = j;
        tableauDegres[j]++;
        graphe[j][tableauDegres[j]] = i; 
      }
    }
  }
  printf("Matrice d'adjacence cree\n");
}

int main (){
    int i=0, j=0;
    initialise_graphe_list();
    for(i=0 ; i<TAILLE ; i++)
    {
        printf("[ ");
        for(j= 0; j<tableauDegres[i] ; j++)
        {
        printf("%d ", graphe[i][j]);
        }
        printf("] "); 
        printf(" degre de %d : %d \n",i, tableauDegres[i]);
    }
    return 0;
}


    

