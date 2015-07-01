# Overview #

The project uses a simple save format to save/load game states. The file contains the current level, the player's name, the current score, the current difficulty, the number of lives, data for each remaining brick in the level, and the current state of our cheats. These elements are all on separate lines in the file, and there is a '@' at the end of each line. When the user loads a game, it will pick right up at the spot where the user clicked "Save Game."

# Example #
_The comments on each line tell what that data stands for._
```
1@ //current level
Nicolas Marsceau@ //player name
0@ //score
1@ //difficulty (0 = easy, 1 = medium, 2 = hard)
5@ //number of lives
1(0,0) 1(40,0) 1(80,0) 1(120,0) 1(160,0) 1(200,0) 1(240,0) 1(280,0) 
1(320,0) 1(360,0) 1(0,20) 1(40,20) 1(80,20) 1(120,20) 1(160,20) 
1(200,20) 1(240,20) 1(280,20) 1(320,20) 1(360,20) 1(0,40) 1(40,40) 
1(80,40) 1(120,40) 1(160,40) 1(200,40) 1(240,40) 1(280,40) 1(320,40) 
1(360,40) 1(0,60) 1(40,60) 1(80,60) 1(120,60) 1(160,60) 1(200,60) 
1(240,60) 1(280,60) 1(320,60) 1(360,60) @ //brick data [format: numhits(x,y)]
000@ /*cheat data (1 = true, 0 = false; the three zeroes correspond to
the following cheats respectively: no death, slowball, and speedball)*/
```

# Explanation #

If you copied the example save file into a text file named "gamesave.txt", removed the comments, and placed the file into the same directory as the game's executable, you would be able to load it and play it. It would start you at level 1 on medium difficulty. Your player's name would be "Nicolas Marsceau," you would still have all 5 of your original lives, and you would have no cheats active.