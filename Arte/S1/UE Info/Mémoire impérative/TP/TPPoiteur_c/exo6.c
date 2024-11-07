#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct date {
    int day;
    int month;
    int year;
}; typedef struct date Date;

void printDate(Date d) {
    printf("Date : %d/%d/%d\n", d.day, d.month, d.year);
}

void incrDate(Date * p) {
    if (p->month == 1 || p->month == 3 || p->month == 5 || p->month == 7 || p->month == 8 || p->month == 10 || p->month == 12) {
        if (p->month == 12 && p->day == 31) {
            p->year++;
            p->month = 1;
            p->day = 1;
        }
        else if (p->day == 31) {
            p->month++;
            p->day = 1;
        }
        else {
            p->day++;
        }
    }
    else if (p->month == 2) {
        if (p->day == 28) {
            p->month++;
            p->day = 1;
        }
    }
    else {
        if (p->day == 30) {
            p->month++;
            p->day = 1;
        }
    }
}

int main(void) {

    Date td = {31,12,1970};

    Date * ptr = &td;

    incrDate(ptr);

    printDate(td);

    return 0;
}
