#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
  char Maestra[4];
  int i, j, Num=0, Letras[4]; 
  srand(time(NULL));
  for(i=0; i < 4; i++)
    {
      Num = rand() % 7;
      if(i > 0)
        {
          j=0;
          while(j < i)
            {
              if(Num == Letras[j])
                {
                  Num= rand() % 7;
                  j=-1;
                }
              j++;
            }
        }
 Letras[i]= Num;
      if(Num == 0)
        {
          Maestra[i]= 'a';
        }
      if(Num == 1)
        {
          Maestra[i]= 'b';
        }
      if(Num == 2)
        {
          Maestra[i]= 'r';
        }
      if(Num == 3)
        {
          Maestra[i]= 'v';
        }
      if(Num == 4)
        {
          Maestra[i]= 'm';
        }
      if(Num == 5)
        {
          Maestra[i]= 'g';
        }
      if(Num == 6)
        {
          Maestra[i]= 'n';
        }
    }
  for(i=0; i<4; i++)
    printf("%c\n", Maestra[i]);
}
