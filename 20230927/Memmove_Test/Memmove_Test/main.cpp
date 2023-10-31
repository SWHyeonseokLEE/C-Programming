#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Insert(int idx, int list[], int searchnum)							//idx = 숫자를 추가할 자리, list[] = 배열의 크기, searchnum = 자리에 추가할 숫자
{
	memmove(list + idx + 1, list + idx, sizeof(int) * (6 - idx));		// memmove(목적지, 복사시작 위치, 복사할 byte)를 이용하여 이동시킨다.
	list[idx] = searchnum;												// 원하는 원소 값을 넣는다.
}

void main(void)
{
	int list[7]{ 1,4,9,15,30,0,0 };
	Insert(3, list, 10);												// list[3] 자리에 10의 값을 추가한다.

	for (int i = 0; i < 7; i++)
	{
		printf("%d  ", list[i]);											// 결과값: 1 4 9 10 15 30 0
	}
}