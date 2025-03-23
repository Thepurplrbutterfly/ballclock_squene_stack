#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linearstack.h"

/*顺序栈创建函数*/
sqstack *stack_create(int len)
{
// 内存分配
   sqstack *S=(sqstack *)malloc(sizeof(sqstack));
   S->data=(data_t *)malloc(sizeof(data_t)*len);
// 判断内存分配是否成功
   if(S==NULL)
   {
      printf("the memory assigning failed!\n");
      return NULL;
   }
   if(S->data==NULL)
   {
      printf("the memory assigning of data failed!\n");
      return NULL;
   }
// 结构体内部参数初始化
   memset(S->data, 0, sizeof(data_t)*len);
   S->maxlen=len;
   S->top=-1;
   printf("maxlen=%d, top=%d\n", S->maxlen, S->top);
   return S;
}

/*入栈函数*/
int stack_push(sqstack *S, data_t value)
{
    if(S==NULL)
	{
      printf("the memory assigning failed!\n");
      return -1;
   }
   if(S->data==NULL)
   {
      printf("the memory assigning of data failed!\n");
      return -1;
   }
//判断栈内是否已满
   printf("%d-%d\n",S->top, S->maxlen-1);
   if(S->top==S->maxlen-1)
   {
      printf("the stack is full!\n");
	  return -1;
   }
//入栈操作
   S->top++;
   S->data[S->top]=value;
   return 0;
}

/*查看栈顶函数*/
int stack_topcheck(sqstack *S, data_t *p)
{ 
    if(S==NULL)
	{
      printf("the memory assigning failed!\n");
      return -1;
   }
   if(S->data==NULL)
   {
      printf("the memory assigning of data failed!\n");
      return -1;
   }
//利用指针传递将栈顶元素赋值给性参指针p
  *p = S->data[S->top];
  printf("*p=%d\n",*p);
  return S->top;
}

/*出栈函数*/
data_t stack_pop(sqstack *S)
{
    if(S==NULL)
	{
      printf("the memory assigning failed!\n");
      return -1;
   }
   if(S->data==NULL)
   {
      printf("the memory assigning of data failed!\n");
      return -1;
   }
//查看栈是否为空
   if(S->top==-1)
   {
     printf("the stack is empty!\n");
     return -1;
   }
   S->top--;
   return S->data[S->top+1];
}

/*满栈判断函数*/
int stack_fullcheck(sqstack *S)
{
    if(S==NULL)
	{
      printf("the memory assigning failed!\n");
	  return -1;
	}
     return (S->top==S->maxlen-1?0:1);
}

/*空栈判断函数*/
int stack_emptycheck(sqstack *S)
{
    if(S==NULL)
	{
      printf("the memory assigning failed!\n");
	  return -1;
	}
     return (S->top==-1?0:1);
}

/*栈清除函数*/
int stack_clear(sqstack *S)
{
    if(S==NULL)
	{
      printf("the memory assigning failed!\n");
	  return -1;
	}
	S->top=-1;
	return 0;
}

/*栈空间释放函数*/
int stack_memroyfree(sqstack *S)
{
   if(S==NULL)
   {
     printf("the memory assigning failed\n");
     return -1;
   }
   if(S->data!=NULL)
   {
     free(S->data);
   }
   free(S);
   return 0;
}
