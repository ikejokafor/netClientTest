#include "network.hpp"
#include <stdio.h>


int main(int argc, char** argv)
{
    int socket = -1;
    if((socket = client_connect()) == -1)
    {
        return -1;
    }
    
    
    int sentNo = 42;
    send_data(socket, (uint8_t*)&sentNo, sizeof(int));
    printf("Client sent %d\n", sentNo);
    
    
    int recvNo;
    recv_data(socket, (uint8_t*)&recvNo, sizeof(int), sizeof(int));
    printf("Client recvd a %d\n", recvNo);


    return 0;
}