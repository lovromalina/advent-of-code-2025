#include <stdio.h>
#include <string.h>
#include <math.h>



char* num_to_string(long long int num){
    static char string[64] = "";
    snprintf(string, sizeof(string), "%lld", num);
    return string;
}

int check_num(long long int num){
    char string[64];
    strcpy(string, num_to_string(num));
    int half = strlen(string)/2;
    char first_half[32]="";

    for (int i = 1; i <= half; ++i)
    {
        int same = 1;
        if(strlen(string)%i != 0){
            continue;
        }

        strncpy(first_half, string, i);
        for (int j = i; j < strlen(string); j += i)
        {   

            if(strncmp(first_half, string + j, i) != 0){
                same = 0;
                break;
            } 
        }
        if(same) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char lower[64],upper[64];
    long long int sum = 0;
    long long int num_lower, num_upper;

    while(scanf("%lld-%lld,,", &num_lower, &num_upper) == 2){

        for (int i = 0; i <= num_upper - num_lower; ++i)
        {
            long long int check = num_lower + i;

            if(check_num(check)) {
                sum += check;   
            }         
        }
    }
    printf("%lld\n", sum);

    return 0;
}