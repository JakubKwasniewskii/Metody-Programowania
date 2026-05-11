#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct DNode 
{
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr){}
};

void pushFront(DNode*& head, int val) {
    DNode* newNode = new DNode(val);
    if (head) head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void popBack(DNode*& head) {
    if (!head) return;
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = nullptr;
    else head = nullptr;
    delete temp;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");

    DNode* head = nullptr;
    pushFront(head, 10);
    pushFront(head, 20);
    pushFront(head, 30);

    int n;
    cout << "Ile losowych elementów dodać do listy ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        pushFront(head, rand() % 100);
    }

    cout << "Zawartość listy: ";
    DNode* temp = head;

    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;

 

    return 0;
}

