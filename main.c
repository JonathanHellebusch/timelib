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

/******
*
* Bezeichner: isLeapYear
*
* Übergabeparameter: int year
*
* Rückgabewert: int
*               0, wenn das Jahr kein Schalltjahr ist
*               1, wenn das Jahr ein Schalltjahr ist
*              -1, wenn das Jahr kleiner als 1582 ist
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

int day_of_the_year(int day, int month, int year)
{
    if(exists_date(day,month,year) == 1)
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

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(1, 1, 2018));
    return 0;
}
