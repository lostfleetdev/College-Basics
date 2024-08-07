// traverse ,list ,insert ,delete ,search
// singly
#include <iostream>

using namespace std;

struct Node{
    int num;
    Node* nxt;

    Node(int data){
        num = data;
    }
};

Node* add(Node* head, int data){
    Node* current = head;
    if (head == nullptr) {
        return new Node(data);
    }
    
    while (current->nxt != nullptr) {
        current = current->nxt;
    }
    current->nxt = new Node(data);
    return head;

}

Node* search_list(Node* head, int key){
    Node* current = head;
    while(current != nullptr){
        if(current->num == key){
            return current;
        }
        current = current->nxt;
    }
    return nullptr;
}

void prnt_lst(Node* head){
    Node* cur = head;
    while(cur != nullptr){
        cout << cur->num << "\t";
        cur = cur->nxt;
    }
    cout << endl;
}

int main(){
    Node* head = nullptr;
    head = add(head, 45);
    head = add(head, 48);
    head = add(head, 58);
    head = add(head, 76);
    head = add(head, 7);
    head = add(head, 8);

    prnt_lst(head);
    cout << "Find: ";
    int n;
    cin >> n;
    /*
    if(n != 0){
        cout << "Number " << n << " present at pointer"
    }*/
    return 0;
}
