#include "p1-support.h"
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
//
//  File          	: p1support.c
//  Description    	: This is a set of general-purpose utility functions 
//					we use for the 257 project #1.
//  Author					: Cheyenne Kent
//	Date						: March 12th, 2021
//	Notes						: Latest version


////////////////////////////////////////////////////////////////////////
// Function Definitions (in p1-support.h)
////////////////////////////////////////////////////////////////////////

//function definitions as described in the project manual

// Takes in a pointer to an array and an integer size
// loops through the array printing each value in it
void display_array(unsigned int* arr, int size){
	//Implement the function
	int i;
	printf("{");
    for(i = 0; i < size; i++){
        printf("%5u", arr[i]);
        if(i != size - 1){
            printf(",");
        }
    }
    printf("}\n");
}

// takes in an unsigned integer num
// loops through the bits of num and counts
// how many 1's are in the bitwise
// shifts the bits accordingly
// returns the counted value
unsigned int count_set_bits(unsigned int num){
    unsigned int count = 0;
    int i;
    for(i = 0; i < 32; i++){
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// takes in an unsigned int num
// loops through the bits and shifts
// the bits accordingly
// uses | and & to achieve reversing the bits
// returns the reversed value
unsigned int reverse_bitwise(unsigned int num){
    unsigned int reversed;
    int i;
    for(i = 0; i < 32; i++){
        reversed <<= 1;
        reversed |= num & 1;
        num >>= 1;
    }
    return reversed;
}

// takes in a pointer char that points to an array
// and takes in an unsigned int num
// loops through 32 values and uses the bit_get()
// function to get the values in each placement
void binary_string(char* bin, unsigned int num){
    bin[0] = '0';
    bin[1] = 'b';
    bin[34] = '\0';
    int i;
    for(i = 2; i < 34; i++){
        bin[i] = bit_get(num, 33 - i) + '0';
    }
}

// takes in an integer num
// uses the & operation to get module
int bitwise_mod64(int num){
    return (num & 63);
}

// takes in an integer num
// finds the left most value in the num
// uses the ^ operation to get the abs
// of the number, and then subtracts abs
// returns abs
int bitwise_abs(int num){
    int abs = (num >> 31);
    abs = (num ^ abs) - abs;
    return abs;
}

// takes in an integer num and integer get
// shifts the bitwise to the placement we need
// uses & operation to get the value and return it
int bit_get(int num, int get){
    int mask = 1;
    num >>= get;
    return (num & mask);
}

// determine if the value is even or odd
// by taking the most significant bit and
// using the & operation to return the value
int odd_or_even(unsigned int num){
    return num & 1;
}

// takes in two integer pointers pointing to two values
// uses ^ operation to swap the values
void swap_ints(int* num1, int* num2){
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}

//Additional function definitions for helper functions




