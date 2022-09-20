#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iomanip>
#include <math.h>

#define N 4000

using namespace std;
int num = 0;

struct record {
    char Author[12];
    char Title[32];
    char Pub[16];
    short int Year;
    short int Pages;
};

struct Node {
    record* r;
};

class TreeNode {
    record** keys;
    int t;
    TreeNode** C;
    int n;
    bool leaf;

public:
    TreeNode(int temp, bool bool_leaf);

    void insertNonFull(record* k);
    void splitChild(int i, TreeNode* y);
    void traverse();
    void Delete();

    TreeNode* search(int k);

    friend class BTree;
};

class BTree {
    TreeNode* root;
    int t;

public:
    BTree(int temp) {
        root = NULL;
        t = temp;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    int real() {
        if (root != NULL) return 1;
        else return 0;
    }

    TreeNode* search(int k) {
        if (root == NULL) return NULL;
        else return root->search(k);
    }

    void Delete() {
        if (root != NULL)
            root->Delete();
    }

    void insert(record* k);
};

TreeNode::TreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys = new record*[2 * t - 1];
    C = new TreeNode * [2 * t];

    n = 0;
}

void TreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << "[" << ++num << "]" << setw(12) << keys[i]->Author
            << setw(36) << keys[i]->Title
            << setw(20) << keys[i]->Pub
            << setw(8) << keys[i]->Year
            << setw(8) << keys[i]->Pages
            << endl;
    }

    if (leaf == false)
        C[i]->traverse();
}

void TreeNode::Delete() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
    }

    delete[] keys;

    if (leaf == false)
        C[i]->traverse();

    delete[] C;

}

TreeNode* TreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i]->Year)
        i++;

    //if (keys[i] != NULL)
        if (keys[i]->Year == k)
            cout << "[" << ++num << "]" << setw(12) << keys[i]->Author
            << setw(36) << keys[i]->Title
            << setw(20) << keys[i]->Pub
            << setw(8) << keys[i]->Year
            << setw(8) << keys[i]->Pages
            << endl;

    if (leaf == true)
        return NULL;

    return C[i]->search(k);
}

void BTree::insert(record* k) {
    if (root == NULL) {
        root = new TreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            TreeNode* s = new TreeNode(t, false);

            s->C[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0]->Year < k->Year)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void TreeNode::insertNonFull(record* k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i]->Year > k->Year) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && keys[i]->Year > k->Year)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1]->Year < k->Year)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void TreeNode::splitChild(int i, TreeNode* y) {
    TreeNode* z = new TreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}

int cnt = 0;
int Rost;
void HeapSort(Node* arr);
void heapify(Node* arr, int n, int i);
int ForHeapSort(Node* arr, int a, int b);
int FindCheck(Node node, char* K);
int FindByKey(Node* arr, int* indexl, int* indexr);
int Reading_Symbols();
void Fill_Chance_Meet_of_Symbols(char symbol, double** array_chance, int symbol_alphabet);
void CodingSymbols(double** array_chance, int symbol_alphabet);
void Huffman(int symbol_alphabet, double* probability, bool** code_word, double* length);
void QuickSortForChance(double** array_chance, int left_limit, int right_limit);
void Down(int symbol_alphabet, int j, double* length, bool** code_word);
int Up(int symbol_alphabet, double q, double* probability);

struct List {
    record r;
    List* next;
};

class Queue {
public:
    List* head, * tail;

    Queue() {
        head = NULL;
        tail = NULL;
    }

