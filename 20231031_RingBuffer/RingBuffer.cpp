#include <stdio.h>

#define Buffer_Size 5

int main()
{
	int Ring_Buffer[Buffer_Size] = { 0, };
	int num;
	int index = 0;

	while (1)
	{
		printf("수를 입력하세요. \n");
		scanf_s("%d", &num);
		


		if (num == 0)
		{
			break;
		}
		Ring_Buffer[index] = num;
		for (int i = 0; i < Buffer_Size; i++) {
			printf("%d ", Ring_Buffer[i]);
		}
		printf("\n\n\n");

		index = (index + 1) % Buffer_Size; // 다음 인덱스로 이동
	}
	return 0;
}