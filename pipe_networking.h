#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MESSAGE_BUFFER_SIZE 256

int client_handshake(&int a){
  char * name = ".pipe";
  int id = getpid();
  char pipename[25];
  sprintf(pipename,"%s%d",name, id);
  mkfifo(pipename, 0644);
  int server = open("pipe1", pipename, O_WRONLY);
  write(server, "hello", 6);
  char buffer[MESSAGE_BUFFER_SIZE];
  open(pipename,buffer, O_RDONLY); 
}
int server_handshake(&int a){
  mkfifo("pipe1", 0644);
  char buffer[MESSAGE_BUFFER_SIZE];
  int client = open("pipe1", buffer, O_RDONLY); 
  read(client, buffer, 6);
  remove("pipe1");
}
