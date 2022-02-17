#include <iostream>
#include <time.h>
#include <iomanip>

int numb = 1;

struct BranchTree {
    int Data;
    int NumVertex;
    BranchTree* LeftBranch;
    BranchTree* RightBranch;
};

BranchTree* AddVertex2(int* const arr, BranchTree*& aBranchTree, int L, int R)
{
    if (L > R) {
        return NULL;
    }
    else
    {
        int m = (L + R) / 2;
        aBranchTree = new BranchTree;
        aBranchTree->Data = arr[m];
        aBranchTree->NumVertex = numb;
        ++numb;
        aBranchTree->LeftBranch = AddVertex2(arr, aBranchTree->LeftBranch, L, m - 1);
        aBranchTree->RightBranch = AddVertex2(arr, aBranchTree->RightBranch, m + 1, R);
        return aBranchTree;
    }
}



BranchTree* AddVertex1(int D, BranchTree*& p)
{
    if (p == NULL) {
        p = new BranchTree;
        p->Data = D;
        p->NumVertex = numb;
        ++numb;
        p->LeftBranch = NULL;
        p->RightBranch = NULL;
    }
    else if (D < p->Data) {
        AddVertex1(D, p->LeftBranch);
    }
    else if (D >= p->Data) {
        AddVertex1(D, p->RightBranch);
    }
    else {
        return NULL;
    }
}

void Obhod(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return;
    Obhod(aBranchTree->LeftBranch);
    std::cout << aBranchTree->NumVertex << ": " << aBranchTree->Data << " " << std::endl;
    Obhod(aBranchTree->RightBranch);
}

int TreeSize(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return 0;
    int count = 0;
    count += TreeSize(aBranchTree->RightBranch);
    ++count;
    count += TreeSize(aBranchTree->LeftBranch);
    return count;
}

int ControlSum(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return 0;
    int sum = 0;
    sum += ControlSum(aBranchTree->RightBranch);
    sum += aBranchTree->Data;
    sum += ControlSum(aBranchTree->LeftBranch);
    return sum;
}

int TreeHeight(BranchTree*& aBranchTree) {
    int h = 0;
    if (aBranchTree == NULL)
    {
        h = 0;
    }
    else
    {
        h = 1 + std::max(TreeHeight(aBranchTree->RightBranch), TreeHeight(aBranchTree->LeftBranch));
    }
    return h;
}

double SumLengths(BranchTree*& aBranchTree, int l) {
    int s;
    if (aBranchTree == NULL) {
        s = 0;
    }
    else {
        s = l + SumLengths(aBranchTree->LeftBranch, l + 1) + SumLengths(aBranchTree->RightBranch, l + 1);
    }
    return s;
}

void QuickSort(int* const arr, int L, int R)
{
    int x = arr[L], i = L, j = R;
    do {
        while (arr[i] < x) ++i;
        while (arr[j] > x) --j;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }

    } while (i <= j);

    if (L < j) {
        QuickSort(arr, L, j);
    }
    if (i < R) {
        QuickSort(arr, i, R);
    }
}

int main()
{
    srand(time(NULL));
    int sizeTree = 100;
    int* arr = new int[sizeTree];
    for (int i = 0; i < sizeTree; i++)
    {
        arr[i] = (rand() % 100 + 1);
    }
    int L = 0, R = sizeTree - 1;
    BranchTree* Root1 = 0;
    for (int i = 0; i < sizeTree; ++i) {
        AddVertex1(arr[i], Root1);
    }

    QuickSort(arr, L, R);
    BranchTree* Root2 = 0;
    AddVertex2(arr, Root2, L, R);

    int Size1 = TreeSize(Root1);
    int Size2 = TreeSize(Root2);

    int Sum1 = ControlSum(Root1);
    int Sum2 = ControlSum(Root2);

    int Height1 = TreeHeight(Root1);
    int Height2 = TreeHeight(Root2);

    int l = 0;

    int SumLengths1 = SumLengths(Root1, l);
    int SumLengths2 = SumLengths(Root2, l);

    std::cout << "Bypassing the tree from left to right: " << std::endl;
    Obhod(Root1);
    std::cout << std::endl;
    std::cout << "Tree size: " << Size1 << std::endl;
    std::cout << "Checksum: " << Sum1 << std::endl;
    std::cout << "Tree height: " << Height1 << std::endl;
    std::cout << "Sum of path lengths to each vertex: " << SumLengths1 << std::endl;
    std::cout << "Average height: " << SumLengths1 / Size1 << std::endl << std::endl;

    std::cout << "   n = 100    |     Size     |  ControlSum  |    Height    | AverageHeight" << std::endl;
    std::cout << "    ISDP      |      "<< Size2 <<"     |     "<< std::setw(5) << Sum2 <<"    |      "<< std::setw(3) << Height2 <<"     |      "<< std::setw(2) << SumLengths2 / Size2 << std::endl;
    std::cout << "     SDP      |      "<< Size1 <<"     |     "<< std::setw(5) << Sum1 <<"    |      "<< std::setw(3) << Height1 <<"     |      "<< std::setw(2) << SumLengths1 / Size1 << std::endl;


    return 0;
}