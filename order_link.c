#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 0
#define ERROR -1
#define INIT_LINK_SIZE 10
#define INC_SIZE 5

typedef int Status;
typedef int Elemtype;


typedef struct{
    Elemtype *elem;
    int length;
    int size;
}SqList;



Status InitList(SqList *L){
    L->elem = (Elemtype *)malloc(INIT_LINK_SIZE * sizeof(Elemtype));
    if(!L->elem){
        return ERROR;
    }

    L->length = 0;
    L->size =INIT_LINK_SIZE;
}




int main()
{

    SqList L;
    if(InitList(&L)!=-1){
        printf("init List finsh\r\n");
    }
    // SqList L;
    // if (InitList(&L))
    // {
    //     Elemtype e;
    //     printf("init_success\n");
    //     int i;
    //     for (i = 0; i < 10; i++)
    //     {
    //         InsertElem(&L, i + 1, i);
    //     }
    //     printf("length is %d\n", getLength(L));
    //     if (GetElem(L, 1, &e)) {
    //         printf("The first element is %d\n", e);
    //     }
    //     else
    //     {
    //         printf("element is not exist\n");        
    //     }
    //     if (isEmpty(L))
    //     {
    //         printf("list is empty\n");
    //     }
    //     else
    //     {
    //         printf("list is not empty\n");
    //     }
    //     printf("The 5 at %d\n", FindElem(L, 5, *compare));
    //     PreElem(L, 6, &e);
    //     printf("The 6's previous element is %d\n", e);
    //     NextElem(L, 6, &e);
    //     printf("The 6's next element is %d\n", e);
    //     DeleteElem(&L, 1, &e);
    //     printf("delete first element is %d\n", e);
    //     printf("list:");
    //     TraverseList(L,visit);
    //     if (DestroyList(&L))
    //     {
    //         printf("\ndestroy_success\n");
    //     }
    // }
}
