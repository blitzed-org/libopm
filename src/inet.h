#ifndef INET_H 
#define INET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#ifndef AF_INET6
#define AF_INET6 10
#endif

typedef struct _opm_sockaddr opm_sockaddr;

struct _opm_sockaddr {
        struct sockaddr_in sa4;
};

extern int inetpton(int, const char *, void *);
extern char *inetntop(int, const void *, char *, unsigned int);
extern struct hostent *opm_gethostbyname(const char *);


#endif /* INET_H */