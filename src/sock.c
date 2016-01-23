#include "sock.h"

/*
 * Translates string of binary bytes into a byte array
 * Note: does not handle packed_str if it has an odd length
 */
unsigned char *bytes_from_packed_string(char *packed_str) {
  unsigned int b = 0, i = 0, odd = 0;
  unsigned char *bytes = NULL;
  size_t len;
 
  if (!packed_str)
    return NULL;

  len = strlen(packed_str);
  if (len < 1)
    return NULL;

  odd = len % 2;
  bytes = (unsigned char *) malloc(len + odd);
  if (!bytes)
    return NULL;

  while (i < len) {
    sscanf(packed_str + i, "%2hhx", &bytes[b]);
    i += 2;
    b++;
  }

  return bytes;
}

/*
 * Parse out IP and port from a IPv4/IPv6 sockaddr.
 */
struct ip_port *parse_sockaddr(unsigned char *s_inet) {
  struct sockaddr *saddr = (struct sockaddr *) s_inet;
  struct sockaddr_in *saddr4 = (struct sockaddr_in *) s_inet;
  struct sockaddr_in6 *saddr6 = (struct sockaddr_in6 *) s_inet;
  struct ip_port *ret = (struct ip_port *) malloc(sizeof(struct ip_port));
  memset(ret, 0, sizeof(ip_port));

  if (saddr->sa_family == AF_INET) {
    inet_ntop(AF_INET, &saddr4->sin_addr, ret->ip, INET_ADDRSTRLEN);
    ret->port = ntohs(saddr4->sin_port);
  } else if (saddr->sa_family == AF_INET6) {
    inet_ntop(AF_INET6, &saddr6->sin6_addr, ret->ip, INET6_ADDRSTRLEN);
    ret->port = ntohs(saddr6->sin6_port);
  } else {
    fprintf(stderr, "Addr type (local socket?) not supported.\n");
    ret = NULL;
  }
  return ret;
}

