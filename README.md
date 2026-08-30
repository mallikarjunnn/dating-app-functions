# Dating App - Core Functionalities (in C)

This repository provides core feature implementations for a command-line based dating application using the C programming language. Each module demonstrates a specific app functionality in a modular and educational wayy.

## Files and Features

- `sending_virtual_gifts.c` – Send and receive virtual gifts between users.
- `SOS_calling_or_messaging.c` – Trigger SOS calls or messages to emergency contacts.
- `user_feedback.c` – Collect and view user feedback using a stack-based approach.
- `user_rating.c` – Rate users and sort them by rating using heap sort.

## How to Compile and Run

Use GCC or any standard C compiler:

```bash

# Compile and run sending_virtual_gifts
gcc sending_virtual_gifts.c -o gifts
./gifts

# Compile and run SOS_calling_or_messaging
gcc SOS_calling_or_messaging.c -o sos
./sos

# Compile and run user_feedback
gcc user_feedback.c -o feedback
./feedback

# Compile and run user_rating
gcc user_rating.c -o rating
./rating

