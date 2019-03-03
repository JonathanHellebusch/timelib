# timelib

Repository for a time library written in C.

You can download the library [here](https://github.com/JonathanHellebusch/timelib/archive/master.zip) and add it to your project.

Then add this line in your code to include this library.

> #include "time.h"


# Implemented struct

 - date_struct
   `int year`
   `int month`
   `int day`
    
# Implemented functions 

A list of all funktions in this library

|Functionname              |Inputparameter				 |Returntype				   |
|----------------|-------------------------------|-----------------------------|
|is_leapyear	 	|`struct date_struct`            |`int`            |
|input_date		 	|`struct date_struct`            |`-`            |
|get_days_for_month |`struct date_struct`            |`int`            |
|exists_date		|`struct date_struct`            |`int`            |
|day_of_the_year	|`struct date_struct`            |`int`            |
|day_of_the_week	|`struct date_struct`            |`int`            |
