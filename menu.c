#include <stdio.h>
#include <stdlib.h>

int menu(choix)
{
    switch (choix)
    {
        case 1:

        {
            printf("choix de la difficulté\n");
            int choix = 0;
            printf("1.Facile pour débutant\n");
            printf("2.Intermediaire pour joueurs habitues\n");
            printf("3.Difficile pour un vrai defis\n");
            scanf ("%d", &choix);
            if choix( ==1)
            {
                printf("1.1ere grille\n");
                printf("2;2eme grille\n");
                printf("3.3eme grille\n");
                scanf ("%d", &choix);
            }


            break;
        }

        case 2:

        {
            printf("Jouer au Hanjie\n");
            int choix = 0;
            printf("1.Nouvelle partie\n");
            printf ("2.Reprendre une partie en cours\n");
            scanf ("%d", &choix);

            break;
        }

        case 3:

        {
            printf("historique des parties\n");
            printf("Score de vos parties");

            break;
        }

    }
}

int main ()
{

    char pseudo [50];
    printf("____________________\n");
    printf("Bienvenue sur Hanjie\n");
    printf("--------------------\n");
    printf("quel est votre pseudo ?\n");
    scanf("%s", &pseudo );
    int choix = 0;
    printf("1. Niveau de dificulte\n");
    printf("2. Jouer au Hanjie\n");
    printf("3. Historique de vos parties\n");
    printf ("4.Quitter\n");
    scanf("%d", &choix);
    if (choix == 4)
    {
        printf("Au revoir et à bientot!");
        return 0;
    }
    menu(choix);

}
