#include<stdio.h>
#include"bigint.h"
int main()
{
	int i, j, len = 0, num = 0;
	int first_option, third_option, fourth_option;
	char second_option;
	int num1[100] = { 0 }, num2[100] = { 0 };
	int ans[100] = { 0 }, tmp[100] = { 0 };
	int result = 0;
	int tmp1[100] = { 0 }, tmp2[100] = { 0 };
	//输出主菜单界面
	MENU();
	while (1)
	{
		//进行相关处理
		printf("请输入仅输入数字以选择您所需要实现的处理\n");
		printf("1.输入两个长整数\n");
		printf("2.输出长整数运算结果\n");
		scanf("%d", &first_option);
		if (first_option == 1) {
			printf("请输入长整数1\n");
			INPUT(num1);
			len = num1[0];
			for (i = 0; i <= len; i++)
				tmp1[i] = num1[i];
			printf("请输入长整数2\n");
			INPUT(num2);
			len = num2[0];
			for (i = 0; i <= len; i++)
				tmp2[i] = num2[i];
			for (i = 1; i <= len; i++)
				for (j = 1; j <= i; j++)
					num2[i + 1] = num2[i + 1] * 10;
			for (i = 1; i <= len; i++)
				num = num + num2[i];
			for (i = 0; i <= len; i++)
				num2[i] = tmp2[i];
			system("cls");
		}
		else if (first_option == 2) {
			OUTPUT(ans);
			if (second_option == 'C') {
				printf("您的所输入的两个长整数经本运算处理后余数为:\n");
				for (i = 0; i <= len; i++)
					num1[i] = tmp1[i];
				result = REMAINDER(num1, num);
				printf("%d\n", result);
				for (i = 1; i < 50; i++) printf("-");
			}
			else
				for (i = 1; i < 50; i++) printf("-");
			printf("\n");
			break;
		}
		else {
			printf("您输入有误，请重试！\n");
			break;
		}
		//选择A B C D进行下一步四种处理运算
		printf("请输入仅输入大写字母以选择您所需要实现的处理\n");
		printf("A.长整数加法运算\n");
		printf("B.长整数减法运算\n");
		printf("C.长整数除法运算\n");
		printf("D.长整数进制转换\n");
		getchar();
		scanf("%c", &second_option);
		if (second_option == 'A')
			ADD(num1, num2, ans);
		else if (second_option == 'B')
			SUB(num1, num2, ans);
		else if (second_option == 'C')
			DIVIDE(num1, num2, ans);
		else if (second_option == 'D') {
			printf("请输入仅输入数字以选择您所需要转换的长整数编号\n");
			scanf("%d", &third_option);
			if (third_option == 1) {
				printf("请输入仅输入数字以选择您所需要将长整数%d转换成的进制数\n", third_option);
				scanf("%d", &fourth_option);
				if (fourth_option == 8)
					CONVERT_8(num1, ans);
				if (fourth_option == 16) {
					CONVERT_16(num1, ans);
					break;
				}
			}
			if (third_option == 2) {
				printf("请输入仅输入数字以选择您所需要将长整数%d转换成的进制数\n", third_option);
				scanf("%d", &fourth_option);
				if (fourth_option == 8)
					CONVERT_8(num2, ans);
				if (fourth_option == 16) {
					CONVERT_16(num2, ans);
					break;
				}
			}
		}
		else {
			printf("您输入有误，请重试！\n");
			break;
		}
	}
	return 0;
}