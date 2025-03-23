#include <stdio.h>
#include "linearstack.h"
#include "listsquene.h"
#include <stdlib.h>
#include <string.h>
int check(sqelink);
int main(int argc, char *argv[])
{
//创建小球存储队列
	sqelink lq = squene_create();
	if(lq == NULL)
	{
		printf("the ball storing squene creating fails!\n");
		return -1;
	}
//为队列放置27个小球：入队操作
   int i;
   for(i = 1; i <= 27; i++)
   {
        squene_en(lq, i);
   }

//创建一分钟、五分钟、一小时小球顺序栈
   sqstack *st_omin, *st_fmin, *st_ohour;
   st_omin = stack_create(4);
   st_fmin = stack_create(11);
   st_ohour = stack_create(11);
   if((st_omin == NULL)||(st_omin->data == NULL))
   {
	   printf("the omin ball volume creating fails!\n");
	   return -1;
   }

   if((st_fmin == NULL)||(st_fmin->data == NULL))
   {
	   printf("the fmin ball volume creating fails!\n");
	   return -1;
   }

   if((st_ohour == NULL)||(st_ohour->data == NULL))
   {
	   printf("the ohour ball volume creating fails!\n");
	   return -1;
   }

//计时开始
   int value;
   int min_t = 0;
   while(1)
   {
	   min_t++;
	  if(!squene_emptycheck(lq)) //从队列取球
	  {
		  value = squene_de(lq);
	  }
      if(stack_fullcheck(st_omin)) //当1分钟容器未装满四个球便将从队列取出来的球进行放置
      {
		  stack_push(st_omin, value);
      }else{ //1分钟容器装满四个球的情况
		  while(stack_emptycheck(st_omin)) //将1分钟容器中的四个球放回队列
		  {
			 squene_en(lq, stack_pop(st_omin)); 
		  }
		  //此时又分为两种情况：五分钟容器中已装满11个球和未装满11个球
		  if(stack_fullcheck(st_fmin)) //未装满11个球，将从队列取出来的球进行放置
		  {
			  stack_push(st_fmin, value);
		  }else{ //5分钟容器装满11个球的情况
			  while(stack_emptycheck(st_fmin)) //将5分钟容器中的11个球放回队列
			  { 
				  squene_en(lq, stack_pop(st_fmin));
			  }
			  //此时又分为两种情况：1小时容器中已装满11个球和未装满11个球
			  if(stack_fullcheck(st_ohour)) //未装满11个球，将从队列取出来的球进行放置
			  {
				  stack_push(st_ohour, value);
			  }else{ //1小时容器装满11个球的情况
				  while(stack_emptycheck(st_ohour)) //将1小时容器中的11个球放回队列
				  {
					  squene_en(lq, stack_pop(st_ohour));
				  }
				  squene_en(lq, value); //将从队列取出来的球放回队列
				  //顺序判断函数：当队列中球的顺序与首次计时前顺序相同时跳出循环
				  if(check(lq) == 1)
				  {
                     break;
				  }
			  }
		  }
	  }
   }
   printf("the total time is:%d\n", min_t);
   while(lq->head->next != NULL)
	{
		printf("de:%d\n", squene_de(lq));
	}
	return 0;
   }
   int check(sqelink lq)
   {
	   nodelink p;
	   p = lq->head->next;
	   while(p->next)
	   {
		   if(p->data < p->next->data)
		   {
			   p = p->next;
		   }else{
              return 0;
		   }
	   }
	   return 1;
   }
