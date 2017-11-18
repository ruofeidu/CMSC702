#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <cmath>
#include <ctime>
#define JPT 6
#define CEU 7
#define NN -1
#define AN 4
#define BN 5
#define AA 0
#define AB 1
#define BB 2
#define BA 3
using namespace std;

const int INF = 200000000;
const int MAXN = 800;
const int MAXL = 10000;
const int MAXM = 28500;
const int MAXT = 200;

int label[MAXL];
double result[MAXL];

int main(){
    srand(time(0)^141592653);
    freopen("phenotypes.in","r",stdin);
    freopen("train.out","w",stdout);

    for (int i = 0; i < MAXN; ++i) {
        int id, value;
        scanf("%d%d", &id, &value);
        label[id] = value;
        result[id] = 0;
    }

    fclose(stdin);

    freopen("genotypes.in","r",stdin);
    for (int i = 0; i < MAXN; ++i) {
        int id;
        scanf("%d", &id);
        printf("%d", label[id]);
        for (int j = 0; j < MAXM; ++j) {
            int feature;
            scanf("%d", &feature);
            if (feature != 4) {
                if (feature == 1) {
                    printf("\t%d:0.5", j);
                } else {
                    feature /= 2;
                    printf("\t%d:%d", j, feature);
                }
            }
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
}
