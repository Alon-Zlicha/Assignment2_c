#include <stdio.h>
#include "my_mat.h"

int main(){
    int matrix[SIZE][SIZE];
    char func;
    printf("Enter A to enter matrix values, Enter B to to check if there is a path, enter C to get the shortest path, enter D or Ctrl+Z to exit:\n");
    while(1){
        scanf("%c ",&func);
        if(func==EOF || func=='D')
            break;
        if(func=='A'){ 
            getMatrixValues(matrix);
        }
        if(func=='B'){
            int i, j;
            scanf("%d %d", &i,&j);
            if(isPath(matrix,i,j)!=0){
                printf("True\n");
            }
            else{
                printf("False\n");
            }
        }
        if(func=='C'){
            int i,j,s_p;
            scanf("%d %d", &i,&j);
            s_p=shortestPath(matrix,i,j);
            printf("%d\n",s_p);
        }
    } 
    return 0;
}