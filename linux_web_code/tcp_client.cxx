#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>


#define BUFFER_SIZE 128

int main(int argc, char* argv[]) {
    int sockfd;
    char buffer[BUFFER_SIZE] = "hello server";
    struct sockaddr_in server_addr;

    if (argc < 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(-1);
    }

    // 分配一个链接描述符维护本地连接信息
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(-1);
    }

    // 配置服务端信息
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // 连接服务端口，将链接保存在sockfd
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(-1);
    }

    // 发送buffer
    send(sockfd, buffer, sizeof(buffer), 0);
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        exit(-1);
    }

    printf("recv from server: %s\n", buffer);
    close(sockfd);
    exit(0);
}