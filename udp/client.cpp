#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 1024

using namespace std;

int main() {
    char buffer[MAX], msg[MAX];
    struct sockaddr_in servaddr;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(1234);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    while (true) {
        cout << "Client : ";
        cin.getline(msg, MAX);
        sendto(sock, msg, strlen(msg), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

        int n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        buffer[n] = '\0';
        cout << "Server : " << buffer << endl; // Added endl
    }

    return 0;
}



