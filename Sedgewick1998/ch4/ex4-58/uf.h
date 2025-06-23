#ifndef UF_H
#define UF_H

typedef struct uf* Uf;
Uf UFinit(int);
int UFfind(Uf, int, int);
void UFunion(Uf, int, int);

#endif
