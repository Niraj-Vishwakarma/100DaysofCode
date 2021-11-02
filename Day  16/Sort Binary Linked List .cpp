/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* solve(listnode* A) {

int oc=0;
int zc =0;
listnode *temp ;
temp = A;
while(temp != NULL)
{

    if(temp->val == 1)
    {
        oc++;
    } else {
        zc++;
    }
    temp = temp->next;
}

temp = A;
while(zc--)
{
    temp->val =0;
    temp = temp->next;
}
while(oc--)
{
    temp->val =1;
    temp = temp->next;
}


return (A);

}
