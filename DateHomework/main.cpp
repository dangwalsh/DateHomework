//
//  main.cpp
//  DateHomework
//
//  Created by Daniel Walsh on 11/9/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

int main()
{
	date d(1, 1, 2012);
    
	cout << "How many days forward from ";
	d.print();
	cout << " do you want to go? ";
    
	int count;   //uninitialized variable
	cin >> count;
    
	d.next(count);
	cout << "The new date is ";
	d.print();
	cout << ".\n";
    
	return EXIT_SUCCESS;
}

