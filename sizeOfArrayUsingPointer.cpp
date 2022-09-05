#include "stdio.h"
int main(){
    int arr[]={1,2,3,4,5,6,7};
    printf("Address of the first element of the arr:%d\n",arr);
    printf("Address of the entire arr:%d\n",&arr);
    printf("Pointer to the byte after the arr:%d\n",&arr+1);
    printf("Value of the next arr:%d",*(&arr+1));
    ///size of the array
    printf("\nSize of the arr:%d",*(&arr+1)-arr);
    return 0;
}