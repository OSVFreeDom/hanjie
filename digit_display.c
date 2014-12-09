#include <stdio.h>
#include <stdlib.h>

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

  switch (digit1)
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
 switch (digit2)
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

int main(int argc, char const *argv[])
{
	int i, taille1 = 5, taille2 = 20;
	int **grandTableau;
	grandTableau = malloc(taille1 *sizeof(*grandTableau));
	for (i=0 ; i<taille1+1 ; i++)
    {
        grandTableau[i] = malloc(taille2 *sizeof(**grandTableau));
    }



	int place=0;
int k=0;
    int h=0;
  int chiffre1 = 2;
  int chiffre2 = 3;
  int chiffre3 = 4;
  int chiffre4 = 0;

	ajout_chiffre(grandTableau, chiffre1, chiffre2, chiffre3, chiffre4);


  // affichage du tableau final en ligne :


/*
   for (k=0 ; k<5 ; k++)
   {

       for(h=0; h<20 ; h++)
       {
           printf("grandtableau [%d][%d] : ",k,h);
           printf("%d\n",grandTableau[k][h]);
       }
   }
*/
  while (k<5)
   {
    while (h<20)
    {
      if (grandTableau[k][h] == 1)
      {
        printf("%c%c%c", 0xE2, 0x96, 0x88);
        h++;
      }
      else
      {
        printf(" ");
        h++;
      }
    }
    k++;
    h=0;
    printf("\n");
   }
   printf("\n");
    return 0;
}
