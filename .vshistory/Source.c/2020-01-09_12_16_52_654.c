#include "ntddk.h"

VOID DriveUnload(IN PDRIVER_OBJECT DriverObject) {
	DbgPrint("Goodbye there!\r\n");
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath) {
	DriverObject->DriverUnload = 
	DbgPrint("Hello there!\r\n");
	return STATUS_SUCCESS;
}