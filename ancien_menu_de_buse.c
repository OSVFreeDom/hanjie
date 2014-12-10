#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define TAILLE_MAX 70 // Tableau de taille 70

int menu(int choix, char* choix_grille[TAILLE_MAX], int* retour_menu)
{
   
    switch (choix_menu1)
    {
        case 1:

        {
            printf("Choix de la difficulte\n");
            int choix = 0;
            printf("1.Facile pour débutant\n");
            printf("2.Intermediaire pour joueurs habitues\n");
            printf("3.Difficile pour un vrai defis\n\n");
            scanf ("%d", &choix);

            if (choix ==1)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n\n");
                scanf ("%d", &choix);
                if (choix ==1)
                {
                    choix_grille = "hanjie11";
                }
                if (choix ==2)
                {
                    choix_grille = "hanjie12";
                }
                if (choix ==3)
                {
                    choix_grille = "hanjie13";
                }

                affichage_menu(choix_grille[TAILLE_MAX]);

            }
            if (choix ==2)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n\n");
                scanf ("%d", &choix);
            }
            if (choix ==3)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n\n");
                scanf ("%d", &choix);
            }

            break;
        }

        case 2:

        {
            printf("Jouer au Hanjie\n");
            int choix = 0;
            printf("1.Nouvelle partie\n");
            printf ("2.Reprendre une partie en cours\n\n");
            scanf ("%d", &choix);

            if(choix == 1)
            {
                return 1;
            }

            break;
        }

        case 3:

        {
            printf("Historique des parties\n");
            printf("Score de vos parties\n\n");

            break;
        }

    }
    return 0;
}

int affichage_menu(char* choix_grille[TAILLE_MAX], int *force_choix, int* retour_menu)
{
    char pseudo [50];
    int difficulte [3]= {0};
    int grille [3]= {0};
    printf("____________________\n");
    printf("Bienvenue sur Hanjie\n");
    printf("--------------------\n");
    printf("Quel est votre pseudo ?\n");
    scanf("%s", &pseudo );
    int choix = 0;
    printf("1. Niveau de difficulte\n");
    printf("2. Jouer au Hanjie\n");
    printf("3. Historique de vos parties\n");
    printf ("4. Manuel\n");
    printf ("5. Quitter\n");
    scanf("%d", &choix);

    if (choix == 4 || force_choix == 4)
    {
        printf("Bienvenue dans le manuel d'Hanjie. Nous allons vous expliquer comment jouer:\n");
        printf("Le jeu est composé de trois niveaux de difficultés.\n");
        printf("Pour chaque niveau, vous avez trois grilles disponibles.\n");
        printf("Le but est simple, trouver le dessin caché dans chaque grille.\n");
        printf("Pour cela, vous devrez vous servir des chiffes indiqués en haut et à gauche de la grille.\n");
        printf("Ces chiffres vous indiquent le nombres de cases à griser par lignes et colonnes.\n");
        printf("Pour griser les cases, vous devez indiquer leurs positions en mettant un espace entre chaques cases.\n");
        printf("Par exemple: A1 B6.\n");
    }

    if (choix == 5  || force_choix == 5)
    {
        printf("Au revoir et à bientot!");
        exit(-1);
    }
    menu(choix,&choix_grille,retour_menu);

}
