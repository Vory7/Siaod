#include <iostream>
#include <cmath>

const int n = 10;

using namespace std;

int CheckSum(int A[n])
{
	int sum = 0;
	for (int i = 0; i < n; i++) sum += A[i];
	return sum;
}

int RunNumber(int A[n])
{
	int num = 1;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] > A[i + 1]) num++;
	}
	return num;
}

void FillRand(int A[n])
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) A[i] = rand() % n;
}

void QuickSort(int A[n], int L, int R)
{
	int x = A[L], i = L, j = R;
	while (L < R) {
		while (A[i] < x) ++i;
		while (A[j] > x) --j;
		if (i <= j) {
			swap(A[i], A[j]);
			++i;
			--j;
		}
		if (j-L < R-i) {
			QuickSort(A, i, R);
			R = j;
		}
		else {
			QuickSort(A, L, j);
			L = i;
		}
	}
}

void PrintMas(int A[n])
{
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << "\n";
}

void FillInc(int A[n])
{
	for (int i = 0; i < n; i++) A[i] = i + 1;
}

void FillDec(int A[n])
{
	for (int i = n; i > 0; i--) A[n - i] = i;
}

int main()
{

	int A[n], M, C, Mt, m, L = 1, R = n;
	float Ct;

	m = int(trunc(float(log(n) / log(2))))-1;


	Ct = 2 * float(log(float(L/R))/log(2));
	Mt = float(log(float(L / R)) / log(2)) + 2;

	cout << "Mt = " << Mt << endl;
	cout << "Ct = " << Ct << endl;

	FillRand(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl;

	QuickSort(A, 0, n - 1);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl << endl << endl;

	FillInc(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl;

	QuickSort(A, 0, n - 1);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl << endl << endl;

	FillDec(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl;

	QuickSort(A, 0, n - 1);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl << endl << endl;
}