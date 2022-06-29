# Startup Logger

The program logs the number of times the device boots into a CSV file named `Record.csv`. The programs adds a record consisting of Serial number, Date and Time of booting to the end of CSV file everytime the device boots. On the first run `Record.csv` will be auto created with necessary table headers. 

The code is written in `C++17` and will not work in previous versions as the function `std::filesystem::exists()` used on line 16 was added in this version. To compile the code on `C++14`, `std::experimental::filesystem::v1::exists()` must be used instead.

### Setting up the program 

1. On Windows
    - Compile the code and save the program in the desired folder.
    - Predd Windows logo key + R and enter shell:startup.
    - Copy the shortcut to the program into the opened folder.

    Refer [this](https://support.microsoft.com/en-us/windows/add-an-app-to-run-automatically-at-startup-in-windows-10-150da165-dcd9-7230-517b-cf3c295d89dd) article to learn more.

2. On Ubuntu

    Refer [this](https://itsfoss.com/manage-startup-applications-ubuntu/) article to setup the program to run on start up in Ubuntu.
