## Tic-Tac-Toe ##
Exactly as it sounds, this is a tic-tac-toe game that was designed using OOP concepts in C alone (wow!).

#### Goal of Project ####
I had a couple of goals while building this project. Some smaller ones included refreshing my Makefile skills, practicing the use of header file for C (and the compilation of said files without a main function), and experimenting with the different ways to format and allocate memory representing a 2d array using pointers and malloc/free.

My more major goal for this project however was to experiment with OOP style in C, a none OOP based language. It's kind of counter intuitive but I saw a cool video [here](https://www.youtube.com/watch?v=73itd0pkna4&t=622s) where C was used to create an OOP styled program with unique syntax and challenges that I felt would make me a better developer at the end of the day. I hope anyone who checks out the project considers doing the same as it was a very educational challenge in the end.

#### Build Instructions ####
To build this project you can run ***make game*** or ***make rebuild***. Make game will compile the project and dependencies while make all will first clean the old project files before building them again. That's It!

#### How-To-Play ####
Kinda sad you don't know how to play tic-tac-toe but that's okay, here's a brief run down of the game. Once you run the main game program after building it (run ***./build***) you will be presented with the game setup which asks you to pick a character for both players one and two. This character will represent your "avatar" in a sense so remember it. 

Following this you will be presented with an empty 3 x 3 grid and a prompt to enter an x and y value. these values represnt the positions on the grid ranging from 1 to 3 with the top left being [1, 1] and the bottom right being [3, 3]. Your goal is to place your character in such a manner that it drawns a straight line that this three characters long while also preventing the other player from doing the same. That's it, good luck!