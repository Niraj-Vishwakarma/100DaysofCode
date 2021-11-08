#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next; 
    struct node *prev; 
};

struct node *head = NULL;

void addAtStart(int num)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (head==NULL)
    {
        head = newNode;
    newNode->next = head;
    newNode->prev = head;
    } else {
   
   //transvere till end

    struct node *temp = head;
    while(temp->next != head) {
      temp = temp->next;
        }  

    // add
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next =head;
    (head)->prev = newNode;
    head = newNode;  
    }
}

void addAtEnd(int num)
{
struct node *temp;
struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;
  newNode->prev = NULL;
  if(head == NULL)
  {
      addAtStart(num);
  } else {

       temp = head;
    while(temp->next != head) {
      temp = temp->next;
    } 
    temp->next = newNode;
    newNode->next = head;
    newNode->prev = temp;
    head->prev = newNode;

  }

}

void addAtPos(int num, int pos)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;
  newNode->prev = NULL;
  struct node *current = head;
  if(pos == 1)
  {
      addAtStart(num);
  } else 
  {
       //transverse elemnent after which to insert
       for (int i = 2; i <= pos - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        newNode->prev = current;
        newNode->next->prev = newNode;
  }
}

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
    head->next->prev = temp;
    temp = head;
    head = head->next; 
    free(temp);
    printf("\t\t\t ELEMENT DELETED ");

}

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
    head->prev = current;
    free(temp);
    printf("\t\t\t ELEMENT DELETED ");
}
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
        temp->next->prev = current;
        free(temp);
        printf("\t\t\t ELEMENT DELETED ");
    }
}


void display()
 {
    if (head == NULL)
    {
        printf("\n\t\t\t LIST IS EMPTY _(-U-)_\n");
        return;
    }
    struct node *temp = head;
    
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



void main ()
{
    int choice, num, num1, num2 , pos, pos2;
  do
    {
        printf("\n\n********/_(^u^)_/*********\n");
        printf("\n 1. Insert at start");
        printf("\n 2. Insert at end");
        printf("\n 3. Insert at specific position");
        printf("\n 4. delete in begining");
        printf("\n 5. delete in middle position");
        printf("\n 6. delete in end");
        printf("\n 7. DISPLAY");
        printf("\n 8. EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\t\t\tEnter the number to add : ");
            scanf("%d", &num);
            addAtStart(num);
            break;
        case 2:
            printf("\t\t\tEnter the number to add : ");
            scanf("%d", &num1);
            addAtEnd(num1);
            break;
        case 3:
             printf("\t\t\tEnter the number to add : ");
            scanf("%d", &num2);
            printf("\t\t\tEnter the position to add : ");
            scanf("%d", &pos);
            addAtPos(num2, pos);
            break;
        case 4:

           deleteAtStart();
            break;
        case 5:
             printf("\t\t\tEnter the position to delete : ");
            scanf("%d", &pos2);
            deleteAtPos(pos2);
                        break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            display();
            break;
        }

    } while (choice != 8);
 
}
