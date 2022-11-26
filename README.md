# kernel-2d-memcpy

Kernel Memory Copy - Adding a syscall and generating a patch file

In this project we are adding a system call which copies one 2-D floating point matrix to another.

For this I have manually written and incorporated a system call to the file sys.c which contains the code for all the system calls. 
Next I have added the name of the system call to the syscall_64.tbl file.
After this I have created a patch file using the ‘diff’ command between the updated kernel and a new stock kernel. 
Using this patch file I patched the kernel and compiled it using the ‘make’ command. Further I created a C program for testing the syscall and ran it successfully after compiling and running the patched kernel.

Firstly, I have downloaded the stock linux kernel and made the following changes to it:- 
Added the 2-D matrix code in the file ‘sys’.c which can be found inside the kernel directory.
Added the syscall name at 451st position in the syscall_64.tbl file which can be found at /arch/x86/entry/syscalls/syscall_64.tbl
Change the name of the kernel source code directory to anything you like and untar a new source code.
In the root directory run diff -ru new_kernel_name  updated_kernel_name > ../patchFile to generate a patch file.
Now use the command patch -p1 < ../patchFile inside the new kernel source directory to patch it.
Use ‘make’ command to compile the kernel.
Now run the following commands 
sudo cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-linuxABC
Sudo make modules_install
Sudo mkinitcpio -k 5.19.9 -g /boot/initramfs-linuxABC.img

After this has been done, reboot the system and log into the new linux kernel by going to the Advanced settings at the grub interface. 
Now you can run the test file to check if the syscall is working correctly.
