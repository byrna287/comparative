#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ailbhe Byrne
// 19424402
// I acknowledge the DCU academic integrity policy.

#include "bst_functions.h"

#define MAX_BUF 256     // max that can be read in

// reference for structs in bst's: Kernighan, Ritchie, The C Programming Language, 1988
// struct for the node of a bst, contains name, number, address, left child and right child - to be used as phonebook
struct bstnode {
   char *name;
   char *number;
   char *address;
   struct bstnode *left;
   struct bstnode *right;
};

int main(int argc, char *argv[])
{
   char *buf = malloc(sizeof(char) * MAX_BUF);       // allocate memory for variables which will be read from stdin
   char *line = malloc(sizeof(char) * MAX_BUF);
   char *prompt = "$ ";

   char *name = malloc(sizeof(char) * MAX_BUF);
   char *number = malloc(sizeof(char) * MAX_BUF);
   char *address = malloc(sizeof(char) * MAX_BUF);
   char *option = malloc(sizeof(char) * MAX_BUF);

   struct bstnode *root_names = malloc(sizeof(*root_names));       // bst which sorts on names
   struct bstnode *root_numbers = malloc(sizeof(*root_numbers));   // bst which sorts on numbers
   struct bstnode *found_name = malloc(sizeof(*found_name));       // bst node which will be used for searching for name
   struct bstnode *found_number = malloc(sizeof(*found_number));   // bst node which will be used for searching for number
   root_names = NULL;                              // initialise bst for names with root of null
   root_numbers = NULL;                            // initalise bst for numbers with root of null

   printf("%s\n", "Welcome to the phonebook!");
   printf("%s\n", "To ADD a contact, enter A");
   printf("%s\n", "To FIND a contact, enter F");
   printf("%s\n", "To DELETE a contact, enter D");
   printf("%s\n", "To QUIT the phonebook, enter Q");

   while (!feof(stdin)) {

      fputs(prompt, stdout);             // print shell prompt
      fgets(buf, MAX_BUF, stdin);        // read from stdin
      line = strdup(buf);                // copy of stdin
      line[strcspn(line, "\n")] = 0;     // strip new line character from input (reference: stack overflow)

      if (strcmp(line, "Q") == 0) {      // if command is quit
         printf("%s\n", "Goodbye!");
         exit(0);                        // exit while loop
      }
      else if (strcmp(line, "A") == 0) {      // if command is add
         printf("%s", "Enter name: ");
         fgets(name, MAX_BUF, stdin);
         name[strcspn(name, "\n")] = 0;

         printf("%s", "Enter number: ");
         fgets(number, MAX_BUF, stdin);
         number[strcspn(number, "\n")] = 0;

         printf("%s", "Enter address: ");
         fgets(address, MAX_BUF, stdin);
         address[strcspn(address, "\n")] = 0;

         char *new_details[3] = {name, number, address};    // store name, number and address in array
         if (search_name(root_names, name) == NULL && search_number(root_numbers, number) == NULL) {   // if name and number are not in phonebook
            root_names = store_name(root_names, new_details);        // add name to bst for names
            root_numbers = store_number(root_numbers, new_details);  // add name to bst for numbers
            printf("%s\n", "Contact has been added!");
         }
         else {
            printf("%s\n", "Name or number is already in the phonebook!");
         }
      }
      else if (strcmp(line, "F") == 0) {    // if command is find
         printf("%s\n", "To FIND a contact by NAME, enter 1");
         printf("%s\n", "To FIND a contact by NUMBER, enter 2");
         fgets(option, MAX_BUF, stdin);
         option[strcspn(option, "\n")] = 0;

         if (strcmp(option, "1") == 0) {    // if option is 1
            printf("%s", "Enter name: ");
            fgets(name, MAX_BUF, stdin);
            name[strcspn(name, "\n")] = 0;
            found_name = search_name(root_names, name);  // search bst for names for contact
            if (found_name != NULL) {                    // if name is in phonebook
               printf("Name: %s\nNumber: %s\nAddress: %s\n", found_name->name, found_name->number, found_name->address);   // print contact details
            }
            else {
               printf("%s\n", "They are not in the phonebook!");
            }
         }
         else if (strcmp(option, "2") == 0) {    // if option is 2
            printf("%s", "Enter number: ");
            fgets(number, MAX_BUF, stdin);
            number[strcspn(number, "\n")] = 0;
            found_number = search_number(root_numbers, number);  // search bst for numbers for contact
            if (found_number != NULL) {                          // if number is in phonebook
               printf("Name: %s\nNumber: %s\nAddress: %s\n", found_number->name, found_number->number, found_number->address);   // print contact details
            }
            else {
               printf("%s\n", "They are not in the phonebook!");
            }
         }
         else {
            printf("%s\n", "Re-enter a valid command!");    // if 1 or 2 not entered, look for new command
         }
      }
      else if (strcmp(line, "D") == 0) {    // if command is delete
         printf("%s", "Enter name: ");
         fgets(name, MAX_BUF, stdin);
         name[strcspn(name, "\n")] = 0;
         found_name = search_name(root_names, name);    // search bst for names for contact
         if (found_name != NULL) {                      // if name is in phonebook
            root_names = remove_name(root_names, name);                      // delete contact from bst for names
            root_numbers = remove_number(root_numbers, found_name->number);  // delete contact from bst for numbers
            printf("%s\n", "Contact has been deleted!");
         }
         else {
            printf("%s\n", "They are not in the phonebook!");
         }
      }
      else {
         printf("%s\n", "Re-enter a valid command!");    // if A, F, D or Q was not entered, look for valid command
      }
   }

   free(buf);    // free memory allocated
   free(line);
   free(name);
   free(number);
   free(address);
   free(option);
   free(root_names);
   free(root_numbers);
   free(found_name);
   free(found_number);

   return 0;
}
