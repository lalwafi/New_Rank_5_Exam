#include "bsq.h"

int main(int av, char **ac)
{
    if (av == 1)
    {
        if (execute_bsq(stdin))
            fprintf(stderr, "Error \n");
        return (1);
    }

    else{
        for (int i = 1; i < av; i++)
        {
            if(file_intrep(ac[i]))
                {
                    fprintf(stderr, "Error\n");
                    return (1);
                }

        }
    }
    return (0);
}