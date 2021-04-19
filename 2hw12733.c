#include<stdio.h>
#include<string.h>
#define mod 1000000007

 char str[2000005],s[2000005]="",temp[2000005];
int main(){
    int s_len,t_len,left,x;
    long long int l;
    int t;
    int i=0,j=0,a=0;
    scanf("%d",&t);
    for(i=0;i<t;++i){
        scanf("%lld",&x);
        scanf("%s",str);
        l=strlen(str);//字串初始長度
        s_len=strlen(str);
        for(j=0;j<x && j<l;++j){
            //設定left,將字串裡的數字轉換為int
            left=str[j]-'0';

            //j=切割前半段不用被複製的部分，left*(l-j)=字串後半段(字串長度減前半段字串)要複製left次，多加mod避免負值產生
            l=((j+1)%mod+(left*(l-(j+1)))%mod+mod)%mod;


            //字串長度大於x，left如果等於1就不需要增加字串
            if(s_len<x && left>1){
                strncpy(s,str+j+1,s_len-j-1);
                t_len=strlen(s);

                //增加字串
                for(a=0;a<left-1 && s_len<x;++a){
                    strcat(str,s);
                    s_len+=t_len;
                }
            }
        }

        printf("%lld\n",l);


    }


    return 0;
}
