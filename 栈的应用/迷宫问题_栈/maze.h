#pragma once
//定义一个迷宫，数字1表示围墙，0表示通道
//为了方便算法，一般在迷宫外围加一条围墙，则数组的行数与列数均加2
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
	int i;//储存方块的行号
	int j;//储存方块的列号
	int di;//di是可以走到下一个相邻可走方块的方位号
};
struct Stack//栈
{
	Box* data;
	int top;
};
void init_stack(Stack*& S)//初始化栈
{
	S = (Stack*)malloc(sizeof(Stack));
	S->data = (Box*)malloc(sizeof(Box) * Maxsize);
	S->top = -1;
	return;
}
bool if_full(Stack* S)//判断栈是否为满
{
	if (S->top == Maxsize - 1)
	{
		return true;
	}
	return false;
}
bool if_empty(Stack* S)//判断栈是否为空
{
	if (S->top == -1)
	{
		return true;
	}
	return false;
}
void push_stack(Stack*& S, Box e)//入栈
{
	if (if_full(S))
	{
		return;//栈已满，直接返回
	}
	S->top++;
	S->data[S->top].i = e.i;
	S->data[S->top].j = e.j;
	S->data[S->top].di = e.di;
	return;
}
void get_stack(Stack*& S, Box& e)//取栈顶元素
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
void pop_stack(Stack*& S, Box& e)//弹出栈元素
{
	if (if_empty(S))
	{
		return;//栈已空，直接返回
	}
	e.di = S->data[S->top].di;
	e.i = S->data[S->top].i;
	e.j = S->data[S->top].j;
	S->top--;
	return;
}
void destory_stack(Stack*& S)//销毁栈
{
	free(S->data);
	free(S);
	return;
}

