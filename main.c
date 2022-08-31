#include <stdio.h>
int digito = 1;
int cpf[12];
int m[10];
int m2[11];
int resultado_soma;
int resultado_soma2;
int d_verificador_1;
int d_verificador_2;
int passou1 = 0;
int passou2 = 0;
int valido;
void pede_cpf(){
    for (int i = 1; i < 12; i++ ){
        printf ("\ndigite o %dº dígito do cpf\n", digito);
        scanf ("%d", &cpf[i]);
        digito++;
    }
}
void multiplicacao1(){
    int multi = 10;
    for (int i = 1; i < 10; i++){
        m[i] = cpf[i] * multi;
        multi--;
    }
}
void soma1(){
    resultado_soma = m[1] + m[2] + m[3] + m[4] + m[5] + m[6] + m[7] + m[8] + m[9];
    d_verificador_1 = (resultado_soma * 10) % 11;
}
void multiplicacao2(){
    int multi = 11;
    for (int i = 1; i < 11; i++){
        m2[i] = cpf[i] * multi;
        multi--;
    }
}

void soma2(){
    resultado_soma2 = m2[1] + m2[2] + m2[3] + m2[4] + m2[5] + m2[6] + m2[7] + m2[8] + m2[9] + m2[10];
    d_verificador_2 = (resultado_soma2 * 10) % 11;
}

void compara(){
    if (d_verificador_1 == cpf[10]){
        passou1 = 1;

    }
    if (d_verificador_2 == cpf[11]){
        passou2 = 1;
    }
    valido = passou1 + passou2;
}

void verifica(){
    if (valido == 2){
        printf("\nO cpf foi validado com sucesso!\n");
    }
    else{
        printf("\nO cpf não passou no teste de validação\n");
        printf("Tente novamente com outro cpf!\n");
    }
}

int main(){
    pede_cpf();
    multiplicacao1();
    soma1();
    multiplicacao2();
    soma2();
    compara();
    verifica();
}