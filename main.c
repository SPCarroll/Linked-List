#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

const int SIZE_OF_LIST = 20;

int main()
{
	Linked_List *linked_list = NULL;
	int error_code;
	int i;
	for(i = 0; i < SIZE_OF_LIST; ++i) {
		error_code = add_linked_list(&linked_list, i);
		if(error_code) {
			fprintf(stderr, "\nError. Adding item (%d) failed.\n", i);
			return EXIT_FAILURE;
		}
	}
	print_linked_list(linked_list);
	printf("\nReversing list...");
	error_code = reverse_linked_list(&linked_list);
	if(error_code) {
		fprintf(stderr, "\nError. Reversing list failed.\n");
	}
	print_linked_list(linked_list);
	printf("\nRemoving 3rd node from end of list...");
	error_code = remove_nth_from_end(&linked_list, 3);
	if(error_code) {
		fprintf(stderr, "\nError. Removing nth node list failed.\n");
	}
	print_linked_list(linked_list);
	destroy_linked_list(linked_list);
	return EXIT_SUCCESS;
}
