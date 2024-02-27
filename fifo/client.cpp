#include <fcntl.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char fname[50], buffer[1025];
    int req, res, n;

    req = open("req.fifo", O_WRONLY);
    res = open("res.fifo", O_RDONLY);

    if (req < 0 || res < 0)
    {
        cout << "Please Start the server first\n";
        exit(-1);
    }

    cout << "Enter filename to request : ";
    cin >> fname;
    write(req, fname, sizeof(fname));
    cout << "Received response\n-------------------------------------------\n";

    while ((n = read(res, buffer, sizeof(buffer))) > 0)
    {
        buffer[n] = '\0';
        cout << buffer;
    }

    cout << "-------------------------------------------\n";

    close(req);
    close(res);

    unlink("req.fifo");
    unlink("res.fifo");
    
    return 0;
}
