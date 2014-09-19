#include<Windows.h>
#include<cstdio>
#include<iostream>
#include<fstream>

using namespace std;

const int Buffsize = 64 * 1024;
const int MBsize = 16 * 1024;

enum status{
	Ok = 0,
	Parameter_err,
	Openfile_err,
	HandleScreen,
	Getcursor_err
};


void ShowUseage();
BOOL isFullPath(char* pszPath);
char* StrCat_to_FullPath(char* pszCurDirectory, char* pszFileName);
void ShowPer(DWORD per, DWORD filesize);
void ShowProcess(DWORD dwPer, DWORD filesize);

void Help();

int main(int argc, char* argv[])
{
	switch (argc)
	{
		case 1:
			Help();
			return Ok;
		case 2:
			if (strcmp(argv[1], "/?") == 0)
			{
				Help();
				return Ok;
			}
			else
			{
				printf("Parameter error");
				ShowUseage();
				return Parameter_err;
			}

		case 4:
			if (strcmp(argv[2], "to") != 0)
			{
				printf("Parameter error");
				ShowUseage();
				return Parameter_err;
			}
			break;

		default:
			printf("Parameter error");
			ShowUseage();
			return Parameter_err;
	}

	char* pszSrcFileName;
	BOOL bIsFullPath;
	bIsFullPath = isFullPath(argv[1]);
	if (bIsFullPath)
	{
		pszSrcFileName = argv[1];
	}
	else
	{
		char szBuf[MAX_PATH];
		pszSrcFileName = szBuf;
		GetCurrentDirectory(MAX_PATH, pszSrcFileName);
		pszSrcFileName = StrCat_to_FullPath(pszSrcFileName, argv[1]);
	}

	char* pszDstFileName;
	bIsFullPath = isFullPath(argv[3]);
	if (bIsFullPath)
	{
		pszDstFileName = argv[3];
	}
	else
	{
		char szBuf[MAX_PATH];
		pszDstFileName = szBuf;
		GetCurrentDirectory(MAX_PATH, pszDstFileName);
		pszDstFileName = StrCat_to_FullPath(pszDstFileName, argv[3]);
	}

	ifstream infile(pszSrcFileName, ios::binary);
	if (infile.fail() == 1)
	{
		cout << "can't open file " << pszSrcFileName << endl;
		return Openfile_err;
	}
	ofstream outfile(pszDstFileName, ios::binary);
	if (outfile.fail() == 1)
	{
		cout << "can't open file " << pszDstFileName << endl;
		return Openfile_err;
	}

	HANDLE handleScreen;
	handleScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!handleScreen)
	{
		return HandleScreen;
	}
	COORD coordCursor;
	CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
	CONSOLE_CURSOR_INFO CursorInfo;

	char Buffer[Buffsize];
	HANDLE fSrcHandle;
	WIN32_FIND_DATA FileData1;
	fSrcHandle = FindFirstFile(pszSrcFileName, &FileData1);
	DWORD64 dwSrcFileSize = (FileData1.nFileSizeHigh*(MAXDWORD + 1)) + FileData1.nFileSizeLow;
	DWORD64 dwWrited = 0;

	printf("\n##################  File Copy Start !  ##################\n\n");

	do
	{

		infile.read(Buffer, sizeof(char)*Buffsize);
		DWORD dwReaded = infile.gcount();
		outfile.write(Buffer, infile.gcount());
		dwWrited += dwReaded;
		ShowPer(dwWrited, dwSrcFileSize);
		ShowProcess(dwWrited, dwSrcFileSize);

		GetConsoleScreenBufferInfo(handleScreen, &ScreenBufferInfo);
		coordCursor = ScreenBufferInfo.dwCursorPosition;
		coordCursor.Y = coordCursor.Y - 2;
		CursorInfo.dwSize = 66;
		CursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(handleScreen, &CursorInfo);
		SetConsoleCursorPosition(handleScreen, coordCursor);

	} while (!infile.eof());

	infile.close();
	outfile.close();
	printf("\n\n\n\n################# File Copy Completed ! #################\n\n");
	return Ok;
}


void Help()
{
	printf("Copy file\n"
		"Usage:\n"
		"    Copynew.exe srcFileName to dstFileName \n"
		"\n"
		"/?:               显示帮助信息.\n"
		"srcFileName :               源文件的路径.\n"
		"dstFileName :               目的文件路径.\n");
}

void ShowPer(DWORD dwPer, DWORD filesize)
{
	DWORD show = (DWORD)(100 * ((float)dwPer / filesize));
	printf("\r");
	printf("            %d/%d----%d%%Precent \n\n", dwPer, filesize,show);
}

void ShowUseage(void)
{
	printf("\n"
		"Copy file\n"
		"Usage:\n"
		"    Copynew.exe srcFileName to dstFileName\n");
}

void ShowProcess(DWORD dwPer, DWORD filesize)
{

	printf("\r");
	DWORD show = (DWORD)(100 * ((float)dwPer / filesize)) / 2;
	show = show > 50 ? 50 : show;
	printf("||");
	DWORD i;
	for (i = 0; i < show; i++)
		printf(">");
	for (; i != 50; ++i)
		printf(" ");
	printf("||");
}

BOOL isFullPath(char* pszPath)
{
	DWORD dwcount;
	dwcount = strlen(pszPath);
	for (DWORD dwi = 0; dwi < dwcount; dwi++)
	{
		if (*pszPath == ':')
			return TRUE;
		else
			pszPath++;
	}
	return FALSE;
}

char* StrCat_to_FullPath(char* pszCurDirectory, char* pszFileName)
{
	pszCurDirectory = strcat(pszCurDirectory, "/");
	pszCurDirectory = strcat(pszCurDirectory, pszFileName);
	return pszCurDirectory;
}