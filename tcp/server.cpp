#include <bits/stdc++.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main() {
    int sersock, sock, fd, n;
    char buffer[1024], fname[50];

    sersock = socket(AF_INET, SOCK_STREAM, 0);
    if (sersock < 0) {
        cerr << "Error in socket creation" << endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = { AF_INET, htons(1234), inet_addr("127.0.0.1") };
    int reuse = 1;
    setsockopt(sersock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if (bind(sersock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        cerr << "Error in binding" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "\nServer is Online" << endl;
    listen(sersock, 5);

    sock = accept(sersock, NULL, NULL);

    recv(sock, fname, 50, 0);
    cout << "\nRequesting for file: " << fname << endl;

    fd = open(fname, O_RDONLY);
    if (fd < 0) {
        send(sock, "\nFile not found\n", 15, 0);
        exit(EXIT_FAILURE);
    }

    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
        send(sock, buffer, n, 0);
    }

    cout << "\nFile content sent\n";

    close(fd);
    return 0;
}
