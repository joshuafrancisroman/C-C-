
#include <stdio.h>
#include <stdlib.h>//contains malloc and free

//read THIS
//need mong malagay yung input string into an array for passing. Also, need ko rin malaman yung number of arguments or arr.length.

int FIFOalg(int input[], int n);//input is user input values delimited by spaces. N is size of array per output
int LRUalg(int input[], int n);
int isFull(int* LRU, int n);


int main()
{
    int n;
    scanf("%d", &n);
    int k[20] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };//make this user input.
    printf("Number of page faults:%d\n",FIFOalg(k, n));
    printf("\n");
    printf("Number of page faults:%d\n",LRUalg(k, n));
    system("pause");
    return 0;
}



//FIFO algo, check if inputted value exists in array, if yes, dont move cursor and get next val
//else if not, put in cursor pos then next val. and also print the whole array.
int FIFOalg(int input[], int n){//'input' array is user input delimited by spaces.
    int pageFault = 0;
    int cursor = 0;
    int exists = 0;//0 = false 1 = true
    int inputSize = 20;//size of input. must be dynamic.
    printf("FIFO page replacement algorithm:\n");
    int *FIFO; //this is a pointer to the stack (dynamic allocation using stacks as arrays
    FIFO = malloc( n * sizeof(int) );//N = number of memory locations in the stack, sizeOf = how big each location is. Returns a pointer
   
    if(FIFO==0 || FIFO==NULL)
    {
        printf("EMPTY");
        return -1;
    }
    int x;
    int check;
    int y;        
    for(x = 0; x < n; x++)
        FIFO[x] = -40000;//just using -40000 as a reference to null for all the values in the array
    
    
    for (x = 0; x < inputSize; x++){
        for (check = 0; check < n; check++){//this loop checks if the value is existing in the array
            if (input[x] == FIFO[check]){
                exists = 1;
                break;
            }
            exists = 0;
        }
        
        if (!exists){//if values does not exist in array, put in current cursor pos then output array
            pageFault++;
            FIFO[cursor++] = input[x];
            for (y = 0; y < n; y++){
                printf("|");
                if (FIFO[y] == -40000)
                   printf("-");
                else
                    printf("%d", FIFO[y]);
            }
            printf("\n");
        }
        
        if (cursor == n)
           cursor = 0;//circular array
    }
    free(FIFO);
    return pageFault;
}

int LRUalg(int input[],int n){
    int pageFault = 0, cursor = 0, exists = 0; // returned val
    int inputSize = 20;//size of input. must be dynamic.
    int x, y ,check, precVal = 0;
    int *LRU = malloc(n * sizeof(int));
    int *prec = malloc(n * sizeof(int));
    if(LRU == NULL || LRU == 0 || prec == 0 || prec == NULL){
           printf("Cannot allocate memory");
           return -1;
    }
    
    for(x = 0 ; x < n; x++){//initialize block of memory
          LRU[x] = -40000;
          prec[x] = -40000;    
    }
    
    printf("LRU page replacement algorithm:\n");
    
    for(x = 0 ; x < inputSize; x++){
          for(check = 0; check < n ; check++){//checks if value already exists
            if( input[x] == LRU[check]){
                exists = 1;
                prec[check] = precVal++;
                break;
            }
            exists = 0;          
          }
          
          if(!exists && isFull(LRU,n)==0){
             pageFault++;
             LRU[cursor] = input[x];
             prec[cursor++] = precVal++;
             for (y = 0; y < n; y++){
                printf("|");
                if (LRU[y] == -40000)
                   printf("-");
                else
                    printf("%d", LRU[y]);
             }
             printf("\n");
          }
          
          else if(!exists && isFull(LRU,n)==1){
               pageFault++;     
               int min = 40000,minL;
               for( y = 0; y < n; y++)//finds min prec value puts to min. minL holds the location of the min prec value
                    if(min > prec[y]){
                           min = prec[y];
                           minL = y;       
                    }
               
               cursor = minL; //insertion point
               LRU[cursor] = input[x];
               prec[cursor] = precVal++;
               for (y = 0; y < n; y++){
                    printf("|");
                    if (LRU[y] == -40000)
                       printf("-");
                    else
                        printf("%d", LRU[y]);
               }
               printf("\n");          
          }    
    }
    
    
    free(LRU);
    free(prec);
    return pageFault;
}

int isFull(int* LRU, int n){
    int full = 0, x;
    for( x = 0; x < n; x++){
         if(LRU[x]==-40000){
              full = 0;
              break;
         }
         full = 1;     
    }
    return full;  
}


