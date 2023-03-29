#pragma 
#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>
typedef  double Elemtype1;//�������
#define Maxsize 20
struct Stack1
{
	Elemtype1* data;
	int top;
};

void init_stack1(Stack1*& S)//��ʼ��ջ
{
	S = (Stack1*)malloc(sizeof(Stack1));
	S->data = (Elemtype1*)malloc(sizeof(Elemtype1) * Maxsize);
	S->top = -1;
	return;
}
bool if_full1(Stack1* S)//�ж�ջ�Ƿ�����
{
	if (S->top == Maxsize - 1)
	{
		return true;
	}
	return false;
}
bool if_empty1(Stack1* S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S->top == -1)
	{
		return true;
	}
	return false;
}
void push_stack1(Stack1*& S, Elemtype1 c)//��ջ
{
	if (if_full1(S))
	{
		printf("ջ������\n");
		return;
	}
	S->top++;
	S->data[S->top] = c;
	return;
}
void get_stack1(Stack1* S, Elemtype1& e)//��ȡջ��Ԫ��
{
	if (if_empty1(S))
	{
		printf("ջΪ�գ�\n");
		return;
	}
	e = S->data[S->top];
	return;
}
void pop_stack1(Stack1*& S, Elemtype1& e)//����Ԫ��
{
	if (if_empty1(S))
	{
		//printf("ջΪ�գ�\n");
		return;
	}
	e = S->data[S->top];
	S->top--;
	return;
}
void destory_stack1(Stack1*& S)//����ջ
{
	free(S->data);
	free(S);
	return;
}

