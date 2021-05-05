#include<stdio.h>
int num[100005];//魁–计瞴计
int array[4];//input3计
int temp,ans,i=0,x=0;
int n,a1,a2,a3;
int gcd(int a, int b);
int circle(int a, int n);


int main(){
    int t,y=0;
    scanf("%d",&t);
    for(y=0;y<t;++y){
        scanf("%d %d %d %d",&n,&array[0],&array[1],&array[2]);
        printf("%d\n",circle(array,n));
    }
    return 0;
}


int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        gcd(b,a%b);
    }
}

int circle(int a, int n){
    int temp=0,ans=0;
    int num[100005]={0};//testcaseぃ璶睲ぃ穦痙セ魁


    for(i=0;i<3;++i){
        //狦ㄢ计が借–计常瞴temp魁┮Τ计常Τ聋瞴
        if (gcd(n,array[i])==1){
            temp+=1;
        }
        else {
            //ex:a1=2,n=6,2 4 6常穦瞴ノ緇计稱猭笲衡
            for(x=1;(array[i]%n*x%n)%n!=0;++x){

                num[(array[i]%n*x%n)%n]+=1;
            }
            //讽緇计=0计程ê瞴ボ钡ㄓ穦碻吏瞴计┮铬癹伴
            num[n]+=1;
        }
    }

    //魁Τぶ3聋瞴
    for (i=1;i<=n;++i){
        if (num[i]+temp==3){
           ans+=1;
        }
    }
    return ans;
}


