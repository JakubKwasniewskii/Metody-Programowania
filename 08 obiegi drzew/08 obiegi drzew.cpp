#include <vector>
#include <iostream>
#include <stack>
#include <string>

using namespace std;



struct Node
{
	string data;
	vector<shared_ptr<Node>> children;
	Node(const string& d) : data(d) {}
};



void addChild(shared_ptr<Node> parent, shared_ptr<Node> child) {
	parent->children.push_back(child);
}

void inorder(shared_ptr<Node> node) {
	if (node == NULL)
		return;

	int total = node->children.size(); // modyfikacja kodu z length na children.size() by pobrac liczbę dzieci

	for (int i = 0; i < total - 1; i++) {
		inorder(node->children[i]);
	}

	cout << node->data << ", " << endl;
	if (total > 0) {
		inorder(node->children[total - 1]);
	}
}

vector<string> preorder(shared_ptr<Node> root) {
	if (!root) return {};

	vector<string> result;
	stack<shared_ptr<Node>> nodes;
	nodes.push(root);

	while (!nodes.empty()) {
		shared_ptr<Node> current = nodes.top();
		result.push_back(current->data);
		nodes.pop();

		int size = current->children.size();
		for (int i = size - 1; i >= 0; --i) {
			nodes.push(current->children[i]);
		}
	}
	return result;
}

void printTree(const shared_ptr<Node>& node, int depth = 0) {
	for (int i = 0; i < depth; ++i) cout << "  ";
	cout << node->data << "\n";
	for (const shared_ptr<Node>& child : node->children) {
		printTree(child, depth + 1);
	}
}
int main()
{
	setlocale(LC_CTYPE, "Polish");
	shared_ptr<Node> KGP = make_shared<Node>("Komendant Główny Policji");
	shared_ptr<Node> PZK = make_shared<Node>("Pierwszy zastepca KGP");
	shared_ptr<Node> ZKGP = make_shared<Node>("Zastępca KGP");
	shared_ptr<Node> ZKGPs = make_shared<Node>("Zastępca KGP");
	shared_ptr<Node> GKGP = make_shared<Node>("Gabinet komendanta Głównego Policji");
	shared_ptr<Node> BKS = make_shared<Node>("Biuro komunikacji Społecznej");
	shared_ptr<Node> BKiOP = make_shared<Node>("Biuro Kadr i organizacji Policji");
	shared_ptr<Node> BP = make_shared<Node>("Biuro Prawne");
	shared_ptr<Node> BBI = make_shared<Node>("Biuro Bezpieczeństwa Informacji");
	shared_ptr<Node> BK = make_shared<Node>("Biuro Kontroli");
	shared_ptr<Node> WOP = make_shared<Node>("Wydział Ochrony Pracy");
	shared_ptr<Node> ZAW = make_shared<Node>("Zespół Audytu Wewnętrznego");
	shared_ptr<Node> BKr = make_shared<Node>("Biuro Kryminalne");
	shared_ptr<Node> BZPE = make_shared<Node>("Biuro Zwalczania Przestępczości Ekonomicznej");
	shared_ptr<Node> BWiIK = make_shared<Node>("Biuro Wywiadu i Informacji Kryminalnych");
	shared_ptr<Node> BMWP = make_shared<Node>("Biuro Międzynarodowej Współpracy Policji");
	shared_ptr<Node> BLP = make_shared<Node>("Biuro Logistyki Policji");
	shared_ptr<Node> BŁiI = make_shared<Node>("Biuro Łączności i Informatyki");
	shared_ptr<Node> BF = make_shared<Node>("Biuro Finansów");
	shared_ptr<Node> BKPKiS = make_shared<Node>("Biuro Koordynacji Postępowań Kwalifikacyjnych i Szkolenia Policji");
	shared_ptr<Node> BPr = make_shared<Node>("Biuro Prewencji");
	shared_ptr<Node> BRG = make_shared<Node>("Biuro Ruchu Drogowego");
	shared_ptr<Node> GSP = make_shared<Node>("Główny Sztab Policji");

	addChild(KGP, PZK);
	addChild(KGP, ZKGP);
	addChild(KGP, ZKGPs);
	addChild(KGP, GKGP);
	addChild(KGP, BKS);
	addChild(KGP, BKiOP);
	addChild(KGP, BP);
	addChild(KGP, BBI);
	addChild(KGP, BK);
	addChild(KGP, WOP);
	addChild(KGP, ZAW);
	addChild(KGP, BKr);
	addChild(KGP, BZPE);
	addChild(KGP, BWiIK);
	addChild(KGP, BMWP);
	addChild(KGP, BLP);
	addChild(KGP, BŁiI);
	addChild(KGP, BF);
	addChild(KGP, BKPKiS);
	addChild(KGP, BPr);
	addChild(KGP, BRG);
	addChild(KGP, GSP);
	//printTree(KGP);

	cout << "IN-ORDER " << endl;
	inorder(KGP);
	cout << endl;

	cout << "PRE-ORDER " << endl;
	vector<string> preResult = preorder(KGP);
	for (const string& element : preResult) {
		cout << element << ", " << endl;
	}
	return 0;
}