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

##Messages:

A message is a string of maximun 510 characters and ends by "\r\n"(so 512 characters in total).
There is no null terminator. 

"\r\n" = CR-LF (Carriage Return - Line Feed)

Any message with more than 510 characters (not counting the delimiter) will be truncated, with the last two characters replaced with “\r\n”.