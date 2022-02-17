#include <iostream>

using namespace std;

const int m = 5, n = 4;

void FillRand(int** const A)
{
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((j == 0) || (j == 1)) {
                A[i][j] = rand() % 1000;
            }
            if ((j == 2) || (j == 3)) {
                A[i][j] = rand() % 100;
            }
        }
    }
}

void PrintMas(int** const A, int* const B)
{
    for (int i = 0; i < m; i++) {
        cout << i + 1 << ". ";
        for (int j = 0; j < n; j++) {
            if ((j == 0) || (j == 1)) {
                if (A[B[i]][j] < 10) {
                    cout << "00" << A[B[i]][j] << " ";
                }
                if ((A[B[i]][j] < 100) && (A[B[i]][j] >= 10)) {
                    cout << "0" << A[B[i]][j] << " ";
                }
                if (A[B[i]][j] >= 100) {
                    cout << A[B[i]][j] << " ";
                }
            }
            if ((j == 2) || (j == 3)) {
                if (A[B[i]][j] < 10) {
                    cout << "0" << A[B[i]][j] << " ";
                }
                if (A[B[i]][j] >= 10) {
                    cout << A[B[i]][j] << " ";
                }
            }
        }
        cout << endl;
    }
}

void IndexSort(int**  const A, int* const B1, int* const B2, int n1, int n2) {
    int t;
    for (int i = 1; i < m; i++) {
        t = B1[i]; int j = i - 1;
        while ((j >= 0) && (A[t][n1] < A[B1[j]][n1])) {
            B1[j + 1] = B1[j];
            j--;
        }
        B1[j + 1] = t;
    }
    for (int i = 1; i < m; i++) {
        t = B2[i]; int j = i - 1;
        while ((j >= 0) && (A[t][n2] < A[B2[j]][n2])) {
            B2[j + 1] = B2[j];
            j--;
        }
        B2[j + 1] = t;
    }
    
}

int main()
{
    setlocale(LC_ALL, "Russian");
	int n1, n2;
    int** A = new int* [m];
    int* B1 = new int[m];
    int* B2 = new int[m];
	for (int i = 0; i < m; i++) {
		A[i] = new int[n];
	}
    for (int i = 0; i < m; i++) {
        B1[i] = i;
        B2[i] = i;
    }
    FillRand(A);
    PrintMas(A, B1);
    do {
        cout << "Выберите 2 разных поля, по которым хотите сделать поиск (1 - 4): " << endl;
        cin >> n1;
        cin >> n2;
        if (((n1 != 1) && (n1 != 2) && (n1 != 3) && (n1 != 4)) || ((n2 != 1) && (n2 != 2) && (n2 != 3) && (n2 != 4)) || (n1 == n2)) {
            cout << "Вы ввели неверные данные." << endl;
            n1 = 0;
        }
    } while (n1 == 0);

    IndexSort(A, B1, B2, n1 - 1, n2 - 1);
    
    cout << "Список, отсортированный по первому введенному полю: " << endl;
    PrintMas(A, B1);
    cout << "Список, отсортированный по второму введенному полю: " << endl;
    PrintMas(A, B2);
}