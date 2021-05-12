#ifndef CMSC257_P1SUPPORT_INCLUDED
#define CMSC257_P1SUPPORT_INCLUDED
////////////////////////////////////////////////////////////////////////
//
//  File          	: p1support.h
//  Description    	: Headers of general-purpose utility functions 
//					we use for the 257 project #1.
//  Author					: Cheyenne Kent
//	Date						: March 12th, 2021
//	Notes						: Latest version
////////////////////////////////////////////////////////////////////////
//	Add comments for each function below in the following format
///////////////////////////////////////////////////////////////////////
//
// 	Function     : display_array
// 	Description  : Prints out an array of unsigned integers
// 
// 	Inputs       : an array of 10 integers
// 	Outputs      : void
////////////////////////////////////////////////////////////////////////
//
// 	Function     : count_set_bits
// 	Description  : Counts the number of 1s in a bitwise version of a number
//                 and returns the total
// 
// 	Inputs       : an unsigned integer
// 	Outputs      : unsigned int
////////////////////////////////////////////////////////////////////////
//
// 	Function     : reverse_bitwise
// 	Description  : Takes a number and reverses the bits
//
// 	Inputs       : an unsigned integer
// 	Outputs      : unsigned int
////////////////////////////////////////////////////////////////////////
//
// 	Function     : binary_string
// 	Description  : Fills a char string with the binary representation of
//                 a value
//
// 	Inputs       : a pointer to a string, unsigned integer
// 	Outputs      : void
////////////////////////////////////////////////////////////////////////
//
// 	Function     : bitwise_mod64
// 	Description  : takes a value and finds the module of 64 of the value
//
// 	Inputs       : integer
// 	Outputs      : int
////////////////////////////////////////////////////////////////////////
//
// 	Function     : bitwise_abs
// 	Description  : Finds the absolute value of the number
//
// 	Inputs       : integer
// 	Outputs      : int
////////////////////////////////////////////////////////////////////////
//
// 	Function     : bit_get
// 	Description  : extracts a specific bit given a value for the placement
//                 of the bit
//
// 	Inputs       : two integers
// 	Outputs      : int
////////////////////////////////////////////////////////////////////////
//
// 	Function     : odd_or_even
// 	Description  : Determines if a value is even or odd, returning 1 if
//                 odd and 0 if even
//
// 	Inputs       : unsigned integer
// 	Outputs      : int
////////////////////////////////////////////////////////////////////////
//
// 	Function     : swap_ints
// 	Description  : swaps two values places
//
// 	Inputs       : two integer pointers
// 	Outputs      : void

////////////////////////////////////////////////////////////////////////
// Functional Prototypes
////////////////////////////////////////////////////////////////////////

// This function prints out the array of integer values
void display_array(unsigned int*, int);

// This function returns the number of 1s in bitwise
unsigned int count_set_bits(unsigned int);

// This function returns a reversed bitwise version of a number
unsigned int reverse_bitwise(unsigned int);

// Fills in a string with the binary representation of a number
void binary_string(char*, unsigned int);

// Returns the mod 64 of a value
int bitwise_mod64(int);

// Returns the absolute value of an integer
int bitwise_abs(int);

// Returns a specific bit given a number
int bit_get(int, int);

// Returns 1 if the value is odd and 0 if the value is even
int odd_or_even(unsigned int);

// Swaps two numbers
void swap_ints(int*, int*);


#endif // CMSC257_P1SUPPORT_INCLUDED
