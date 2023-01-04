/* functions used in bst_loop.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ailbhe Byrne
// 19424402
// I acknowledge the DCU academic integrity policy.

#include "bst_functions.h"

// struct for the node of a bst, contains name, number, address, left child and right child - to be used as phonebook
struct bstnode {
   char *name;
   char *number;
   char *address;
   struct bstnode *left;
   struct bstnode *right;
};

// reference for store_name: Kernighan, Ritchie, The C Programming Language, 1988
// function to add a contact to a bst, sorted by name
struct bstnode *store_name(struct bstnode *ptr, char *new_details[])
{
   if (ptr == NULL) {                         // if right place is found
      ptr = malloc(sizeof(*ptr));             // allocate memory for node
      ptr->name = strdup(new_details[0]);     // add name to node
      ptr->number = strdup(new_details[1]);   // add number to node
      ptr->address = strdup(new_details[2]);  // add address to node
      ptr->left = ptr->right = NULL;          // add left and right child which have no children
   }
   else if (strcmp(new_details[0], ptr->name) < 0) {     // if name to be added is before current name alphabetically go down left side of bst
      ptr->left = store_name(ptr->left, new_details);
   }
   else {
      ptr->right = store_name(ptr->right, new_details);  // if name to be added is after current name alphabetically go down right side of bst
   }
   return ptr;
}

// reference for store_number: Kernighan, Ritchie, The C Programming Language, 1988
// function to add a contact to a bst, sorted by number
struct bstnode *store_number(struct bstnode *ptr, char *new_details[])
{
   if (ptr == NULL) {                         // if right place is found
      ptr = malloc(sizeof(*ptr));             // allocate memory for node
      ptr->name = strdup(new_details[0]);     // add name to node
      ptr->number = strdup(new_details[1]);   // add number to node
      ptr->address = strdup(new_details[2]);  // add address to node
      ptr->left = ptr->right = NULL;          // add left and right child which have no children
   }
   else if (strcmp(new_details[1], ptr->number) < 0) {     // if number to be added is smaller (alphabetically) than current number go down left side of bst
      ptr->left = store_number(ptr->left, new_details);
   }
   else {
      ptr->right = store_number(ptr->right, new_details);  // if number to be added is bigger (alphabetically) than current number go down right side of bst
   }
   return ptr;
}

// function to search a bst, which is sorted by name
struct bstnode *search_name(struct bstnode *ptr, char *name_check)
{
   if (ptr == NULL) {   // if name not found
      return NULL;
   }
   else if (strcmp(name_check, ptr->name) == 0) {   // if name is found
      return ptr;                                   // return node
   }
   else if (strcmp(name_check, ptr->name) < 0) {    // if name to be found is before current name alphabetically go down left side of bst
      return search_name(ptr->left, name_check);
   }
   else {
      return search_name(ptr->right, name_check);   // otherwise go down right side of bst
   }
}

// function to search a bst, which is sorted by number
struct bstnode *search_number(struct bstnode *ptr, char *number_check)
{
   if (ptr == NULL) {   // if number not found
      return NULL;
   }
   else if (strcmp(number_check, ptr->number) == 0) {   // if number is found
      return ptr;                                       // return node
   }
   else if (strcmp(number_check, ptr->number) < 0) {    // if number to be found is smaller (alphabetically) than current number go down left side of bst
      return search_number(ptr->left, number_check);
   }
   else {
      return search_number(ptr->right, number_check);   // otherwise go down right side of bst
   }
}

// function to remove contact from a bst, which is sorted by name
struct bstnode *remove_name(struct bstnode *ptr, char *name_check) {
   if (ptr == NULL) {   // if name not found
      return NULL;
   }
   else if (strcmp(name_check, ptr->name) == 0) {      // if name is found
      if (ptr->left == NULL && ptr->right == NULL) {   // if node has no children
         return NULL;
      }
      else if (ptr->left != NULL && ptr->right == NULL) {   // if node only has left child
         return ptr->left;                                  // return left child
      }
      else if (ptr->left == NULL && ptr->right != NULL) {   // if node only has right child
         return ptr->right;                                 // return right child
      }
      else {                                                   // if node has 2 children
         struct bstnode *ptr_new = malloc(sizeof(*ptr_new));   // allocate memory for node
         ptr_new = first_str_alpha(ptr->right);                // find first name alphabetically in right child
         ptr->name = strdup(ptr_new->name);                    // overwrite name to be deleted
         ptr->number = strdup(ptr_new->number);                // overwrite number to be deleted
         ptr->address = strdup(ptr_new->address);              // overwrite address to be deletd
         ptr->right = remove_name(ptr->right, ptr_new->name);  // delete node which was used to overwrite
         return ptr;
      }
   }
   else if (strcmp(name_check, ptr->name) < 0) {        // if name to be deleted is before current name alphabetically go down left side of bst
      ptr->left = remove_name(ptr->left, name_check);
      return ptr;
   }
   else {
      ptr->right = remove_name(ptr->right, name_check); // if name to be deleted is after current name alphabetically go down right side of bst
      return ptr;
   }
}

// function to remove contact from a bst, which is sorted by number
struct bstnode *remove_number(struct bstnode *ptr, char *number_check) {
   if (ptr == NULL) {   // if number not found
      return NULL;
   }
   else if (strcmp(number_check, ptr->number) == 0) {   // if number is found
      if (ptr->left == NULL && ptr->right == NULL) {    // if node has no children
         return NULL;
      }
      else if (ptr->left != NULL && ptr->right == NULL) {   // if node only has left child
         return ptr->left;                                  // return left child
      }
      else if (ptr->left == NULL && ptr->right != NULL) {   // if node only has right child
         return ptr->right;                                 // return right child
      }
      else {                                                      // if node has 2 children
         struct bstnode *ptr_new = malloc(sizeof(*ptr_new));      // allocate memory for node
         ptr_new = first_str_alpha(ptr->right);                   // find smallest number in right child
         ptr->name = strdup(ptr_new->name);                       // overwrite name to be deleted
         ptr->number = strdup(ptr_new->number);                   // overwrite number to be deleted
         ptr->address = strdup(ptr_new->address);                 // overwrite address to be deletd
         ptr->right = remove_number(ptr->right, ptr_new->number); // delete node which was used to overwrite
         return ptr;
      }
   }
   else if (strcmp(number_check, ptr->number) < 0) {
      ptr->left = remove_number(ptr->left, number_check);    // if number to be deleted is smaller (alphabetically) than current number go down left side of bst
      return ptr;
   }
   else {
      ptr->right = remove_number(ptr->right, number_check);  // if number to be deleted is bigger (alphabetically) than current number go down left side of bst
      return ptr;
   }
}

// function to find contact in tree with first string alphabetically
struct bstnode *first_str_alpha(struct bstnode *ptr) {
   if (ptr->left == NULL) {
      return ptr;
   }
   else {
      return first_str_alpha(ptr->left);
   }
}
