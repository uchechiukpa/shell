#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(){
    char cmd[100];
    char *argv[10];
    while(1){
        printf("> ");
        fgets(cmd, 100, stdin);
        // printf("> ");
        // printf("command %s", cmd);
        cmd[strlen(cmd) - 1] = '\0';
        argv[0] = strtok(cmd, " ");
        int i = 0;
        while (argv[i] != NULL){
            i++;
            argv[i] = strtok(NULL, " ");
        };
        argv[i] = NULL;
        int pid = fork();
        if(pid == 0){
            execvp(argv[0], argv);
            fprintf(stderr, "Failed to execute command\n");
            exit(1);

        }else{
            wait(NULL);
        };


    }

    return 0;
}