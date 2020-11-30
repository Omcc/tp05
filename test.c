#include <stdio.h>

#include "tp05.h"
#include <time.h>
int swapIndex(int* x, int* y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int shuffleArray(int *arr)
{
	int randIndex1=0;
	int randIndex2=0;
	int i=0;
	
	for(int j=0;j<5;j++)
	{

	  for(i;i<100;i++)
 	  {
		randIndex1 = (rand()%99);
		randIndex2 = (rand()%99);
		swapIndex(&(arr[randIndex1]),&(arr[randIndex2]));
	  }
	  i=0;
	 
	}


}

double swapIndexDouble(double* x, double* y)
{
	double temp=*x;
	*x=*y;
	*y=temp;
}

double shuffleArrayDouble(double *arr)
{
	int randIndex1=0;
	int randIndex2=0;
	int i=0;
	
	for(int j=0;j<5;j++)
	{

	  for(i;i<100;i++)
 	  {
		randIndex1 = (rand()%99);
		randIndex2 = (rand()%99);
		swapIndexDouble(&(arr[randIndex1]),&(arr[randIndex2]));
	  }
	  i=0;
	 
	}


}

void Run()
{
	clock_t start,end,general_start,general_end;

	double time_passed=0.0;
	double general_time=0.0;

	struct IntNode *root=NULL;


	int arr[100];
	
	
	for(int i=0;i<1000;i++)
	{
		
		general_start=clock();
		for(int i=0;i<100;i++)
		{	
			arr[i]=i+1;
		}

		shuffleArray(arr);
		
		insertIntArrayIntoTree(arr,&root,100);
	
		time_passed=0;
		for (int i=1;i<101;i++)
		{
	
			start=clock();

			findIntNode(root,i);

			end=clock();
				
			time_passed += ((double)(end-start));
		

		}	

		time_passed = (time_passed/CLOCKS_PER_SEC)/100;

		general_end=clock();

		general_time += ((double)(general_end-general_start));
	}




	printf("\n Soru-2(int): Bir degerin int agacta ortalama bulunma süresi %f sec",time_passed);

	printf("\n Soru 3(int): int  Agac olusturma + arama süre ortalaması: %f sec",general_time/CLOCKS_PER_SEC/1000);



     	// double
	
	struct DoubleNode *rootDouble=NULL;
	double num;

	double arrDouble[100];
	for(int i=0;i<100;i++)
	{	
		arrDouble[i]=(i+1.5);
	}

	shuffleArrayDouble(arrDouble);


	
	for(int i=0;i<1000;i++)
	{
		
		general_start=clock();
		
		insertDoubleArrayIntoTree(arrDouble,&rootDouble,100);
	
		time_passed=0;
		for (int i=1;i<101;i++)
		{
			num=(double)i+0.5;
			
	
			start=clock();

			findDoubleNode(rootDouble,(num));

			end=clock();
				
			time_passed += ((double)(end-start));
		

		}	

		time_passed = (time_passed/CLOCKS_PER_SEC)/100;

		general_end=clock();

		general_time += ((double)(general_end-general_start));
	}





	printf("\n Soru-4(double): Bir double degerin agacta ortalama bulunma süresi %f sec",time_passed);
	printf("\n Soru 4(double): Double Agac olusturma + arama süre ortalaması: %f sec",general_time/CLOCKS_PER_SEC/1000);


	char c[4];
	
	struct CharNode *rootChar=NULL;




	for(int i=97;i<123;i++)
	{
		c[0]=i;
		for(int j=97;j<123;j++){
			c[1]=j;

			for(int k=97;k<123;k++)
			{
				c[2]=k;

				rootChar = insertCharNode(rootChar,c);
	
			}

		}

	}



	




}

int main()
{



	Run();
}

