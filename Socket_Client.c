#include "stdio.h"
#include "winsock2.h"
#include "stdlib.h"
#include "conio.h"

#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)

#pragma comment(lib, "ws2_32.lib")

#define LENGTH 100

int main(){
    char *msg = "a";
    char client[2050] = "Client: ";
    unsigned long on = 1;
    int reader;
    WSADATA wsa;
    int sent = 0;
    SOCKET sock;
    struct sockaddr_in server;
    char *message;
    char *smessage;

    message = (char*)malloc(LENGTH * sizeof(char));
    smessage = (char*)malloc(LENGTH * sizeof(char));
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Failed. Error Code : %d", WSAGetLastError());
        getch();
        return 1;
    }

    printf("Initialised.\n");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket! Error: %d", WSAGetLastError());
        getch();
        return 1;
    }
    //textcolor(2);
    printf("Socket Created!\n");
    //ioctlsocket(sock, FIONBIO, &on);
    server.sin_addr.s_addr = inet_addr("192.168.100.8");
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Connect Error");
        getch();
        return 1;
    }
    puts("Connected\n");

    message = "ducvm10";
    send(sock, message, LENGTH, 0);
    recv(sock, smessage, LENGTH, 0);
    
    printf("%s\n", smessage);

}