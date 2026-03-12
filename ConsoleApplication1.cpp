// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream> 
using namespace std;
int silnia(int n) {
	if (n == 0)  
		return 1;
	else
		return n * silnia(n - 1); 
}
int fibonacci(int n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int sumaCyfr(int n) {
	if (n <= 0) {
		return 0;
	};
	return sumaCyfr(n / 10) + (n % 10);
}
int liczbaWystapien(int n, int cyfra) {
	if (n <= 0) {
		return 0;
	};
	return ((n % 10) == cyfra ? 1 : 0) + liczbaWystapien((n / 10), cyfra);
	
	
}
int main() {
	setlocale(LC_CTYPE, "Polish");
	for (int i = 0; i < 3; i++) {
		int n;
		cout << "Podaj liczbę: ";
		cin >> n;

		if (n < 0) {
			cout << "Wartosc mniejsza od zera!\n";
		}
		else {
			cout << "Silnia " << n << " wynosi: " << silnia(n) << endl;
		}
	}
	int n;
	cout << "Podaj liczbe ciagu" << endl;
	cin >> n;
	cout << fibonacci(n);
	cout << "Podaj liczbę" << endl;
	int n;
	cin >> n;
	cout << sumaCyfr(n);
	cout << liczbaWystapien(3, 3213);


	
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
