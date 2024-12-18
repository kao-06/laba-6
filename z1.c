#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void int_in(int* n){
    char c[100];
    int error = 0;
    do{
    error = 0;
    fgets(c, sizeof(c), stdin);

    if (c[0] < '0' || c[0] > '9') {
      if (c[0] != '-') {
        error = 1;
      }
    }

    for (int i = 1; c[i] != '\n'; i++)
    {
      if (c[i] < '0' || c[i] > '9') {
        error = 1;
        break;
      }
    }

    if(!error)
    {
      if (sscanf(c, "%d", n) == 1)
        {
          return;
        }
      else{printf("Please enter one number\n");}
    }
    else{printf("Please enter a number\n");}
    }while(error);
    return;
}
void rand_in(int* n){
    srand(clock());
    *n = -15 + rand() % 66;
}
void merge(int* b, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* l;
    int* r;
    l =(int*) malloc(n1 * sizeof(int));
    r =(int*) malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        l[i] = b[left + i];
    for (int j = 0; j < n2; j++)
        r[j] = b[mid + 1 + j];
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2) {
        if (l[i] < r[j]) {
            b[left] = l[i];
            i++;
        } else {
            b[left] = r[j];
            j++;
        }
        left++;
    }
    while (i < n1) {
        b[left] = l[i];
        i++;
        left++;
    }
    while (j < n2) {
        b[left] = r[j];
        j++;
        left++;
    }
    free(l);
    free(r);
}
void sort(int* b, int left, int right){
    if(left < right){
        sort(b, left, (left + right) / 2);
        sort(b, (left + right) / 2 + 1, right);
        merge(b, left, (left + right) / 2, right);

    }
}
int main(){
    int n, f, k, j;
    int* a;
    int* b;
    f = -1;
    system("clear");
    while(f != 1 && f != 0){
        puts("for random input enter '0', for manual '1':");
        int_in(&f);
    }
    k = 0;
    if(f == 1){
        puts("please enter size of array");
        int_in(&n);
        a = (int*) malloc(n * sizeof(int));
        puts("please enter elements of array:");
        for(int i = 0;i < n;i++){
            int_in(&a[i]);
            if(a[i] > 0)
                k++;
        }
        puts("your array");
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
        puts("");
    }
    else{
        srand(clock());
        n = 1 + rand() % 30;
        a = (int*) malloc(n * sizeof(int));
        puts("size of generated array");
        printf("%d \n", n); 
        for(int i = 0;i < n;i++){
            rand_in(&a[i]);
            if(a[i] > 0)
                k++;
        }
        puts("your generated array:");
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
        puts("");
    }
    b = (int*) malloc(n * sizeof(int)); 
    j = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > 0){
            b[j] = a[i];
            j++;
        }
    }
    puts("your positive numbers:");
    for(int i = 0;i < k;i++){
        printf("%d " "", b[i]);
    }
    puts("");
    puts("your sorted positive numbers:");
    sort(b, 0, k - 1);
    for(int i = 0;i < k;i++){
        printf("%d " "", b[i]);
    }
    puts("");
    puts("your final array:");
    j = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > 0){
            printf("%d " "", b[j]);
            j++;
        }
        else
            printf("%d " "", a[i]);
    }
    puts("");
return 0;}