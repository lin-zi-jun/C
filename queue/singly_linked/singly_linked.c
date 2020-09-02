#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "singly_linked.h"
//===================================================1111============================================================

typedef struct test_node     /* 链表节点结构体 */
{
    SLIST_ENTRY(test_node) next;
    uint32_t ID;
    char * people;
} test_node;

typedef SLIST_HEAD(num_head, test_node) num_head;    /* 链表头结构体 */


int main(void)
{
    //1-从堆空间申请链表表头并初始化
    num_head *p_head = malloc(sizeof(num_head));


    //2-将头链表初始化，防止野指针
    SLIST_INIT(p_head);

    //3 定义一个元素并申请堆内存
    test_node *elm = malloc(sizeof(test_node));

    elm->ID = 1;
    //指向常量区
    elm->people = "张三";
    //从链表头开始插入
    SLIST_INSERT_HEAD(p_head, elm, next);

    elm = malloc(sizeof(test_node));
    elm->ID = 2;
    //指向常量区
    elm->people = "李四";
    //从链表头开始插入
    SLIST_INSERT_HEAD(p_head, elm, next);

    test_node* var = malloc(sizeof(test_node));
    var->ID = 3;
    var->people = "王五";
    //从链表头开始插入
    // SLIST_INSERT_HEAD(p_head, elm, next);
    SLIST_INSERT_AFTER(elm,var,next);

    SLIST_FOREACH (elm, p_head, next) {
        printf("addr = %p,%d:%s\n", elm, elm->ID,elm->people);
    }

    SLIST_REMOVE(p_head, var, test_node, next);

    SLIST_FOREACH (elm, p_head, next) {
        printf("addr = %p,%d:%s\n", elm, elm->ID,elm->people);
    }


    while (!SLIST_EMPTY(p_head)) {
        printf("--------------------\n");
        test_node *ptr = SLIST_FIRST(p_head);
        SLIST_REMOVE_HEAD(p_head, next);
        free(ptr);
    }
    free(p_head);

    return 0;
}
