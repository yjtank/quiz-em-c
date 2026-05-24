#include <stdio.h>
#include <ctype.h>
#include <string.h>

int perguntar(
    char pergunta[],
    char altA[],
    char altB[],
    char altC[],
    char altD[],
    char correta)
{
    char resposta;

    printf("\n%s\n", pergunta);

    printf("A) %s\n", altA);
    printf("B) %s\n", altB);
    printf("C) %s\n", altC);
    printf("D) %s\n", altD);

    do
    {
        printf("Resposta: ");

        scanf(" %c", &resposta);

        while (getchar() != '\n')
            ;

        resposta = toupper(resposta);

        if (
            resposta != 'A' &&
            resposta != 'B' &&
            resposta != 'C' &&
            resposta != 'D')
        {
            printf("Resposta invalida! Digite apenas A, B, C ou D.\n");
        }

    } while (
        resposta != 'A' &&
        resposta != 'B' &&
        resposta != 'C' &&
        resposta != 'D');

    if (resposta == correta)
    {
        printf("Acertou!\n");
        return 1;
    }
    else
    {
        printf("Errou!\n");
        return 0;
    }
}

int main()
{
    char nome[50];
    int pontos = 0;
    int erros = 0;
    int opcao;

    printf("=====================================\n");
    printf("         NEY QUIZ 1.0\n");
    printf("=====================================\n");

    printf("\nDigite seu nome: ");

    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("\n=====================================\n");
    printf("            REGRAS DO JOGO\n");
    printf("=====================================\n");

    printf("1. O quiz contem 10 perguntas.\n");
    printf("2. Responda usando: A, B, C ou D.\n");
    printf("3. O jogo termina apos 3 erros.\n");

    printf("\nBoa sorte, %s!\n", nome);

    printf("\n=====================================\n");
    printf("               MENU\n");
    printf("=====================================\n");

    printf("1 - Iniciar Quiz\n");
    printf("2 - Sair\n");

    do
    {
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida! Digite apenas 1 ou 2.\n");

            while (getchar() != '\n')
                ;

            opcao = 0;
        }
        else
        {
            while (getchar() != '\n')
                ;

            if (opcao != 1 && opcao != 2)
            {
                printf("Opcao invalida! Digite 1 ou 2.\n");
            }
        }

    } while (opcao != 1 && opcao != 2);

    if (opcao == 2)
    {
        printf("Quiz encerrado.\n");
        return 0;
    }

    char perguntas[10][100] = {
        "Em que ano Neymar nasceu?",
        "Qual era o numero da camisa de Neymar na selecao de 2022?",
        "Por qual clube Neymar iniciou sua carreira profissional?",
        "Quantas vezes Neymar foi campeao da Libertadores?",
        "Em que ano Neymar foi transferido para o Barcelona?",
        "Qual foi o valor da transferencia de Neymar para o PSG?",
        "Qual eh a nacionalidade de Neymar?",
        "Qual era o apelido de Neymar na infancia?",
        "Em qual clube Neymar joga atualmente (2026)?",
        "Qual a altura de Neymar?"};

    char altA[10][100] = {
        "1992",
        "7",
        "Santos",
        "1",
        "2014",
        "222 milhoes",
        "Portugues",
        "Arabia Saudita",
        "Santos",
        "1.85m"};

    char altB[10][100] = {
        "1994",
        "10",
        "Corinthians",
        "3",
        "2013",
        "150 milhoes",
        "Argentino",
        "Menino Ney",
        "Barcelona",
        "1.76m"};

    char altC[10][100] = {
        "1995",
        "9",
        "Palmeiras",
        "2",
        "2015",
        "190 milhoes",
        "Espanhol",
        "Ney da Silva",
        "PSG",
        "1.75m"};

    char altD[10][100] = {
        "1990",
        "5",
        "Flamengo",
        "4",
        "2016",
        "250 milhoes",
        "Brasileiro",
        "Neymar Junior",
        "Al-Hilal",
        "1.80m"};

    char respostas[10] = {
        'A',
        'B',
        'A',
        'A',
        'B',
        'A',
        'D',
        'B',
        'D',
        'C'};

    for (int i = 0; i < 10; i++)
    {
        int resultado = perguntar(
            perguntas[i],
            altA[i],
            altB[i],
            altC[i],
            altD[i],
            respostas[i]);

        if (resultado == 1)
        {
            pontos++;
        }
        else
        {
            erros++;
        }

        printf("\nPontos: %d\n", pontos);
        printf("Erros: %d/3\n", erros);

        if (erros == 3)
        {
            printf("\nGAME OVER\n");
            break;
        }
    }

    printf("\n===== RESULTADO FINAL =====\n");

    printf("Jogador: %s\n", nome);
    printf("Pontos finais: %d\n", pontos);
    printf("Erros: %d/3\n", erros);

    return 0;
}
