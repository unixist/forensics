#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define ADDR_SIZE INET6_ADDRSTRLEN

struct ip_port {
  char ip[ADDR_SIZE];
  unsigned short port;
} ip_port;

unsigned char *bytes_from_packed_string(char *);
struct ip_port *parse_sockaddr(unsigned char *);
