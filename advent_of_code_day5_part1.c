#include <stdio.h>

int main(){

	unsigned long long int ranges[256][2];
	int num_ranges = 0;
	unsigned long long int id;
	int fresh = 0;

	char line[128];

	while (fgets(line, sizeof(line), stdin)) {
	    
	    if (line[0] == '\n' || line[0] == '\r')
	        break;

	    unsigned long long a, b;
	    if (sscanf(line, "%llu-%llu", &a, &b) == 2) {
	        ranges[num_ranges][0] = a;
	        ranges[num_ranges][1] = b;
	        num_ranges++;
	    } else {
	       
	        break;
	    }
	}

	while(scanf("%llu", &id) == 1){
		for (int i = 0; i < num_ranges; ++i)
		{
			if(id >= ranges[i][0] && id <= ranges[i][1]){
				fresh++;
				break;
			}
		}
	}

	printf("%d\n", fresh);

	return 0;
}