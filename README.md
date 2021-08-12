# Socket Communication C++

## Summary
This project show how to create a Snake game and play it on two computer screens.<br />
Both computers are on local network and the communication between them will be via<br /> Ethernet cable/ Wi-Fi.

### The code for this project uses the following:
- Visual Studio 2019 platform.
- OOP ( Object-Oriented Programming ).
- Winsock library ( Windows Libraries ).
- Socket Static Library ( Created to reduce code lines ).
- SDL2 ( Graphic Library ).

<p align="center">
  <img src="https://github.com/matanelg/socket/blob/master/files/soc.png">
</p>


## Resources:

- [Winsock library documentation](https://docs.microsoft.com/en-us/windows/win32/winsock/getting-started-with-winsock)
- [Socket programing tutorial](https://www.tutorialspoint.com/unix_sockets/index.htm)
- [SDL2 library documentation](https://wiki.libsdl.org/)


## Operating Instructions

### Step 1 
In one comuter open your cmd and get your local ip address (ipconfig command) this gonna be your server ip. run the Snake Game Server Side.exe on this computer and input the ip in first, and then choose port number as you like and input it too (number 0~65535). It is recommended to select a high port number like 50000 to avoid using ports that may already be in use on your computer.

### Step 2
On the other computer open Snake Game Client Side.exe and input the same ip address and port like you did in step one.

<style>
p{color:Red !important;}
</style>

Be aware the apps will only work for Windows users

Please note that on both computers you will need to authorize access to the executable files through the firewall.


## Performance

https://user-images.githubusercontent.com/64362937/129179849-d3afb0a4-a35b-4470-8894-324d4e3ed259.mp4


