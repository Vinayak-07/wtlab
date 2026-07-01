// Online C compiler to run C program online
#include <stdio.h>
int main() {
    int n;
    int t;
    printf("if a matrix of n x n enter n :");
    scanf("%d",&n);
    int arr1[n][n];
    int arr2[n][n];
    int arr3[n][n];
    //arr1 input
    printf("enter elements of first arry");
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          scanf("%d",&t);
          arr1[i][j] = t;
        }
    }
    //arr2 input
    printf("enter elements of 2nd arry");
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          scanf(" %d ",&t);
          arr2[i][j] = t;
        }
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            arr3[i][j] = 0;
            //use formula cij = summetion a[i][k] x b[i][k]  
            for(int k = 0; k < n; k++){
                 arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("[");
        for (int j = 0; j < n; j++){
           printf(" %d ",arr3[i][j]);
        }
        printf("]\n");
    }
}
