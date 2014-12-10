#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TAILLE_MAX 70 // Tableau de taille 70

int createCoordonnee(char* str, int *nbligne, int *nbcolonne, int *modifs)
{
    int i=1, y;
    char tmp[2];
 
    /*on verifie si le caractère entré est entre A et le nombre max de ligne
    si non on retourne un code erreur*/
    if (str[0]<'A' && str[0]>='A'+nbcolonne)
    {
        modifs[0]=-1;
        return 1;
    }
    else
    {
        modifs[0]= str[0]-'A';
    }
    /*on verifie si le caractère lu est entre 0 et 9*/
    if (str[0]<'0' && str[1]>='9')
    {
        modifs[1]=-1;
        return 1;
    }
    /*on rentre dans une boucle au cas ou il est plusieurs chiffre*/
    while (str[i]>='0' && str[i]<='9')
    {
        tmp[i-1]=str[i];
        i++;
    }
    i++;
 
    /*on converti la chaine de caractère en nombre*/
    modifs[1]=atoi(tmp)-1;

 
    /*on verifie si il y a plusieurs coordonné entré ou qu'une seul
    si il n'y a qu'ne seul coordonné, on retourne le tableau avec des -1 sur les deuxième coordonné*/
    if(str[i]==' '||str[i]=='\0'||str[i]=='\n')
    {
        modifs[2]=-1;
        modifs[3]=-1;
        return 1;
    }
    /*sinon on refait la même manip qu'avant pour la nouvelles coordonné*/
    else
    {
        if (str[i]<'A' && str[i]>='A'+nbcolonne)
        {
            modifs[2]=-1;
            return 1;
        }
        else
        {
            modifs[2]= str[i]-'A';
        }
        y=i+1;
        if (str[y]<'0' && str[y]>='9')
        {
            modifs[3]=-1;
            return 1;
        }
        tmp[0]='\0';
        tmp[1]='\0';
        while (str[y]>='0' && str[y]<='9')
        {
            tmp[y-i-1]=str[y];
            y++;
        }
        modifs[3]=atoi(tmp)-1;
    }
    return 0;//on retourn le tableau de coordonné
}

int modifs_grille(int *modifs, int *grille_cours[TAILLE_MAX][TAILLE_MAX], int *taille)
{
	int deux = 0;
	int x,y,x2,y2 = 0;
	int i = 0;
	int same = 0;


	if(modifs[0] != -1)
	{
		y = modifs[0];
	}
	if(modifs[1] != -1)
	{
		x = modifs[1];
	}
	if(modifs[2] != -1)
	{
		y2 = modifs[2];
		deux = 1;
	}
	if(modifs[3] != -1)
	{
		x2 = modifs[3];
	}

	if(x == x2)
	{
		same = 1;
	}

	if(deux != 1)
	{
		if(grille_cours[x][y] == 0)
		{
			grille_cours[x][y] = 1;
		}
		else
		{
			grille_cours[x][y] = 0;
		}
	}
	else {
		if(same != 1)
		{
			while(x <= x2)
			{
				y = 0;
				while(y < taille[1])
				{
					if(grille_cours[x][y] == 0)
					{
						grille_cours[x][y] = 1;
					}
					else
					{
						grille_cours[x][y] = 0;
					}
					y++;
				}
				x++;
			}
			y = 0;
			while(y <= y2)
			{
				if(grille_cours[x][y] == 0)
				{
					grille_cours[x][y] = 1;
				}
				else
				{
					grille_cours[x][y] = 0;
				}
				y++;
			}
		}
		else {
			while(x <= x2)
			{
				y = 0;
				while(y <= y2)
				{
					if(grille_cours[x][y] == 0)
					{
						grille_cours[x][y] = 1;
					}
					else
					{
						grille_cours[x][y] = 0;
					}
					y++;
				}
				x++;
			}
		}
	}
	return 0;
}

int verification(int *grille_cours[TAILLE_MAX][TAILLE_MAX], int *taille, int *grille[TAILLE_MAX][TAILLE_MAX])
{
	int valide = 0;
	int x = 0;
	int y = 0;
	while(x < taille[0])
	{
		y = 0;
		while(y < taille[1])
		{
			if(grille_cours[x][y] != grille[x][y])
			{
				valide = 0;
				return 1;
			}
			y++;
		}
		x++;
	}

	return 0;
}

int init_grille_cours(int *grille_cours[TAILLE_MAX][TAILLE_MAX])
{
	int i, j = 0;
	while(i < TAILLE_MAX)
	{
		j = 0;
		while(j < TAILLE_MAX)
		{
			grille_cours[i][j] = 0;
			j++;
		}
		i++;
	}

	return 0;
}

int affichage_grille(int niveau, int diffuclte, char* nom_fichier, int *nb_colones, int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_lignes, int *nb_lignes)
{
	
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int l = 0;
 
    fichier = fopen(nom_fichier, "r");
 
    if (fichier != NULL)
    {
    	int i = 1;
    	int j = 0;
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
        	if(i >= 3)
        	{
        		affichage_grille3(indicateurs_lignes, taille, taille_nb_lignes_indicateur_lignes, nb_lignes, l);
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
				printf(" ");
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
				}

				/* free the memory allocated */

				free (new_chaine);
        		l++;
        	}

            i++;
            j = 0;
        }
        fclose(fichier);

    }
    return 0;
}

