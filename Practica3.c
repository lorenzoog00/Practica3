#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
 
void Intro();
void Random(char Maestra[4]);
void Pregunta_comb(char Nuevo[8]);
void cuatro_letras(char Nuevo[8], int *flag);
void Letras_permitidas(char Nuevo[8], int *flag);
void No_repeticion(char Nuevo[8], int *flag);
void Comb_no_repetida(char Temp[4], char Acumulado[100], char Nuevo[8], int *flag, int i);
void Nuevo_Nuevo2(char Nuevo[8], char Nuevo2[4]);
void Num_aciertos(char Nuevo2[4], char Maestra[4]);
void Posicion_correcta(char Nuevo2[4], char Maestra[4]);
void Op_restantes(int i);
void Concatenar(char Nuevo2[4], char Acomulado[100]);
void Trampa(char Maestra[4]);
void Historia(char Temp[4],char Acomulado[4] ,char Maestra[4], int i);
void Mayus_a_minus(char Nuevo[8]);

int main(void)
{
  int i, flag;
  char Maestra[4], Nuevo[8], Acomulado[100], Nuevo2[4], Temp[4], Salirf[6], Historiaf[9];
  char Trampaf[7] = "trampa";
  strcpy (Salirf, "salir");
  strcpy (Historiaf, "historia");
  Intro();
  Random (Maestra);
 
 for(i=1; i<=16; i++)
    {
      Pregunta_comb(Nuevo);
      Mayus_a_minus(Nuevo);
      if(strcmp(Nuevo, Trampaf)==0 || strcmp(Nuevo, Salirf)==0 || strcmp(Nuevo, Historiaf)==0)
        {
          if(strcmp(Nuevo, Trampaf)==0)
            {
              Trampa(Maestra);
            }
 
	  if(strcmp(Nuevo, Salirf)==0)
            {
            }
          if(strcmp(Nuevo, Historiaf)==0)
            {
              Historia(Temp, Acomulado, Maestra, i);
            }
	}
      else
        {
          cuatro_letras(Nuevo, &flag);
          Letras_permitidas(Nuevo, &flag);
          No_repeticion(Nuevo, &flag);
          Comb_no_repetida(Temp, Acomulado, Nuevo, &flag, i);
          Nuevo_Nuevo2(Nuevo, Nuevo2);
          if(flag==1)
            {
              printf("Cometiste un error al ingresar los datos, por favor vuelve a intentarlo. Esta oportunidad no contará como una errada\n");
              i--;
	      flag=0;
	    }
          else
            {
              if(strcmp(Maestra, Nuevo2)==0)
                {
                  printf("\nGanaste, muchas felicidades Xime y Lorenzo te deben un gansito.\n");
                  i=18;
                }
	      else
                {
                  Num_aciertos(Nuevo2, Maestra);
                  Posicion_correcta(Nuevo2, Maestra);
                  Op_restantes(i);
                  Concatenar(Nuevo2, Acomulado);
                }
            }
        }
      
    }
 if(i==16)
   {
     printf("Perdiste, lo sentimos mucho");
   }
}
 
void Intro()
{
  printf("Este programa fue elaborado por Lorenzo Orozco y Ximena Baez\n");
  getchar();
  printf("El objetivo del juego es descubrir la combinacion que el programa ha \
generado aleatoriamente que consta de una combinacion de 4 letras, entre amaril\
lo (a), rojo ( r), gris (g), verde (v), morado (m), negro (n) y blanco (b), par\
a esto tendra 16 intentos donde después de cada tiro se mostrará cuantos colore\
s ha acertado y de estos colores correctos, si están en la posición adecuada. D\
e querer salir del juego teclear “salir” en minúsculas, de querer saber el hist\
orial de tiros, teclear 'historial'. Mucha suerte");
}
 
void Pregunta_comb (char Nuevo[8])
{
  printf("\nDame una combinación\n");
  fgets(Nuevo, 8, stdin);
}
 
