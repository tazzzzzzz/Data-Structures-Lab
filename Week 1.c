#include<stdio.h>
#include<stdlib.h>
void selectsort(int arr[], int i);
void swapperdapper(int *x, int *y);
int main(int argc, char const *argv[]) 
{
	int n; //size of the array
	int *arr; //array of size n
	int i;
	//printf("enter the number of test input values\n");
	scanf("%d", &n);
	//scanf("%d", &x);
	arr = (int *) malloc(n * sizeof(n));
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	selectsort(arr, n); // sort n elements
	for (i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}

//DO NOT MODIFY CODE ABOVE. WRITE YOUR CODE BELOW.
void selectsort(int arr[], int i)
{
    int z,j,min;
    for(z=0;z<(i-1);z++)
    {
        min=z;
        for(j=z+1;j<i;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swapperdapper(&arr[z],&arr[min]);
    }
}

void swapperdapper(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
