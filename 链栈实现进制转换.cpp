#include<iostream>
using namespace std;
 struct Node
 {
 	int data;
 	struct Node* next;
 };
 struct Stack
 {
 	struct Node* top;
 	struct Node* bottom;
 };
 void init_stack(Stack* S);//初始化栈
 bool empty_stack(Stack* S);//判断栈是否为空
 void input_stack(Stack* S,int n);//入栈
 void pop_stack(Stack* S);//出栈 
 void transform(Stack* S,int n,int k);//进制转换 
int main()
{
	Stack S;
	init_stack(&S);
	int n,k;
	cout<<"请输入一个大于零的十进制数字：";
	cin>>n;
	cout<<"请输入将该数字转换成的进制：";
	cin>>k;
	while(n>0)
	{
		transform(&S,n,k);
		cout<<"请输入一个大于零的十进制数字：";
	    cin>>n;
	    cout<<"请输入将该数字转换成的进制：";
	    cin>>k;
	}
	return 0;
}
void init_stack(Stack* S)
{
	S->top=new Node;
	S->bottom=S->top;
	S->top->next=NULL;//栈底与栈顶指针指向为空 
	return;
} 
bool empty_stack(Stack* S)
{
	if(S->top==S->bottom)
	{
		return true;
	}else
	{
		return false;
	}
}
void input_stack(Stack* S,int n)
{
	Node* Val=S->bottom;
	Node* pNew=new Node;
	pNew->data=n;
	pNew->next=S->top;
	S->top=pNew;
	return;
}
void pop_stack(Stack* S)
{
	if(empty_stack(S))
	{
		cout<<"栈为空！"<<endl;
		return;
	}
	Node* temp;
	while(S->top!=S->bottom)
	{
		temp=S->top;
		cout<<temp->data<<" ";
		S->top=temp->next;
		delete temp;
	}
	cout<<endl;
	return;
}
void transform(Stack* S,int n,int k)
{
	int num;
	int t=n;
	while(n>0)
	{
		num=n%k;
		n=n/k;
		input_stack(S,num);
	}
	cout<<"数字 "<<t<<" 转换成 "<<k<<" 进制后为："<<endl;
	pop_stack(S);
}
