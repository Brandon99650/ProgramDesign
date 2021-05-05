#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include<unistd.h>
#include<string.h>
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_heap(int arr[], int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    int i;
    // 初始化，i從最後一個父節點開始調整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heap(arr, i, len - 1);
    // 先將第一個元素和已排好元素前一位做交換，再重新調整，直到排序完畢
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heap(arr, 0, i - 1);
    }
}

void swap_char(char *a, char *b) {
    //a=malloc(sizeof(char)*101);
    //b=malloc(sizeof(char)*101);
    char *temp=malloc(sizeof(char)*101);
    strcpy(temp,b);
    strcpy(b,a);
    strcpy(a,temp);
    /*free(a);
    free(b);
    free(temp);*/


}

void max_heap_char(char **arr, int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && strcmp(arr[son],arr[son + 1])<0) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (strcmp(arr[dad],arr[son])>0) //如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap_char(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort_char(char **arr, int len) {
    int i;
    // 初始化，i從最後一個父節點開始調整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heap_char(arr, i, len - 1);
    // 先將第一個元素和已排好元素前一位做交換，再重新調整，直到排序完畢
    for (i = len - 1; i > 0; i--) {
        swap_char(arr[0], arr[i]);
        max_heap_char(arr, 0, i - 1);
    }
}
