#include<iostream>
using namespace std;
int n; 
struct Queue
{
	int *pbase;
	int front;
	int rear;
};
void init_queue(Queue*);//初始化队列
void enter_queue(Queue*,int);//入队
void output_queue(Queue*);//出队
bool empty_queue(Queue*);//判断队列是否为空
bool full_queue(Queue*);//判断队列是否已满
void travel_queue(Queue*);//遍历队列 
int main()
{
	Queue Q;
	init_queue(&Q);
	cout<<"遍历空队列："<<endl;
	travel_queue(&Q);
	enter_queue(&Q,1); 
	enter_queue(&Q,2); 
	enter_queue(&Q,3); 
	enter_queue(&Q,4); 
	enter_queue(&Q,5);
	enter_queue(&Q,6);
	cout<<"队列元素有："<<endl;
	travel_queue(&Q);
	output_queue(&Q);
	cout<<"弹出一个元素后结果为："<<endl;
	travel_queue(&Q);  
	return 0;
}
void init_queue(Queue* pQ)
{
	cout<<"请输入队列中元素个数(输入数减去一):";
	cin>>n;
	pQ->pbase=new int[n];
	pQ->front=0;
	pQ->rear=0;//头尾指针相等且设置为零，队列为空 
	return;
}
bool empty_queue(Queue* pQ)
{
	if(pQ->front==pQ->rear)//头尾指针相等，队列为空 
	{
		return true;
	}else
	{
		return false;
	}
}
bool full_queue(Queue* pQ)
{
	if((pQ->rear+1)%n==pQ->front)//尾指针加一取余等于头指针即代表队列已满 
	{
		return true;
	}else
	{
		return false;
	}
}
void enter_queue(Queue* pQ,int n)
{
	if(full_queue(pQ))
	{
		cout<<"队列已满"<<endl;
		return;
	}
	else
	{
		pQ->pbase[pQ->rear]=n;//将n赋值给当前rear元素 
		pQ->rear=(pQ->rear+1)%n;//rear加一取余，达到循环目的 
	}
	return;
}
void travel_queue(Queue* pQ)
{
	if(empty_queue(pQ)) 
	{
		cout<<"队列为空"<<endl;
		return; 
	}else
	{
		int i=pQ->front;//front的值赋给i，遍历队列 
		while(i!=pQ->rear)
		{
			cout<<pQ->pbase[i]<<" ";
			i=(i+1)%n; 
		} 
		cout<<endl;
	}
	return;
}
void output_queue(Queue* pQ)
{
	int n;
	if(empty_queue(pQ))
	{
		cout<<"队列为空"<<endl;
		return;
	}else
	{
		n=pQ->pbase[pQ->front];
		pQ->front=(pQ->front+1)%n;//首节点往后移 
	}
	cout<<"弹出队列的元素为："<<n<<endl;
	return;
}
