#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}ponto;

//Prototipação
double calculaPi(int);
int selecionaQuantidade();
void imprimePi(int);
ponto* gerarPonto(double, double);

int main(void)
{
    printf("=============================================================\n");
    printf(" Descubra o valor de PI segundo o método de Monte Carlo\n");
    printf("=============================================================\n");
    int n = selecionaQuantidade();
    imprimePi(n);

    return 0;
}

double calculaPi(int n)
{
    int i, insideCircle = 0;
    //double x, y;
    ponto *pp;
    double n1;
    double n2;
    srand(time(NULL));
   
    for (i = 0; i < n; i++)
    {
        n1 = (double)rand() / RAND_MAX * 2.0 - 1.0;
        n2 = (double)rand() / RAND_MAX * 2.0 - 1.0;
        pp = gerarPonto(n1, n2);

        if (pp -> x * pp -> x + pp -> y * pp -> y <= 1)
        {
            insideCircle++;
        }
        free(pp);
    }
    return (double)4 * insideCircle / n;
}

int selecionaQuantidade()
{
    int n;
    printf("\nEscolha a quantidade de pontos aleatorios a serem gerados(Quanto mais, mais aproximado vai ser o resultado)\n");
    scanf("%d", &n);

    return n;
}

void imprimePi(int n)
{
    double pi = calculaPi(n);
    printf("%lf", pi);
}

ponto* gerarPonto(double n1, double n2){
    ponto *pp;
    pp = malloc(sizeof(ponto));
    pp -> x = n1;
    pp -> y = n2;

    return pp;
}