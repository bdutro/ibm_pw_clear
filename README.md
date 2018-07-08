# IBM x3550/x3560 M3 Password Clear Tool

Small EFI utility that clears the power-on and setup passwords in IBM x3550/x3650 M3 servers

## Getting Started

### Prerequisites

You'll need the GNU-EFI headers and libraries installed if you want to build this from source. Alternatively, you can just download a precompiled binary from the release page.

### Building

Just run
```
make
```
The resulting binary is named `ibm_pw_clear.efi`

### Running

* You can directly boot to the binary if you rename it to `shellx64.efi` and place it on a USB drive. The server should automatically reboot after clearing the passwords.
* Alternatively, you can also boot into a UEFI shell and run `ibm_pw_clear.efi` manually

### FAQ

* **Wait, how am I supposed to run this tool if the boot and setup passwords are both set?**
**Boot Password**
This can be disabled with a switch on the motherboard.
**Setup Password**
This one is harder, because you can't change boot options unless you know the setup password. If you're lucky, USB UEFI boot might already be enabled. If it isn't, you can try resetting the CMOS settings. PXE boot is enabled in the default settings, and it's relatively simple to PXE boot an EFI binary (either a shell or this tool).

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Nikolaj Schlej's [UEFITool](https://github.com/LongSoft/UEFITool) made all this possible
* Pedro Vilaça's [EFISwissKnife IDA plugin](https://github.com/gdbinit/EFISwissKnife) and [blog post](https://reverse.put.as/2016/06/25/apple-efi-firmware-passwords-and-the-scbo-myth/) on Apple EFI reverse engineering were both enormously helpful
* Jethro Beekman's [blog post](https://jbeekman.nl/blog/2015/03/reverse-engineering-uefi-firmware/) on UEFI reverse engineering

