#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main()
{
    int a;
    a = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in mghaddress;
    mghaddress.sin_family = AF_INET;
    mghaddress.sin_port = htons(5000);
    mghaddress.sin_addr.s_addr = INADDR_ANY;
    int b;
    b = connect(a, (struct sockaddr *)&mghaddress, sizeof(mghaddress));
    char c[1024]; //buffer
    recv(a, &c, sizeof(c), 0);
    printf("%s\n", c);
    return 0;
}