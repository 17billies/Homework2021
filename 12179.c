#include<stdio.h>
int test(int x, int y);
void queen(int row);
int col[50], cnt1[50], cnt2[50];
int n,x,y,row,ans=0;
int main(){
    scanf("%d",&n);
    queen(0);
    printf("%d\n",ans);
    return 0;
}
int test(int x, int y){
    if(col[y]==1 | cnt1[x-y+15]==1 | cnt2[x+y]==1){
        return 0;
    }
    else{
        return 1;
    }
}
void queen(int row){
    int y=0;
    if(row==n){
        ans++;
    }
    else{
            for(y=0;y<n;++y){
                if(test(row,y)==1){
                col[y]=1;
                cnt1[row-y+15]=1;
                cnt2[row+y]=1;
                queen(row+1);
                col[y]=0;
                cnt1[row-y+15]=0;
                cnt2[row+y]=0;
                }
            }
    }
}
