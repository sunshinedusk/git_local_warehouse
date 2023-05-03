#include <stdio.h>

const int N = 101;
int n, m;
int a[101],temp[101];
int comparisons = 0;

//ѡ������
void selection_sort(int arr[], int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            comparisons++;  // ��¼�Ƚϴ���
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

//ð������
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        int flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            comparisons++; // ��¼�Ƚϴ���
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) { // �����һ��������û�з���������˵���Ѿ��ź�����
            break;
        }
    }
}


// ��������Ԫ�ص�ֵ
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


// �ѵ���
/*void heapify(int arr[], int n, int i) {
    int largest = i;  // largestΪ��ǰ�ڵ������ӽڵ��е����ֵ���±�
    int left = 2 * i + 1;  // ���ӽڵ���±�
    int right = 2 * i + 2;  // ���ӽڵ���±�

    comparisons += 1; // �Ƚϴ���+1
    if (left < n && arr[left] > arr[largest])
        largest = left;

    //comparisons += 1; // �Ƚϴ���+1
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// ������
void heap_sort(int arr[], int n) {
    // ������
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // ���ȡ���Ѷ�Ԫ�ز�������
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}*/

void adjust(int* k, int i, int n)
{
    int j, temp;
    temp = k[i];
    j = 2 * i + 1;
    while (j < n)
    {
        if (j < n - 1 && k[j] < k[j + 1])
            j++;
        if ((++comparisons) && (temp >= k[j]))
            break;
        k[(j - 1) / 2] = k[j];
        j = 2 * j + 1;
    }
    k[(j - 1) / 2] = temp;
}


void heapSort(int* k, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        adjust(k, i, n);
    for (i = n - 1; i >= 1; i--)
    {
        k[i] = k[i] ^ k[0];
        k[0] = k[i] ^ k[0];
        k[i] = k[i] ^ k[0];
        adjust(k, 0, i);
    }
    return;
}

//��·�鲢����
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int count = 0;

    i = left; // ��벿����ʼλ��
    j = mid;  // �Ұ벿����ʼλ��
    k = left; // �ϲ����������ʼλ��

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
        count++;
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
        //count++;
    }

    while (j <= right) {
        temp[k++] = arr[j++];
        //count++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, count = 0;

    if (right > left) {
        mid = (left + right) / 2;
        count += mergeSort(arr, temp, left, mid); // �ݹ�������벿��
        count += mergeSort(arr, temp, mid + 1, right); // �ݹ������Ұ벿��
        count += merge(arr, temp, left, mid + 1, right); // �ϲ��������벿��
    }

    return count;
}

//��������
/*void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int i = left, j = right;
        while (i < j) {
            while (i < j && arr[j] >= pivot) {
                comparisons++; // �Ƚϴ���+1
                j--;
            }
            comparisons++;
            if (i < j) {
                arr[i] = arr[j];
                i++;
            }
            while (i < j && arr[i] < pivot) {
                comparisons++; // �Ƚϴ���+1
                i++;
            }
            comparisons++;
            if (i < j) {
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = pivot;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}*/

void quickSort(int k[], int left, int right)

{
    int i, last;

    if (left < right) {

        last = left;

        for (i = left + 1; i <= right; i++)
        {
            comparisons++;
            if (k[i] < k[left])
            {
                swap(&k[++last], &k[i]);
                //comparisons++;
            }
        }
        swap(&k[left], &k[last]);

        quickSort(k, left, last - 1);

        quickSort(k, last + 1, right);

    }

}

//������������Ԫ��
void show()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

    if (m == 1)
    {
        selection_sort(a, n);
        show();
        printf("%d\n", comparisons);
    }
    else if (m == 2)
    {
        bubbleSort(a, n);
        show();
        printf("%d\n", comparisons);
    }
    else if (m == 3)
    {
        heapSort(a, n);
        show();
        printf("%d\n", comparisons);
    }
    else if (m == 4)
    {
        comparisons  = mergeSort(a, temp, 0, n - 1);
        show();
        printf("%d\n", comparisons);
    }
    else if (m == 5)
    {
        quickSort(a, 0, n - 1);
        show();
        printf("%d\n",comparisons);
    }

    //�޸Ĳ���
    printf("Hello git!\n");
	return 0;
}