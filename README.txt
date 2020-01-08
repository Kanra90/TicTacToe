This is a simple tictactoe program utilizing a 3x3 tictactoe board. 

To run: 
	./TicTacToe.exe

To recompile:
	g++ TicTacToe.cpp board.cpp game_AI.cpp -g -o TicTacToe.exe

Questions:

Who are you?

	I am Lauren. I code a lot. I draw a lot. I collect comics and play video games. I drink a lot of coffee. 

Why use minimax?
	
	search space is small enough that a recursive function is an appropriate solution. Time complexity is a^x and space complexity is ax (a=num moves). Another heuristic would have been to simply keep a table of the 'best' move for each board and store it in a hash function. And although I would love nothing more than to sit and score boards manually all day, I did not opt to spend a day on solving an hour's worth of problem. My first thought when I thought about the tictactoe ai solution was a red black tree or alpha beta pruning. And while the idea is cute, I decided it was also overkill, let's not use a katana as a letter opener. 

Any issues?

	The only real 'issue' I had was setting up my vscode for c++ debugging w/ WSL. After a couple hours of screaming into the void, this was solved. For a while I struggled with an idea to pass object references to the functions inside game_AI, instead of just passing in char arrays, I chose to pass in char[][] for utility sake. what if we needed to apply this algorithm to a not board.cpp object? Unlikely to be reused, but it's also 'safer'.

Why is the board and game_AI seperated?

	I chose to make them seperate objects with different functions in order to seperate them by behavior. The ai should only have access to information it needs to have. The board should only have the functions that relate to it's object utility as a 'board.'

Is there any error handling?

	No. I chose to spend my time fine tuning behavior and coming up with an easy input system for the user, but if I were to spend more time, I would finish handling user input more effectively. As is, please only enter legal digits within the table.


References used:

https://github.com/bcko/tictactoe-react/tree/master/node_modules/functional-red-black-tree
https://github.com/GeorgeSeif/Tic-Tac-Toe-AI
https://github.com/Kanra90/Computer-Networks/tree/master/Project5 **This is a previous TicTacToe 2 player game I made for my networks class, it won't work, the client port is no longer functional, but I did refer to some of the structure
https://github.com/Kanra90/Chess-AI/tree/master/src **this is a previous chess_AI game me and a friend worked on, just as a note that I do understand Alpha Beta pruning.
https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-4-alpha-beta-pruning/
