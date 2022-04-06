//Nomes: 
//Guilherme Narciso Lee - Numero USP: 12543203
//Bruno Alves Catão Silva - Número USP: 7553278
//Obs: Essa Ep deu um trabalho mas foi legal de fazer. Muito obrigado por ser nosso professor de IP.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int pixel =  0;

typedef struct
{
    int x, y;

}Ponto2D;
typedef struct
{
    int comprimento;
    int altura;
    int **matriz;

}Figura;

Figura * criar_figura(int comprimento, int altura)
{
    Figura * figura = (Figura *) malloc(sizeof(Figura));
    figura->altura = altura;
    figura->comprimento = comprimento;
    figura->matriz = (int **) malloc(altura * sizeof(int *));
    for(int linha = 0; linha < figura->altura; linha++)
    { 
        figura->matriz[linha] = (int *) malloc(comprimento * sizeof(int));
        for(int coluna = 0; coluna < figura->comprimento; coluna++)
        {
            figura->matriz[linha][coluna] = 0;
        }
    }
    return figura;
}
void gerar_figura(Figura * figura, char arquivo_entrada[32])
{
    FILE * abrir = fopen(arquivo_entrada, "wb");
    if(abrir)
    {
        fprintf(abrir, "P2\n%d %d\n%d\n", figura->comprimento, figura->altura, 255);
        for(int linha = 0; linha < figura->altura; linha++)
        {
            for(int coluna = 0; coluna < figura->comprimento; coluna++)
            {
                pixel = figura->matriz[linha][coluna];
                fprintf(abrir, "%d ", pixel);
            }
            fprintf(abrir, "\n");
        }
    }
}
void liberar_imagem(Figura * imagem){

	int lin;
	for(lin = 0; lin < imagem->altura; lin++) free(imagem->matriz[lin]);
	free(imagem->matriz);	
	free(imagem);		
}
void reta(Figura * imagem, Ponto2D p1, Ponto2D p2, int cor)
{
    int l, c;
    double comprimento, altura, a, b, linha , coluna;
    altura = p2.y-p1.y;
    comprimento = p2.x-p1.x;
    a = altura/comprimento;
    b = p1.y - a*p1.x;
    if(p2.x>p1.x)//Direita
    { 
        if(p2.y==p1.y)//Leste
        { 
            for(int lh1 = p1.x; lh1<= p2.x; lh1++) imagem->matriz[p1.y][lh1] = cor;
        }
        else//SE ou NE
        { 
            for(int x = p1.x; x<=p2.x; x++){
            linha = a*x+b;
            l = round(linha);
            imagem->matriz[l][x] = cor;
            }
        }
    }
    else if(p2.x==p1.x)//Mesmo eixo Y
    {
        if(p2.y>p1.y){//S
            for(int y = p1.y;y<=p2.y; y++){
                imagem->matriz[y][p1.x] = cor;
            }
        }
        else if(p2.y<p1.y){//N
            for(int y = p2.y; y<=p1.y; y++){
                imagem->matriz[y][p1.x] = cor;
            }
        }
        else{
            imagem->matriz[p2.y][p2.x] = cor;
        }
    }
    else if(p2.x<p1.x)//Esquerda
    {
        for(int x = p2.x; x<=p1.x; x++){
        linha = a*x+b;
        l = round(linha);
        imagem->matriz[l][x] = cor;
        }
    }
}
void retangulo_contorno(Figura * imagem, Ponto2D p1, Ponto2D p2, int cor)
{
    if(p2.x>p1.x)//Direita
    { 
        if(p2.y>p1.y)//SE
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++) imagem->matriz[lv1][p1.x] = cor;
            for(int lv2 = p1.y; lv2<= p2.y; lv2++) imagem->matriz[lv2][p2.x] = cor;
            for(int lh1 = p1.x; lh1<= p2.x; lh1++) imagem->matriz[p1.y][lh1] = cor;
            for(int lh2 = p1.x; lh2<= p2.x; lh2++) imagem->matriz[p2.y][lh2] = cor;
        }
        else if(p2.y==p1.y)//E
        {
            for(int lh1 = p1.x; lh1<= p2.x; lh1++) imagem->matriz[p1.y][lh1] = cor;
        }
        else if(p2.y<p1.y)//NE
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++) imagem->matriz[lv1][p1.x] = cor;
            for(int lv2 = p2.y; lv2<= p1.y; lv2++) imagem->matriz[lv2][p2.x] = cor;
            for(int lh1 = p1.x; lh1<= p2.x; lh1++) imagem->matriz[p2.y][lh1] = cor;
            for(int lh2 = p1.x; lh2<= p2.x; lh2++) imagem->matriz[p1.y][lh2] = cor;
        }
    }
    else if(p2.x==p1.x)//Mesmo eixo Y
    {
        if(p2.y>p1.y)//S
        {
            for(int y = p1.y; y <= p2.y; y++) imagem->matriz[y][p1.x] = cor;
        }
        else if(p2.y==p1.y)//C
        {
            imagem->matriz[p2.y][p2.x] = cor;
        }
        else if(p2.y<p1.y)//N
        {
             for(int y = p2.y; y <= p1.y; y++) imagem->matriz[y][p1.x] = cor;
        }
    }
    else if(p2.x<p1.x)
    {
        if(p2.y>p1.y)//SO
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++) imagem->matriz[lv1][p2.x] = cor;
            for(int lv2 = p1.y; lv2<= p2.y; lv2++) imagem->matriz[lv2][p1.x] = cor;
            for(int lh1 = p2.x; lh1<= p1.x; lh1++) imagem->matriz[p1.y][lh1] = cor;
            for(int lh2 = p2.x; lh2<= p1.x; lh2++) imagem->matriz[p2.y][lh2] = cor;
        }
        else if(p2.y==p1.y)//O
        {
            for(int lh1 = p2.x; lh1<= p1.x; lh1++) imagem->matriz[p1.y][lh1] = cor;
        }
        else if(p2.y<p1.y)//NO
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++) imagem->matriz[lv1][p2.x] = cor;
            for(int lv2 = p2.y; lv2<= p1.y; lv2++) imagem->matriz[lv2][p1.x] = cor;
            for(int lh1 = p2.x; lh1<= p1.x; lh1++) imagem->matriz[p2.y][lh1] = cor;
            for(int lh2 = p2.x; lh2<= p1.x; lh2++) imagem->matriz[p1.y][lh2] = cor;
        }
    }
}
void retangulo_preenchido(Figura * imagem, Ponto2D p1, Ponto2D p2, int cor)
{
    if(p2.x>p1.x)//Direita
    { 
        if(p2.y>p1.y)//SE
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    imagem->matriz[lv1][lh1] = cor;
                }
            }
        }
        else if(p2.y==p1.y)//E
        {
            for(int lh1 = p1.x; lh1<= p2.x; lh1++) imagem->matriz[p1.y][lh1] = cor;
        }
        else if(p2.y<p1.y)//NE
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    imagem->matriz[lv1][lh1] = cor;
                }
            }
        }
    }
    else if(p2.x==p1.x)//Mesmo eixo Y
    {
        if(p2.y>p1.y)//S
        {
            for(int y = p1.y; y <= p2.y; y++) imagem->matriz[y][p1.x] = cor;
        }
        else if(p2.y==p1.y)//C
        {
            imagem->matriz[p2.y][p2.x] = cor;
        }
        else if(p2.y<p1.y)//N
        {
             for(int y = p2.y; y <= p1.y; y++) imagem->matriz[y][p1.x] = cor;
        }
    }
    else if(p2.x<p1.x)
    {
        if(p2.y>p1.y)//SO
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    imagem->matriz[lv1][lh1] = cor;
                }
            }
        }
        else if(p2.y==p1.y)//O
        {
            for(int lh1 = p2.x; lh1<= p1.x; lh1++) imagem->matriz[p1.y][lh1] = cor;
        }
        else if(p2.y<p1.y)//NO
        {
           for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    imagem->matriz[lv1][lh1] = cor;
                }
            }
        }
    }
}
void clona(Figura * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3)
{  
    int i = 0;
    int *array = (int *)malloc((1+abs(p2.y-p1.y))*(1+abs(p2.x-p1.x+1))*sizeof(int));
    if(p2.x>p1.x)//Direita
    { 
        if(p2.y>p1.y)//Sudeste
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Leste
        {
            for(int lh1 = p1.x; lh1<= p2.x; lh1++)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = array[i];
                i++;
            }
        }
        else if(p2.y<p1.y)//Nordeste
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
    }
    else if(p2.x==p1.x)//Mesmo eixo Y
    {
        if(p2.y>p1.y){
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = array[i];
                i++;
            }
        }
        else if(p2.y<p1.y){
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = array[i];
                i++;
            }
        }
        else{
            imagem->matriz[p3.y][p3.x] = imagem->matriz[p1.y][p1.x];
        }
    }
    else if(p2.x<p1.x)//Esquerda
    {
        if(p2.y>p1.y)//Sudoeste
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Oeste
        {
            for(int lh1 = p2.x; lh1<= p1.x; lh1++)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = array[i];
                i++;
            }
        }
       else if(p2.y<p1.y)//Noroeste
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
    }
    free(array);
}
void clona_inverte_cor(Figura * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3)
{
    int i = 0, cor = 0;
    int *array = (int *)malloc((1+abs(p2.y-p1.y))*(1+abs(p2.x-p1.x+1))*sizeof(int));
    if(p2.x>p1.x)//Direita
    { 
        if(p2.y>p1.y)//Sudeste
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = 255 - array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Leste
        {
            for(int lh1 = p1.x; lh1<= p2.x; lh1++)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = 255 - array[i];
                i++;
            }
        }
        else if(p2.y<p1.y)//Nordeste
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = 255 - array[i];
                    i++;
                }
            }
        }
    }
    else if(p2.x==p1.x)//Mesmo eixo Y
    {
        if(p2.y>p1.y){
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = 255 - array[i];
                i++;
            }
        }
        else if(p2.y<p1.y){
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = 255 - array[i];
                i++;
            }
        }
        else{
            imagem->matriz[p3.y][p3.x] = 255 - imagem->matriz[p1.y][p1.x];
        }
    }
    else if(p2.x<p1.x)//Esquerda
    {
        if(p2.y>p1.y)//Sudoeste
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = 255 - array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Oeste
        {
            for(int lh1 = p2.x; lh1<= p1.x; lh1++)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = 255 - array[i];
                i++;
            }
        }
       else if(p2.y<p1.y)//Noroeste
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = 255 - array[i];
                    i++;
                }
            }
        }
    }
    free(array);
}
void clona_espelha_horizontal(Figura * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3)
{
	int i = 0;
    int *array = (int *)malloc((1+abs(p2.y-p1.y))*(1+abs(p2.x-p1.x+1))*sizeof(int));
    if(p2.x>p1.x)//Direita
    { 
        if(p2.y>p1.y)//Sudeste
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p2.x; lh1>=p1.x; lh1--)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Leste
        {
            for(int lh1 = p2.x; lh1>= p1.x; lh1--)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = array[i];
                i++;
            }
        }
        else if(p2.y<p1.y)//Nordeste
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p2.x; lh1>=p1.x; lh1--)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
    }
    else if(p2.x==p1.x)//Mesmo eixo Y
    {
        if(p2.y>p1.y){
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = array[i];
                i++;
            }
        }
        else if(p2.y<p1.y){
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = array[i];
                i++;
            }
        }
        else{
            imagem->matriz[p3.y][p3.x] = imagem->matriz[p1.y][p1.x];
        }
    }
    else if(p2.x<p1.x)//Esquerda
    {
        if(p2.y>p1.y)//Sudoeste
        { 
            for(int lv1 = p1.y; lv1<= p2.y; lv1++)
            {
                for(int lh1 = p1.x; lh1>=p2.x; lh1--)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Oeste
        {
            for(int lh1 = p1.x; lh1>= p2.x; lh1--)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = array[i];
                i++;
            }
        }
       else if(p2.y<p1.y)//Noroeste
        {
            for(int lv1 = p2.y; lv1<= p1.y; lv1++)
            {
                for(int lh1 = p1.x; lh1>=p2.x; lh1--)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
    }
    free(array);
}
void clona_espelha_vertical(Figura * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3)
{
    int i = 0;
    int *array = (int *)malloc((1+abs(p2.y-p1.y))*(1+abs(p2.x-p1.x+1))*sizeof(int));
    if(p2.x>p1.x)//Direita
    { 
        if(p2.y>p1.y)//Sudeste
        { 
            for(int lv1 = p2.y; lv1>= p1.y; lv1--)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Leste
        {
            for(int lh1 = p1.x; lh1<= p2.x; lh1++)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = array[i];
                i++;
            }
        }
        else if(p2.y<p1.y)//Nordeste
        {
            for(int lv1 = p1.y; lv1>= p2.y; lv1--)
            {
                for(int lh1 = p1.x; lh1<= p2.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
    }
    else if(p2.x==p1.x)//Mesmo eixo Y
    {
        if(p2.y>p1.y){
            for(int lv1 = p2.y; lv1>= p1.y; lv1--)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = array[i];
                i++;
            }
        }
        else if(p2.y<p1.y){
            for(int lv1 = p1.y; lv1>= p2.y; lv1--)
            {
                array[i] = imagem->matriz[lv1][p1.x];
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                imagem->matriz[lv1][p3.x] = array[i];
                i++;
            }
        }
        else{
            imagem->matriz[p3.y][p3.x] = imagem->matriz[p1.y][p1.x];
        }
    }
    else if(p2.x<p1.x)//Esquerda
    {
        if(p2.y>p1.y)//Sudoeste
        { 
            for(int lv1 = p2.y; lv1>= p1.y; lv1--)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
        else if(p2.y==p1.y)//Oeste
        {
            for(int lh1 = p2.x; lh1<= p1.x; lh1++)
            {
                array[i] = imagem->matriz[p1.y][lh1];
                i++;
            }
            for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
            {
                imagem->matriz[p3.x][lh1] = array[i];
                i++;
            }
        }
       else if(p2.y<p1.y)//Noroeste
        {
            for(int lv1 = p1.y; lv1>= p2.y; lv1--)
            {
                for(int lh1 = p2.x; lh1<= p1.x; lh1++)
                {
                    array[i] = imagem->matriz[lv1][lh1];
                    i++;
                }
            }
            i=0;
            for(int lv1 = p3.y; lv1<=p3.y+abs(p2.y-p1.y); lv1++)
            {
                for(int lh1 = p3.x; lh1<=p3.x+abs(p2.x-p1.x); lh1++)
                {
                    imagem->matriz[lv1][lh1] = array[i];
                    i++;
                }
            }
        }
    }
    free(array);
}
int main()
{
    int comprimento, altura, p1x, p1y, p2x, p2y, p3x, p3y, cor;
    char arquivo_entrada[32], operacao[32];
    Figura * figura;
    Ponto2D p1, p2, p3;
    scanf("%s %d %d ", arquivo_entrada, &comprimento, &altura);
    figura = criar_figura(comprimento, altura);
    while(scanf("%s", operacao) == 1 && strcmp(operacao, "FIM") != 0)
    {
        printf("%s\n", operacao);
        if(strcmp(operacao, "RETA") == 0){
			scanf("%d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &cor);
            p1.x = p1x;
            p1.y = p1y;
            p2.x = p2x;
            p2.y = p2y;
			reta(figura, p1, p2, cor);
		}
		else if(strcmp(operacao, "RETANGULO_CONTORNO") == 0){
			scanf("%d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &cor);
            p1.x = p1x;
            p1.y = p1y;
            p2.x = p2x;
            p2.y = p2y;
			retangulo_contorno(figura, p1, p2, cor);
		}
		else if(strcmp(operacao, "RETANGULO_PREENCHIDO") == 0){
			scanf("%d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &cor);
            p1.x = p1x;
            p1.y = p1y;
            p2.x = p2x;
            p2.y = p2y;
			retangulo_preenchido(figura, p1, p2, cor);
		}
		else if(strcmp(operacao, "CLONA") == 0){
			scanf("%d %d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);
            p1.x = p1x;
            p1.y = p1y;
            p2.x = p2x;
            p2.y = p2y;
            p3.x = p3x;
            p3.y = p3y;
			clona(figura, p1, p2, p3);
		}
		else if(strcmp(operacao, "CLONA_HOR") == 0){
			scanf("%d %d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);
            p1.x = p1x;
            p1.y = p1y;
            p2.x = p2x;
            p2.y = p2y;
            p3.x = p3x;
            p3.y = p3y;
			clona_espelha_horizontal(figura, p1, p2, p3);
		}
		else if(strcmp(operacao, "CLONA_INV") == 0){
			scanf("%d %d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);
            p1.x = p1x;
            p1.y = p1y;
            p2.x = p2x;
            p2.y = p2y;
            p3.x = p3x;
            p3.y = p3y;
			clona_inverte_cor(figura, p1, p2, p3);
		}
		else if(strcmp(operacao, "CLONA_VER") == 0){
			scanf("%d %d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);
            p1.x = p1x;
            p1.y = p1y;
            p2.x = p2x;
            p2.y = p2y;
            p3.x = p3x;
            p3.y = p3y;
			clona_espelha_vertical(figura, p1, p2, p3);
		}
		else{
		}
    }
    gerar_figura(figura, arquivo_entrada);
    liberar_imagem(figura);
    return 0;
}