void cuatro_letras(char Nuevo[8], int *flag)
{
  if(strlen(Nuevo)!=5)
    {
      *flag=1;
    }
}
 
void Letras_permitidas(char Nuevo[8], int *flag)
{
  int j;
  for(j=0; j>=3; j++)
    {
      Nuevo[j];
      if('a' || 'r' || 'v' || 'g' || 'm' || 'n' || 'b')
        {
        }
      else
        {
          *flag=1;
        }
    }
}
 
void No_repeticion(char Nuevo[8], int *flag)
{
  char Temporal;
  int k, h; // k y h son contadores que se incrementan y sirven para ir checand\
o el arreglo                                                                    
 
  for(k=0; k<=2; k++)
    {
      Temporal = Nuevo[k];
      for(h=k+1; h<=3; h++)
        {
          if(Nuevo[h] == Temporal)
            {
              *flag= 1;
            }
        }
    }
}
 
void Comb_no_repetida(char Temp[4], char Acomulado[100], char Nuevo[8], int *flag, int i)
{
  int j, k=0;
  for(j=0; j<=(i*4)-1; j++)
    {
      Temp[k] = Acomulado[j];
      k++;
      if(j+1 % 4 == 0)
        {
	  if(strcmp(Nuevo, Temp)==0)
	    {
              *flag = 1;
            }
          k=0;
        }
    }
}
 
void Nuevo_Nuevo2(char Nuevo[8], char Nuevo2[4])
{
  int j;
  for(j=0; j<=3; j++)
    {
      Nuevo2[j]=Nuevo[j];
    }
}
 
void Num_aciertos(char Nuevo2[4], char Maestra[4])
{
  int r,aciertos=0, j;
  for(r=0; r<4; r++)
    {
      for(j=0; j<4; j++)
	if(Nuevo2[j]==Maestra[r])
	   aciertos++;
    }
  //for(r=0; r<4; r++)
  
    //printf("%c", Nuevo2[r]);
  
  printf("\nNúmero de aciertos: %d\n", aciertos);
}
 
void Posicion_correcta(char Nuevo2[4], char Maestra[4])
{
  int posicion=0;
  if(Nuevo2[0]==Maestra[0])
    posicion++;
  if(Nuevo2[1]==Maestra[1])
    posicion++;
  if(Nuevo2[2]==Maestra[2])
    posicion++;
  if(Nuevo2[3]==Maestra[3])
    posicion++;
  printf("Número de aciertos en color y posición: %d", posicion);
}
 
void Op_restantes(int i)
{
      printf("\nTe quedan %d oportunidades\n ", 16-i);
}
 
void Concatenar(char Nuevo2[4], char Acomulado[100])
{
  strcat(Acomulado, Nuevo2);
}
 
void Historia(char Temp[4],char Acomulado[4], char Maestra[100], int i)
{
  int j, k=0, print;
  for(j=0; j<=(i*4)-1; j++)
    {
      Temp[k]=Acomulado[j];
      k++;
      if(j+1%4==0)
	{
	  for(print=0; print<4; print++)
	    {
	      printf("%c", Temp[print]);
	    }	     
	  Num_aciertos(Temp, Maestra);
	  Posicion_correcta(Temp, Maestra);
	  k=0;
	}
    }
}
 
void Random(char Maestra[4])
{
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
}
void Trampa(char Maestra[4])
{
  int h;
  printf("tramposooooo, la combinacion es");
  for(h=0; h<4; h++)
    {
      printf("%c", Maestra[h]); 
    }
}

void Mayus_a_minus(char Nuevo[8])
{
  int i;
  i=0;
  for(i=0; i<4; i++)
    {
      if(Nuevo[i]>= 'A' && Nuevo[i]<='Z')
	  Nuevo[i]= Nuevo[i] - 'A' + 'a';
    }
}
