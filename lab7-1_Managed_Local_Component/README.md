# Lab 7-1: Local Component Demo

## คำอธิบาย
การทดลองนี้แสดงการใช้งาน component ที่มีอยู่ในโฟลเดอร์ `components/Sensors/` ของ project


## สรุปคำสั่งที่ใช้ และผลลัพธ์ที่ได้

ตอบ 
### สร้างโฟลเดอร์หลัก components
mkdir -p components/Sensors

mkdir -p components/Display

### สร้างไฟล์สำหรับ Sensors
touch components/Sensors/CMakeLists.txt

touch components/Sensors/sensor.h

touch components/Sensors/sensor.c

### สร้างไฟล์สำหรับ Display
touch components/Display/CMakeLists.txt

touch components/Display/display.h

touch components/Display/display.c


คำสั่งที่ใช้ build - idf.py build

คำสั่งที่ใช้ดูผลลัพธ์ idf.py qemu monitor




ผลลัพธ์ ในส่วนที่ยังไม่เพิ่ม display 

root@b35f767591b4:/project/lab7-1_Managed_Local_Component# idf.py qemu monitor
Running qemu on socket://localhost:5555
Adding "qemu"'s dependency "all" to list of commands with default set of options.
Executing action: all (aliases: build)
Running ninja in directory /project/lab7-1_Managed_Local_Component/build
Executing "ninja all"...
[1/4] cd /project/lab7-1_Managed_Local_Component/build/e.../project/lab7-1_Managed_Local_Component/build/lab7-1.bi 
lab7-1.bin binary size 0x27c80 bytes. Smallest app partition is 0x100000 bytes. 0xd8380 bytes (84%) free.
[1/1] cd /project/lab7-1_Managed_Local_Component/build/b..._Managed_Local_Component/build/bootloader/bootloader.bi 
Bootloader binary size 0x66a0 bytes. 0x960 bytes (8%) free.
[4/4] Completed 'bootloader'Executing action: qemu
Generating flash image: /project/lab7-1_Managed_Local_Component/build/qemu_flash.bin
esptool.py --chip=esp32 merge_bin --output=/project/lab7-1_Managed_Local_Component/build/qemu_flash.bin --fill-flash-size=2MB --flash_mode dio --flash_freq 40m --flash_size 2MB 0x1000 bootloader/bootloader.bin 0x10000 lab7-1.bin 0x8000 partition_table/partition-table.bin
esptool.py v4.9.0
SHA digest in image updated
Wrote 0x200000 bytes to file /project/lab7-1_Managed_Local_Component/build/qemu_flash.bin, ready to flash to offset 0x0
Generating efuse image: /project/lab7-1_Managed_Local_Component/build/qemu_efuse.bin
Running qemu (bg): qemu-system-xtensa -M esp32 -m 4M -drive file=/project/lab7-1_Managed_Local_Component/build/qemu_flash.bin,if=mtd,format=raw -drive file=/project/lab7-1_Managed_Local_Component/build/qemu_efuse.bin,if=none,format=raw,id=efuse -global driver=nvram.esp32.efuse,property=drive,value=efuse -global driver=timer.esp32.timg,property=wdt_disable,value=true -nic user,model=open_eth -nographic -serial tcp::5555,server
Executing action: monitor
Running idf_monitor in directory /project/lab7-1_Managed_Local_Component
Executing "/opt/esp/python_env/idf6.0_py3.12_env/bin/python /opt/esp/idf/tools/idf_monitor.py -p socket://localhost:5555 -b 115200 --toolchain-prefix xtensa-esp32-elf- --target esp32 --revision 0 /project/lab7-1_Managed_Local_Component/build/lab7-1.elf /project/lab7-1_Managed_Local_Component/build/bootloader/bootloader.elf -m '/opt/esp/python_env/idf6.0_py3.12_env/bin/python' '/opt/esp/idf/tools/idf.py'"...
--- esp-idf-monitor 1.6.2 on socket://localhost:5555 115200
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H
I (9712) SENSOR: 📊 Reading sensor data from file: /project/components/Sensors/sensor.c, line: 18
I (9712) SENSOR: 🌡️  Temperature: 35.1°C
I (9712) SENSOR: 💧 Humidity: 76.5%
I (9712) SENSOR: ✅ Sensor status check from file: /project/components/Sensors/sensor.c, line: 30
I (9712) SENSOR: 📈 All sensors operating normally
I (9712) LAB7-1: ----------------------------
I (12712) SENSOR: 📊 Reading sensor data from file: /project/components/Sensors/sensor.c, line: 18
I (12712) SENSOR: 🌡️  Tempe rature: 27.7°C
I (12712) SENSOR: 💧 Humidity: 78.9%
I (12712) SENSOR: ✅ Sensor status check from file: /project/components/Sensors/sensor.c, line: 30
I (12712) SENSOR: 📈 All sensors operating normally
I (12712) LAB7-1: ----------------------------
I (15712) SENSOR: 📊 Reading sensor data from file: /project/components/Sensors/sensor.c, line: 18
I (15712) SENSOR: 🌡️  Te mperature: 30.9°C
I (15712) SENSOR: 💧 Humidity: 82.5%
I (15712) SENSOR: ✅ Sensor status check from file: /project/components/Sensors/sensor.c, line: 30
I (15712) SENSOR: 📈 All sensors operating normally
