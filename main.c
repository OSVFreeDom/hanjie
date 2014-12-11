#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "menu.h"
#include "core.h"

#define TAILLE_MAX 70 // Tableau de taille 70

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

	init_grille_cours(&grille_cours);
	calcul_chiffres_colone(&taille, nom_fichier, &grille, &indicateurs_colones, &taille_nb_lignes_indicateur_colones, &nb_colones);
	calcul_chiffres_ligne(&taille, nom_fichier, &grille, &indicateurs_lignes, &taille_nb_lignes_indicateur_lignes, &nb_lignes);

	while(jeu_fini == 0)
	{
		grille_haut(&taille, &nb_colones, &taille_nb_lignes_indicateur_lignes);
		affichage_grille2(&indicateurs_colones, &taille, &taille_nb_lignes_indicateur_colones, &nb_colones, &taille_nb_lignes_indicateur_lignes);
		affichage_grille_cours(1,1, nom_fichier, &nb_colones, &indicateurs_lignes, &taille, &taille_nb_lignes_indicateur_lignes, &nb_lignes, &grille, &grille_cours);
		printf("\n Coordonnees ? : ");
		scanf("%d",&retour_final);
		fgets(&commande, sizeof &commande, stdin);
		createCoordonnee(&commande, &nb_lignes, &nb_colones, &modifs);
		modifs_grille(&modifs, &grille_cours, &taille);
		retour_final = verification(&grille_cours, &taille, &grille);
		if(retour_final == 0)
		{
			jeu_fini = 1;
		}

	}

	return 0;
}