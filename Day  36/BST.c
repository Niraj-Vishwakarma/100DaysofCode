#include <stdio.h>
#include <stdlib.h>
#define bool int

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

// new node function
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}

// insert function
struct node *insert(struct node *node, int key)
{
    
    if (node == NULL)
      {  printf("\n\t\t\t Element inserted");
        return newNode(key);
      }

    if (key < node->data)
        node->leftChild = insert(node->leftChild, key);

    else if (key > node->data)
        node->rightChild = insert(node->rightChild, key);

     
    return node;
}

// required for node deletion
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current && current->leftChild != NULL)
        current = current->leftChild;

    return current;
}

// delete
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->leftChild = deleteNode(root->leftChild, key);

    else if (key > root->data)
        root->rightChild = deleteNode(root->rightChild, key);

    else
    {
        if (root->leftChild == NULL)
        {
            struct node *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            struct node *temp = root->leftChild;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->rightChild);

        root->data = temp->data;

        root->rightChild = deleteNode(root->rightChild, temp->data);
    }
    return root;
}
// counting leaf node
int getLeafCount(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        return 1;
    }
    else
    {
        return (getLeafCount(root->leftChild) + getLeafCount(root->rightChild));
    }
}

// stack creation for inorder transversal
struct sNode
{
    struct node *t;
    struct sNode *next;
};

// Stack related functions
void push(struct sNode **top_ref, struct node *t);
struct node *pop(struct sNode **top_ref);
bool isEmpty(struct sNode *top);

// inorder using iteration
void inOrder(struct node *root)
{

    struct node *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {

        if (current != NULL)
        {
            push(&s, current);
            current = current->leftChild;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->rightChild;
            }
            else
                done = 1;
        }
    }
}

// push
void push(struct sNode **top_ref, struct node *t)
{
    struct sNode *new_node =
        (struct sNode *)malloc(sizeof(struct sNode));

    if (new_node == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }

    new_node->t = t;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

bool isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}

struct node *pop(struct sNode **top_ref)
{
    struct node *res;
    struct sNode *top;

    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

struct node *newnode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return (node);
}


void main()
{
    
     
    struct node *root = NULL;
    int choice, input, key;
   do
    {
        
        printf("\n\n********/_(^u^)_/*********\n");
        printf("\n 1. INSERT ELEMENT");
        printf("\n 2. DELETE");
        printf("\n 3. INORDER TRANSVERSE");
        printf("\n 4. COUNT LEAF-NODES");
        printf("\n 5. EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\t\t\tEnter the element to be added : ");
            scanf("%d", &input);
            if(root == NULL)
            {
            root = insert(root, input);
            }
            else  {
                insert(root, input);
            }
            break;
        case 2:

            printf("\t\t\tEnter the element to be deleted : ");
            scanf("%d", &key);
            deleteNode(root, key);
            break;
        case 3:
            printf("\n\t\t\t");
              inOrder(root);
            break;
        case 4:
             printf("\n\t\t\t The total leaf-nodes are : %d",getLeafCount(root));
            break;
        }

    } while (choice != 5);
}
