#pragma once

#define ulonglong unsigned unsigned long


struct _UNICODE_STRING
{
	unsigned short Length;
	unsigned short MaxLength;
	unsigned long Pad;
	wchar_t* Buffer;
};





extern "C"
{
		int ZwPlugPlayControl(ulonglong InfoClass,
						ulonglong pInfo,
						ulonglong InfoLength);

}



bool Acquire_Tcb();



