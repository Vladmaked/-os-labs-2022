#include "stdio.h"
#include "unistd.h"

int main() {
    int pid2 = fork();
    if (pid2 == 0) {
        int pid3 = fork();
        if (pid3 != 0) {
            int pid4 = fork();
            if (pid4 != 0) {
                int pid5 = fork();
            }
        }
    } else {
        int pid6 = fork();
        if (pid6 == 0) {
            int pid7 = fork();
        }
    }
    sleep(180);

    return 0;
}
