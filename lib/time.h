/******
*
*   time.h
*
*   Name: Jonathan Hellebusch
*   Datum: 18.12.2018
*
*   Beschreibung: Diese Bibliothek hat funktionen zur Datums be- und verarbeitung
*
*****/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date_struct
{
    int year;
    int month;
    int day;
};

int is_leapyear(struct date_struct temp_date);
void input_date(struct date_struct *temp_date);
int get_days_for_month(struct date_struct temp_date);
int exists_date(struct date_struct temp_date);
int day_of_the_year(struct date_struct temp_date);
int day_of_the_week(struct date_struct temp_date);

#endif // TIME_H_INCLUDED
