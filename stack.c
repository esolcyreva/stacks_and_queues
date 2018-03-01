#include "stack.h"
#include <stdlib.h>

void list_remove(Multi_Purpose_List **head, void *value, int type) {
    Multi_Purpose_List *temp = head, *del = NULL;
    if (type == STACK_TYPE_INT) {
        *value = *temp->data;
    } else {
        *value = *temp->letter;
    }
    del = temp;
    temp = temp->next;
    *head = temp;
    free(del);
    return;

}

void list_push(Multi_Purpose_List **head, void *value, int type) {
    Multi_Purpose_List *temp = *head;
    char *letter;
    int *data;
    Multi_Purpose_List *n = malloc(sizeof(Multi_Purpose_List));
    if (type == STACK_TYPE_INT) {
        data = (int *)value;
        n->data = data;
        n->letter = NULL;
    } else {
        letter = (char *)value;
        n->letter = letter;
        n->data = NULL;
    }

    if (temp == NULL) {
        temp = n;
    } else {
        n->next = temp;
        temp = n;
    }
    *head = temp;
    return;
}

Stack* stack_init(int type)
{
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->type = type;
    return s;
}

void stack_push(Stack *s, void *value) {
    if(s == NULL) {
        printf("Stack not initialized");
        exit(0);
    }
    list_push(&s->head, value, s->type);
}

void stack_pop(Stack *s, void *value) {
    if(s == NULL) {
        printf("Stack not initialized");
        exit(0);
    }
    list_remove(&s->head, value, s->type);
}
