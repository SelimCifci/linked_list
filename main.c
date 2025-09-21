#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node_t;

node_t *iterate(node_t *head, int index) {
    node_t *current = head;

    int current_index = 1;

    while (current != NULL && current_index < index) {
        current = current->link;
    }

    return current;
}

int main() {
    int *ptr = (int *)malloc(0 * sizeof(int));

    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->data = 5;
    head->link = (node_t *)malloc(sizeof(node_t));
    head->link->data = 8;
    head->link->link = NULL;

    printf("%d\n", iterate(head, 1)->data);

    free(ptr);
    return 0;
}
