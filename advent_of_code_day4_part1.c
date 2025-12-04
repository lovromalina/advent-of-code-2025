#include <stdio.h>
#include <string.h>


int main() {
    char grid[256][256];
    int can_move[256][256] = {0};
    int rows = 0;
    int count = 0;
    int res = 0;


    while (scanf("%s\n", grid[rows]) == 1) {
        rows++;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < strlen(grid[i]); ++j)
        {
            if(grid[i][j] == '@'){
                for (int x = -1; x < 2; ++x)
                {
                    for (int y = -1; y < 2; ++y)
                    {
                        if(x == 0 && y == 0) continue;
                        if(i+x >= 0 && j+y >= 0){
                            if(grid[i+x][j+y] == '@')
                                count++;
                        }
                    }
                }
                if(count < 4) {
                    res++;
                }
                count = 0;
            }
        }
        
    }
    
    printf("%d\n", res);

    return 0;
}
