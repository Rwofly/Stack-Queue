#include<iostream>
using namespace std;
int n; 
struct Queue
{
	int *pbase;
	int front;
	int rear;
};
void init_queue(Queue*);//��ʼ������
void enter_queue(Queue*,int);//���
void output_queue(Queue*);//����
bool empty_queue(Queue*);//�ж϶����Ƿ�Ϊ��
bool full_queue(Queue*);//�ж϶����Ƿ�����
void travel_queue(Queue*);//�������� 
int main()
{
	Queue Q;
	init_queue(&Q);
	cout<<"�����ն��У�"<<endl;
	travel_queue(&Q);
	enter_queue(&Q,1); 
	enter_queue(&Q,2); 
	enter_queue(&Q,3); 
	enter_queue(&Q,4); 
	enter_queue(&Q,5);
	enter_queue(&Q,6);
	cout<<"����Ԫ���У�"<<endl;
	travel_queue(&Q);
	output_queue(&Q);
	cout<<"����һ��Ԫ�غ���Ϊ��"<<endl;
	travel_queue(&Q);  
	return 0;
}
void init_queue(Queue* pQ)
{
	cout<<"�����������Ԫ�ظ���(��������ȥһ):";
	cin>>n;
	pQ->pbase=new int[n];
	pQ->front=0;
	pQ->rear=0;//ͷβָ�����������Ϊ�㣬����Ϊ�� 
	return;
}
bool empty_queue(Queue* pQ)
{
	if(pQ->front==pQ->rear)//ͷβָ����ȣ�����Ϊ�� 
	{
		return true;
	}else
	{
		return false;
	}
}
bool full_queue(Queue* pQ)
{
	if((pQ->rear+1)%n==pQ->front)//βָ���һȡ�����ͷָ�뼴����������� 
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
		cout<<"��������"<<endl;
		return;
	}
	else
	{
		pQ->pbase[pQ->rear]=n;//��n��ֵ����ǰrearԪ�� 
		pQ->rear=(pQ->rear+1)%n;//rear��һȡ�࣬�ﵽѭ��Ŀ�� 
	}
	return;
}
void travel_queue(Queue* pQ)
{
	if(empty_queue(pQ)) 
	{
		cout<<"����Ϊ��"<<endl;
		return; 
	}else
	{
		int i=pQ->front;//front��ֵ����i���������� 
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
		cout<<"����Ϊ��"<<endl;
		return;
	}else
	{
		n=pQ->pbase[pQ->front];
		pQ->front=(pQ->front+1)%n;//�׽ڵ������� 
	}
	cout<<"�������е�Ԫ��Ϊ��"<<n<<endl;
	return;
}
