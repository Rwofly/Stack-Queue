#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#define Maxsize 100
struct Stack
{
	char *num;
	int top;
};
void init_stack(Stack *&S);
void pop_stack(Stack *&S);
void push_stack(Stack *&S,char t);
bool if_empty(Stack *S);
bool if_full(Stack *S);
void destory_stack(Stack *&S);//�ͷ�ջ 
int s_ten(char *str,int sys);//�������׼��Ϊʮ���� 
void t_every(Stack *&S,int m,int n);//ʮ����ת��Ϊ������� 
bool if_legal(char *str,int sys);//�ж������Ƿ�Ϸ� 
int main()
{
	Stack *S=NULL;
	init_stack(S);
	int m,n,sys;
	char str[20];
	printf("�������������ֵĽ��ƣ�");
	scanf("%d",&sys);
	printf("������Ҫת�������֣�");
	scanf("%s",str);
	if(!if_legal(str,sys))
	{
		printf("���벻�Ϸ���\n");
		return 0;
	}
	m=s_ten(str,sys);
    printf("������Ҫת���Ľ��ƣ�");
    scanf("%d",&n);
    t_every(S,m,n);
	printf("ת��Ϊ%d���ƺ�Ϊ��\n",n);
	pop_stack(S);
	destory_stack(S);
	return 0;
}
void init_stack(Stack *&S)
{
	S=(Stack*)malloc(sizeof(Stack));
	S->num=(char*)malloc(sizeof(char)*Maxsize);
	S->top=-1;
	return;
}
void push_stack(Stack *&S,char m)
{
	if(if_full(S))
	{
		printf("ջ������\n");
		return; 
	}
	S->top++;
	S->num[S->top]=m;
	return;
}
void pop_stack(Stack *&S)
{
	if(if_empty(S))
	{
		printf("ջΪ�գ�\n");
		return;
	}
	while(S->top>=0)
	{
		printf("%c ",S->num[S->top]);
		S->top--;
	} 
	printf("\n"); 
	return;
}
bool if_empty(Stack *S)
{
	return (S->top==-1);
}
bool if_full(Stack *S)
{
	return (S->top==Maxsize-1);
}
void destory_stack(Stack *&S)
{
	free(S->num);
	S->num=NULL;
	free(S);
	S=NULL;
	return;
}
int s_ten(char *str,int sys)
{
	int number[Maxsize];
	int size=strlen(str);
	for(int i=0;i<size;i++)
	{
		if(str[i]>=48&&str[i]<=57)
		{
			number[i]=str[i]-48;
		}else if(str[i]>=65&&str[i]<=90)
		{
			number[i]=str[i]-55;
		}
	}
	int sum=0;
	int num,i,k=0;
	for(i=size-1,k=0;i>=0;i--,k++)
	{
		num=pow(sys,k);
		num=num*number[i];
		sum+=num;
	}
	return sum;
} 
void t_every(Stack *&S,int m,int n)
{
	int t;
	char c;
	while(m>0)
	{
		t=m%n;
		m=m/n;
		if(t>=0&&t<=9)//����ASCII�뽫����ת��Ϊ�ַ����� 
		{
			c=t+48;
		}else if(t>=10)
		{
			c=t+55;
		}
		push_stack(S,c);
	}
	return;
}
bool if_legal(char *str,int sys)
{
	int size=strlen(str);
	int number[Maxsize];
	for(int i=0;i<size;i++)
	{
		if(str[i]>=48&&str[i]<=57)
		{
			number[i]=str[i]-48;
		}else if(str[i]>=65&&str[i]<=90)
		{
			number[i]=str[i]-55;
		}
		if(number[i]>=sys)
		{
			return false;
		}
	}
	return true;
}

