#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 128

int main(int argc, char* argv[]) {
    int listenfd, connfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t peerlen;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage %s <ip> <port>\n", argv[0]);
        exit(-1);
    }

    // listenfd维护一个socket链接
    /* 一般有四种类型的socket: sock_stream, sock_datagram 这两种是最常见的，分别为tcp/udp
        AF_INET 是ipv4的32位地址加port，也就是套接字
     */
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(-1);
    }
    printf("listenfd: %d\n", listenfd);

    // 初始化一下server地址，制定套接字，ip，port
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // 将这个监听端口描述符与服务器地址相绑定
    if (bind(listenfd, (struct sockaddr*)& server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }
    printf("bind success\n");

    // listenfd监听链接，最大连接数为10
    if (listen(listenfd, 10) == -1) {
        perror("listem");
        exit(-1);
    }
    printf("Listening...\n");

    // 这里要初始化socketlen
    peerlen = sizeof(client_addr);
    while(1) {
        // listenfd监听链接clientaddr，并将连接符维护在connfd
        if ((connfd = accept(listenfd, (struct sockaddr*)&client_addr, &peerlen)) < 0) {
            perror("accept");
            exit(-1);
        }

        memset(buffer, 0, sizeof(buffer));
        // 开始接受服务端发来的消息
        if (recv(connfd, buffer, BUFFER_SIZE, 0) == -1) {
            perror("recv");
            exit(-1);
        }
        printf("Received a message: %s\n", buffer);
        strcpy(buffer, "Welcome to server");
        // 向 connfd 发送消息
        send(connfd, buffer, BUFFER_SIZE, 0);
        close(connfd);
    }

    close(listenfd);
    exit(0);
}