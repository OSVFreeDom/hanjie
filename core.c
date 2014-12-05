#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 70 // Tableau de taille 70

int main(int argc, char const *argv[])
{
	//FILE* fichier = NULL;
	char* nom_fichier = "hanjie2.pbm";

	int *taille[2] = {0};
	int *grille[TAILLE_MAX][TAILLE_MAX] = {0};
	taille_affichage(&taille, nom_fichier);
	int taille_largeur = taille[0];
	int taille_hauteur = taille[1];
	int *taille_nb_lignes_indicateur_colones = 0;
	int *taille_nb_lignes_indicateur_lignes = 0;
	int *nb_colones = 1;
	int *nb_lignes = 1;
	int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX] = {NULL};
	int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX] = {NULL};
	//printf("%d %d\n", taille[0], taille[1]);

	calcul_chiffres_colone(&taille, nom_fichier, &grille, &indicateurs_colones, &taille_nb_lignes_indicateur_colones, &nb_colones);
	calcul_chiffres_ligne(&taille, nom_fichier, &grille, &indicateurs_lignes, &taille_nb_lignes_indicateur_lignes, &nb_lignes);
	grille_haut(&taille, &nb_colones);
	affichage_grille2(&indicateurs_colones, &taille, &taille_nb_lignes_indicateur_colones, &nb_colones);
	affichage_grille3(&indicateurs_lignes, &taille, &taille_nb_lignes_indicateur_lignes, &nb_lignes);
	affichage_grille(1,1, nom_fichier, &nb_colones);
	return 0;
}

int affichage_grille(int niveau, int diffuclte, char* nom_fichier, int *nb_colones)
{
	//char* nom_fichier = "hanjie1.pbm";
	
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
 
    fichier = fopen(nom_fichier, "r");
 
    if (fichier != NULL)
    {
    	int i = 1;
    	int j = 0;
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
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
							if(*nb_colones == 2)
		       				{
		       					printf("%c%c%c", 0xE2, 0x96, 0x88);
		       				}
							printf("%c%c%c", 0xE2, 0x96, 0x88);
							printf("%c%c%c", 0xE2, 0x96, 0x88);
						} else {
							if(*nb_colones == 2)
		       				{
		       					printf(" ");
		       				}
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
        		//printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        	}
            //printf("%s", chaine); // On affiche la chaîne qu'on vient de lire

            i++;
            j = 0;
        }
 		//printf("%s", new_chaine);
        fclose(fichier);

    }
    return 0;
}

int affichage_grille2(int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_colones, int *nb_colones)
{	
    int i = *taille_nb_lignes_indicateur_colones;
    int j = 0;
    int doublevaleur = taille[1] * 2;
    int triplevaleur = taille[1] * 3;
    int k = 0;

    //printf("%d\n", i);
    //printf("%d\n", *taille_nb_lignes_indicateur_colones);
    while (k < i)
    {
    	j = 0;
    	printf("     ");
    	printf("%c%c%c", 0xE2, 0x94, 0x82);
      	while (j < taille[1])
       	{
       		if(indicateurs_colones[k][j] == 0)
       		{
       			printf("  ");
       			if(*nb_colones == 2)
       			{
       				printf(" ");
       			}
       		}
       		else
       		{
       			if(indicateurs_colones[k][j] < 10)
       			{
       				if(*nb_colones == 2)
       				{
       					printf(" ");
       				}
       				printf(" ");
       				printf ("%d", indicateurs_colones[k][j]);
       			}
       			else
       			{
       				if(*nb_colones == 2)
       				{
       					printf(" ");
       				}
       				printf ("%d", indicateurs_colones[k][j]);
       			}
       		}
       		j++;
       	}
       	//printf("%d", i);
       	printf(" ");
       	printf("%c%c%c", 0xE2, 0x94, 0x82);
       	printf ("\n");
        k++;
    }
    j = 0;
    //printf ("\n");
    printf("       ");
    if(*nb_colones == 2)
    {
       	while (j < triplevaleur)
       	{
       		printf("%c%c%c", 0xE2, 0x94, 0x80);
       		j++;
       	}
    }
    else {
    	while (j < doublevaleur)
       	{
       		printf("%c%c%c", 0xE2, 0x94, 0x80);
       		j++;
       	}
    }
    printf ("\n");
    return 0;
}

