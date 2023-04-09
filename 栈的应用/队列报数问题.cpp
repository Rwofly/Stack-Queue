/*队列求解报数问题
设有n个人站成一排，从左到右标号非别为1~n，现在从左往右报数"1,2,1,2..."
数到1的人出列，数到2的人立即站到队伍的最右边，报数过程反复进行，直到n个人都出列为止。
要求给出他们的出列顺序*/ 
#include<stdio.h>
#include<malloc.h>
#define Maxsize 11
//使用循环队列
struct Queue
{
	int *data;
	int front;
	int rear;
};
void init_queue(Queue *&q);//初始化队列 
void input_queue(Queue *&q,int e);//入队列 
void output_queue(Queue *&q,int &e);//出队列 
void destory_queue(Queue *&q);//销毁队列 
void travel_queue(Queue *q);//遍历队列 
void operation(int n);//操作 
int main()
{
	int n;//队列中元素的个数 
	printf("请输入队列中元素个数(最多为%d个)：",Maxsize-1);
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
		printf("栈已满！\n");
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
		printf("栈为空！\n");
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
	//入队 
	for(int i=0;i<n;i++)
	{
		printf("请输入第%d个入队元素：",i+1);
		scanf("%d",&e);
		input_queue(q,e);
	}
	printf("队列顺序为：\n");
	travel_queue(q);
	//开始报数
	printf("报数完成后出列顺序为：\n");
	while(q->front!=q->rear)//当队列不为空时，执行循环 
	{
		count++;
		if(count==1)//如果为1则出队 
		{
			output_queue(q,e);
			printf("%d ",e);
		}else if(count==2)//如果为2，则立刻放在队列最右端（最后端） 
		{
			output_queue(q,e);//出队列
			input_queue(q,e);//入队列 
			count=0;//设置为为新的一轮报数 
		}
	} 
	return;
}
