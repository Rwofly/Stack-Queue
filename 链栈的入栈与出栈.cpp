#include<iostream>
using namespace std;
struct Node//ջԪ�� 
{
	int data;
	struct Node* next;
};
struct Stack//�ṹ��洢ջ����ջ��ָ�� 
{
	Node* top;
	Node* bottom;
};
void init_stack(Stack* S);//��ʼ��ջ ��������һ����ջ��ջ��ָ��Ϊ�ա� 
void input_stack(Stack* S,int n);//��ջ���� 
void travel_stack(Stack* S);//���������ջ
bool empty(Stack* S);//�ж�ջ�Ƿ�Ϊ��
void pop_stack(Stack* S);//��ջ���� 
int main()
{
	Stack S;
	init_stack(&S);
	input_stack(&S, 1);
	input_stack(&S, 2);
	input_stack(&S, 3);
	cout << "ջ������Ԫ��Ϊ��" << endl;
	travel_stack(&S);
	pop_stack(&S);
	cout << "��ջ���Ԫ���У�" << endl;
	travel_stack(&S);
	return 0;
}
void init_stack(Stack* S)
{
	S->top = new Node;
	S->bottom = S->top;
	S->bottom->next = NULL;//ջ����ջ��ָ�붼ָ���
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
		cout << "ջΪ��ջ";
		return;
	}
	else
	{
		Node* p = S->top;//�����ͷ�ɾ��Ԫ�ص��ڴ�
		S->top = p->next;
		delete p;//�ͷ��ڴ�
	}
	return;
}
