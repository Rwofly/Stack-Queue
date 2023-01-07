#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct Queue
{
	Node* front;//��ͷָ��
	Node* rear;//��βָ��
};
void init_queue(Queue*);//��ʼ��һ������
void enter_queue(Queue*);//����У�����������β�巨
void delete_queue(Queue*);//������
void travel_queue(Queue*);//�������������
int main()
{
	Queue Q;
	init_queue(&Q);
	delete_queue(&Q);//ɾ���ն����е�Ԫ��
	travel_queue(&Q);//�����ն����е�Ԫ��
	enter_queue(&Q);
	enter_queue(&Q);
	enter_queue(&Q);
	enter_queue(&Q);
	cout << "�����һ��Ԫ�غ�Ķ���Ϊ��" << endl;
	travel_queue(&Q);
	delete_queue(&Q);
	cout << "������һ��Ԫ�غ�Ķ���Ϊ��" << endl;
	travel_queue(&Q);
	return 0;
}
void init_queue(Queue* Q)
{
	Q->front = Q->rear = new Node;//�����½ڵ���Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ������ڵ�
	Q->front->next = NULL;//ͷ���ָ����Ϊ��
	return;
}
void enter_queue(Queue* Q)
{
	int m;
	Node* p = new Node;//Ϊ��ӽڵ����ռ�
	cout << "��������ӽڵ��ֵ��";
	cin >> m;
	p->data = m;
	p->next = NULL;
	Q->rear->next = p;//���½ڵ���뵽��β
	Q->rear = p;//�޸Ķ�βָ�룬��β�巨����
	return;
}
void delete_queue(Queue* Q)
{
	if (Q->front == Q->rear)//�ж϶����Ƿ�Ϊ��
	{
		cout << "����Ϊ�գ��޷����������е�Ԫ��"<<endl;
		return;
	}
	Node* p=Q->front->next;//pָ���ͷԪ��
	Q->front->next = p->next;//�޸�ͷ����ָ����
	if (Q->rear == p)//��������һ��Ԫ�ر�ɾ����βָ��ָ��ͷ���
	{
		Q->rear = Q->front;
	}
	delete p;//�ͷ�ԭ��ͷԪ�صĿռ�
	return;
}
void travel_queue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		cout << "����Ϊ��,�޷���������"<<endl;
		return;
	}
	Node* p = Q->front->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
