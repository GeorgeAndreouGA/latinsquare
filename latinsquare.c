#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define N 9
int readLatinSquare(char txt[],int txtSize,int shortSquar[][N]);
void displayLatinSquare(int pin[][N],int n);
void play(int pin[][N],int n,char txt[]);
void canBoardUpdate(int i,int j,int val,int pin[][N],int size,char txt[]);
void writeLatinSquare(int pin[][N],int size,char txt[]);


/**
 * @brief Main function for testing the displayLatinSquare function.
 *
 * This function initializes an example nxn Latin square and calls
 * displayLatinSquare to print it.
 *
 * @return 0 if the program executes successfully.
 */

int main(int argc, char *argv[]){
    if(argc!=2){
    printf("you have to give 2 arguments");
    return 0; }


int shortSquare[N][N];
    int txtSize=strlen(argv[1]);

int size=readLatinSquare(argv[1],txtSize,shortSquare); 



play(shortSquare,size,argv[1]);



return 0;
}

/**
 * @brief Reads a Latin square from a file and stores it in a 2D array.
 *
 * This function reads a file that contains a Latin square. The first value is 
 * the size of the square, followed by the values of the square itself. If any 
 * value is invalid (e.g., out of bounds or incorrect format), it prints an error 
 * and exits the program.
 *
 * @param txt The name of the input file.
 * @param txtSize The size of the file name string.
 * @param shortSquare The 2D array where the Latin square will be stored.
 * @return The size of the Latin square (n x n).
 */

int readLatinSquare(char txt[],int txtSize,int shortSquare[][N]){
    FILE *read=NULL;
    read=fopen(txt,"r");

    if(read==NULL){
    perror("no such file");
     exit(-1);
    }
    int size=0;
    fscanf(read,"%d",&size);

      if(size>N||size<=1){
         perror("The number for creating the latinsqueare is invalid");
     exit(-1);
      }
    shortSquare[size][size];

    int number,plith=0,i=0,j=0;
while(fscanf(read,"%d",&number)!=EOF){
    plith++;
            if(number!=0 && number<-size){
                perror("File contains invalid values!");
                  exit(-1);
            }
         if(plith<=size*size){
            if(j<size){
      shortSquare[i][j]=number;
      j++;
      }
      else{
        i++;
        j=0;
        shortSquare[i][j]=number;
        j++;
      } 
         }
}
if(plith<size*size || plith>size*size){
perror("File contains more data than expected!");
                  exit(-1);
 }
 fclose(read);
 return size;
}

/**
 * @brief Displays a Latin square in a human-readable format.
 *
 * This function prints the current state of a Latin square, where:
 * - Negative values (fixed values) are shown in parentheses.
 * - Empty cells (values of 0) are shown as dots ('.').
 * - Positive values (user-inputted) are displayed as regular numbers.
 *
 * The grid is formatted with row and column separators to represent the structure of the Latin square.
 *
 * @param n The size of the Latin square (n x n).
 * @param square A 2D array containing the Latin square values.
 */
void displayLatinSquare(int pin[][N],int n) {
    // Print top border
    printf("+");
    for (int j = 0; j < n; j++) {
        printf("-----+");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            int value = pin[i][j];
            if (value < 0) {  
                printf(" (%d) ", -value);
            } else if (value == 0) {  
                printf("  0  ");
            } else {  
                printf("  %d  ", value);
            }
            printf("|");
        }
        printf("\n");

        
        printf("+");
        for (int j = 0; j < n; j++) {
            printf("-----+");
        }
        printf("\n");
    }
}

/**
 * @brief Allows the user to interactively solve the Latin square.
 *
 * This function continuously prompts the user to input commands to solve the 
 * Latin square. The user can insert values, clear cells, or save and exit the game.
 * It checks the legality of the moves and displays error messages if needed.
 *
 * @param pin A 2D array representing the Latin square.
 * @param n The size of the Latin square.
 * @param txt The name of the input file for saving progress.
 */

