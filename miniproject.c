#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(){

    const int MAX_BOOK = 100 ;
    char titre[MAX_BOOK][30];
    char auteur[MAX_BOOK][30];
    char recherche[30];
    int nblivres = 0;
    int quantite[MAX_BOOK];
    float prix[MAX_BOOK];
    int n = 0;
    int i ;
    int choix;
    int quantiteupdate = 0;
 do
 {
        printf("\033[0;33m**********************MENU****************************\n\033[0m");
        printf("*                                                    *\n");
        printf("\033[0;34m*     1-Ajouter un livre au stock.                   *\n\033[0m");
        printf("\033[0;34m*     2-Afficher tous les livres disponibles.        *\n\033[0m");
        printf("\033[0;34m*     3-Rechercher un livre par son titre.           *\n\033[0m");
        printf("\033[0;34m*     4-Mettre a jour la quantite d'un livre.        *\n\033[0m");
        printf("\033[0;34m*     5-Supprimer un livre du stock.                 *\n\033[0m");
        printf("\033[0;34m*     6-Afficher le nombre total de livres en stock. *\n\033[0m");
        printf("\033[0;34m*     7-quitter                                      *\n\033[0m");
        printf("*                                                    *\n");
        printf("******************************************************\n");
        printf("\n");

        printf("choiser un nombre entre(1 et 7):");
        scanf("%d", &choix);

   if ( choix == 1 ){
        if(nblivres < MAX_BOOK){
            printf("titre:");
            getchar(); // pour supprimer buffer of scanf()
            fgets(titre[nblivres], MAX_BOOK, stdin);
            titre[nblivres][strcspn(titre[nblivres], "\n")] = 0;

            printf("auteur:");
            fgets(auteur[nblivres], MAX_BOOK, stdin);
            auteur[nblivres][strcspn(auteur[nblivres], "\n")] = 0;

            printf("prix:");
            scanf("%f", &prix[nblivres]);

            printf("quantite:");
            scanf("%d", &quantite[nblivres]);

            nblivres++;
        }else {
        printf("Stock plein.\n");
   }
   }

   if (choix == 2){
    if(nblivres == 0 ){

    printf("\033[0;31mthere is nothing here\033[0m\n");
    }else{
        for( i = 0 ; i <nblivres ; i++){
                printf("-------------------livre N%d-------------------\n", i + 1);
                printf("titre du livre: %s\n", titre[i]);
                printf("auteur du livre: %s\n", auteur[i]);
                printf("prix du livre: %.2f DH\n", prix[i]);
                printf("quantite en stock: %d \n", quantite[i]);
                printf("-----------------------------------------------\n");

                printf("\n");
                printf("\n");
        }

    }
   }

 if (choix == 3) {
            printf("entrez le titre du livre : ");
            getchar();

            fgets(recherche, MAX_BOOK, stdin);
            recherche[strcspn(recherche, "\n")] = 0;
            int trouve = 0;
            for (int i = 0; i < nblivres; i++) {
                if (strcmp(titre[i], recherche) == 0) {
                    printf("Titre du livre: %s\n", titre[i]);
                    printf("Auteur du livre: %s\n", auteur[i]);
                    printf("Prix du livre: %.2f \n", prix[i]);
                    printf("Quantite en stock: %d \n", quantite[i]);
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
            getchar();

            fgets(recherche, MAX_BOOK, stdin);
            recherche[strcspn(recherche, "\n")] = 0;
            int trouve = 0;

            for( i  = 0 ; i < nblivres; i++){

                if(strcmp(titre[i],recherche) == 0){
                    printf("enter la nouvelle quantite :");
                    scanf("%d",&quantiteupdate);
                    quantite[i] = quantiteupdate;

                    printf("la quantite has updated\n");
                    trouve = 1;
                    break;
                }
            }
            if (!trouve) {
    printf("Livre non trouve.\n");
}

        }

        if( choix == 5){
            printf("Entrez le titre du livre pour supprimer : ");
            getchar();
            fgets(recherche, MAX_BOOK, stdin);
            recherche[strcspn(recherche, "\n")] = 0;
            int trouve = 0;
            for ( i = 0; i < nblivres; i++) {
                if (strcmp(titre[i], recherche) == 0) {
                    for (int j = i; j < nblivres - 1; j++) {
                        strcpy(titre[j], titre[j + 1]);
                        strcpy(auteur[j], auteur[j + 1]);
                        prix[j] = prix[j + 1];
                        quantite[j] = quantite[j + 1];
                    }
                    nblivres--;
                    printf("Livre supprime avec succes.\n");
                    trouve = 1;
                    break;
                }
            }
            if (!trouve) {
                printf("Livre non trouve.\n");
            }


        }

        if ( choix == 6){
     printf("le nombre total des livre et %d\n", nblivres);
        }
 } while (choix !=7);
    return 0;

}




