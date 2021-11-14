/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* head, int x) {
    queue<int> q1;

queue<int> q2;

ListNode* curr=head;

int count=0;

while(curr!=NULL){

if(curr->val<x){

q1.push(curr->val);

}

else{

q2.push(curr->val);

}

curr=curr->next;

count++;

}

curr=head;

while(!q1.empty()){

curr->val=q1.front();

q1.pop();

curr=curr->next;

}

while(!q2.empty()){

curr->val=q2.front();

q2.pop();

curr=curr->next;

}

return head;


    
}
