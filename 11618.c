#include<stdio.h>
int num[100005];//�����C�ӼƦr�ள�쪺��y��
int array[4];//�sinput��3�Ӽ�
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
    int num[100005]={0};//�]��testcase���u�@�ӡA�n�M�Ť~���|�d�U�쥻������


    for(i=0;i<3;++i){
        //�p�G��Ƥ���A�C�@�ӼƦr���ள���y�A�Htemp�����Ҧ��Ʀr�����@����y
        if (gcd(n,array[i])==1){
            temp+=1;
        }
        else {
            //ex:a1=2,n=6,2 4 6���|�����y�A�ξl�ƪ��Q�k�h�B��
            for(x=1;(array[i]%n*x%n)%n!=0;++x){

                num[(array[i]%n*x%n)%n]+=1;
            }
            //��l��=0�N��Ʀr�̤j�����@�ӤH�����y�]��ܱ��U�ӷ|�`���^�h�w�����y���Ʀr�A�ҥH���X�j��
            num[n]+=1;
        }
    }

    //�������h�֤H����3����y
    for (i=1;i<=n;++i){
        if (num[i]+temp==3){
           ans+=1;
        }
    }
    return ans;
}


