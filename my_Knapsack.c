#include <stdio.h>

#define SIZE 5
#define MAX_WEIGHT 20

typedef struct item
{
    char name;
    int value;
    int weight;
}item;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int knapsack(int weights[],int values[],int selected_bool[]){
    int dp[SIZE+1][MAX_WEIGHT+1]={0};
    for(int i=0;i<SIZE+1;i++){
        for(int j=0;j<MAX_WEIGHT+1;j++){
            if((i==0)||(j==0)){
                dp[i][j]=0;
            }
            else{
                if(weights[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
                }
            }
        }
    }
    int tempMaxValue=dp[SIZE][MAX_WEIGHT];
    int tempMaxWeight=MAX_WEIGHT;
    for (int i = SIZE; i>0 && tempMaxValue>0; i--){
        if(dp[i][tempMaxWeight]!=dp[i-1][tempMaxWeight]){
            selected_bool[i-1]=1;
            tempMaxValue-=values[i-1];
            tempMaxWeight-=weights[i-1];
        }
    }
    return dp[SIZE][MAX_WEIGHT];
}

int main(){
    item items[SIZE];
    int weights[SIZE];
    int values[SIZE];
    int result[SIZE]={0};
    for(int i = 0; i < SIZE; i++) {
        scanf(" %c %d %d", &items[i].name, &items[i].value, &items[i].weight);
    }
    for(int i=0;i<SIZE;i++){
        values[i]=items[i].value;
        weights[i]=items[i].weight;
    }
    int max_profit=knapsack(weights,values,result);
    printf("Maximum profit: %d",max_profit);
    printf("\nSelected items:");
    for(int i=0;i<SIZE;i++){
        if(result[i]==1){
            printf(" %c", items[i].name);
        }
    }
    return 0;
}