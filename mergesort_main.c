#include "mergesort.h"
int main(){
 struct  timeval start;
 struct  timeval end;
 unsigned  long diff;
  srand(  time(NULL) );
  int *buf=malloc(sizeof(int)*1000000);
  int *ptr;
  ptr=buf;
  /* 指定亂數範圍 */
  int min = 0;
  int max = 32767;
  int x;
  FILE *fp=fopen("database1.txt","w+");
   /* if(fp==NULL) {
      printf("can't open, err %d\n", errno);
    }*/
    for(int i=0;i<1000000;i++){
      x = rand() % (max - min + 1) + min;
      buf[i]=x;
    }
    gettimeofday(&start,NULL);
    merge_sort(ptr, 1000000);
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    //diff = end.tv_usec-start.tv_usec;
   
    for(int i=0;i<1000000;i++){
      fprintf(fp,"%d\n",ptr[i]);
    }
    fclose(fp);
  printf("thedifference is %ld\n",diff);
  free(buf);

int flag, i,j;  
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
                /*case 2:  
                    str[i] = '0' + rand() % 10;  
                    break;  */
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
   merge_sort_string(ptr1,1000000);
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
