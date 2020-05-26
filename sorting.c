#include <stdio.h>
#include<time.h>
#define MAX 100

int main(void) {
    int array[MAX], n;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    fflush(stdin);
	inputArray(array, n);
	//selectionsort(array, n);
    //bubblesort(array, n);
    //insertionsort(array, n);
    //quicksort(array, 0, n - 1 );
    //heapsort(array, n)
	for( int i = 0 ; i < n ; i++)
	    printf("%d\t", array[i]);
	return 0;
}

void inputArray( int array[], int n ){
    printf("Enter the elements\n");
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d", &array[i]);
        fflush(stdin);
    }
}

void selectionsort( int array[], int n){
    for( int i = 0 ; i < n ; i++ ){
        int index = i;
        int min = array[i];
        for( int j = i + 1 ; j < n ; j++ ){
            if( min > array[j]){
                min = array[j];
                index = j;
            }
        }
            array[index] = array[i];
            array[i] = min;
    }
}

void bubblesort(int array[], int n){
    for(int i = 0 ; i < n - 1 ; i++ ){
        for( int j = 0 ; j < n - i - 1 ; j++ ){
            if( array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void insertionsort(int a[], int n){
    int b[n], j;
    b[0] = a[0];
    for( int i = 1 ; i < n ; i++ ){
        for( j = i - 1 ; j >= 0 && a[i] < b[j] ; j-- )
            b[j + 1] = b[j];
        b[j + 1] = a[i];
    }
    for( int i = 0 ; i < n ; i++ ){
        a[i] = b[i];
    }
}

void quicksort( int array[], int start, int end ){
    if( start < end ){
    int pIndex = partition(array, start, end);
    quicksort(array, start, pIndex - 1);
    quicksort(array, pIndex + 1, end);
    }
}

int partition(int array[], int start , int end){
    int pivot = array[end];
    int pIndex = start;
    for( int i = start ; i < end ; i++ ){
        if( array[i] < pivot){
            int temp = array[i];
            array[i] = array[pIndex];
            array[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = array[pIndex];
    array[pIndex] = array[end];
    array[end] = temp;

    return pIndex;
}

void heapsort(int array[], int n){
    heapcreate(array, n - 1);
    sort(array, 0, n - 1);
}

void heapcreate(int array[], int end){
    for( int i = (end + 1) / 2 - 1 ; i >= 0 ; i-- )
        maxHeapify(array, i, end);
}

void maxHeapify(int array[], int i, int end){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if( l <= end && array[largest] < array[l] )
        largest = l;
    if( r <= end && array[largest] < array[r] )
        largest = r;
    if( largest != i ){
        int temp = array[largest];
        array[largest] = array[i];
        array[i] = temp;
        if( largest >= (end + 1) / 2 )
            return;
        else
            maxHeapify(array, largest, end);
    }
}

void sort( int array[], int start, int end ){
    if(end == 0 )
        return;
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    end--;
    maxHeapify(array , start, end);
    sort(array, start, end);
}
