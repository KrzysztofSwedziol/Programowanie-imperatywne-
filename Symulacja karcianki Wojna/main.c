#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int obecna_talia[52];
int talia_graczaA[52];   //do maina
int talia_graczaB[52];
int ziarno;
int A;
int B;
int tablica_wojnyA[52];
int tablica_wojnyB[52];
int C=0;
int D=0;
int j=0;
int wybor;
int max_konflikt;
int liczba_konfliktow=0;
int save_lenA=0;
int save_lenB=0;
//--------------------------------------------------------------------------------------
int outA=0, lenA=0, CBUFF_SIZEA=52; //do talii gracza A
int leftA=0;
//---------------------------------------------------------------------------------------
int outB=0, lenB=0, CBUFF_SIZEB=52; //do talii gracza B
int leftB=0;
//---------------------------------------------------------------------------------------

void rand_permutation(int n, int tab[]){
    for(int i=0; i<=n-1; i++){
        tab[i]=i;

    }
    for(int i=0; i<=n-2; i++){
        int k = (rand()%(n-i))+i;
        int a=tab[i];
        int b=tab[k];
        tab[i]=b;
        tab[k]=a;

    }

}

//----------------------------------------------------------------------------------------------------------------------



double cbuff_pushA(int card_number) {
    if(lenA>CBUFF_SIZEA){
        return INFINITY;
    }
    else{
        talia_graczaA[(outA + lenA)%CBUFF_SIZEA]=card_number;
        lenA++;
        return 0.0;
    }
}

int cbuff_popA(void) {
    if(lenA==0){
        return -1;
    }
    else{
        leftA=talia_graczaA[outA];
        lenA--;
        outA++;
        outA %= CBUFF_SIZEA;
        return leftA;
    }
}

int cbuff_stateA() {
    return lenA;
}

void cbuff_printA() {
    int l;
    for (int i = 0; i < lenA; i++) {
        l = (outA + i) % CBUFF_SIZEA;
        printf("%d ", talia_graczaA[l]);

    }
}


//----------------------------------------------------------------------------------------------------------------------

double cbuff_pushB(int card_number) {
    if(lenB>CBUFF_SIZEB){
        return INFINITY;
    }
    else{
        talia_graczaB[(outB + lenB)%CBUFF_SIZEB]=card_number;
        lenB++;
        return 0.0;
    }
}

int cbuff_popB(void) {
    if(lenB==0){
        return -1;
    }
    else{
        leftB=talia_graczaB[outB];
        lenB--;
        outB++;
        outB %= CBUFF_SIZEB;
        return leftB;
    }
}

int cbuff_stateB() {
    return lenB;
}

void cbuff_printB() {
    int l;
    for (int i = 0; i < lenB; i++) {
        l = (outB + i) % CBUFF_SIZEB;
        printf("%d ", talia_graczaB[l]);

    }
}



int main() {
    scanf("%d", &ziarno);
    scanf("%d", &wybor);
    scanf("%d", &max_konflikt);

    srand(ziarno);
    rand_permutation(52, obecna_talia);
    for(int i=0; i<=25; i++){
        cbuff_pushA(obecna_talia[i]);
    }
    for(int i=26; i<=51; i++){
        cbuff_pushB(obecna_talia[i]);
    }
    if(wybor==0){
        while (1){
            if((lenB<=0) || (lenA<=0)){
                break;
            }
            if(liczba_konfliktow>=max_konflikt){
                printf("%d, %d, %d", 0, lenA, lenB);
                break;
            }
            A=cbuff_popA();
            B=cbuff_popB();
            if((A/4)>(B/4)){
                cbuff_pushA(A);
                cbuff_pushA(B);
                liczba_konfliktow++;
            }
            if((B/4)>(A/4)){
                cbuff_pushB(B);
                cbuff_pushB(A);
                liczba_konfliktow++;
            }
            save_lenA=lenA;
            save_lenB=lenB;
            if((A/4)==(B/4)){              //-----WOJNA-----
                while((C/4)==(D/4)){
                    if((lenB<=0) || (lenA<=0)){
                        printf("%d\n%d\n%d", 1, save_lenA, save_lenB);
                        break;
                    }

                    C=cbuff_popA();
                    D=cbuff_popB();
                    tablica_wojnyA[j]=C;
                    tablica_wojnyB[j]=D;
                    j++;

                    if((lenB<=0) || (lenA<=0)){
                        printf("%d\n%d\n%d", 1, save_lenA, save_lenB);
                        break;
                    }


                    C=cbuff_popA();
                    D=cbuff_popB();
                    tablica_wojnyA[j]=C;
                    tablica_wojnyB[j]=D;
                    j++;

                    if((C/4)>(D/4)){
                        cbuff_pushA(A);
                        for(int i=0; i<j; i++ ){
                            cbuff_pushA(tablica_wojnyA[i]);
                        }
                        cbuff_pushB(B);
                        for(int i=0; i<j; i++){
                            cbuff_pushA(tablica_wojnyB[i]);
                        }
                        j=0;
                        C=0;
                        D=0;
                        liczba_konfliktow++;
                        break;
                    }

                    //--endif--

                    if((D/4)>(C/4)){
                        cbuff_pushB(B);
                        for(int i=0; i<j; i++){
                            cbuff_pushB(tablica_wojnyB[i]);
                        }
                        cbuff_pushB(A);
                        for(int i=0; i<j; i++){
                            cbuff_pushB(tablica_wojnyA[i]);
                        }
                        j=0;
                        C=0;
                        D=0;
                        liczba_konfliktow++;
                        break;
                    }

                    //--endif--


                }


            }
        }
        if(lenB<=0){
            printf("2\n%d", liczba_konfliktow);
        }
        if(lenA<=0){
            printf("3\n");
            cbuff_printB();
        }
    }
    if(wybor==1){
        while(1){
            if((lenB<=0) || (lenA<=0)){
                break;
            }

            if(liczba_konfliktow>=max_konflikt){
                printf("%d, %d, %d", 0, lenA, lenB);
                break;
            }

            A=cbuff_popA();
            B=cbuff_popB();

            if((A/4)>(B/4)){
                cbuff_pushA(A);
                cbuff_pushA(B);
                liczba_konfliktow++;
            }
            if((B/4)>(A/4)){
                cbuff_pushB(B);
                cbuff_pushB(A);
                liczba_konfliktow++;
            }
            if((A/4)==(B/4)){
                cbuff_pushB(B);
                cbuff_pushA(A);
            }

        }
        if(lenB<=0){
            printf("2\n%d", liczba_konfliktow);
        }
        if(lenA<=0){
            printf("3\n");
            cbuff_printB();
        }
    }


    return 0;
}


