#include<iostream>
#define Max 100//˳��ջ�洢�ռ��ʼ������
using namespace std;
struct Stack
{
	int* top;//ջ��ָ��
	int* base;//ջ��ָ��
	int maxsize;//ջ�����������
};
void init_stack(Stack* S);//˳��ջ�ĳ�ʼ��
void push_stack(Stack* S, int n);//��ջ����
void travel_stack(Stack* S);//���������ջ�е�Ԫ��
void pop_stack(Stack* S);//��ջ
int main()
{
	Stack S;
	init_stack(&S);//�����ַ
	push_stack(&S, 1);
	push_stack(&S, 2);
	push_stack(&S, 3);
	push_stack(&S, 4);
	push_stack(&S, 5);
	push_stack(&S, 6);
	cout << "ջ��Ԫ���У�" << endl;
	travel_stack(&S);
	pop_stack(&S);
	pop_stack(&S);
	cout << "��ջ��Ԫ���У�" << endl;
	travel_stack(&S);
	return 0;
}
void init_stack(Stack* S)
{
	S->base = new int[Max];//��˳��ջ��̬����һ���������ΪMax������
	if (!S->base)
	{
		cout << "�ڴ����ʧ�ܣ���������";
		exit(-1);
	}
	S->top = S->base;//top��ʼ��Ϊbase��ʾΪ��ջ
	S->maxsize = Max;
	return;
}
void push_stack(Stack* S, int n)
{
	if (S->top - S->base == S->maxsize)
	{
		cout << "ջ��" << endl;
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
		cout << "��ջ" << endl;
		return;
	}
	S->top--;
	return;
}