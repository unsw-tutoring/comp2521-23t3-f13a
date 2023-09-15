#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
	int size;
	struct node *tail;
};

// delete the first instance of node with 'value' from the linked list
void listDelete(struct list *list, int value) {
	if (list == NULL) return;
	if (list->head == NULL) return;
	if (list->head->value == value) {
		struct node *newHead = list->head->next;
		free(list->head);
		list->head = newHead;
		return;
	}

	for (struct node *curr = list->head; curr->next != NULL;
	     curr = curr->next) {
		if (curr->next->value == value) {
			struct node *tmp = curr->next->next;
			free(curr->next);
			curr->next = tmp;
			return;
		}
	}

	return;
}
