#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define max 10
int size = 0;
struct node
{
    char data[max];
    struct node *next;
};

struct node *head = NULL;

// AT START
void addAtStart(char name[])
{
    struct node *newNode = malloc(sizeof(struct node));
    size++;
    strcpy(newNode->data, name);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// AT END
void insertAtEnd(char name[])
{
    struct node *newNode = malloc(sizeof(struct node));
    size++;
    strcpy(newNode->data, name);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// AT SPECIFIED POSITION
void insertAtMiddle(char name[], int pos)
{

    struct node *newNode = malloc(sizeof(struct node));
    strcpy(newNode->data, name);
    newNode->next = NULL;
    size++;

    struct node *temp;
    temp = head;

    if (pos == 1)
    {
        addAtStart(name);
    }
    for (int i = 2; i <= pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            break;
        }
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("UNABLE TO FIND THE GIVEN POSITION (o_|_o) \n");
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\t\t\t LIST IS EMPTY (-v-) ");
        return;
    }
    struct node *temp;
    temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("\t\t\t%d.) ", i);
        printf(temp->data);
        printf("\n");
        temp = temp->next;
        i++;
    }
}

void delete (char key[])
{
    struct node *current;
    struct node *previous;
    current = head;

    if (strcmp(current->data, key) == 0 && current != NULL)
    {
        head = current->next;
        free(current);
        return;
    }
    while (strcmp(current->data, key) != 0 && current != NULL)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("NAME NOT FOUND (˘︹˘)\n");
    }
    else
    {
        previous->next = current->next;
    }

    free(current);
}

// sort the names
void sort()
{
    if (head == NULL)
    {
        printf("\n\t\t\t Nothing to sort (-.-) ");
        return;
    }
    struct node *current;
    struct node *temp;
    current = head;

    while (current->next != NULL)
    {
        temp = current->next;
        while (temp != NULL)
        {
            char t[max];
            char t1[max];
            char t2[max];
            strcpy(t1, current->data);
            strcpy(t2, temp->data);
            if (strcmp(t1, t2) > 0)
            {
                strcpy(t, t1);
                strcpy(t1, t2);
                strcpy(t2, t);

                strcpy(current->data, t1);
                strcpy(temp->data, t2);
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

void main()
{
    char input[max], input1[max], input2[max], key[max];
    int pos, choice;
 
    do
    {
        printf("\n\n********/_(^u^)_/*********\n");
        printf("\n 1. Add at the START");
        printf("\n 2. Add at the END");
        printf("\n 3. Add in the MIDDLE");
        printf("\n 4. DELETE");
        printf("\n 5. DISPLAY");
        printf("\n 6. SORT");
        printf("\n 7. EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\t\t\tEnter the name : ");
            scanf("%s", &input);
            addAtStart(input);
            break;
        case 2:

            printf("\t\t\tEnter the name : ");
            scanf("%s", &input1);
            insertAtEnd(input1);
            break;
        case 3:

            printf("\t\t\tEnter the name : ");
            scanf("%s", &input2);
            printf("\t\t\tEnter the position : ");
            scanf("%d", &pos);
            insertAtMiddle(input2, pos);
            break;
        case 4:

            printf("\t\t\tEnter the name to delete : ");
            scanf("%s", &key);
            delete (key);
            break;
        case 5:
            display();
            break;
        case 6:
            sort();
            break;
        }

    } while (choice != 7);
}
