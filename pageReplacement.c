
#include <stdio.h>
#include <stdlib.h>//contains malloc and free

//read THIS
//need mong malagay yung input string into an array for passing. Also, need ko rin malaman yung number of arguments or arr.length.

int FIFOalg(int input[], int n, int inputSize);//input is user input values delimited by spaces. N is size of array per output
int LRUalg(int input[], int n, int inputSize);
int OPTalg(int input[], int n, int inputSize);
int isFull(int* LRU, int n);
void printFrames(int* LRU, int n);
void pageReplace();
int main()
{
	char input;
	char *i;
	do{
		pageReplace();
		gets(&i);
		printf("\n\nDo you want to input another Reference String?[y/n]: ");
		scanf("%c", &input);
		gets(&i);
		if(input != 'n' || input != 'N' || input != 'y' || input != 'Y'){
			do{
				printf("\n\nDo you want to input another Reference String?[y/n]: ");
				scanf("%c", &input);
				gets(&i);
				if(input == 'n' || input == 'N' || input == 'y' || input == 'Y'){
					break;
				}
			}while(1);
		}
		if(input == 'n' || input == 'N'){
			break;
		}
		if(input == 'y' || input == 'Y'){
			continue;
		}
	}while(1);
    return 0;
}

void pageReplace(){
    int n;
    char *p;
    char str[50];
    int input[50];
	int i = 0, j;//i is input size
	float output;
	printf("Input Reference String: ");
	gets(str);
	//tokenize string and converts into integer array
	p = strtok(str, " ");
	input[i++] = atoi(p);
	do{
		p = strtok(NULL, " ");
		if(p != NULL)
			input[i++] = atoi(p);
	}while(p);

    printf("Input size of page frame: ");
    scanf("%d", &n);
    output = FIFOalg(input, n, i);
    printf("Number of page faults:%d\n", (int)output);
    printf("Percentage: %.2f\n", ((output/i)*100));
    
    output = OPTalg(input, n, i);
    printf("Number of page faults:%d\n", (int)output);
	printf("Percentage: %.2f\n", ((output/i)*100));
	
	output = LRUalg(input, n, i);
    printf("Number of page faults:%d\n", (int)output);
	printf("Percentage: %.2f\n", ((output/i)*100));
	 
    free(p);
    return 0;
}

//FIFO algo, check if inputted value exists in array, if yes, dont move cursor and get next val
//else if not, put in cursor pos then next val. and also print the whole array.
int FIFOalg(int input[], int n, int inputSize){//'input' array is user input delimited by spaces.
    int pageFault = 0;
    int cursor = 0;
    int exists = 0;//0 = false 1 = true
    printf("\nFIFO page replacement algorithm:\n");
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

int LRUalg(int input[], int n, int inputSize){
    int pageFault = 0, cursor = 0, exists = 0; // returned val
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
    
    printf("\nLRU page replacement algorithm:\n");
    
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

int ifExist(int* frames, int n, int key){
	int i;
	for(i = 0; i < n; i++){
		if(frames[i] == key){
			return 1;
		}
	}
	return 0;
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

void printFrames(int* LRU, int n){
    int full = 0, x;
    for( x = 0; x < n; x++){
    	 printf("|");
         if(LRU[x]==-40000){
              printf("-");
         }
         else{
         	printf("%d", LRU[x]);
         }     
    }  
    printf("\n");
}

int OPTalg(int input[], int n, int inputSize){
	int pageFault = 0;
	int exist, check, runner;
	if(n <= 0){
		printf("Unable to allocate memory.");
		return -1;
	}
	int *frames = malloc(n*sizeof(int));//create frames with n size
	int ctr, index, rep, x;

	printf("\nOPT page replacement algorithm:\n");
	//initialize frames
	for(ctr = 0; ctr < n; ctr++){
		frames[ctr] = -40000;
	}
	for(ctr = 0, runner = 0; ctr < inputSize; ctr++){
		if(runner >= n){
			runner = 0;
		}
        if(!isFull(frames, n)){//if frames is not yet full
            if(ifExist(frames, n, input[ctr]) == 1){//if the current pointer exist in the current frame, no page fault
				continue;
        	}
        	else{
        		frames[runner] = input[ctr];
	        	pageFault++;
	        	printFrames(frames, n);
	        	runner++;
        	}
        }
        else{
        	if(ifExist(frames, n, input[ctr]) == 1){//if the current pointer exist in the current frame, no page fault
				continue;
        	}
			else{
				index = getOptIndex(input, ctr, inputSize, frames, n);
				for(x = 0; x < n; x++){
					if(frames[x] == index){
						rep = x;
					}
				}
	   			frames[rep] = input[ctr];
	        	printFrames(frames, n);
	        	pageFault++;
			}
        }
	}
	return pageFault;
}
int getOptIndex(int *string, int current_pointer, int size_ref, int *frames, int frame_size ){
	int x, y, isWeightComputed = 1, index = current_pointer % frame_size;
	int indexScore[frame_size];//weights which is least used in frames
	for(x = 0; x < frame_size; x++){
		indexScore[x] = 0;
	}
	for(x = current_pointer; x < size_ref; x++){
		isWeightComputed = 1;
		for(y = 0; y < frame_size; y++){
			if(string[x] == frames[y]){//if the current pointed page is in frame
				indexScore[y] = indexScore[y] + 1;//add Score to the frame
			}
		}
		for(y = 0; y < frame_size; y++){//checks if all has a score
			if(indexScore[y] == 0){//if a frame dont have a score make it false
				isWeightComputed = 0;
			}
		}
		
		if(isWeightComputed == 1){//checks if atleast all has a score
			for(y = 0; y < frame_size; y++){//find which index has the lowest score
				if(indexScore[y] < indexScore[index]){
					index = y;
				}
			}
			return frames[index];
		}
	}
	for(y = 0; y < frame_size; y++){//find which index has the lowest score
		if(indexScore[y] == 0){
			index = y;
		}
	}	
	return frames[index];
}

