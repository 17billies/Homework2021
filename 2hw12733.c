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
        l=strlen(str);//�r���l����
        s_len=strlen(str);
        for(j=0;j<x && j<l;++j){
            //�]�wleft,�N�r��̪��Ʀr�ഫ��int
            left=str[j]-'0';

            //j=���Ϋe�b�q���γQ�ƻs�������Aleft*(l-j)=�r���b�q(�r����״�e�b�q�r��)�n�ƻsleft���A�h�[mod�קK�t�Ȳ���
            l=((j+1)%mod+(left*(l-(j+1)))%mod+mod)%mod;


            //�r����פj��x�Aleft�p�G����1�N���ݭn�W�[�r��
            if(s_len<x && left>1){
                strncpy(s,str+j+1,s_len-j-1);
                t_len=strlen(s);

                //�W�[�r��
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
