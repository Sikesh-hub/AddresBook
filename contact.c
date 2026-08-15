#include "contact.h"
void cre_num_ber(AddressBook *addressbook);
void cre_mail_id(AddressBook *addressbook);
void user_contact_editbook(AddressBook *addressbook,int i);
void load_contacts(AddressBook *addressbook);

void create_contact(AddressBook *addressbook)
{
    char temp[20];
    int i, valid;

    if(addressbook->contact_count >= 100)
    {
        printf("Address Book Full!\n");
        return;
    }

    while(1)
    {

        printf("Enter Name: ");
        scanf(" %[^\n]", temp);

        valid = 1;

        for(i = 0; temp[i] != '\0'; i++)
        {
            if(!isalpha(temp[i]))
            {
                valid = 0;
                break;
            }
        }

        if(valid)
            break;

        printf("Invalid Name! Only alphabets allowed.\n");
    }

    strcpy(addressbook->contact_details[addressbook->contact_count].name, temp);

    cre_num_ber(addressbook);  //function call..
    cre_mail_id(addressbook);   //function call..

    printf("------------- Contact Saved Sucessfully--------------\n");

    addressbook->contact_count++;  // increment if adding new contact

    printf("Did you want to add one more contact\n(1.y or 2.n)\nEnter the option :");
    int zx;
    scanf("%d",&zx);
    if(zx == 1)
    {
        create_contact(addressbook);   //function call..

    }
    else if (zx == 2)
    {
        printf("------------- Contact Saved Sucessfully--------------\n");
       
    }
    
    
}


void cre_num_ber(AddressBook *addressbook)
{
    char num[11];
    int i, valid;


    while(1)
    {
        printf("Enter Mobile Number: ");
        scanf("%s", num);
        valid =1;
        for(i = 0; i < addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].mobile_number, num) == 0) // comparing two strings
            {
                printf("Mobile number already exists.\nPlease enter a unique number.\n");
                valid = 0;
                break;
            }
        }
        if(i < addressbook->contact_count) // duplicate found
            continue;

        if(strlen(num) != 10) 
        {
            printf("Mobile number must contain exactly 10 digits.\n");
            continue;
        }
        
        for(i = 0; num[i] != '\0'; i++)
        {
            if(!isdigit(num[i]))
            {
                valid = 0;
                break;
            }
        }

        if(!valid)
        {
            printf("Mobile number must contain digits only.\n");
            continue;
        }
        strcpy(addressbook->contact_details[addressbook->contact_count].mobile_number, num);
        break;
    }
}


void cre_mail_id(AddressBook *addressbook)
{
    char mailid[50];

while (1)
{
    printf("Enter Email ID: ");
    scanf("%49s", mailid);

    // Count occurrences of '@' and ".com"
    int at_count = 0;
    int dotcom_count = 0;

    // Scan string manually
    for (int i = 0; mailid[i] != '\0'; i++)
    {
        if (mailid[i] == '@')
            at_count++;

        if (strncmp(&mailid[i], ".com", 4) == 0)
            dotcom_count++;
    }

    char *at = strchr(mailid, '@');
    char *dotcom = strstr(mailid, ".com");

    if (at && dotcom && at_count == 1 && dotcom_count == 1 && at < dotcom && (dotcom - at) > 1)
    {
        break;
    }

    printf("Invalid Email ID.\n");
}

strcpy(addressbook->contact_details[addressbook->contact_count].mail_id, mailid);

}

void list_contacts(AddressBook *addressbook)
{
    int i;

    if(addressbook->contact_count == 0)
    {
        printf("No Contacts Available.\n");
        return;
    }

    for(i = 0; i < addressbook->contact_count; i++)
    {
        printf("\nContact %d.", i + 1);
        printf("Name   : %s     ",addressbook->contact_details[i].name);
        printf("Mobile : %s     ",addressbook->contact_details[i].mobile_number);
        printf("Email  : %s     ",addressbook->contact_details[i].mail_id);
    }
}

void search_contacts(AddressBook *addressbook)

