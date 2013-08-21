#ifndef LINKED_LIST_H
#define LINKED_LIST_H

static const int NO_ERROR = 0;
static const int MEMORY_ERROR = 1;
static const int IMPROPER_USAGE = 2;

struct Linked_List;
typedef struct Linked_List Linked_List;

int add_linked_list(Linked_List **linked_list, int id);
void destroy_linked_list(Linked_List *linked_list);
void print_linked_list(Linked_List *linked_list);
int remove_nth_from_end(Linked_List **linked_list, const int number);
int reverse_linked_list(Linked_List **linked_list);

#endif /* LINKED_LIST */
