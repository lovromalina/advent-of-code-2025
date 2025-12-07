#include <stdio.h>
#include <string.h>

#define SIZE 200

int main(){

	long long int beam[SIZE] = {0};
	char input_line[SIZE];
	int split = 0;
	long long int timeline = 0;
	

	while(fgets(input_line, sizeof(input_line), stdin)){

		for (int i = 0; i < strlen(input_line); ++i)
		{
			if(input_line[i] == 'S'){
				beam[i] = 1;
			}

			if(input_line[i] == '^' && beam[i] > 0){
				
				beam[i-1] += beam[i];

				beam[i+1] += beam[i];

				beam[i] = 0;

				split++;
			}
		}
	}

	for (int i = 0; i < SIZE; ++i)
	{
		timeline += beam[i];
	}

	printf("timelines: %lld\n", timeline);
	printf("splits: %d\n", split);

	return 0;
}