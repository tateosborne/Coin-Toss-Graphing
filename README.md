# Module 3, Open-Ended Project: Multiple Programming Languages
#### _Author: Tate Osborne_

### Overview
#### Necessary installations for Python ~
- `install sys`: This is for Python to interact/gather arguments from CLI
- `pip3 install matplotlib`: This is for Python to create the graph.

This open-ended project uses two languages: C++ and Python.

There are only two files in the project: `main.cpp` and `graph.py`.

The project will simulate a simple betting game. The user will choose how much they would like
to bet and how many coin tosses they would like to simulate.

Then, the game will begin. It will tell the user with how much money they currently have in the game.

After each correct guess, the user will have their current amount of money doubled. After each
incorrect guess, the user will have their current amount of money halved.

It will prompt whether they would like to guess heads or tails, and the user will enter their guess.
The correct answer will be outputted to the console, and the program gives feedback explaining if they got it
right or wrong. The console will also show the toss number they are on, and it will show the updated amount of money.
After the tosses are simulated, the console prints out a summary to the user, saying the amount of money the user won or lost.
The amount of money, at each toss, is sent to Python via CLI, and Python creates a graph that summarizes the user's game.

### Files:
`main.cpp` handles the bulk of the project's contents and the game logic. The amount of money will be stored
in a vector, where each element reflects the updated amount (based on whether they were correct on guessing
heads or tails). 

Once all tosses are completed, C++ will call to CLI, where it runs `graph.py`. It passes in multiple arguments to the CLI,
where the first argument is 'graph.py'. The next argument is the initial amount of money the user put on the table. After that,
there the amounts of money after each toss. The last command line argument is the number of tosses the user simulated.

Python has a great library for graphing data, so we will take advantage of that.
Python takes in the command line arguments, and translates them into two lists, and then creates a graph. The graph is
a line graph displaying how the user's money changed (went up/down) during the betting game. The x-axis is the toss number,
and the y-axis is the money, measured in dollars.

### Example 
Suppose the user decided to bet $10 on 4 tosses.
If the user guessed `H, T, T, T` and the actual tosses were `H, H, T, T` then transition function would be as follows:
```
toss number:           0      1      2      3      4
money transition:    $10 -> $20 -> $10 -> $20 -> $40
```
The command called by C++ in command line to call the Python file, with the appropriate arguments, would be:
```
python3 graph.py 10 20 10 20 40 4
```
