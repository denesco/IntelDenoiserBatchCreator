#include <iostream>
#include <fstream>
#include<windows.h>
using namespace std;

int main() {
	const int SIZE = 512;
	char todenoiser[SIZE]{}, toinput[SIZE]{}, tooutput[SIZE]{}, denoiser[]{"Denoiser.exe"};
	cout << "This is simple Batch creator for Denoiser.exe\n";
	cout << "You will need to point 3 directories :\nwhere is the Denoiser.exe, where are source files and where to save denoised pictures\n";
	cout << "You should know, ALL files in source directory, will be written in batch, so there must be only needed pictures\n";
	cout << "Directories must look like this - C:\\Users\\Public\\, with last \"\\\" (slash)\n" ;
	cout << "So, now insert directory, where is Denoiser.exe\n";
	cin >> todenoiser;
	cout << "\nNow, Insert where are the source fies\n";
	cin >> toinput;
	cout << "\nAnd last, insert directory, where to save files\n";
	cin >> tooutput;
	strcat_s(todenoiser, denoiser);
		WIN32_FIND_DATA FindFileData;
		HANDLE hf;
		ofstream fout;
		fout.open("!Image_sequence_batch.bat");
		char dot('.');
		for (int i = 0; i < 511; i++)
		{
			if (toinput[i] == '\0')
			{
				toinput[i] = '*';
				break;
			}
		}
		hf = FindFirstFile(toinput, &FindFileData);
		for (int i = 0; i < 511; i++) 
		{
			if (toinput[i] == '\0') 
			{
				i--; 
				toinput[i] = '\0';
				break;
			}
		}
		if (hf != INVALID_HANDLE_VALUE) {
			do
			{
				dot = (char)FindFileData.cFileName[0];
				if (dot == '.') goto skp;
				fout <<"\""<< todenoiser << "\" -i \"" << toinput << FindFileData.cFileName << "\" -o \"" << tooutput << FindFileData.cFileName<<"\"\n";	
			skp:
				cout << '.';
			} while (FindNextFile(hf, &FindFileData) != 0);
			FindClose(hf);
		}
		fout.close();
		cout << "\n\nDone! \nNow, check directory, where THIS programm is placed.\nThere must be a created batch file named \"!Image_sequence_batch.bat\"\n";
		cout << "Just run the batch, when you will need it\n";

	system("pause");
	return 0;
}

