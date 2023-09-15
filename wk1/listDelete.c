#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

// delete the first instance of node with 'value' from the linked list
// returns the head of the linked list after this is complete
struct node *listDelete(struct node *list, int value) {
	if (list == NULL) return NULL;

	if (list->value == value) {
		struct node *newHead = list->next;
		free(list);
		return newHead;
	}

	for (struct node *curr = list; curr->next != NULL; curr = curr->next) {
		if (curr->next->value == value) {
			struct node *tmp = curr->next->next;
			free(curr->next);
			curr->next = tmp;
			return list;
		}
	}

	return list;
}
