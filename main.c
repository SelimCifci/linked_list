#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node_t;

node_t *iterate(node_t *head, int index) {
    if (head == NULL) return NULL;

    node_t *current = head;

    int current_index = 0;

    while (current->link != NULL && current_index < index) {
        current = current->link;
        current_index++;
    }

    return current;
}

void add_node(node_t **head, int index, int data) {
    node_t *current = iterate(*head, index);

    if (index == 0) {
        node_t *new = malloc(sizeof(node_t));

        new->data = data;
        new->link = *head;
        *head = new;
    }
    else {
        node_t *previous = iterate(*head, index-1);
        node_t *new = malloc(sizeof(node_t));

        new->data = data;
        
        if (previous->link == NULL) {
            new->link = NULL;
        }
        else {
            new->link = current;
        }

        previous->link = new;
    }
}

void pop_node(node_t **head, int index) {
    node_t *current = iterate(*head, index);

    if (index == 0) {
        *head = current->link;
    }
    else {
        node_t *previous = iterate(*head, index-1);
        previous->link = current->link;
    }
    free(current);
}

node_t *convert(node_t *head, int arr[], int len) {
    head->data = arr[0];
    head->link = NULL;

    for (int i = 1; i < len; i++) {
        add_node(&head, i, arr[i]);
    }

    return head;
}

void print(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
}

void free_list(node_t *head) {
    node_t *current = head;
    
    while (current != NULL) {
        node_t *next = current->link;
        free(current);
        current = next;
    }
}

int main() {
    node_t *head = malloc(sizeof(node_t));

    int arr[] = {5,8,4,1,3,2};
    int length = sizeof(arr)/sizeof(arr[0]);

    convert(head, arr, length);

    print(head);

    free_list(head);
    return 0;
}
