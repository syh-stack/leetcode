#include "stdio.h"
#include "stdlib.h"
/*使用两个栈实现队列
 *构造两种新的数据结构：stack queue
 *stack具有的功能：入栈和出栈
 *queue具有的功能：入队和出队
 *
 * */
#define MAX_SIZE 10 //队列元素最多值
typedef struct stack
{
	int DATA[MAX_SIZE];
	int TOP;
}STACK;

typedef struct queue
{
	STACK stack_A;
	STACK stack_B;
	int last_elem;	
}QUEUE;

	int last_elem;
/*压栈
 *如果栈已满，则直接返回
 *未满则入栈并返回自身
 * */
int  stack_push(STACK* S,int data)
{
	if(S->TOP==(MAX_SIZE-1))
	{
	
		printf("this stack is full，cannot to push");
		return -1 ;
	}
	S->DATA[++S->TOP]=data;
	return 0;
}

/*弹栈
 *如果栈满，返回-1并报告错误
 *
 * */
int stack_pop(STACK* S)
{
	if(S->TOP == -1)
	{
		printf("this stack is empty，cannot to pop");
		return -1 ;
	}
	return S->DATA[S->TOP--];
}

/*出队列操作
 *判断stack_B是否为空？不为空，直接pop B
 *为空判断A是否为空？不为空，a数据给b
 *否则报错
 * */
int queue_pop(STACK* pa,STACK* pb)
{ 
	int temp;
	if(pb->TOP==-1)
	{
		if(pa->TOP == -1)
		{
			printf("这是空队列,无法进行出队操作！！！\r\n");
			return 0 ;
		}
		else
		{
			while(pa->TOP >=0 )
			{	
				temp = stack_pop(pa);
				stack_push(pb,temp);
				printf("正在入队......\r\n");
			}
			temp=stack_pop(pb);
			printf("当前出队元素为：%d\r\n",temp);
		}
	}
	else
	{	temp=stack_pop(pb);
		printf("当前出队元素为：%d 栈A状态：%d 栈B状态：%d\r\n",temp,pa->TOP,pb->TOP);
	}
	return temp;

}

/*入队列操作
 *入队使用stack_A的压栈操作
 *压栈，并对栈顶元素更新
 * */
int queue_push(STACK* pa , int elem)
{		
	
	stack_push(pa,elem);
	last_elem = elem;
	return elem;

}

int main()
{
	
	/*变量定义*/
	STACK stack_A;
	STACK stack_B;
	STACK* pa;
	STACK* pb;
	pa = &stack_A;
	pb = &stack_B;

	stack_A.TOP =-1;
	stack_B.TOP =-1;
	queue_push(pa,10);
	queue_pop(pa,pb);
	queue_pop(pa,pb);
	queue_push(pa,20);
	queue_push(pa,30);
	queue_pop(pa,pb);
	queue_pop(pa,pb);
	queue_pop(pa,pb);

//	int elem=61514;
//	STACK stack_A ;
//	STACK* p;
//	p = &stack_A;
//	p->TOP = -1;
//	stack_push(p,20);
//	stack_push(p,30);
//	stack_push(p,40);
//	elem = stack_pop(p);
//	elem = stack_pop(p);
//	printf("%d  %d\r\n",elem,p->TOP);
//	stack_push(p,50);
//	stack_push(p,60);
//	stack_pop(p);
//	stack_pop(p);
//	elem=stack_pop(p);
//	printf("%d  %d\r\n",elem,p->TOP);
	return 0 ;
}
