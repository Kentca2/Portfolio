#define MAILBOX_SIZE 2000
#define ADRESS_SIZE 20
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//CHANGE TO VCU email below
#define user_email "kentca2@vcu.edu"
//add other define Macros as needed
////////////////////////////////////////////////////////////////////////
//
//  File          	: p2support.h
//  Description    	: Headers of general-purpose utility functions
//					we use for the 257 project #2.
//  Author					: Cheyenne Kent
//	Date						: April 8th, 2021
//	Notes						: Latest version
////////////////////////////////////////////////////////////////////////
struct Email
{
        char sender[ADRESS_SIZE];
        char receiver[ADRESS_SIZE];
        //add other struct members as needed
        char subject[SUBJECT_SIZE];
        char body[BODY_SIZE];
        //consider adding a nested struct here
        struct sent_date
        {
                int month, day, year;
        }date;
        int ID;
};

struct Mailbox
{
        int size;
        //add other struct members as needed
        struct Email* emails;
};

/////////////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each function declared within the .h file
//
// Function : initialize
// Description : Initializes the database for CMSC257 project #2 by manually entering
// the records using create_email function
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void initialize (struct Mailbox *ib);

//add other function declarations as needed

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : create_email
// Description : populates the mailbox with the emails
//
// Inputs : char array sender, char array user, char array header, char array body,
// int month, int day, in year, struct Mailbox* - pointer to the database
// Outputs : void

void create_email(char sender[], char user[], char header[], char body[], int month, int day, int year, struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : display_inbox_menu
// Description : displays the menu for the inbox and gives users options
// on what they would like to accomplish
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void display_inbox_menu(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : show_inbox
// Description : displays the emails in the mailbox by iterating through the array
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void show_inbox(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : show_email_ID
// Description : prompts the user to enter the ID of the email they'd like to see
// then prints the email out for user
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void show_email_ID(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : sort_by_sender
// Description : sorts the emails in alphabetical order according to the senders email
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void sort_by_sender(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : sort_by_ID
// Description : sorts the emails from the newest to the oldest email
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void sort_by_ID(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : search_inbox
// Description : prompts the user for a string they would like to find in their email
// prints the emails containing the string (whether in senders email, subject, or body)
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void search_inbox(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//
// Function : delete_email
// Description : prompts user for the ID of the email they'd like to delete
// deletes the email from the mailbox
//
// Inputs : struct Mailbox* - pointer to the database
// Outputs : void

void delete_email(struct Mailbox *ib);