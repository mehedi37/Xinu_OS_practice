cd learning-xinu/compile/ 
make clean 
sudo make
# for linux users
# echo "YOUR_ADMIN_PASS" | sudo -S make
qemu-system-i386 -m 16 -kernel xinu.elf -nographic -append "console=ttyS0"