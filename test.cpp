#include <iostream>
#include <string>
#include <windows.h>

void clearconsole(void)
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

int main(void)
{
	std::string somearray[10] = {
					" ========",
					"= =======",
					"== ======",
					"=== =====",
					"==== ====",
					"===== ===",
					"====== ==",
					"======= =",
					"======== ",
					"========="};
	int i = 0;
	int j = 0;

	while (true)
	{	
		clearconsole();
		std::cout << somearray[i];
		i++;
		if (i > 9)
		{
			i = 0;
			j++;
		}
		if (j > 5)
		{
			exit(-1);
		}
		Sleep(100);
	}
	return 0;
}