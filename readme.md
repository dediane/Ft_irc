# Usefull links for documentation:


#### Good introduction to ft_IRC project
http://chi.cs.uchicago.edu/chirc/index.html

#### Documentation for Architecture
https://www.rfc-editor.org/rfc/rfc2810

#### Documentation for Client protocol 
https://www.rfc-editor.org/rfc/rfc2812

#### Documentation for Channel management
https://www.rfc-editor.org/rfc/rfc2811

![](http://chi.cs.uchicago.edu/_images/architecture1.png)

## Messages:

A message is a string of maximun 510 characters and ends by "\r\n"(so 512 characters in total).
There is no null terminator. 

"**\r\n**" = CR-LF (Carriage Return - Line Feed)

Any message with more than 510 characters (not counting the delimiter) will be truncated, with the last two characters replaced with “\r\n”.

A message contains at least two parts: the command and the command parameters. 
ex: 

````
NICK amy

WHOIS doctor

MODE amy +o

JOIN #tardis

QUIT
````

Some messages also include a prefix before the command and the command parameters. 
The presence of a prefix is indicated with a single leading colon character. 

````
:borja!borja@polaris.cs.uchicago.edu PRIVMSG #cmsc23300 :Hello everybody

:doctor!doctor@baz.example.org QUIT :Done for the day, leaving
````

### Reply:

Special type of message called a reply.
When a client sends a command to a server, the server will send a reply.

Replies are used to acknowledge that a command was processed correctly, to indicate errors, or to provide information when the command performs a server query.
A reply is a message with the following characteristics:
It always includes a prefix.
The command will be a three-digit code. The full list of possible replies is specified in [RFC2812 §5].
The first parameter is always the target of the reply, typically a nick.

````
:irc.example.com 001 borja :Welcome to the Internet Relay Network borja!borja@polaris.cs.uchicago.edu

:irc.example.com 433 * borja :Nickname is already in use.

:irc.example.org 332 borja #cmsc23300 :A channel for CMSC 23300 studen
````


### functions to use:

socket() create endpoint and return fd. 

getsockopt() to get socket options you need to send the fd returned by socket() function

getsockname() return 0 on success and -1 on error, return the current address to which the socket is bound.

gethostbyname() return a struct type hostent and copy name into the h_name of the struct.

getaddrinfo() returns struct addrinfo: 
struct addrinfo {
    int              ai_flags;
    int              ai_family;
    int              ai_socktype;
    int              ai_protocol;
    socklen_t        ai_addrlen;
    struct sockaddr *ai_addr;
    char            *ai_canonname;
    struct addrinfo *ai_next;
};
freeaddrinfo -> to free.

bind() assigns the address specified by addr to the socket referred to
by the file descriptor sockfd

fcntl() performs one of the operations described below on the
open file descriptor fd.  The operation is determined by cmd.


### Connect to irssi

````
 irssi -c localhost -p 1050
 ````