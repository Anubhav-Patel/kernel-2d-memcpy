#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/syscall.h>
#include <linux/kernel.h>

#define Tds 451

void check_equals(float scr[2][2], float dest[2][2], int len1, int len2)
{

    int i = 0;
    int j = 0;
    while (i < len1)
    {
        j =0;
        while (j < len2)
        {
            if (scr[i][j] == dest[i][j])
            {
                continue;
            }
            else
            {
                printf("Error : LHS[%d][%d] != RHS[%d][%d]\n", i + 1, j + 1, i + 1, j + 1);
                return;
            }
            j++;
        }
        i++;
    }

   
    printf("Message : Success LHS = RHS \n");
}

int main(int argc, char const *argv[])
{
    float src_arr[2][2] = {{1.1, 2.0}, {1.5, 2.7}};
    float dest_arr[2][2];

    long sys_call;

    sys_call = syscall(Tds, src_arr, dest_arr, 2, 2);
    
    if (sys_call == EFAULT)
    {
        check_equals(src_arr, dest_arr, 2, 2);
        printf("Message : System Call 451 successfuly invoked\n");
    }
    else
    {
        printf("Message : System Call 451 not successfuly invoked\n");
    }

    return 0;
}