int affichage_grille3(int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_lignes, int *nb_lignes)
{	
    int i = *taille_nb_lignes_indicateur_lignes;
    int j = 0;
    int doublevaleur = taille[0] * 2;
    int triplevaleur = taille[0] * 3;
    int k = 0;

    //printf("%d\n", i);
    //printf("%d\n", *taille_nb_lignes_indicateur_colones);
    while (k < i)
    {
    	j = 0;
    	//printf("     ");
    	//printf("%c%c%c", 0xE2, 0x94, 0x82);
      	while (j < taille[1])
       	{
       		if(indicateurs_lignes[j][k] == 0)
       		{
       			printf("  ");
       			if(*nb_lignes == 2)
       			{
       				printf(" ");
       			}
       		}
       		else
       		{
       			if(indicateurs_lignes[j][k] < 10)
       			{
       				if(*nb_lignes == 2)
       				{
       					printf(" ");
       				}
       				printf(" ");
       				printf ("%d", indicateurs_lignes[j][k]);
       			}
       			else
       			{
       				if(*nb_lignes == 2)
       				{
       					printf(" ");
       				}
       				printf ("%d", indicateurs_lignes[j][k]);
       			}
       		}
       		j++;
       	}
       	//printf("%d", i);
       	//printf(" ");
       	//printf("%c%c%c", 0xE2, 0x94, 0x82);
       	printf ("\n");
        k++;
    }
    j = 0;
    //printf ("\n");
    //printf("       ");
    /*if(*nb_lignes == 2)
    {
       	while (j < triplevaleur)
       	{
       		printf("%c%c%c", 0xE2, 0x94, 0x80);
       		j++;
       	}
    }
    else {
    	while (j < doublevaleur)
       	{
       		printf("%c%c%c", 0xE2, 0x94, 0x80);
       		j++;
       	}
    }*/
    printf ("\n");
    return 0;
}

int taille_affichage(int *taille, char* nom_fichier)
{
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
 
    fichier = fopen(nom_fichier, "r");
 
    if (fichier != NULL)
    {
    	int i = 0;
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
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
            //printf("%s", chaine); // On affiche la chaîne qu'on vient de lire

            i++;
        }
 
        fclose(fichier);
        //printf("%d %d", chaine);
    }
    return 0;

}

int grille_haut(int *taille[2], int *nb_colones)
{
	int k = 0;
	int i = 0;
	int somme = 0;
	int sommedouble = 0;
	int sommetriple = 0;
	int j = 0;
	somme = taille[0];
	sommedouble = (somme * 2);
	sommetriple = (somme * 3);
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
		if(*nb_colones == 2)
       	{
       		printf(" ");
       	}
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
	if(*nb_colones == 2)
    {
       	while(j < sommetriple)
		{
			printf("%c%c%c", 0xE2, 0x94, 0x80);
			j++;
		}
    }
    else {
    	while(j < sommedouble)
		{
			printf("%c%c%c", 0xE2, 0x94, 0x80);
			j++;
		}
    }
	printf("\n");
    return 0;

}

int grille_gauche(int *taille[2], int *nb_cours, int debut, int *nb_colones)
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

int calcul_chiffres_colone(int *taille, char* nom_fichier, int *grille[TAILLE_MAX][TAILLE_MAX], int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX], int *taille_nb_lignes_indicateur_colones, int *nb_colones)
{
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
 
    fichier = fopen(nom_fichier, "r");

    if (fichier != NULL)
    {
		int i = 0;
	    int j = 0;
	    int k = 1;
	    //int k = 0;
	        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
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
	int smax = s;
	while(c < taille[1])
	{
		//printf("%d\n", s);
		if(s > smax)
		{
			smax = s;
		}
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
					if(o >= 10)
					{
						*nb_colones = 2;
					}
					s++;
					o = 0;
				}
			}
			l++;
			if(o > 0)
			{
				indicateurs_colones[s][c] = o;
				if(o >= 10)
				{
					*nb_colones = 2;
				}
				
			}
		}
		s++;
		c++;
	}
	if(s > smax)
	{
		smax = s;
	}
	*taille_nb_lignes_indicateur_colones = smax;
	//printf("%d\n", *taille_nb_lignes_indicateur_colones);
    return 0;
}

int calcul_chiffres_ligne(int *taille, char* nom_fichier, int *grille[TAILLE_MAX][TAILLE_MAX], int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille_nb_lignes_indicateur_lignes, int *nb_lignes)
{
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
 
    fichier = fopen(nom_fichier, "r");

    if (fichier != NULL)
    {
		int i = 0;
	    int j = 0;
	    int k = 1;
	    //int k = 0;
	        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
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
	int smax = s;
	while(l < taille[0])
	{
		//printf("%d\n", s);
		if(s > smax)
		{
			smax = s;
		}
		c = 0;
		s = 0;
		o = 0;
		while(c < taille[1])
		{
			if(grille[l][c] == 1) {
				o++;
				//printf("%d\n", grille[l][c]);
			}
			if(grille[l][c] == 0) {
				if(o > 0)
				{
					indicateurs_lignes[s][l] = o;
					//printf("%d ", indicateurs_colones[s][c]);
					if(o >= 10)
					{
						*nb_lignes = 2;
					}
					s++;
					o = 0;
				}
			}
			c++;
			if(o > 0)
			{
				indicateurs_lignes[s][l] = o;
				if(o >= 10)
				{
					*nb_lignes = 2;
				}
				
			}
		}
		s++;
		l++;
	}
	if(s > smax)
	{
		smax = s;
	}
	*taille_nb_lignes_indicateur_lignes = smax;
	//printf("%d\n", *taille_nb_lignes_indicateur_colones);
    return 0;
}