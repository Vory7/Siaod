#include <iostream>
#include <time.h>

int numb = 1;

struct BranchTree {
    int Data;
    int NumVertex;
    BranchTree* LeftBranch;
    BranchTree* RightBranch;
};

BranchTree* AddVertex(int* const arr, BranchTree*& aBranchTree, int L, int R)
{
    if (L > R) {
        return NULL;
    }else
    {
        int m = (L + R) / 2;
        aBranchTree = new BranchTree;
        aBranchTree->Data = arr[m];
        aBranchTree->NumVertex = numb;
        ++numb;
        aBranchTree->LeftBranch = AddVertex(arr, aBranchTree->LeftBranch, L, m - 1);
        aBranchTree->RightBranch = AddVertex(arr, aBranchTree->RightBranch, m + 1, R);
        return aBranchTree;
    }
}

void Obhod(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return;
    Obhod(aBranchTree->RightBranch);
    std::cout << aBranchTree->NumVertex << ": " << aBranchTree->Data << " " << std::endl;
    Obhod(aBranchTree->LeftBranch);
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
    int* arr = new int [sizeTree];
    for (int i = 0; i < sizeTree; i++)
    {
        arr[i] = (rand() % 100 + 1);
    }
    int L = 0, R = sizeTree - 1;
    QuickSort(arr, L, R);
    BranchTree* Root = 0;
    AddVertex(arr, Root, L, R);
    std::cout << "Bypassing the tree from left to right: ";
    Obhod(Root);
    std::cout << std::endl;
    std::cout << "Tree size: " << TreeSize(Root) << std::endl;
    std::cout << "Checksum: " << ControlSum(Root) << std::endl;
    std::cout << "Tree height: " << TreeHeight(Root) << std::endl;
    int l = 0;
    std::cout << "Sum of path lengths to each vertex: " << SumLengths(Root, l) << std::endl;
    std::cout << "Average height: " << SumLengths(Root, l) / TreeSize(Root);
    return 0;
}
