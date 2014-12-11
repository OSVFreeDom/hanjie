#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "menu.h"
#include "core.h"

#define TAILLE_MAX 150 // Tableau de taille 150

int main(int argc, char const *argv[])
{
	int *retour_menu =0;
	char *choix_grille[TAILLE_MAX];
	affichage_menu(&choix_grille);
	int jeu_fini = 0;
	char* nom_fichier = choix_grille;
    // initialisation des variables pour l'affichage et la gestion des grilles :
	int *taille[2] = {0};
	int *grille[TAILLE_MAX][TAILLE_MAX] = {0};
	int *grille_cours[TAILLE_MAX][TAILLE_MAX] = {2};
	taille_affichage(&taille, nom_fichier);
	int taille_largeur = taille[0];
	int taille_hauteur = taille[1];
	int *taille_nb_lignes_indicateur_colones = 0;
	int *taille_nb_lignes_indicateur_lignes = 0;
	int *nb_colones = 1;
	int *nb_lignes = 1;
	int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX] = {NULL};
	int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX] = {NULL};
	char* *commande = "";
	int *modifs[4] = {0};
	int retour_final = 0;
	char* commande_quit = "quit";
	int ret = 0;

	// Code pour l'affichage digital :
	int nn, taille1 = 5, taille2 = 20;
	int kk=0;
	int hh=0;
	int **grandTableau;
	grandTableau = malloc(taille1 *sizeof(*grandTableau));
	for (nn=0 ; nn<taille1+1 ; nn++)
    {
        grandTableau[nn] = malloc(taille2 *sizeof(**grandTableau));
    }
    int chiffre1 = 0;
  	int chiffre2 = 0;
  	int chiffre3 = 0;
  	int chiffre4 = 0;


	// Code pour l'affichage digital |


	time_t time1 = 0 ;
	time_t time2 = 0 ;
	time_t TimePast = 0;
	int minute = 0;
	int seconde = 0;
	int last = 0;
	time(&time1);

	init_grille_cours(&grille_cours);
	calcul_chiffres_colone(&taille, nom_fichier, &grille, &indicateurs_colones, &taille_nb_lignes_indicateur_colones, &nb_colones);
	calcul_chiffres_ligne(&taille, nom_fichier, &grille, &indicateurs_lignes, &taille_nb_lignes_indicateur_lignes, &nb_lignes);

	while(jeu_fini == 0 || last == 0)
	{
		system("clear");
		grille_haut(&taille, &nb_colones, &taille_nb_lignes_indicateur_lignes);
		affichage_grille2(&indicateurs_colones, &taille, &taille_nb_lignes_indicateur_colones, &nb_colones, &taille_nb_lignes_indicateur_lignes);
		affichage_grille_cours(1,1, nom_fichier, &nb_colones, &indicateurs_lignes, &taille, &taille_nb_lignes_indicateur_lignes, &nb_lignes, &grille, &grille_cours);
		//grille_bas(&taille, &nb_colones, &taille_nb_lignes_indicateur_lignes);
		if(jeu_fini == 1)
		{
			last = 1;
			chiffre2 = minute/10;
			chiffre1 = minute%10;
			chiffre3 = seconde/10;
			chiffre4 = seconde%10;
			ajout_chiffre(grandTableau, chiffre1, chiffre2, chiffre3, chiffre4);

		//	printf ("\nBravo vous avez mis %d minutes et %d secondes pour realiser cette grille \n", minute, seconde);
			printf("\n\nBravo vous avez reussi !!\n");
			printf("\n Temps de jeu pour résoudre la grille :");
			printf("\n");
			 while (kk<5)
          	 {
      			while (hh<20)
    			{
      			if (grandTableau[kk][hh] == 1)
     			{
        			printf("%c%c%c", 0xE2, 0x96, 0x88);
        			hh++;
      			}
      			else
      			{
       			printf(" ");
        		hh++;
      			}
    			}
    			kk++;
    			hh=0;
    			printf("\n");
   				}

			printf("\n (temps en minutes : secondes)");

			printf("\n\n Appuyez sur Entrer pour revenir au menu.");
			fgets(&commande, sizeof &commande, stdin);
		}
		else {
			printf("\n Coordonnees ? : ");
			scanf("%d",&retour_final);
			fgets(&commande, sizeof &commande, stdin);
			//printf("%s\n", &commande);
			//printf("%s\n", commande_quit);
			ret = strcmp(&commande, commande_quit);
			//printf("%d\n", ret);
			if(ret == 10)
			{
				//printf("OK\n");
				jeu_fini = 1;
				//printf("OK\n");
			}
			else
			{
				createCoordonnee(&commande, &nb_lignes, &nb_colones, &modifs);
				modifs_grille(&modifs, &grille_cours, &taille);
				retour_final = verification(&grille_cours, &taille, &grille);
				if(retour_final == 0)
				{
					jeu_fini = 1;
					time(&time2);
					TimePast = time2 - time1;

					minute = TimePast/60;
					seconde = TimePast%60;
				}
			}
		}

	}
	printf("%d\n", last);
	system("clear");
	affichage_menu(&choix_grille);

	return 0;
}