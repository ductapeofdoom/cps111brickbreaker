# Project Description #
> Our game is a state of the art brick breaker. A brick breaker is a simple game in which a player-controlled paddle tries to bounce a ball from the bottom of the screen to break bricks which are at the top of the screen.

## Project Details ##
> Our project is a brick-breaker style game. The game is played as follows: a user-controlled paddle exists at the bottom of the screen. The player can launch a ball from the paddle toward the bricks at the top of the screen. As the ball collides with the bricks, they will break. (Some will take more than one hit to break) The player is then able to move the paddle left and right to bounce the ball around the screen, into the bricks.

> When the ball collides with a brick, it is destroyed and points are awarded to the player. The level continues until all the blocks are destroyed or until the player runs out of lives, which happens when the ball falls past the paddle, off the bottom of the screen.

> As the player progress through the levels more block types begin to appear. First, unbreakable blocks are introduced. The player does not have to break these, but they will be in the way of the blocks that must be broken. Also, blocks appear that require more hits to destroy but award more points. Then as the player progresses power-ups begin to appear granting abilities such as destroying unbreakable blocks, extra lives, double points, and a wall that keeps the ball from going off the screen. Also included in the game is the ability to play with a friend over a network and compete on the same level, for example a block destroyed in one world is destroyed in the other, and the ability to save your progress through the levels.

## Project Design Levels ##

**C Level**
  * Platform - Works on Linux (Ubuntu 12.04)
    * Technology - GUI interface implemented; Basic menu; Simple game interface
    * 1 brick design
    * Scoring - Destroyed blocks are worth varying point values, and all the final value is displayed at the end of the game and saved to a high score list.
    * Levels - different types of blocks
    * Installation - game should work on any directory
    * Screen resolution (1024x768)
    * Cheat mode - testing
      * Add life
      * No death
      * Ball speed
    * Help screen - how to play
    * Design - OO design patterns and techniques
    * Block types:
      * Basic - destroyed on one hit
      * Color 1 - 2 hits
      * Color 2 - 3 hits
      * Color 3 - 4 hits
      * Color 4 - 5 hits
      * Color 5 - 6 hits
    * Level difficulties
      * Basic = 20 bricks
      * Intermediate = 40 bricks
      * Advanced = 60 bricks
    * Different score list for difficulties of game

**B Level**
  * Speed up ball
  * 2 brick designs
  * Game save / load

**A Level**
  * Networked / multiuser capability
    * Competition on the same level for the highest score. Where there is only one world shared by two people.
    * For example: If Player 1 destroys the first block on the first row, then Player 2 will see that block destroyed, but he will not get points for it.

**Extra Credit**
  * More brick designs
  * Cheat: Shoot bullets from paddle to destroy blocks
  * Mouse control
  * Animations and sound
  * Power-ups - drop & must catch:
    * Double points - for “x” seconds
    * Able to destroy unbreakable bricks (2 max or “x” seconds)
    * Extra life
    * Solidifies bottom of screen for "x" seconds
    * Smaller paddle / enlarge "x" seconds

  * Powerup : extra ball running at same time
  * Speed up ball randomly
  * 3 brick designs
  * Platform - works on Windows/Mac



