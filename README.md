
## How to run the game?
Go to the directory  and run the following commands

    cd build
    cmake ..
    make
    ./zelda

# Game controls:
The player is controlled by the arrow keys:

     left key       => Rotate left,
     right key      => Rotate right
     up key         => Move Forward

     space key      => jump
         F          => Fire a fireballs through the cannon

     "1 key"        => Default view
     "2 key"        => Camera in Boat
     "3 key"        => Top view 2
     "4 key"        => Tower view
     "5 key"        => Helicopter view



Score and Lives left are displayed on the title.

### Health
There are certain gifts on the sea which when collected will increase the health of the boat.
* Initially, you are given with health of 50. If you collide with an enemy boat or rocks, you loose health. When the health reaches 0, the GAME IS OVER.

### Collision
On collision with rocks and enemy boats, the health of the boat is decreased.

### Gifts
There are barrels floating on the sea with gifts on them which when jumped over would increase the score of the boat.

### Boosters
There are some boosters floating on the sea which when collected would give boost to the boat for a couple of seconds.

### Fireball
Fireballs can be used to kill the monsters. They are realeased through cannons which is in front of the boat.

### Killing monsters
On Killing the monsters through Cannons, the score of the boat is increased and also the monsters leaves a booster when it dies which can be collected to boost the speed of the boat.

### Boss Monster
On Killing 4 Monsters, a Boss Monster would appear in the sea. To kill the boss monster, the boat should fire atleast 3 fireballs to kill the Boss Monster. When it dies, it leaves a booster and the score of the boat is increased.
