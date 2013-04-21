# SpaceCraft Odyssey Design Document
SpaceCraft Odyssey: '99 Prime Edition is a top-down spaceship shooter game.  The player controls a ship which begins at the bottom of the screen.  Enemies spawn from the top of the screen, which will attempt to attack the player.  The player has the ability to shoot back, and can pick up items to make him more power and grant new abilities.  The game is set against a moving backdrop to give the illusion that the player and enemies are flying.

----

## Main Menu
When the executable is run, the player will be met with the main window.  They will have the choices: Start Game, Quit.  During the game, if they pause by pressing the 'Esc' key, they will enter the menu and have the options Restart, Quit, and Resume.

When Start Game is chosen, they will be prompted to enter their name.

## Graphical User Interface
Once the game has been started, the user's name will appear in the corner along with their current points (which will start at 0).  Points will be awarded in a steady stream over time, and more will be awarded when enemies are defeated.

Lives will be displayed as well - the user will have three lives, which will be indicated by two ship icons which resemble the player's ship (such that when they're on their last life, there are no ship icons remaining).

----

## Player
The player's ship will begin in the bottom center of the window, and the player will control it's movements.  The player will not be able to move off the screen in any direction.  The player will likely spend most of the game near the bottom of the screen.

The player will move using 'wasd' controls, and fire by pressing the spacebar.  The player's default weapon will fire "bullets", a simple projectile class that moves forward very quickly and deals damage upon contacting enemies.

## Enemies
There will be two "normal" enemy types - long-range fighters and close-range slicers.  The long-range fighters will aim to group near the middle or top of the screen, and shoot projectiles at the player.  The close-range slicers will move quicker, and aim to get very close to the player to deal contact damage.

There will be three "boss" enemies, which will probably be based on the same class but with different attributes.  The bosses will have the long-range fighter's normal projectile attack as well as one special attack that shoots out multiple large projectiles which move slowly in multiple directions, which the player must avoid.

## Projectiles and Damage
The player's bullets and the normal long-range enemies projectiles will be based on the same class, but the player's bullets will move faster.  The boss's special attack will be multiple simple objects that move at varying initial velocities.  Each type of projectile will deal a different amount of damage.  When an enemy's health drops below 0, an animation will play and they will dissappear.  When the player's health drops below 0, they will dissappear, a "life" will be removed, and they will respawn in the center bottom of the screen.

## Items
There will be two types of items in the game.  The first is a shield which will prevent the player from damage from the next source of damage to hit it, and will also deal damage to enemies on contact.  The second is a bomb, which will explode when the player touches it and deal damage to enemies in an area around the player.

----

## Levels and Sprites
There will be three levels.  The first level, set against a backdrop of clouds and nature, will have the player encountering "scout" (long-range) and "corsair" (close-range) enemies, with the boss being a "carrier".  The second level, against a city / industrial backdrop, will have the player encountering "valkyrie" (long-range) "wraith" (close-range) enemies, with the boss being a "battlecruiser".  The final level, set against a space backdrop, will have the player encountering all types of previous enemies, and the boss will be an "arbiter".  

![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_scout.gif "Long-Range 1: Scout")

![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_corsair.gif "Close-Range 1: Corsair")

![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/terran_valkyrie.gif "Long-Range 2: Valkyrie")

![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/terrain_wraith.gif "Close-Range 2: Wraith")

![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_carrier.gif "Boss 1: Carrier")

![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/terran_bc.gif "Boss 2: Battlecruiser")

![alt text](http://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_arbiter.gif "Boss 3: Arbiter")




The player at all times will be represented by a blue "arbiter".  All of the enemy types will have red accent color.

The backdrops of all three levels will be provided as one tall vertical image file.  It will scroll as the player "flies", but fairly slowly compared to the movement speed of the player and the enemies.  

## Timing
One clock object will control the animations of all sprites in the game.  Each enemy type will have a specific movement speed, and each projectile type will as well.  The "items" will also move down the screen towards the player, and the background will move as well.  The clock will speed up between each level, so it gets progressively more difficult.  If the player completes the third level, they will return to the beginning of the game, but the clock speed will not return to its original speed.  Beating the game two times in a row will be exceptionally difficult due to the increased game speed.