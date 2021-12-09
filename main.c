#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int x =0;
void* fnc(void *arg) {
  long * val_arg = (long*) arg;
  printf("Bienvenue chez le thread ayant comme argument %d\n", x);
  

  //pthread_exit((void *) (unsigned long long)(dec)); 
}


void* lire_entier(void *arg) {
  long * val_arg = (long*) arg;
  int un_entier;
  printf("Bienvenue chez le thread ayant comme argument %ld\n", val_arg);
  printf("Priere de saisir un entier:");
  scanf("%ld", &un_entier);
  x=un_entier;
  pthread_join(arg, (void *)&(un_entier));

  printf("vouz avez lu:%d \n",un_entier);
printf("x:%d",x);

  

  pthread_exit((void *) (unsigned long long)(un_entier)); 
}

void* lire_entier_en_octal(void *arg) {
	// int z;
  long * val_arg = (long*) arg;
 // scanf("%ld", &z);
  int oct =  x;
  printf("Bienvenue chez le thread de la lecture en octale ayant comme argument %ld\n", val_arg);
  printf("le nombre lu en octale est :%o \n ",oct);
  
  
  pthread_join(arg, (void *)&(oct));
  

  pthread_exit((void *) (unsigned long long)(oct)); 
}
void* lire_entier_en_hexa(void *arg) {
  long * val_arg = (long*) arg;
  int hexa = x;
  printf("Bienvenue chez le thread de la lecture en hexadecimale ayant comme argument %ld\n", val_arg);
  printf("le nombre lu en hexadecimal est : %x \n",hexa);
  pthread_join(arg, (void *)&(hexa));

  pthread_exit((void *) (unsigned long long)(hexa)); 
}

int main(int argc, char *argv[]) {
	pthread_t t0;
	pthread_t t1;
	pthread_t t2;
	srand(time(NULL));
		long  val_retour, val_retour1, val_retour2;
clock_t start, end,start1, end1,start2, end2;
     double cpu_time_used,cpu_time_used1,cpu_time_used2;
     
     start = clock();
	
	pthread_create(&t0, NULL,lire_entier, (void *)&t0);
	
               				pthread_join(t0, (void *)&val_retour);
end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("le tps is %f\n", cpu_time_used);
         
     start1 = clock();
             pthread_create(&t1, NULL,lire_entier_en_hexa, (void *)&t1);

               				pthread_join(t1, (void *)&val_retour1);
               				
               				end1 = clock();
     cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
     printf("le tps is %lf\n", cpu_time_used1);

start2 = clock();
                pthread_create(&t2, NULL,lire_entier_en_octal, (void *)&t2);
                               				pthread_join(t2, (void *)&val_retour2);

                	end2 = clock();
     cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
printf("le tps is %lf\n", cpu_time_used2);
		pthread_exit(NULL);

	return 0;
}
