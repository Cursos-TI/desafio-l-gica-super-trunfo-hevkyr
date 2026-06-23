#include <stdio.h>

int main() {

    /* ---------- Cadastro da Carta 1 ---------- */
    char pais1[50] = "Brasil";
    int   populacao1        = 213000000;
    float area1             = 8515767.0;
    float pib1              = 2170.0;   // em bilhoes de dolares
    int   pontosTuristicos1 = 40;
    float densidade1 = populacao1 / area1;

    /* ---------- Cadastro da Carta 2 ---------- */
    char pais2[50] = "Argentina";
    int   populacao2        = 46000000;
    float area2             = 2780400.0;
    float pib2              = 640.0;    // em bilhoes de dolares
    int   pontosTuristicos2 = 28;
    float densidade2 = populacao2 / area2;

    int atributo1, atributo2; // escolhas do jogador (1 a 5)

    /* ---------- Menu: escolha do PRIMEIRO atributo ---------- */
    printf("===== Super Trunfo - Comparacao com Dois Atributos =====\n\n");
    printf("Carta 1: %s | Carta 2: %s\n\n", pais1, pais2);
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("Opcao: ");
    scanf("%d", &atributo1);

    // Valida o primeiro atributo antes de seguir para o segundo menu
    if (atributo1 < 1 || atributo1 > 5) {
        printf("\nOpcao invalida! Escolha um numero entre 1 e 5.\n");
        return 1; // encerra o programa, nao ha como continuar sem atributo valido
    }

    /* ---------- Menu DINAMICO: escolha do SEGUNDO atributo ----------
     * O atributo ja escolhido (atributo1) nao e exibido como opcao aqui.
     * Isso e o que torna o menu "dinamico" em vez de fixo.
     */
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    if (atributo1 != 1) printf("1 - Populacao\n");
    if (atributo1 != 2) printf("2 - Area\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos turisticos\n");
    if (atributo1 != 5) printf("5 - Densidade demografica\n");
    printf("Opcao: ");
    scanf("%d", &atributo2);

    // Valida o segundo atributo: precisa estar no intervalo E ser diferente do primeiro
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("\nOpcao invalida! Escolha um atributo diferente do primeiro, entre 1 e 5.\n");
        return 1;
    }

    float soma1 = 0.0; // soma dos atributos escolhidos para a Carta 1
    float soma2 = 0.0; // soma dos atributos escolhidos para a Carta 2

    printf("\n===== Resultado da Comparacao =====\n\n");
    printf("Carta 1: %s | Carta 2: %s\n\n", pais1, pais2);

    for (int passo = 0; passo < 2; passo++) {

        // Em cada passo, pegamos qual atributo estamos processando
        int atributoAtual = (passo == 0) ? atributo1 : atributo2;

        float valor1 = 0.0, valor2 = 0.0;
        const char *nomeAtributo;
        int densidadeInvertida = 0; // flag: 1 se este atributo usa regra invertida

        switch (atributoAtual) {
            case 1:
                nomeAtributo = "Populacao";
                valor1 = (float) populacao1;
                valor2 = (float) populacao2;
                break;
            case 2:
                nomeAtributo = "Area";
                valor1 = area1;
                valor2 = area2;
                break;
            case 3:
                nomeAtributo = "PIB";
                valor1 = pib1;
                valor2 = pib2;
                break;
            case 4:
                nomeAtributo = "Pontos turisticos";
                valor1 = (float) pontosTuristicos1;
                valor2 = (float) pontosTuristicos2;
                break;
            case 5:
                nomeAtributo = "Densidade demografica";
                valor1 = densidade1;
                valor2 = densidade2;
                densidadeInvertida = 1; // regra de vitoria invertida
                break;
            default:
                // nunca deveria chegar aqui, pois ja validamos atributo1 e atributo2 antes
                nomeAtributo = "Desconhecido";
                break;
        }

        printf("Atributo %d - %s:\n", passo + 1, nomeAtributo);
        printf("  %s: %.2f\n", pais1, valor1);
        printf("  %s: %.2f\n", pais2, valor2);

        // Operador ternario para indicar o vencedor individual deste atributo.
        // Se for densidade, a comparacao e invertida (menor valor vence).
        const char *vencedorAtributo = densidadeInvertida
            ? (valor1 < valor2 ? pais1 : (valor2 < valor1 ? pais2 : "Empate"))
            : (valor1 > valor2 ? pais1 : (valor2 > valor1 ? pais2 : "Empate"));

        printf("  Vencedor neste atributo: %s\n\n", vencedorAtributo);

        if (densidadeInvertida) {
            soma1 += -valor1;
            soma2 += -valor2;
        } else {
            soma1 += valor1;
            soma2 += valor2;
        }
    }

    /* ---------- Resultado final: soma dos atributos ---------- */
    printf("===== Resultado Final (soma dos atributos escolhidos) =====\n\n");
    printf("Soma %s: %.2f\n", pais1, soma1);
    printf("Soma %s: %.2f\n\n", pais2, soma2);

    // Operador ternario para o resultado final da rodada
    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("Vencedor da rodada: %s\n", (soma1 > soma2) ? pais1 : pais2);
    }

    return 0;
}
