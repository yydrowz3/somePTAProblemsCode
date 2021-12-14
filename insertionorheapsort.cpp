#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int orign[N], tempOri[N], changed[N];
int n;

bool isSame(int A[], int B[]);
void showArray(int A[]);
bool insertSort(void);
void downAdjust(int low, int high);
void heapSort(void);

int main(int argc, const char *argv[])
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> orign[i];
        tempOri[i] = orign[i];
    }
    for(int i = 1; i <= n; i++)
        cin >> changed[i];
    if(insertSort())
    {
        cout << "Insertion Sort" << endl;
        showArray(tempOri);
    }
    else
    {
        cout << "Heap Sort" << endl;
        for(int i = 1; i <= n; i++)
            tempOri[i] = orign[i];
        heapSort();
    }


    return 0;
}

bool isSame(int A[], int B[])
{
    for(int i = 1; i <= n; i++)
        if(A[i] != B[i])
            return false;
    return true;
}

void showArray(int A[])
{
    for(int i = 1; i <= n; i++)
    {
        cout << A[i];
        if(i < n)
            cout << " ";
    }
    cout << endl;
}

bool insertSort(void)
{
    bool flag = false;
    for(int i = 2; i <= n; i++)
    {
        if(i != 2 && isSame(tempOri, changed))
            flag = true;
        sort(tempOri, tempOri + i + 1);
        if(flag == true)
            return true;
    }
    return false;
}

void downAdjust(int low, int high)
{
    int i = low, j = i * 2;
    while(j <= high)
    {
        if(j + 1 <= high && tempOri[j + 1] > tempOri[j])
            j = j + 1;
        if(tempOri[j] > tempOri[i])
        {
            swap(tempOri[j], tempOri[i]);
            i = j;
            j = j * 2;
        }
        else
            break;
    }
}

void heapSort(void)
{
    bool flag = false;
    for(int i = n / 2; i >= 1; i--)
        downAdjust(i, n);
    for(int i = n; i >= 1; i--)
    {
        if(i != n && isSame(tempOri, changed))
            flag = true;
        swap(tempOri[i], tempOri[1]);
        downAdjust(1, i - 1);
        if(flag == true)
        {
            showArray(tempOri);
            return;
        }
    }
    
}
