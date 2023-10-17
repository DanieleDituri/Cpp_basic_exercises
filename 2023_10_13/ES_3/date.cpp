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
    int i = year1;
    if (month1 >= month2)
    {
        i++;
    }
    for (i; i < year2; ++i)
    {
        if (i % 4 == 0)
        {
            diff += 366;
        }
        else
        {
            diff += 365;
        }
    }
    int j = month2 - month1;
    i = month1;
    if(day1 >= day2){
        i++;
    }
    if (j < 0)
    {
        j += 11;
    }
    while (j != 0)
    {
        if (i > 12)
        {
            i -= 12;
            year1++;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            diff += 30;
            i++;
        }
        else if (i == 2)
        {
            if (year1 % 4 == 0)
            {
                diff += 29;
                i++;
            }
            else
            {
                diff += 28;
                i++;
            }
        }
        else{
            diff += 31;
            i++;
        }
        j--;
    }
    if(day1 < day2){
        diff += day2 - day1;
    }
    else{
        if(month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11){
            diff += 30 - day1;
        }
        else if (month1 == 2){
            if(year1 % 4 == 0){
                diff += 29 - day1;
            }
            else{
                diff += 28 - day1;
            }
        }
        else{
            diff += 31 - day1;
        }
        diff += day2;
    }

    return diff;
}