//Add program descriptions, author name, last edit date as in project1
//Add necessary include statements
#define _GNU_SOURCE
#include "p2-support.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////
//
//  File          	: p2support.c
//  Description    	: This is a set of general-purpose utility functions
//					we use for the 257 project #2.
//  Author					: Cheyenne Kent
//	Date						: April 8th, 2021
//	Notes						: Latest version


////////////////////////////////////////////////////////////////////////
// Function Definitions (in p2-support.h)
////////////////////////////////////////////////////////////////////////

void
initialize (struct Mailbox *ib)
{
    //allocate memory for 2000 emails
    ib->emails = malloc (sizeof (struct Email) * MAILBOX_SIZE);
    ib->size = 0;

    //calls the create_email to populate mailbox ib
    create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.", "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.", 11,20,2020, ib);
    create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.", "Yet another email just to pad out your inbox, have fun!", 11,30,2020, ib);
    create_email ("dboyle@mail.com", user_email, "3rd email!", "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!", 12,2,2020, ib);
    create_email ("cbluer@mail.com", user_email, "4th email!", "Content of fourth email. More coding, more fun!", 12,8,2020, ib);
    create_email ("cboyle@mail.com", user_email, "5th email!", "Content of fifth email. Coding is fun-tastic!", 12,18,2020, ib);
    create_email ("sblack@mail.com", user_email, "6th email!", "Content of fifth email. coding is fun-tastic!", 1,1,2021, ib);
    create_email ("sblack@mail.com", user_email, "7th email!", "Body of sixth email. Coding is fun-tastic!", 1,5,2021, ib);
    create_email ("sblack@mail.com", user_email, "8th email!", "Body of eighth email. Coding is fun-tastic!", 2,15,2021, ib);
    create_email ("sblack@mail.com", user_email, "9th email!", "Body of ninth email. Coding is fun-tastic!", 2,25,2021, ib);
    create_email ("dboyle@mail.com", user_email, "Last email!", "Body of tentth email. Coding is fun-tastic!", 3,15,2021, ib);
}

//takes in Mailbox ib and prints the inbox menu
//gives user option to pick one of the options for the menu
//cases call method accordingly
void
display_inbox_menu (struct Mailbox *ib)
{
        //initialization of input
        int input = 0;

        //prints the inbox menu
        printf("\n*************** %s INBOX ***************\n", ib->emails[1].receiver);
        printf("***************   Total Inbox: %04d   ***************\n\n", ib->size);
        printf("1. Show Inbox\n");
        printf("2. Show Email by ID\n");
        printf("3. Sort Inbox by Sender\n");
        printf("4. Sort Inbox by ID\n");
        printf("5. Search Inbox by Keyword\n");
        printf("6. Delete\n");
        printf("7. Exit Inbox\n\n");

        scanf("%d", &input);

        //switch case to call methods accordingly
        switch(input) {
            case 1: show_inbox(ib); break;
            case 2: show_email_ID(ib); break;
            case 3: sort_by_sender(ib); break;
            case 4: sort_by_ID(ib); break;
            case 5: search_inbox(ib); break;
            case 6: delete_email(ib); break;
            case 7: free(ib->emails); printf("\nExiting e-mail client - Good Bye!\n\n"); break;
        }
}

//takes in sender, user, header, body, month, day, year, and ib
//populates ib with the values passed in
void
create_email(char sender[], char user[], char header[], char body[], int month, int day, int year, struct Mailbox *ib)
{
    //using strcpy() to copy the passed in strings to the array since they are strings
    strcpy(ib->emails[ib->size].sender, sender);
    strcpy(ib->emails[ib->size].receiver, user);
    strcpy(ib->emails[ib->size].subject, header);
    strcpy(ib->emails[ib->size].body, body);
    //assigning the int values into the array
    ib->emails[ib->size].date.month = month;
    ib->emails[ib->size].date.day = day;
    ib->emails[ib->size].date.year = year;
    ib->emails[ib->size].ID = ib->size;
    ib->size++;
}