{
    int ch, i, found = 0;

    printf("\nSearch Contact Menu\n");
    printf("1.Search by Name\n");
    printf("2.Search by Mobile Number\n");
    printf("3.Search by Mail ID\n");
    printf("4. Exit\n");
    printf("Enter Choice: ");

    scanf("%d", &ch);

    if(ch == 1)
    {
        char name[20];

        printf("Enter Name To Search: ");
        scanf("%19s", name);
        int len1=strlen(name);

        for(i = 0; i < addressbook->contact_count; i++)
        {
            if(strncmp(name,addressbook->contact_details[i].name,len1) == 0) // comparing two strings
            {
                found = 1;

                printf("\nContact Found\n");
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
            }
        }
    }
    else if(ch == 2)
    {
        char number[11];

        printf("Enter Mobile Number To Search : ");
        scanf("%10s", number);

        for(i = 0; i < addressbook->contact_count; i++)
        {
            if(strcmp(number,addressbook->contact_details[i].mobile_number) == 0)  // comparing two strings
            {
                found = 1;

                printf("\nContact Found\n");
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                break;
            }
        }
    }
    else if(ch == 3)
    {
        char mail[50];

        printf("Enter Email ID To Search: ");
        scanf("%49s", mail);

        for(i = 0; i < addressbook->contact_count; i++)
        {
            if(strcmp(mail,addressbook->contact_details[i].mail_id) == 0) // comparing two strings
            {
                found = 1;

                printf("\nContact Found\n");
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                break;
            }
        }
    }
    else if(ch == 4)
    {
        return;
    }

    if(!found)
    {
        printf("Contact Not Found!\n");
    }
}
void delete_contact(AddressBook *addressbook)
{
    printf("Delete Contact menu : \n1.Enter The Name \n2.Enter The Mobile number\n3.Enter The Mail ID\n4.Exit\nEnter the option : ");
    int cv;
    scanf("%d",&cv);
    char an[20];
    int found = 0;
    if(cv == 1)
    {
        char an[20];
        printf("Enter The Name To Delete : ");
        scanf("%s", an);
        for (int i = 0; i < addressbook->contact_count; i++)
        {
            if (strcmp(an, addressbook->contact_details[i].name) == 0) // comparing two strings
            {
                found = 1;
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                // Shift contacts left
                char cx;
                printf("\nDo you want to delete this contact? (y/n): ");
                scanf(" %c", &cx);
                if(cx =='y' || cx=='Y')
                {
                    for (int j = i; j < addressbook->contact_count - 1; j++)
                    {
                        addressbook->contact_details[j] =addressbook->contact_details[j + 1];
                    }
                    addressbook->contact_count--;  // decrement if adding new contact

                    printf("Contact Deleted Successfully!\n");
                }
                else{
                    printf("Deletion Cancelled!\n");
                }
                    
            }
        }
    }
    else if(cv == 2)
    {
        printf("Enter The Mobile Number :");
        char vb[11];
        scanf("%s", vb);
        for(int i=0;i<addressbook->contact_count;i++)
        {
            if(strcmp(vb,addressbook->contact_details[i].mobile_number)==0)  // comparing two strings
            {
                found =1;
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                char nh;
                printf("\nDo you want to delete this contact? (y/n): ");
                scanf(" %c", &nh);
                if(nh=='y' || nh=='Y')
                {
                    for (int j = i; j < addressbook->contact_count - 1; j++)
                    {
                        addressbook->contact_details[j] =addressbook->contact_details[j + 1];
                    }
                    addressbook->contact_count--; // decrement if adding new contact
                    printf("Contact Deleted Successfully!\n");
                }
               
                else{
                    printf("Deletion Cancelled!\n");
                }

            }
            
        }
    }
    else if(cv== 3)
    {
        printf("Enter The Maill Id To Delete Contact :");
        char hup[50];
        scanf("%s",hup);
        for(int i=0;i<addressbook->contact_count;i++)
        {
            if(strcmp(hup,addressbook->contact_details[i].mail_id)==0)  // comparing two strings
            {
                found =1;
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                char df;
                printf("\nDo you want to delete this contact? (y/n): ");
                scanf(" %c", &df);
                if(df == 'y' || df == 'Y')
                {
                    for (int j = i; j < addressbook->contact_count - 1; j++)
                    {
                        addressbook->contact_details[j] =addressbook->contact_details[j + 1];
                    }
                    addressbook->contact_count--;  // decrement if adding new contact
                    printf("Contact Deleted Successfully!\n");

                }
                else
                {
                    printf("Deletion Cancelled!\n");
                }
            }
        }
        
    }

    if (!found)
    {
        printf("Contact Not Found!\n");
    }
}
void contact_editbook(AddressBook *addressbook)
{
    int bn;
    printf("\nSearch Contact Menu\n1.Search Name To Edit\n2.Search Mobile Number To Edit\n3.Search Mail_id To Edit\n4. Exit\n");
    printf("Enter Choice: ");
    int found =0;


    scanf("%d", &bn);
    if(bn == 1)
    {
        char name[20];

        printf("Enter Name: ");
        scanf("%19s", name);
        int len =strlen(name);
        
        for(int i = 0; i < addressbook->contact_count; i++)
        {
            if(strncmp(name,addressbook->contact_details[i].name,len) == 0) // comparing two strings
            {
                found = 1;

                printf("\nContact Found\n");
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                user_contact_editbook(addressbook,i); //function call..
               // break;
            }
        }

    }
    else if(bn == 2)
    {
        char number[11];

        printf("Enter Mobile Number: ");
        scanf("%10s", number);

        for(int i = 0; i < addressbook->contact_count; i++)
        {
            if(strcmp(number,addressbook->contact_details[i].mobile_number) == 0) // comparing two strings
            {
                found = 1;

                printf("\nContact Found\n");
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                user_contact_editbook(addressbook,i);  //function call..
                break;
            }
        }

    }
    else if(bn == 3)
    {
        char mail[50];

        printf("Enter Email ID: ");
        scanf("%49s", mail);

        for(int i = 0; i < addressbook->contact_count; i++)
        {
            if(strcmp(mail,addressbook->contact_details[i].mail_id) == 0)  // comparing two strings
            {
                found = 1;

                printf("\nContact Found\n");
                printf("Name   : %s\n",addressbook->contact_details[i].name);
                printf("Mobile : %s\n",addressbook->contact_details[i].mobile_number);
                printf("Email  : %s\n",addressbook->contact_details[i].mail_id);
                user_contact_editbook(addressbook,i);  //function call..
                break;
            }
        }

    }
    else
    {
        return;
    }

    if(!found)
    {
        printf("Contact Not Found!\n");

    }

}

