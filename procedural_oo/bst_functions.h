/* functions used in bst_loop.c */

// Ailbhe Byrne
// 19424402
// I acknowledge the DCU academic integrity policy.

// function to add a contact to a bst, sorted by name
struct bstnode *store_name(struct bstnode *ptr, char *new_details[]);

// function to add a contact to a bst, sorted by number
struct bstnode *store_number(struct bstnode *ptr, char *new_details[]);

// function to search a bst, which is sorted by name
struct bstnode *search_name(struct bstnode *ptr, char *name_check);

// function to search a bst, which is sorted by number
struct bstnode *search_number(struct bstnode *ptr, char *number_check);

// function to remove contact from a bst, which is sorted by name
struct bstnode *remove_name(struct bstnode *ptr, char *name_check);

// function to remove contact from a bst, which is sorted by number
struct bstnode *remove_number(struct bstnode *ptr, char *name_check);

// function to find contact in tree with first string alphabetically
struct bstnode *first_str_alpha(struct bstnode *ptr);
