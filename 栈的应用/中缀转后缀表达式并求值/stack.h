#pragma once
#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>
typedef char Elemtype;//±£´æ×Ö·û
#define Maxsize 20
struct Stack
{
	Elemtype *data;
	int top;
};

void init_stack(Stack*& S)//³õÊ¼»¯Õ»
{
	S = (Stack*)malloc(sizeof(Stack));
	S->data = (Elemtype*)malloc(sizeof(Elemtype) * Maxsize);
	S->top = -1;
	return;
}
bool if_full(Stack* S)//ÅÐ¶ÏÕ»ÊÇ·ñÒÑÂú
{
	if (S->top == Maxsize - 1)
	{
		return true;
	}
	return false;
}
bool if_empty(Stack* S)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	if (S->top == -1)
	{
		return true;
	}
	return false;
}
void push_stack(Stack*& S,Elemtype c)//½øÕ»
{
	if (if_full(S))
	{
		printf("Õ»ÒÑÂú£¡\n");
		return;
	}
	S->top++;
	S->data[S->top] = c;
	return;
}
void get_stack(Stack* S, Elemtype& e)//»ñÈ¡Õ»¶¥ÔªËØ
{
	if (if_empty(S))
	{
		printf("Õ»Îª¿Õ£¡\n");
		return;
	}
	e = S->data[S->top];
	return;
}
void pop_stack(Stack*& S, Elemtype& e)//µ¯³öÔªËØ
{
	if (if_empty(S))
	{
		//printf("Õ»Îª¿Õ£¡\n");
		return;
	}
	e = S->data[S->top];
	S->top--;
	return;
}
void destory_stack(Stack*& S)//Ïú»ÙÕ»
{
	free(S->data);
	free(S);
	return;
}
