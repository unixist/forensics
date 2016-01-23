# ausock
Parse linux's auditd audit.log file for network connections

auditd doesn't log information in the most accessible way, least of all network-related information. `ausock` will parse out and simply print network call information from auditd logs.

# Build
```bash
root@precise64:~/forensics/ausock# make clean
mkdir -p obj
gcc -Wall -pedantic -std=c11 -c -o obj/sock.o src/sock.c
mkdir -p obj
gcc -Wall -pedantic -std=c11 -c -o obj/file.o src/file.c
mkdir -p bin
gcc -Wall -pedantic -std=c11 obj/file.o obj/sock.o src/main.c -o bin/ausock
```

# Use
```
root@precise64:~/forensics/ausock# bin/ausock < /var/log/audit/audit.log 2>&1 | grep -v 'not supported' | tail -30
2001:db8::1337:19
2001:db8::1337:20
2001:db8::1337:21
2001:db8::1337:22
:::22
0.0.0.0:22
10.0.2.3:53
91.189.91.15:80
91.189.91.24:80
91.189.91.13:80
91.189.91.14:80
91.189.91.23:80
2001:67c:1562::16:80
2001:67c:1562::14:80
2001:67c:1562::17:80
2001:67c:1562::15:80
2001:67c:1562::13:80
91.189.91.15:80
10.0.2.3:53
10.0.2.3:53
10.0.2.3:53
10.0.2.3:53
10.0.2.3:53
192.30.252.130:9418
10.0.2.3:53
192.30.252.131:22
10.0.2.3:53
192.30.252.130:22
10.0.2.3:53
192.30.252.131:22
root@precise64:~/forensics/ausock#
```

`ausock` reads from standard input and pulls out log entries that look like this:

 type=SOCKADDR msg=audit(1453586383.778:5989): saddr=020000350A0002030000000000000000
 
# Future
* Support local sockets (AF_UNIX/PF_LOCAL)
* Roll up `ausock` into a greater auditd timeline graph
