#include "stdio.h"
void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
int n;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2], i, j, k;
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    //int n = right - left +1;
    printf("Pass");
        for (i=0;i<n;i++){
    	printf(" %d",arr[i]);
	}
	printf("\n");
}
void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int i;
    printf("Enter the number of elements to be present in array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array are \n");
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    mergesort(arr, 0, n - 1);

    printf("Sorted array is \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


