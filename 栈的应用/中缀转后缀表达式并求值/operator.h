#pragma once
#include<stdlib.h>
#include"stack.h"
#include"stack1.h"
void turn(char* str, char last[])//��׺ת��׺
{
	char e;
	int i = 0;
	Stack* S = NULL;
	init_stack(S);//��ʼ��ջ
	while (*str != '\0')
	{
		switch (*str)
		{
		case '(':   //�ж�Ϊ������
			push_stack(S, '(');//�����Ž�ջ
			str++;
			break;
		case ')':    //�ж�Ϊ������
			pop_stack(S, e);//��ջ
			while (e != '(')//��Ϊ������ʱѭ��
			{
				last[i++] = e;
				pop_stack(S, e);//������ջ
			}
			str++;
			break;
		case '+':
		case '-':
			while (!if_empty(S))
			{
				get_stack(S, e);//�õ�ջ��Ԫ��
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
					pop_stack(S, e);//��ջ
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
	//��ʱstr������ϣ�ջ��Ϊ��ʱ����ѭ��
	while (!if_empty(S))
	{
		pop_stack(S, e);
		last[i++] = e;
	}
	last[i] = '\0';//��ӽ�����־
	destory_stack(S);//����ջ
	return;
}
double caculate(char* last)//�����׺���ʽ��ֵ
{
	double d, a, b,c, e;
	Stack1* S = NULL;
	init_stack1(S);//��ʼ������ջ
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
				printf("��0����\n");
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
	get_stack1(S, e);//ȡջ��Ԫ��
	destory_stack1(S);
	return e;
}
