#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int quantiteupdate = 0;
 do
 {
    printf("\033[0;33m\n===show menu===\n\033[0m");
    printf("\033[0;34m1.Ajouter un livre\n\033[0m");
    printf("\033[0;34m2.Afficher tous les livres\n\033[0m");
    printf("\033[0;34m3.recherche un livre\n\033[0m");
    printf("\033[0;34m4.update le stock dun livre un livre\n\033[0m");
    printf("\033[0;34m5.supprimer  un livre\n\033[0m");
    printf("\033[0;34m6.Afficher le nombre total de livres en stock\n\033[0m");
    printf("\033[0;34m7.Quitter\n");
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
        printf("Stock plein.\n");
   }
}

  if (choix == 2){
    if(nbLivres == 0 ){
        
    printf("\033[0;31mthere is nothing here\033[0m");
    }else{
        for( int i = 0 ; i <nbLivres ; i++){
                    printf("Titre : %s\n, Auteur : %s\n, Prix : %.2f\n, Quantite : %d\n", titres[i], auteurs[i], prix[i], quantite[i]);

        }
        
    }
   }

 if (choix == 3) {
            printf("Entrez le titre du livre a rechercher : ");
            scanf("%s", titrerecherche);
            int trouve = 0;
            for (int i = 0; i < nbLivres; i++) {
                if (strcmp(titres[i], titrerecherche) == 0) {
                    printf("\nLivre trouve: Titre : %s\n \nAuteur %s :  \nPrix : %.2f \nQuantite : %d", titres[i], auteurs[i], prix[i], quantite[i]);
                    trouve = 1;
                    break;
                }
            }
            if (!trouve) {
                printf("Livre non trouve.\n");
            }
        }

        if ( choix == 4){

            printf("enter the name of the book you wanna update his stock :");
            scanf("%s", titrerecherche);
            int trouve = 0;

            for( int i  = 0 ; i < nbLivres; i++){

                if(strcmp(titres[i],titrerecherche) == 0){
                    printf("enter la nouvelle quantite :");
                    scanf("%d",&quantiteupdate);
                    quantite[i] = quantiteupdate;

                    printf("la quantite has updated\n");
                    trouve = 1;
                    break;
                }
            }
        }

        if ( choix == 5){

        }
 } while (choix !=7);
 

    return 0;
}