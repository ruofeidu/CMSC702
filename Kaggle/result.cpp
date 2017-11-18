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
const int MAXL = 20000;
const int MAXM = 28500;
const int MAXT = 200;

int label[MAXL];
float result[MAXL];

int main(){
    srand(time(0)^141592653);
    freopen("result3.out","r",stdin);
    freopen("result3.csv","w",stdout);

	string s;
	getline(cin, s); 
    for (int i = 0; i < MAXT; ++i) {
        int id, value; 
        float value1, value2; 
        scanf("%d%f%f", &id, &value1, &value2);
        //result[id] = value;
        result[i] = value1;
    }
    fclose(stdin);

    freopen("test_genotypes.in","r",stdin);
    printf("Id,Category\n");
    for (int i = 0; i < MAXT; ++i) {
        int id, type;
        scanf("%d%d", &id, &type);
        if (type == 0) {
            printf("\"jpt.%d\",%.2f", id, result[i]);
        } else {
            printf("\"ceu.%d\",%.2f", id, result[i]);
        }
        for (int j = 0; j < MAXM; ++j) {
            int feature;
            scanf("%d", &feature);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
}
