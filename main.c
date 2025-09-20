#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};


int main() {
    int *ptr = (int *)malloc(0 * sizeof(int));

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 8;
    current->link = NULL;

    head->link = current;

    printf("%d\n", head->data);
    return 0;

    free(ptr);
}
