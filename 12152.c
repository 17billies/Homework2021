#include<stdio.h>
int main(){
    //int:-21 4748 3648 бу 21 4748 3647
    int n,k;
    int station[100005];
    int battery,ans=0;
    int i=0,flag=0;
    int checkpoint=0;
    scanf("%d",&n);
    scanf("%d",&k);
    station[0]=0;
    battery=k;
    for(i=1;i<=n;++i){
        scanf("%d",&station[i]);
        battery=battery-(station[i]-station[i-1]);
        if(battery<0){
            ans++;
            //change battery
            battery=k;
            //if the full battery cannot afford to next check place,then it fails
            //check:1 21 (22) ans:fail
            if(battery-(station[i]-station[i-1])<0){
                flag=1;
                printf("The Legend Falls.\n");
                break;
            }
                //the added battery is added in the former station,so we have to minus the consumption in this check place
                //check 8 5(2 3 5 10 12 15 17 20)ans:3
            else{
                battery=battery-(station[i]-station[i-1]);
            }
        }
    }
    if(flag!=1){
        printf("%d\n",ans);
    }



    return 0;
}
