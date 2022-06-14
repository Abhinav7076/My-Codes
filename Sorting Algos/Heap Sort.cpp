void heap_sort(int arr[], int n){
    int i, temp, child;
    for(i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(i = n - 1; i >= 0; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void pop_from_heap(int arr[], int n){
    int temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;
    heapify(arr, n-1, 0);
}

void push_to_heap(int arr[], int n, int val){
    arr[n] = val;
    int i = n;
    while(i > 0 && arr[(i-1)/2] < arr[i]){
        int temp = arr[i];
        arr[i] = arr[(i-1)/2];
        arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr, n);
    printf("Sorted array is \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}