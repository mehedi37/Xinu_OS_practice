#include<xinu.h>
#include<stdio.h>

int commonVar = 0, range=10;

void sndA(sid32, sid32);
void sndB(sid32, sid32);

int concurrent() {
    sid32 prod, cons;
    prod = semcreate(1);
    cons = semcreate(0);
    if (prod == SYSERR || cons==SYSERR) {
        kprintf("Failed to create semaphore\n");
        return SYSERR;
    }
    resume(create(sndA, 1024, 20, "sndA", 2, prod, cons));
    resume(create(sndB, 1024, 20, "sndB", 2, cons, prod));
    return 0;
}


void sndA(sid32 prod, sid32 cons){
    int i;
    for(i=0;i<range;i++){
      wait(prod);
        printf("sndA: %d\n", commonVar);
      signal(cons);
      kprintf("ProdA: %d | ConsA: %d\n", (&semtab[prod])->scount, (&semtab[cons])->scount);
    }
    return;
}

void sndB(sid32 cons, sid32 prod){
  int i;
  for(i=0;i<range;i++){
    wait(cons);
      printf("sndB: %d\n", ++commonVar);
    signal(prod);
    kprintf("ProdB: %d | ConsB: %d\n", (&semtab[prod])->scount, (&semtab[cons])->scount);
  }
  return;
}