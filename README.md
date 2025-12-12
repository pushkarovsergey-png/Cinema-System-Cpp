# Cinema Booking System (C++ Multithreaded TCP Server)

This is a real-time cinema ticketing simulation designed to demonstrate **Network Programming**, **Multithreading**, and **Thread Safety** in C++.

It consists of a **Central Server** (Cinema Hall) and multiple **Clients** (Cashiers/Terminals). Multiple clients can connect simultaneously to view seat availability and book tickets without data races.

## Features

* **TCP/IP Networking:** Implemented using Windows Sockets 2 (`Winsock2`).
* **Multithreading:** The server handles each client in a separate thread (`std::thread`).
* **Thread Safety:** Uses `std::mutex` and `std::lock_guard` to prevent double-booking (Race Conditions).
* **Smart Automation:** Includes a **Python script (`run.py`)** that automatically cleans old processes, builds the project, and launches the system.
* **Modern C++:** Uses C++17 standard.

## Tech Stack

* **Language:** C++17
* **Build System:** CMake
* **Automation:** Python 3
* **OS:** Windows (MinGW/GCC)

## Commands

When the client is connected, you can use the following commands:

| Command | Description | Example |
| :--- | :--- | :--- |
| **`SHOW`** | Displays the current status of the hall (Free/Taken). | `SHOW` |
| **`BOOK <id>`** | Attempts to book a specific seat number (0-9). | `BOOK 5` |
| **`EXIT`** | Disconnects the client from the server. | `EXIT` |

## How to Build and Run

### Prerequisites
* C++ Compiler (MinGW/GCC) added to system PATH.
* CMake.
* Python 3.

### Option 1: Automatic Launch (Recommended)
Simply run the Python script. It handles everything: killing old processes, compiling, and launching.

```bash
python run.py
```
### Option 2: Manual Build
If you want to build it manually without the script:

```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
```

Then run CinemaServer.exe first, followed by CinemaClient.exe.

### Testing

The project is configured to use Google Test. The run.py script automatically attempts to run tests if they are built successfully.

## To run manually after building:

```bash
./build/run_tests.exe
```

##Future Improvements

* **Concurrency Optimization (C++17):** Replace standard `std::mutex` with `std::shared_mutex` to implement a Readers-Writer lock pattern. This will significantly improve performance by allowing multiple clients to check seat availability simultaneously.
* **Scalability (Thread Pool):** Implement a Thread Pool to handle high loads and address the C10k problem, replacing the current thread-per-client model.
