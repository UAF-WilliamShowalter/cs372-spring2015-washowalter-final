#CS 372 Spring 2015 WAShowalter Final
==================================

Final exam's take home section. It implements an example of Chain of Responsibility Design Pattern. 
The implementation example is to perform firewall filtering with chains.

A "Request" (network datagram, in this example) goes through a chain of handlers that are geared to filter traffic matching themselves based on protocol and direction, for example, IPv4 inbound or IPv6 outbound. The chain is applied in the order specified below (the order is setup in the main, and can be manipulated):

`InputIPv4Handler -> InputIPv6Handler -> OutputIPv4Handler -> OutputIPv6Handler -> ForwardIPv4Handler ->  ForwardIPv6Handler -> NullHandler1

NullHandler is an implementation of the Null Object design pattern.

#Instructions:
This project includes submodules, so you should perform clones recursively.

`git clone --recursive https://github.alaska.edu/washowalter/cs372-spring2015-washowalter-final.git`

or

`git clone --recursive git@github.alaska.edu/washowalter/cs372-spring2015-washowalter-final.git`

If you clone without the recursive option, you will need to manually initialize the SwiftyJSON submodule:

`git submodule init SwiftyJSON`

`git submodule update`

