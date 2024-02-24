#include"header.h"


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(Date d) {
    if (d.yy < 1) {  // Check if the year is valid
        return false;
    }
    if (d.mm < 1 || d.mm > 12) { // Check if the month is valid
        return false;
    }
    // Check if the day is valid
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.mm == 2 && isLeapYear(d.yy)) { // Adjust for leap year
        daysInMonth[2] = 29;
    }
    if (d.dd < 1 || d.dd > daysInMonth[d.mm]) {
        return false;
    }
    return true;
}
int datecmp(Date d1,Date d2) {
    // Compare the dates and return the result
    // printf("%d  %d\n",isValidDate(d1),isValidDate(d1));
    if (isValidDate(d1) && isValidDate(d2)) {
        if (d1.dd == d2.dd && d1.mm == d2.mm && d1.yy ==d2.yy)
            return 0;
        else if (d1.yy > d2.yy || (d1.yy == d2.yy && (d1.mm > d2.mm || (d1.mm == d2.mm && d1.dd > d2.dd))))
            return 1;
        else
            return -1;
    }else{
        printf("The entered date is not valid\n");
        return 0;
    }
}