/******
*
*   main.c
*
*   Name: Jonathan Hellebusch
*   Datum: 18.12.2018
*
*****/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

/******
*
* Bezeichner: main
*
* Beschreibung: Testfunktion
*
*
*****/
int test()
{
    const char *wochentag[7];
    wochentag[0] = "Montag";
    wochentag[1] = "Dienstag";
    wochentag[2] = "Mittwoch";
    wochentag[3] = "Donnerstag";
    wochentag[4] = "Freitag";
    wochentag[5] = "Samstag";
    wochentag[6] = "Sonntag";

    int t=4;
    for(int i=1582; i<=2400; i++)
    {
        for(int j=1; j<=12; j++)
        {
            int a = get_days_for_month(j,i);
            for(int k=1; k<=a; k++)
            {
                int def = day_of_the_week(k, j, i);
                if(def != t)
                {
                    printf("\n\nFATAL\n\n");
                    //system("pause");
                    return 1;
                }
                printf("Tag:       %02i.%02i.%i\nWochentag: %s\n%i\n\n", k, j, i, wochentag[def], t);
                t++;t %= 7;
            }
        }
        //system("pause>nul");
    }
    return 0;
}

int main()
{
    const char *a[7];
    a[3] = "Donnerstag";
    a[4] = "Freitag";
    a[5] = "Samstag";
    a[6] = "Sonntag";
    a[0] = "Montag";
    a[1] = "Dienstag";
    a[2] = "Mittwoch";

    int day = 26, month = 2, year = 1997;

    printf("Tag:       %i.%i.%i\nWochentag: %s\n", day, month, year, a[day_of_the_week(day,month,year)]);
    //system("pause>nul");
    return 0;
}

