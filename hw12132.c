#include <stdio.h>
long long arr[200005];//��ʪ��s������
long long eaten[200005];
long long ans[200005];//������ʬO�_�Q�Y���}�C
int main(){
    int n,k=0,i=0,t=0,count;
    scanf("%d",&n);//��J����
    for(i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }//��J��ʽs������


    i=0;
    for(k=0;k<n;++k){
        count=0;//��ݦY����ʦ����k�s
        scanf("%d",&t);//��J�����n�Y����ʽs��
        if(eaten[t]==1){
            ans[k]=count;
        }
        else{
            for(i=i;i<n;++i){
                if(t==arr[i]){
                    eaten[arr[i]]=1;        //�Q�Y����ʬ�����1
                    ++count;
                    ans[k]=count;
                    i++;
                    break;
                }
                else{
                    eaten[arr[i]]=1;        //�Q�Y����ʬ�����1
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

