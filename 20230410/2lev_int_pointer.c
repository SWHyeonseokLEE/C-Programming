#include<stdio.h>

int* getNumbers2() 
{
    static int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    return (int*) arr;
}
int main() {
    int* nums = getNumbers2();
    for(int i=0; i<3; i++)
	{
        for(int j=0; j<3; j++)
		{
			printf("%d ", *(nums+i*3+j));
		}
        printf("| ");
    }
}