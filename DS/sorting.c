#include <stdio.h>
#include <stdlib.h>
int temp;
void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int *, int *);
void quickSort(int a[], int start, int end){
    if (start < end){
        int pIndex = partition(a, start, end);
        quickSort(a, start, pIndex - 1);
        quickSort(a, pIndex + 1, end);
    }
}
int partition(int a[], int start, int end){
    int pIndex = start;
    int pivot = a[end];
    int i;
    for (i = start; i < end; i++){
        if (a[i] < pivot){
            swap(&a[i], &a[pIndex]);
            pIndex++;
        }
    }
    swap(&a[end], &a[pIndex]);
    return pIndex;
}
void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
void merge(int a[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}
void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n){
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (i = n - 1; i >= 0; i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
void main(){
    int a[10];
    int i, n, ch, op;
    do{
        printf("Enter the size of array : ");
        scanf("%d", &n);
        printf("\n");
        printf("Enter the elements of array :");
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("Select from the following\n  1. Quick Sort\n  2.Merge Sort \n  3. Heap Sort");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            quickSort(a, 0, n - 1);
            printf("Sorted array is :\n");
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
            break;
        case 2:
            mergeSort(a, 0, n - 1);
            printf("\nSorted array is :\n");
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
            break;
        case 3:
            heapSort(a, n);
            printf("Sorted array is :\n");
            for (i = 0; i < n; ++i)
                printf("%d ", a[i]);
            break;
        }
        printf("\nDo you want to continue?(1 for yes and 0 for no): ");
        scanf("%d", &op);
    } while (op == 1);
}
