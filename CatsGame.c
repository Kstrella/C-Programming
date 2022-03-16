#include <stdio.h>

void print(int val)
{
    printf("%d\n", val);
    fflush(stdout);
}

int main()
{
    // nlogbase 2 of n = max
    // G is guess.
    int max, G1, G2, min = 1;
    char input[1000];

    scanf("%d", &max);
    fgets(input, 1000, stdin);

    while (0 < max)
    {
        // guesses midpoint
        G1 = ((max + min) / 2);
        print(G1);
        fgets(input, 10000, stdin);

        if (input[0] == 'Y')
        {
            return 0;
        }

        if (input[4] == 'N')
        {
            print((G1 + G2) / 2);
            fgets(input, 1000, stdin);
            return 0;
        }

        // guesses midpoint +1
        G2 = ((max + min) / 2) + 1;
        print(G2);
        fgets(input, 1000, stdin);

        // Colder check midpoint and subtracts 1 as max
        if (input[4] == 'C')
        {
            max = (min + max) / 2 - 1;
        }

        // Game Over just kills program
        {
            if (input[0] == 'G')
                return 0;
        }
        // Yes ends program
        if (input[0] == 'Y')
        {
            return 0;
        }

        // Warmer gets midpoint and increases by 2 for min
        if (input[4] == 'W')
        {
            min = (min + max) / 2 + 2;
        }
    }

    return 0;
}
