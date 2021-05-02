# A denial of service bug in ntoskrnl!PiControlQueryConflictList, where a usermode-supplied pointer is not probed. 


To test POC, you have to be "SYSTEM" ===> via e.g. "psexec.exe -s -i poc.exe".


//----------- Crash Dump -------------------------
2: kd> !analyze -v
*******************************************************************************
*                                                                             *
*                        Bugcheck Analysis                                    *
*                                                                             *
*******************************************************************************

SYSTEM_SERVICE_EXCEPTION (3b)
An exception happened while executing a system service routine.
Arguments:
Arg1: 00000000c0000005, Exception code that caused the bugcheck
Arg2: fffff8072b4af490, Address of the instruction which caused the bugcheck
Arg3: ffffcb8d77d4ef30, Address of the context record for the exception that caused the bugcheck
Arg4: 0000000000000000, zero.


CONTEXT:  ffffcb8d77d4ef30 -- (.cxr 0xffffcb8d77d4ef30)
rax=fffff8072b4af430 rbx=ffffba8a99d03030 rcx=0000000000000012
rdx=cecececefefefefe rsi=0000000000000001 rdi=0000000000000012
rip=fffff8072b4af490 rsp=ffffcb8d77d4f930 rbp=ffffcb8d77d4f980
 r8=0000000000000028  r9=0000000000000001 r10=0000000000000001
r11=0000000000000000 r12=ffffba8a99d03050 r13=0000000000000000
r14=0000000000000000 r15=0000000000000000
iopl=0         nv up ei pl zr na po nc
cs=0010  ss=0018  ds=002b  es=002b  fs=0053  gs=002b             efl=00050246
nt!PiControlQueryConflictList+0x60:
fffff807`2b4af490 443912          cmp     dword ptr [rdx],r10d ds:002b:cececece`fefefefe=????????
Resetting default scope


STACK_TEXT:  
ffffcb8d`77d4f930 fffff807`2b2a75de : fffff807`2ac01970 00000000`00000038 00000000`00000001 00000000`00000012 : nt!PiControlQueryConflictList+0x60
ffffcb8d`77d4f9b0 fffff807`2b0077b5 : ffffe105`0e9c5080 0000003a`61eff750 ffffcb8d`77d4fa80 ffffba8a`99d03030 : nt!NtPlugPlayControl+0xbe
ffffcb8d`77d4fa00 00007ff9`081cf354 : 00000000`00000000 00000000`00000000 00000000`00000000 00000000`00000000 : nt!KiSystemServiceCopyEnd+0x25
0000003a`61eff728 00000000`00000000 : 00000000`00000000 00000000`00000000 00000000`00000000 00000000`00000000 : 0x00007ff9`081cf354

