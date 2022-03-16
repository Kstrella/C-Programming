#include <stdio.h>
#include <stdlib.h>

// struct to store everything
typedef struct
{
    long long int token, bill;
    long long int units;
    char *name;
} custy;

void mergeArr(custy *Name, int left, int mid, int right)
{
    int Temp1 = mid - left + 1;
    int Temp2 = right - mid;
    int i;
    int f;
    int p;

    // for temp arrays
    custy L[Temp1], R[Temp2];

    // populate temps with data
    for (i = 0; i < Temp1; i++)
    {
        L[i] = Name[left + i];
    }

    for (f = 0; f < Temp2; f++)
    {
        R[f] = Name[mid + 1 + f];
    }

    // sets index for vals and merges
    i = 0;
    f = 0;
    p = left;

    while (i < Temp1 && f < Temp2)
    {
        if (L[i].units > R[f].units)
        {
            Name[p] = L[i];
            i++;
        }
        else
        {

            Name[p] = R[f];
            f++;
        }
        p++;
    }

    // following 2 while loops are to check and copy any remaining values from temps
    while (i < Temp1)
    {
        Name[p] = L[i];
        i++;
        p++;
    }

    while (f < Temp2)
    {
        Name[p] = R[f];
        f++;
        p++;
    }
}

// sorts values that have been merged
void mergesort(custy *Name, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = left + (right - left) / 2;

        // recursive call
        mergesort(Name, left, mid);
        mergesort(Name, mid + 1, right);

        // calls merging function
        mergeArr(Name, left, mid, right);
    }
}

int main()
{
    int numCusty;
    long long int unitT;
    long long int unitB;
    long long int Tmath = 0;
    long long int Bmath = 0;

    scanf("%d", &numCusty);

    custy cust[numCusty];

    // scans into struct members
    for (int i = 0; i < numCusty; ++i)
    {
        cust[i].name = calloc(21, sizeof(char));

        scanf("%s%lld%lld", cust[i].name, &cust[i].token, &cust[i].bill);
    }

    // scans units bills and tokens
    scanf("%lld%lld", &unitB, &unitT);

    // does the conversion to a standard unit
    for (int i = 0; i < numCusty; ++i)
    {

        Tmath = unitT * cust[i].token;
        Bmath = unitB * cust[i].bill;
        cust[i].units = Tmath + Bmath;
    }
    // call to merge sort function
    mergesort(cust, 0, numCusty - 1);

    // prints everything
    for (int i = 0; i < numCusty; ++i)
    {
        printf("%s\n", cust[i].name);
    }

    for (int i = 0; i < numCusty; ++i)
    {
        free(cust[i].name);
    }
    return 0;
}
