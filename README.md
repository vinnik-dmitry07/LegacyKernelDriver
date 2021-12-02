# legacy-windows-kernel-driver

A simple legacy driver that sends the "Hello there!" message to the kernel debugger.

## Steps
1. Download and install  [WDK](https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk "WDK") corresponding version of Windows
- **Tip:** to open *Command Prompt* as administrator press WIN + R, enter *cmd*, press Ctrl + Shift + Enter
2. Install Oracle VM VirtualBox
3. 
	1. **Use ready** virtual machine (VM):
		- Download from the [link](https://mega.nz/#!rJwSAYRA!l-YGqnSmLzNXeu5EJ8TwR0efprQJ89b09nx7kh2uBwU "link")
		- Extract it somewhere
		- Run the VM using .vbox file
	2. *OR*
	3. **Create it yourself**:
		- Install the last image of Windows 10 x64 on the VM
		- **Tip:** You can always switch language to English in VirtualBox settings
		- Go to *Oracle VM Virtual Box Manager* (main window)
		- Select your machine on the left side
		- Go to *Settings > Network*
		- Choose *Attached to: Host-only adapter*
		- Select *Adapter 2* tab
		- Check *Enable Network Adapter*
		- Choose *Attached to: NAT*
		- Click *OK*
		- Run the VM
		- On the *Devices* menu, choose *Insert Guest Additions CD image...*
		- Navigate to the CD drive and install *VBoxWindowsAdditions*
		- Reload VM's Windows
		- On the *Devices* menu, choose *Shared Clipboard: Bidirectional*, *Drag and Drop: Bidirectional*
		- In the *Run* window (Win + R) run *ncpa.cpl* (runs *Network Connections* - *Сетевые подключения*)
		- Right click *Ethernet* > *Properties* > *Internet Protocol Version 4*-*IP версии 4* > *Properties*
		- Choose *Use the following IP address*
		- Enter *IP address: 192.168.56.56*
		- Enter *Subnet mask: 255.255.255.0*
		- Click *OK*
		- Execute the command as admin: *REG ADD "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Debug Print Filter" /v DEFAULT /t REG_DWORD /d 0xF*
		([Description why](https://github.com/vinnik-dmitry07/LegacyWindowsKernelDriver "Description why"))
		- Drug and drop *..\Windows Kits\10\Debuggers\x64\kdnet.exe* and *VerifiedNICList.xml* from the same folder of host computer to the VM
		- Run *kdnet* - execute the command as admin: *kdnet 192.168.56.1 50000*
		- Reload VM's Windows - execute the command: *shutdown -r -t 0*
4. On the VM:
	- Execute the command as admin: *bcdedit /dbgsettings*
	- Copy the *key* somewhere
5. On the host computer:
	- Run *..\Windows Kits\10\Debuggers\x64\windbg.exe*
	- On the *File* menu, choose *Kernel Debug*. In the *Kernel Debugging* dialog box, open the *Net* tab. Check if port number is *50000* and paste the key that you saved. 
	- Click OK.
	- Drug and drop *OSRLOADER.exe* and driver's .sys file to the VM (you can get all driver files from the Release section of this repository)
6. On the VM:
	- Run OSRLOADER.exe
	- Locate .sys file in the *Driver Path*
	- Click *Register Service*
	- Click *Start Service*, as a result, you will see this in WinDbg:
	![Result 1](Result&#32;1.png)
	- Click *Stop Service*, as a result, you will see this in WinDbg:
	![Result 2](Result&#32;2.png)
