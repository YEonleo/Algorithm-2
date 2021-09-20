#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct sentence{
   char x[10000];
   char y[100];
}Sentence;

void find_func(Sentence*,int);

int main() {
   int num;

   scanf("%d", &num);

   Sentence* smp_case = (Sentence*)malloc(sizeof(Sentence) * num);

   for (int i = 0; i < num; i++) {
      scanf("%s", smp_case[i].x);
      scanf("%s", smp_case[i].y);
   }

   find_func(smp_case,num);
   

   return 0;
}

void find_func(Sentence* sample,int num) {
   int k = 0;
   while (num !=0) {
      int s = strlen(sample[k].x);
      int t = strlen(sample[k].y);
      int** cmp_array = malloc(sizeof(int) * t + 1);

      for (int i = 0; i < t + 1; i++) {
         cmp_array[i] = (int*)malloc(sizeof(int) * s + 1);
      }
      for (int i = 0; i <= t; i++) {
         cmp_array[i][0] = 0;
      }
      for (int j = 0; j <= s; j++) {
         cmp_array[0][j] = 1;
      }

      for (int i = 0; i < t; i++) {
         for (int j = 0; j < s; j++) {
            if (sample[k].y[i] == sample[k].x[j]) {
               cmp_array[i + 1][j + 1] = cmp_array[i][j] + cmp_array[i + 1][j];
            }
            else {
               cmp_array[i + 1][j + 1] = cmp_array[i + 1][j];
            }
         }
      }
      printf("%d\n", cmp_array[t][s]);
      num--;
      k++;
   }

}