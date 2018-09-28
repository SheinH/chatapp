# Chat App

This is a ncurses based chat app that I banged out on my keyboard in an hour and a half. I made this mostly so I can chat with people while I am teamviewering them. It can only be used by two users typing on the same computer with the same keyboard and currently, it is hard coded to support two users named Shein and Victoria.

![Wow, isn't this app cool???](https://i.imgur.com/20miiKJ.png)

## Compilation

This program is manually compiled and requires some implementation of curses.h. If your computer has ncurses and uses cc to compile C code, you may compile with any c compiler using "cc Chat.c -lncurses" as an example.

## How to use:

Simply type messaages and hit enter to log them on the screen
If you want to switch users, hit tab.
To quit, enter "quit" in the message field and hit enter.
