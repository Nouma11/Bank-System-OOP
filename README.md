Bank System - Object-Oriented Programming (OOP)
This is a Bank System project implemented in C++ using Object-Oriented Programming (OOP) principles. The system allows users to manage clients, perform transactions, and handle user authentication with encrypted passwords stored in files. The project is designed to demonstrate clean code practices, modularity, and secure data handling.

Features
User Authentication:

Secure login system with encrypted passwords stored in files.

Password encryption using a simple Caesar cipher (shift of 13).

Login attempts tracking with a maximum of 3 attempts before locking the user.

Client Management:

Add, delete, update, and find clients.

Store client information such as name, email, phone, account number, PIN code, and account balance.

Transactions:

Deposit and withdraw funds from client accounts.

Transfer funds between accounts.

Log all transactions with timestamps and user details.

User Management:

Add, delete, and update users.

Assign permissions to users (e.g., manage clients, perform transactions, etc.).

Login Register:

Track all login attempts and successful logins.

Store login details such as username, password, and permissions.

File-Based Data Storage:

All data (clients, users, transactions, and login records) is stored in text files.

Encrypted passwords ensure data security.

Modular Design:

The system is divided into multiple classes, each handling a specific functionality (e.g., clsUser, clsBankClient, clsLoginScreen, etc.).

Easy to extend and maintain.

Encryption Details
Password Encryption:

Passwords are encrypted using a Caesar cipher with a shift of 13.

Example:

Original: password

Encrypted: cnffjbeq

File Storage:

Encrypted passwords are stored in Users.txt.

Example entry:

Copy
John#//#Doe#//#john@example.com#//#123456789#//#admin#//#cnffjbeq#//#-1
Permissions
Users can have the following permissions:

eAll: Full access.

pListClients: View client list.

pAddNewClient: Add new clients.

pDeleteClient: Delete clients.

pUpdateClients: Update client information.

pFindClient: Find clients.

pTranactions: Perform transactions.

pManageUsers: Manage users.

pLoginRegister: View login register.

Screenshots
Login Screen:

Copy
Enter Username? admin
Enter Password? password
Login successful!
Main Menu:

Copy
===========================================
            Main Menu
===========================================
[1] Show Client List.
[2] Add New Client.
[3] Delete Client.
[4] Update Client Info.
[5] Find Client.
[6] Transactions.
[7] Manage Users.
[8] Login Register.
[9] Logout.
===========================================
Client List:

Copy
===========================================
            Client List
===========================================
Account Number: 123456
Name: John Doe
Email: john@example.com
Phone: 123456789
Balance: 1000.00
===========================================
Future Improvements
Enhanced Encryption:

Implement stronger encryption algorithms (e.g., AES).

Database Integration:

Replace file-based storage with a database (e.g., SQLite, MySQL).

Graphical User Interface (GUI):

Develop a GUI using frameworks like Qt or wxWidgets.

Multi-User Support:

Allow multiple users to access the system simultaneously.

Audit Logs:

Add detailed audit logs for all actions performed in the system.

File Structure
Users.txt: Stores user information (username, encrypted password, permissions).

Clients.txt: Stores client information (name, email, phone, account number, PIN code, balance).

LoginRegister.txt: Logs all login attempts and successful logins.

TransfereRegister.txt: Logs all fund transfer transactions.
