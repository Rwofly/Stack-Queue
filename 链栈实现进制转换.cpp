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
 void init_stack(Stack* S);//��ʼ��ջ
 bool empty_stack(Stack* S);//�ж�ջ�Ƿ�Ϊ��
 void input_stack(Stack* S,int n);//��ջ
 void pop_stack(Stack* S);//��ջ 
 void transform(Stack* S,int n,int k);//����ת�� 
int main()
{
	Stack S;
	init_stack(&S);
	int n,k;
	cout<<"������һ���������ʮ�������֣�";
	cin>>n;
	cout<<"�����뽫������ת���ɵĽ��ƣ�";
	cin>>k;
	while(n>0)
	{
		transform(&S,n,k);
		cout<<"������һ���������ʮ�������֣�";
	    cin>>n;
	    cout<<"�����뽫������ת���ɵĽ��ƣ�";
	    cin>>k;
	}
	return 0;
}
void init_stack(Stack* S)
{
	S->top=new Node;
	S->bottom=S->top;
	S->top->next=NULL;//ջ����ջ��ָ��ָ��Ϊ�� 
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
		cout<<"ջΪ�գ�"<<endl;
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
	cout<<"���� "<<t<<" ת���� "<<k<<" ���ƺ�Ϊ��"<<endl;
	pop_stack(S);
}
