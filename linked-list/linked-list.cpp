#include <iostream>


using namespace std;

struct Node {
    int data;
    struct Node *nextPtr;
};

class linked_list {
private:
    Node *head;
    Node *tail;
public:
    linked_list(){
        head = nullptr;
        tail = nullptr;
    }
    void add_node(int data) {
        Node *tmp = new Node;
        tmp->data = data;
        tmp->nextPtr = nullptr;
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->nextPtr = tmp;
            tail = tail->nextPtr;
        }
    }


    void insert_node(int _data,int index){
        Node* current = head;
        Node* tmp = new Node;
        tmp -> data = _data;

        while(current != NULL){
            if(current->data == index){
                tmp->nextPtr = current->nextPtr;
                current->nextPtr = tmp;
                break;
            }
            current = current -> nextPtr;
        }
    }

    void remove_node(int index){
        Node* current = head;
        Node* tmp = new Node;


        while(current != NULL){
            if(current->nextPtr->data == index){
                tmp->nextPtr = current->nextPtr->nextPtr;
                current->nextPtr = NULL;
                current->nextPtr = tmp->nextPtr;

                break;
            }
            current = current -> nextPtr;
        }
    }


    void add_node_into_begin(int data){
        Node *tmp = new Node;
        tmp->data = data;
        tmp->nextPtr = head;
        head = tmp;
    }


    void printList() {
        Node *current = head;

        while (current != nullptr) {
            cout << current->data << endl;
            current = current->nextPtr;
        }
    }
};


int main() {

    linked_list liste1;
    

    return 0;
}
