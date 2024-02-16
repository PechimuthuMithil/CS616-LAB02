#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// char chrarray[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// char *funct2string(int num, int length)
// {
//     char myarr[length];
//     for (int i = 0; i < length; i++)
//     {
//         myarr[i] = '$';
//     }
//     int counter = length - 1;
//     while (num > 0 && counter > 0)
//     {
//         int curr_char = num % 36;
//         myarr[counter] = chrarray[curr_char];
//         num /= 36;
//         counter--;
//     }

//     // for(int i=0;i<length/2;i++)
//     // {
//     //     char temp = myarr[i];
//     //     myarr[i] = myarr[length-i-1];
//     //     myarr[length-i-1]=temp;
//     // }
//     return myarr;
// }

int main(int argc, char *argv[])
{
    int p, X, N;
    p = atoi(argv[1]); // rank size
    X = atoi(argv[2]);
    N = atoi(argv[3]);
    printf("PARAMETERS GIVEN--> p: %d  X: %d  N: %d\n", p, X, N);
    char chrarray[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // double sigma = (36 / 35) * (pow(36, N) - 1);
    double sigma =36;
    int rank;
    int i_max = sigma / p;
    int j_max = X / p;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("My Rank: %d\n", rank);

    int length =N;
    for (int j = ((sigma * (rank)) / p) ; j < j_max + ((sigma * (rank)) / p) + 1; j++)
    {
        char myarr[length+1];
        for (int i = 0; i < length; i++)
        {
            myarr[i] = '$';
        }
        
        int counter = length;
        int num = j;
        while (num > 0 && counter > 0)
        {
            int curr_char = num % 36;
            myarr[counter] = chrarray[curr_char];
            num /= 36;
            counter--;
        }
        myarr[length]='\0';
        printf("%s\n", myarr);
    }

    MPI_Finalize();
    return 0;
}