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
 * This file contains the functions for each problem in Lab 2
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <array>
using namespace std;

string reverseStr(string s, int count);
/* Returns the given string with its positions reversed
 * Parameters: s: Any given string to be reversed
 * 			   count: Length of the given string
 */

int sumDigits(int x, int sum);
/* Returns the sum of each digit from a given integer
 * Parameters: x: Any integer to be evaluated
 *             sum: Sum of the digits. Mustust be initialized to 0
 */

int minVal(int x[], int size);
/* Returns the smallest value from a given array of integers
 * Parameters: x[]: Any given array of integers to be evaluated
 * 			   size: Size of the given array
 */

bool isElfish(string x, int len, bool e, bool l, bool f);
/* Returns a boolean on whether the given string is elfish or not
 * Parameters: x: Any string to be evaluated
 * 			   len: Length of the given string
 * 			   e: Whether e is in the given string or not. Must initialize to false.
 * 			   l: Whether l is in the given string or not. Must initialize to false.
 * 			   f: Whether f is in the given string or not. Must initialize to false.
 */
bool isPerfect(int x, int sum, int divisor);
/* Returns a boolean on whether the given integer is a perfect number or not
 * Parameters: x: Any integer to be evaluated
 * 			   sum: Sum of the digits. Must be initialized to 0
 * 			   divisor: Divisor to check all numbers that cleanly divide x. Must be initialized to 1
 */

void printX(int x, int row);
/* Prints an X of asterisks, based on the integer given
 * Parameters: x: How long each 'side' of the X will be
 * 			   row: #row to be printed. Must be initialized to 1
 */

void printLine(int x, int row);
/* Helper function for printX. Prints a line based on the given integer x and row number
 */

bool order1(int *x, int *y);
/* Returns a boolean on whether the given integer x is less than or equal to y. If this is false,
 * the values of x and y are switched.
 * Parameters: *x: Pointer of integer x to be evaluated
 * 			   *y: Pointer of integer y to be evaluated
 */

bool order2(int &x, int &y);
/* Returns a boolean on whether the given integer x is less than or equal to y. If this is false,
 * the values of x and y are switched.
 * Parameters: &x: Reference of integer x to be evaluated
 * 			   &y: Reference of integer y to be evaluated
 */

void printInfoPointer(int *x);
/* Prints out the value at the address, the address in the parameter, and the address
 * of the parameter.
 * Parameters: *x: Pointer of integer x to be evaluated
 */

void printInfoReference(int &y);
/* Prints out the address and the value of the parameter
 * Parameters: &y: Reference of integer y to be evaluated
 */

void fillArray(int x[20], int size);
/* Fills an array of 20 integers with random values between 0 and 100, excluding 100
 * Parameters: x[20]: Array of integers with 20 spaces held in memory
 * 			   size: Size of the given array. Should be initialized to 20
 */

void printArray(int x[], int size);
/* Prints out each value in a given array of integers
 * Parameters: x[]: Array of integers to be evaluated
 * 			   size: Size of the given array
 */

void minValInfo(int x[], int size, int &val, int &index);
/* Modifies the third parameter to the smallest value of the given array of integers, and
 * modifies the fourth parameter to the index of that value
 * Paramters: x[]: Array of integers to be evaluated
 * 			  size: Size of the given array
 * 			  &val: Reference of int to be changed to smallest value in given array
 * 			  &index: Reference of int to be changed to index of smallest value in given array
 */

void printAddresses(int x[], int size);
/* Prints the address of each value in a given array of integers
 * Parameters: x[]: Any array of integers to be evaluated
 * 			   size: Size of the given array
 */

void printAddressesDoubles(double x[], int size);
/* Prints the address of each value in a given array of doubles
 * Parameters: x[]: Any array of doubles to be evaluated
 * 			   size: Size of the given array
 */

int compareArraySums(int x[], int y[], int sizex, int sizey, int &sumx, int &sumy);
/* Returns an integer value dependent on the sums of each value in two given arrays of integers:
 * 1 if the sum of the integers in the first array is greater than the sum of the integers in the
 * second array, 0 if the sums are equal, and -1 if the second array’s sum is greater than the first.
 * Modifies the fifth and sixth parameters to the sum of the first array and second array respectively.
 * Parameters: x[]: First array of integers to be analyzed
 * 			   y[]: Second array of integers to be analyzed
 * 			   sizex: Size of first array of integers
 * 			   sizey: Size of second array of integers
 * 			   &sumx: Reference of int to be changed to the sum of integers in the first array
 * 			   &sumy: Reference of int to be changed to the sum of integers in the second array
 */

