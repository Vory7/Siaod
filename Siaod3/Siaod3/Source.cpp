#include <iostream>

using namespace std;

void FillRand(int* const A, const int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) A[i] = rand() % n + 1;
}

void BubbleSort(int* const A, const int n)
{
	int s, M = 0, C = 0;
	for (int i = 0; i < (n-1); i++) {
		for (int j = (n - 1); j > i; j--) {
			C++;
			if (A[j] < A[j - 1]) {
				s = A[j];
				A[j] = A[j - 1];
				A[j - 1] = s;
				M += 3;
			}
		}
	}
	cout << M + C;
}

int CheckSum(int* const A, const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) sum += A[i];
	return sum;
}

int RunNumber(int* const A, const int n)
{
	int num = 1;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] > A[i + 1]) num++;
	}
	return num;
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
	int M, C, Mt, n;
	float Ct;


	cout << "n      M+C(t)    Dec(M+C)    Inc(M+C)    Rand(M+C)" << endl;
	for (int i = 1; i <= 5; i++) {
		n = 100 * i;

		int* A = new int[n];

		Ct = float(pow(n, 2) - n) / 2;
		Mt = 3 * Ct;
		

		if(n == 100) {
			cout << n << "    " << Mt + Ct << "     "; FillDec(A, n); BubbleSort(A, n);
			cout << "       "; FillInc(A, n); BubbleSort(A, n);
			cout << "        "; FillRand(A, n); BubbleSort(A, n);
			cout << endl;
		}

		if (n == 200) {
			cout << n << "    " << Mt + Ct << "     "; FillDec(A, n); BubbleSort(A, n);
			cout << "       "; FillInc(A, n); BubbleSort(A, n);
			cout << "       "; FillRand(A, n); BubbleSort(A, n);
			cout << endl;
		}

		if (n == 300) {
			cout << n << "    " << Mt + Ct << "    "; FillDec(A, n); BubbleSort(A, n);
			cout << "      "; FillInc(A, n); BubbleSort(A, n);
			cout << "       "; FillRand(A, n); BubbleSort(A, n);
			cout << endl;
		}

		if (n == 400) {
			cout << n << "    " << Mt + Ct << "    "; FillDec(A, n); BubbleSort(A, n);
			cout << "      "; FillInc(A, n); BubbleSort(A, n);
			cout << "       "; FillRand(A, n); BubbleSort(A, n);
			cout << endl;
		}

		if (n == 500) {
			cout << n << "    " << Mt + Ct << "    "; FillDec(A, n); BubbleSort(A, n);
			cout << "      "; FillInc(A, n); BubbleSort(A, n);
			cout << "      "; FillRand(A, n); BubbleSort(A, n);
			cout << endl;
		}
	}

}

