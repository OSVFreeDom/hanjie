#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define TAILLE_MAX 70 // Tableau de taille 70

int affichage_menu(char* choix_grille[TAILLE_MAX], int* retour_menu)
{

    // declaration de variables pour enregistrer pseudo joueur et gerer le menu
    char pseudo[50];
    int choix_menu1= 0;
    int menu_exit =0;
    int choix_menu_difficulte = 0;
    int choix_menu_grille = 0;
    int niveau_choisi =0;
    printf("____________________\n");
    printf("Bienvenue sur Hanjie\n");
    printf("--------------------\n");
    printf("Quel est votre pseudo ?\n");
    scanf("%s", &pseudo );

    while (menu_exit == 0)
    {
        system("clear");
    printf("\n--------------------\n");
    printf("Menu du Jeu Hanjie :");
    printf("\n--------------------\n");
    printf("1. Regler niveau de difficulte\n");
    printf("2. Jouer au Hanjie\n");
    printf("3. Manuel\n");
    printf("4. Quitter\n");
    scanf("%d", &choix_menu1);

    // switch qui gere les choix du joueur dans le menu
    switch (choix_menu1)
    {
        case 1 :
        {
            // Choix de la difficultee pour le joueur :

            system("clear");
            printf("____________________\n");
            printf("Choix de la difficulte\n");
            printf("--------------------\n");
            printf("1.Facile pour débutant\n");
            printf("2.Intermediaire pour joueurs habitues\n");
            printf("3.Difficile pour un vrai defis\n\n");
            scanf ("%d", &choix_menu_difficulte);

            // Puis ensuite quelle grille il veut, en fonction de la diffucultee
                if (choix_menu_difficulte ==1)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n\n");
                scanf ("%d", &choix_menu_grille);
                if (choix_menu_grille ==1)
                {
                   sprintf(choix_grille,"hanjie11.pbm");
                   niveau_choisi =1;
                }
                if (choix_menu_grille ==2)
                {
                    sprintf(choix_grille,"hanjie12.pbm");
                    niveau_choisi =1;
                }
                if (choix_menu_grille ==3)
                {
                    sprintf(choix_grille,"hanjie13.pbm");
                    niveau_choisi =1;
                }
            }
            if (choix_menu_difficulte ==2)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n\n");
                scanf ("%d", &choix_menu_grille);
                if (choix_menu_grille ==1)
                {
                    sprintf(choix_grille,"hanjie21.pbm");
                    niveau_choisi =1;
                }
                if (choix_menu_grille ==2)
                {
                    sprintf(choix_grille,"hanjie22.pbm");
                    niveau_choisi =1;
                }
                if (choix_menu_grille ==3)
                {
                    sprintf(choix_grille,"hanjie23.pbm");
                    niveau_choisi =1;
                }
            }

            if (choix_menu_difficulte ==3)
            {
                printf("1.1ere grille\n");
                printf("2.2eme grille\n");
                printf("3.3eme grille\n\n");
                scanf ("%d", &choix_menu_grille);
                if (choix_menu_grille ==1)
                {
                    sprintf(choix_grille,"hanjie31.pbm");
                     niveau_choisi =1;
                }
                if (choix_menu_grille ==2)
                {
                    sprintf(choix_grille,"hanjie32.pbm");
                     niveau_choisi =1;
                }
                if (choix_menu_grille ==3)
                {
                    sprintf(choix_grille,"hanjie33.pbm");
                    niveau_choisi =1;
                }
            }



        }
        break;

        case 2 :
        {
            if (niveau_choisi == 1)
            {
                menu_exit =1;
                system("clear");
                printf("Lancement de la nouvelle partie en cours..\n\n");
            }
            else
            {
            printf("Vous devez d'abord choisir un niveau de difficultee avant de lancer une partie!");
            }

        }
        break;

        case 3 :
        {
            system("clear");
            printf("Bienvenue dans le manuel d'Hanjie. Nous allons vous expliquer comment jouer:\n");
            printf("Le jeu est composé de trois niveaux de difficultés.\n");
            printf("Pour chaque niveau, vous avez trois grilles disponibles.\n");
            printf("Le but est simple, trouver le dessin caché dans chaque grille.\n");
            printf("Pour cela, vous devrez vous servir des chiffes indiqués en haut et à gauche de la grille.\n");
            printf("Ces chiffres vous indiquent le nombres de cases à griser par lignes et colonnes.\n");
            printf("Pour griser les cases, vous devez indiquer leurs positions en mettant un espace entre chaques cases.\n");
            printf("Par exemple: A1 B6.\n");
        }
        break;

        case 4 :
        {
            menu_exit = 1;
            system("clear");
            printf("Au revoir et à bientot!\n\n");
            exit(-1);
        }
        break;
    }
    }

}