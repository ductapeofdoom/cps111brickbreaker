# Test Scripts #

## Basic Game Control ##

  1. Click the "New Game" button. A dialog asking for your name and the difficulty should appear.
  1. Enter your name, choose the hard difficulty from the drop-down box, and press the "Ok" button. The dialog should disappear and a game window should show up with 60 blue blocks, an orange ball, and a white paddle. Also the name you entered should be at the top of the window after "Player's Name."
  1. Click just left of the paddle and drag to the left. The paddle should move to your cursor and the ball should begin to move left.
  1. Continue to hold down a mouse button and drag the mouse in the black window. The paddle should continue to move with your cursor.
  1. Release the mouse and let the ball drop off the screen. The ball should reset to the middle of the paddle, and "Number of Lives" should go down by one.
  1. Now hit the "Tab" key on the keyboard and then hit the right arrow key. The paddle and the ball should now move right.
  1. While the ball is bouncing hit the "Pause" button. The game should freeze.
  1. Hit the "Resume" button. The game should begin again.
  1. Click on the "No Death" button and let the ball hit the bottom of the screen. The ball should bounce back up.
  1. Click the "Speed Ball" button and the speed of the ball should increase.
  1. Continue to play the level with these cheats enabled and you should see "Score" increment as you destroy each block and when the last block is destroyed you should receive a dialog asking if you want to continue.
  1. Case 1: Choose no and the game window should close.
  1. Case 2: Choose yes and a new level should generate containing blue and green blocks. Also your score from the previous level should still be after "Score."

## Save/Load Use ##

  1. Complete the previous test script, "Basic Game Control," using case 2.
  1. Start the ball going left and allow it to hit some blocks and fall off the screen. Then hit the "Save Game" button and close the window.
  1. Hit the "Load" button and a game window should come up with the world you just closed.

## High Score Tracking ##

  1. After completing "Basic Game Controls" with case 1, click on the "High Scores" button on the main menu. A new window should come up containing your score.
  1. Play another game and check your score. If your score was higher than your first one, it should be listed before your first score. If it was lower it should be listed after your first score.
  1. Play another 8 games. The High Score list should now be filled with 10 scores in descending numeric order.
  1. Play one more game and at least score higher than the lowest score on the list. Your new score should appear on the list and the lowest score should no longer appear.

## Multiplayer Functionality ##

  1. You will need to instances of the game running on your computer to complete this script. They will be refered to as "Game 1" and "Game 2."
  1. On Game 1 and Game 2 click the "Multiplayer" button. Two multiplayer windows should appear.
  1. On Game 1, hit the "Start TCP Server" button. "Server Status" on Game 1 should change to "Running."
  1. Hit the "Connect to TCP Server" button on Game 1. "Server Status" on Game 1 should change to "Waiting for more client connections" and "Connection Status" on Game 1 should change to connected.
  1. Hit the "Connect to TCP Server" button on Game 2. "Connection Status" on Game 2 should change to connected and a level choice dialog should appear over Game 1.
  1. Press "Ok." "Server Status" on Game 1 should change to "Level data sent," and two dialog boes asking for a name should appear over Game 1 and Game 2.
  1. Enter different names into each box and press "Ok." on each. After pressing "Ok" a game window will generate with the level selected earlier.
  1. Begin the ball moving on Game 1. As soon as the ball destroys a brick on Game 1, the same brick should also be destroyed on Game 2.
  1. Begin the ball moving on Game 2. Bricks destroyed on Game 2 should be reflected on Game 1.
  1. Case 1: Destroy all the bricks. A dialog should appear announcing the winner and after the dialog is closed the game window should disappear.
  1. Case 2: Lose all lives on both games.  A dialog should appear announcing the winner and after the dialog is closed the game window should disappear.