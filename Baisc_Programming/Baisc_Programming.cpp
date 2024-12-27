#include <iostream>

using namespace std;

// 합 출력
int PrintSum(int* _arr, int _size)
{
    int sum = 0;

    for (int i = 0; i < _size; i++)
    {
        sum += *(_arr + i);
    }

    return sum;
}

// 평균 출력
float PrintAverage(int* _arr, int _size)
{
    return (float)PrintSum(_arr, _size) / (float)_size;
}

// 오름차순 정렬
void AscendingSort(int* _arr, int _size)
{
    int* pTempArr = new int[_size] {};

    for (int i = 0; i < _size; i++)
    {
        *pTempArr = *(_arr + i);

        for (int i = 1; i < _size; i++)
        {
            if (*(pTempArr + (i - 1)) > *(pTempArr + i))
            {
                int temp = pTempArr[i];
                pTempArr[i] = pTempArr[i - 1];
                pTempArr[i - 1] = temp;
            }
        }
    }

    for (int i = 0; i < _size; i++)
    {
        *(_arr + i) = *(pTempArr + i);
    }

    delete[] pTempArr;
}

// 내림차순 정렬
void DescendingSort(int* _arr, int _size)
{
    int* pTempArr = new int[_size] {};

    for (int i = _size; i > 0; i--)
    {
        *(pTempArr + (_size - 1)) = *(_arr + (i - 1));

        for (int i = _size - 1; i > 0; i--)
        {
            if (*(pTempArr + i) > *(pTempArr + (i - 1)))
            {
                int temp = pTempArr[i];
                pTempArr[i] = pTempArr[i - 1];
                pTempArr[i - 1] = temp;
            }
        }
    }

    for (int i = 0; i < _size; i++)
    {
        *(_arr + i) = *(pTempArr + i);
    }

    delete[] pTempArr;
}

int main()
{
    int arrSize = 0;
    cout << "배열에 입력할 숫자의 개수를 입력하세요" << "\n";
    cin >> arrSize;
    int* arr = new int[arrSize] {};

    //int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "배열의 요소 " << arrSize << "개를 입력해주세요." << "\n";
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    cout << "배열의 요소들의 총 합은 " << PrintSum(arr, arrSize) << "입니다." << "\n";
    cout << "배열의 요소들의 평균은 " << PrintAverage(arr, arrSize) << "입니다." << "\n";

    int sortCase = 0;

    cout << "배열을 오름차순으로 정렬하려면 1을, 내림차순으로 정렬하려면 2를 입력하세요." << "\n";
    cin >> sortCase;

    if (sortCase == 1)
    {
        AscendingSort(arr, arrSize);

        for (int i = 0; i < arrSize; i++)
        {
            cout << "오름차순으로 정렬한 배열의 " << i + 1 << "번째 요소의 값은 " << *(arr + i) << "입니다." << "\n";
        }
    }
    else
    {
        DescendingSort(arr, arrSize);

        for (int i = 0; i < arrSize; i++)
        {
            cout << "내림차순으로 정렬한 배열의 " << i + 1 << "번째 요소의 값은 " << *(arr + i) << "입니다." << "\n";
        }
    }

    delete[] arr;
}