#include <stdio.h>
#include <stdlib.h>
/* 穷举法解密 */
int main()
{
    char word_1[5500] = "\0"; //解密前
    char word_2[5500] = "\0"; //解密后
    int i = 0;
    int j = 0;
    int len;
    printf("输入明文：");
    scanf("%s", word_1);
    len=strlen(word_1);

    for(i = 0; i < len; i++)
    {
	word_1[i]+=len;
	printf("0x%x ",word_1[i]);
    }

    i=0;
    for(i=0;i<len;i++){
        word_2[i]=word_1[i]-len;
    }

   
   printf("输出明文：%s",word_2);


    return 0;
}

