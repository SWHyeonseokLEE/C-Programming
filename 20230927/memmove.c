#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Insert(int idx, int list[], int searchnum)							//idx = ���ڸ� �߰��� �ڸ�, list[] = �迭�� ũ��, searchnum = �ڸ��� �߰��� ����
{
	memmove(list + idx + 1, list + idx, sizeof(int) * (6 - idx));		// memmove(������, ������� ��ġ, ������ byte)�� �̿��Ͽ� �̵���Ų��.
	list[idx] = searchnum;												// ���ϴ� ���� ���� �ִ´�.
}

void main(void)
{
	int list[7]{ 1,4,9,15,30,0,0 };
	Insert(3, list, 10);												// list[3] �ڸ��� 10�� ���� �߰��Ѵ�.

	for (int i = 0; i < 7; i++)
	{
		printf("%d  ", list[i]);											// �����: 1 4 9 10 15 30 0
	}
}