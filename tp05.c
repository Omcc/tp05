#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp05.h"








int treeHeight(struct IntNode *p)
{
	if(p==NULL)return 0;

	int heightOfLeft = treeHeight(p->leftChild);
	int heightOfRight = treeHeight(p->rightChild);

	return heightOfLeft > heightOfRight ? heightOfLeft+1 : heightOfRight+1;
}


void insertIntArrayIntoTree(int *arr,struct IntNode **root,int size)
{
	if(*root==NULL)
	*root=insertIntNode(*root,arr[0]);

	struct IntNode *p=*root;

	int i=1;

	for(i;i<size;i++)
	{
		insertIntNode(p,arr[i]);

	}





}

void insertDoubleArrayIntoTree(double *arr,struct DoubleNode **root,int size)
{
	if(*root==NULL)
	*root=insertIntNode(*root,arr[0]);

	struct IntNode *p=*root;

	int i=1;

	for(i;i<size;i++)
	{
		insertDoubleNode(p,arr[i]);

	}



}




void findIntNode(struct IntNode *p,int data)
{

	if(p==NULL)
	{
		return;
	}
	
	if(data == p->data)
	{
		return;
	}
	else if(data < p->data)
	{
		findIntNode(p->leftChild,data);
	}

	else
	{
		findIntNode(p->rightChild,data);
	}





}

void findDoubleNode(struct DoubleNode *p,double data)
{

	if(p==NULL)
	{
		return;
	}
	
	if(data == p->data)
	{
		return;
	}
	else if(data < p->data)
	{
		findDoubleNode(p->leftChild,data);
	}

	else
	{
		findDoubleNode(p->rightChild,data);
	}





}

struct IntNode* insertIntNode(struct IntNode* p,int data)
{
	
	struct IntNode* CodeNode;
	if(!p)
	{
		CodeNode = (struct IntNode*)malloc(sizeof(struct IntNode));
		CodeNode->data=data;
		CodeNode->leftChild=NULL;
		CodeNode->rightChild=NULL;
		return CodeNode;
			
	
	}

	if(data < p->data)
	{
		p->leftChild=insertIntNode(p->leftChild,data);
	}
	else if(data > p->data)
	{
		p->rightChild=insertIntNode(p->rightChild,data);
	}

	return p;



}

struct DoubleNode* insertDoubleNode(struct DoubleNode* p,double data)
{
	
	struct DoubleNode* CodeNode;
	if(!p)
	{
		CodeNode = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
		CodeNode->data=data;
		CodeNode->leftChild=NULL;
		CodeNode->rightChild=NULL;
		return CodeNode;
			
	
	}

	if(data < p->data)
	{
		p->leftChild=insertDoubleNode(p->leftChild,data);
	}
	else if(data > p->data)
	{
		p->rightChild=insertDoubleNode(p->rightChild,data);
	}

	return p;



}

struct CharNode* insertCharNode(struct CharNode* p,char* data)
{
	
	struct CharNode* CodeNode;
	if(!p)
	{
	
		CodeNode = (struct CharNode*)malloc(sizeof(struct CharNode));
		CodeNode->data = (char *)malloc(sizeof(char)*5);
		strcpy(CodeNode->data,data);
		CodeNode->leftChild=NULL;
		CodeNode->rightChild=NULL;
		return CodeNode;
			
	
	}

	if(strcmp(data,p->data) > 0)
	{
		p->leftChild=insertCharNode(p->leftChild,data);
	}
	else if(strcmp(data,p->data) < 0)
	{
		p->rightChild=insertCharNode(p->rightChild,data);
	}

	return p;



}

struct IntNode* deleteIntNode(struct IntNode* p,struct IntNode **root,int data)
{


	struct IntNode* q;

	if(p==NULL)
	{
		return NULL;
		
	}

	if(p->leftChild==NULL && p->rightChild==NULL && data==p->data)
	{
		if(p==*root)
		{
			*root=NULL;

		}


		free(p);
		return NULL;
	}



	if(p->data==data)
	{



		if(treeHeight(p->leftChild) > treeHeight(p->rightChild))
		{
			q=findMaxInt(p->leftChild);
			p->data=q->data;
			p->leftChild=deleteIntNode(p->leftChild,root,q->data);
		}
		else
		{
			q=findMinInt(p->rightChild);
			p->data=q->data;
			p->rightChild=deleteIntNode(p->rightChild,root,q->data);
		}



	}

	else if(p->data>data)
	{
		p->leftChild=deleteIntNode(p->leftChild,root,data);
	}
	

	else
	{
		p->rightChild=deleteIntNode(p->rightChild,root,data);
	}


	return p;

}


struct DoubleNode* deleteDoubleNode(struct DoubleNode* p,struct DoubleNode **root,double data)
{


	struct DoubleNode* q;

	if(p==NULL)
	{
		return NULL;
		
	}

	if(p->leftChild==NULL && p->rightChild==NULL && data==p->data)
	{
		if(p==*root)
		{
			*root=NULL;

		}


		free(p);
		return NULL;
	}



	if(p->data==data)
	{



		if(treeHeight(p->leftChild) > treeHeight(p->rightChild))
		{
			q=findMaxDouble(p->leftChild);
			p->data=q->data;
			p->leftChild=deleteDoubleNode(p->leftChild,root,q->data);
		}
		else
		{
			q=findMinDouble(p->rightChild);
			p->data=q->data;
			p->rightChild=deleteDoubleNode(p->rightChild,root,q->data);
		}



	}

	else if(p->data>data)
	{
		p->leftChild=deleteDoubleNode(p->leftChild,root,data);
	}
	

	else
	{
		p->rightChild=deleteDoubleNode(p->rightChild,root,data);
	}


	return p;

}
struct IntNode *findMaxInt(struct IntNode* root)
{
	struct IntNode *p=root;
	while(p->rightChild)
	{
		p=p->rightChild;
	}

	return p;

}

struct DoubleNode *findMaxDouble(struct DoubleNode* root)
{
	struct DoubleNode *p=root;
	while(p->rightChild)
	{
		p=p->rightChild;
	}

	return p;

}



struct IntNode *findMinInt(struct IntNode* root)
{

	struct IntNode *p=root;
	while(p->leftChild)
	{
		p=p->leftChild;
	}

	return p;

}

struct DoubleNode *findMinDouble(struct DoubleNode* root)
{

	struct DoubleNode *p=root;
	while(p->leftChild)
	{
		p=p->leftChild;
	}

	return p;

}






int countNodes(struct IntNode *head)
{
	if(head==NULL)
		return 0;
	int leftBranch = countNodes(head->leftChild);
	int rightBranch = countNodes(head->rightChild);

	return leftBranch+rightBranch+1;
}

