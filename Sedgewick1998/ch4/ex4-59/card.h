#ifndef CARD_H
#define CARD_H

typedef struct card* Card;
Card CARDinit(int suite, int number);
int CARDeval(Card);
void CARDshow(Card);
int CARDsuite(Card);
int CARDnumber(Card);

#endif
