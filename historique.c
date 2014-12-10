#include <stdio.h> //on va dans les bibliothèques stdio et stdlib.
#include <stdlib.h>
#define TAILLE_MAX 1000 //Taille du tableau (ici il est de taille 1000)

int main(int argc, char *argv[])
{
    FILE* historique = NULL; //on initialise le pointeur à NULL.

    char chaine[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX.


    historique = fopen("historique.txt", "r+");  //non du fichier pointé.

    if (historique != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, historique) != NULL) //On lit le fichier tant que l'on ne reçoit pas (NULL).
        {
            printf("%s", chaine); //on affiche la chaîne que l'on vient de lire.

        }


        fclose(historique); //On ferme le fichier ouvert.
    }
    else
    {

        printf("Il n'y a aucune donnee sauvegardee"); //message d'erreur si il n'y a pas encore de sauvegarde.

    }

    return 0;
}

