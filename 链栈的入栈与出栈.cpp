#include<iostream>
using namespace std;
struct Node//栈元素 
{
	int data;
	struct Node* next;
};
struct Stack//结构体存储栈顶与栈底指针 
{
	Node* top;
	Node* bottom;
};
void init_stack(Stack* S);//初始化栈 。即设置一个空栈，栈顶指针为空。 
void input_stack(Stack* S,int n);//入栈操作 
void travel_stack(Stack* S);//遍历并输出栈
bool empty(Stack* S);//判断栈是否为空
void pop_stack(Stack* S);//出栈操作 
int main()
{
	Stack S;
	init_stack(&S);
	input_stack(&S, 1);
	input_stack(&S, 2);
	input_stack(&S, 3);
	cout << "栈内所有元素为：" << endl;
	travel_stack(&S);
	pop_stack(&S);
	cout << "出栈后的元素有：" << endl;
	travel_stack(&S);
	return 0;
}
void init_stack(Stack* S)
{
	S->top = new Node;
	S->bottom = S->top;
	S->bottom->next = NULL;//栈顶与栈底指针都指向空
	return;
}
void input_stack(Stack* S, int n)
{
	Node* p = new Node;
	p->data = n;
	p->next = S->top;
	S->top = p;
	return;
}
void travel_stack(Stack* S)
{
	Node* p = S->top;
	while (p->next != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
bool empty(Stack* S)
{
	if (S->bottom == S->top)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void pop_stack(Stack* S)
{
	if (empty(S))
	{
		cout << "栈为空栈";
		return;
	}
	else
	{
		Node* p = S->top;//便于释放删除元素的内存
		S->top = p->next;
		delete p;//释放内存
	}
	return;
}
