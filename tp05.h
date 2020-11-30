#include <stdio.h>

#ifndef TP02
#define TP02
struct IntNode{
	int data;
	struct IntNode* leftChild;
	struct IntNode* rightChild;
};

struct DoubleNode{
	double data;
	struct DoubleNode* leftChild;
	struct DoubleNode* rightChild;
};


struct CharNode{
	char* data;
	struct DoubleNode* leftChild;
	struct DoubleNode* rightChild;
};




struct IntNode* insertIntNode(struct IntNode *p,int data);

struct IntNode* deleteIntNode(struct IntNode *p,struct IntNode **root,int data);

struct DoubleNode* insertDoubleNode(struct DoubleNode *p,double data);

struct DoubleNode* deleteDoubleNode(struct DoubleNode *p,struct DoubleNode **root,double data);

struct CharNode* insertCharNode(struct CharNode *p,char* data);

struct CharNode* deleteCharNode(struct CharNode *p,struct CharNode **root,char* data);

void findDoubleNode(struct DoubleNode *p,double data);

void findIntNode(struct IntNode *p,int data);

void findCharNode(struct CharNode *p,char* data);
struct IntNode* findMaxInt(struct IntNode* root);

struct IntNode* findMinInt(struct IntNode* root);

struct CharNode* findMinChar(struct CharNode* root);

struct CharNode* findMaxChar(struct CharNode* root);

struct DoubleNode* findMaxDouble(struct DoubleNode* root);

struct DoubleNode* findMinDouble(struct DoubleNode* root);






//utilization functions
void insertIntArrayIntoTree(int *arr,struct IntNode **root,int size);

void insertDoubleArrayIntoTree(double *arr,struct DoubleNode **root,int size);




int countNodes(struct IntNode* root);


void Run();





struct QueueNode{
	int front;
	int rear;
	int size;
	struct IntNode** countryList;
};


struct QueueNode* queueFactory(int size);

int isQueueEmpty(struct QueueNode *p);

int isQueueFull(struct QueueNode *p);

void enqueue(struct IntNode* p,struct QueueNode *q);

struct IntNode* dequeue(struct QueueNode *q);







#endif
