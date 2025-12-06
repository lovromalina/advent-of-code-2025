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
	int num = 0;

	for (int i = 0; i < ROWS; ++i)
	{
		fgets(grid[i], SIZE, stdin);
	}

	op = grid[ROWS-1];

	for (int i = 0; i < strlen(op); ++i){
		if(op[i] == ' ') {
			continue;
		}

		is_space = 1;	

		for(j = i; ; j++){
			for (int z = ROWS-2; z >= 0 ; --z){

				if(grid[z][j] == '\n'){
					break;
				}

				if(grid[z][j] != ' '){
					is_space = 0;
					num += (grid[z][j] -'0')*pow(10, exp++);
				}	
			}

			if(is_space){
				break;
			}

			if(op[i] == '+'){
				sum += num;
				
			}else{
				mul *= num;
			}
			
			is_space = 1;
			exp = 0;
			num = 0;
		}

		if(mul != 1)res += mul;
		else res += sum;
		mul = 1;
		sum = 0;
		
	}
	printf("%llu\n", res);

	return 0;
}