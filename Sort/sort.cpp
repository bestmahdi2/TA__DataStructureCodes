#include <iostream>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// تابع مرتب سازی بابل
void bubbleSort(int arr[], int n) {
   for (int i = 0; i < n-1; i++)      
       for (int j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

// تابع مرتب سازی انتخابی
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// تابع مرتب سازی درجی
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// تابع پارتیشن برای کوییک سورت
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// تابع مرتب سازی سریع
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// تابع برای چاپ آرایه
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// تابع اصلی
int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // استفاده از فانکشن های مرتب سازی
    bubbleSort(arr, n);
    std::cout << "Sorted array with Bubble Sort: ";
    printArray(arr, n);

    selectionSort(arr, n);
    std::cout << "Sorted array with Selection Sort: ";
    printArray(arr, n);

    insertionSort(arr, n);
    std::cout << "Sorted array with Insertion Sort: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    std::cout << "Sorted array with Quick Sort: ";
    printArray(arr, n);

    return 0;
}