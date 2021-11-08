#include <stdio.h>
#include <stdlib.h>
#define max 10
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Sort while Inserting
void sortAdd(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    struct node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else if (temp->data >= newNode->data)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        while (temp->next->data < newNode->data && temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\n\t\t\t LIST IS EMPTY _(-U-)_\n");
        return;
    }
    struct node *temp;
    temp = head;
    printf("\t\t\t");
    printf("-> %d -> ", temp->data);
    temp = temp->next;
    while (temp != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// delete at begining
void deleteAtStart()
{
    if (head == NULL)
    {
        printf("\n NOTHING TO DELETE ---(*,*)---\n");
        return;
    }
    struct node *temp = head;

    if (temp->next == head)
    {
        head = NULL;

        free(head);
        printf("\t\t\t ELEMENT DELETED ");
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    temp = head;
    head = head->next;

    free(temp);
    printf("\t\t\t ELEMENT DELETED ");
}

// delete at end
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("\n\t\t\t NOTHING TO DELETE ---(*,*)---\n");
        return;
    }

    struct node *current = head;
    struct node *temp;
    if (current->next == head)
    {
        head = NULL;
        free(head);
        printf("\t\t\t ELEMENT DELETED ");
        return;
    }
    while (current->next->next != head)
    {
        current = current->next;
    }
    temp = current->next;
    current->next = head;

    free(temp);
    printf("\t\t\t ELEMENT DELETED ");
}

// delete at specific position
void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("\n\t\t\tNOTHING TO DELETE ---(*,*)---\n");
        return;
    }

    struct node *current = head;
    struct node *temp;
    if (pos == 1)
    {
        deleteAtStart();
    }
    else
    {
        for (int i = 2; i <= pos - 1; i++)
        {
            current = current->next;
        }

        temp = current->next;
        current->next = temp->next;

        free(temp);
        printf("\t\t\t ELEMENT DELETED ");
    }
}

// search
void search(int num)
{
    int counter = 1;
    if (head == NULL)
    {
        printf("\n\t\t\t NOTHING TO SEARCH ---(*,*)---\n");
        return;
    }
    struct node *temp = head;
    while (temp->data != num)
    {
        temp = temp->next;
        counter++;
        if (temp == head)
        {
            printf("\n\t\t\t ELEMENT NOT PRESENT__(x.x)__ \n");
            return;
        }
    }

    printf("\n\t\t\tELEMENT FOUND IN THE LIST AT POSITION : %d \n", counter);
}

void main()
{
    int choice, pos, key, num;

    do
    {
        printf("\n\n********/_(^u^)_/*********\n");
        printf("\n 1. Insert in Sorting order");
        printf("\n 2. delete in begining");
        printf("\n 3. delete in middle position");
        printf("\n 4. delete in end");
        printf("\n 5. DISPLAY");
        printf("\n 6. SERACH");
        printf("\n 7. EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\t\t\tEnter the number to add : ");
            scanf("%d", &num);
            sortAdd(num);
            break;
        case 2:
            deleteAtStart();
            break;
        case 3:

            printf("\t\t\tEnter the position to delete : ");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;
        case 4:

            deleteAtEnd();
            break;
        case 5:
            display();
                        break;
        case 6:
            printf("\t\t\tEnter the number to be search : ");
            scanf("%d", &key);
            search(key);
            break;
        }

    } while (choice != 7);
}
