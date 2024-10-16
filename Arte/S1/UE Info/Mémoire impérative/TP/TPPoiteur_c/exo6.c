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

int main(void) {

    Date td = {01,01,1970};

    printDate(td);

    return 0;
}
