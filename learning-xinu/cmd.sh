echo $PASS | sudo -S mkdir -p '/srv/tftp' && \
echo $PASS | sudo -S chmod 777 '/srv/tftp'

source .env
cd ~/Desktop/github/learning-xinu/compile/ && \
make clean && \
echo $PASS | sudo -S make && \
qemu-system-i386 -m 16 -kernel xinu.elf -nographic -append "console=ttyS0"