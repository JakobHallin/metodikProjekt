<h1>Stock Portfolio Management System</h1>

A desktop C++ application built with Qt for managing users, financial accounts, and stock portfolios. 
The project uses object-oriented design principles and SQL-based persistent storage, with an attempted MVVM structure to separate concerns across logic, data, and UI.

<h3>Requirements </h3>
C++17 or later
Qt 5.x or 6.x
Database for SQL (MariaDB was used)

<h3>Architecture</h3>
This project follows a Model-View-ViewModel (MVVM) structure to improve modularity and separation of responsibilities.
<h4>MVVM Breakdown</h4>
<h5>Model:</h5>
Core classes like User, Account, and Stock, and backend logic (Db, Sql) encapsulate business logic and data.
<h5>View:</h5>
*UI components created using Qt (e.g., userview.cpp, stockview.cpp, etc.), responsible for displaying data and capturing input.
<h5>ViewModel:</h5>
*Logic bridges like userviewmodel.cpp manage communication between views and models, transforming data and reacting to UI events.
<h5>Notes: MVVM was chosen as a conceptual guide, but Qt’s event-driven model and widget-based design do not align naturally with MVVM. </h5>

<h3>Database tables</h3>
User
Accounts
Stock
AllStocks
<h3>Login Window</h3>
Login interface for entering a username and accessing user-specific data 
Password is not required but is a feature that could be implemented

<p align="center"> <img src="https://github.com/user-attachments/assets/8cda8714-234c-4862-8b64-7ac6235c7c0d" alt="Login Window" width="400" height="300"/> </p>
<h3> After login</h3>
<p align="center"><img src="https://github.com/user-attachments/assets/e3d3ed95-8d8a-4456-a277-ce50021d932d" alt="After Login UI" width="500" height="300"/> </p>
Displays selected user’s account info, stock portfolio, and allows buy/sell operations.
Scrollable area for multiple stock entries.
Each stock shows its ID and current amount.

<h3>Documentation</h3>
This project is documented using Doxygen.

To generate the documentation: doxygen Doxyfile 
