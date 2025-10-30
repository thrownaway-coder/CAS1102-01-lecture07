#include <iostream>
#include <cstring>

struct Node {
    char ch;
    Node* next; 

    Node(char character) : ch(character), next(nullptr) {}
};

void makeList(const char* s, Node*& head, Node*& tail) {
    head = nullptr; 
    tail = nullptr;

    for (int i = 0; s[i] != '\0'; ++i) {
        Node* newNode = new Node(s[i]);

        if (head == nullptr) {
            head = newNode; 
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        std::cout << cur->ch;
        cur = cur->next;
    }
    std::cout << '\n';
}

int main() {
    Node* helloHead = nullptr;
    Node* helloTail = nullptr;
    makeList("Hello ", helloHead, helloTail);

    Node* nameHead = nullptr;
    Node* nameTail = nullptr;
    makeList("MyName", nameHead, nameTail); 

    if (helloTail != nullptr) {
        helloTail->next = nameHead;
    } else {
        helloHead = nameHead;
    }
    
    printList(helloHead); 

    Node* current = helloHead;
    while (current != nullptr) {
        Node* nextNode = current->next; 
        delete current;                 
        current = nextNode;             
    }

    return 0;
}
