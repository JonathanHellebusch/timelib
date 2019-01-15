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

