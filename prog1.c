#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i = 0;
  int j = 0;

  for(i = 0; i < 12; i++){
        for(j = 0; j < 26; j++){
            pid_t child = 0;
            child = fork();

            if (child < 0){ //error proof for forking
              perror("Unable to fork");
              exit(EXIT_FAILURE);
            }

            else if(child == 0){ //child code, as j goes up, each child prints out the next letters
              printf("%c", alpha[j]);
              exit(EXIT_SUCCESS);
            }
        }

        while(wait(NULL) != -1){} //waits for all children to terminate
        printf("\n"); //parent code
      }
  return EXIT_SUCCESS;
}
