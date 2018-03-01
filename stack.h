#define STACK_TYPE_INT 1
#define STACK_TYPE_CHAR 2

typedef struct list {
    int *data;
    char *letter;
    int type; /* 1=integer, 2=character */
    struct list* next;
} Multi_Purpose_List;

typedef struct stack_s {
    Multi_Purpose_List *head;
    int type;
} Stack;

Stack* stack_init(int);
void stack_push(Stack *, void *);

