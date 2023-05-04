#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5555

int main(void)
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    char buffer[10];

    // Criação do socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Erro na criação do socket.\n");
        exit(0);
    } else {
        printf("Socket criado com sucesso.\n");
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Configuração do endereço do servidor
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Ligação do socket com o endereço do servidor
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Erro na ligação do socket.\n");
        exit(0);
    } else {
        printf("Socket ligado com sucesso.\n");
    }

    // Servidor aguardando conexões
    if ((listen(sockfd, 5)) != 0) {
        printf("Erro na escuta do socket.\n");
        exit(0);
    } else {
        printf("Servidor aguardando conexões...\n");
    }

    // Aceitando conexões
    while (1) {
        int len = sizeof(cli);

        connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
        if (connfd < 0) {
            printf("Erro na aceitação da conexão.\n");
            exit(0);
        } else {
            printf("Conexão aceita do endereço %s e porta %d.\n",
                    inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));
        }

        // Mensagem de boas vindas para o cliente
        write(connfd, "Insira até 10 bytes de dados:\n", 31);

        // Recebimento dos dados do cliente
        read(connfd, buffer, sizeof(buffer));

        // Exibição dos dados recebidos
        printf("Dados recebidos: %s\n", buffer);

        // Fechamento da conexão
        close(connfd);
    }

    return 0;
}
