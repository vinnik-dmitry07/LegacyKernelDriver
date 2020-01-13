# LegacyKernelDriver
1. Download and install  [WDK](https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk "WDK") corresponding version of Windows
- **Tip:** to open *Command Prompt* as administrator press WIN + R, enter *cmd*, press Ctrl + Shift + Enter
2. Install Oracle VM VirtualBox
3. 
    1. **Use ready** virtual machine (VM):
        - Download from [link](https://mega.nz/#!eIAGxYhY!Y1yOnsnTl6WYUL3rqqLZ_bU77bapbYUQp_KmssuKPhw "link")
        - Extract it somewhere
        - Run the VM using .vbox file
    2. *OR*
    3. **Create it yourself**:
        - Install last image of Windows 10 x64 on the VM
        - Setup the VM network:
        - **Tip:** You can always swich language to English in VirtualBox settings
        - Go to *Oracle VM Virtual Box Manager* (main window)
        - Select your machine in the left side
        - Go to *Settings > Network*
        - Choose *Attached to: Host-only adapter*
        - Select *Adapter 2* tab
        - Check *Enable Network Adapter*
        - Choose *Attached to: NAT*
        - Click *OK*
        - Run the VM
        - In the *Run* window (Win + R) run *ncpa.cpl* (runs *Network Connections* - *Сетевые подключения*)
        - Right click *Ethernet* > *Properties* > *Internet Protocol Version 4*-*IP версии 4* > *Properties*
        - Choose *Use the following IP address*
        - Enter *IP address: 192.168.56.56*
        - Enter *Subnet mask: 255.255.255.0*
        - Click *OK*
        - Execute the command as admin: *REG ADD "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Debug Print Filter" /v DEFAULT /t REG_DWORD /d 0xF*
        [Description why](HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Debug Print Filter "Description why")
      - Copy * ..\Windows Kits\10\Debuggers\x64\kdnet.exe* from to host computer to the VM
      - Run *kdnet* - execute the command : *kdnet 192.168.56.1 53000*
4. On the VM:
	- Execute the command as admin: *bcdedit /dbgsettings*
	- Copy the *key* somewhere
5. On the host computer:
  - Run *..\Windows Kits\10\Debuggers\x64\windbg.exe*
	- On the *File* menu, choose *Kernel Debug*. In the *Kernel Debugging* dialog box, open the *Net* tab. Paste in *53000* port number and key that you saved. 
	- Click OK.
6. On the VM:
	- On desktop run OSRLOADER
	- Select *Driver Path: C:\Users\WDKRemoteUser\Desktop\Legacy.sys*
	- Ignoring warnings click *Stop Service*, *Unregister Service*
	- Click *Register Service*
	- Click *Start Service* as result you will see this in WinDbg:
	![Result 1](Result&#32;1.png)
	- Click *Stop Service* as result you will see this in WinDbg:
	![Result 2](Result&#32;2.png)
