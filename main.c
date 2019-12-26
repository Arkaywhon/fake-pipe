#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int binRunner(char *, char *, int, int, char **);

int main(int argc, char *argv[], char *envp[]){

    return 0;
}

int binRunner(char *name, char *path, int in_file, int out_file, char *envp[]){

    int pid;
    pid = fork();
    if(pid == 0){

        char *args[2];
        args[0] = name;
        args[1] = NULL;

        execve(path, args, envp);
        printf("Error with execve\n");
        return 1;
    }else if(pid > 0){
        wait(NULL);
    }else{
        printf("Error forking\n");
        return 1;
    }
}