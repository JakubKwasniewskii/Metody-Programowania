#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 100;
const string stackEmptyInfo = "Stack is empty. ";

class Stack {
    int arr[MAX];
    int top = -1;
public:
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }
    void push(int x) {
        if (isFull()) {
            cout << "Stack is Full.\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << stackEmptyInfo << "\n";
            return;
        }
        top--;
    }
    int peek() {
        if (!isEmpty())
            return arr[top];
        cout << stackEmptyInfo << "\n";
        return -1;

    }

    int getSize() {
        return top + 1;
    }

    void printStack() {
        if (isEmpty()) {
            cout << stackEmptyInfo << "\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << "\n";
        }
    }

    void resetStack() {
        top = -1;
    }
};
int main()
{
    setlocale(LC_CTYPE, "Polish");

    Stack mojStos;
    cout << "Czy stos jest pusty? (1 = Tak, 0 = Nie): " << mojStos.isEmpty() << "\n";

    mojStos.push(10);
    mojStos.push(20);
    mojStos.push(30);

    cout << "Element na samej górze stosu: " << mojStos.peek() << "\n";
    cout << "Czy stos jest pełny?: " << mojStos.isFull() << "\n";
    mojStos.pop();
    cout << "Teraz na górze jest: " << mojStos.peek() << "\n";

    int liczbaElementow;
    cout << "Podaj liczbę elementów" << endl;
    cin >> liczbaElementow;

    for (int i = 0; i < liczbaElementow; i++) {
        int losowaLiczba = rand() % 100;
        mojStos.push(losowaLiczba);
        cout << losowaLiczba << " " << endl;
    }

    cout << "Liczba elementów w stosie wynosi: " << mojStos.getSize() << endl;

    if (liczbaElementow == mojStos.getSize()) {
        cout << "Wyniki się zgadzają " << liczbaElementow << " liczba elementów w stosie: " << mojStos.getSize() << endl;
    }
    else {
        cout << "Liczby się nie zgadzają" << endl;
    }

    mojStos.printStack();

    mojStos.resetStack();
    mojStos.printStack();
    mojStos.push(50);
    mojStos.push(60);
    mojStos.push(70);
    mojStos.printStack();
    mojStos.pop();
    mojStos.printStack();

    return 0;
}