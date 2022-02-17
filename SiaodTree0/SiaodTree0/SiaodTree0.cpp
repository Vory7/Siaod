#include <iostream>
#include <ctime>
using namespace std;
struct Vertex
{
	int Data;
	string num;
	Vertex* Left;
	Vertex* Right;
};
Vertex* create();
void Obhod(Vertex* p);
int Size(Vertex* p);
int Hight(Vertex* p);
int Max(int a, int b);
int Controlsum(Vertex* p);
int MidLenghtRay(Vertex* p, int L);
int main() {
	Vertex* Root;
	Root = create();
	Obhod(Root);
	cout << endl << "Size = " << Size(Root);
	cout << endl << "Hight = " << Hight(Root);
	cout << endl << "Midhight = " << MidLenghtRay(Root, 1) / Size(Root);
	cout << endl << "ControllSum = " << Controlsum(Root) << endl;
	return 0;
}
Vertex* create() {
	srand(time(NULL));
	Vertex* Root = new Vertex;
	Vertex* p = Root;
	p->Data = rand() % 10;
	p->num = "1: ";
	p->Right = NULL;
	p->Left = new Vertex;
	p = p->Left;
	p->Data = rand() % 10;
	p->num = "2: ";
	p->Left = new Vertex;
	p->Right = new Vertex;
	p->Right->Data = rand() % 10;
	p->Right->num = "2.1: ";
	p->Right->Left = NULL;
	p->Right->Right = NULL;
	p = p->Left;
	p->Data = rand() % 10;
	p->num = "3: ";
	p->Left = NULL;
	p->Right = new Vertex;
	p = p->Right;
	p->Data = rand() % 10;
	p->num = "4: ";
	p->Right = NULL;
	p->Left = new Vertex;
	p = p->Left;
	p->Data = rand() % 10;
	p->num = "5: ";
	p->Right = NULL;
	p->Left = NULL;
	return Root;
}
void Obhod(Vertex* p) {
	if (p != NULL) {
		cout << p->num << p->Data << endl;
		Obhod(p->Left);
		Obhod(p->Right);
	}
}
int Size(Vertex* p) {
	int n = 0;
	if (p == NULL) {
		n = 0;
	}
	else {
		n = 1 + Size(p->Left) + Size(p->Right);
	}
	return n;
}
int Hight(Vertex* p) {
	int n = 0;
	if (p == NULL) {
		n = 0;
	}
	else {
		n = 1 + Max(Hight(p->Left), Hight(p->Right));
	}
	return n;
}
int Max(int a, int b) {
	if (a > b) { return a; }
	else return b;
}
int Controlsum(Vertex* p) {
	int S = 0;
	if (p == NULL) {
		S = 0;
	}
	else {
		S = p->Data + Controlsum(p->Left) + Controlsum(p->Right);
	}
	return S;
}
int MidLenghtRay(Vertex* p, int L) {
	int S = 0;
	if (p == NULL) {
		S = 0;
	}
	else {
		S = L + MidLenghtRay(p->Left, L + 1) + MidLenghtRay(p->Right, L + 1);
	}
	return S;
}