# Filler
[![My Skills](https://skills.thijs.gg/icons?i=c&theme=light)](https://skills.thijs.gg)
## Table of contents
- [Filler](#filler)
  - [Table of contents](#table-of-contents)
  - [About](#about)
  - [How it works](#how-it-works)
  - [Usage](#usage)
  - [Subject](#subject)

## About
42 School project that has us coding an algorithmic game in C.

## How it works
The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program).

The game ends when the game piece cannot be placed anymore.

## Usage
> \> make && cd res

__**Launch program:**__
> \> ./filler_vm -f path/map [-i | -p1 path/player1 | -p2 path/player2] [-s | -q | -t time]
```
-f --fileuse a map file (required)
-i --interactiveinteractive mode(default)
-p1 --player1use filler binary as a first player
-p2 --player2use filler binary as a second player
-s --seeduse the seed number (initialization random)(man srand)
-q --quietquiet mode
-t --timeset timeout in second
```
__**Example:**__
> \> ./filler_vm -f maps/map01 -p1 ../gavizet.filler -p2 players/superjeannot.filler

You will find pre-made maps and players in the "res" directory. My champion, situated at the root of the project, is named "gavizet.filler". You have to be in the "res" directory in order to launch the game.

## Subject
For more details, you can download the project (in French) from [here](https://raw.githubusercontent.com/gavizet/filler/master/filler.fr.pdf).
You can also view it directly in the root of this project.
