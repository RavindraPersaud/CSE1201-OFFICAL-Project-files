#  User Manual  
**Message Storage Application**  
**Course:** CSE1201 — Introduction to Programming  


---

## Table of Contents
---
- [Introduction](#introduction)  
- [Tutorial](#tutorial)  
  - [Compilation](#compilation)  
  - [Execution](#execution)  
- [Main Menu Options](#main-menu-options)  
- [Storing a Message](#option-0--store-a-new-notemessage) 
- [Viewing Messages](#option-1--view-all-notes-and-messages)  
- [Searching Messages](#option-2--search-for-a-notemessage)  
- [Modifying Messages](#option-3--modify-a-previously-stored-note)  
- [Deleting Messages](#option-4--delete-a-notemessage)  
- [Exiting the Program](#option-5--exit-the-program)  
- [Password Protection](#password-protection)  
- [Troubleshooting](#troubleshooting)  
- [Credits](#credits)  
- [Group Members](#group-members)


---

## Introduction
This is a C application that allows users to manage notes or messages. It includes features for storing, viewing, searching, modify, deleting, redacting, and encrypting/decrypting messages.

---

## Tutorial

### Compilation 
Steps:

1.Compile the program using GCC:
Note: Please ensure you are in the group-2-semester-project/src directory before compiling.
```bash
gcc src/*.c -o NotPad--.exe
```

### Execution  
2.Run the program:

```bash
./NotPad--
```

---

##  Main Menu Options
When you run the program, you will be presented with a numbered menu. Follow the steps below based on your desired action:


| Option | Description                                 |
|--------|---------------------------------------------|
| 0      | Store a new note/message                    |
| 1      | View all notes and messages                 |
| 2      | Search for a note/message                   |
| 3      | Modify a previously stored note             |
| 4      | Delete a note/message                       |
| 5      | Exit the program                            |

---

##  Functional Overview

### Option 0 Store a New Note/Message
Choose Option 0 from the menu.
Enter the Title (maximum 50 characters).
Enter the Message Body (maximum 300 characters).
Choose one of the following options:
Encrypt the message (you will be prompted to enter a key).
Redact specific words (provide a comma-separated list).
Store the message as-is (unencrypted and uncensored).
The message will be saved to records.dat.

### Option 1 – View All Notes and Messages
Choose Option 1 from the menu.
All stored messages will be displayed, showing:
Message ID
Title
Content (if unencrypted)
If a message is encrypted, only the ID and Title will be shown.

### Option 2 – Search for a Note/Message
Choose Option 2 from the menu.
Select a search method:
1 – By Title (case-sensitive, exact match)
2 – By ID
3 – By Phrase (search within the message body)
Enter the appropriate search term.
Matching results will be displayed.

### Option 3 – Modify a Previously Stored Note
Choose Option 3 from the menu.
Enter the ID of the message you want to modify.
If the message is encrypted, you will be asked to enter the correct password.
Enter the new content for the message.
Choose whether to:
Re-encrypt the message,
Redact new words, or
Store it without changes.
The old content will be overwritten.

### Option 4 – Delete a Note/Message
Choose Option 4 from the menu.
Enter the ID of the message you wish to delete.
The program will ask for confirmation.
Upon confirmation, the message will be permanently removed from records.dat.

### Option 5 – Exit the Program
Choose Option 5 from the menu.
The program will close and return you to the terminal or command line.

### Password Protection
Encrypted messages are secured using a user-defined key (password).
You must enter the correct key to view or modify the encrypted message.
The application does not store passwords in plain text for security reasons.
Make sure to remember your key, as lost keys cannot be recovered.


## Troubleshooting

| Issue                            | Solution                                               |
|----------------------------------|--------------------------------------------------------|
| Program won't start              | Ensure all files are properly compiled                 |
| Messages not saving              | Make sure `NotPad--` is run from the correct directory |
| Wrong password error             | Double-check for typos in your password                |
| Search not returning results     | Ensure you entered the exact title, ID, or phrase      |

---

## Credits

This project was developed by Group 2 for CSE1201 – Introduction to Programming.

### Group Members

| Full Name               | University Student ID (USI) |
|-------------------------|-----------------------------|
| Gayendra Gavin Baijnath | 1052667                     |
| Kiran Doobay            | 1053135                     |
| Irshad Mohamed          | 1052668                     |
| Dinar Mohabir           | 1052382                     |
| Ravindra Persaud        | 1052507                     |
| Serina Rebecca Garrett  | 1037042                     |
| Kyahri Whyte            | 1053151                     |

We collaborated to ensure every function—from storing to encrypting messages—was implemented according to the CSE1201 project specifications.
