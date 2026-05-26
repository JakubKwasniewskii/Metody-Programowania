#include <iostream> 
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

long long swapCount = 0;
long long binarySearchCalls = 0;

int binarySearch(int arr[], int left, int right, int target) {
    binarySearchCalls++;
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        else
            return binarySearch(arr, mid + 1, right, target);
    }
    return -1;  
}

void swap(int& a, int& b) {
    swapCount++;
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    setlocale(LC_CTYPE, "Polish");

   /*
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    int minVal, maxVal;
    cout << "Podaj zakres min: ";
    cin >> minVal;
    cout << "Podaj zakres max: ";
    cin >> maxVal;

    int* arr = new int[n];
    cout << "Tablica: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (maxVal - minVal + 1) + minVal;
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);
    cout << "Posortowana tablica: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int target;
    cout << "Podaj liczbę do znalezienia: " << endl;
    cin >> target;
    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element znaleziony na indeksie " << result << endl;
    else
        cout << "Element nie znaleziony" << endl;
   */
   
    /*
    const int N = 2000000; 
    int* arr1 = new int[N];

    
    for (int i = 0; i < N; i++) arr1[i] = rand(); 
    auto start = high_resolution_clock::now();
    quickSort(arr1, 0, N - 1);
    auto stop = high_resolution_clock::now();
    chrono::duration<double> duration = stop - start; 
    cout << "Czas QuickSort: " << duration.count() << " sekund" << endl;

    
    for (int i = 0; i < N; i++) arr1[i] = rand(); 
    start = high_resolution_clock::now();
    sort(arr1, arr1 + N);
    stop = high_resolution_clock::now();
    duration = stop - start; 
    cout << "Czas sort: " << duration.count() << " sekund" << endl;
    */
    /*
     czas losowania dla QuickSort oraz dla dla funkcji sort()
     QuickSort:
     1 loswanie dla 1000000 liczb losowanych - 0.170881 sekundy
     2 loswanie dla 1500000 liczb losowanych - 0.272088 sekundy
     3 loswanie dla 2000000 liczb losowanych - 0.416912 sekundy

     sort():
     1 loswanie dla 1000000 liczb losowanych - 0.328570 sekundy
     2 loswanie dla 1500000 liczb losowanych - 0.530816 sekundy
     3 loswanie dla 2000000 liczb losowanych - 0.638574 sekundy
    */

    /*
    int N = 1400; 
    int* arr = new int[N];

    
    for (int i = 0; i < N; i++) arr[i] = i;

    
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, N - 1);
    auto stop = high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;
    cout << "Czas QuickSort dla posortowanej tablicy: " << duration.count() << " sekund" << endl;

    
    for (int i = 0; i < N; i++) arr[i] = i;

    
    start = high_resolution_clock::now();
    sort(arr, arr + N);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << "Czas sort dla posortowanej tablicy: " << duration.count() << " sekund" << endl;
    */

    /*
     czas losowania dla QuickSort oraz dla dla funkcji sort()
     QuickSort:
     1 loswanie dla 1400 liczb losowanych - 0.005349 sekundy
     2 loswanie dla 1600 liczb losowanych - 0.0067998 sekundy
     3 loswanie dla 1800 liczb losowanych - 0.008701 sekundy

     sort():
     1 loswanie dla 1400liczb losowanych - 0.0001428 sekundy
     2 loswanie dla 1600 liczb losowanych - 0.0001737 sekundy
     3 loswanie dla 1800 liczb losowanych - 0.0001796 sekundy
    */
    
/*
int N = 1800; 
int* arr = new int[N];


for (int i = 0; i < N; i++) arr[i] = N - i;


auto start = high_resolution_clock::now();
quickSort(arr, 0, N - 1);
auto stop = high_resolution_clock::now();
chrono::duration<double> duration = stop - start;
cout << "Czas QuickSort malejąco: " << duration.count() << " sekund" << endl;


for (int i = 0; i < N; i++) arr[i] = N - i;


start = high_resolution_clock::now();
sort(arr, arr + N);
stop = high_resolution_clock::now();
duration = stop - start;
cout << "Czas sort malejąco: " << duration.count() << " sekund" << endl;
*/

/*
    czas losowania dla QuickSort oraz dla dla funkcji sort()
    QuickSort:
    1 loswanie dla 1400 liczb losowanych - 0.0034267 sekundy
    2 loswanie dla 1600 liczb losowanych - 0.0048778 sekundy
    3 loswanie dla 1800 liczb losowanych - 0.0056755 sekundy

    sort():
    1 loswanie dla 1400 liczb losowanych - 0.0001668 sekundy
    2 loswanie dla 1600 liczb losowanych - 0.0002035 sekundy
    3 loswanie dla 1800 liczb losowanych - 0.0002302 sekundy
   */

   
int sizes[] = { 10, 100, 1000, 10000, 100000, 1000000 };


for (int sz : sizes) { 
    int* arr = new int[sz];

    
    for (int i = 0; i < sz; i++) arr[i] = rand();

    
    swapCount = 0; 
    auto startQS = high_resolution_clock::now();
    quickSort(arr, 0, sz - 1);
    auto stopQS = high_resolution_clock::now();
    double timeQS = duration<double>(stopQS - startQS).count();

    
    binarySearchCalls = 0; 
    int target = arr[sz / 2]; 
    auto startBS = high_resolution_clock::now();
    binarySearch(arr, 0, sz - 1, target);
    auto stopBS = high_resolution_clock::now();
    double timeBS = duration<double>(stopBS - startBS).count();

    double totalTime = timeQS + timeBS;

    
    cout << "Rozmiar tablicy: " << sz << endl; ;
    cout << "Czas QuickSort: " << timeQS << " s " << endl;
    cout << "Liczba operacji swap: " << swapCount << " " << endl;
    cout << "Czas BinarySearch: " << timeBS << " s " << endl;
    cout << "Liczba wywołań BinarySearch: " << binarySearchCalls << " " << endl;
    cout << "Czas łączny: " << totalTime << " s " << endl;
    cout << endl;
    
}

return 0;
}
