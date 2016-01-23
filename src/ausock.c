#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sock.h"
#include "file.h"

int main(int argc, char **argv, char **envp) {
  size_t buf_len = 4096;
  char *buf = malloc(buf_len);
  char *packed_saddr;
  unsigned char *s_inet;
  struct ip_port *ipp;

  memset(buf, 0, buf_len);
  while ((fgets(buf, buf_len, stdin)) != NULL) {
    if (!(packed_saddr = sockaddr_from_audit_log(buf)))
      continue;
    s_inet = bytes_from_packed_str(packed_saddr);
    if (!(ipp = parse_sockaddr(s_inet)))
      continue;

    printf("%s:%d\n", ipp->ip, ipp->port);
    free(ipp);
    memset(buf, 0, buf_len);
  }
  return 0;
}
