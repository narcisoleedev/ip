//Nome: Guilherme Narciso Lee
//Numero USP: 12543203
#include <stdlib.h>
#include <stdio.h>

double modulo(double n, double x){
    double dif = x*x-n;
    double menos = 0;
    if(dif>0)
    {
        return dif;
    }
    else{
        menos = dif*-1;
        return menos;
    }
}
int main()
{
    double n=0, e=0, x=0, inf = 0, sup = 0, var = 0;
    int cont = 0;
    printf("BEM VINDO AO CALCULADOR DE RAIZ QUADRADA!\n");
    printf("Programa desenvolvido por: Guilherme Narciso Lee\n");
    printf("Para sair, insira um valor nulo ou negativo a 'n'.\n");
    while(1==1)
    { 
    cont = 0, inf = 0, sup = 0, var = 0, x = 0;
    printf("\nInsira o valor de 'n' (valor para ser extraido a raiz quadrada):\n");
    scanf("%lf", &n);
    if(n<=0)
    {
        printf("Insira um valor positivo, por favor.\n");
        break;
    }
    printf("Insira o valor de 'e' (valor da aproximacao):\n");
    scanf("%lf", &e);
    do{
        if(cont==0)
        {
            inf = 0;
            sup = n;
        }
        else{
            if(cont==100)
            {
                break;
            }
        }
        if(modulo(n, (inf+sup)/2)<=modulo(n, sup))
        {
            if(inf!=0)
            {
            if(modulo(n, inf)<=modulo(n, (inf+sup)/2))
            {
                if(modulo(n, inf-(sup-inf)/2)<=modulo(n, inf))
                {
                var = inf;
                x = inf-(sup-inf)/2;
                printf("%d: [  %f,  %f], x= %f.\n", cont, inf, sup, x);
                inf = x;
                sup = var;
                }
                else{
                var = inf;
                x = x-(sup-inf)/2;
                printf("%d: [  %f,  %f], x= %f.\n", cont, inf, sup, x);
                //sup = x; 
                inf = x;
                sup = var;
                }
            }
            else{
                x = (inf+sup)/2;
                printf("%d: [  %f,  %f], x= %f.\n", cont, inf, sup, x);
                sup = x;
            }
            }
            else{ 
            x = (inf+sup)/2;
            printf("%d: [  %f,  %f], x= %f.\n", cont, inf, sup, x);
            sup = x;
            } 
        }
        else{
            x = sup + (sup-inf)/2;
            var = sup;
            printf("%d: [  %f,  %f], x= %f.\n", cont, inf, sup, x);
            inf = var;
            sup = x;
        }
        cont++;
    }while(modulo(n, x)>e);
    if(cont==100)
    {
    printf("\nO numero maximo de iteracoes foi atingido: %d\n", cont);
    printf("Diferenca absoluta: %lf\n", modulo(n, x));
    printf("Raiz quadrada: %lf\n", x);
    }
    else{ 
    printf("\nO numero de iteracoes: %d\n", cont);
    printf("Diferenca absoluta: %lf\n", modulo(n, x));
    printf("Raiz quadrada: %lf\n", x);
    }
    //printf("O valor da raiz e: %f, com um total de %d tentativas e %f de aproximacao.", x, cont, modulo(n, x));
    }
    return 0;
}
