#include<stdio.h>
void* getNumbers3() 
{
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (void*) arr;
}
int main() 
{
    int (*nums)[2][3] = getNumbers3();
    for(int i=0; i<2; i++)
	{
        for(int j=0; j<2; j++)
		{
            for(int k=0; k<3; k++) 
			{
				printf("%d ", nums[i][j][k]);
			}
            printf(", ");
        }
        printf("| ");
    }
}