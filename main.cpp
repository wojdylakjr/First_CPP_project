/* The game provides a Kalah board and a number of stones. The board has 6 small holes on each side; and a big hole, called mancala at each end. The object of the game is to capture more stones  in mancala than one's opponent.

1. At the beginning of the game, four stones are placed in each hole.
2. Each player controls the six holes and their stones on the player's side of the board. The player's score is the number of stoness in the mancala to their right.
3. Players take turns sowing their stones. On a turn, the player removes all stones from one of the holes under their control. Moving counter-clockwise, the player drops one stone in each hole in turn, including the player's own mancala but not their opponent's.
4. If the last stone lands in an empty hole owned by the player, and the opposite hole contains stones, both the last stone and the opposite stones are captured and placed into the player's mancala.
5. If the last stone lands in the player's mancala, the player gets an additional move. There is no limit on the number of moves a player can make in their turn.
6. When one player no longer has any stones in any of their holes, the game ends. The other player moves all remaining stones to their mancala, and the player with the most stoness in their mancala wins.
It is possible for the game to end in a draw.*/

#include"Game.h"

int main() {
  Game::startGame();
} 
