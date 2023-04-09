/*������ⱨ������
����n����վ��һ�ţ������ұ�ŷǱ�Ϊ1~n�����ڴ������ұ���"1,2,1,2..."
����1���˳��У�����2��������վ����������ұߣ��������̷������У�ֱ��n���˶�����Ϊֹ��
Ҫ��������ǵĳ���˳��*/ 
#include<stdio.h>
#include<malloc.h>
#define Maxsize 11
//ʹ��ѭ������
struct Queue
{
	int *data;
	int front;
	int rear;
};
void init_queue(Queue *&q);//��ʼ������ 
void input_queue(Queue *&q,int e);//����� 
void output_queue(Queue *&q,int &e);//������ 
void destory_queue(Queue *&q);//���ٶ��� 
void travel_queue(Queue *q);//�������� 
void operation(int n);//���� 
int main()
{
	int n;//������Ԫ�صĸ��� 
	printf("�����������Ԫ�ظ���(���Ϊ%d��)��",Maxsize-1);
	scanf("%d",&n);
	operation(n);
	return 0;
}
void init_queue(Queue *&q)
{
	q=(Queue*)malloc(sizeof(Queue));
	q->data=(int*)malloc(sizeof(int)*Maxsize);
	q->front=0;
	q->rear=0;
	return;
} 
void input_queue(Queue *&q,int e)
{
	if((q->rear+1)%Maxsize==q->front)
	{
		printf("ջ������\n");
		return;
	}
	q->data[q->rear]=e;
	q->rear=(q->rear+1)%Maxsize;
	return;
}
void output_queue(Queue *&q,int &e)
{
	if(q->front==q->rear)
	{
		printf("ջΪ�գ�\n");
		return;
	}
	e=q->data[q->front];
	q->front=(q->front+1)%Maxsize;
	return;
}
void travel_queue(Queue *q)
{
	int n=q->front;
	while(n!=q->rear)
	{
		printf("%d ",q->data[n]);
		n=(n+1)%Maxsize;
	}
	printf("\n");
	return;
}
void destory_queue(Queue *&q)
{
	free(q->data);
	free(q);
	return;
}
void operation(int n)
{
	Queue *q;
	init_queue(q);
	int e,count=0;
	//��� 
	for(int i=0;i<n;i++)
	{
		printf("�������%d�����Ԫ�أ�",i+1);
		scanf("%d",&e);
		input_queue(q,e);
	}
	printf("����˳��Ϊ��\n");
	travel_queue(q);
	//��ʼ����
	printf("������ɺ����˳��Ϊ��\n");
	while(q->front!=q->rear)//�����в�Ϊ��ʱ��ִ��ѭ�� 
	{
		count++;
		if(count==1)//���Ϊ1����� 
		{
			output_queue(q,e);
			printf("%d ",e);
		}else if(count==2)//���Ϊ2�������̷��ڶ������Ҷˣ����ˣ� 
		{
			output_queue(q,e);//������
			input_queue(q,e);//����� 
			count=0;//����ΪΪ�µ�һ�ֱ��� 
		}
	} 
	return;
}
