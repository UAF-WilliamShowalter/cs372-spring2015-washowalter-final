#CS 372 Spring 2015 WAShowalter Final
==================================

Final exam's take home section. It implements an example of Chain of Responsibility Design Pattern. 
The implementation example is to perform firewall filtering with chains.

A "Request" (network datagram, in this example) goes through a chain of handlers that are geared to filter traffic matching themselves based on protocol and direction, for example, IPv4 input or IPv6 output. The chain is applied in the order specified below (the order is setup in the main, and can be manipulated):

`InputIPv4Handler -> InputIPv6Handler -> OutputIPv4Handler -> OutputIPv6Handler -> ForwardIPv4Handler ->  ForwardIPv6Handler -> NullHandler1`

NullHandler is an implementation of the Null Object design pattern.

##Limitations

The Handlers only output their handling to a logging observer, and do not apply their own filtering rules, as a real firewall filter would. My initial idea was to have each of the handler chains send the traffic down its own rule chain, so you would have the protocol/direction chains of responsibility and then the rule chains of responsibility. However, that would be a lot more work, and would break all of the tests in catch, and make adding new tests very complicated.

Logging also only logs the fact that it was processed by a handler and not passed on. It does not log the message details (source, destination, message, etc).

#Instructions:
This project includes submodules, so you should perform clones recursively.

`git clone --recursive https://github.alaska.edu/washowalter/cs372-spring2015-washowalter-final.git`

or

`git clone --recursive git@github.alaska.edu/washowalter/cs372-spring2015-washowalter-final.git`

If you clone without the recursive option, you will need to manually initialize the SwiftyJSON submodule:

`git submodule init SwiftyJSON`

`git submodule update`

