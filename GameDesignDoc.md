
>Copyright (C) 2013  Clayton Brand
>
>This program is free software: you can redistribute it and/or modify
>it under the terms of the GNU General Public License as published by
>the Free Software Foundation, either version 3 of the License, or
>(at your option) any later version.
>
>This program is distributed in the hope that it will be useful,
>but WITHOUT ANY WARRANTY; without even the implied warranty of
>MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>GNU General Public License for more details.
>
>You should have received a copy of the GNU General Public License
>along with this program.  If not, see <http://www.gnu.org/licenses/>.


# SpaceCraft Odyssey Design Document
SpaceCraft Odyssey: '99 Prime Edition is a top-down spaceship shooter game.  The player controls a ship which begins at the bottom of the screen.  Enemies spawn from the top of the screen, which will attempt to attack the player.  The player has the ability to shoot back, and can pick up items to regain health.  The game is set against a moving backdrop to give the illusion that the player and enemies are flying.

----

### Main Menu
When the executable is run, the player will be met with the main window.  They will enter their name, choose their gamemode ("normal" or "invincible"), and have the choices: Start / Pause, Quit.  During the game, if they pause by pressing the Start / Pause button, the gameplay will freeze until the click it again.

The player must enter a name and choose a gamemode before the game will begin.

### Graphical User Interface
Once the game has been started, the user's health will appear in the bottom of the screen along with their name and their current points (which will start at 0).  The user will have five health, which will be indicated by five green bars.  Points will be released when enemies are defeated.

----

### Grading / Extra Credit: Seven Things
The seven things to be graded are the enemy projectiles, the bosses, the point items, the close-range enemies, the moving background, the health items, and the "health" (icons displayed on the screen - these are the only unmoving things).

High scores are viewable when the player dies - they are not viewable in Invincible Mode, since the player cannot die.  They are written to the file "scores.txt".  

Three levels are designated by changes in enemy sprites, enemy movements, game speed, and bosses.

AI is present in two things: The points items, which are spawned when enemies are defeated, and move to the player (upon which the player's point total goes up), and the close-range enemies (which move towards the player based on the current level and the player's position).

### Player
The player's ship will begin in the bottom center of the window, and the player will control it's movements.  The player will not be able to move off the screen in any direction.  The player will likely spend most of the game near the bottom of the screen.

The player will move using 'wasd' controls, and fire by holding the spacebar.  The player's weapon will fire projectiles forward.

### Enemies
There will be two "normal" enemy types - long-range close-range.  The long-range enemies will group near the middle or top of the screen, and shoot projectiles downward at the player.  The close-range enemies will move quicker, and deal damage upon contacting the player.  The close-range enemies do not fire projectiles.

There will be three "boss" enemies, which are based on the same class but with different attributes.  The bosses will have the long-range fighter's normal projectile attack as well as one special attack that shoots out multiple large projectiles which move slowly in multiple directions, which the player must avoid.  Boss 2 has a second attack in addition to the standard one, which is similar but shoots multiple projectiles downward with the same yvelocity.  Boss 2 only moves horizontally.  Boss 3 moves very quickly, and fires the special attack with a higher frequency.

### Projectiles and Damage
The player's bullets and the normal long-range enemies projectiles will be based on the same class, but the player's bullets will move faster.  The boss's special attack will be multiple simple objects that move at varying initial velocities.  Each type of projectile will deal a different amount of damage.  When an enemy's health drops below 0, they will dissappear.  When the player's health drops below 0, they will dissappear and the game will end.

### Health
The player starts with five health, and when damage is dealt (by colliding with an enemy projectile or an enemy) the player loses one.  Their health is displayed by visual objects on the screen, and also kept track of inside the player object.

Health items will spawn periodically, and move downwards toward the player.  If the player picks them up they will regain one health (only up to the maximum five.

In the invincible gamemode, whenever the player's health reaches 0, it is reset to 5, so that they cannot die.

### Points
When enemies are defeated, points are created.  Points move from their initial position toward the player.  When the player touches them, they disappear and the the player's point total (in the corner of the screen) increases at a rate of 5 per point item.  Harder enemies release more point items.

----

### Levels and Sprites
There will be three levels.  The first level will have the player encountering "scout" (long-range) and "corsair" (close-range) enemies, with Boss 1 being a "carrier".  The second level will have the player encountering "wraith" (long-range) "valkyrie" (close-range) enemies, with Boss 2 being a "battlecruiser".  The final level will have the player encountering all types of previous enemies, and Boss 3 will be an "arbiter".  All images are sourced from Blizzard's Starcraft or simple sprites created by me.

Enemy images used (mouse-over for name):
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_scout.gif?raw=true "Long-Range 1: Scout")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_corsair.gif?raw=true "Close-Range 1: Corsair")
![alt text](https://raw.github.com/usc-csci102-spring2013/game_cbrand/master/sprites/terran_valkyrie.gif?login=clay-to-n&token=8a7e798723d61f2b6e77e61a6f674b28 "Close-Range 2: Valkyrie")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/terran_wraith.gif?raw=true "Long-Range 2: Wraith")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_carrier.gif?raw=true "Boss 1: Carrier")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/terran_bc.gif?raw=true "Boss 2: Battlecruiser")
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_arbiter.gif?raw=true "Boss 3: Arbiter")

Player image:
![alt text](https://github.com/usc-csci102-spring2013/game_cbrand/blob/master/sprites/toss_arbiter.png?raw=true "Player: Dark Colored Arbiter")

The player at all times will be represented by an "arbiter" with blue / purple accents.  All of the enemy types will have red accent color.

The backdrops will be provided as two tall vertical image file.  The "background" will scroll as the player "flies", but fairly slowly compared to the movement speed of the player and the enemies.  The "clouds" will scroll above it, faster, to give the illusion that they are closer.

### Timing
One clock object will control the animations of all sprites in the game.  Each enemy type will have a specific movement speed, and each projectile type will as well.  The "items" will also move down the screen towards the player, and the background will move as well.  The clock will speed up when bosses are defeated, so it gets progressively more difficult.  If the player beats the third boss, they will return to the beginning of the game, but the clock speed will not return to its original speed.  Beating the game two times in a row will be exceptionally difficult due to the increased game speed.

In addition to movement, the clock handles all collisions and enemy spawning.