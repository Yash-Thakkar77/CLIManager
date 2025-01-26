# CLIManager

---

This project simulates a simple command line interface's command history manager using a **doubly linked list** in C++. The program allows users to enter commands, navigate through previous commands (up and down), view the command history, and clear the history.

## Features

- **Add Command**: Enter commands and store them in the history.
- **Navigate Up (`w` or `W`)**: Navigate to the previous command in history.
- **Navigate Down (`s` or `S`)**: Navigate to the next command in history.
- **View History (`history`)**: Display all stored commands.
- **Clear History (`history -c`)**: Remove all stored commands from history.

## How to Use

1. Run the program.
2. Enter commands.
3. Use `w` to navigate up through the command history, and `s` to navigate down.
4. Type `history` to view all commands in history.
5. Use `history -c` to clear the command history.

## Example Commands

- `w` → Move to the previous command.
- `s` → Move to the next command.
- `history` → Print all commands.
- `history -c` → Clear the command history.
