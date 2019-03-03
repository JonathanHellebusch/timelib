#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date_struct
{
    int year;
    int month;
    int day;
};

int is_leapyear(struct date_struct tempDate);
void input_date(struct date_struct *tempDate);
int get_days_for_month(struct date_struct tempDate);
int exists_date(struct date_struct tempDate);
int day_of_the_year(struct date_struct tempDate);
int day_of_the_week(struct date_struct tempDate);

#endif // TIME_H_INCLUDED
