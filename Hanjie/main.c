#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 70 // Tableau de taille 70

int main(int argc, char const *argv[])
{
	//FILE* fichier = NULL;
	char* nom_fichier = "hanjie1.pbm";

	int *taille[2] = {0};
	int *grille[TAILLE_MAX][TAILLE_MAX] = {0};
	taille_affichage(&taille, nom_fichier);
	int taille_largeur = taille[0];
	int taille_hauteur = taille[1];
	int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX] = {NULL};
	//grille_haut(&taille);
	//printf("%d %d\n", taille[0], taille[1]);
	//affichage_grille(1,1, nom_fichier);

	calcul_chiffres_colone(&taille, nom_fichier, &grille, &indicateurs_colones);
	affichage_grille2(&indicateurs_colones, &taille);
	return 0;
}

int affichage_grille(int niveau, int diffuclte, char* nom_fichier)
{
	//char* nom_fichier = "hanjie1.pbm";

	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Cha”ne vide de taille TAILLE_MAX

    fichier = fopen(nom_fichier, "r");

    if (fichier != NULL)
    {
    	int i = 1;
    	int j = 0;
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reoit pas d'erreur (NULL)
        {
        	if(i >= 3)
        	{
        		char ** new_chaine = NULL;
        		char *  p    = strtok (chaine, " ");
        		int n_spaces = 0, i;
				/* split string and append tokens to 'res' */

				while (p) {
				  new_chaine = realloc (new_chaine, sizeof (char*) * ++n_spaces);

				  if (new_chaine == NULL)
				    exit (-1); /* memory allocation failed */

				  new_chaine[n_spaces-1] = p;

				  p = strtok (NULL, " ");
				}
				printf("       ");
				/* realloc one extra element for the last NULL */

				new_chaine = realloc (new_chaine, sizeof (char*) * (n_spaces+1));
				new_chaine[n_spaces] = 0;

				/* print the result */

				for (i = 0; i < (n_spaces+1); ++i)
				{
					if(new_chaine[i] != NULL)
					{
						if(atoi(new_chaine[i]) == 1)
						{
							printf("%c%c%c", 0xE2, 0x96, 0x88);
							printf("%c%c%c", 0xE2, 0x96, 0x88);
						} else {
							printf(" ");
							printf(" ");
						}
					} else {
						printf("\n");
					}
				  //printf ("new_chaine[%d] = %s\n", i, new_chaine[i]);
					//printf ("%s\n", new_chaine[i]);
				}

				/* free the memory allocated */

				free (new_chaine);
        		//printf("%s", chaine); // On affiche la cha”ne qu'on vient de lire
        	}
            //printf("%s", chaine); // On affiche la cha”ne qu'on vient de lire

            i++;
            j = 0;
        }
 		//printf("%s", new_chaine);
        fclose(fichier);

    }
    return 0;
}

int affichage_grille2(int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX], int *taille)
{
    int i = 0;
    int j = 0;
    while (i < taille[0]) // On lit le fichier tant qu'on ne reoit pas d'erreur (NULL)
    {
    	j = 0;
      	while (j < taille[1])
       	{
       		printf ("%d", indicateurs_colones[i][j]);
       		j++;
       	}
       	//printf("%d", i);
       	//printf ("\n");
        i++;
    }
    return 0;
}

int taille_affichage(int *taille, char* nom_fichier)
{
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Cha”ne vide de taille TAILLE_MAX

    fichier = fopen(nom_fichier, "r");

    if (fichier != NULL)
    {
    	int i = 0;
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reoit pas d'erreur (NULL)
        {
        	if(i == 1)
        	{
        		//fscanf(fichier, "%d %d", &taille[0], &taille[1]);
        		char *  p    = strtok (chaine, " ");
        		taille[0] = atoi(p);
        		p    = strtok (chaine, " ");
        		taille[1] = atoi(p);
        		//printf("%s \n", chaine);
        		//printf("%d %d\n", taille[0], taille[1]);
        	}
            //printf("%s", chaine); // On affiche la cha”ne qu'on vient de lire

            i++;
        }

        fclose(fichier);
        //printf("%d %d", chaine);
    }
    return 0;

}

int grille_haut(int *taille[2])
{
	int k = 0;
	int i = 0;
	int somme = 0;
	int sommedouble = 0;
	int j = 0;
	somme = taille[0];
	sommedouble = (somme * 2);
	//printf("%d %d\n", somme, sommedouble);
	printf("       ");
	/*if(somme >= 10)
	{
		char lettres[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		printf("%c ", lettres[0]);
	}*/
	while(i < somme)
	{
		char lettres[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		printf("%c ", lettres[i]);
		//printf("%c%c%c", 0xE2, 0x94, 0x80);
		i++;
	}
	printf("\n");
	printf("       ");
	/*if(sommedouble >= 10)
	{
		while(j < sommedouble)
		{
			printf("%c%c%c", 0xE2, 0x94, 0x80);
			j++;
		}
	}*/
	while(j < sommedouble)
	{
		printf("%c%c%c", 0xE2, 0x94, 0x80);
		j++;
	}
	printf("\n");
    return 0;

}

int grille_gauche(int *taille[2], int *nb_cours, int debut, int nb_colones)
{
	int j = 0;
	if (debut == 1)
	{
		printf("   ");
		while(j < nb_colones) {
			for (int i = 0; i < 3; i++)
			{
				printf("%c%c%c", 0xE2, 0x94, 0x80);
			}
			j++;
		}
	}
	else {
		printf("%d ", nb_cours);
		printf(" ");
		printf("%c%c%c", 0xE2, 0x94, 0x82);
	}
	return 0;
}

int calcul_chiffres_colone(int *taille, char* nom_fichier, int *grille[TAILLE_MAX][TAILLE_MAX], int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX])
{
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Cha”ne vide de taille TAILLE_MAX

    fichier = fopen(nom_fichier, "r");

    if (fichier != NULL)
    {
		int i = 0;
	    int j = 0;
	    int k = 1;
	    //int k = 0;
	        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reoit pas d'erreur (NULL)
	        {
	        	i = 0;
	        	if(k >= 3)
	        	{
	        		char *  p    = strtok (chaine, " ");

					while (p) {

					  grille[j][i] = atoi(p);
					  //printf("test : %d ", grille[j][i]);
					  i++;
					  p = strtok (NULL, " ");
					}
					j++;
	        	}

	            k++;
	        }
	        fclose(fichier);

	}
	int l = 0;
	int c = 0;
	int o = 0;
	int s = 0;
	while(c < taille[1])
	{
		l = 0;
		s = 0;
		o = 0;
		while(l < taille[0])
		{
			if(grille[l][c] == 1) {
				o++;
			}
			if(grille[l][c] == 0) {
				if(o > 0)
				{
					indicateurs_colones[s][c] = o;
					//printf("%d ", indicateurs_colones[s][c]);
					s++;
					o = 0;
				}
			}
			l++;
		}
		c++;
	}
    return 0;
}
