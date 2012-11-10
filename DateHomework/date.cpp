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
    const div_t d = div(count, 365);
    
    if (d.rem < 0) {
        year += d.quot - 1;
        count = d.rem + 365;
    } else {
        year += d.quot;
        count = d.rem;
    }
    
    while (count >= date_length[month]) {
        count -= date_length[month];
        ++month;
    }
    day += count;
    //day = julian();
}

int const date::julian()
{
    int d = 0;
    for (int i = 1; i < month;  ++i) {
        d += date_length[i];
    }
    return d + day;
}