void user_contact_editbook(AddressBook *addressbook,int index)
{
    int vb;

    printf("\n1.Edit Name To Update :\n2.Edit Mobile Number To Update\n3.Edit Mail ID To Update\n4.Edit All\n5.Exit..\n");
    printf("Enter option : ");
    scanf("%d", &vb);
    int valid=0;

    switch(vb)
    {
        case 1:
            char hj[20];
            while(1)
            {
                printf("Enter New Name to Update: ");
                scanf(" %[^\n]",hj );
                valid = 1;
                for(int i = 0; hj[i] != '\0'; i++)
                {
                    if(!isalpha(hj[i]))
                    {
                        valid = 0;
                        break;
                    }
                }
                if(valid)
                break;
                printf("Invalid Name! Only alphabets allowed.\n");
            }
            //Replace old Name with new one
            strcpy(addressbook->contact_details[index].name,hj);
            break;
            

        case 2:

            char nm[11];
            int valid =0;
            while(1)
            {
                printf("Enter New Mobile Number :");
                scanf("%s", nm);
                valid =1;
                //Check uniqueness
                for(int i = 0; i < addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[i].mobile_number, nm) == 0)
                    {
                        printf("Mobile number already exists.\nPlease enter a unique number.\n");
                        valid = 0;
                        break;
                    }
                }
                if (!valid) continue;
                if(strlen(nm) != 10)
                {
                    printf("Mobile number must contain exactly 10 digits.\n");
                    continue;
                }
                //Check digits only
                
                for(int i = 0; nm[i] != '\0'; i++)
                {
                    if(!isdigit(nm[i]))
                    {
                        valid = 0;
                        break;
                    }
                }

                if(!valid)
                {
                    printf("Mobile number must contain digits only.\n");
                    continue;
                }
                //Replace old number with new one
                strcpy(addressbook->contact_details[index].mobile_number,nm);
                //printf("Mobile number updated successfully!\n"); 
                break;
            }
            break;

        case 3:
                char mailid[50];

            while (1)
            {
                printf("Enter Email ID: ");
                scanf("%49s", mailid);

                // Count occurrences of '@' and ".com"
                int at_count = 0;
                int dotcom_count = 0;

                // Scan string manually
                for (int i = 0; mailid[i] != '\0'; i++)
                {
                    if (mailid[i] == '@')
                        at_count++;

                    if (strncmp(&mailid[i], ".com", 4) == 0)
                        dotcom_count++;
                }

                char *at = strchr(mailid, '@');
                char *dotcom = strstr(mailid, ".com");

                if (at && dotcom &&
                    at_count == 1 &&
                    dotcom_count == 1 &&
                    at < dotcom &&
                    (dotcom - at) > 1)
                {
                    break;
                }

                printf("Invalid Email ID.\n");
            }
            //Replace old mail_id with new one

            strcpy(addressbook->contact_details[index].mail_id, mailid);
            break;

        case 4:
            char we[20];
            int temp= 0,i;
            // ---- Edit Name ----
            while(1)
            {
                printf("Enter New Name to Update: ");
                scanf(" %[^\n]", we);
                temp=1;
                for(i = 0; we[i] != '\0'; i++)
                {
                    if(!isalpha(we[i]))
                    {
                        temp= 0;
                        break;
                    }
                }
                if(temp)
                break;
                
                printf("Invalid Name! Only alphabets allowed.\n");
            }
            //Replace old Name with new one
            strcpy(addressbook->contact_details[index].name, we);
             // ---- Edit Mobile Number ----
            char fg[11];
            //int valid =0;
            while(1)
            {
                printf("Enter New Mobile Number :");
                scanf("%s", fg);
                temp =1;
                //Check uniqueness
                for(int i = 0; i < addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[index].mobile_number, fg) == 0)
                    {
                        printf("Mobile number already exists.\nPlease enter a unique number.\n");
                        temp = 0;
                        break;
                    }
                }
                if (!temp) continue;
                if(strlen(fg) != 10)
                {
                    printf("Mobile number must contain exactly 10 digits.\n");
                    continue;
                }
                //Check digits only
                
                for(int i = 0; fg[i] != '\0'; i++)
                {
                    if(!isdigit(fg[i]))
                    {
                        temp = 0;
                        break;
                    }
                }

                if(!temp)
                {
                    printf("Mobile number must contain digits only.\n");
                    continue;
                }
                //Replace old number with new one
                strcpy(addressbook->contact_details[index].mobile_number, fg);
                //printf("Mobile number updated successfully!\n"); 
                break;
            }
            // maill id -----
            char qw[50];

            while (1)
            {
                printf("Enter Email ID: ");
                scanf("%49s", qw);

                // Count occurrences of '@' and ".com"
                int at_count = 0;
                int dotcom_count = 0;

                // Scan string manually
                for (int i = 0; qw[i] != '\0'; i++)
                {
                    if (qw[i] == '@')
                        at_count++;

                    if (strncmp(&qw[i], ".com", 4) == 0)
                        dotcom_count++;
                }

                char *at = strchr(qw, '@');
                char *dotcom = strstr(qw, ".com");

                if (at && dotcom &&
                    at_count == 1 &&
                    dotcom_count == 1 &&
                    at < dotcom &&
                    (dotcom - at) > 1)
                {
                    break;
                }

                printf("Invalid Email ID.\n");
            }
            //Replace old mail with new one

            strcpy(addressbook->contact_details[index].mail_id, qw);
            break;

        case 5:
            return;
        default:
            printf("Invalid option\n");
    }
    printf("Contact updated successfully\n");
}

