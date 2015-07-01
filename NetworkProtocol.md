# Overview #

The basic idea of the network protocol is a 3 part system composed of 2 clients and a server. The server will host a persistent game and will send the game state to the two clients. The clients will then send world updates to the server so it can update the world and echo back the updates.

# Message Format Description #

## Server ##

The server will send three kinds of messages to the clients and receive two kinds of messages. On the initialization of the game, the server will send a message containing the initial state of the bricks. The message will be formatted using integers between 1 and 7 to represent bricks and line breaks to represent new rows of bricks. The server will then send update messages to the clients after it has received an update message from a client and it has confirmed brick destruction. The message will be formatted using an integer to represent the unique id of the brick to be destroyed. The next kind of message the server will send is a level end message after all the bricks have been destroyed. The message will be formatted as an empty string to represent and empty world. The server will then receive final score messages from the clients and process them to determine the winner. Finally, The server will then send a message containing the name of the winner. The message will be formatted as a string containing the winning player's name.

## Client ##

The client will send two kinds of messages and receive four kinds of messages. The client will initially receive a world initialization method to create the world. The client will then send update messages to the server as bricks are destroyed and receive a message back from the server to update the world. The update message will be formatted as an integer to represent the unique id of the brick to be destroyed. Next, the client will receive a level end message from the server once all the bricks have been destroyed and then it will send a score message to the server. The score message will be formatted as an integer containing the final score of client. Finally, the client will receive a message containing the name of the winning player.