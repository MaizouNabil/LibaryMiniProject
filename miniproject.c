#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


int main(){

    const int MAX_BOOK = 100 ;
    char titres[MAX_BOOK][50];
    char auteurs[MAX_BOOK][50];
    char titrerecherche[50];
    int nbLivres = 0;
    int quantite [MAX_BOOK];
    float prix[MAX_BOOK];
    int n = 0;
    int choix;
 do
 {
    printf("\033[0;33m\n===show menu===\n\033[0m");
    printf("\033[0;34m1.Ajouter un livre\n\033[0m");
    printf("\033[0;34m2.Afficher tous les livres\n\033[0m");
    printf("\033[0;34m3.update or modifiee un livre\n\033[0m");
    printf("\033[0;34m4.Supprimer un livre\n\033[0m");
    printf("\033[0;34m5.Afficher le nombre total de livres en stock\n\033[0m");
    printf("\033[0;34m6.Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

   if ( choix == 1 ){
    if(nbLivres < MAX_BOOK){
    printf("Entrez le titre du livre : ");
    scanf(" %s", &titres[nbLivres]);
    printf("Entrez l'auteur du livre: ");
    scanf(" %s", &auteurs[nbLivres]);
     printf("Entrez le prix du livre : ");
    scanf("%f", &prix[nbLivres]);
    printf("Entrez la quantite en stock:");
    scanf("%d", &quantite[nbLivres]);
     nbLivres++;
   }else {
        printf("Stock plein. Impossible d'ajouter plus de livres.\n");
   }
}

  if (choix == 2){
    if(nbLivres >= 1){
        printf("liste de livre disponible\t");
        for(int i = 0 ; i < nbLivres; i++ ){
            printf("Titre : %s, Auteur : %s, Prix : %.2f, Quantite : %d\n", titres[i], auteurs[i], prix[i], quantite[i]);
        }
        
    }else{
        printf("\033[0;31mthere is nothing here\033[0m");
        
    }
   }

 if (choix == 3) {
            printf("Entrez le titre du livre a rechercher : ");
            scanf("%s", titrerecherche);
            int trouve = 0;
            for (int i = 0; i < nbLivres; i++) {
                if (strcmp(titres[i], titrerecherche) == 0) {
                    printf("Livre trouve : Titre : %s, Auteur : %s, Prix : %.2f, Quantite : %d\n", titres[i], auteurs[i], prix[i], quantite[i]);
                    trouve = 1;
                    break;
                }
            }
            if (!trouve) {
                printf("Livre non trouve.\n");
            }
        }
 
 } while (choix !=7);
 

    return 0;
}