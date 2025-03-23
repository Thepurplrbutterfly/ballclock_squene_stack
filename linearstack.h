typedef int data_t;
typedef struct{
    data_t *data;
	int maxlen;
	int top;
} sqstack;

sqstack *stack_create(int len);
int stack_push(sqstack *S, data_t value);
int stack_topcheck(sqstack *S, data_t *p);
data_t stack_pop(sqstack *S);
int stack_fullcheck(sqstack *S);
int stack_emptycheck(sqstack *S);
int stack_clear(sqstack *S);
int stack_memroyfree(sqstack *S);