void play(int pin[][N],int n,char txt[]){


    int i=0,j=0,val=0;
bool didYouSolveIt=false;

while (didYouSolveIt == false) {
		
  displayLatinSquare(pin,n);
 printf("Enter your command in the following format:\n");
 printf(">i,j=val: for entering val at position (i,j)\n");
 printf(">i,j=0 : for clearing cell (i,j)\n");
 printf(">0,0=0 : for saving and ending the game");
 printf("Notice: i,j,val numbering is from [1...%d]\n>",n);


 if (scanf("%d,%d=%d",&i,&j,&val) != 3) {
while (getchar() != '\n') {};
printf("wrong format of command\n");
}
  else{
     int plith=0;
 canBoardUpdate(i,j,val,pin,n,txt);
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if(pin[i][j]!=0)
          plith++;

if(plith==n*n){
didYouSolveIt=true;
displayLatinSquare(pin,n);
printf("YOU SOLVED IT\n");
writeLatinSquare(pin,n,txt);
}
}
}
}

/**
 * @brief Updates the Latin square based on user input.
 *
 * This function checks if a value can be legally inserted into a specific cell 
 * in the Latin square. If the insertion is valid, the value is updated in the array.
 * If not, an error message is printed. It also handles clearing cells and saving 
 * the game state when necessary.
 *
 * @param i The row index where the user wants to insert a value.
 * @param j The column index where the user wants to insert a value.
 * @param val The value to be inserted or cleared.
 * @param pin A 2D array representing the Latin square.
 * @param size The size of the Latin square.
 * @param txt The name of the input file for saving progress.
 */
void canBoardUpdate(int i,int j,int val,int pin[][N],int size,char txt[]){
int plithGrammis=0,plithStillis=0;
int num = pin[i-1][j-1];


if( ((i>0 && i<=size) && (j>0 && j<=size) && (val >0 && val<=size)) || ((i>0 && i<=size) && (j>0 && j<=size) && val==0) ){
    if (val!=0){
      
      if(num==0){
         plithGrammis=0, plithStillis=0;

               for(int k=0;k<size;k++)
                   if(pin[i-1][k]==val || -pin[i-1][k]==val)
                         plithGrammis++;
          
             for(int k=0;k<size;k++){
                   if(pin[k][j-1]==val || -pin[k][j-1]==val)
                         plithStillis++;
              }


         if(plithStillis!=0 || plithGrammis!=0){
             printf("Error: Illegal value insertion!\n");
                }
       if(plithGrammis==0 && plithStillis==0){
          pin[i-1][j-1]=val;
           printf("Value  inserted!\n");
       }

      }
      else{
      printf("Error: cell is already occupied!\n");
      }
    
         }
         else{
         
         if(num<=0){
         printf("illegal to clear cell!\n");
         }
         else{
          pin[i-1][j-1]=val;
          printf("Value cleared!\n");
         }
    }
}

else if ((i<0 || i>size) || (j<0 || j>size) || (val<0 || val>size))
     printf("Error: i,j or val are outside the allowed range [1..%d]!\n",size);

 else if((i==0 && j==0 && val==0)){
writeLatinSquare(pin,size,txt);
exit(-1);
 }
    
}

/**
 * @brief Saves the current state of the Latin square to a file.
 *
 * This function writes the current state of the Latin square to a file. It is called
 * either when the game is solved or when the user opts to save and exit the game.
 * The file is named based on the input file, prefixed with "out-".
 *
 * @param pin A 2D array representing the Latin square.
 * @param size The size of the Latin square.
 * @param txt The name of the input file (used for naming the output file).
 */
void writeLatinSquare(int pin[][N],int size,char txt[]){

    char fullOutTxt[256];
    strcpy(fullOutTxt, "out-");
    strcat(fullOutTxt, txt);

FILE *write = fopen(fullOutTxt,"w");
 fprintf(write,"%d\n",size);
for(int i=0;i<size;i++){
for(int j=0;j<size;j++)
  fprintf(write,"%d ",pin[i][j]);
   fprintf(write,"\n");
}
fclose(write);
}
