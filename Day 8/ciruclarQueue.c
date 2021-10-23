#include <stdio.h>
#define max 3

int arr[max];
int front;
int rear;

void enqueue()
{
    if ((rear + 1) % max == front)
    {
        printf("!!!!!!Queue is FULL!!!!!");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == max - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % max;
    }
    printf("\nEnter the data to enqueue :");
    int data;
    scanf("%d", &data);
    arr[rear] = data;
}

void dequeue()
{
    if (front == -1)
    {
        printf("!!!!!!Queue is EMPTY!!!!!");
        return;
    }
    printf("%d", arr[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == max - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", arr[i]);
            }
        }
        else
        {
            for (int i = front; i <= max - 1; i++)
            {
                printf("%d ", arr[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", arr[i]);
            }
        }
        return;
    }
}
void main()
{
    front = -1;
    rear = -1;

    int flag = -1;
    while (flag)
    {
        printf("\n\n********************");
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. exit\n");

        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            flag = 0;
            break;
        default:
            printf("Invalid choice!");
        }
    }
}
