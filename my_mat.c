#include <stdio.h>
#include "my_mat.h"

#define INFINITY 999999999

void getMatrixValues(int matrix[][SIZE] ){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            scanf("%d ", &matrix[i][j]);
        }
    }
}

int isPath (int matrix[][SIZE] , int i, int j){
    if(shortestPath(matrix,i,j)>0){
        return 1;
    }
    return 0;
}


int shortestPath(int matrix[][SIZE] , int i, int j){
    if(i==j){
        return -1;
    }
    int dist[SIZE][SIZE];
    for(int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if((i!=j) && (matrix[i][j]==0)){
                dist[i][j]=INFINITY;
            }
            else{
                dist[i][j]=matrix[i][j];
            }
        }
    }
    for(int k=0;k<SIZE;k++){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    if(dist[i][j]!=INFINITY){
        return dist[i][j];
    }
    return -1;
}