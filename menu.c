#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define TAILLE_MAX 150 // Tableau de taille 150

int ajout_chiffre(int **pointeurGrandTableau, int digit1, int digit2, int digit3, int digit4)
{
  int chiffre0[5][3] = {{1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1}};
  int chiffre1[5][3] = {1,0,0,1,0,0,1,0,0,1,0,0,1,0,0};
  int chiffre2[5][3] = {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1};
  int chiffre3[5][3] = {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1};
  int chiffre4[5][3] = {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1};
  int chiffre5[5][3] = {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1};
  int chiffre6[5][3] = {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1};
  int chiffre7[5][3] = {1,1,1,0,0,1,0,0,1,0,0,1,0,0,1};
  int chiffre8[5][3] = {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1};
  int chiffre9[5][3] = {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1};
  int i=0;
  int j=0;
  int k=0;


  // Place des premieres colonnes pour ajouter les 4 chiffres
  int place1 = 0; // chiffre 1 : 1ere colonne
  int place2 = 5;
  int place3 = 12;
  int place4 = 17;

  // chiffre 1

  switch (digit2)
  {
    case 1 :
      for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre1[j][k];
                        }

        k++;
    }
    break;
    case 2 :
      for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre2[j][k];
                        }

        k++;
    }
    break;
    case 3 :
      for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre3[j][k];
                        }

        k++;
    }
    break;
    case 4 :
      for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre4[j][k];
                        }

        k++;
    }
    break;
    case 5 :
      for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre5[j][k];
                        }

        k++;
    }
    break;
    case 6 :
     for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre6[j][k];
                        }

        k++;
    }
    break;
    case 7 :
      for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre7[j][k];
                        }

        k++;
    }
    break;
    case 8 :
     for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre8[j][k];
                        }

        k++;
    }
    break;
    case 9 :
      for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }
    break;
    case 0 :
     for (i= place1 ; i<place1+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }

}

// RAZ de la variable k pour la re-incrementer pour le 2eme digit
k = 0;
// chiffre2
 switch (digit1)
  {
    case 1 :
      for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre1[j][k];
                        }

        k++;
    }
    break;
    case 2 :
      for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre2[j][k];
                        }

        k++;
    }
    break;
    case 3 :
      for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre3[j][k];
                        }

        k++;
    }
    break;
    case 4 :
      for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre4[j][k];
                        }

        k++;
    }
    break;
    case 5 :
      for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre5[j][k];
                        }

        k++;
    }
    break;
    case 6 :
     for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre6[j][k];
                        }

        k++;
    }
    break;
    case 7 :
      for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre7[j][k];
                        }

        k++;
    }
    break;
    case 8 :
     for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre8[j][k];
                        }

        k++;
    }
    break;
    case 9 :
      for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }
    break;
    case 0 :
     for (i= place2 ; i<place2+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }

  }


// RAZ de la variable k pour la re-incrementer pour le 2eme digit
k = 0;

  // chiffre 3 : 
   switch (digit3)
  {
    case 1 :
      for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre1[j][k];
                        }

        k++;
    }
    break;
    case 2 :
      for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre2[j][k];
                        }

        k++;
    }
    break;
    case 3 :
      for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre3[j][k];
                        }

        k++;
    }
    break;
    case 4 :
      for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre4[j][k];
                        }

        k++;
    }
    break;
    case 5 :
      for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre5[j][k];
                        }

        k++;
    }
    break;
    case 6 :
     for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre6[j][k];
                        }

        k++;
    }
    break;
    case 7 :
      for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre7[j][k];
                        }

        k++;
    }
    break;
    case 8 :
     for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre8[j][k];
                        }

        k++;
    }
    break;
    case 9 :
      for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }
    break;
    case 0 :
     for (i= place3 ; i<place3+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }

}


// RAZ de la variable k pour la re-incrementer pour le 2eme digit
k = 0;
//chiffre 4
switch (digit4)
  {
    case 1 :
      for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre1[j][k];
                        }

        k++;
    }
    break;
    case 2 :
      for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre2[j][k];
                        }

        k++;
    }
    break;
    case 3 :
      for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre3[j][k];
                        }

        k++;
    }
    break;
    case 4 :
      for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre4[j][k];
                        }

        k++;
    }
    break;
    case 5 :
      for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre5[j][k];
                        }

        k++;
    }
    break;
    case 6 :
     for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre6[j][k];
                        }

        k++;
    }
    break;
    case 7 :
      for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre7[j][k];
                        }

        k++;
    }
    break;
    case 8 :
     for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre8[j][k];
                        }

        k++;
    }
    break;
    case 9 :
      for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }
    break;
    case 0 :
     for (i= place4 ; i<place4+3 ; i++)
    {
        for (j =0 ; j<5 ; j++)
                            {
                pointeurGrandTableau[j][i] = chiffre0[j][k];
                        }

        k++;
    }

}
  pointeurGrandTableau[1][9] = 1;
  pointeurGrandTableau[3][9] = 1;
  pointeurGrandTableau[1][10] = 1;
  pointeurGrandTableau[3][10] = 1;

}








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