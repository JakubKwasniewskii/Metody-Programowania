#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* tail;
    Node(int val) : data(val), next(tail), tail(next) {}
};

void pushFront(Node*& head, int val) {
    Node* newNode = new Node(val);
    Node* temp = newNode->next;
    newNode->next = head;
    newNode->tail = temp;
    head = newNode;
}

void popFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head->tail = head->next;
    head = head->next;
    delete temp;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");

    Node* head = nullptr;
    pushFront(head, 10);
    pushFront(head, 20);
    pushFront(head, 30);
    printList(head);
    popFront(head);
    printList(head);

    return 0;
}


