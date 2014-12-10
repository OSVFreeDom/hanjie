#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TAILLE_MAX 70 // Tableau de taille 70

int createCoordonnee(char* str, int *nbligne, int *nbcolonne, int *modifs);
int modifs_grille(int *modifs, int *grille_cours[TAILLE_MAX][TAILLE_MAX], int *taille);
int verification(int *grille_cours[TAILLE_MAX][TAILLE_MAX], int *taille, int *grille[TAILLE_MAX][TAILLE_MAX]);
int init_grille_cours(int *grille_cours[TAILLE_MAX][TAILLE_MAX]);
int affichage_grille(int niveau, int diffuclte, char* nom_fichier, int *nb_colones, int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_lignes, int *nb_lignes);
int affichage_grille_cours(int niveau, int diffuclte, char* nom_fichier, int *nb_colones, int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_lignes, int *nb_lignes, int *grille[TAILLE_MAX][TAILLE_MAX], int *grille_cours[TAILLE_MAX][TAILLE_MAX]);
int affichage_grille2(int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_colones, int *nb_colones, int *taille_nb_lignes_indicateur_lignes);
int affichage_grille3(int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_lignes, int *nb_lignes, int ligne_cours);
int taille_affichage(int *taille, char* nom_fichier);
int grille_haut(int *taille[2], int *nb_colones, int *taille_nb_lignes_indicateur_lignes);
int grille_gauche(int *taille[2], int *nb_cours, int debut, int *nb_colones, int *taille_nb_lignes_indicateur_lignes);
int calcul_chiffres_colone(int *taille, char* nom_fichier, int *grille[TAILLE_MAX][TAILLE_MAX], int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX], int *taille_nb_lignes_indicateur_colones, int *nb_colones);
int calcul_chiffres_ligne(int *taille, char* nom_fichier, int *grille[TAILLE_MAX][TAILLE_MAX], int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille_nb_lignes_indicateur_lignes, int *nb_lignes);
