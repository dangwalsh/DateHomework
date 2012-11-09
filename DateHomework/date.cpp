//
//  date.cpp
//  DateClass
//
//  Created by Daniel Walsh on 11/6/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

const int date_length[] = {
    0,   //dummy element so that January will have subscript 1
	31,   //January
	28,   //February
	31,   //March
	30,   //April
	31,   //May
	30,   //June
	31,   //July
	31,   //August
	30,   //September
	31,   //October
	30,   //November
	31    //December
};

date::date(int initial_month, int initial_day, int initial_year)
{
	if (initial_month < 1 || initial_month > 12) {
		cerr << "bad month " << initial_month << "/" << initial_day
        << "/" << initial_year << "\n";
		exit(EXIT_FAILURE);
	}
    
	if (initial_day < 1 || initial_day > date_length[initial_month]) {
		cerr << "bad day " << initial_month << "/" << initial_day
        << "/" << initial_year << "\n";
		exit(EXIT_FAILURE);
	}
    
	year = initial_year;
	month = initial_month;
	day = initial_day;
}

void date::next(int count)
{
	//Call the other next count times.
	while (--count >= 0) {
		next();
	}
    day = julian();
    month = 1;
}

void date::next()
{
	//Move to the next date.
	if (++day > date_length[month]) {
		day = 1;
		if (++month > 12) {
			month = 1;
			++year;
		}
	}
}

int const date::julian()
{
    int d = 0;
    for (int i = 1; i < month;  ++i) {
        d += date_length[i];
    }
    return d + day;
}


