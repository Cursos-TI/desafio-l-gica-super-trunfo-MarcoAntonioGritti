#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct 
{
    char nomecidade [5];
    int populacao;
    float area; 
    float pib;
    int numeroDePontosTuristicos;
}Cidades;

typedef struct{
    int idPais;
    char nome;
    Cidades cidades[4];
}Paises;

Paises paises[8];
char letrasPaises[9] = "ABCDEFGH";

void cadastroPaisesCidades(){
     for (int p = 0; p < 8; p++){
        paises[p].idPais = p + 1;
        paises[p].nome = letrasPaises[p];
        for (int c = 0; c < 4; c++){
            
            sprintf(paises[p].cidades[c].nomecidade,"%c0%d",letrasPaises[p],c + 1);

            printf("População da cidade %s:\n", paises[p].cidades[c].nomecidade);            
            scanf("%d", &paises[p].cidades[c].populacao );
            printf("Área:\n");
            scanf("%f", &paises[p].cidades[c].area);
            printf("PIB:\n");
            scanf("%f", &paises[p].cidades[c].pib );
            printf("Numero de pontos turísticos:\n");
            scanf("%d", &paises[p].cidades[c].numeroDePontosTuristicos );    
        }
    }
}

void exibirPaisesCidades() {
    printf("\n========= LISTA DE PAÍSES E CIDADES =========\n");
    for (int p = 0; p < 8; p++) {
        printf("\n--------------------------------------------\n");
        printf("PAÍS %d - Nome: %c\n", paises[p].idPais, paises[p].nome);
        printf("--------------------------------------------\n");

        for (int c = 0; c < 4; c++) {
            printf("Cidade: %s\n", paises[p].cidades[c].nomecidade);
            printf("  População: %d\n", paises[p].cidades[c].populacao);
            printf("  Área: %.2f km²\n", paises[p].cidades[c].area);
            printf("  PIB: %.2f\n", paises[p].cidades[c].pib);
            printf("  Pontos Turísticos: %d\n", paises[p].cidades[c].numeroDePontosTuristicos);
            printf("--------------------------------------------\n");
        }
    }
    printf("=============================================\n");
}


void menuJogo(){
    bool jaForamCadastrados = false;
    while (true)
    {     
        printf("------------MENU-------------\n");
        printf("1 -CADASTRAR PAÍSES E CIDADES\n");
        printf("2 - EXIBIR PAÍSES E CIDADES\n");
        printf("3 - BATALHA DE CARTAS\n");
        printf("-----------------------------\n");
        char escolha;
        printf("O que você deseja fazer?");
        scanf(" %c",&escolha);
        switch (escolha)
        {
        case '1':
            if(jaForamCadastrados == false){
                cadastroPaisesCidades();
                jaForamCadastrados = true;
            }else{
                printf("CIDADES E PAÍSES JA FORAM CADASTRADOS!");
            }
            break;
        case '2':
            exibirPaisesCidades();
            break;
        case '3':
            batalhaDeCartas();
            break;
        default:
            break;
        }

        char resp;
        printf("DESEJA CONTINUAR? [S/N]");
        scanf(" %c", &resp);
        resp = toupper(resp);
        if(resp == 'S')
        {
            continue;
        }else{
            break;
        }
    }
}

void batalhaDeCartas(){
    int pais1, cidade1, pais2, cidade2;

    printf("Selecione o primeiro país (1 a 8): ");
    scanf("%d", &pais1);
    printf("Selecione a primeira cidade (1 a 4): ");
    scanf("%d", &cidade1);

    printf("Selecione o segundo país (1 a 8): ");
    scanf("%d", &pais2);
    printf("Selecione a segunda cidade (1 a 4): ");
    scanf("%d", &cidade2);

    pais1 -= 1;
    cidade1 -= 1;
    pais2 -= 1;
    cidade2 -= 1;
    
    int pontosCidade1=0, pontosCidade2=0;

    Cidades c1 = paises[pais1].cidades[cidade1];
    Cidades c2 = paises[pais2].cidades[cidade2];


    if(c1.populacao > c2.populacao){ 
        pontosCidade1++;
    }else if(c2.populacao > c1.populacao){
        pontosCidade2++;
    }else{
        pontosCidade1++;
        pontosCidade2++;
    }

    if(c1.area > c2.area){
        pontosCidade1++;
    }else if(c2.area > c1.area){
        pontosCidade2++;
    }else{
        pontosCidade1++;
        pontosCidade2++;
    }

    
    if(c1.pib > c2.pib){ 
        pontosCidade1++;
    }else if(c2.pib > c1.pib){
        pontosCidade2++;
    }else{
        pontosCidade1++;
        pontosCidade2++;
    }

    
    if(c1.numeroDePontosTuristicos > c2.numeroDePontosTuristicos){ 
        pontosCidade1++;
    }else if(c2.numeroDePontosTuristicos > c1.numeroDePontosTuristicos){
        pontosCidade2++;
    }else{
        pontosCidade1++;
        pontosCidade2++;
    }

    printf("Pontuação da cidade %s: %d\n", c1.nomecidade, pontosCidade1);
    printf("Pontuação da cidade %s: %d\n", c2.nomecidade, pontosCidade2);

    if (pontosCidade1 > pontosCidade2) {
        printf("A cidade %s venceu!\n", c1.nomecidade);
    } else if (pontosCidade1 < pontosCidade2) {
        printf("A cidade %s venceu!\n", c2.nomecidade);
    } else {
        printf("Empate entre as cidades %s e %s!\n", c1.nomecidade, c2.nomecidade);
    }

    
}

int main() {
        
    menuJogo();

    return 0;
}

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);
