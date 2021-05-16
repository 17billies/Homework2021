#include<stdio.h>
int s[1005][1005];
int con[2005];
int n,i,j;
int min,max;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;++i){
        max=0;
        for(j=0;j<n;++j){
            scanf("%d",&s[i][j]);
            if(s[i][j]>max){
                max=s[i][j];
            //determine the max of the row
            }
        }
        con[i]=max;
    }
    for(j=0;j<n;++j){
        min=50000;
        for(i=0;i<n;++i){
            if(s[i][j]<min){
                min=s[i][j];
            //determine the min of the column(switch the i and j)
            }
        }
        con[n+j]=min;
    }
    for(i=0;i<n*2;++i){
        printf("%d",con[i]);
        if(i==n-1 |i==n*2-1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}


