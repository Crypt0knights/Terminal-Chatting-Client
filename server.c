#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    int fd = 0;
    char buff[1024];
    char nbuff[1024];
    
    //Setup Buffer Array
    memset(buff, '0',sizeof(buff)); 

    //Create Socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
        if(fd<0)
    {
        perror("Client Error: Socket not created succesfully");
        return 0;
    }
    //Structure to store details
    struct sockaddr_in server; 
    memset(&server, '0', sizeof(server)); 

    //Initialize    
    server.sin_family = AF_INET;
    server.sin_port = htons(8000); 
        server.sin_addr.s_addr = htonl(INADDR_ANY);
   

    bind(fd, (struct sockaddr*)&server, sizeof(server)); 

    int in;
    
    listen(fd, 10); 
    while(  in = accept(fd, (struct sockaddr*)NULL, NULL))
    {       
        int childpid,n;
        if ( (childpid = fork ()) == 0 ) 
        {
        
            //printf ("\nOne Client Connected !! ");
        
            //close listening socket
            close (fd);
        
            //Clear Zeroes
            bzero(buff,256);
            bzero(nbuff,256);
}