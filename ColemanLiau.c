#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int contarLetras(const char *text);
int contarPalavras(const char *text);
int contarFrases(const char *text);
float mediaLP(int quantidadeLetras, int quantidadePalavras);
float mediaFP(int quantidadeFrases, int quantidadePalavras);
int coleman_liau(float mediaLP, float mediaFP);

int main(void){
    char tecla;

     printf("-------------------------------------\n");
        printf("| Autor: Guilherme Freitas de Souza \n");
        printf("| GitHub: @Guilhermefrsz\n");
        printf("| Insta: @guilhermefrsz\n");
        printf("| DATA DE CRIAÇÃO: 02/01/2024\n\n");
        printf("Precione ENTER para continuar.....");

        do{
          tecla =  getchar();
        }while (tecla != '\n');

    char text[1000];

    printf("What is the text, bro?\n");
    fgets(text, sizeof(text), stdin);

    int quantidadeLetras = contarLetras(text);
    int quantidadePalavras = contarPalavras(text);
    int quantidadeFrases = contarFrases(text);
    float LP = mediaLP(quantidadeLetras, quantidadePalavras);
    float FP = mediaFP(quantidadeFrases, quantidadePalavras);

    printf("--------------------------------------------\n");
    printf("| O texto possui %d letra(s).\n", quantidadeLetras);
    printf("| O texto possui %d palavras(s).\n", quantidadePalavras);
    printf("| O texto possui %d frase(s).\n", quantidadeFrases);
    printf("| A média de LP é: %.2f.\n", LP);
    printf("| A média de FP é: %.2f.\n", FP);
    printf("------->");

    int indiceColemanLiau = coleman_liau(LP, FP);

    if(indiceColemanLiau == 1){
         printf("Grade: 1\n");
    } else if(indiceColemanLiau == 16){
        printf("Grade: 16+\n");
    } else {
        printf("Grade: %i\n", indiceColemanLiau);
    }


    return 0;
}

int contarLetras(const char *text) {
    int qntLetras = 0;

    for(int i = 0; text[i] != '\0'; i++){
        if(isalpha(text[i])){
            qntLetras++;
        }
    }
    return qntLetras;

}

int contarPalavras(const char *text){
    int qntPalavras = 0;

    for(int i = 0; text[i] != '\0'; i++){
        if (text[i] == ' '){
            qntPalavras++;
        }
    }

    qntPalavras += 1;
    return qntPalavras ;
}

int contarFrases(const char *text){
    int qntFrases = 0;

    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            qntFrases++;
        }
    }

    return qntFrases;
}

float mediaLP(int quantidadeLetras, int quantidadePalavras){

   float MdLetras = (float)quantidadeLetras / quantidadePalavras * 100;

   return MdLetras;
}

float mediaFP(int quantidadeFrases, int quantidadePalavras){

   float MdFrases = (float)quantidadeFrases / quantidadePalavras * 100;

   return MdFrases;
}


int coleman_liau(float mediaLP, float mediaFP){
    float indice = 0.0588 * mediaLP -0.296 * mediaFP - 15.8;

    int grade = round(indice);

    if(grade <= 1){
        return 1;
    } else if (grade >= 16){
        return 16;
    } else {
        return grade;
    }


}

