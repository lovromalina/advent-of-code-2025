#include <stdio.h>
#include <string.h>
#include <math.h>

long long int string_to_int(char* string){
    long long int num = 0;
    int j = 0;

    for (int i = strlen(string)-1; i >= 0; --i)
    {
        num = num + (string[j]-'0')*pow(10, i);
        j++;
    }

    return num;
}

char* num_to_string(long long int num){
    static char string[64] = "";
    snprintf(string, sizeof(string), "%lld", num);
    return string;
}

int check_num(long long int num){
    char string[64];
    strcpy(string, num_to_string(num));
    int half = strlen(string)/2;
    char first_half[32]="", second_half[32]="";

    strncpy(first_half, string, half);

    if(strlen(string) % 2 == 0){
        strncpy(second_half, string + half, half);
    }else{
        return 0;
        //strncpy(second_half, string + half + 1, half);
    }

    //if(strlen(second_half)%2) second_half += 1;

    //printf("%s -- %s, %s\n", string, first_half, second_half);

    if(strcmp(first_half, second_half) == 0) {
        //printf("Found match (%s, %s)\n", first_half, second_half);
        return 1;
    }
    else {
        return 0;
    }

}

int main()
{
    char lower[64],upper[64];
    long long int sum = 0;
    long long int num_lower, num_upper;

    while(scanf("%63[^-]-%63[^,],,", &lower, &upper) == 2){
        num_lower = string_to_int(lower);
        num_upper = string_to_int(upper);

        for (int i = 0; i <= num_upper - num_lower; ++i)
        {
            long long int check = num_lower + i;

            if(check_num(check)) {
                sum += check;   
                //printf("%lld, %lld\n_______\n", sum, check);
            }         
        }
    }
    printf("%lld\n", sum);

    return 0;
}