    void push(record& rec) {
        List* tmp = new List;
        tmp->r = rec;
        tmp->next = NULL;
        if (head == NULL) head = tail = tmp;
        else {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void printQueue() {
        int i = 1;
        List* p = head;
        while (p != NULL) {
            cout << '[' << i << ']' << setw(12) << p->r.Author
                << setw(36) << p->r.Title
                << setw(20) << p->r.Pub
                << setw(8) << p->r.Year
                << setw(8) << p->r.Pages
                << endl;             
            p = p->next;
            ++i;
        }
    }
};

int main() {
    FILE* fp;
    fopen_s(&fp, "testBase1.dat", "rb");
    record* records;
    Node* pointers = new Node[N];
    Queue q;
    BTree tree(2);
    int choice;

    if (fp == NULL) {
        cout << "PROBLEM" << endl;
        system("pause");
        return -1;
    }

    records = new record[N];
    fread((record*)records, sizeof(record), N, fp);
    fclose(fp);

    for (int i = 0; i < N; ++i) pointers[i].r = &records[i];
    HeapSort(pointers);

    while (true) {
        system("cls");
        cout << "[1]Show unsorted data" 
            << endl << "[2]Show sorted data" 
            << endl << "[3]Find by last name of a wonderful person" 
            << endl << "[4]Build the tree"
            << endl << "[5]Search in tree by year"
            << endl << "[6]Encode Data Base by Huffman"
            << endl;
        cout << "The choice is yours: ";

        cin >> choice;

        switch (choice) {
        case 1:
        {
            system("cls");
            int i = 0, j = 0;

            while (i < N) {
                if (j == 20) {
                    cout << "========================================================================"
                        << endl << "Print more? (0 - NO, 1 - YES): ";
                    cin >> choice;
                    if (choice == 0) break;
                    else j = 0;
                }

                cout << '[' << i << ']' << setw(12) << records[i].Author
                    << setw(36) << records[i].Title
                    << setw(20) << records[i].Pub
                    << setw(8) << records[i].Year
                    << setw(8) << records[i].Pages
                    << endl;                
                ++i;
                ++j;
            }
        } break;
        case 2:
        {
            system("cls");
            int i = 0, j = 0;
            while (i < N) {
                if (j == 20) {
                    cout << "========================================================================" 
                        << endl << "Print more? (0 - NO, 1 - YES): ";
                    cin >> choice;
                    if (choice == 0) break;
                    else j = 0;
                }

                cout << '[' << i << ']' << setw(12) << pointers[i].r->Author
                    << setw(36) << pointers[i].r->Title
                    << setw(20) << pointers[i].r->Pub
                    << setw(8) << pointers[i].r->Year
                    << setw(8) << pointers[i].r->Pages
                    << endl;
                ++i;
                ++j;
            }
        } break;
        case 3:
        {
            int indexl = 0, indexr = 0;
            if (FindByKey(pointers, &indexl, &indexr)) {
                for (int i = indexl; i <= indexr; ++i) q.push(*pointers[i].r);
                q.printQueue();
            }
            else {
                cout << "Node not found!" << endl;
            }
        } break;
        case 4:
        {
            if (q.head == NULL) {
                cout << "Queue not found!" << endl;
            }
            else {
                List* p = q.head;
                while (p != NULL) {
                    tree.insert(&p->r);
                    p = p->next;
                }
                tree.traverse();
                num = 0;
            }
        } break;
        case 5:
        {
            if (tree.real()) {
                int y;
                cin >> y;
                tree.search(y);
                num = 0;
            }
            else {
                cout << "Tree not found!" << endl;
            }
        } break;
        case 6:
        {
            Reading_Symbols();
        } break;
        }
        system("PAUSE");
        std::cout << '\n';
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}

int FindCheck(Node node, char* K) {
    int check = 0, m = 0;
    for (int i = 0; i < 32; ++i) {
        if (check == 2) {
            m = i;
            break;
        }
        if (node.r->Title[i] == ' ') check++;
    }

    check = 0;
    for (int i = 0; i < 3; ++i) {
        if (check == 0) {
            if (node.r->Title[m + i] > K[i]) check = 1;
            if (node.r->Title[m + i] < K[i]) check = 2;
        }
        else break;
    }

    return check;
}

int FindByKey(Node* arr, int* indexl, int* indexr) {
    char* K = new char[4];
    for (int i = 0; i < 3; ++i) {
        cin >> K[i];
    }

    int l = 0, r = N - 1, mid, flag = 1;

    while ((l <= r) && flag) {
        mid = (l + r) / 2;

        if (FindCheck(arr[mid], K) == 0) {
            flag = 0;
            *indexl = mid;
        }
        else if (FindCheck(arr[mid], K) == 1) r = mid - 1;
        else l = mid + 1;
    }

    *indexr = *indexl;
    if (flag == 0) {
        while (flag == 0) {
            int i = *indexl - 1;
            if (FindCheck(arr[i], K) == 0) *indexl -= 1;
            else flag = 1;
        }

        flag = 0;
        while (flag == 0) {
            int i = *indexr + 1;
            if (FindCheck(arr[i], K) == 0) *indexr += 1;
            else flag = 1;
        }
    } else flag = 0;
    delete[] K;

    return flag;
}

int ForHeapSort(Node* arr, int a, int b) {
    int check1 = 0, check2 = 0, m1 = 0, m2 = 0, k1 = 0, k2 = 0;
    for (int i = 0; i < 32; ++i) {
        if (check1 == 2) {
            m1 = i;
            ++check1;
        }
        else {
            if (arr[a].r->Title[i] == ' ') check1++;
        }

        if (check2 == 2) {
            m2 = i;
            ++check2;
        }
        else {
            if (arr[b].r->Title[i] == ' ') check2++;
        }
    }

    for (int i = 0; i < 32; ++i) {
        if (arr[a].r->Title[m1 + i] > arr[b].r->Title[m2 + i]) {
            return 1;
        }
        else if (arr[a].r->Title[m1 + i] < arr[b].r->Title[m2 + i]) {
            return 0;
        }
    }
    return 0;
}

void heapify(Node* arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ForHeapSort(arr, left, largest))
        largest = left;

    if (right < n && ForHeapSort(arr, right, largest))
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(Node* arr) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int Reading_Symbols()
{
    double** array_chance;
    FILE* file;
    double entropy = 0.0;
    int symbol_alphabet = 256;
    int sum = 0;
    char symbol = '\0';
    fopen_s(&file, "testBase1.dat", "rb");

    if (file == NULL)
    {
        return 0;
    }

    array_chance = new double*[symbol_alphabet];
    for (int i = 0; i < symbol_alphabet; i++)
    {
        array_chance[i] = new double[2];
        array_chance[i][0] = 0;
        array_chance[i][1] = 0;
    }

    while (fread(&symbol, sizeof(char), 1, file) && (!feof(file)))
    {
        Fill_Chance_Meet_of_Symbols(symbol, array_chance, symbol_alphabet);
    }
    fclose(file);

    for (int i = 0; i < symbol_alphabet; i++)
        sum += array_chance[i][1];

    cout << "!!!SUM == " << sum << endl;

    for (int i = 0; i < symbol_alphabet; i++)
        array_chance[i][1] = (array_chance[i][1] / sum);

    for (int i = 0; i < symbol_alphabet; i++)
        entropy = (entropy + log(array_chance[i][1]) / log(2) * array_chance[i][1]);

    entropy = entropy * -1;

    CodingSymbols(array_chance, symbol_alphabet);

    cout << "Entropy: " << entropy << endl;

    for (int i = 0; i < symbol_alphabet; i++)
    {
        delete[] array_chance[i];
    }
    delete[] array_chance;
    return 0;
}

void Fill_Chance_Meet_of_Symbols(char symbol, double** array_chance, int symbol_alphabet)
{
    for (int i = 0; i < symbol_alphabet; i++)
    {
        if (array_chance[i][0] == symbol)
        {
            array_chance[i][1]++;
            return;
        }
        if (array_chance[i][1] == 0)
        {
            array_chance[i][0] = symbol;
            array_chance[i][1]++;
            return;
        }
    }
}

void CodingSymbols(double** array_chance, int symbol_alphabet)
{
    double average_code_length = 0.0;
    double *probability = new double[symbol_alphabet + 1];
    double *length = new double[symbol_alphabet + 1];
    bool **code_word = new bool*[symbol_alphabet + 1];
    for (int i = 0; i < symbol_alphabet + 1; i++)
    {
        probability[i] = 0;
        length[i] = 0;
        code_word[i] = new bool[20];
    }

    for (int i = 0; i < symbol_alphabet + 1; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            code_word[i][j] = 0;
        }
    }

    QuickSortForChance(array_chance, 0, symbol_alphabet - 1);
    for (int i = 1; i < symbol_alphabet + 1; i++)
    {
        probability[i] = array_chance[i - 1][1];
    }

    Huffman(symbol_alphabet, probability, code_word, length);

    cout << endl << "Symbol    Probability        Code word    Word length" << endl;
    for (int i = 1; i < symbol_alphabet + 1; i++)
    {
        average_code_length += array_chance[i - 1][1] * length[i];
        printf("%hu)%c\t%f\t\t", i, (char)array_chance[i - 1][0], array_chance[i - 1][1]);
        for (int j = 0; j < length[i]; j++)
        {
            printf("%d", code_word[i][j]);
        }
        cout << "\t\t" << length[i] << endl;
    }
    cout << "Average length of code words : " << average_code_length << endl;
}

void Huffman(int symbol_alphabet, double *probability, bool **code_word, double *length)
{
    if (symbol_alphabet == 2)
    {
        code_word[1][0] = 0;
        length[1] = 1;
        code_word[2][0] = 1;
        length[2] = 1;
    }
    else
    {
        double q = probability[symbol_alphabet - 1] + probability[symbol_alphabet];
        int j = Up(symbol_alphabet, q, probability);
        Huffman(symbol_alphabet - 1, probability, code_word, length);
        Down(symbol_alphabet, j, length, code_word);
    }
}

void QuickSortForChance(double** array_chance, int left, int right)
{
    int j = right, i = left;
    double X = array_chance[(left + right) / 2][1];
    double temp, m;
    while (i <= j)
    {
        while (array_chance[i][1] > X)
        {
            i++;
        }
        while (array_chance[j][1] < X)
        {
            j--;
        }
        if (i <= j)
        {
            m = array_chance[j][0];
            array_chance[j][0] = array_chance[i][0];
            array_chance[i][0] = m;
            temp = array_chance[j][1];
            array_chance[j][1] = array_chance[i][1];
            array_chance[i][1] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        QuickSortForChance(array_chance, left, j);
    }
    if (i < right)
    {
        QuickSortForChance(array_chance, i, right);
    }
    return;
}

void Down(int symbol_alphabet, int j, double *length, bool **code_word)
{
    bool S[20] = { 0 };
    for (int i = 0; i < 20; i++)
    {
        S[i] = code_word[j][i];
    }
    int l = length[j];
    for (int i = j; i <= symbol_alphabet - 2; i++)
    {
        for (int k = 0; k < 20; k++)
        {
            code_word[i][k] = code_word[i + 1][k];
        }
        length[i] = length[i + 1];
    }
    for (int i = 0; i < 20; i++)
    {
        code_word[symbol_alphabet - 1][i] = S[i];
        code_word[symbol_alphabet][i] = S[i];
    }
    code_word[symbol_alphabet - 1][l] = 0;
    code_word[symbol_alphabet][l] = 1;
    length[symbol_alphabet - 1] = l + 1;
    length[symbol_alphabet] = l + 1;
}

int Up(int symbol_alphabet, double q, double *probability)
{
    int j = 1;
    for (int i = symbol_alphabet - 1; i > 1; i--)
    {
        if (probability[i - 1] <= q)
        {
            probability[i] = probability[i - 1];
        }
        else
        {
            j = i;
            break;
        }
    }
    probability[j] = q;
    return j;
}
