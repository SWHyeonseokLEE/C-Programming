#include <stdio.h>


int binomialCoefficient(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
    }
}


void expandExpression(int n)
{
    for (int k = 0; k <= n; k++)
    {
        int coefficient = binomialCoefficient(n, k);

        if (coefficient != 1)
        {
            printf("%d", coefficient);
        }

        if (n - k > 0)
        {
            printf("x^%d", n - k);
        }

        if (k > 0)
        {
            printf("a^%d", k);
        }

        if (k < n)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    int n;

    // ����ڷκ��� ���� n �Է� �ޱ�
    printf("���� n�� �Է��ϼ���: ");
    scanf_s("%d", &n);

    // (x+a)^n�� �����Ͽ� ���
    expandExpression(n);

    return 0;
}