#include <stdio.h>

/*
 * Super Trunfo - Comparação de Cartas (Nível Novato)
 * ----------------------------------------------------
 * Cadastra duas cartas (cidades), calcula densidade populacional
 * e PIB per capita, e compara as cartas usando UM atributo
 * escolhido diretamente no código (sem interação com o usuário).
 */

int main() {

    /* ---------- Cadastro da Carta 1 ---------- */
    char estado1[3]  = "SP";
    char codigo1[4]  = "A01";
    char cidade1[50] = "Sao Paulo";
    int   populacao1     = 12300000;
    float area1          = 1521.0;
    float pib1           = 750.0;     // em bilhoes de reais
    int   pontosTuristicos1 = 25;

    /* ---------- Cadastro da Carta 2 ---------- */
    char estado2[3]  = "RJ";
    char codigo2[4]  = "B01";
    char cidade2[50] = "Rio de Janeiro";
    int   populacao2     = 6000000;
    float area2          = 1200.0;
    float pib2           = 330.0;     // em bilhoes de reais
    int   pontosTuristicos2 = 30;

    /* ---------- Calculos derivados ---------- */
    float densidade1 = populacao1 / area1;       // habitantes por km^2
    float densidade2 = populacao2 / area2;

    // PIB per capita: PIB esta em bilhoes, populacao em unidades,
    // entao multiplicamos por 1e9 para ter o valor em reais por habitante.
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    /* ---------- Exibicao dos dados cadastrados ---------- */
    printf("===== Cartas cadastradas =====\n\n");

    printf("Carta 1 - %s (%s) | Codigo: %s\n", cidade1, estado1, codigo1);
    printf("  Populacao: %d habitantes\n", populacao1);
    printf("  Area: %.2f km2\n", area1);
    printf("  PIB: %.2f bilhoes de reais\n", pib1);
    printf("  Pontos turisticos: %d\n", pontosTuristicos1);
    printf("  Densidade populacional: %.2f hab/km2\n", densidade1);
    printf("  PIB per capita: %.2f reais\n\n", pibPerCapita1);

    printf("Carta 2 - %s (%s) | Codigo: %s\n", cidade2, estado2, codigo2);
    printf("  Populacao: %d habitantes\n", populacao2);
    printf("  Area: %.2f km2\n", area2);
    printf("  PIB: %.2f bilhoes de reais\n", pib2);
    printf("  Pontos turisticos: %d\n", pontosTuristicos2);
    printf("  Densidade populacional: %.2f hab/km2\n", densidade2);
    printf("  PIB per capita: %.2f reais\n\n", pibPerCapita2);

    /* ---------- Comparacao das cartas ----------
     */
    printf("===== Comparacao de cartas (Atributo: Populacao) =====\n\n");

    printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);

    // Regra geral: maior valor vence (vale para populacao, area, PIB e PIB per capita)
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }


    return 0;
}
