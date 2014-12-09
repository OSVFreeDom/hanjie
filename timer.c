#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "timer.h"

int timer()
{
time_t time1 = 0 ;
time_t time2 = 0 ;
time_t TimePast = 0;
int minute = 0;
int seconde = 0;

time(&time1);
sleep(10);
time(&time2);
TimePast = time2 - time1;

minute = TimePast/60;
seconde = TimePast%60;
printf ("Bravo vous avez mis %d minutes et %d secondes pour realiser cette grille \n", minute, seconde);

return 0;
}