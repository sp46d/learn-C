// All cards must be tracked during the game. Once the game is finished, memory
// allocated for each and every card must be properly freed.

#include "poker.h"
#include "agent.h"
#include "cstack.h"
#include "deck.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int n_players;
static Agent* agents;
static Agent me;
static Deck deck;
static Agent board;
static Cstack burnin;

void POKERinit(int n)
{
    agents = malloc(n * sizeof(Agent));
    n_players = n;
    for (int i = 0; i < n; i++) {
        agents[i] = AGENTinit();
    }
    me = AGENTinit();
    deck = DECKinit();
    board = AGENTinit();
    burnin = CSTACKinit();
}

void POKERbegin(void)
{
    for (int i = 0; i < n_players; i++) {
        printf("Player %d has participated in the game.\n", i + 1);
        usleep(500000);
    }
    printf("\n");
    usleep(1000000);
    printf("All players are ready.\n\n");
    printf("To begin, press <ENTER>.\n");

    char ch;
    while ((ch = getchar()) != '\n')
        ;
    printf("A new poker game has just started!\n\n");
    usleep(500000);
    printf("<< Dealer is now distributing the cards >>\n\n");

    // distribute hole cards to each player
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n_players; j++) {
            AGENTgetcard(agents[j], DECKdraw(deck));
        }
        AGENTgetcard(me, DECKdraw(deck));
    }
    usleep(1500000);

    printf("<< Initial set of cards are successfully dealt to each "
           "player >>\n\n");
    sleep(1);

    for (int i = 0; i < n_players; i++) {
        printf("Player %d: ", i + 1);
        AGENTshowcards(agents[i], 0);
    }
    printf("\n");
    ch = POKERprompt();
    printf("\n");

    printf("<< Flop: Three community cards are dealt after burning one "
           "card>>\n");
    sleep(1);

    // burn in one card
    CSTACKpush(burnin, DECKdraw(deck));

    // flop: three community cards
    for (int i = 0; i < 3; i++) {
        AGENTgetcard(board, DECKdraw(deck));
    }

    printf("\n");
    for (int i = 0; i < n_players; i++) {
        printf("Player %d: ", i + 1);
        AGENTshowcards(agents[i], 0);
    }

    printf("\n");
    printf("Board: ");
    AGENTshowcards(board, 1);
    printf("\n");
    ch = POKERprompt();
    printf("\n");
    printf("<< Turn: One community card is dealt after burning one card >>\n");
    sleep(1);

    CSTACKpush(burnin, DECKdraw(deck));
    // turn: one community card
    AGENTgetcard(board, DECKdraw(deck));

    printf("\n");
    for (int i = 0; i < n_players; i++) {
        printf("Player %d: ", i + 1);
        AGENTshowcards(agents[i], 0);
    }
    printf("\n");
    printf("Board: ");
    AGENTshowcards(board, 1);
    printf("\n");
    ch = POKERprompt();
    printf("\n");
    printf("<< River: One last community card is dealt after burning one card "
           ">>\n");
    sleep(1);

    CSTACKpush(burnin, DECKdraw(deck));
    // turn: one community card
    AGENTgetcard(board, DECKdraw(deck));

    printf("\n");
    for (int i = 0; i < n_players; i++) {
        printf("Player %d: ", i + 1);
        AGENTshowcards(agents[i], 0);
    }
    printf("\n");
    printf("Board: ");
    AGENTshowcards(board, 1);
    printf("\n");
    ch = POKERprompt();
    printf("\n");
    printf("<< All cards are dealt. Face up all cards >>\n");
    sleep(1);

    printf("\n");
    for (int i = 0; i < n_players; i++) {
        printf("Player %d: ", i + 1);
        AGENTshowcards(agents[i], 1);
    }
    printf("\n");
    printf("Board: ");
    AGENTshowcards(board, 1);
    printf("\n");
    ch = POKERprompt();
    printf("\n");
    POKERdestroy();
    printf("Thank you for playing!\n");
}

char POKERprompt(void)
{
    char ch;
    do {
        printf(">> My Cards:");
        for (int i = 0; i < 2; i++) {
            printf(" ");
            CARDshow(AGENTpickcard(me, i));
        }
        printf("  ACTION: [F] fold, [C] call, [R] raise\n");
        printf("> ");
        scanf(" %c", &ch);
    } while (ch != 'f' && ch != 'F' && ch != 'c' && ch != 'C' && ch != 'r'
        && ch != 'R');
    return ch;
}

void POKERdestroy(void)
{
    for (int i = 0; i < n_players; i++) {
        AGENTdestroy(agents[i]);
    }
    free(agents);
    AGENTdestroy(board);
    AGENTdestroy(me);
    CSTACKdestroy(burnin);
    DECKdestroy(deck);
}
