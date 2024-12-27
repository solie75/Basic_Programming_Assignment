#include <iostream>

using namespace std;

// �� ���
int PrintSum(int* _arr, int _size)
{
    int sum = 0;

    for (int i = 0; i < _size; i++)
    {
        sum += *(_arr + i);
    }

    return sum;
}

// ��� ���
float PrintAverage(int* _arr, int _size)
{
    return (float)PrintSum(_arr, _size) / (float)_size;
}

// �������� ����
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

// �������� ����
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
    cout << "�迭�� �Է��� ������ ������ �Է��ϼ���" << "\n";
    cin >> arrSize;
    int* arr = new int[arrSize] {};

    //int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "�迭�� ��� " << arrSize << "���� �Է����ּ���." << "\n";
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    cout << "�迭�� ��ҵ��� �� ���� " << PrintSum(arr, arrSize) << "�Դϴ�." << "\n";
    cout << "�迭�� ��ҵ��� ����� " << PrintAverage(arr, arrSize) << "�Դϴ�." << "\n";

    int sortCase = 0;

    cout << "�迭�� ������������ �����Ϸ��� 1��, ������������ �����Ϸ��� 2�� �Է��ϼ���." << "\n";
    cin >> sortCase;

    if (sortCase == 1)
    {
        AscendingSort(arr, arrSize);

        for (int i = 0; i < arrSize; i++)
        {
            cout << "������������ ������ �迭�� " << i + 1 << "��° ����� ���� " << *(arr + i) << "�Դϴ�." << "\n";
        }
    }
    else
    {
        DescendingSort(arr, arrSize);

        for (int i = 0; i < arrSize; i++)
        {
            cout << "������������ ������ �迭�� " << i + 1 << "��° ����� ���� " << *(arr + i) << "�Դϴ�." << "\n";
        }
    }

    delete[] arr;
}