#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>
#include <ctype.h>

// Structures for the Fields
typedef struct Contact_data
{
    char name[20];
    char mobile_number[11];
    char mail_id[20];

} Contacts;

// Structures foe the Contact deatils
typedef struct AddressBook_Data
{
    // Array of structures for the Fields sturucture
    Contacts contact_details[100];
    // To keep the track no of contact count
    int contact_count;
} AddressBook;

/* Function declarations */

void create_contact(AddressBook *addressbook);
void list_contacts(AddressBook *addressbook);
void search_contacts(AddressBook *addressbook);
void delete_contact(AddressBook *addressbook);
void save_contacts(AddressBook *addressbook);
void contact_editbook(AddressBook *addressbook);
void load_contacts(AddressBook *addressbook);



#endif
// CONTACT_H
// CONTACT_H