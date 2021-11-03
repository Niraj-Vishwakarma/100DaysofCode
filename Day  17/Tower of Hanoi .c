#include <stdio.h>

void hanoi(int num, char ndl1, char ndl2, char ndl3)
{

    if (num == 1)
    {

        printf("Move top disk from needle %c to needle %c\n", ndl1, ndl2);
        return;
    }

    hanoi(num - 1, ndl1, ndl3, ndl2);

    printf("Move top disk from needle %c to needle %c\n", ndl1, ndl2);

    hanoi(num - 1, ndl3, ndl2, ndl1);
}

void main()
{

    int no;

    printf("Enter the Number of Disks to be Transferred:\n\n");

    scanf("%d", &no);

    if (no < 1)
    {

        printf("\n There is nothing to move:\n");
    }
    else
    {

        printf("\n Recursive:\n");
        hanoi(no, 'A', 'B', 'C');
    }
}
