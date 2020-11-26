#ifndef _LMCHDEV_H
#define _LMCHDEV_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define CHARDEVQ_NO_REQUESTS (-1)
#define CHARDEV_CLOSE 0
#define CHARDEVQ_MAX_PRIORITY 1
#define CHARDEVQ_DEV_PARMNUM 1
#define HANDLE_INFO_LEVEL_1 1
#define HANDLE_CHARTIME_PARMNUM 1
#define HANDLE_CHARCOUNT_PARMNUM 2
#define CHARDEV_STAT_OPENED 2
#define CHARDEVQ_PRIORITY_PARMNUM 2
#define CHARDEVQ_DEVS_PARMNUM 3
#define CHARDEV_STAT_ERROR 4
#define CHARDEVQ_NUMUSERS_PARMNUM 4
#define CHARDEVQ_NUMAHEAD_PARMNUM 5
#define CHARDEVQ_DEF_PRIORITY 5
#define CHARDEVQ_PRIORITY_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+CHARDEVQ_PRIORITY_PARMNUM)
#define CHARDEVQ_DEVS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+CHARDEVQ_DEVS_PARMNUM)
#define CHARDEVQ_MIN_PRIORITY 9
typedef struct _CHARDEV_INFO_0 { LPWSTR ch0_dev; } CHARDEV_INFO_0,*PCHARDEV_INFO_0,*LPCHARDEV_INFO_0;
typedef struct _CHARDEV_INFO_1 {
	LPWSTR ch1_dev;
	DWORD ch1_status;
	LPWSTR ch1_username;
	DWORD ch1_time;
} CHARDEV_INFO_1,*PCHARDEV_INFO_1,*LPCHARDEV_INFO_1;
typedef struct _CHARDEVQ_INFO_0 { LPWSTR cq0_dev; } CHARDEVQ_INFO_0,*PCHARDEVQ_INFO_0,*LPCHARDEVQ_INFO_0;
typedef struct _CHARDEVQ_INFO_1 {
	LPWSTR cq1_dev;
	DWORD cq1_priority;
	LPWSTR cq1_devs;
	DWORD cq1_numusers;
	DWORD cq1_numahead;
} CHARDEVQ_INFO_1,*PCHARDEVQ_INFO_1,*LPCHARDEVQ_INFO_1;
typedef struct _CHARDEVQ_INFO_1002 { DWORD cq1002_priority; } CHARDEVQ_INFO_1002,*PCHARDEVQ_INFO_1002,*LPCHARDEVQ_INFO_1002;
typedef struct _CHARDEVQ_INFO_1003 { LPWSTR cq1003_devs; } CHARDEVQ_INFO_1003,*PCHARDEVQ_INFO_1003,*LPCHARDEVQ_INFO_1003;
typedef struct _HANDLE_INFO_1 {
	DWORD hdli1_chartime;
	DWORD hdli1_charcount;
}HANDLE_INFO_1,*PHANDLE_INFO_1,*LPHANDLE_INFO_1;
NET_API_STATUS WINAPI NetCharDevEnum(LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
NET_API_STATUS WINAPI NetCharDevGetInfo(LPCWSTR,LPCWSTR,DWORD,PBYTE*);
NET_API_STATUS WINAPI NetCharDevControl(LPCWSTR,LPCWSTR,DWORD);
NET_API_STATUS WINAPI NetCharDevQEnum(LPCWSTR,LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
NET_API_STATUS WINAPI NetCharDevQGetInfo(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,PBYTE*);
NET_API_STATUS WINAPI NetCharDevQSetInfo(LPCWSTR,LPCWSTR,DWORD,PBYTE,PDWORD);
NET_API_STATUS WINAPI NetCharDevQPurge(LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetCharDevQPurgeSelf(LPCWSTR,LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetHandleGetInfo(HANDLE,DWORD,PBYTE*);
NET_API_STATUS WINAPI NetHandleSetInfo(HANDLE,DWORD,PBYTE,DWORD,PDWORD);
#ifdef __cplusplus
}
#endif
#endif
