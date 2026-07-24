# Stock Portfolio Management System

A C++17 desktop application built with Qt for managing users, financial accounts, stock holdings, and simulated buy/sell operations.

The project uses SQL-backed persistence and an MVVM-inspired structure to separate UI, application logic, and domain/data concerns.

## Highlights

* C++17 desktop application using Qt Widgets
* User, account, stock, and portfolio management
* Buy and sell operations with persisted holdings and balances
* SQL/MariaDB-backed storage through Qt SQL
* MVVM-inspired separation between models, views, and view models
* Qt signals and slots for UI updates and component communication
* Doxygen documentation

## Tech Stack

* C++17
* Qt 5 / Qt 6
* Qt Widgets
* Qt SQL
* MariaDB / MySQL
* CMake
* Doxygen

## Architecture

The project uses an MVVM-inspired structure as a guide for separating responsibilities.

### Model

Core classes such as `User`, `Account`, and `Stock` contain application state and business logic.

Database-related classes handle persistence and SQL operations.

### View

Qt widgets such as `userview`, `accountview`, and `stockview` display application state and collect user input.

### ViewModel

View-model classes sit between the UI and model layer and coordinate updates between them.

Qt's widget and signal/slot model does not map perfectly to MVVM, so the pattern is used as a practical architectural guide rather than a strict MVVM implementation.

## Database

The application uses MariaDB/MySQL through Qt's `QMYSQL` driver.

Database connection details are configured through environment variables:

```bash
export DB_HOST=localhost
export DB_NAME=metodik
export DB_USER=root
export DB_PASSWORD=your-password
export DB_PORT=3306
```

## Screenshots

### Login

<p align="center">
  <img src="https://github.com/user-attachments/assets/e3d3ed95-8d8a-4456-a277-ce50021d932d" alt="Login window" width="500" />
</p>

### Portfolio View

<p align="center">
  <img src="https://github.com/user-attachments/assets/8cda8714-234c-4862-8b64-7ac6235c7c0d" alt="Portfolio view" width="500" />
</p>

The portfolio view displays account information and stock holdings and supports simulated buy/sell operations.

## Build

Requirements:

* CMake 3.5+
* C++17-compatible compiler
* Qt 5 or Qt 6 with Widgets and SQL modules
* MariaDB/MySQL with the Qt `QMYSQL` driver available

Example build:

```bash
cmake -S . -B build
cmake --build build
```

## Documentation

Generate the Doxygen documentation with:

```bash
doxygen Doxyfile
```

Generated build and documentation output should not be committed to the repository.
