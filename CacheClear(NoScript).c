#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>


bool SystemCacheMemory();
bool ClearOutSwap();
bool DNSCscheMemory();
bool TemporaryFile();
bool RAMCacheMemory();
bool ARPCacheMemory();
bool OtherCache();
bool DoAll();


int main()
{
	int choice;
	int check = 0;
	bool result;
	while(check == 0)
	{
		printf("Following are the Cache Memory types, Which memory you want to erase\n");
		printf("1. System cache memory.\n2. Clear out Swap\n3. DNS cach Memory\n4. temporary Files\n5. RAM cache Memory\n6. ARP cache Memory\n7. Clearing other caches on Ubuntu\n8. Clean All\n0. None of the above\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		if(choice == 0)
		{
			check++;
			return 0;
		}
		
		switch(choice)
		{
			case 1:
				result = SystemCacheMemory();
				if(result == 1)
				{
					printf("\n\nOperation status: true\n\n");
				}
				result = 0;
				break;
			case 2:
				result = ClearOutSwap();
				if(result == 1)
				{
					printf("\n\nOperation status: true\n\n");
				}
				result = 0;
				break;
			case 3:
				result = DNSCscheMemory();
				if(result == 1)
				{
					printf("\n\nOperation status: true\n\n");
				}
				result = 0;
				break;
			case 4:
				result = TemporaryFile();
				if(result == 1)
				{
					printf("\n\nOperation status: true\n\n");
				}
				result = 0;
				break;
			case 5:
				result = RAMCacheMemory();
				if(result == 1)
				{
					printf("\n\nOperation status: true\n\n");
				}
				result = 0;
				break;
			case 6:
				result = ARPCacheMemory();
				if(result == 1)
				{
					printf("\n\nOperation status: true\n\n");
				}
				result = 0;
				break;
			case 7:
				result = OtherCache();
				if(result == 1)
				{
					printf("\n\nOperation status: true\n\n");
				}
				result = 0;
				break;
			case 8:
				DoAll();
				sleep(5);
				break;
			default:
				printf("\nOut of range.\n");
				break;
		}
		sleep(10);
		system("clear");
	}

	return 0;
}

bool SystemCacheMemory()
{
	printf("\n\nStatus before clearing:\n");
	system("free -m -h");
	system("echo 1 > /proc/sys/vm/drop_caches");
	printf("\n\nStatus after clearing:\n");
	system("free -m -h");
	return true;
}

bool ClearOutSwap()
{
	printf("\nStatus before clearing:\n");
	system("free -m -h");
	system("sudo swapoff -a && swapon -a");
	printf("\nStatus after clearing:\n");
	system("free -m -h");
	return true;
}

bool DNSCscheMemory()
{
	printf("\nStatus before clearing:\n");
	system("free -m -h");
	system("sudo systemd-resolve --flush-caches");
	printf("\nStatus after clearing:\n");
	system("free -m -h");
	printf("\n");
	system("sudo systemd-resolve --statistics");
	return true;
}

bool TemporaryFile()
{
	system("ls /var/tmp");
	printf("\n");
	system("sudo find /var/tmp/* -type d -delete");
	printf("\n");
	system("ls /var/tmp");
	return true;
}

bool RAMCacheMemory()
{
	system("free -h");
	printf("\n");
	system("echo 1 > /proc/sys/vm/drop_caches");
	system("echo 2 > /proc/sys/vm/drop_caches");
	system("echo 3 > /proc/sys/vm/drop_caches");
	printf("\n");
	system("free -h");
	return true;
}

bool ARPCacheMemory()
{

	system("ip -s -s neigh flush all");
	return true;
}


bool OtherCache()
{
	system("sudo apt install bleachbit");
	system("sudo bleachbit --preview system.tmp");
	system("sudo bleachbit --clean cleaner-name.name");
	return true;
}

bool DoAll()
{
	SystemCacheMemory();
	ClearOutSwap();
	DNSCscheMemory();
	TemporaryFile();
	RAMCacheMemory();
	ARPCacheMemory();
	OtherCache();
}
