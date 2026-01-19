//ADD ONE TO LINKED LIST
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    return prev;
    }
  public:
    Node* addOne(Node* head) {
        int carry = 1;
        head = reverse(head);
        Node* temp = head;
        
         while (temp != NULL && carry) {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;

            if (temp->next == NULL && carry)
                temp->next = new Node(0);

            temp = temp->next;
        }
    return reverse(head);
    }
};
