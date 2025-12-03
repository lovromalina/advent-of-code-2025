#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[128];
    int first = 0, second = 0;
    int sum = 0;

    while(scanf("%127s\n", &buffer) == 1){
    	for (int i = 0; i < strlen(buffer)-1; ++i)
    	{
    		if(buffer[i] > first){
    			first = buffer[i];
    			second = 0;
    		}
    		if(buffer[i+1] > second && buffer[i] <= first){
    			second = buffer[i+1];
    		}
    	}
    	//printf("%d, %d\n", first - '0', second - '0');
    	sum += (first - '0')*10 + second - '0';
    	first = 0;
    	second = 0;
    }

    printf("%d\n", sum);

    return 0;
}