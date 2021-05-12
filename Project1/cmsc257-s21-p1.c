////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s20-p1.c
//  Description    : This is the main source code for for the first 
//					 project of CMSC257.  
//					 See the related assignment page for details.
//
//   Author        : Cheyenne Kent
//   Last Modified : March 12th, 2021
//

// Include Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Project Includes
#include "p1-support.h"
//#include "p1-support.c"
#define current int_array2[i]

// Functions

///////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 project #1
// 
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char *argv[]) {

	// Local variables
	int int_array1[10];
	unsigned int uint_array1[10], uint_array2[10], uint_array3[10];
	int i;
	//Add more local variables here as needed

	//Checking if there are less than 10 inputs 
	if (argc < 11)
	{   
		//Exit if there are less than 10 inputs
		printf("Exiting the program, missing input");
		return 0;	
	}


	// Step a - Read in the integer numbers input at 
	// the time of exeution and save them into int_array1
	for(i=1; i<11; i++){
        int_array1[i-1] = atoi(argv[i]);//converting input to an integer
    }

	// Step b - Reverse the order of array elements in int_array1 
	//           using swap function. 
    for(i=0; i<5; i++){
        swap_ints(&int_array1[i], &int_array1[9 - i]);//swapping the integers
    }

	// Step c - Convert numbers in int into positive values by taking their 
	//           absolute values and save them in uint_array1. 
	// Print all numbers in a single line using display_array function
    for(i=0; i<10; i++){
        uint_array1[i] = bitwise_abs(int_array1[i]);//finding the absolute value
    }
    display_array(uint_array1, 10);//printing the array

	// Step d - Convert these positive integers to numbers 
	//           in the range 0,…,64 by implementing the  mod operation
	//           save them into uint_array2. 
	// Print all numbers in a single line using display_array function
    for(i=0; i<10; i++){
        uint_array2[i] = bitwise_mod64(uint_array1[i]);//finding the module of the values
    }
    display_array(uint_array2, 10);//printing the array

	// Step e - for each integer in uint_array1 print: 
	//           number, number of set bits, even or odd
    for(i=0; i<10; i++){
        printf("[number: %10d, # of 1 bits: %5d,      ", uint_array1[i], count_set_bits(uint_array1[i]));//printing the number and the number of 1s in the bit
        if(odd_or_even(uint_array1[i])){
            printf(" odd]\n");//prints if the value is odd
        } else {
            printf("even]\n");//prints if the value is even
        }
    }

	// Step f - Reverse bits of each element of the uint_array2 and 
	// save them into uint_array3
    for(i=0; i<10; i++){
        uint_array3[i] = reverse_bitwise(uint_array2[i]);//reverses the bits in the number
    }

	// Step h - Print each element of int_array1, uint_array2 and uint_array3 
	// in a separate line along with 
	// binary representation of each of the numbers 
	//using binary_string function.
    char bin[35];
    for(i=0; i<10; i++){
        binary_string(bin, uint_array3[i]);
        printf("[number: %10d,   mod64:%10d,  reversed: %10u,     %5s]\n", uint_array1[i], uint_array2[i], uint_array3[i], bin);//prints the number, the module, the reversed value and the binary string
    }

	// Return successfully
	return(0);
}