//passes in Mailbox ib
//prints the header and then prints the inbox
//prints every email in the array
void
show_inbox(struct Mailbox *ib)
{
        int i;
        printf("\nID  SENDER--------------    MM/DD/YYYY  SUBJECT--------\n");
        printf("--  --------------------    --/--/----  ---------------\n");
        //for loop to go through the array and print the id, sender, date, and subject
        for(i = 0; i < ib->size; i++){
            printf("%02d - %-20s - %02d/%02d/%4d - %-15s \n", ib->emails[i].ID, ib->emails[i].sender, ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year, ib->emails[i].subject);
        }
        display_inbox_menu(ib);
}

//passes in Mailbox ib
//prints the email by ID passed in by user
void
show_email_ID(struct Mailbox *ib)
{
        int id;
        printf("Enter the ID of the email you want to read:\n");
        scanf("%d", &id);
        printf("\n%s - %s\nEmail Received on: %d/%d/%d\n\n%s\n\n", ib->emails[id].sender, ib->emails[id].subject, ib->emails[id].date.month, ib->emails[id].date.day, ib->emails[id].date.year, ib->emails[id].body);
        display_inbox_menu(ib);
}

//passes in Mailbox ib
//sorts the emails by the senders email in alphabetical order
void
sort_by_sender(struct Mailbox *ib)
{
        struct Email temp;
        int i, j;
        //nested for loops so the array can be gone through multiple times
        for (i = 0; i < ib->size; i++){
            for(j = i + 1; j < ib->size; j++){
                //uses strcmp to compare the senders email
                if(strcmp(ib->emails[i].sender, ib->emails[j].sender) > 0){
                    temp = ib->emails[i];
                    ib->emails[i] = ib->emails[j];
                    ib->emails[j] = temp;
                }
            }
        }
        display_inbox_menu(ib);
}

//passes in Mailbox ib
//sorts the emails from newest email to oldest email
void
sort_by_ID(struct Mailbox *ib)
{
        struct Email temp;
        int i, j;
        //nested for loop so the array can be cone through multiple times
        for (i = 0; i < ib->size; i++){
            for(j = i + 1; j < ib->size; j++){
                if(ib->emails[i].ID < ib->emails[j].ID){
                    temp = ib->emails[i];
                    ib->emails[i] = ib->emails[j];
                    ib->emails[j] = temp;
                }
            }
        }
        display_inbox_menu(ib);
}

//passes in Mailbox ib
//searches the inbox for a certain string
//prints the emails that contain the string whether in sender, subject, or body
void
search_inbox(struct Mailbox *ib)
{
        int i;
        char find[200];
        printf("\nEnter the keyword you are searching for:\n");
        scanf("%s", find);
        //prints the header
        printf("\nID  SENDER--------------    MM/DD/YYYY  SUBJECT\n");
        printf("--  --------------------    --/--/----  \n");

        for(i = 0; i < ib->size; i++){
            //checks to see if string is found in either sender, subject, or body
            if(strcasestr(ib->emails[i].sender, find) || strcasestr(ib->emails[i].subject, find) || strcasestr(ib->emails[i].body, find)){
                printf("%02d - %-20s - %02d/%02d/%4d - %-15s \n", ib->emails[i].ID, ib->emails[i].sender, ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year, ib->emails[i].subject);
            }
        }
        display_inbox_menu(ib);
}

//passes in Mailbox ib
//deletes email based on the id user inputs
void
delete_email(struct Mailbox *ib)
{
        int id, i, j;
        printf("\nEnter the ID of the e-mail you want to delete: \n");
        scanf("%d", &id);
        //first for loop goes through the array until if finds the matching id
        //second for loop shifts everything to the left to get rid of email
        for(j = 0; j < ib->size; j++){
            if(ib->emails[j].ID == id){
                for(i = j; i < ib->size - 1; i++){
                    ib->emails[i] = ib->emails[i+1];
                }
            }
        }

        ib->size--;
        printf("Email with the ID = %d is deleted\n", id);
        display_inbox_menu(ib);
}