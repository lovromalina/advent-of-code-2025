#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char buffer[128];
    long long int sum = 0;
    int digits[12] = {0};
    int j = 0;
    int max_index = 0;


    while(scanf("%127s\n", &buffer) == 1){
        for (int i = 0; i < 12; ++i)
        {
            for (j = max_index; j < strlen(buffer) - 11 + i; ++j)
            {
                if(buffer[j] > digits[i])
                {
                    digits[i] = buffer[j];
                    buffer[j] = '0';    
                    max_index = j;

                }
            }
        }
        max_index = 0;


        for (int i = 0; i < 12; ++i)
        {
            sum += (digits[i] - '0') * pow(10, 11-i); 
        }

        for (int i = 0; i < 12; ++i)
        {
            digits[i] = 0;
        }        
    }

    printf("%lld", sum);



    return 0;
}