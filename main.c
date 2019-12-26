#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Usage: fipe <bin1> <bin2>");
        return 1;
    }

    return 0;
}
