#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 1024

using namespace std;

int main() {
    char buffer[MAX], msg[MAX];
    struct sockaddr_in servaddr, cliaddr;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    int reuse = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(1234);

    bind(sock, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    cout << "Waiting for message from client...\n";

    socklen_t len = sizeof(cliaddr);

    while (true) {
        int n = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        cout << "Client : " << buffer << endl; // Added endl
        cout << "Server : ";
        cin.getline(msg, MAX);
        sendto(sock, msg, strlen(msg), 0, (const struct sockaddr *)&cliaddr, len);
    }

    return 0;
}
