#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode {
	ElemType data;
  	struct LNode *next;
	} LNode, *LinkedList;
	
typedef enum Status {
	ERROR,
	SUCCESS
	} Status;

void visit(ElemType e)
{
	printf("%d ", e);
} 

void CreateList(LinkedList *L,int n) 
{	
	int i;
	LNode *p = *L;
	LNode *s = *L;
	printf("请输入%d个数据:\n",n);
	for(i = n;i > 0;i--){
		s = (LNode*)malloc(sizeof(LNode));
		scanf("%d",&s->data);
		s->next = p->next;
		p->next = s;
		p = s;	
	}
	LNode *q = (*L)->next;
	printf("创建的链表为:\n");
	while(i < n){
		visit(q->data); 
		q = q->next;
		i++;	
	}
}

Status DeleteList(LNode **r, ElemType *e) 
{	
	if((*r)->next == NULL){
		printf("没有可以删除的元素！\n");
		return ERROR;
		}
	else{
		LNode *t = (*r)->next;
		(*r)->next = t->next;
		*e = t->data;
		free(t);
		return SUCCESS;	
	}
}

LNode* FindNode(LNode **r,int i)
{	
 	int j = i;
 	while((*r != NULL)&&(j > 0)){
		*r = (*r)->next;
		j--;
	}
 	if(*r == NULL || i<= 0){
 		printf("请输入合法数据！\n"); 
	}
	else{
		return *r;
	}	 
 }
 
void TraverseList(LinkedList L, void (*visit)(ElemType e)) 
{
	LNode *q = L->next;
	while(q != NULL){
		(*visit)(q->data);
		q = q->next;}
}

int main()
{		
	LinkedList L;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	int n; 
	printf("请输入创建链表的长度：\n");
	scanf("%d",&n);                                                                                             
	CreateList(&L,n);
	int i; 
	printf("\n请输入删除目标的位置：\n");
	scanf("%d",&i);
	LNode **r = &L;
	FindNode(r,i);
	ElemType *e =(ElemType*)malloc(sizeof(ElemType));
	if(DeleteList(r,e) == SUCCESS){
		TraverseList(L,(*visit));
	}
	return 0;	
}
