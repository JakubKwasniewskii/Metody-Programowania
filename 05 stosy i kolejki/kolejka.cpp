#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 100;
const string queueEmptyInfo = "Queue is empty. ";

class Queue {
    int arr[MAX];
    int first = 0;
    int last = 0;

public:
    bool isEmpty() {
        return first == last;
    }

    bool isFull() {
        return last == MAX;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        arr[last++] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << queueEmptyInfo << "\n";
            return;
        }
        first++;
    }

    int peek() {
        if (!isEmpty())
            return arr[first];
        cout << queueEmptyInfo << "\n";
        return -1;
    }

    int getSize() {
        return last - first;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << queueEmptyInfo << "\n";
            return;
        }
        for (int i = last - 1; i >= first; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void resetQueue() {
        first = 0;
        last = 0;
    }

};

int main()
{
    setlocale(LC_CTYPE, "Polish");

    Queue mojaKolejka;
    cout << "Czy kolejka jest pusta? (1 = Tak, 0 = Nie): " << mojaKolejka.isEmpty() << "\n";

    mojaKolejka.enqueue(10);
    mojaKolejka.enqueue(20);
    mojaKolejka.enqueue(30);

    cout << "Pierwszy element w kolejce to: " << mojaKolejka.peek() << "\n";
    cout << "Czy kolejka jest pełna?: " << mojaKolejka.isFull() << "\n";
    mojaKolejka.dequeue();
    cout << "Teraz pierwszy element w kolejce to: " << mojaKolejka.peek() << "\n";

    int liczbaElementow;
    cout << "Podaj liczbę elementów do dodania do kolejki: ";
    cin >> liczbaElementow;

    for (int i = 0; i < liczbaElementow; i++) {
        int losowaLiczba = rand() % 100; 
        mojaKolejka.enqueue(losowaLiczba);
        cout << losowaLiczba << " " << endl;
    }

    cout << "Liczba elementów w kolejce wynosi: " << mojaKolejka.getSize() << "\n";

    if (liczbaElementow == mojaKolejka.getSize()) {
        cout << "Wyniki się zgadzają " << liczbaElementow << "liczba elementów w kolejce: " << mojaKolejka.getSize() << "\n";
    }
    else {
        cout << "Liczby się nie zgadzają.\n";
    }

    mojaKolejka.printQueue();

    mojaKolejka.resetQueue();
    mojaKolejka.printQueue();
    mojaKolejka.enqueue(55);
    mojaKolejka.enqueue(65);
    mojaKolejka.enqueue(75);
    mojaKolejka.printQueue();
    mojaKolejka.dequeue();
    mojaKolejka.printQueue();

    return 0;
}
