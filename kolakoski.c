#include <stdio.h>
#include <stdlib.h>


int usage(char*);

int main(int argc, char **argv)
{
  // usage statment
  if (argc != 2) return usage(argv[0]);

  // define how long we want it to be
  const int MAX = atoi(argv[1]);
  // make an array set them all to 0
  int kola[MAX];
  for(int i = 0; i < MAX; i++)
    kola[i] = 0;

  // make 2 pointers looking at the start of the array
  int *setPtr;
  setPtr = &kola[0];
  int *checkPtr;
  checkPtr = &kola[0];
  int increas = 1;

  // i wasn't sure how to make it make the start so i hard coded it
  kola[0] = 1;
  kola[1] = 2;

  for(int i = 0; i < MAX; i++)
  {
    // if the pointer i have looking at the array is 1
    if(*checkPtr == 1)
    {
      // make the thing the second pointer is looking at the increase amount
      *setPtr = increas;
      setPtr++;
      checkPtr++;
      // switch the amount invreased
      if(increas == 1)
        increas = 2;
      else if(increas == 2)
        increas = 1;
    }
    // if its 2 do it twice
    else if(*checkPtr == 2)
    {
      *setPtr = increas;
      setPtr++;
      *setPtr = increas;
      setPtr++;
      checkPtr++;
      if(increas == 1)
        increas = 2;
      else if(increas == 2)
        increas = 1;

    }
    
    // when the second pointer gets to the end of the array stop making more numbers
    if(setPtr - &kola[0] == MAX)
    {
       break;
    }

  }
  
  float count;
  // printf sequence
  for(int i = 0; i < MAX; i++)
  {
    printf("%d",kola[i]);
    // its a 1 add to count so we get the ratio
    if (kola[i] == 1)
    {
      count++; 
    }
  }
  puts("");
  printf("fraction of 1s = %f\n",(float) count/MAX); 

  return 0;
}


int usage(char *argv)
{
  fprintf(stderr,"usage %s <num>\n", argv);
  fprintf(stderr,"some numbers don't work for some reason.\n");
  return 1;
}
