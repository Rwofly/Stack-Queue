#pragma once
//����һ���Թ�������1��ʾΧǽ��0��ʾͨ��
//Ϊ�˷����㷨��һ�����Թ���Χ��һ��Χǽ�����������������������2
#include<malloc.h>
#define Maxsize 50
int mg[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};
struct Box
{
	int i;//���淽����к�
	int j;//���淽����к�
	int di;//di�ǿ����ߵ���һ�����ڿ��߷���ķ�λ��
};
struct Stack//ջ
{
	Box* data;
	int top;
};
void init_stack(Stack*& S)//��ʼ��ջ
{
	S = (Stack*)malloc(sizeof(Stack));
	S->data = (Box*)malloc(sizeof(Box) * Maxsize);
	S->top = -1;
	return;
}
bool if_full(Stack* S)//�ж�ջ�Ƿ�Ϊ��
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
void push_stack(Stack*& S, Box e)//��ջ
{
	if (if_full(S))
	{
		return;//ջ������ֱ�ӷ���
	}
	S->top++;
	S->data[S->top].i = e.i;
	S->data[S->top].j = e.j;
	S->data[S->top].di = e.di;
	return;
}
void get_stack(Stack*& S, Box& e)//ȡջ��Ԫ��
{
	if (if_empty(S))
	{
		return;
	}
	e.di = S->data[S->top].di;
	e.i = S->data[S->top].i;
	e.j = S->data[S->top].j;
	return;
}
void pop_stack(Stack*& S, Box& e)//����ջԪ��
{
	if (if_empty(S))
	{
		return;//ջ�ѿգ�ֱ�ӷ���
	}
	e.di = S->data[S->top].di;
	e.i = S->data[S->top].i;
	e.j = S->data[S->top].j;
	S->top--;
	return;
}
void destory_stack(Stack*& S)//����ջ
{
	free(S->data);
	free(S);
	return;
}

