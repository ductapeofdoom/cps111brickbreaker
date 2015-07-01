# Milestone 2 Report #

## Hours Spent ##

Stephen Sidwell: 26 hours

Nick Marsceau: 31.25 hours

## Bug Summary ##

There are 5 known bugs with the program right now:

  * Graphical tearing with the ball: The ball appears to do some very strange things on redraw causing apparent tearing. This bug does not effect game play.
  * Corner Collision on Paddle: When the ball collides with one of the paddles two top corners it will sometimes bounce back in a straight line.
  * Mouse Move on Initial: When the user clicks inside the paddle and drags left the ball will move right instead. Also if the user moves the paddle too much with the mouse on the initial move the ball will fall off the screen.
  * Sounds do not play the way they are intended to: We have sounds playing, but we still want to tweak when they play. Right now, the clicking noise does not play every time the ball hits a brick, and it should play every time.
  * There is no error message if saving the game fails: When an error message functionality is implemented, saving fails every time. However, that functionality is removed for now to enable saving the game. The user will just not be notified in the event of the save failing.

## How to Play ##

**Single Player**
  1. Click New Game
  1. Enter your name, choose your difficulty, and click Ok
  1. For mouse control: click on the top left corner of the paddle and drag to move
  1. For arrow control: Hit tab then the left or right arrow on the keyboard to start the ball moving and continue to use these keys to move the paddle.

**Multiplayer**
  1. Click Multiplayer
  1. Click Start TCP Server
  1. Connect two clients the server
  1. Choose the level to play, enter your name and play like single player