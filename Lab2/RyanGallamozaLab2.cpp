/*
 * RyanGallamozaLab2.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: Ryan
 */

/*
 * Ryan Gallamoza
 * TA: Eeshita Biswas
 * 9/12/2017
 * Lab 2
 * This file contains the functions for each problem in Lab 1
 */

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

string reverseStr(string s, int count);

int sumDigits(int x);

int main(){
	cout << "Problem 1" << endl;
	cout << "Test 1:" << endl << reverseStr("amri",3) << endl; // Expected: irma returned
	cout << "Test 2:" << endl << reverseStr("CompSci",6) << endl; // Expected: icSpmoC returned
	cout << "Test 3:" << endl << reverseStr("hannah",5) << endl; // Expected: hannah returned
	cout << "*************************" << endl;
	return 0;
}

string reverseStr(string s, int count){
	if(s.length()==0){
		return "";
	}
	else{
		if(count==0){
			return string(1,s[0]);
		}
		else{
			return(s[count] + reverseStr(s,count-1));
		}
	}
}

int sumDigits(int x, int count){
	if(x/10==0){
		return x;
	}
	else{

	}
}

