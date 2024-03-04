#include <stdio.h>
#include <string.h>

void hangmanart(int c) {
    if (c == 0) {
        printf("+-------------+  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|________________  \n");
    }
    else if (c == 1) {
        printf("+-------------+  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|             @  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|________________  \n");
    }
    else if (c == 2) {
        printf("+-------------+  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|             @  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|  \n");
        printf("|________________  \n");
    }
    else if (c == 3) {
        printf("+-------------+  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|             @  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|            /    \n");
        printf("|  \n");
        printf("|  \n");
        printf("|________________  \n");
    }
    else if (c == 4) {
        printf("+-------------+  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|             @  \n");
        printf("|             |  \n");
        printf("|             |  \n");
        printf("|            / \\  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|________________  \n");
    }
    else if (c == 5) {
        printf("+-------------+ \n");
        printf("|             | \n");
        printf("|             | \n");
        printf("|             @ \n");
        printf("|            /|  \n");
        printf("|             |  \n");
        printf("|            / \\  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|________________  \n");
    }
    else if (c == 6) {
        printf("+-------------+ \n");
        printf("|             | \n");
        printf("|             | \n");
        printf("|             @ \n");
        printf("|            /|\\  \n");
        printf("|             |  \n");
        printf("|            / \\  \n");
        printf("|  \n");
        printf("|  \n");
        printf("|________________  \n");
    }
}

int main() {
    int count;
    scanf("%d", &count);
    hangmanart(count);
    return 0;
}
