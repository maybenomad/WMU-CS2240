# A7: Web Server

Yeah, I suppose we skipped ahead a few assignments. Oh, well. 

In this assignment you will be building a simple multi-process HTTP web server and profiling it. 

## The Web Server
Your server will have to do a few different things. First, it will need to `bind` to a port specified as a command line argument. After successfully doing this, it must `listen` for incoming client connections and `accept` them. (Hint: all of the highlighted words are the names of system calls used to do these things).

The server will need to fork() a new process for each connection that it is handling. It is not quite this simple though. If you simply keep forking new processes, when the client closes its connection, you will end up with a zombie process. These zombie processes will build up and slowly eat up your machine's resources. Obviously, this isn't good. 

To remedy this, you should write a signal handler for the `SIGCHLD` signal to properly dispose of zombified children (hehe). 

After the new process has been created, the server is responsible for reading data from the client (`recv`) and parsing it as an HTTP request. We are only concerned with GET requests. Remember that handy dictionary you wrote in A1? That'll be really useful here, since HTTP headers are a key/value data structure. 

Now that the GET request has been parsed, you can look up the file that is being requested. If the server can locate the file, it should form an appropriate response header and serve file back to the client with a 200 response code. If it can't find it, it should return a 404 response code. If there is some other kind of error, just throw a 500 response code. 

Note that you should support enough of the HTTP protocol to allow a web browser to navigate to the port your server is running on and successfully get a file. [This article](http://www3.ntu.edu.sg/home/ehchua/programming/webprogramming/http_basics.html) should help you with that. 
