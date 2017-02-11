#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, const char* argv[])
{
    int fd[2];
    pid_t pid;
    char buf;

    if(argc!=2)
    {
        fprintf(stderr,"Usgae:%s<string>\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if(pipe(fd)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid=fork();
    if(pid==-1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(pid==0)
    {
        close(fd[1]);
        while(read(fd[0],&buf,1)>0)
        {
            write(STDOUT_FILENO,&buf,1);
        } 
        write(STDOUT_FILENO,"\N",1);
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }
    else{
        close(fd[0]);
        write(fd[1],argv[1],strlen(argv[1]));
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
