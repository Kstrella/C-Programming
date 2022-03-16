#include <stdio.h>
#include <string.h>
#define maxWords 12
#define SIZE 21

// A phrase is pretty if for all pairs of consecutive words the first word ends with the same letter
// that the second word starts with.

// used permutations.c as big inspiration
int isPretty(char perm[][SIZE], int numWrds)
{
    for (int i = 0; i < numWrds - 1; i++)
    {

        // check if last char and first char are the same
        if (perm[i][strlen(perm[i]) - 1] != perm[i + 1][0])

            // out of order elements
            return 0;
    }
    // stop when in order
    return 1;
}

// permutations
int rec(char wrds[][SIZE], char perm[][SIZE], int count, int numWrds, int *used)
{
    if (count == numWrds)
    {

        if (isPretty(perm, numWrds))
        {

            for (int i = 0; i < numWrds; i++)
            {
                printf("%s ", perm[i]);
            }
            // printf("\n");
            // if sorted stop
            return 1;
        }
        return 0;
    }
    else
    {
        // look at spots in input
        for (int j = 0; j < numWrds; j++)
        {
            if (used[j] == 0)
            {
                // stores in used
                strcpy(perm[count], wrds[j]);
                used[j] = 1;
                if (rec(wrds, perm, count + 1, numWrds, used))
                    return 1;

                used[j] = 0;
            }
        }
        return 0;
    }
}

int main()
{
    int numWrds, count = 0;
    int used[maxWords];

    // scans into numwrds
    scanf("%d", &numWrds);

    // makes everything in used array 0
    for (int i = 0; i < numWrds; i++)
    {
        used[i] = 0;
    }

    // defined SIZE 21 (space for null terminator) at top
    char wrds[maxWords][SIZE];

    // for letters
    char perm[maxWords][SIZE];

    // scans words into the wrds array
    for (int i = 0; i < numWrds; i++)
    {
        scanf("%s", wrds[i]);
    }

    // sending everything to be permutaded in rec function
    rec(wrds, perm, count, numWrds, used);

    return 0;
}
