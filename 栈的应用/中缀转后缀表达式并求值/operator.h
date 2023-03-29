#pragma once
#include<stdlib.h>
#include"stack.h"
#include"stack1.h"
void turn(char* str, char last[])//中缀转后缀
{
	char e;
	int i = 0;
	Stack* S = NULL;
	init_stack(S);//初始化栈
	while (*str != '\0')
	{
		switch (*str)
		{
		case '(':   //判定为左括号
			push_stack(S, '(');//左括号进栈
			str++;
			break;
		case ')':    //判定为右括号
			pop_stack(S, e);//出栈
			while (e != '(')//不为左括号时循环
			{
				last[i++] = e;
				pop_stack(S, e);//继续出栈
			}
			str++;
			break;
		case '+':
		case '-':
			while (!if_empty(S))
			{
				get_stack(S, e);//得到栈顶元素
				if (e != '(')
				{
					last[i++] = e;
					pop_stack(S, e);
				}
				else
				{
					break;
				}
			}
			push_stack(S, *str);
			str++;
			break;
		case '*':
		case '/':
			while (!if_empty(S))
			{
				get_stack(S, e);
				if (e == '*' || e == '/')
				{
					last[i++] = e;
					pop_stack(S, e);//出栈
				}
				else
				{
					break;
				}
			}
			push_stack(S, *str);
			str++;
			break;
		default:
			while (*str >= '0' && *str <= '9')
			{
				last[i++] = *str;
				str++;
			}
			last[i++] = '#';
			break;
		}
	}
	//此时str遍历完毕，栈不为空时进行循环
	while (!if_empty(S))
	{
		pop_stack(S, e);
		last[i++] = e;
	}
	last[i] = '\0';//添加结束标志
	destory_stack(S);//销毁栈
	return;
}
double caculate(char* last)//计算后缀表达式的值
{
	double d, a, b,c, e;
	Stack1* S = NULL;
	init_stack1(S);//初始化数字栈
	while (*last != '\0')
	{
		switch (*last)
		{
		case '+':
			pop_stack1(S, a);
			pop_stack1(S, b);
			c = a + b;
			push_stack1(S, c);
			break;
		case '-':
			pop_stack1(S, a);
			pop_stack1(S, b);
			c = a - b;
			push_stack1(S, c);
			break;
		case '*':
			pop_stack1(S, a);
			pop_stack1(S, b);
			c = a * b;
			push_stack1(S, c);
			break;
		case '/':
			pop_stack1(S, a);
			pop_stack1(S, b);
			if (a != 0)
			{
				c = b / a;
				push_stack1(S, c);
				break;
			}
			else
			{
				printf("除0错误！\n");
				exit(0);
			}
			break;
		default:
			d = 0;
			while (*last >= '0' && *last <= '9')
			{
				d = 10 * d + *last - '0';
				last++;
			}
			push_stack1(S, d);
			break;

		}
		last++;
	}
	get_stack1(S, e);//取栈顶元素
	destory_stack1(S);
	return e;
}
