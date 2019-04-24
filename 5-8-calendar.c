#include <stdio.h>

//static char daytab[2][13] = {
//    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
//    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
//};


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};



int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

char *month_name(int n);

int main()
{
    int d;
    int month, day;


    d = day_of_year(2019, 2, 1);
    printf("day: %d\n", d);
    month_day(2019, 32, &month, &day);
    printf("%d-%d\n", month, day);
    printf("%s\n", month_name(9));
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
    for (i=1; i < month; i++)
        day += *(*(daytab +leap) + i);
    return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
    for (i = 1; yearday > (*(daytab +leap))[i]; i++)
        yearday -= *(*(daytab +leap) + i);

    *pmonth= i;
    *pday= yearday;
}

char *month_name(int n)
{
    static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
    };

    return (n < 1 || n > 12)  ? name[0] : name[n];
}