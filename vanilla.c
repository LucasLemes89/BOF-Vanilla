#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5555

int main() {
    int sockfd, newsockfd, n;
    socklen_t clilen;
    char buffer[10];
    struct sockaddr_in serv_addr, cli_addr;

    // Cria o socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Erro ao abrir socket");
        exit(1);
    }

    // Configura o endereço do servidor
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Associa o socket ao endereço do servidor
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Erro ao fazer bind");
        exit(1);
    }

    // Escuta na porta especificada
    listen(sockfd, 5);

    // Aceita uma nova conexão
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Erro ao aceitar conexão");
        exit(1);
    }

    // Lê a mensagem do cliente
    bzero(buffer, sizeof(buffer));
    n = read(newsockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Erro ao ler mensagem do cliente");
        exit(1);
    }

    // Imprime a mensagem do cliente na tela
    printf("Mensagem recebida: %s\n", buffer);

    // Fecha a conexão
    close(newsockfd);
    close(sockfd);

    return 0;
}
