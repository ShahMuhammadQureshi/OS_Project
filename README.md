# OS_Project

Cache Cleaner
Introduction
Cache memory is a type of temporary data storage that stores frequently used data for quicker access by the system. Over time, cache memory can become cluttered and cause system performance issues. The cache cleaner program presented in this report provides several options for clearing out different types of cache memory on Ubuntu systems. The cache cleaner program is a C program that allows users to clean various types of caches on their Linux-based operating system. The program gives users a menu of different cache types to choose from and performs the cleaning operation on the selected cache type. The program includes the following cache cleaning operations:
•	System cache memory
•	Swap cache memory
•	DNS cache memory
•	Temporary files
•	RAM cache memory
•	ARP cache memory
•	Other caches on Ubuntu
Code Overview
The program uses C standard libraries like stdio.h, stdlib.h, stdbool.h, sys/wait.h, and unistd.h. It defines several functions, including:
•	SystemCacheMemory() to clear the system cache memory
•	ClearOutSwap() to clear the swap cache memory
•	DNSCscheMemory() to clear the DNS cache memory
•	TemporaryFile() to clear the temporary files
•	RAMCacheMemory() to clear the RAM cache memory
•	ARPCacheMemory() to clear the ARP cache memory
•	OtherCache() to clear other caches on Ubuntu
•	DoAll() to clear all caches at once
The main() function presents a menu of cache types to the user and allows the user to select the cache type to clean. After the user's selection, the program calls the appropriate function to clear the cache type. If the user selects the "Clean All" option, the DoAll() function is called to clear all cache types.
Working
The main() function presents a menu of cache types to the user. The user selects the desired cache type to clean by entering the corresponding number. If the user selects the "Clean All" option, the DoAll() function is called, which sequentially executes all the cache clearing functions one by one.
1. System Cache Memory
This option clears out the system cache memory by dropping cached data from memory by executing this command “echo 1 > /proc/sys/vm/drop_caches”. Before and after running this option, the program displays the status of the system cache memory using the "free -m -h" command 
2. Clear Out Swap
This option clears out the swap memory by turning swap off and then on again. Before and after running this option, the program displays the status of the swap memory using the "free -m -h" command.
3. DNS Cache Memory
This option clears out the DNS cache memory by flushing the system's DNS cache using the "systemd-resolve --flush-caches" command. Before and after running this option, the program displays the status of the system cache memory using the "free -m -h" command and the statistics of the DNS cache memory using the "systemd-resolve --statistics" command.
4. Temporary Files
This option clears out temporary files by listing the files in the "/var/tmp" directory, deleting all directories in that directory using the "find /var/tmp/* -type d -delete" command, and then listing the files in the directory again.
5. RAM Cache Memory
This option clears out the RAM cache memory by dropping the cache using the "echo 1 > /proc/sys/vm/drop_caches", "echo 2 > /proc/sys/vm/drop_caches", and "echo 3 > /proc/sys/vm/drop_caches" commands. Before and after running this option, the program displays the status of the RAM cache memory using the "free -h" command.
6. ARP Cache Memory
This option clears out the ARP cache memory by flushing all entries in the ARP cache using the "ip -s -s neigh flush all" command.
7. Clearing Other Caches on Ubuntu
This option installs the "bleachbit" package using the "sudo apt install bleachbit" command and then uses the "bleachbit" command with the "--preview system.tmp" option to preview the system cache memory cleaning. After previewing, the program uses the "bleachbit" command with the "--clean cleaner-name.name" option to clean the system cache memory.
8. Clean All
This option runs all of the above options one by one. The program waits for 5 seconds after each option before proceeding to the next.

After executing the command to clear the cache type, the function displays the status of the cache type before and after clearing using the system command free -m -h for memory-based caches and ls for file-based caches.
Conclusion
The cache cleaner program provides a convenient way for Linux users to clean various types of caches on their system. It uses system commands to clear the caches and presents a menu-based interface to the user. By running the program, users can quickly free up valuable system resources and improve the performance of their system.

Group Members:
21k-3557	Shah Muhammad Qureshi
21k-4761	Anas Khan
21k-3589	Sami

