#include <iostream>
#include <vector>
#include <string>
using namespace std;
class GraphMatrix {
private:
	std::vector<std::vector<int>> graphMatrix;
	int verticesNumber;
public:
	GraphMatrix(int vertices) {
		verticesNumber = vertices;
		graphMatrix.resize(vertices, std::vector<int>(vertices, 0));
	}
	void addEdge(int i, int j) {
		graphMatrix[i][j] = 1;
		graphMatrix[j][i] = 1; // usuń, jeśli graf ma być skierowany
	}
	void print(const vector<string>& names) {
		cout << "Matrix" << endl;
		for (const string& name : names)
			cout << name << " " << endl;
	
		for (int i = 0; i < verticesNumber; ++i) {
			for (int j = 0; j < verticesNumber; ++j) {
				std::cout << graphMatrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
};

class GraphList {
private:
	std::vector<std::vector<int>> graphList;
public:
	GraphList(int vertices) {
		graphList.resize(vertices);
	}
	void addEdge(int u, int v) {
		graphList[u].push_back(v);
		graphList[v].push_back(u); // usuń, jeśli graf ma być skierowany
	}
	void print(const vector<string>& names) {
		cout << "List" << endl;
		for (int i = 0; i < graphList.size(); ++i) {
			std::cout << names[i] << ": ";
			for (int neighbor : graphList[i]) {
				std::cout << names[neighbor] << " ";
			}
			std::cout << "\n";
		}
	}
};
int main()
{
	setlocale(LC_CTYPE, "Polish");
	cout << "Matrix" << endl;
	// Tworzymy graf o 3 wierzchołkach
	GraphMatrix gm(3);

	// Dodaje krawędzie
	gm.addEdge(0, 1); // Połączenie między 0 a 1
	gm.addEdge(1, 2); // Połączenie między 1 a 2
	
	//Wyświetlenie macierzy
	 // gm.print();

	cout << "Neighborhood Lists" << endl;

	GraphList gl(3);

	// Dodaje krawędzie
	gl.addEdge(0, 1); // Połączenie między 0 a 1;
	gl.addEdge(1, 2); // Połączenie między 1 a 2;

	// Wyświetlanie listy
	// gl.print(); 
	
	// Wybór sposobu reprezentacji grafu
	int choice;
	cout << "Choose graph representation " << endl;
	cout << "1- Adjacency Matrix " << endl;
	cout << "2- Adjacency List " << endl;
	cout << "Your choice: ";
	cin >> choice;

	// Wybór liczby wierzchołków
	int vertexCount;
	cout << "Enter the number of vertices: ";
	cin >> vertexCount;

	// Wpisanie nazw wierzchołków
	vector<string> vertexNames(vertexCount);
	cout << "Enter the name for each vertex: " << endl;
	for (int i = 0; i < vertexCount; ++i) {
		cout << "Vertex " << i << ": ";
		cin >> vertexNames[i];
	}

	// Tworzenie obiektów obu klas
	GraphMatrix gmm(vertexCount);
	GraphList gll(vertexCount);

	// Stworzenie grafu
	int edgeCount;
	cout << "How many edges do you want to add?: ";
	cin >> edgeCount;

	cout << "Enter edges by typing two vertex names: " << endl;
	for (int k = 0; k < edgeCount; ++k) {
		string start, end;
		cout << "Edge " << k + 1 << ": ";
		cin >> start >> end;
		// Szukanie indesku liczbowego dla wpisanej nazwy start
		int idStart = -1;
		for (int i = 0; i < vertexCount; ++i) {
			if (vertexNames[i] == start) {
				idStart = i;
				break;
			}
		}
		// szukanie indesku liczbowego dla wpisanej nazwy end
		int idEnd = -1;
		for (int i = 0; i < vertexCount; ++i) {
			if (vertexNames[i] == end) {
				idEnd = i;
				break;
			}
		}
		// jeśli obie nazwy zostały znalezione
		if (idStart != -1 && idEnd != -1) {
			if (choice == 1) {
				gmm.addEdge(idStart, idEnd);
			} 
			else
			{
				gll.addEdge(idStart, idEnd);
			}

		}
		else {
			// jesli uzytkownik wpisał złą nazwę
			cout << "ERROR- Vertex name does not exist" << endl;
			k--;
		}
	}
	// Wyświetlenie 
	if (choice == 1) {
		gmm.print(vertexNames);
	}
	else {
		gll.print(vertexNames);
	}

	return 0;
}

