#include <stdio.h>
#include <stdlib.h>
/* 穷举法解密 */
#define DEBUG_PK printf
static char *sgStandCharBlack="0123456789ABCDEF";
void DbgPrinStr( const char *iStr,void *iPD,int iLen){
    char    *tPD = (char*)iPD;
    int     _i,_j, _k, _s, _c;
    char    tTppl[4];
    char    tvPrintBuf[ 128 ];

    tTppl[2] = '\0';

    DEBUG_PK("%s\n",(char*)iStr);
    for( _i=0; _i<10; _i++ )
        tvPrintBuf[ 49 + _i ] = ' ';
    _i = 0;
    while(_i<iLen){
        _c = 0;
        for(_j=0;(_j<16)&&((_i+_j)<iLen);_j++){
            tvPrintBuf[ _c++ ] = sgStandCharBlack[(tPD[_i+_j]&0xF0)>>4];
            tvPrintBuf[ _c++ ] = sgStandCharBlack[tPD[_i+_j]&0x0F];
            tvPrintBuf[ _c++ ] = ' ';
            if(_j == 7) tvPrintBuf[ _c++ ] = ' ';
        }
        _s = 49 - (_j*3) - _j/8;
        for( _k=0;_k<_s;_k++ )
            tvPrintBuf[ _c++ ] = ' ';

        _c += 10;

        for(_j=0;(_j<16)&&(_i<iLen);_j++){
            if( ( isprint( tPD[_i] ) ) && ( tPD[_i] != '\r' ) && ( tPD[_i] != '\n' ) )
                tvPrintBuf[ _c++ ] = tPD[_i];
            else
                tvPrintBuf[ _c++ ] = '.';
            _i++;
        }
        tvPrintBuf[ _c++ ] = '\r';
        tvPrintBuf[ _c++ ] = '\n';
        tvPrintBuf[ _c++ ] = '\0';
        DEBUG_PK( "%s", tvPrintBuf );
    }
}


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
    printf("len:%d\n",len);	
    for(i = 0; i < len; i++)
    {
	word_1[i]+=len;
        printf("%d  ",word_1[i]);
    }
DbgPrinStr("转",word_1,strlen(word_1));
    i=0;
    len=strlen(word_1);
    for(i=0;i<len;i++){
        word_2[i]=word_1[i]-len;
	printf("%d  ",word_2[i]);
    }

   DbgPrinStr("输出",word_2,strlen(word_2));   


    return 0;
}

