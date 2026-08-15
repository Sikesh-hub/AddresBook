#include "contact.h"

int main()
{
    int option;
    AddressBook addressbook;
    load_contacts(&addressbook);
    save_contacts(&addressbook); 

    addressbook.contact_count = 0;

    while(1)
    {
        printf("\n========== ADDRESS BOOK ==========\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Save Contacts\n");
        printf("7. Exit...\n");

        printf("Enter the option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                create_contact(&addressbook);
                break;

            case 2:
                search_contacts(&addressbook);
                break;

            case 3:
                contact_editbook(&addressbook);
                break;

            case 4:
                delete_contact(&addressbook);
                break;

            case 5:
                list_contacts(&addressbook);
                break;

            case 6:
                save_contacts(&addressbook);
                break;

            case 7:
            save_contacts(&addressbook);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option!...\n");
        }
    }

    return 0;
}