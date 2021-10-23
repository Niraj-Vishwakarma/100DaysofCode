#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val)
{
    
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = top;
    top = ptr;
}

void pop()
{
    struct node *temp;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", top->data);

        temp = top;

        top = temp->next;

        free(temp);
    }
}

void display()
{
    struct node *temp = top;

    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    int choice;
    int num;
    do
    {
        printf("\n******************");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter the number : ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }

    } while (choice != 4);
  
}