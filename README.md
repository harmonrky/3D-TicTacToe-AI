# 3D-TicTacToe
Collaborative 3D TicTacToe Game

This was a project created by me and a friend that uses two different AI systems to play out 3D TicTacToe. Games are repeated 1000 times in order to find which AI is better. My friend's AI ended up beating mine pretty consistantly. Even so, I thought my implementation was creative even if it wasn't the best or more efficient.

My algorithm randomly finds a point in the playing field to start off. This point acts as a seed for which other moves are to be based off. The algorithm then finds acceptable moves around the seed that will lead to a completed line. The AI will check if a line is already partly filled by an opponent and will decide if another move in a free space is better. Despite this, the AI is a bit oblivous since it doesn't monitor the moves of the opponent and instead focuses on its own moves. Furthermore, my friend and I created different systems to run the game so we had to stitch them together in the end. This makes it a bit clunky but the logic behind the AI's is sound. 