int main(){
	cout << "Problem 1.1" << endl;
	cout << "Test 1:" << endl << reverseStr("amri",3) << endl; // Expected: irma returned
	cout << "Test 2:" << endl << reverseStr("CompSci",6) << endl; // Expected: icSpmoC returned
	cout << "Test 3:" << endl << reverseStr("hannah",5) << endl; // Expected: hannah returned
	cout << "*************************" << endl;

	cout << "Problem 1.2" << endl;
	cout << "Test 1:" << endl << sumDigits(1234,0) << endl; // Expected: 10 returned
	cout << "Test 2:" << endl << sumDigits(12345,0) << endl; // Expected: 15 returned
	cout << "Test 3:" << endl << sumDigits(1000001,0) << endl; // Expected: 2 returned
	cout << "*************************" << endl;

	cout << "Problem 1.3" << endl;
	int a1[3] = {3,2,1};
	int a2[6] = {3,1,1,2,3,4};
	int a3[5] = {1,2,3,4,5};
	cout << "Test 1:" << endl << minVal(a1,3) << endl; // Expected: 1 returned
	cout << "Test 2:" << endl << minVal(a2,6) << endl; // Expected: 1 returned
	cout << "Test 3:" << endl << minVal(a3,5) << endl; // Expected: 1 returned
	cout << "*************************" << endl;

	cout << "Problem 1.4" << endl;
	cout << "Test 1:" << endl << isElfish("abcd",4,false,false,false) << endl; // Expected: 0(false) returned
	cout << "Test 2:" << endl << isElfish("waffles",7,false,false,false) << endl; // Expected: 1(true) returned
	cout << "Test 3:" << endl << isElfish("unfriendly",10,false,false,false) << endl; // Expected: 1(true) returned
	cout << "*************************" << endl;

	cout << "Problem 1.5" << endl;
	cout << "Test 1:" << endl << isPerfect(7,0,1) << endl; // Expected: 0(false) returned
	cout << "Test 2:" << endl << isPerfect(5,0,1) << endl; // Expected: 0(false) returned
	cout << "Test 3:" << endl << isPerfect(8128,0,1) << endl; // Expected: 1(true) returned
	cout << "*************************" << endl;

	cout << "Problem 1.6" << endl;
	cout << "Test 1:" << endl;
	printX(5,1); // Expected: 5x5 X of asterisks printed
	cout << "Test 2:" << endl;
	printX(4,1); // Expected: 4x4 X of asterisks Printed
	cout << "Test 3:" << endl;
	printX(1,1); // Expected: Single asterisk printed
	cout << "*************************" << endl;

	cout << "Problem 2.1" << endl;
	int x1 = (rand() % 100 + 1)/2;
	int y1 = (rand() % 100 + 1)/2;
	cout << "Test 1:" << endl;
	cout << "x1_i: " << x1 << endl << "y1_i: " << y1 << endl;
	cout << order1(&x1,&y1) << endl;
	cout << "x1_f: " << x1 << endl << "y1_f: " << y1 << endl; // Expected: smaller value in x1
	int x2 = (rand() % 100 + 1)/2;
	int y2 = (rand() % 100 + 1)/2;
	cout << "Test 2:" << endl;
	cout << "x2_i: " << x2 << endl << "y2_i: " << y2 << endl;
	cout << order1(&x1,&y1) << endl;
	cout << "x2_f: " << x2 << endl << "y2_f: " << y2 << endl; // Expected: smaller value in x2
	int x3 = (rand() % 100 + 1)/2;
	int y3 = (rand() % 100 + 1)/2;
	cout << "Test 3:" << endl;
	cout << "x3_i: " << x3 << endl << "y3_i: " << y3 << endl;
	cout << order1(&x1,&y1) << endl;
	cout << "x3_f: " << x3 << endl << "y3_f: " << y3 << endl; // Expected: smaller value in x3
	cout << "*************************" << endl;

	cout << "Problem 2.2" << endl;
	int x4 = (rand() % 100 + 1)/2;
	int y4 = (rand() % 100 + 1)/2;
	cout << "Test 1:" << endl;
	cout << "x4_i: " << x4 << endl << "y4_i: " << y4 << endl;
	cout << order2(x4,y4) << endl;
	cout << "x4_f: " << x4 << endl << "y4_f: " << y4 << endl; // Expected: smaller value in x4
	int x5 = (rand() % 100 + 1)/2;
	int y5 = (rand() % 100 + 1)/2;
	cout << "Test 2:" << endl;
	cout << "x5_i: " << x5 << endl << "y5_i: " << y5 << endl;
	cout << order2(x5,y5) << endl;
	cout << "x5_f: " << x5 << endl << "y5_f: " << y5 << endl; // Expected: smaller value in x5
	int x6 = (rand() % 100 + 1)/2;
	int y6 = (rand() % 100 + 1)/2;
	cout << "Test 3:" << endl;
	cout << "x6_i: " << x6 << endl << "y6_i: " << y6 << endl;
	cout << order2(x6,y6) << endl;
	cout << "x6_f: " << x6 << endl << "y6_f: " << y6 << endl; // Expected: smaller value in x6
	cout << "*************************" << endl;

	cout << "Problem 2.3" << endl;
	int x = 42;
	cout << "Address of x in main: " << &x << endl;
	printInfoPointer(&x);
	cout << "*************************" << endl;

	cout << "Problem 2.4" << endl;
	int y = 9000;
	cout << "Value of y: " << y << endl;
	cout << "Address of y: " << &y << endl;
	printInfoReference(y);
	cout << "*************************" << endl;

	cout << "Problem 2.5" << endl;
	int array1[20];
	fillArray(array1,20);
	cout << "Check if array values filled:" << endl;
	for(int i=0;i<20;i++){
		if(i==19){
			cout << array1[i] << endl;
		}
		else{
			cout << array1[i] << ",";
		}
	} // Expected: all array values filled with some integer between 0 and 100
	cout << "*************************" << endl;

	cout << "Problem 2.6" << endl;
	printArray(array1,20); // Expected: all values in array1 printed
	int array2[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	printArray(array2,10); // Expected: all values in array2 printed
	int array3[5] = {1,2,3,4,5};
	printArray(array3,5); // Expected: all values in array3 printed
	cout << "*************************" << endl;

	cout << "Problem 2.7" << endl;
	int val1 = -1,val2 = -1,val3 = -1,index1 = -1,index2 = -1,index3 = -1;
	int array4[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	cout << "Test 1:" << endl;
	cout << "val1_i: " << val1 << endl << "index1_i: " << index1 << endl;
	minValInfo(array4,20,val1,index1);
	cout << "val1_f: " << val1 << endl << "index1_f: " << index1 << endl; // Expected: val1 now 1, index1 now 19
	cout << "Test 2:" << endl;
	cout << "val2_i: " << val2 << endl << "index2_i: " << index2 << endl;
	minValInfo(array2,10,val2,index2);
	cout << "val2_f: " << val2 << endl << "index2_f: " << index2 << endl; // Expected: val2 now 2, index2 now 0
	cout << "Test 3:" << endl;
	cout << "val3_i: " << val3 << endl << "index3_i: " << index3 << endl;
	minValInfo(array3,5,val3,index3);
	cout << "val3_f: " << val3 << endl << "index3_f: " << index3 << endl; // Expected: val3 now 1, index3 now 0
	cout << "*************************" << endl;

	cout << "Problem 2.8" << endl;
	cout << "Test 1:" << endl;
	printAddresses(array2,10); // Expected: All addresses printed.. increments of 4 (base 16)
	cout << "Test 2:" << endl;
	printAddresses(array3,5); // Expected: All addresses printed.. increments of 4 (base 16)
	cout << "Test 3:" << endl;
	printAddresses(array4,20); // Expected: All addresses printed.. increments of 4 (base 16)
	cout << "*************************" << endl;

	cout << "Problem 2.9" << endl;
	cout << "Test 1:" << endl;
	double array5[5] = {0.2,0.9,1.2,1.8,2.7};
	printAddressesDoubles(array5,5); // Expected: All addresses printed.. increments of 8 (base 16)
	cout << "Test 2:" << endl;
	double array6[5] = {3.6,4.8,5.2,6.9,7.5};
	printAddressesDoubles(array6,5); // Expected: All addresses printed.. increments of 8 (base 16)
	cout << "Test 3:" << endl;
	double array7[5] = {8.4,9.9,10.3,11.7,100000.2};
	printAddressesDoubles(array7,5); // Expected: All addresses printed.. increments of 8 (base 16)
	cout << "*************************" << endl;


	cout << "Problem 2.10" << endl;
	int sum1 = 0, sum2 = 0;
	int arr1[5] = {1,2,3,4,5}, arr2[5] = {5,4,3,2,1}, arr3[5] = {6,7,8,9,10};
	cout << "Test 1:" << endl;
	cout << "sum1_i: " << sum1 << endl << "sum2_i: " << sum2 << endl;
	cout << compareArraySums(arr1,arr2,5,5,sum1,sum2) << endl; //Expected: 0 returned
	cout << "sum1_f: " << sum1 << endl << "sum2_f: " << sum2 << endl;
	sum1 = 0, sum2 = 0;
	cout << "Test 2:" << endl;
	cout << "sum1_i: " << sum1 << endl << "sum2_i: " << sum2 << endl;
	cout << compareArraySums(arr3,arr1,5,5,sum1,sum2) << endl; //Expected: 1 returned
	cout << "sum1_f: " << sum1 << endl << "sum2_f: " << sum2 << endl;
	sum1 = 0, sum2 = 0;
	cout << "Test 3:" << endl;
	cout << "sum1_i: " << sum1 << endl << "sum2_i: " << sum2 << endl;
	cout << compareArraySums(arr1,arr3,5,5,sum1,sum2) << endl; //Expected: -1 returned
	cout << "sum1_f: " << sum1 << endl << "sum2_f: " << sum2 << endl;
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

bool isElfish(string x, int len, bool e, bool l, bool f){
	if(len==0){
		if(e && l && f){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		switch(x[len-1]){
		case 'e':
			return isElfish(x,len-1,true,l,f);
		case 'l':
			return isElfish(x,len-1,e,true,f);
		case 'f':
			return isElfish(x,len-1,e,l,true);
		default:
			return isElfish(x,len-1,e,l,f);
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

bool order1(int *x, int *y){
	if(*x<=*y){
		return true;
	}
	else{
		int tempNum = *x;
		*x = *y;
		*y = tempNum;
		return false;
	}
}

bool order2(int &x, int &y){
	if(x<=y){
		return true;
	}
	else{
		int tempNum = x;
		x = y;
		y = tempNum;
		return false;
	}
}

void printInfoPointer(int *x){
	cout << "Value at x's address: " << *x << endl;
	cout << "Address in the parameter: " << x << endl;
	cout << "Address of the parameter: " << &x << endl;
}

void printInfoReference(int &y){
	cout << "Address of parameter: " << &y << endl;
	cout << "Value of parameter: " << y << endl;
}

void fillArray(int x[20], int size){
	for(int i=0;i<size;i++){
		x[i] = rand() % 100;
	}
}

void printArray(int x[], int size){
	for(int i=0;i<size;i++){
		if(i==size-1){
			cout << x[i] << endl;
		}
		else{
			cout << x[i] << ",";
		}
	}
}

void minValInfo(int x[], int size, int &val, int &index){
	int min = x[0];

	for(int i=0;i<size;i++){
		if(x[i]<min){
			min = x[i];
		}
	}

	val = min;
	for(int i=0;i<size;i++){
		if(x[i]==min){
			index = i;
		}
	}
}

void printAddresses(int x[], int size){
	for(int i=0;i<size;i++){
		if(i==size-1){
			cout << &x[i] << endl;
		}
		else{
			cout << &x[i] << ", ";
		}
	}
}

void printAddressesDoubles(double x[], int size){
	for(int i=0;i<size;i++){
		if(i==size-1){
			cout << &x[i] << endl;
		}
		else{
			cout << &x[i] << ", ";
		}
	}
}

int compareArraySums(int x[], int y[], int sizex, int sizey, int &sumx, int &sumy){
	for(int i=0;i<sizex;i++){
		sumx += x[i];
	}

	for(int i=0;i<sizey;i++){
		sumy += y[i];
	}

	if(sumx>sumy){
		return 1;
	}
	else if(sumx==sumy){
		return 0;
	}
	else{
		return -1;
	}
}
