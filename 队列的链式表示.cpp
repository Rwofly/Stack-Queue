#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct Queue
{
	Node* front;//队头指针
	Node* rear;//队尾指针
};
void init_queue(Queue*);//初始化一个队列
void enter_queue(Queue*);//入队列，即链表创建的尾插法
void delete_queue(Queue*);//出队列
void travel_queue(Queue*);//遍历并输出队列
int main()
{
	Queue Q;
	init_queue(&Q);
	delete_queue(&Q);//删除空队列中的元素
	travel_queue(&Q);//遍历空队列中的元素
	enter_queue(&Q);
	enter_queue(&Q);
	enter_queue(&Q);
	enter_queue(&Q);
	cout << "入队列一个元素后的队列为：" << endl;
	travel_queue(&Q);
	delete_queue(&Q);
	cout << "出队列一个元素后的队列为：" << endl;
	travel_queue(&Q);
	return 0;
}
void init_queue(Queue* Q)
{
	Q->front = Q->rear = new Node;//生成新节点作为头结点，队头和队尾指针指向这个节点
	Q->front->next = NULL;//头结点指针域为空
	return;
}
void enter_queue(Queue* Q)
{
	int m;
	Node* p = new Node;//为入队节点分配空间
	cout << "请输入入队节点的值：";
	cin >> m;
	p->data = m;
	p->next = NULL;
	Q->rear->next = p;//将新节点插入到队尾
	Q->rear = p;//修改队尾指针，与尾插法类似
	return;
}
void delete_queue(Queue* Q)
{
	if (Q->front == Q->rear)//判断队列是否为空
	{
		cout << "队列为空，无法弹出队列中的元素"<<endl;
		return;
	}
	Node* p=Q->front->next;//p指向队头元素
	Q->front->next = p->next;//修改头结点的指针域
	if (Q->rear == p)//如果是最后一个元素被删，队尾指针指向头结点
	{
		Q->rear = Q->front;
	}
	delete p;//释放原队头元素的空间
	return;
}
void travel_queue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		cout << "队列为空,无法遍历队列"<<endl;
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
