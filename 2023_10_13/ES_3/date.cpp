#include <iostream>
#include "date.h"

int date_difference(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int diff = 0;
    if (year1 >= year2)
    {
        if (year1 == year2)
        {
            if (month1 >= month2)
            {
                if (month1 == month2)
                {
                    if (day1 > day2)
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }
            }
        }
        else
        {
            return -1;
        }
    }

    for (int i = year1; i < year2 - 1; i++){
        if (i % 4 == 0){
            diff += 366;
        }
        else{
            diff += 365;
        }
    }
    for (int i = month1; i < month2; i++){
        if(i == 4 || i == 6 || i == 9 || i == 11){
            diff += 30;
        }
        else if(i == 2){
            diff += 28;
        }
        else{
            diff += 31;
        }
    }
    for (int i = day1; i < day2; i++){
        diff++;
    }
    return diff;
}