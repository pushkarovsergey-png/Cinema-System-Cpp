#  Cinema Booking System (C++ Multithreaded TCP Server)

This is a real-time cinema ticketing simulation designed to demonstrate **Network Programming**, **Multithreading**, and **Thread Safety** in C++.

It consists of a **Central Server** (Cinema Hall) and multiple **Clients** (Cashiers/Terminals). Multiple clients can connect simultaneously to view seat availability and book tickets without data races.

##  Features

* **TCP/IP Networking:** Implemented using Windows Sockets 2 (`Winsock2`).
* **Multithreading:** The server handles each client in a separate thread (`std::thread`), allowing concurrent connections.
* **Thread Safety:** Uses `std::mutex` and `std::lock_guard` to protect the seating map from Race Conditions (preventing double-booking).
* **Business Logic Layer:** Separated logic in `Cinema` class.
* **Automation:** Includes a Bash script (`run.sh`) for one-click build and launch.
* **Modern C++:** Uses C++20 features.

## 🛠 Tech Stack

* **Language:** C++20
* **Build System:** CMake
* **OS:** Windows (MinGW/GCC)
* **Tools:** Git, Bash

##  Commands

When the client is connected, you can use the following commands:

| Command | Description | Example |
| :--- | :--- | :--- |
| **`SHOW`** | Displays the current status of the hall (Free/Taken). | `SHOW` |
| **`BOOK <id>`** | Attempts to book a specific seat number (0-9). | `BOOK 5` |
| **`EXIT`** | Disconnects the client from the server. | `EXIT` |

##  How to Build and Run

### Prerequisites
* C++ Compiler (MinGW/GCC)
* CMake
* Git Bash (recommended for running the script)

### Option 1: Automatic (Recommended)
Simply run the provided bash script. It will build the project and launch the Server + 2 Clients automatically.

```bash
./run.sh