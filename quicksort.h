#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include<unistd.h>
#include<string.h>
int comp(const void *a,const void *b){
     return *(int *)a - *(int *)b;
}
int comp1(const void *a,const void *b){
     return strcmp(*(char **)a , *(char **)b);
     }
int Paritition1(int *A, int low, int high) {
   int pivot = A[low];
   while (low < high) {
     while (low < high && A[high] >= pivot) {
       --high;
     }
     A[low] = A[high];
     while (low < high && A[low] <= pivot) {
       ++low;
     }
     A[high] = A[low];
   }
   A[low] = pivot;
   return low;
 }

 void QuickSort(int *A, int low, int high)
 {
   if (low < high) {
     int pivot = Paritition1(A, low, high);
     QuickSort(A, low, pivot - 1);
     QuickSort(A, pivot + 1, high);
   }
 }

 int Paritition2(char **A, int low, int high) {
   char *pivot=malloc(103);
   strcpy(pivot,A[low]);
  //  printf("%s\n",pivot);
  //  char pivot=malloc(sizeof(char)*101);
   while (low < high) {
     while (low < high && strcmp(A[high],pivot)>=0) {
       --high;
     }
     strcpy(A[low],A[high]);
     while (low < high && strcmp(A[low], pivot)<=0) {
       ++low;
     }
     strcpy(A[high] ,A[low]);
   }
  //  printf("%s\n",pivot);
  //  printf("%s:%s",A[low],pivot);
   strcpy(A[low] ,pivot);
   return low;
 }

 void QuickSort_string(char **A, int low, int high)
 {
   if (low < high) {
     int pivot = Paritition2(A, low, high);
     QuickSort_string(A, low, pivot - 1);
     QuickSort_string(A, pivot + 1, high);
   }
 }
