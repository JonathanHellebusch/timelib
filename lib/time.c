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

/******
*
* Bezeichner: is_leapyear
*
* Übergabeparameter: int year
*
* Rückgabewert: int
*               0, wenn das Jahr kein Schalltjahr ist
*               1, wenn das Jahr ein Schalltjahr ist
*              -1, wenn das Jahr kleiner als 1582 ist oder größer als 2400
*
* Beschreibung: Die Funktion ermittelt für ein übergebenes Jahr, ob es sich um ein Schaltjahr handelt
*
*****/

int is_leapyear(int year)
{
    //Variablen für die Rechnungen mit Modulo
    int Dvier = 0, Dhundert = 0, Dvierhundert = 0, result = 0;

    //Rechnung der Modulo-Werte
    Dvier = year % 4;
    Dhundert = year % 100;
    Dvierhundert = year % 400;

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
    if (year < 1582 || year > 2400)
    {
        result = -1;
    }

    //Rückgabe des Ergebnisses
    return result;
}

/******
*
* Bezeichner: get_days_for_month
*
* Übergabeparameter: int month, int year
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
int get_days_for_month(int month, int year)
{
    const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (year < 1582 || year > 2400 || month < 1 || month > 12)
    {
        return -1;
    }
    else
    {
        int days = monthDays[month-1];
        if(month == 2)
        {
            int result = is_leapyear(year);
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
* Übergabeparameter: int day, int month, int year
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
int exists_date(int day, int month, int year)
{
    int result = 0;
    if (year >= 1582 && year <= 2400)
    {
        if (month >= 1 && month <= 12)
        {
            if(day >= 1 && day <= get_days_for_month(month,year))
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
* Übergabeparameter: int day, int month, int year
*
* Rückgabewert: int
*          1 - 366, wenn das Datum existiert
*               -1, wenn das Datum nicht existiert
*
* Beschreibung: Die Funktion gibt die Anzahl der Tage die in dem Jahr schon vorrüber sind an
*
*****/
int day_of_the_year(int day, int month, int year)
{
    if(exists_date(day,month,year))
    {
        int totalDays = day;
        for(int i=1; i<month; i++)
        {
            totalDays += get_days_for_month(i,year);
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
int day_of_the_week(int day, int month, int year)
{
    int dayDifference = 0;
    if(exists_date(day,month,year))
    {
        if(year > 1582)
        {
            for(int i=1582; i<year; i++)
            {
                dayDifference += (365 + is_leapyear(i));
            }
        }
        if(month > 1)
        {
            for(int i=1; i<month; i++)
            {
                dayDifference += get_days_for_month(i, year);
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
