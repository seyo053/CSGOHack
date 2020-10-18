#include "ProcMem.h"
#include "csgo.hpp"

using namespace std;
using namespace hazedumper;
using namespace netvars;
using namespace signatures;

ProcMem mem;

int main()
{
	char proc[9] = "csgo.exe";
	char module[20] = "client_panorama.dll";
	mem.Process(proc);
	DWORD gameModule = mem.Module(module);

	cout << "Radar Hack Enabled - bySeyo";

	while (true)
	{
		for (short int i = 0; i < 64; i++)
		{
			DWORD entity = mem.Read<DWORD>(gameModule + dwEntityList + i * 0x10);
			if (entity != NULL)
			{
				mem.Write(entity + m_bSpotted, true);
			}
		}
		Sleep(40);
	}
}