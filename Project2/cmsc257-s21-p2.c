//Add program description, author name, last edit date as in the project1
//Do not modify anything below this line

////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s21-p2.c
//  Description    : This is the main source code for for the second
//					 project of CMSC257.
//					 See the related assignment page for details.
//
//   Author        : Cheyenne Kent
//   Last Modified : April 8th, 2021
//

//include files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Project Includes
#include "p2-support.h"

///////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 project #2
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure
int main() {
        struct Mailbox* ib;
        //initialize ib and malloc size for it
        ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
        //calls different functions i p2-support.c and frees memory
        initialize(ib);
        display_inbox_menu(ib);
        free (ib);
        return 0;
}