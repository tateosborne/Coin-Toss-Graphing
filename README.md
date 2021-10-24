# Module 3, Open-Ended Project: Multiple Programming Languages

This open-ended project uses two languages: C++ and Python.

There are only two files in the project: `main.cpp` and `graph.py`.

The project will simulate a simple betting game. The user will choose how much they would like
to bet. The program will simulate coin tosses. It will ask the user how many coin tosses they would
like to risk. Each correct guess, the user will have their current amount of money doubled. Each
incorrect guess, the user will have their current amount of money halved.

The `main.cpp` file handles the bulk of the project's contents. The program takes in user input for the
amount of money and how many coin flips they would like to simulate. The amount of money will be stored
in a vector, where each element reflects the updated amount (based on whether they were correct on guessing
heads or tails). Once the flip guesses have completed, C++ will call to CLI, where it runs `graph.py`.
Python has a great library for graphing data, so we will take advantage of that. It will graph the money
and how it changed during the coin flips.