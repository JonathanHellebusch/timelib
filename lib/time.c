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

#define ARRAY_LEN 11

/******
*
* Bezeichner: is_leapyear
*
* Übergabeparameter: struct date_struct temp_date
*
* Rückgabewert: int
*               0, wenn das Jahr kein Schalltjahr ist
*               1, wenn das Jahr ein Schalltjahr ist
*              -1, wenn das Jahr kleiner als 1582 ist oder größer als 2400
*
* Beschreibung: Die Funktion ermittelt für ein übergebenes Jahr, ob es sich um ein Schaltjahr handelt
*
*****/

int is_leapyear(struct date_struct temp_date)
{
    //Variablen für die Rechnungen mit Modulo
    int divided_by_four = 0, divided_by_hundred = 0, divided_by_fourhundred = 0, result = 0;

    //Rechnung der Modulo-Werte
    divided_by_four = temp_date.year % 4;
    divided_by_hundred = temp_date.year % 100;
    divided_by_fourhundred = temp_date.year % 400;

    //Ermittlung ob das Jahr ein schalltjahr ist
    if (divided_by_four == 0)
    {
        if (divided_by_hundred == 0)
        {
            if (divided_by_fourhundred == 0)
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
    if (temp_date.year < 1582 || temp_date.year > 2400)
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
* Übergabeparameter: struct date_struct *temp_date
*
* Beschreibung:Einlesen der einzelnen Zahlen für das Datum
*
*****/

void input_date(struct date_struct *temp_date)
{
    int bool_valid = 0;
    char input[ARRAY_LEN];
    int temp_date_array[] = {0, 0, 0};
    do
    {
        fgets(input,ARRAY_LEN,stdin);

        for(int i=0, j=0, k=0; i<ARRAY_LEN-1; i++)
        {
            if(input[i] == '.' || input[i] == '/')
            {
                input[i] = '\0';
                temp_date_array[j] = atoi(input[k]);
                k = i + 1;
                j++;
                printf("%s\n", input[k]);
                printf("%i\t%i\t%i\n", i,j,k);
            }
        }
        struct date_struct temp_day_month_year;
        temp_day_month_year.day = temp_date_array[0];
        temp_day_month_year.month = temp_date_array[1];
        temp_day_month_year.year = temp_date_array[2];

        if(exists_date(temp_day_month_year))
        {
            bool_valid = 1;
            temp_date->day = temp_date_array[0];
            temp_date->month = temp_date_array[1];
            temp_date->year = temp_date_array[2];
        }
    }while(!bool_valid);

    return;
}

/******
*
* Bezeichner: get_days_for_month
*
* Übergabeparameter: struct date_struct temp_date
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

int get_days_for_month(struct date_struct temp_date)
{
    const int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (temp_date.year < 1582 || temp_date.year > 2400 || temp_date.month < 1 || temp_date.month > 12)
    {
        return -1;
    }
    else
    {
        int days = month_days[temp_date.month-1];
        if(temp_date.month == 2)
        {
            int result = is_leapyear(temp_date);
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
* Übergabeparameter: struct date_struct temp_date
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

int exists_date(struct date_struct temp_date)
{
    int result = 0;
    if (temp_date.year >= 1582 && temp_date.year <= 2400)
    {
        if (temp_date.month >= 1 && temp_date.month <= 12)
        {
            if(temp_date.day >= 1 && temp_date.day <= get_days_for_month(temp_date))
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
* Übergabeparameter: struct date_struct temp_date
*
* Rückgabewert: int
*          1 - 366, wenn das Datum existiert
*               -1, wenn das Datum nicht existiert
*
* Beschreibung: Die Funktion gibt die Anzahl der Tage die in dem Jahr schon vorrüber sind an
*
*****/

int day_of_the_year(struct date_struct temp_date)
{
    if(exists_date(temp_date))
    {
        int total_days = temp_date.day;
        for(int i=1; i<temp_date.month; i++)
        {
            struct date_struct temp_day_month_year;
            temp_day_month_year.day = temp_date.day;
            temp_day_month_year.month = i;
            temp_day_month_year.year = temp_date.year;
            total_days += get_days_for_month(temp_day_month_year);
        }
        return total_days;
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
* Übergabeparameter: struct date_struct temp_date
*
* Rückgabewert: int
*            0 - 6, für den Wochentag Montag = 0 und so weiter ..
*               -1, wenn das Datum nicht existiert
*
* Beschreibung: Die Funktion gibt den Wochentag an mit einer zahl von 0-6
*
*****/

int day_of_the_week(struct date_struct temp_date)
{
    int day_difference = 0;
    if(exists_date(temp_date))
    {
        if(temp_date.year > 1582)
        {
            for(int i=1582; i<temp_date.year; i++)
            {
                struct date_struct temp_day_month_year;
                temp_day_month_year.day = temp_date.day;
                temp_day_month_year.month = temp_date.month;
                temp_day_month_year.year = i;
                day_difference += (365 + is_leapyear(temp_day_month_year));
            }
        }
        if(temp_date.month > 1)
        {
            for(int i=1; i<temp_date.month; i++)
            {
                struct date_struct temp_day_month_year;
                temp_day_month_year.day = temp_date.day;
                temp_day_month_year.month = i;
                temp_day_month_year.year = temp_date.year;
                day_difference += get_days_for_month(temp_day_month_year);
            }
        }
        day_difference += temp_date.day;
        return ((day_difference + 3) % 7);
    }
    else
    {
        return -1;
    }
}
