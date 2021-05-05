#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include<unistd.h>
#include<string.h>
#define MAX 1000000
//#define SHOWPASS
#define BASE 10
void radixsort(int *a) {
  int  m = a[0], exp = 1;
  int *b=malloc(sizeof(int)*1000000);
  long long int i;
  for (i = 1; i <MAX; i++) {
    if (a[i] > m) {
      m = a[i];
    }
  }

  while (m / exp > 0) {
    int bucket[BASE] = { 0 };

    for (i = 0; i < MAX; i++) {
      bucket[(a[i] / exp) % BASE]++;
    }

    for (i = 1; i < BASE; i++) {
      bucket[i] += bucket[i - 1];
    }

    for (i = MAX- 1; i >= 0; i--) {
      b[--bucket[(a[i] / exp) % BASE]] = a[i];
    }

    for (i = 0; i < MAX; i++) {
      a[i] = b[i];
    }
    exp *= BASE;
  }
}

