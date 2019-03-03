/******
*
*   time.c
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
* Bezeichner: is_leapyear
*
* Übergabeparameter: struct date_struct tempDate
*
* Rückgabewert: int
*               0, wenn das Jahr kein Schalltjahr ist
*               1, wenn das Jahr ein Schalltjahr ist
*              -1, wenn das Jahr kleiner als 1582 ist oder größer als 2400
*
* Beschreibung: Die Funktion ermittelt für ein übergebenes Jahr, ob es sich um ein Schaltjahr handelt
*
*****/

int is_leapyear(struct date_struct tempDate)
{
    //Variablen für die Rechnungen mit Modulo
    int Dvier = 0, Dhundert = 0, Dvierhundert = 0, result = 0;

    //Rechnung der Modulo-Werte
    Dvier = tempDate.year % 4;
    Dhundert = tempDate.year % 100;
    Dvierhundert = tempDate.year % 400;

    //Ermittlung ob das Jahr ein schalltjahr ist
    if (Dvier == 0)
    {
        if (Dhundert == 0)
        {
            if (Dvierhundert == 0)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            result = 1;
        }
    }
    else
    {
        result = 0;
    }

    // Einführungsjahr des Schaltjahres
    if (tempDate.year < 1582 || tempDate.year > 2400)
    {
        result = -1;
    }

    //Rückgabe des Ergebnisses
    return result;
}

/******
*
* Bezeichner: input_date
*
* Übergabeparameter: struct date_struct *tempDate
*
* Beschreibung:Einlesen der einzelnen Zahlen für das Datum
*
*****/
void input_date(struct date_struct *tempDate)
{
    const int ARRAY_LEN = 11;
    int bool_valid = 0;
    char a[ARRAY_LEN];
    int temp_date[] = {0, 0, 0};
    do
    {
        fgets(a,ARRAY_LEN,stdin);

        for(int i=0, j=0, k=0; i<ARRAY_LEN-1; i++)
        {
            if(a[i] == '.' || a[i] == '/')
            {
                a[i] = '\0';
                temp_date[j] = atoi(a[k]);
                k = i + 1;
                j++;
                printf("%s\n", a[k]);
                printf("%i\t%i\t%i\n", i,j,k);
            }
        }
        struct date_struct tdmy;
        tdmy.day = temp_date[0];
        tdmy.month = temp_date[1];
        tdmy.year = temp_date[2];
        if(exists_date(tdmy))
        {
            bool_valid = 1;
            *tempDate.day = temp_date[0];
            *tempDate.month = temp_date[1];
            *tempDate.year = temp_date[2];
        }
    }while(!bool_valid);

    return;
}

/******
*
* Bezeichner: get_days_for_month
*
* Übergabeparameter: struct date_struct tempDate
*
* Rückgabewert: int
*         28 - 31, wenn kein Fehler aufkommt :)
*              -1, wenn das Jahr kleiner als 1582 ist oder größer als 2400
*                  oder wenn der Monat nicht eine zahl von 1 - 12 ist
*                  oder die Funktion is_leapyear eine -1 wiedergibt
*
* Beschreibung: Die Funktion gibt die Anzahl der Tage des übergebenen Monaths zurück
*
*****/
int get_days_for_month(struct date_struct tempDate)
{
    const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (tempDate.year < 1582 || tempDate.year > 2400 || tempDate.month < 1 || tempDate.month > 12)
    {
        return -1;
    }
    else
    {
        int days = monthDays[tempDate.month-1];
        if(month == 2)
        {
            int result = is_leapyear(tempDate);
            if(result == -1)
            {
                return -1;
            }
            else
            {
                days += result;
            }
        }
        return days;
    }
}

/******
*
* Bezeichner: exists_date
*
* Übergabeparameter: struct date_struct tempDate
*
* Rückgabewert: int
*              1, wenn der Tag existiert
*              0, wenn das Jahr kleiner als 1582 ist oder größer als 2400
*                  oder wenn der Monat nicht eine zahl von 1 - 12 ist
*                  oder die Funktion get_days_for_month eine -1 wiedergibt
*
* Beschreibung: Die Funktion prüft ob ein bestimmtes Datum existiert
*
*****/
int exists_date(struct date_struct tempDate)
{
    int result = 0;
    if (tempDate.year >= 1582 && tempDate.year <= 2400)
    {
        if (tempDate.month >= 1 && tempDate.month <= 12)
        {
            if(tempDate.day >= 1 && tempDate.day <= get_days_for_month(tempDate))
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

/******
*
* Bezeichner: day_of_the_year
*
* Übergabeparameter: struct date_struct tempDate
*
* Rückgabewert: int
*          1 - 366, wenn das Datum existiert
*               -1, wenn das Datum nicht existiert
*
* Beschreibung: Die Funktion gibt die Anzahl der Tage die in dem Jahr schon vorrüber sind an
*
*****/
int day_of_the_year(struct date_struct tempDate)
{
    if(exists_date(tempDate))
    {
        int totalDays = day;
        for(int i=1; i<tempDate.month; i++)
        {
            struct date_struct tdmy;
            tdmy.day = tempDate.day;
            tdmy.month = i;
            tdmy.year = tempDate.year;
            totalDays += get_days_for_month(tdmy);
        }
        return totalDays;
    }
    else
    {
        return -1;
    }
}

/******
*
* Bezeichner: day_of_week
*
* Übergabeparameter: int day, int month, int year
*
* Rückgabewert: int
*            0 - 6, für den Wochentag Montag = 0 und so weiter ..
*               -1, wenn das Datum nicht existiert
*
* Beschreibung: Die Funktion gibt den Wochentag an mit einer zahl von 0-6
*
*****/
int day_of_the_week(struct date_struct tempDate)
{
    int dayDifference = 0;
    if(exists_date(tempDate))
    {
        if(tempDate.year > 1582)
        {
            for(int i=1582; i<tempDate.year; i++)
            {
                struct date_struct tdmy;
                tdmy.day = tempDate.day;
                tdmy.month = tempDate.month;
                tdmy.year = i;
                dayDifference += (365 + is_leapyear(tdmy));
            }
        }
        if(tempDate.month > 1)
        {
            for(int i=1; i<tempDate.month; i++)
            {
                struct date_struct tdmy;
                tdmy.day = tempDate.day;
                tdmy.month = i;
                tdmy.year = tempDate.year;
                dayDifference += get_days_for_month(tdmy);
            }
        }
        dayDifference += day;
        return ((dayDifference + 3) % 7);
    }
    else
    {
        return -1;
    }
}
