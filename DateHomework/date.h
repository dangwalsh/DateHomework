//
//  date.h
//  DateClass
//
//  Created by Daniel Walsh on 11/6/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#ifndef DATEH
#define DATEH
#include <iostream>
using namespace std;

class date {
	int year;
	int month;               //1 to 12 inclusive
	int day;                 //1 to date_length[month] inclusive
public:
	date(int initial_month, int initial_day, int initial_year);
	void next(int count);    //Go count days forward.
	void next();             //Go one day forward.
	void print() const {cout << month << "/" << day << "/" << year;}
    int const julian();
};
#endif
