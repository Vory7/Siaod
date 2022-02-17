#include <iostream>
#include <cmath>

using namespace std;

void FillRand(int* const A, const int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) A[i] = rand() % n + 1;
}

void InsertSort(int* const A, const int n) {
	int t;
	for (int i = 1; i < n; i++) {
		t = A[i]; int j = i - 1;
		while ((j >= 0) && (t < A[j])) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = t;
	}
}

int None(int* const A, const int n) {
	int c = 0, j = 0;
	int* B = new int[n];
	for (j = 1; j <= n; j++) {
		c = 0;
		for (int i = 0; i < n; i++) {
			B[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (A[i] == j) {
				B[i]++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (B[i] == 0) {
				c++;
			}
		}
		if (c == n) break;
	}
	if (c == n) {
		return(j);
	}
	else {
		return(0);
	}
}

int BSearch1(int* const A, const int n, int x) {
	FillRand(A, n);
	InsertSort(A, n);
	srand(time(NULL));
	int L = 0, R = n - 1, m, C = 0;
	bool naiden = false;
	if (x == 101) {
		x = A[0];
	}
	if (x == 102) {
		x = A[n-1];
	}
	if (x == 103) {
		x = A[int(floor((L + R) / 2))];
	}
	if (x == 104) {
		x = None(A, n);
		if (x == 0) {
			return (0);
		}
	}
	while (L <= R) {
		m = int(floor((L + R) / 2));
		C++;
		if (A[m] == x) {
			naiden = true;
			break;
		}
		C++;
		if (A[m] < x) {
			L = m + 1;
			continue;
		}
		else {
			R = m - 1;
			continue;
		}
	}
	return(C);
}

int BSearch2(int* const A, const int n, int x) {
	FillRand(A, n);
	InsertSort(A, n);
	srand(time(NULL));
	int L = 0, R = n - 1, m, C = 0;
	bool naiden = false;
	if (x == 101) {
		x = A[0];
	}
	if (x == 102) {
		x = A[n - 1];
	}
	if (x == 103) {
		x = A[int(floor((L + R) / 2))];
	}
	if (x == 104) {
		x = None(A, n);
		if (x == 0) {
			return (0);
		}
	}
	while (L < R) {
		m = int(floor((L + R) / 2));
		C++;
		if (A[m] < x) {
			L = m + 1;
			continue;
		}
		else {
			R = m;
			continue;
		}
	}
	if (A[R] == x) {
		naiden = true;
	}
	else {
		naiden = false;
	}
	return(C);
}

int main()
{
	cout << "n      C1    C2" << endl;
	int n, x;
	for (int i = 1; i <= 10; i++) {
		n = 100 * i;
		cout << n << "    ";
		int* A = new int[n];
		x = rand() % n + 1;
		if (n == 100) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 200) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 300) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 400) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 500) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 600) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 700) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 800) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 900) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 1000) {
			cout << BSearch1(A, n, x) << "     ";
			cout << BSearch2(A, n, x) << endl;
		}
	}
	cout << endl;
	cout << "n                  C1                                   C2" << endl;
	cout << "n      First   Last    Middle    None   |   First   Last    Middle    None" << endl;
	for (int i = 1; i <= 10; i++) {
		n = i * 100;
		int* A = new int[n];
		x = rand() % n + 1;
		if (n == 100) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "       ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "       ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 200) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "       ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 300) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "       ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 400) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "       ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 500) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "       ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 600) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "      ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 700) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "      ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 800) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "      ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "       ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 900) {
			cout << n << "    ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "      ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "        ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
		if (n == 1000) {
			cout << n << "   ";
			x = 101;
			cout << BSearch1(A, n, x) << "      ";
			x = 102;
			cout << BSearch1(A, n, x) << "      ";
			x = 103;
			cout << BSearch1(A, n, x) << "         ";
			x = 104;
			cout << BSearch1(A, n, x) << "     |   ";
			x = 101;
			cout << BSearch2(A, n, x) << "      ";
			x = 102;
			cout << BSearch2(A, n, x) << "        ";
			x = 103;
			cout << BSearch2(A, n, x) << "       ";
			x = 104;
			cout << BSearch2(A, n, x) << endl;
		}
	}


}