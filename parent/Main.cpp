#include <iostream>
#include <Windows.h>

const char CHILD_PATH[] = "..\\Debug\\child.exe";

int main(int argc, char** argv) {
	STARTUPINFO startUpInfo;
	ZeroMemory(&startUpInfo, sizeof(startUpInfo));
	startUpInfo.cb = sizeof(startUpInfo);

	PROCESS_INFORMATION processInfo;

	if (!CreateProcess(
		CHILD_PATH,
		NULL,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&startUpInfo,
		&processInfo
	)) {
		std::cout << "cannot create process!" << std::endl;
	}

	switch (WaitForSingleObject(processInfo.hProcess, 20000)) {
	case WAIT_FAILED:
		std::cout << "waiting failed. error: " << GetLastError() << std::endl;
		break;
	case WAIT_OBJECT_0:
		std::cout << "waiting succeed" << std::endl;
		break;
	case WAIT_TIMEOUT:
		std::cout << "timeout is over" << std::endl;
		break;
	}
	system("pause > NUL");
	return 0;
}