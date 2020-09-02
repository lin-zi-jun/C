#ifndef _SINGLY_QUEUE_H_
#define	_SINGLY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * Singly-linked List definitions.---------------------------------2-------------------------------------------
 */
 //第一个元素，只是指向下一个元素，不带任何参数，若为空则链表为空
#define	SLIST_HEAD(name, type)						\
struct name {								\
	struct type *slh_first;	/* first element */			\
}

#define	SLIST_HEAD_INITIALIZER(head)					\
	{ NULL }

#define	SLIST_ENTRY(type)						\
struct {								\
	struct type *sle_next;	/* next element */			\
}

/*
 * Singly-linked List functions.
 */
 //将头初始化为NULL;建立链表头后使用
#define	SLIST_INIT(head) do {						\
	(head)->slh_first = NULL;					\
} while (/*CONSTCOND*/0)

//从某个元素往后插一个元素
#define	SLIST_INSERT_AFTER(slistelm, elm, field) do {			\
	(elm)->field.sle_next = (slistelm)->field.sle_next;		\
	(slistelm)->field.sle_next = (elm);				\
} while (/*CONSTCOND*/0)

//从链表头插入元素
#define	SLIST_INSERT_HEAD(head, elm, field) do {			\
	(elm)->field.sle_next = (head)->slh_first;			\
	(head)->slh_first = (elm);					\
} while (/*CONSTCOND*/0)

//头指针直接指向第二个元素,忽略第一个元素
#define	SLIST_REMOVE_HEAD(head, field) do {				\
	(head)->slh_first = (head)->slh_first->field.sle_next;		\
} while (/*CONSTCOND*/0)

#define	SLIST_REMOVE(head, elm, type, field) do {			\
	if ((head)->slh_first == (elm)) {				\
		SLIST_REMOVE_HEAD((head), field);			\
	}								\
	else {								\
		struct type *curelm = (head)->slh_first;		\
		while(curelm->field.sle_next != (elm))			\
			curelm = curelm->field.sle_next;		\
		curelm->field.sle_next =				\
		    curelm->field.sle_next->field.sle_next;		\
	}								\
} while (/*CONSTCOND*/0)

#define	SLIST_FOREACH(var, head, field)					\
	for((var) = (head)->slh_first; (var); (var) = (var)->field.sle_next)

/*
 * Singly-linked List access methods.
 */
//判断链表是否为NULL 
#define	SLIST_EMPTY(head)	((head)->slh_first == NULL)

//获取头指向的第一个元素
#define	SLIST_FIRST(head)	((head)->slh_first)

#define	SLIST_NEXT(elm, field)	((elm)->field.sle_next)

#endif
