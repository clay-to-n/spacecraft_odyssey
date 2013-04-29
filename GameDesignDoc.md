# SpaceCraft Odyssey Design Document
SpaceCraft Odyssey: '99 Prime Edition is a top-down spaceship shooter game.  The player controls a ship which begins at the bottom of the screen.  Enemies spawn from the top of the screen, which will attempt to attack the player.  The player has the ability to shoot back, and can pick up items to regain health.  The game is set against a moving backdrop to give the illusion that the player and enemies are flying.

----

### Main Menu
When the executable is run, the player will be met with the main window.  They will enter their name, choose their gamemode ("normal" or "invincible"), and have the choices: Start Game, Quit.  During the game, if they pause by pressing the Pause button, the gameplay will freeze.

The player must enter a name and choose a gamemode before the game will begin.

### Graphical User Interface
Once the game has been started, the user's health will appear in the bottom of the screen along with their name and their current points (which will start at 0).  The user will have five health, which will be indicated by five green bars.  Points will be awarded when enemies are defeated.

----

### Grading Five Things
The five things to be graded are the projectiles, the bosses, the long-range enemies, the close-range enemies, and the health items.  The three enemy types all move in sufficiently different manners, and do differing things (the boss has a special attack, the close range enemy moves quickly throughout the scene, etc).

### Player
The player's ship will begin in the bottom center of the window, and the player will control it's movements.  The player will not be able to move off the screen in any direction.  The player will likely spend most of the game near the bottom of the screen.

The player will move using 'wasd' controls, and fire by pressing the spacebar.  The player's default weapon will fire "bullets" forward.

### Enemies
There will be two "normal" enemy types - long-range fighters and close-range slicers.  The long-range fighters will group near the middle or top of the screen, and shoot projectiles downward at the player.  The close-range slicers will move quicker, and deal damage upon contacting the player.

There will be three "boss" enemies, which are based on the same class but with different attributes.  The bosses will have the long-range fighter's normal projectile attack as well as one special attack that shoots out multiple large projectiles which move slowly in multiple directions, which the player must avoid.  Boss 2 has a second attack in addition to the standard one, which is similar but shoots multiple projectiles downward with the same yvelocity.  Boss 2 only moves horizontally.  Boss 3 moves very quickly, and fires the special attack with a higher frequency.

### Projectiles and Damage
The player's bullets and the normal long-range enemies projectiles will be based on the same class, but the player's bullets will move faster.  The boss's special attack will be multiple simple objects that move at varying initial velocities.  Each type of projectile will deal a different amount of damage.  When an enemy's health drops below 0, they will dissappear.  When the player's health drops below 0, they will dissappear and the game will end.

### Health
The player starts with five health, and when damage is dealt (by colliding with an enemy projectile or an enemy) the player loses one.  Their health is displayed by visual objects on the screen, and also kept track of inside the player object.

Health items will spawn periodically, and move downwards toward the player.  If the player picks them up they will regain one health (only up to the maximum five.

In the invincible gamemode, whenever the player's health reaches 0, it is reset to 5, so that they cannot die.

----

### Levels and Sprites
There will be three levels.  The first level, set against a backdrop of clouds and nature, will have the player encountering "scout" (long-range) and "corsair" (close-range) enemies, with the boss being a "carrier".  The second level, against a city / industrial backdrop, will have the player encountering "valkyrie" (long-range) "wraith" (close-range) enemies, with the boss being a "battlecruiser".  The final level, set against a space backdrop, will have the player encountering all types of previous enemies, and the boss will be an "arbiter".  All images (so far) are sourced from Blizzard's Starcraft or simple sprites created by me.

Enemy images used (mouse-over for name):
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_scout.gif?raw=true "Long-Range 1: Scout")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_corsair.gif?raw=true "Close-Range 1: Corsair")
![alt text](https://raw.github.com/usc-csci102-spring2013/game_cbrand/master/sprites/terran_valkyrie.gif?login=clay-to-n&token=8a7e798723d61f2b6e77e61a6f674b28 "Long-Range 2: Valkyrie")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/terran_wraith.gif?raw=true "Close-Range 2: Wraith")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_carrier.gif?raw=true "Boss 1: Carrier")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/terran_bc.gif?raw=true "Boss 2: Battlecruiser")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_arbiter.gif?raw=true "Player: Arbiter")


The player at all times will be represented by an "arbiter".  All of the enemy types will have red accent color.

The backdrops will be provided as two tall vertical image file.  The "background" will scroll as the player "flies", but fairly slowly compared to the movement speed of the player and the enemies.  The "clouds" will scroll faster, to give the illusion that they are closer.

### Timing
One clock object will control the animations of all sprites in the game.  Each enemy type will have a specific movement speed, and each projectile type will as well.  The "items" will also move down the screen towards the player, and the background will move as well.  The clock will speed up when bosses are defeated, so it gets progressively more difficult.  If the player beats the third boss, they will return to the beginning of the game, but the clock speed will not return to its original speed.  Beating the game two times in a row will be exceptionally difficult due to the increased game speed.