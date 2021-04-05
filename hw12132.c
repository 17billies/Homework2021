#include <stdio.h>
long long arr[200005];//西瓜的編號順序
long long eaten[200005];
long long ans[200005];//紀錄西瓜是否被吃的陣列
int main(){
    int n,k=0,i=0,t=0,count;
    scanf("%d",&n);//輸入次數
    for(i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }//輸入西瓜編號順序


    i=0;
    for(k=0;k<n;++k){
        count=0;//把需吃的西瓜次數歸零
        scanf("%d",&t);//輸入本次要吃的西瓜編號
        if(eaten[t]==1){
            ans[k]=count;
        }
        else{
            for(i=i;i<n;++i){
                if(t==arr[i]){
                    eaten[arr[i]]=1;        //被吃掉西瓜紀錄成1
                    ++count;
                    ans[k]=count;
                    i++;
                    break;
                }
                else{
                    eaten[arr[i]]=1;        //被吃掉西瓜紀錄成1
                    ++count;
                }
            }
        }
    }
    for(i=0; i<n-1; i++){
        printf("%d ", ans[i]);
    }//print all answers(except last) by the format "%d "

    printf("%d\n", ans[n-1]); //print the last answer with no blank and an new line}}
    return 0;
}

