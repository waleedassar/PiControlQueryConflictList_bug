# A denial of service bug in ntoskrnl!PiControlQueryConflictList, where a usermode-supplied pointer is not probed. 


To test POC, you have to be "SYSTEM" ===> via e.g. "psexec.exe -s -i poc.exe".



STACK_TEXT:  
ffffcb8d`77d4f930 fffff807`2b2a75de : fffff807`2ac01970 00000000`00000038 00000000`00000001 00000000`00000012 : nt!PiControlQueryConflictList+0x60
ffffcb8d`77d4f9b0 fffff807`2b0077b5 : ffffe105`0e9c5080 0000003a`61eff750 ffffcb8d`77d4fa80 ffffba8a`99d03030 : nt!NtPlugPlayControl+0xbe
ffffcb8d`77d4fa00 00007ff9`081cf354 : 00000000`00000000 00000000`00000000 00000000`00000000 00000000`00000000 : nt!KiSystemServiceCopyEnd+0x25
0000003a`61eff728 00000000`00000000 : 00000000`00000000 00000000`00000000 00000000`00000000 00000000`00000000 : 0x00007ff9`081cf354

