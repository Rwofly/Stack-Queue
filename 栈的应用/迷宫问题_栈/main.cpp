#include<stdio.h>
#include"maze.h"
//��⺯��
bool mgpath(int xi, int yi, int xe, int ye);//�������·��Ϊ��xi,yi)->(xe,ye);
int main(void)
{
	int m, n;
	printf("���������λ�ã�");
	scanf_s("%d %d", &m, &n);
	int k = mgpath(1, 1, m, n);
	if (!mgpath(1, 1, m, n))//(1,1)��ʾ���λ��
	{
		printf("���Թ�û�н⣡");
	}
	return 0;
}
bool mgpath(int xi, int yi, int xe, int ye)
{
	int i, j, di, il, jl, k;
	//���Ϊ��xi,yi),�����ջ
	Box path[Maxsize], e;//path����·��
	bool find;
	Stack* S=NULL;
	init_stack(S);//��ʼ��ջ
	e.i = xi, e.j = yi, e.di = -1;//��ʼ��λ����Ϊ-1
	push_stack(S, e);//����e��ջ
	mg[xi][yi] = -1;//����ջ��������Ϊ-1��ֹ�ظ�����������ѭ��
	while (!if_empty(S))//���ջ��Ϊ��
	{
		get_stack(S, e);//��ȡջ��
		i = e.i;j = e.j;di = e.di;
		if (i == xe && j == ye)//����ҵ��˳��ڣ������·��
		{
			printf("��·�����£�\n");
			k = 0;//��ʾ·���еķ�����
			while (!if_empty(S))
			{
				pop_stack(S, e);
				path[k] = e;
				k++;         //��·�����뵽ջ��
			}
			while (k > 0)
			{
				printf("\t(%d,%d)", path[k - 1].i, path[k - 1].j);
				if ((k + 1) % 5 == 0)
				{
					printf("\n");//ÿ������Ԫ�ؾͻ���
				}
				k--;
			}
			destory_stack(S);//����ջ
			return true;
		}
		find = false;
		while (di < 4 && !find)//�ҷ��飨i,j������һ�����ڿ��߷��飨il,jl)
		{
			di++;//���ڷ���λ��
			//��һ�������Ϸ������ʾΪ0����˳ʱ�뷽�����α�ʾΪ0��1��2��3
			switch (di)
			{
			case 0:il = i - 1;jl = j;break;
			case 1:il = i;jl = j + 1;break;
			case 2:il = i + 1;jl = j;break;
			case 3:il = i;jl = j - 1;break;
			}
			if (mg[il][jl] == 0)
			{
				find = true;//�ҵ����ڷ�����ߣ�findΪ��
			}
		}
		if (find)//�ҵ�һ�����ߵ�����
		{
			S->data[S->top].di = di;//�޸�ԭջ��Ԫ�ص�ֵ,��ʾ�÷�������̽��
			e.i = il;e.j = jl;e.di = -1;
			push_stack(S, e);//���ڷ�����ߣ�e��ջ
			mg[i][j] = -1;//����Ϊ-1�������ظ��ߵ��÷���
		}
		else
		{
			pop_stack(S, e);//û��·�����ߣ�����ջ
			mg[e.i][e.j] = 0;//����ջ�����λ�ñ�Ϊ����
		}
	}
	destory_stack(S);//����ջ
	return false;
}