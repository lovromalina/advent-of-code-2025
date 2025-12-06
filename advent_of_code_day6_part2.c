#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 4096
#define ROWS 5

int main(){

	char grid[ROWS][SIZE];
	char *op;
	int j;
	int is_space;
	unsigned long long res = 0;
	unsigned long long sum = 0;
	unsigned long long mul = 1;
	int exp = 0;
	for (int i = 0; i < ROWS; ++i)
	{
		fgets(grid[i], SIZE, stdin);
	}

	op = grid[ROWS-1];

	//printf("%s\n", op);
	/*
	for (int i = 0; i < ROWS; ++i)
	{
		printf("%s\n", grid[i]);
	}
	
	for (int i = 0; i < strlen(op); ++i)
	{
		printf("%c\n", op[i]);
	}
	*/

	for (int i = 0; i < strlen(op); ++i)
	{
		if(op[i] == ' ') {
			continue;
		}

		if(op[i] == '+'){
			is_space = 1;	

			for(j = i; ; j++){
				for (int z = ROWS-2; z >= 0 ; --z){
					if(grid[z][j] == '\n'){
						break;
					}
					if(grid[z][j] != ' '){
						is_space = 0;
						sum += (grid[z][j] -'0')*pow(10, exp++);


					}
					
				}
				if(is_space){
					//printf("break\n");
					break;
				}
				is_space = 1;
				//printf(" %d\n", sum);
				res += sum;
				sum = 0;
				exp = 0;
				
			}
		}else{
			is_space = 1;	

			for(j = i; ; j++){
				for (int z = ROWS-2; z >= 0 ; --z){
					if(grid[z][j] == '\n'){
						break;
					}
					if(grid[z][j] != ' '){
						is_space = 0;
						sum += (grid[z][j] -'0')*pow(10, exp++);

					}
					
				}
				exp = 0;
				if(is_space){
					//printf("break\n");
					break;
				}
				is_space = 1;
				//printf("%d\n", sum);
				mul *= sum;
				//printf("mul = %d\n", mul);
				sum = 0;
				
			}
			res += mul;
			mul = 1;
			sum = 0;
		}
		
	}
	printf("%llu\n", res);

	return 0;
}