#pragma 
#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>
typedef  double Elemtype1;//´æ·ÅÊý×Ö
#define Maxsize 20
struct Stack1
{
	Elemtype1* data;
	int top;
};

void init_stack1(Stack1*& S)//³õÊ¼»¯Õ»
{
	S = (Stack1*)malloc(sizeof(Stack1));
	S->data = (Elemtype1*)malloc(sizeof(Elemtype1) * Maxsize);
	S->top = -1;
	return;
}
bool if_full1(Stack1* S)//ÅÐ¶ÏÕ»ÊÇ·ñÒÑÂú
{
	if (S->top == Maxsize - 1)
	{
		return true;
	}
	return false;
}
bool if_empty1(Stack1* S)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	if (S->top == -1)
	{
		return true;
	}
	return false;
}
void push_stack1(Stack1*& S, Elemtype1 c)//½øÕ»
{
	if (if_full1(S))
	{
		printf("Õ»ÒÑÂú£¡\n");
		return;
	}
	S->top++;
	S->data[S->top] = c;
	return;
}
void get_stack1(Stack1* S, Elemtype1& e)//»ñÈ¡Õ»¶¥ÔªËØ
{
	if (if_empty1(S))
	{
		printf("Õ»Îª¿Õ£¡\n");
		return;
	}
	e = S->data[S->top];
	return;
}
void pop_stack1(Stack1*& S, Elemtype1& e)//µ¯³öÔªËØ
{
	if (if_empty1(S))
	{
		//printf("Õ»Îª¿Õ£¡\n");
		return;
	}
	e = S->data[S->top];
	S->top--;
	return;
}
void destory_stack1(Stack1*& S)//Ïú»ÙÕ»
{
	free(S->data);
	free(S);
	return;
}

