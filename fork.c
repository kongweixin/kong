#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, const char* argv[])
{
    pid_t pid;
    for(int i=0;i<3;i++)
    {

        pid=fork();
        if(pid==0)
        {
            break;

        }
    }
    if(pid==0)
    {
        for(int i=0;i<2;i++)
        {

            pid=fork();
            if(pid==0)
            {
                break;
            }

        }
    }
    sleep(10);
    printf("thread %d exiting now",getpid());
    return 0;
}
