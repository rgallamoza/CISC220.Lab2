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
#include <array>
using namespace std;

string reverseStr(string s, int count);
int sumDigits(int x, int sum);
int minVal(int x[], int size);
bool isElfish(string x, int len);
bool isPerfect(int x, int sum, int divisor);
void printX(int x, int row);
void printLine(int x, int row);

int main(){
	cout << "Problem 1" << endl;
	cout << "Test 1:" << endl << reverseStr("amri",3) << endl; // Expected: irma returned
	cout << "Test 2:" << endl << reverseStr("CompSci",6) << endl; // Expected: icSpmoC returned
	cout << "Test 3:" << endl << reverseStr("hannah",5) << endl; // Expected: hannah returned
	cout << "*************************" << endl;

	cout << "Problem 2" << endl;
	cout << "Test 1:" << endl << sumDigits(1234,0) << endl; // Expected: 10 returned
	cout << "Test 2:" << endl << sumDigits(12345,0) << endl; // Expected: 15 returned
	cout << "Test 3:" << endl << sumDigits(1000001,0) << endl; // Expected: 2 returned
	cout << "*************************" << endl;

	cout << "Problem 3" << endl;
	int a1[3] = {3,2,1};
	int a2[6] = {3,1,1,2,3,4};
	int a3[5] = {1,2,3,4,5};
	cout << "Test 1:" << endl << minVal(a1,3) << endl; // Expected: 1 returned
	cout << "Test 2:" << endl << minVal(a2,6) << endl; // Expected: 1 returned
	cout << "Test 3:" << endl << minVal(a3,5) << endl; // Expected: 1 returned
	cout << "*************************" << endl;

	cout << "Problem 4" << endl;
	cout << "Test 1:" << endl << isElfish("abcd",4) << endl; // Expected: 0(false) returned
	cout << "Test 2:" << endl << isElfish("waffles",4) << endl; // Expected: 1(true) returned
	cout << "Test 3:" << endl << isElfish("unfriendly",4) << endl; // Expected: 1(true) returned
	cout << "*************************" << endl;

	cout << "Problem 5" << endl;
	cout << "Test 1:" << endl << isPerfect(7,0,1) << endl; // Expected: 0(false) returned
	cout << "Test 2:" << endl << isPerfect(5,0,1) << endl; // Expected: 0(false) returned
	cout << "Test 3:" << endl << isPerfect(8128,0,1) << endl; // Expected: 1(true) returned
	cout << "*************************" << endl;

	cout << "Problem 6" << endl;
	cout << "Test 1:" << endl;
	printX(5,1);
	cout << "Test 2:" << endl;
	printX(4,1);
	cout << "Test 3:" << endl;
	printX(1,1);
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

int sumDigits(int x, int sum){
	if(x==0){
		return sum;
	}
	else{
		return sumDigits(x/10,sum+(x%10));
	}
}


int minVal(int x[], int size){
	 if (size == 0){
		 return x[0];
	 }
	 if(x[size-1] < minVal(x , size-1)){
		 return x[size-1];
	 }
	 else{
		 return (minVal(x , size-1));
	 }
}

bool isElfish(string x, int len){
	if(len==1){
		return false;
	}
	else if(len==1){
		switch(x[0]){
		case 'e':
			return true;
		case 'l':
			return true;
		case 'f':
			return true;
		case 'i':
			return true;
		case 's':
			return true;
		case 'h':
			return true;
		default:
			return false;
		}
	}
	else{
		switch(x[len-1]){
		case 'e':
			return true;
		case 'l':
			return true;
		case 'f':
			return true;
		case 'i':
			return true;
		case 's':
			return true;
		case 'h':
			return true;
		default:
			return isElfish(x,len-1);
		}
	}
}

bool isPerfect(int x, int sum, int divisor){
	if(x<6){
		return false;
	}
	else if(divisor==x){
		if(x==sum){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(x%divisor==0){
			sum+=divisor;
		}
		return isPerfect(x,sum,divisor+1);
	}
}

void printX(int x, int row){
	if(row==(2*x)-1){
		printLine(x,row);
	}
	else{
		printLine(x,row);
		printX(x,row+1);
	}
}

void printLine(int x, int row){
	int spaces, spacesBtw;

	if(row<=x){
		spaces = row-1;
		if(row!=x){
			spacesBtw = (2*x)-(2*row)-1;
		}
	}
	else{
		spaces = (2*x)-row-1;
		spacesBtw = (2*row)-(2*x)-1;
	}

	if(row==x){
		for(int i=0;i<spaces;i++){
			cout << " ";
		}
		cout << "*" << endl;
	}
	else{
		for(int i=0;i<spaces;i++){
			cout << " ";
		}
		cout << "*";
		for(int i=0;i<spacesBtw;i++){
			cout << " ";
		}
		cout << "*" << endl;
	}
}










