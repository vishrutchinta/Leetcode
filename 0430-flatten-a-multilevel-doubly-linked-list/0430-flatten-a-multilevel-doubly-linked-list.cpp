// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node* child;
// };
// */

// class Solution {
// public:
//     Node* taill(Node* head){
//         Node* temp = head;
//         while(temp->next!=NULL){
//             temp = temp->next;
//         }
//         return temp;
//     }
//     Node* flatten(Node* head) {
//         Node* temp = head;
//         Node* tail = head;
//         Node* curr = head;
    
//         if(tail->next == NULL){
//             return tail;
//         }
//         while(temp!=NULL && temp->child == NULL){
//             temp = temp->next;
//         }
//         while(tail->next != NULL){
//             tail = tail->next;
//         }
//         if(temp!=NULL && temp->next != NULL){
//             curr = temp->next;
//         }
        
        
//         Node* temp2 = flatten(temp->child);
//         Node* temp3 = taill(temp2);
//         temp3->next = curr;
//         curr->prev = temp3;
//         temp->next = temp2;
//         temp2->prev = temp;
        
//         return head;
        

        
//     }
// };

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* taill(Node* head){
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp;
    }

    Node* flatten(Node* head) {
        if(head == NULL) return head;

        Node* temp = head;

        // find first node (from head onward) that has a child
        while(temp != NULL && temp->child == NULL){
            temp = temp->next;
        }

        if(temp != NULL){
            Node* curr = temp->next;

            Node* temp2 = flatten(temp->child);   // flatten the child list
            Node* temp3 = taill(temp2);            // find its tail

            temp->next = temp2;
            temp2->prev = temp;
            temp->child = NULL;

            temp3->next = curr;
            if(curr != NULL){
                curr->prev = temp3;
            }

            // keep scanning the rest of the list for more children
            flatten(curr);
        }

        return head;
    }
};