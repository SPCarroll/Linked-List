#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct Linked_List {
	int id; /* id is assumed to be unique */
	struct Linked_List *next;
};

int add_linked_list(Linked_List **linked_list, int id)
{
	if(!*linked_list) {
		/* empty list to start, so make room for item then add */
		*linked_list = malloc(sizeof(Linked_List));
		if(!*linked_list) {
			fprintf(stderr, "\nError. Could not get memory to create linked list.\n");
			return MEMORY_ERROR;
		}
		(*linked_list)->id = id;
		(*linked_list)->next = NULL;
	} else {
		/* list already exists, resize and add one */
		Linked_List **tmp = linked_list;
		while(*tmp) {
			tmp = &(*tmp)->next;
		}
		*tmp = malloc(sizeof(Linked_List));
		if(!*tmp) {
			fprintf(stderr, "\nError. Could not get memory to add to linked list.\n");
			return MEMORY_ERROR;
		}
		(*tmp)->id = id;
		(*tmp)->next = NULL;
	}
	return NO_ERROR;
}

void destroy_linked_list(Linked_List *linked_list)
{
	Linked_List *tmp;
	while(linked_list) {
		tmp = linked_list;
		linked_list = linked_list->next;
		free(tmp);
	}
}

void print_linked_list(Linked_List *linked_list)
{
	if(!linked_list) {
		printf("\nList is empty");
	} else {
		while(linked_list) {
			printf("\nID: %d", linked_list->id);
			linked_list = linked_list->next;
		}
	}
}

int remove_nth_from_end(Linked_List **linked_list, const int number)
{
	/* note this makes it 0-based */
	/* for 1-based, use number_tmp = number */
	int number_tmp = number+1;
	if(!linked_list) {
		printf("\nError. List is empty.");
		return IMPROPER_USAGE;
	}
	int count = 0;
	Linked_List **prev_node = NULL;
	Linked_List **tmp = linked_list;
	while(*tmp) {
		if(count < number_tmp) {
			++count;
		} else if(count == number_tmp) {
			prev_node = linked_list;
			++count;
		} else {
			prev_node = &(*prev_node)->next;
		} 
		tmp = &(*tmp)->next;
	}
	if(!prev_node) {
		printf("\nError. Asked for a number greater than the size of the list.\n");
		return IMPROPER_USAGE;
	}
	/* now, prev_node is pointing to correct spot */
	if((*prev_node)->next) {
		Linked_List *to_free = (*prev_node)->next;
		(*prev_node)->next = (*prev_node)->next->next;
		free(to_free);
	}
	return NO_ERROR;
}

int reverse_linked_list(Linked_List **linked_list)
{
	/*
		1) remove the node from tmp
		2) add at beginning to q
		3) doing until tmp becomes NULL
	*/
	Linked_List *tmp = *linked_list;
	Linked_List *q = NULL;
	Linked_List *r = NULL;
	while(tmp) {
		r = q;
		q = tmp;
		tmp = tmp->next;
		q->next = r;
	}
	*linked_list = q;
    return NO_ERROR;
}