void save_contacts(AddressBook *addressbook)
{
    FILE *fp = fopen("addressbook.csv", "w");

    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }
    fprintf(fp, "#%d\n", addressbook->contact_count);
    for(int i = 0; i < addressbook->contact_count; i++)
    {
        fprintf(fp, "%s,%s,%s\n",addressbook->contact_details[i].name,addressbook->contact_details[i].mobile_number,addressbook->contact_details[i].mail_id);
    }

    fclose(fp);
    printf("Contact saved successfully\n");
}
void load_contacts(AddressBook *addressbook)
{
    FILE *fp = fopen("addressbook.csv", "r");

    if(fp == NULL)
    {
        addressbook->contact_count = 0;
        save_contacts(addressbook);   // creates file with #0
        return;
    }
    
    if(fscanf(fp, "#%d\n",&addressbook->contact_count) != 1)
    {
        addressbook->contact_count = 0;
        fclose(fp);
        return;
    }
    if(addressbook->contact_count > 100)
    {
        addressbook->contact_count = 100;
    }
    
    for(int i = 0; i < addressbook->contact_count; i++)
    {
        if(fscanf(fp,"%19[^,],%10[^,],%49[^\n]\n",addressbook->contact_details[i].name,addressbook->contact_details[i].mobile_number,addressbook->contact_details[i].mail_id) != 3)
        {
            addressbook->contact_count = i;
            break;
        }
    }
    fclose(fp);
}