#include<stdio.h>
#include<string.h>
#include"bigint.h"
void MENU()
{
    int i;
    for (i = 1; i < 50; i++)
        printf("-");
    printf("\n");
    printf("您好，欢迎来到长整数处理软件！\n");
}
void INPUT(int a[])
{
    int i;
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    a[0] = len;
    for (i = 1; i <= len; i++) {
        if (str[len - i] <= '9' && str[len - i] >= '0')
            a[i] = str[len - i] - '0';
        else {
            printf("您输入有误，请重试！\n");
            break;
        }
    }
}
void OUTPUT(int a[])
{
    int i, len = a[0];
    printf("您的所输入的两个长整数经本运算处理后结果为:\n");

    for (i = len; i >= 1; i--)
        printf("%d", a[i]);
    printf("\n");
}
void ADD(int a[], int b[], int c[])
{
    int t = 0, i;
    for (i = 1; i <= a[0] || i <= b[0] || t; i++) {
        if (i <= a[0])
            t = t + a[i];
        if (i <= b[0])
            t = t + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    c[0] = i - 1;
}
void SUB(int a[], int b[], int c[])
{
    int t = 0, i;
    for (i = 1; i <= a[0]; i++) {
        c[i] = a[i] - t;
        if (i <= b[0]) {
            c[i] -= b[i];
        }
        if (c[i] < 0) {
            t = 1;
            c[i] += 10;
        }
        else {
            t = 0;
        }
    }
    while (i > 1 && c[i - 1] == 0) {
        i--;
    }
    c[0] = i - 1;
}
void DIVIDE(int a[], int b[], int c[])
{
    int re = 0, i, j;
    int len = a[0];
    int num = 0;
    for (i = 1; i <= len; i++)
        for (j = 1; j <= i; j++)
            b[i + 1] = b[i + 1] * 10;
    for (i = 1; i <= len; i++)
        num = num + b[i];
    if (num == 0)
        printf("您好，除数不能为零！请重试！\n");
    for (i = len; i >= 1; i--) {
        re = re * 10 + a[i];
        a[i] = re / num;
        re %= num;
    }
    for (i = 0, a[0] = len; a[len - i] == 0; i++)
        a[0] -= 1;
    for (i = 0; i < len; i++)
        c[i] = a[i];
}
int REMAINDER(int a[], int b)
{
    int re = 0, i;
    int len = a[0];
    for (i = len; i >= 1; i--) {
        re = re * 10 + a[i];
        a[i] = re / b;
        re %= b;
    }
    for (i = 0, a[0] = len; a[len - i] == 0; i++)
        a[0] -= 1;
    return re;
}
void CONVERT_8(int a[], int b[])
{
    int len = a[0];
    int i, j;
    for (i = 1; len > 0; i++)
    {
        b[i] = REMAINDER(a, 8);
        len = a[0];
    }
    b[0] = i - 1;
}
void CONVERT_16(int a[], int b[])
{
    int len = a[0];
    int i, j;
    for (i = 1; len > 0; i++)
    {
        b[i] = REMAINDER(a, 16);
        len = a[0];
        if (b[i] < 10)
            b[i] = b[i] + '0';
        else
            b[i] = b[i] - 10 + 'A';
    }
    b[0] = i - 1;
    printf("您的所输入的长整数经本运算处理后结果为:\n");
    for (j = b[0]; j >= 1; j--)
        printf("%c", b[j]);
    printf("\n");
}