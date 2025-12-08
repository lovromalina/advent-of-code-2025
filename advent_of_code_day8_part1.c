#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1000

typedef struct{
	int x;
	int y; 
	int z;
	int circuit;
	short int conected[SIZE];
}Junction_box;

int comp(const void *a, const void *b) {
    return (*(long int *)b - *(long int *)a);
}



int main(){
	Junction_box junction[SIZE];
	unsigned long long int distance;
	unsigned long long int min_distance = ULLONG_MAX;
	long int circuit_size[SIZE];
	int n = sizeof(circuit_size) / sizeof(circuit_size[0]);

	for (int i = 0; i < SIZE; ++i){
		scanf("%d,%d,%d", &junction[i].x, &junction[i].y, &junction[i].z);
		junction[i].circuit = i;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		circuit_size[i] = 1;
		for (int j = 0; j < SIZE; ++j)
		{
			if(i == j){
				junction[i].conected[j] = 1;
			}else{
				junction[i].conected[j] = 0;
			}

		}
	}
/*
	for (int i = 0; i < SIZE; ++i){
		printf("%d,%d,%d\n", junction[i].x, junction[i].y, junction[i].z);
	}
*/
	int i_min, j_min;
	for (int n = 0; n < SIZE; ++n){
		for (int i = 0; i < SIZE; ++i){
			for(int j = i; j < SIZE; ++j){
				if(i == j)continue;
				if(junction[i].conected[j] || junction[j].conected[i])continue;
				distance = 
						pow(junction[i].x - junction[j].x, 2)
						+pow(junction[i].y - junction[j].y, 2)
						+pow(junction[i].z - junction[j].z, 2);
				if (distance < min_distance){
					min_distance = distance;
					i_min = i;
					j_min = j;
				}
			}
		}
		printf("%llu, i = %d, j = %d\n", min_distance, i_min, j_min);


		junction[i_min].conected[j_min] = 1;
		junction[j_min].conected[i_min] = 1;

		if(junction[i_min].circuit == junction[j_min].circuit){
			min_distance = ULLONG_MAX;
			continue;
		}

		if(junction[i_min].circuit < junction[j_min].circuit){

			circuit_size[junction[i_min].circuit] += circuit_size[junction[j_min].circuit];
			circuit_size[junction[j_min].circuit] = 0;

			for (int i = 0; i < SIZE; ++i){
				if(junction[i].circuit == junction[j_min].circuit){
					junction[i].circuit = junction[i_min].circuit;	
				}
			}
	
			

		}else{

			circuit_size[junction[j_min].circuit] += circuit_size[junction[i_min].circuit];
			circuit_size[junction[i_min].circuit] = 0;

			for (int i = 0; i < SIZE; ++i){
				if(junction[i].circuit == junction[i_min].circuit){
					junction[i].circuit = junction[j_min].circuit;	
				}
			}
			
		}
		
		min_distance = ULLONG_MAX;

	}

	qsort(circuit_size, n, sizeof(circuit_size[0]), comp);
	int sum = 0;



	for (int i = 0; i < SIZE; i++){


		sum += circuit_size[i];
        printf("%ld ", circuit_size[i]);

    }
    printf("\n%d\n", sum);

    printf("\n%ld\n", circuit_size[0]*circuit_size[1]*circuit_size[2]);



	return 0;
}