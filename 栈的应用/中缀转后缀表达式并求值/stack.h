#pragma once
#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>
typedef char Elemtype;//�����ַ�
#define Maxsize 20
struct Stack
{
	Elemtype *data;
	int top;
};

void init_stack(Stack*& S)//��ʼ��ջ
{
	S = (Stack*)malloc(sizeof(Stack));
	S->data = (Elemtype*)malloc(sizeof(Elemtype) * Maxsize);
	S->top = -1;
	return;
}
bool if_full(Stack* S)//�ж�ջ�Ƿ�����
{
	if (S->top == Maxsize - 1)
	{
		return true;
	}
	return false;
}
bool if_empty(Stack* S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S->top == -1)
	{
		return true;
	}
	return false;
}
void push_stack(Stack*& S,Elemtype c)//��ջ
{
	if (if_full(S))
	{
		printf("ջ������\n");
		return;
	}
	S->top++;
	S->data[S->top] = c;
	return;
}
void get_stack(Stack* S, Elemtype& e)//��ȡջ��Ԫ��
{
	if (if_empty(S))
	{
		printf("ջΪ�գ�\n");
		return;
	}
	e = S->data[S->top];
	return;
}
void pop_stack(Stack*& S, Elemtype& e)//����Ԫ��
{
	if (if_empty(S))
	{
		//printf("ջΪ�գ�\n");
		return;
	}
	e = S->data[S->top];
	S->top--;
	return;
}
void destory_stack(Stack*& S)//����ջ
{
	free(S->data);
	free(S);
	return;
}
