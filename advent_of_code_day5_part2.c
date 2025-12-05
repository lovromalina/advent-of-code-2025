#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned long long int start;
	unsigned long long int end;
	int valid;

}Range;

int comp(const void *a, const void *b) {
    unsigned long long A = ((Range *)a)->end;
    unsigned long long B = ((Range *)b)->end;

    if (A < B) return -1;
    if (A > B) return 1;
    return 0;
}

int main(){

	Range ranges[256];
	int num_ranges = 0;
	unsigned long long int id_num = 0;
	int fresh = 0;

	char line[128];

	while (fgets(line, sizeof(line), stdin)) {
	    
	    if (line[0] == '\n' || line[0] == '\r')
	        break;

	    unsigned long long a, b;
	    if (sscanf(line, "%llu-%llu", &a, &b) == 2) {
	        ranges[num_ranges].start = a;
	        ranges[num_ranges].end = b;
	        ranges[num_ranges].valid = 1;
	        num_ranges++;
	    } else {
	       
	        break;
	    }
	}

	qsort(ranges, num_ranges, sizeof(Range), comp);

	int j = 0;
	for (int i = num_ranges-1; i >= 0 ; i = j)
	{
		j = i-1;
		while(j > 0 && ranges[j].end >= ranges[i].start){

			if(ranges[j].start >= ranges[i].start){
				ranges[j].valid = 0;
			}else{
				ranges[i].start = ranges[j].start;
				ranges[j].valid = 0;
			}
			j--;
		}
	}

	for (int i = 0; i < num_ranges; ++i)
	{
		if(ranges[i].valid){
			id_num += ranges[i].end - ranges[i].start + 1;
		}
	}

	printf("id_num = %llu\n", id_num);

	return 0;
}