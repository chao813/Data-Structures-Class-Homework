#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "sorting.h"
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
  long *Array;
  double Comparisons = 0;
  double Moves = 0;
  double *N_Comp = &Comparisons;
  double *N_Move = &Moves;
  int *Size = malloc(sizeof(int));
  clock_t input;
  clock_t Stime1;
  clock_t Stime2;
  double Stotal = 0;
  clock_t output;

  input = clock();
  
  if(argc != 6){
    return EXIT_FAILURE;
  }

  Array = Load_File(argv[3], Size);
 
  if(argv[1][0] == '1'){ //seq 1
    if(argv[1][2] == 'i'){
      Print_Seq_1(argv[4], *Size);
      Stime1 = clock(); 
      Shell_Insertion_Sort_Seq1(Array, *Size, N_Comp, N_Move);
      Stime2 = clock();
      Stotal = (double)((Stime2 - Stime1)/CLOCKS_PER_SEC);
    }
    else if(argv[1][2] == 'b'){
      Print_Seq_1(argv[4], *Size);
      Stime1 = clock();
      Shell_Bubble_Sort_Seq1(Array, *Size, N_Comp, N_Move);
      Stime2 = clock();
      Stotal = (double)((Stime2 - Stime1)/CLOCKS_PER_SEC);
    }
    else {
      return EXIT_FAILURE;
    }
   }
  else if(argv[1][0] == '2'){ //seq 2
    if(argv[1][2] == 'i'){
      Print_Seq_2(argv[4], *Size);
      Stime1 = clock();
      Shell_Insertion_Sort_Seq2(Array, *Size, N_Comp, N_Move);
      Stime2 = clock();
      Stotal = (double)((Stime2 - Stime1)/CLOCKS_PER_SEC);
    }
    else if(argv[1][2] == 'b'){
      Print_Seq_2(argv[4], *Size);
      Stime1 = clock();
      Shell_Bubble_Sort_Seq2(Array, *Size, N_Comp, N_Move);
      Stime2 = clock();
      Stotal = (double)((Stime2 - Stime1)/CLOCKS_PER_SEC);
    }
    else {
      return EXIT_FAILURE;
    }
  }
  else {
    return EXIT_FAILURE;
  }
  
  Save_File(argv[5], Array, *Size);
  free(Array);
  free(Size);
  output = clock();
  double IO = (double)(output - input)/CLOCKS_PER_SEC;
  
  printf("Number of comparison: %le\n", *N_Comp);
  printf("Number of Moves: %le\n", *N_Move);
  printf("I/O time [sec]: %le\n", IO);
  printf("Sorting time [sec]: %le\n", Stotal);

  return EXIT_SUCCESS;
}
