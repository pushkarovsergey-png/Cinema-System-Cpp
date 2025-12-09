import os
import sys
import time

def run(command):
    print(f"Running command: {command}")
    if os.system(command) != 0:
        print("Error!")
        exit(1)

print("Killing old processes...")
os.system("taskkill /F /IM CinemaServer.exe 2>nul")
os.system("taskkill /F /IM CinemaClient.exe 2>nul")
time.sleep(1)

print("Building project...")
if not os.path.exists("build"):
    os.makedirs("build")

run("cmake -S . -B build -G \"MinGW Makefiles\"")
run("cmake --build build")

print("Launching...")
os.system("start cmd /c build\\CinemaServer.exe")
time.sleep(1)
os.system("start cmd /c build\\CinemaClient.exe")
os.system("start cmd /c build\\CinemaClient.exe")

if os.path.exists("build\\run_tests.exe"):
    print("Testing...")
    os.system("build\\run_tests.exe")