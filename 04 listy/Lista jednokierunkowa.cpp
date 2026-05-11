#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node
{
    int data; 
    Node* next;
    Node(int val) : data(val), next(nullptr){}
};

void pushFront(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void pushBack(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void popFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void popBack(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

Node* findNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");

    Node* mojaLista = nullptr;
    pushFront(mojaLista, 10);
    pushFront(mojaLista, 20);
    printList(mojaLista);

    pushBack(mojaLista, 30);
    pushBack(mojaLista, 40);
    printList(mojaLista);

    popFront(mojaLista);
    printList(mojaLista);

    popBack(mojaLista);
    printList(mojaLista);

    Node* mojaLista2 = nullptr;
    int n;
    cout << "Podaj liczbę węzłów do wygenerowania: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int losowaWartosc = rand() % 100;
        pushBack(mojaLista2, losowaWartosc);
    }
    printList(mojaLista2);

    int liczbaWezlow = countNodes(mojaLista2);
    cout << "Liczba węzłów w liscie: " << liczbaWezlow << endl;

    if (liczbaWezlow == n) {
        cout << " Liczba węzłów zgadza się" << " " << n << endl;
    }
    else {
        cout << "Liczba węzłów jest inna" << endl;
    }

    int szukana;
    cout << "Podaj wartość do odszukania: ";
    cin >> szukana;

    Node* wynik = findNode(mojaLista2, szukana);

    if (wynik != nullptr) {
        cout << "Znaleziono węzeł o wartości " << szukana << " pod adresem: " << wynik << endl;
    }
    else {
        cout << "Wartość " << szukana << " nie istnieje w liscie" << endl;
    }

    return 0;
}


