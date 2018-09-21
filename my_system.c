#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

char **get_input(char *input); 

int my_system(char* line){ 
          
        pid_t pid;
        int status;
        char** arg = get_input(line); //split line into array of char* to be parsed in exec()
        pid=fork();

        if(pid==0){ //child process
            execvp(arg[0],arg); //unable to properly recognize flags
            printf("Shouldnt print"); //doesnt print when flags are present

        }
        else {
            waitpid(pid, &status, WUNTRACED); //parent needs to wait until child executes 
        }
        free(line);
        free(arg);

        return 0;
}

char** get_input(char *input){
    char **arguments = malloc(8 * sizeof(char *)); //allocate space
    char *delimiter=" \n"; //commands are space 
    char *result;
    int i =0;

    result=strtok(input, delimiter);
    
    while(result != NULL) {
        arguments[i] = result;
        i++;
        result = strtok(NULL, delimiter);
    }
    arguments[i]=NULL;
    return arguments;
}
