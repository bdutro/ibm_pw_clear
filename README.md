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
*Boot Password*  
This can be disabled with a switch on the motherboard.  
*Setup Password*  
This one is harder, because you can't change boot options unless you know the setup password. If you're lucky, USB UEFI boot might already be enabled. If it isn't, you can try resetting the CMOS settings. PXE boot is enabled in the default settings, and it's relatively simple to PXE boot an EFI binary (either a shell or this tool).

* **Will this work on a non-IBM server?**  
No, this uses IBM-specific UEFI hooks to reset the passwords.

* **Will this work on other IBM server models?**  
I don't know. It definitely won't work on older servers that don't use UEFI. It might work on other M3-series servers, but I can only be sure it works on the x3550 and x3650 models because they share the same motherboard. It's possible that it could work on newer IBM/Lenovo servers, but they also could have changed or removed the UEFI hook that this tool relies on.

## Disclaimer

Use at your own risk, and don't use this tool without permission on any servers you don't own.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Nikolaj Schlej's [UEFITool](https://github.com/LongSoft/UEFITool) made all this possible
* Pedro Vilaça's [EFISwissKnife IDA plugin](https://github.com/gdbinit/EFISwissKnife) and [blog post](https://reverse.put.as/2016/06/25/apple-efi-firmware-passwords-and-the-scbo-myth/) on Apple EFI reverse engineering were both enormously helpful
* Jethro Beekman's [blog post](https://jbeekman.nl/blog/2015/03/reverse-engineering-uefi-firmware/) on UEFI reverse engineering

## Donations

This tool is made available for absolutely no charge, but if it helps you out and you want to send a couple of bucks my way, feel free to use the donation button.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=AAY5Q8QSLN9RL&source=url)
