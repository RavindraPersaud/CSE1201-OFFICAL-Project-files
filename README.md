#  User Manual  
**Message Storage Application**  
**Course:** CSE1201 — Introduction to Programming  


---

## Table of Contents
1. [Introduction](#introduction)  
2. [Tutorial](#tutorial)  
3. [Main Menu Options](#main-menu-options)  
4. [Functional Overview](#functional-overview)  
   - [Storing a Message](#storing-a-message)  
   - [Viewing Messages](#viewing-messages)  
   - [Searching Messages](#searching-messages)  
   - [Modifying Messages](#modifying-messages)  
   - [Deleting Messages](#deleting-messages)  
   - [Redacting Words](#redacting-words)  
   - [Encrypting/Decrypting Messages](#encryptingdecrypting-messages)  
5. [Password Protection](#password-protection)  
6. [Troubleshooting](#troubleshooting)  
7. [Credits](#credits)  
8. [Group Members](#group-members)

---

## Introduction
This C application which allows users to manage notes or messages. It includes features for storing, viewing, searching, modify, deleting, redacting, and encrypting/decrypting messages.

---

## Tutorial

### Compilation 
Steps:

1.Compile the program using GCC:

```bash
gcc main.c menu.c load.c message_modifyers.c search.c store_message.c delete_message.c modify_message.c -o NotPad--
```

### Execution  
2.Run the program:

```bash
./NotPad--
```

---

##  Main Menu Options

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

###  Storing a Message
Prompts user to enter:
- A title
- Message 
- Whether or not to encrypt the message using a key

Encrypted messages are protected and may only be accessed using the right key.

---

###  Viewing Messages
Displays all stored messages from `records.dat`:
- Shows message ID, title, and content (if not encrypted)

---

###  Searching Messages
Enables you to search by various method from the Search Menu:
- `1. Title` – Exact match (case-sensitive)
- `2. ID` – Unique identifier
- `3. Phrase` – Substring within the message body

Results found are printed to the screen.

---

###  Modifying Messages
- Enter the id of the message to edit.
- Encrypted messages needs password to access.
- Once decrypted, the user may input new content which overwrites the previous data.

---

### Deleting Messages
Users can delete messages by:
- Message ID
- Title

Deletion involves copying all other records to a temp file, then replacing the original file.

---

### Redacting Words
Replaces all instances of a particular word in a message with asterisks (e.g., `stupid` → `******`).

---

### Encrypting/Decrypting Messages
Uses a **Columnar Transposition algorithm**:
- Substitutes spaces with `-` before to encryption.
- Reads encrypted message in a columnar manner according to the key
- Decryption restores original message using the key

---

## Password Protection
To prevent unauthorized access:
- A hardcoded password (`your_password_here`) is required to decrypt or modify encrypted messages.

---

## Troubleshooting

| Issue                            | Solution                                           |
|----------------------------------|----------------------------------------------------|
| Program won't start              | Ensure all file are properly complied              |
| Messages not saving              | Ensure `records.dat` is writable and exists        |
| Wrong password error             | Check password for typos                           |
| Search not returning results     | Ensure you entered correct phrase/title/ID         |

---

## Credits

This project was developed by **Group 2** for **CSE1201 – Introduction to Programming**.

### Group Members

| Full Name                | University Student ID (USI) |
|-------------------------|-----------------------------|
| Gayendra Gavin Baijnath | 1052667                     |
| Kiran Doobay            | 1053135                     |
| Irshad Mohamed          | 1052668                     |
| Dinar Mohabir           | 1052382                     |
| Ravindra Persaud        | 1052507                     |
| Serina Rebecca Garrett  | 1037042                     |
| Kyahri Whyte            | 1053151                     |


We worked together to ensure each function of the message system—from storage to encryption—was implemented according to the CSE1201 project Specifications.
