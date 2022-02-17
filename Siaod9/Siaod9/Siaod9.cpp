#include <iostream>

using namespace std;

void FillRand(int* const A, const int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) A[i] = rand() % n + 1;
}

int Pyramid(int* const A, int L, int R) {
	int i = L, C = 0, M = 0, x = A[i];
	while (true) {
		int j = 2 * i + 1;

		if (j > R) break;
		++C;
		if ((j < R) && (A[j + 1] <= A[j])) ++j;
		++C;
		if (x <= A[j]) break;
		++M;
		A[i] = A[j];
		i = j;
	}
	++M;
	A[i] = x;
	return (C + M);
}

void HeapSort(int* const A, const int n)
{
	int  L = trunc(n / 2), M = 0, C = 0;
	int R = n - 1;
	for (L; L >= 0; --L) {
		C += Pyramid(A, L, R);
	}



	while (R >= 1) {
		swap(A[0], A[R]);
		--R;
		C += Pyramid(A, 0, R);
	}

	int x;

	for (int i = 0; i < n/2; ++i) {
		x = A[n - 1 - i];
		A[n - 1 - i] = A[i];
		A[i] = x;
	}
	//cout << M + C;
}

void PrintMas(int* const A, const int n)
{
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << "\n";
}

void FillInc(int* const A, const int n)
{
	for (int i = 0; i < n; i++) A[i] = i + 1;
}

void FillDec(int* const A, const int n)
{
	for (int i = n; i > 0; i--) A[n - i] = i;
}

int main()
{
	int M, C, n = 100;
	float Ct, Mt;

	int* A = new int[n];
	FillDec(A, n); HeapSort(A, n);

	for (int i = 0; i < n; ++i) {
		cout << A[i] << " ";
	}

	cout << endl;

	

}
