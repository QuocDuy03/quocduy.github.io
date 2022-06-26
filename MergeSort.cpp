#include <iostream>

using namespace std;

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void Merge(int a[], int left, int mid, int right)
{
    int *temp = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid || j <= right)
    {
        if ((i <= mid && j <= right && a[i] < a[j]) || j > right)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    for (int i = 0; i < k; i++)
        a[left + i] = temp[i];
    delete[] temp;
}

void MergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[100], n;
    cin >> n;
    input(a, n);
    MergeSort(a, 0, n - 1);
    output(a, n);
    return 0;
}