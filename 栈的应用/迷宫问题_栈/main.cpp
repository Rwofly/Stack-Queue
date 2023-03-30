#include<stdio.h>
#include"maze.h"
//求解函数
bool mgpath(int xi, int yi, int xe, int ye);//代表求解路径为（xi,yi)->(xe,ye);
int main(void)
{
	int m, n;
	printf("请输入出口位置：");
	scanf_s("%d %d", &m, &n);
	int k = mgpath(1, 1, m, n);
	if (!mgpath(1, 1, m, n))//(1,1)表示入口位置
	{
		printf("该迷宫没有解！");
	}
	return 0;
}
bool mgpath(int xi, int yi, int xe, int ye)
{
	int i, j, di, il, jl, k;
	//入口为（xi,yi),将其进栈
	Box path[Maxsize], e;//path保存路径
	bool find;
	Stack* S=NULL;
	init_stack(S);//初始化栈
	e.i = xi, e.j = yi, e.di = -1;//初始方位设置为-1
	push_stack(S, e);//方块e进栈
	mg[xi][yi] = -1;//将进栈方格设置为-1防止重复经过产生死循环
	while (!if_empty(S))//如果栈不为空
	{
		get_stack(S, e);//获取栈顶
		i = e.i;j = e.j;di = e.di;
		if (i == xe && j == ye)//如果找到了出口，输出该路径
		{
			printf("该路径如下：\n");
			k = 0;//表示路径中的方块数
			while (!if_empty(S))
			{
				pop_stack(S, e);
				path[k] = e;
				k++;         //将路径存入到栈中
			}
			while (k > 0)
			{
				printf("\t(%d,%d)", path[k - 1].i, path[k - 1].j);
				if ((k + 1) % 5 == 0)
				{
					printf("\n");//每输出五个元素就换行
				}
				k--;
			}
			destory_stack(S);//销毁栈
			return true;
		}
		find = false;
		while (di < 4 && !find)//找方块（i,j）的下一个相邻可走方块（il,jl)
		{
			di++;//相邻方块位号
			//以一个方块上方方块表示为0，按顺时针方向依次表示为0、1、2、3
			switch (di)
			{
			case 0:il = i - 1;jl = j;break;
			case 1:il = i;jl = j + 1;break;
			case 2:il = i + 1;jl = j;break;
			case 3:il = i;jl = j - 1;break;
			}
			if (mg[il][jl] == 0)
			{
				find = true;//找到相邻方块可走，find为真
			}
		}
		if (find)//找到一个可走到方块
		{
			S->data[S->top].di = di;//修改原栈顶元素的值,表示该方块以试探过
			e.i = il;e.j = jl;e.di = -1;
			push_stack(S, e);//相邻方块可走，e进栈
			mg[i][j] = -1;//设置为-1，避免重复走到该方块
		}
		else
		{
			pop_stack(S, e);//没有路径可走，则退栈
			mg[e.i][e.j] = 0;//让退栈方块的位置变为可走
		}
	}
	destory_stack(S);//销毁栈
	return false;
}