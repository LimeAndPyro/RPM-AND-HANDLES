
#include <Windows.h>
#include <iostream>
#include <sys/types.h>

using namespace std;

int main()
{
	DWORD PID = 0; //buffer for process ID
	cout << "Process ID: ";
	cin >> dec >> PID;//Prompt for id

	//create handle to dummy program
	HANDLE hofproc = OpenProcess(PROCESS_ALL_ACCESS, false, PID);
	if (hofproc != NULL)
	{
		uintptr_t MemAdd = 0x0;
		cout << "MEMORY ADDRESS: ";
		cin >> hex >> MemAdd;//Prompt for address

		int readbuffer = 0;
		BOOL rpm = ReadProcessMemory(hofproc, (LPCVOID)MemAdd, &readbuffer, sizeof(readbuffer), NULL);
		cout << "Memaddress value = " << readbuffer << std::endl;
		std::cout << "PRESS ENTER TO PRINT AGAIN" << std::endl;
		getchar();
		//- Print to console a line of dashes("-") and then let it loop back to the beginning
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		return EXIT_SUCCESS;
	}
	else
	{
		std::cout << "-------------------HANDLE FAILED TO ATTATCH TO PROCESS------------------------------" << std::endl;
		return EXIT_FAILURE;
	}


}
