#include <iostream>
#include <algorithm>
#include <queue>


class testSort {
public:
// selectionSort
    void selectionSort(int* arr, int n) { // n = arr의 크기
        int i, j;
        int maxIdx;
        int tmp;

        for(i = 0; i < n-1; i++) {
            maxIdx = i;    // 정렬 순서상 가장 앞서는 데이터의 index

            for(j = i+1; j<n; j++) { // 최소값 찾기
                if(arr[j] < arr[maxIdx])
                    maxIdx = j;
            }
            tmp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = tmp;
        }
}


// bubbleSort
    void bubbleSort(int* arr, int n) { // n = arr의 크기
        int i, j;
        int tmp;

        for(i = 0; i < n-1; i++) {
            for(j = 0; j < (n-i)-1; j++) {
                if(arr[j] > arr[j+1]) {
                    tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
    }

// insertSort
    void insertSort(int* arr, int n) { // n = arr의 크기
        int i, j;
        int target; // 삽입할 타겟

        for(i=1; i < n; i++) {
            target = arr[i];   // 정렬할 타겟 선정

            for(j=i-1; j >= 0 ; j--) {
                if(arr[j] > target) 
                    arr[j+1] = arr[j];    // 비교할 대상을 한 칸 뒤로 민다.
                else
                    break;   // intser 위치 찾으면 break
            }
            arr[j+1] = target;  // 찾은 위치에 tartget 삽입
        }
    }

// mergeSort
private:
    void mergeArea(int* arr, int left, int mid, int right) {
        int frontIdx = left;
        int rearIdx = mid+1;
        int i;

        int* sortingArr = (int*)malloc(sizeof(int) * (right+1));
        int sortingIdx = left;

        while(frontIdx <= mid && rearIdx <= right) {
            if(arr[frontIdx] <= arr[rearIdx]) {
                sortingArr[sortingIdx] = arr[frontIdx++];
            } else {
                sortingArr[sortingIdx] = arr[rearIdx++];
            }

            sortingIdx++;
        }


        if(frontIdx > mid) {
            for(i = rearIdx; i <= right;) {
                sortingArr[sortingIdx++] = arr[i++];
            }
        } else {
            for(i = frontIdx; i <= mid;) {
                sortingArr[sortingIdx++] = arr[i++];
            }
        }

        for(i = left; i <= right; i++) {
            arr[i] = sortingArr[i];
        }

        free(sortingArr);
    }

public:
    void swap(int* arr, int idx1, int idx2) {
        int tmp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = tmp;
    }
    void mergeSort(int* arr, int left, int right) {
        int mid;

        if(left < right) { // 엇갈리면 종료
            mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);

            mergeArea(arr, left, mid, right);
        }
    }


// quickSort
private:
    int Partition(int* arr, int left, int right) {
        int pivot = arr[left];    // 피벗의 시작 : 가장 왼쪽 
        int low = left+1;
        int high = right;

        // printf("피벗: %d \n", pivot);

        while(low <= high) { // 엇갈리면 종료
            while(pivot >= arr[low] && low <= right)
                low++;

            while(pivot <= arr[high] && high >= (left+1))
                high--;

            if(low <= high)    // 엇갈리지 않았다면 Swap
                swap(arr, low, high);    // low와 high 교환
        }
        swap(arr, left, high);    // 피벗과 high 교환
        return high;    // 옮겨진 피벗 리턴
    }

public:
    void quickSort(int* arr, int left, int right) {
        if(left < right)
        {
            int pivot = Partition(arr, left, right);    // 반으로 나눈다.
            quickSort(arr, left, pivot-1);    // 왼쪽 정렬
            quickSort(arr, pivot+1, right);    // 오른쪽 정렬
        }
    }

// heapSort heap 구현 없이.
public:
    void heapSort_simple(int* arr, int n) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        // std::priority_queue<int> heap; // (기본값)내림차순, 최대힙
        for(int i = 0; i < n; i++) {
            heap.push(arr[i]);
        }

        for(int i = 0; i < n; i++) {
            arr[i] = heap.top();
            heap.pop();
        }
    }

// radixSort
    void radixSort(int* arr, int n, int maxLength) {
        const int BUCKET_DECIMAL = 10;

        std::queue<int> buckets[BUCKET_DECIMAL];
        int radix; // 기수. 10진법이므로 0~9
        int factorial = 1;

        for(int i = 0; i < maxLength; i++) {
            
            // 정렬할 배열로부터 버킷에 저장.
            for(int j = 0; j < n; j++) {
                radix = (arr[j] / factorial) % 10;
                buckets[radix].push(arr[j]);
            }

            // 버킷에 있는 일부만 정렬된 데이터들을 다시 배열로 옮긴다.
            for(int j = 0, k = 0; j < BUCKET_DECIMAL; j++) {
                while(!buckets[j].empty()) {
                    arr[k++] = buckets[j].front();
                    buckets[j].pop();
                }
            }

            // 다음 자리수를 기준으로 정렬하기 위해
            factorial *= 10;
        }

    }
};


// Driver code 
int main() {
    testSort ts;
    const int SMALL_ARRAY_SIZE = 7;
    const int SMALL_END_IDX = SMALL_ARRAY_SIZE - 1;

    int arr1[SMALL_ARRAY_SIZE] = {3, 2, 4, 1, 7, 6, 5};
    printf("selection sort \n");
    ts.selectionSort(arr1, SMALL_ARRAY_SIZE);
    for(int i = 0; i < SMALL_ARRAY_SIZE; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int arr2[SMALL_ARRAY_SIZE] = {3, 2, 4, 1, 7, 6, 5};
    printf("bubble sort \n");
    ts.bubbleSort(arr2, SMALL_ARRAY_SIZE);
    for(int i = 0; i < SMALL_ARRAY_SIZE; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int arr3[SMALL_ARRAY_SIZE] = {3, 2, 4, 1, 7, 6, 5};
    printf("insert sort \n");
    ts.insertSort(arr3, SMALL_ARRAY_SIZE);
    for(int i = 0; i < SMALL_ARRAY_SIZE; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    int arr4[SMALL_ARRAY_SIZE] = {3, 2, 4, 1, 7, 6, 5};
    printf("quick sort \n");
    ts.quickSort(arr4, 0, SMALL_END_IDX);
    for(int i = 0; i < SMALL_ARRAY_SIZE; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n");

    int arr5[SMALL_ARRAY_SIZE] = {3, 2, 4, 1, 7, 6, 5};
    printf("merge sort \n");
    ts.mergeSort(arr5, 0, SMALL_END_IDX);
    for(int i = 0; i < SMALL_ARRAY_SIZE; i++) {
        printf("%d ", arr5[i]);
    }
    printf("\n");


    int arr6[SMALL_ARRAY_SIZE] = {3, 2, 4, 1, 7, 6, 5};
    printf("heap sort \n");
    ts.heapSort_simple(arr6, SMALL_ARRAY_SIZE);
    for(int i = 0; i < SMALL_ARRAY_SIZE; i++) {
        printf("%d ", arr6[i]);
    }
    printf("\n");


    int arr7[SMALL_ARRAY_SIZE] = {413, 2, 14, 1643, 237, 6642, 5123};
    printf("radix sort \n");
    ts.radixSort(arr7, SMALL_ARRAY_SIZE, 4);
    for(int i = 0; i < SMALL_ARRAY_SIZE; i++) {
        printf("%d ", arr7[i]);
    }
    printf("\n");


// 좀 키워서
    return 0;
}
