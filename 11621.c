#include<stdio.h>
#include<string.h>
int num=0,size;
char str1[2005],str3[2002];
char* reverse(char str2[2002]);
int mission(char str1[2005]);
//�D�{��
int main(){
    while(scanf("%s",&str1)!=EOF){
         printf("%d\n",mission(str1));
    }
    return 0;
}


//�h�P�_���X��equisite substring
int mission(char str1[2005]){
    int num=0;
    int i=0,j=0;
    //�����r�����
    size=strlen(str1);
    for(j=0;j<size-1;++j){//j=��ܦr�ꪺ�_�l�I
        for(i=size-j;i>=2;--i){//i=����substring����
            char str2[2002]={0};//�M�Ŧr��
            strncat(str2,str1+j,i);//�Nsubstring��J�s���}�C��
            str2[i]='\0';
            //ex: ababa�P�_ab�Mba�A�p�G��ba�˹L��=ab(function reverse),�N��ܳo�Ӧr��Osubstring
            if(strncmp(str2,reverse(str2),i/2)==0){
                num+=1;
            }
        }
    }
    return num;
}

//�@�w�n�[*�A�n���O���Ъ��Ϊk
char* reverse(char str2[2002]){
    int count=strlen(str2);
    int t;
    //ex:str2=ababa,�n��᭱ba�˹L��
    if (count%2==1){
        //t�_�l�O�}�C���̫�@��index�At�u�ݭn�����`�r��ƪ��@�b�[�@
        for(t=count-1;t>=count/2+1;--t){
            //��̫�@�Ӧr���s�}�C���Ĥ@�Ӧ�l�A�H������
            str3[count-1-t]=str2[t];
        }
    }
    else{
        //����t�ݰ����`�r��ƪ��@�b
        for(t=count-1;t>=count/2;--t){
            str3[count-1-t]=str2[t];
        }
    }
    str3[count]='\0';
    return str3;
}
