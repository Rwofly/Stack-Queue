#include<iostream>
#define Max 100//顺序栈存储空间初始分配量
using namespace std;
struct Stack
{
	int* top;//栈顶指针
	int* base;//栈底指针
	int maxsize;//栈可用最大容量
};
void init_stack(Stack* S);//顺序栈的初始化
void push_stack(Stack* S, int n);//入栈操作
void travel_stack(Stack* S);//遍历并输出栈中的元素
void pop_stack(Stack* S);//出栈
int main()
{
	Stack S;
	init_stack(&S);//传入地址
	push_stack(&S, 1);
	push_stack(&S, 2);
	push_stack(&S, 3);
	push_stack(&S, 4);
	push_stack(&S, 5);
	push_stack(&S, 6);
	cout << "栈中元素有：" << endl;
	travel_stack(&S);
	pop_stack(&S);
	pop_stack(&S);
	cout << "出栈后元素有：" << endl;
	travel_stack(&S);
	return 0;
}
void init_stack(Stack* S)
{
	S->base = new int[Max];//给顺序栈动态分配一个最大容量为Max的数组
	if (!S->base)
	{
		cout << "内存分配失败！结束程序！";
		exit(-1);
	}
	S->top = S->base;//top初始化为base表示为空栈
	S->maxsize = Max;
	return;
}
void push_stack(Stack* S, int n)
{
	if (S->top - S->base == S->maxsize)
	{
		cout << "栈满" << endl;
		return;
	}
	S->top++;
	*S->top = n;
	return;
}
void travel_stack(Stack* S)
{
	int* p = S->top;
	while (p != S->base)
	{
		cout << *p << " ";
		p--;
	}
	cout << endl;
	return;
}
void pop_stack(Stack* S)
{
	if (S->top == S->base)
	{
		cout << "空栈" << endl;
		return;
	}
	S->top--;
	return;
}