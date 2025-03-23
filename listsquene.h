typedef int data_t;
/*插入节点的结构体定义及声明*/
typedef struct node{
    data_t data;
    struct node *next;
} nodestruct, * nodelink;
/*队头队尾指针结构体*/
typedef struct{
    nodelink head;
    nodelink rear;
} sqestruct, * sqelink;
sqelink squene_create();
int squene_en(sqelink, data_t);
data_t squene_de(sqelink);
int squene_emptycheck(sqelink);
sqelink squene_free(sqelink);
int squene_clear(sqelink);
