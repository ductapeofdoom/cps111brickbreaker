# Milestone 1 Report #

## Hours Spent ##

  * Stephen Sidwell 14
  * Nick Marsceau 17.25
  * Daniel Tan 10

## Bug Summary ##

There are three known bugs with the program right now.

  * Graphical tearing with the ball: The ball appears to do some very strange things on redraw causing apparent tearing. This bug does not effect game play.
  * Corner Collision on Paddle: When the ball collides with one of the paddles two top corners it will sometimes bounce back in a straight line.
  * Speed Ball and Scoring: When speed ball is turned on the score will increment in larger values than intended. This is due to the fact that the ball is moving faster than the collision detection intended.

## How to Play ##
  1. Click New Game
  1. Enter your name, choose your difficulty, and click Ok
  1. Hit the left or right arrow on the keyboard to start the ball moving and continue to use these keys to move the paddle.