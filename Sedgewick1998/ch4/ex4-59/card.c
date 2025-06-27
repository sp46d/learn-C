#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#define SPADE "\u2660"
#define DIAMOND "\u2666"
#define HEART "\u2665"
#define CLUB "\u2663"

static const char* suites[] = { CLUB, HEART, DIAMOND, SPADE };
static const char* numbers[]
    = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

struct card {
    // 1 = Club, 2 = Heart, 3 = Diamond, 4 = Spade
    int suite;
    // 11 = Jack, 12 = Queen, 13 = King, 14 = Ace
    int number;
};

Card CARDinit(int suite, int number)
{
    Card new = malloc(sizeof(struct card));
    new->suite = suite;
    new->number = number;
    return new;
}

// CARDeval(Card a): Evaluate Card a to a numeric value for comparison. The
// resulted value is not a real or meaningful value of a card in the real world,
// but an artificial one made solely for comparison.
int CARDeval(Card a) { return CARDnumber(a) * 10 + CARDsuite(a); }

void CARDshow(Card a)
{
    printf("[%s", suites[a->suite]);
    printf("%s]", numbers[a->number]);
}

// CARDsuite(Card a): Returns Card a's suite in a numeric value (see the struct
// above)
int CARDsuite(Card a) { return a->suite + 1; }

// CARDnumber(Card a): Returns Card a's number (see the struct above)
int CARDnumber(Card a) { return a->number + 2; }
