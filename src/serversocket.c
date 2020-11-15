#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
//https://www.tenouk.com/Module40c.html
int main()
{
    int a;
    a = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in mghaddress;
    mghaddress.sin_family = AF_INET;
    mghaddress.sin_port = htons(5000);
    mghaddress.sin_addr.s_addr = INADDR_ANY;
    int b;
    b = bind(a, (struct sockaddr *)&mghaddress, sizeof(mghaddress));
    listen(a, 500); //up to 5 connections
    int conn;
    conn = accept(a, 0, 0);
    char d[256] = "these data are from server";
    send(conn, d, sizeof(d), 0);
    close(a); //close socket
    return 0;
}