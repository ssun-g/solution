#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int da ,ma, ya, de, me, ye;
    scanf("%d %d %d %d %d %d", &da, &ma, &ya, &de, &me, &ye);
    int ddiff = da-de;
    int mdiff = ma-me;
    int ydiff = ya-ye;
    if(ydiff > 0) printf("10000\n");
    else if(ydiff == 0 && mdiff > 0) printf("%d\n", 500*mdiff);
    else if(ydiff == 0 && ddiff > 0) printf("%d\n", 15*ddiff);
    else printf("0\n");

    return 0;
}