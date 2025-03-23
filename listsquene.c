#include <stdio.h>
#include "listsquene.h"
#include <stdlib.h>
#include <string.h>
/*队列创建函数*/
sqelink squene_create()
{
//节点结构体创建
    sqelink S = (sqelink)malloc(sizeof(sqestruct));
    if(S==NULL)
    {
        printf("the memory assigning failed!\n");
        return NULL;
    }
//对头队尾指针结构体创建
    S->head = S->rear = (nodelink)malloc(sizeof(nodelink));
    if(S->head==NULL)
    {
        printf("the memeory assigning failed!\n");
        return NULL;
    }
//用队头指针代替普通链表中的H指针
    S->head->data = 0;
    S->head->next = NULL;
    return S;
}

/*入队函数*/
int squene_en(sqelink S, data_t value)
{
    if(S==NULL)
    {
        printf("the memory assigning failed!\n");
        return -1;
    }
    nodelink q = (nodelink)malloc(sizeof(nodestruct));
    if(q==NULL)
    {
        printf("the node creation failed!\n");
        return -1;
    }
    q->data = value;
    q->next = NULL;
//按FIFO的规则进行头部插入
    S->rear->next = q;
    S->rear = q;
    return 0;
}

/*出队函数*/
data_t squene_de(sqelink S)
{
    if(S==NULL)
    {
        printf("the memory assigning failed!\n");
        return -1;
    }
//按FIFO的规则进行删除
nodelink q = S->head;
S->head = q->next;
free(q);
q=NULL;
return (S->head->data);
}

/*队列空判断*/
int squene_emptycheck(sqelink S)
{
    if(S==NULL)
    {
        printf("the memory assigning failed!\n");
        return -1;
    }
    return ((S->rear == S->head)?1:0);
}

/*队列内存释放*/
sqelink squene_free(sqelink S)
{
    if(S==NULL)
    {
        printf("the memory assigning failed!\n");
        return NULL;
    }
    nodelink q;
    while(S->head)
    {
        q = S->head;
        S->head = q->next;
        printf("free:%d\n", q->data);
        free(q);
        q = NULL;
    }
    free(S);
    S=NULL;
    return S;
}

/*队列清空函数*/
int squene_clear(sqelink S)
{
    if(S==NULL)
    {
        printf("the memory assigning failed!\n");
        return -1;
    }
    nodelink q;
    while(S->head->next)
    {
        q = S->head;
        S->head = q->next;
        printf("clear:%d\n", q->data);
        free(q);
        q = NULL;
    }
    return 0;
}
