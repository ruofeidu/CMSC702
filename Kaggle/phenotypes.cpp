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


int main(){
    srand(time(0)^141592653);
    freopen("phenotypes.csv","r",stdin);
    freopen("phenotypes.in","w",stdout);

    string s;
    getline(cin, s); // FIRST LINE
    char ch, prev_ch, read_ch;
    int state = 0;
    int lines = 0;

    while ( scanf("%c", &ch) != EOF ) {
        bool print = true;
        read_ch = ch;
        if (ch == '"') continue;
        if (ch == 'j') state = JPT; else if (ch == 'c') state = CEU;
        if (ch >= 'a' && ch <= 'z') {
            prev_ch = read_ch;
            continue;
        }

        if (ch == 'A') {
            if (state == AN) state = AA; else
            if (state == BN) state = BA; else
            state = AN;
        } else
        if (ch == 'B') {
            if (state == AN) state = AB; else
            if (state == BN) state = BB; else
            state = BN;
        }
        if ((ch >= 'A' && ch <= 'Z') || ch == '.' || ch == '+') {
            prev_ch = read_ch;
            continue;
        }

        if (ch == ',') {
            if (state == JPT) {
                printf("\t0");
                state = NN;
            } else
            if (state == CEU) {
                printf("\t1");
                state = NN;
            } else
            if (state != NN) {
                printf("%d", state);
                state = NN;
            }

            if (prev_ch == ch && prev_ch == ',') {
                printf("4");
            }
            ch = '\t';
        }

        if (print) printf("%c", ch);

        if (ch == '\n') {
            ++lines;
            //stdout.flush();
        }
        prev_ch = read_ch;
        //if (lines > 10) break;
    }

    fclose(stdin);
    fclose(stdout);
}
