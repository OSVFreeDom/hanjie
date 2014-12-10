#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 1000
int menu(int choix, FILE* historique)
{
    switch (choix)
    {
        case 1:

        {
            printf("choix de la difficulte\n");
            int choix = 0;
            printf("1.Facile pour débutant\n");
            printf("2.Intermediaire pour joueurs habitues\n");
            printf("3.Difficile pour un vrai defis\n");
            scanf ("%d", &choix);

            fprintf (historique, "choix de la difficulte:%d\n", choix);

            if (choix ==1)
            {
                printf("1.1ere grille\n");
                printf("2.2eme algrille\n");
                printf("3.3eme grille\n");
                scanf ("%d", &choix);
            }
            if (choix ==2)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n");
                scanf ("%d", &choix);
            }
            if (choix ==3)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n");
                scanf ("%d", &choix);
            }

                fprintf (historique, "numero de grille%d\n", choix);




            break;
        }

        case 2:

        {
            printf("Jouer au Hanjie\n");
            int choix = 0;
            printf("1.Nouvelle partie\n");
            printf ("2.Reprendre une partie en cours\n");
            scanf ("%d", &choix);

            break;
        }

        case 3:

        {
            printf("historique des parties\n");
            printf("Score de vos parties");

            break;
        }

    }
}

int main (int argc, char *argv [])
{

    FILE* historique= NULL;
    historique = fopen("historique.txt", "r+");

    char pseudo [50];
    int difficulte [3]= {0};
    int grille [3]= {0};
    printf("____________________\n");
    printf("Bienvenue sur Hanjie\n");
    printf("--------------------\n");
    printf("quel est votre pseudo ?\n");
    scanf("%s", &pseudo );

    fprintf (historique, "pseudo:%s\n", pseudo);


    int choix = 0;
    printf("1. Niveau de difficulte\n");
    printf("2. Jouer au Hanjie\n");
    printf("3. Historique de vos parties\n");
    printf ("4.Manuel\n");
    printf ("5.quitter\n");
    scanf("%d", &choix);

    if (choix == 4)
    {
        printf("Bienvenue dans le manuel d'Hanjie. Nous allons vous expliquer comment jouer:\n");
        printf("Le jeu est composé de trois niveaux de difficultés.\n");
        printf("Pour chaque niveau, vous avez trois grilles disponibles.\n");
        printf("Le but est simple, trouver le dessin caché dans chaque grille.\n");
        printf("Pour cela, vous devrez vous servir des chiffes indiqués en haut et à gauche de la grille.\n");
        printf("Ces chiffres vous indiquent le nombres de cases à griser par lignes et colonnes.\n");
        printf("Pour griser les cases, vous devez indiquer leurs positions en mettant un espace entre chaques cases.\n");
        printf("Par exemple: A1 B6 D4.\n");
    }

    if (choix == 5)
    {
        printf("Au revoir et à bientot!");
        return 0;
    }
    menu(choix,historique);



   fclose(historique);
}
