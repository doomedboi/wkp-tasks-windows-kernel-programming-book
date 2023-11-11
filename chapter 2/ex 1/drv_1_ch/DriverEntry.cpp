#include <ntddk.h>


auto DriverUnload(_In_ PDRIVER_OBJECT) -> void;

extern "C"
NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = &DriverUnload;

	KdPrint(("Driver in ready state."));

	auto printWinVersion = []() noexcept
	{
		RTL_OSVERSIONINFOW osInfo;
		if (NT_SUCCESS(RtlGetVersion(&osInfo)))
		{
			KdPrint(("major ver.: %d minor ver.: %d build num.: %d", osInfo.dwMajorVersion, osInfo.dwMinorVersion, osInfo.dwBuildNumber));
		}
		
	};

	printWinVersion();

	return STATUS_SUCCESS;
}

auto DriverUnload(_In_ PDRIVER_OBJECT DriverObject) -> void
{
	UNREFERENCED_PARAMETER(DriverObject);
}

