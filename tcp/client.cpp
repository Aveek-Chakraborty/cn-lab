#include <bits/stdc++.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main() {
    int sock, n;
    char buffer[1024], fname[50];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cerr << "Error in socket creation" << endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = { AF_INET, htons(1234), inet_addr("127.0.0.1") };

    while(connect(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) ;

    cout << "\nClient is connected to Server" << endl;

    cout << "\nEnter file name: ";
    cin >> fname;
    send(sock, fname, sizeof(fname), 0);
    cout << "\nReceived file data" << endl;
    cout << "---------------------------------------------------------" << endl;

    while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        cout << buffer;
    }

    cout << "---------------------------------------------------------" << endl;
    return 0;
}
