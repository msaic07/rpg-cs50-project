# Goblin fight rpg

## Video demo: 

## The Game

This was a text-based game, made in C++, that I had created as my CS50x project. It is an rpg turn-based text game where you, the player, and the enemy, a giant goblin, fight.

You first start out by typing in a name that your player will use. After that, a line will appear saying that the village is being attacked by a giant goblin, which you will go and fight. The fight starts and a couple of different things are displayed. The first thing displayed is your health which is 40. The next is the giant goblin's health which is 30. Next is the potions you have that can be used to heal you. The next couple of lines shows the commands that you can do. The first command is attack, the second is heal, and the last is a mega potion. 

### The attack command:
This command allows you to attack the giant goblin for any number between 0 and 6. This number is randomized and determines how much damage the giant goblin takes. 0 is a missed attacked, 1 is a weak attack, 2 - 5 are normal attacks, and 6 is a critical hit.

### The heal command:
This command allows you to be healed up by 3 hp. Not only will you gain health, but you will be invincible for the next attack that the goblin does. Every time you use this command, a health potion  will be up. You only start out with only 2 health potions so you have to use them wisely. 

### The mega potion command:
This command allows you to be healed up by 10 hp. You only have one of these potions so you should only use it when you really need to.

## The Code

### main.cpp
This is the main file. It creates the player and enemy, names your player, and starts the game. It also makes sure that the attacks are really randomized by executing this line - srand(static_cast<unsigned>(time(NULL)));
  
### Player.h
This is the header file for Player.cpp. It creates the private variables name, health, max_health, potions, damage, isPlayersTurn, and game_over. It also creates the constructors, destructors, and the public functions which are: get_name, set_name, get_health, set_health, attack, heal, commands, and take_damage.
  
### Player.cpp
This is where all of code is for the player functions. The constructor sets health to max_health, isPlayersTurn to true, and game_over to false. The attack function takes health from the enemy, The heal functions gives health points to the player. the commands function allows the player to choose what they want to do and is essentially the game loop. The take_damage function allows the player to be attacked taking off health points from any number between 1 and 5, inclusive. The operator<< function allows a class to be displayed in a certain way which can be used for easy debugging.

### Enemy.h
This is the header file for Enemy.cpp It creates the private variables name, health, and used potion. It also ccreates the constructors, destructor, and the public functions which are: get_name, set_name, get_health, set_health, attack, heal, and take_damage. It also has a static variable called damage so it can be called in any file.
  
### Enemy.cpp
This is where all of the code is for the enemy functions. First, it sets the static variable, damage, to 0. The attack function takes health from the enemy, the heal function gives the enemy 15 health points. The take_damage function allows the enemy to be attacked taking off health points from any number between 0 - 6, inclusive. The operator<< function allows a class to be displayed in a certain way which can be used for easy debugging.
