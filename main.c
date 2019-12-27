#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int binRunner(char *, char *, char *, char *, char **);

int main(int argc, char *argv[], char *envp[]){

    return 0;
}

int binRunner(char *name, char *path, char *in_file, char *out_file, char *envp[]){

    int pid;
    int in_fd, out_fd;

    pid = fork();
    if(pid == 0){

        if(in_file != NULL){
            in_fd = open(in_file, O_RDWR);
            dup2(in_fd, 0);
            close(in_fd);
        }

        if(out_file != NULL){
            out_fd = open(out_file, O_CREAT|O_RDWR);
            dup2(out_fd, 1);
            close(out_fd);
        }

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