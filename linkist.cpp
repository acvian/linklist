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
	printf("������%d������:\n",n);
	for(i = n;i > 0;i--){
		s = (LNode*)malloc(sizeof(LNode));
		scanf("%d",&s->data);
		s->next = p->next;
		p->next = s;
		p = s;	
	}
	LNode *q = (*L)->next;
	printf("����������Ϊ:\n");
	while(i < n){
		visit(q->data); 
		q = q->next;
		i++;	
	}
}

Status DeleteList(LNode **r, ElemType *e) 
{	
	if((*r)->next == NULL){
		printf("û�п���ɾ����Ԫ�أ�\n");
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
 		printf("������Ϸ����ݣ�\n"); 
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
	printf("�����봴������ĳ��ȣ�\n");
	scanf("%d",&n);                                                                                             
	CreateList(&L,n);
	int i; 
	printf("\n������ɾ��Ŀ���λ�ã�\n");
	scanf("%d",&i);
	LNode **r = &L;
	FindNode(r,i);
	ElemType *e =(ElemType*)malloc(sizeof(ElemType));
	if(DeleteList(r,e) == SUCCESS){
		TraverseList(L,(*visit));
	}
	return 0;	
}
