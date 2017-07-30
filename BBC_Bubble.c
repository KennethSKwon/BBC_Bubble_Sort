#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){
	long int *Array=(long int *)malloc(sizeof(long int)*(atoi(argv[1])));
	//time_t t;
	long int _time1=0;
	long int _time2=0;
	long int tmp=0;
	int _size = atoi(argv[1]);

	printf("====================================\n");
	printf("Input argv[1] : %d\n", _size);
//	printf("_size of Array : %u\n",*(Array-8));
	
	srand(time(NULL));

// START : ALLOCATION + RANDOM VALUE

	for(long int i=0; i<_size; i++){
		Array[i]=rand()%_size;  
		//printf("*TEST %d*\n",i);
/*
		if(i%10==0){
			printf("\n");
		}
		else{
			printf("%d ",Array[i]);	
		}
*/		
	}
	printf("\n");


// START : FIRST TIME MEASURE
	_time1=time(NULL);

// START : BUBBLE SORT
	for(long int i=0; i<_size-1; i++){
		for(long int j=0; j<_size-i-1; j++){
			if(Array[j]>Array[j+1]){
				tmp=Array[j];
				Array[j]=Array[j+1];
				Array[j+1]=tmp;
			}
		}		
	}


	for(long int i=0; i<_size; i++){
		if(i%10==0){
			printf("\n");
		}
		else{
			printf("%li ",Array[i]);	
		}
		
	}
	printf("\n");

// STRAT : SECOND TIME + TIME GAP
	_time2=time(NULL);

	printf("Time1 : %li\n",_time1);
	printf("Time2 : %li\n",_time2);
	printf("Sorting Delta Time : %li second\n", (_time2-_time1));

	return 0;

}