int affichage_grille_cours(int niveau, int diffuclte, char* nom_fichier, int *nb_colones, int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_lignes, int *nb_lignes, int *grille[TAILLE_MAX][TAILLE_MAX], int *grille_cours[TAILLE_MAX][TAILLE_MAX])
{
	
    int l = 0;
    int i = 0;
    int j = 0;
 
				while (i < taille[0])
				{
					affichage_grille3(indicateurs_lignes, taille, taille_nb_lignes_indicateur_lignes, nb_lignes, l);
					printf(" ");
					j = 0;
					while (j < taille[1])
					{
						if(grille_cours[i][j] == 1)
						{
							if(*nb_colones == 2)
		       				{
		       					printf("%c%c%c", 0xE2, 0x96, 0x88);
		       				}
							printf("%c%c%c", 0xE2, 0x96, 0x88);
							printf("%c%c%c", 0xE2, 0x96, 0x88);
						}
						if(grille_cours[i][j] == 2)
						{
							if(*nb_colones == 2)
		       				{
		       					printf("%c%c%c", 0xE2, 0x96, 0x91);
		       				}
							printf("%c%c%c", 0xE2, 0x96, 0x91);
							printf("%c%c%c", 0xE2, 0x96, 0x91);
						}
						if(grille_cours[i][j] == 0) 
						{
							if(*nb_colones == 2)
		       				{
		       					printf(" ");
		       				}
							printf(" ");
							printf(" ");
						}
						j++;
					}
					printf("\n");
					i++;
					l++;
				}
				
    return 0;
}

int affichage_grille2(int *indicateurs_colones[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_colones, int *nb_colones, int *taille_nb_lignes_indicateur_lignes)
{	
    int i = *taille_nb_lignes_indicateur_colones;
    int j = 0;
    int doublevaleur = taille[1] * 2;
    int triplevaleur = taille[1] * 3;
    int k = 0;

    while (k < i)
    {
    	j = 0;
    	printf(" ");
    	for (int i = 0; i < *taille_nb_lignes_indicateur_lignes; i++)
		{
			printf("  ");
			if(*nb_colones == 2)
       		{
       			printf(" ");
       		}
		}
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
       	printf(" ");
       	printf("%c%c%c", 0xE2, 0x94, 0x82);
       	printf ("\n");
        k++;
    }
    j = 0;
    printf("  ");
    for (int i = 0; i < *taille_nb_lignes_indicateur_lignes; i++)
		{
			printf("%c%c%c", 0xE2, 0x94, 0x80);
		}
    if(*nb_colones == 2)
    {
    	for (int i = 0; i < *taille_nb_lignes_indicateur_lignes; i++)
		{
			printf("%c%c%c", 0xE2, 0x94, 0x80);
			printf("%c%c%c", 0xE2, 0x94, 0x80);
			printf("%c%c%c", 0xE2, 0x94, 0x80);
		}
       	while (j < triplevaleur)
       	{
       		printf("%c%c%c", 0xE2, 0x94, 0x80);
       		j++;
       	}
    }
    else {
    	for (int i = 0; i < *taille_nb_lignes_indicateur_lignes; i++)
		{
			printf("%c%c%c", 0xE2, 0x94, 0x80);
			printf("%c%c%c", 0xE2, 0x94, 0x80);
		}
    	while (j < doublevaleur)
       	{
       		printf("%c%c%c", 0xE2, 0x94, 0x80);
       		j++;
       	}
    }
    printf ("\n");
    return 0;
}

int affichage_grille3(int *indicateurs_lignes[TAILLE_MAX][TAILLE_MAX], int *taille, int *taille_nb_lignes_indicateur_lignes, int *nb_lignes, int ligne_cours)
{	
    int i = *taille_nb_lignes_indicateur_lignes;
    int j = 0;
    int doublevaleur = taille[0] * 2;
    int triplevaleur = taille[0] * 3;
    int k = 0;

    k = ligne_cours;

    	j = 0;
    	printf("%c%c%c", 0xE2, 0x94, 0x82);
      	while (j < i)
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
       	printf("%c%c%c", 0xE2, 0x94, 0x82);

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
        		char *  p    = strtok (chaine, " ");
        		taille[0] = atoi(p);
        		p    = strtok (chaine, " ");
        		taille[1] = atoi(p);
        	}
            i++;
        }
 
        fclose(fichier);
    }
    return 0;

}

int grille_haut(int *taille[2], int *nb_colones, int *taille_nb_lignes_indicateur_lignes)
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
	for (int i = 0; i < *taille_nb_lignes_indicateur_lignes; i++)
	{
		printf("  ");
		if(*nb_colones == 2)
       		{
       			printf(" ");
       		}
	}
	printf("   ");
	while(i < somme)
	{
		char lettres[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		if(*nb_colones == 2)
       	{
       		printf(" ");
       	}
		printf("%c ", lettres[i]);
		i++;
	}
	printf("\n");
	printf("  ");
	for (int i = 0; i < *taille_nb_lignes_indicateur_lignes; i++)
	{
		printf("  ");
		if(*nb_colones == 2)
       		{
       			printf(" ");
       		}
	}
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

int grille_gauche(int *taille[2], int *nb_cours, int debut, int *nb_colones, int *taille_nb_lignes_indicateur_lignes)
{
	int j = 0;
	for (int i = 0; i < *taille_nb_lignes_indicateur_lignes; i++)
	{
		printf("    ");
	}
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
	        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
	        {	
	        	i = 0;
	        	if(k >= 3)
	        	{
	        		char *  p    = strtok (chaine, " ");

					while (p) {
					  
					  grille[j][i] = atoi(p);
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
	        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
	        {	
	        	i = 0;
	        	if(k >= 3)
	        	{
	        		char *  p    = strtok (chaine, " ");

					while (p) {
					  
					  grille[j][i] = atoi(p);
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
			}
			if(grille[l][c] == 0) {
				if(o > 0)
				{
					indicateurs_lignes[s][l] = o;
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
    return 0;
}