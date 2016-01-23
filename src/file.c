#include "file.h"

char *sockaddr_from_audit_log(char *logline) {
  char *saddr;

  if (strncmp(logline, "type=SOCKADDR ", 14) != 0)
    return NULL;
  else if ((saddr = strstr(logline, " saddr=")) == NULL)
    return NULL;
  else
    return saddr + 7;
}
