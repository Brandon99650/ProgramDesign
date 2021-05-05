#include "radixsort.h"
//int arr[MAX];
int main() {
 struct  timeval start;
 struct  timeval end;
 unsigned  long diff;
  int *arr=malloc(sizeof(int)*1000000);
 int i;
  int min = 0;
  int max = 32767;
  int x; 
  srand(time(NULL));
  FILE *fp=fopen("database1.txt","w+");
  if(fp==NULL) {
      printf("can't open, err %d\n", errno);
    }
  
  for (i = 0; i < MAX; i++) {
      x = rand() % (max - min + 1) + min;
      arr[i]=x;
  }
  gettimeofday(&start,NULL);
  radixsort(arr);
  gettimeofday(&end,NULL);
  diff = end.tv_usec-start.tv_usec;
  //print(arr);
  for (i = 0; i < MAX; i++) {
    fprintf(fp,"%d\n", arr[i]);
  }
  fclose(fp);
  printf("thedifference is %ld\n",diff);
  free(arr);


  int flag, j;  
    char *str =malloc(sizeof(char)*101);
    char **ptr1 =malloc(sizeof(char*)*1000000); 
    srand((unsigned) time(NULL )); 
    FILE *fp1=fopen("database2.txt","w+");
    if(fp1==NULL) {
      /*printf("can't open, err %d\n", errno);*/
    }
    if ((str = (char*) malloc(101)) == 0 )  
    {  
        printf("erorrrrrrrr\n");
        return 0 ;  
    }  
    for(j=0;j<1000000;j++){
        for (i = 0; i < 100; i++)  
        {  
            flag = rand() % 3;  
            switch (flag)  
            {  
                case 0:  
                    str[i] = 'A' + rand() % 26;  
                    break;  
                case 1:  
                    str[i] = 'a' + rand() % 26;  
                    break;  
                case 2:  
                    str[i] = '0' + rand() % 10;  
                    break;  
                default:  
                    str[i] = 'x';  
                    break;  
            }  
        } 
        str[100] = '\0';  
    *(ptr1+j)=malloc(strlen(str)+1);
        strcpy(*(ptr1+j),str);
    }
    
    gettimeofday(&start,NULL);
   radixsort_string(ptr1);
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
    for(int i=0;i<1000000;i++){
        fprintf(fp1,"%s\n",*(ptr1+i));
        free(*(ptr1+i));
        }
    printf("thedifference is %ld\n",diff);
    fclose(fp1);
    free(ptr1);
    free(str);
  

  return 0;
}