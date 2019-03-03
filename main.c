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
#include "lib/time.h"


/******
*
* Bezeichner: main
*
* Beschreibung: aufruf von Testfunktionen
*
*
*****/
int main()
{
    struct date_struct new_date;
    printf("Bitte Datum eingeben: ");
    input_date(&new_date);
    printf("\n\nTag: %i\nMonat: %i\nJahr: %i\n", new_date.day, new_date.month, new_date.year);

    return 0;
}

