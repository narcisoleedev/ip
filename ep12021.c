//Nome: Guilherme Narciso Lee
//Numero USP: 12543203

#include <stdio.h>
#include <math.h>
double a, b, c, z = 0;
//Queria incluir uma function booleana mas nao tem em c :( 
int triangulo(double d, double e , double f){
    if(d>fabs(e-f) && d<e+f){
        if(e>fabs(d-f) && e<d+f){
            if(f>fabs(d-e) && f<d+e){
                return 1;
            }
            else{
                return 0;
            }
        }
         else{
            return 0;
        }
    }
    else{
         return 0;
    }
}
void escalenoangulo(double d, double e, double f)
{
    double angulosesc[3]; int cont = 0;
    int i = 0;
    for(cont = 0; cont<3; cont++){
        if(cont==0){
            angulosesc[cont] = (pow(a,2)-pow(b,2)-pow(c,2))/(-2*b*c);
        }
        else if(cont==1){
            angulosesc[cont] = (pow(b,2)-pow(a,2)-pow(c,2))/(-2*a*c);
        }
        else if(cont==2){
            angulosesc[cont] = (pow(c,2)-pow(a,2)-pow(b,2))/(-2*a*b);
        }
        else{}
        if(angulosesc[cont]<0){
            i++;
            }
        //printf("\n O angulo %d e: %f graus.\n", cont, 360*acos(angulosesc[cont])/(2*3.1415));
    }
    if(i==1){
        printf("Classificacao em funcao dos angulos: OBTUSO\n");
    }
    else{
        printf("Classificacao em funcao dos angulos: AGUDO\n");
    }
}
void lados(double d, double e, double f){
    double altura, angulo, angulorad;
        if(d==e && d==f){
            printf("Classificacao em funcao dos lados: EQUILATERO\n");
            printf("Classificacao em funcao dos angulos: AGUDO\n");
        }
        else if(d==e&&d!=f){
            printf("Classificacao em funcao dos lados: ISOSCELES\n");
            altura = sqrt(pow(d, 2) - pow(f/2, 2));
            angulorad = 2*acos(altura/d);
            angulo = 360*angulorad/(2*3.1415);
            if(angulo<90){
                printf("Classificacao em funcao dos angulos: AGUDO\n");
            }
            else if(angulo==90){
                printf("Classificacao em funcao dos angulos: RETO\n");
            }
            else{
                printf("Classificacao em funcao dos angulos: OBTUSO\n");
            }
        }
        else if((d==f && d!=e)){
            printf("Classificacao em funcao dos lados: ISOSCELES!\n");
            altura = sqrt(pow(d, 2) - pow(e/2, 2));
            angulorad = 2*acos(altura/d);
            angulo = 360*angulorad/(2*3.1415);
            if(angulo<90){
                printf("Classificacao em funcao dos angulos: AGUDO\n");
            }
            else if(angulo==90){
                printf("Classificacao em funcao dos angulos: RETO\n");
            }
            else{
                printf("Classificacao em funcao dos angulos: OBTUSO\n");
            }
        }
        else if((e==f && e!=d)){
            printf("Classificacao em funcao dos lados: ISOSCELES!\n");
            altura = sqrt(pow(e, 2) - pow(d/2, 2));
            angulorad = 2*acos(altura/e);
            angulo = 360*angulorad/(2*3.1415);
            if(angulo<90){
                printf("Classificacao em funcao dos angulos: AGUDO\n");
            }
            else if(angulo==90){
                printf("Classificacao em funcao dos angulos: RETO\n");
            }
            else{
                printf("Classificacao em funcao dos angulos: OBTUSO\n");
            }
        }
        else{
            printf("Classificacao em funcao dos lados: ESCALENO\n");
            //Verifica se da pra fazer um Pitágoras:
            if((pow(d,2)==(pow(e,2)+pow(f,2))) || (pow(e,2)==(pow(d,2)+pow(f,2))) || (pow(f,2)==(pow(d,2)+pow(e,2)))){
                printf("Classificacao em funcao dos angulos: RETO\n");
            }
            //Isso deu bastante trabalho pra pensar
            else{
                escalenoangulo(a, b, c);
            }
        }
}
int main(){
    printf("Digite os valores para os lados A, B e C respectivamente:\n");
    printf("A:\n");
    scanf("%lf", &a);
    printf("B:\n");
    scanf("%lf", &b);
    printf("C:\n");
    scanf("%lf", &c);
    printf("\n");
    //Checar se é um triangulo mesmo:
    if(triangulo(a, b, c)==1){
        printf("Medidas dos lados formam um triangulo: VALIDO\n");
        //Ver em função dos lados:
        lados(a, b, c);
        //Cálculo da area:
        double p = (a+b+c)/2;
        double area = sqrt(p*(p-a)*(p-b)*(p-c));
        printf("Area do triangulo: %f\n", area);
        scanf("%d", &z);
    }
    else{
        printf("Medidas dos lados formam um triangulo: INVALIDO\n");
        scanf("%d", &z);

    }
    return 0;
}
