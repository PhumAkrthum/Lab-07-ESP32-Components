#### 1.7 สร้างไฟล์ `lab7-2_Managed_url_Component/README.md`
```markdown
# Lab 7-2: Managed Component from GitHub URL Demo

## คำอธิบาย
การทดลองนี้แสดงการใช้งาน managed component จาก GitHub Repository
ใช้ `Sensors` component จาก https://github.com/APPLICATIONS-OF-MICROCONTROLLERS/Lab7_Components

## ผลลัพธ์ที่คาดหวัง
- แสดงข้อความการเริ่มต้น sensor จาก GitHub component
- แสดงข้อมูล temperature และ humidity ทุก 4 วินาที
- แสดงสถานะการทำงานของ sensor
- แสดงแหล่งที่มาของ component (GitHub Repository)

## ความแตกต่างจาก Lab 7-1
- Lab 7-1: ใช้ local component (ในเครื่อง)
- Lab 7-2: ใช้ managed component จาก GitHub URL

## การใช้งาน
1. เข้าไปในโฟลเดอร์ lab7-2_Managed_url_Component
2. รันคำสั่ง `idf.py build` (จะดาวน์โหลด component จาก GitHub อัตโนมัติ)
3. ทดสอบด้วย QEMU


# ผลการทดสอบ ตอนยังไม่มี display 

root@b35f767591b4:/project/lab7-2_Managed_url_Component# idf.py qemu monitor
Running qemu on socket://localhost:5555
Adding "qemu"'s dependency "all" to list of commands with default set of options.
Executing action: all (aliases: build)
Running ninja in directory /project/lab7-2_Managed_url_Component/build
Executing "ninja all"...
[1/4] cd /project/lab7-2_Managed_url_Component/build/esp...n /project/lab7-2_Managed_url_Component/build/lab7-2.bi 
lab7-2.bin binary size 0x27dd0 bytes. Smallest app partition is 0x100000 bytes. 0xd8230 bytes (84%) free.
[1/1] cd /project/lab7-2_Managed_url_Component/build/boo...-2_Managed_url_Component/build/bootloader/bootloader.bi 
Bootloader binary size 0x66a0 bytes. 0x960 bytes (8%) free.
[4/4] Completed 'bootloader'Executing action: qemu
Generating flash image: /project/lab7-2_Managed_url_Component/build/qemu_flash.bin
esptool.py --chip=esp32 merge_bin --output=/project/lab7-2_Managed_url_Component/build/qemu_flash.bin --fill-flash-size=2MB --flash_mode dio --flash_freq 40m --flash_size 2MB 0x1000 bootloader/bootloader.bin 0x10000 lab7-2.bin 0x8000 partition_table/partition-table.bin
esptool.py v4.9.0
SHA digest in image updated
Wrote 0x200000 bytes to file /project/lab7-2_Managed_url_Component/build/qemu_flash.bin, ready to flash to offset 0x0
Generating efuse image: /project/lab7-2_Managed_url_Component/build/qemu_efuse.bin
Running qemu (bg): qemu-system-xtensa -M esp32 -m 4M -drive file=/project/lab7-2_Managed_url_Component/build/qemu_flash.bin,if=mtd,format=raw -drive file=/project/lab7-2_Managed_url_Component/build/qemu_efuse.bin,if=none,format=raw,id=efuse -global driver=nvram.esp32.efuse,property=drive,value=efuse -global driver=timer.esp32.timg,property=wdt_disable,value=true -nic user,model=open_eth -nographic -serial tcp::5555,server
Executing action: monitor
Running idf_monitor in directory /project/lab7-2_Managed_url_Component
Executing "/opt/esp/python_env/idf6.0_py3.12_env/bin/python /opt/esp/idf/tools/idf_monitor.py -p socket://localhost:5555 -b 115200 --toolchain-prefix xtensa-esp32-elf- --target esp32 --revision 0 /project/lab7-2_Managed_url_Component/build/lab7-2.elf /project/lab7-2_Managed_url_Component/build/bootloader/bootloader.elf -m '/opt/esp/python_env/idf6.0_py3.12_env/bin/python' '/opt/esp/idf/tools/idf.py'"...
--- esp-idf-monitor 1.6.2 on socket://localhost:5555 115200
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H
I (10220) LAB7-2: 📋 Reading #2 from GitHub Component

I (10220) SENSOR: 📊 Reading sensor data from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 18

I (10220) SENSOR: 🌡️  Temperature: 25.6 °C

I (10220) SENSOR: 💧 Humidity: 99.3%

I (10220) SENSOR: ✅ Sensor status check from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 30

I (10220) SENSOR: 📈 All sensors operating normally

I (10220) LAB7-2: � Component Source: GitHub Repository

I (10220) LAB7-2: ==========================================

I (14220) LAB7-2: 📋 Reading #3 from GitHub Component

I (14220) SENSOR: 📊 Reading sensor data from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 18

I (14220) SENSOR: 🌡️   Temperature: 30.9°C

I (14220) SENSOR: 💧 Humidity: 81.8%

I (14220) SENSOR: ✅ Sensor status check from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 30I (14220) SENSOR: 📈 All sensors operating normally

I (14220) LAB7-2: � Component Source: GitHub Repository

I (14220) LAB7-2: ==========================================

I (18220) LAB7-2: 📋 Reading #4 from GitHub Component

I (18220) SENSOR: 📊 Reading sensor data from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 18I (18220) SENSOR: 🌡️  Tem perature: 27.6°C

I (18220) SENSOR: 💧 Humidity: 85.0%

I (18220) SENSOR: ✅ Sensor status check from file: ./managed_components/lab7_components/Sensors/sensor.c, line:
 30I (18220) SENSOR: 📈 All sensors operating normally

I (18220) LAB7-2: � Component Source: GitHub Repository

I (18220) LAB7-2: ==========================================








## โจทย์ท้าทาย

### 1. สร้าง  component ชื่อ `Display` โดย นำไฟล์ `display.c` และ `display.h` จากใบงานที่ 6 มาใช้ 

สิ่งที่ต้องมีใน display component
1. ไฟล์ `CMakeLists.txt` 
2. ไฟล์ `display.h`
3. ไฟล์ `display.c`


### 2. นำโค้ดจาก main.c ในใบงานที่ 6 มาใช้ แล้ว build พร้อมทดสอบ

ให้ผลลักษณะเดียวกับ component แบบ local หรือไม่

ตอบ ความเหมือน
การทำงาน: โค้ดจะทำงานเหมือนกัน คือ มีการเริ่มต้นโมดูล Sensor และ Display, แสดงข้อความเริ่มต้น,มีการอ่านค่าจำลอง (dummy) และส่งไปแสดงผลที่ Display รวมถึงมีการตรวจสอบสถานะเป็นระยะๆ

Log Output: ผลลัพธ์ที่ปรากฏใน Serial Monitor จะมีลักษณะคล้ายกันเพราะทั้งสองโปรเจกต์ใช้ฟังก์ชัน ESP_LOGI ในการแสดงผลเหมือนกัน

ความแตกต่าง
ที่มาของ Component: 

Local Component: โค้ดสำหรับ Sensor และ Display อยู่ในโฟลเดอร์ components ภายในโปรเจกต์เดียวกัน

Managed Component (จาก URL): โค้ดถูกดึงมาจากการอ้างอิง URL ของ Git Repository ในไฟล์ idf_component.yml และถูกเก็บไว้ในโฟลเดอร์ managed_components ที่สร้างขึ้นอัตโนมัติ

การแก้ไขโค้ด: หากต้องการแก้ไขโค้ดของ component:

Local Component: สามารถแก้ไขไฟล์ sensor.c และ display.c ได้โดยตรง

Managed Component: ไม่สามารถแก้ไขไฟล์ที่อยู่ใน managed_components ได้โดยตรง แต่ต้องแก้ไขที่ Git Repository ต้นทาง แล้วจึงสั่งให้โปรเจกต์อัปเดตใหม่

ไฟล์ CMake: ในโปรเจกต์แบบ Local Component จะต้องมีการระบุ REQUIRES ใน CMakeLists.txt เพื่อเชื่อมโยง component เข้าด้วยกัน ส่วน Managed Component จะใช้ไฟล์ idf_component.yml เพื่อจัดการการพึ่งพา (dependencies) โดยอัตโนมัติ

ตอบ ผลลัพธ์ทั้งหมดเมื่อใส่ display 

root@b35f767591b4:/project/lab7-2_Managed_url_Component# idf.py qemu monitor
Running qemu on socket://localhost:5555
Adding "qemu"'s dependency "all" to list of commands with default set of options.
Executing action: all (aliases: build)
Running ninja in directory /project/lab7-2_Managed_url_Component/build
Executing "ninja all"...
[1/4] cd /project/lab7-2_Managed_url_Component/build/es... /project/lab7-2_Managed_url_Component/build/lab7-2.bin 
lab7-2.bin binary size 0x280c0 bytes. Smallest app partition is 0x100000 bytes. 0xd7f40 bytes (84%) free.
[1/1] cd /project/lab7-2_Managed_url_Component/build/bo...2_Managed_url_Component/build/bootloader/bootloader.bin 
Bootloader binary size 0x66a0 bytes. 0x960 bytes (8%) free.
[4/4] Completed 'bootloader'Executing action: qemu
Generating flash image: /project/lab7-2_Managed_url_Component/build/qemu_flash.bin
esptool.py --chip=esp32 merge_bin --output=/project/lab7-2_Managed_url_Component/build/qemu_flash.bin --fill-flash-size=2MB --flash_mode dio --flash_freq 40m --flash_size 2MB 0x1000 bootloader/bootloader.bin 0x10000 lab7-2.bin 0x8000 partition_table/partition-table.bin
esptool.py v4.9.0
SHA digest in image updated
Wrote 0x200000 bytes to file /project/lab7-2_Managed_url_Component/build/qemu_flash.bin, ready to flash to offset 0x0
Generating efuse image: /project/lab7-2_Managed_url_Component/build/qemu_efuse.bin
Running qemu (bg): qemu-system-xtensa -M esp32 -m 4M -drive file=/project/lab7-2_Managed_url_Component/build/qemu_flash.bin,if=mtd,format=raw -drive file=/project/lab7-2_Managed_url_Component/build/qemu_efuse.bin,if=none,format=raw,id=efuse -global driver=nvram.esp32.efuse,property=drive,value=efuse -global driver=timer.esp32.timg,property=wdt_disable,value=true -nic user,model=open_eth -nographic -serial tcp::5555,server
Executing action: monitor
Running idf_monitor in directory /project/lab7-2_Managed_url_Component
Executing "/opt/esp/python_env/idf6.0_py3.12_env/bin/python /opt/esp/idf/tools/idf_monitor.py -p socket://localhost:5555 -b 115200 --toolchain-prefix xtensa-esp32-elf- --target esp32 --revision 0 /project/lab7-2_Managed_url_Component/build/lab7-2.elf /project/lab7-2_Managed_url_Component/build/bootloader/bootloader.elf -m '/opt/esp/python_env/idf6.0_py3.12_env/bin/python' '/opt/esp/idf/tools/idf.py'"...
--- esp-idf-monitor 1.6.2 on socket://localhost:5555 115200
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H
I (8583) LAB7-2: === Loop 1 ===
I (8583) DISPLAY: 🧹 Screen cleared from file: ./managed_components/lab7_components/Display/display.c, line: 28
I (8583) DISPLAY: ✨ Display ready for new content
I (8583) SENSOR: 📊 Reading sensor data from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 18
I (8583) SENSOR: 🌡️  Temperature: 26.5°C
I (8583) SENSOR: 💧 Humidity: 98.4%
I (8583) DISPLAY: 📊 Data display from file: ./managed_components/lab7_components/Display/display.c, line: 21
I (8583) DISPLAY: 📈 Value 1: 27.50
I (8583) DISPLAY: 📉 Value 2: 62.00
I (10583) LAB7-2: === Loop 2 ===
I (10583) DISPLAY: 🧹 Screen cleared from file: ./managed_components/lab7_components/Display/display.c, line: 28
I (10583) DISPLAY: ✨ Display ready for new content
I (10583) SENSOR: 📊 Reading sensor data from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 18
I (10583) SENSOR: 🌡️  Tempera ture: 27.5°C
I (10583) SENSOR: 💧 Humidity: 97.2%
I (10583) DISPLAY: 📊 Data display from file: ./managed_components/lab7_components/Display/display.c, line: 21
I (10583) DISPLAY: 📈 Value 1: 28.50
I (10583) DISPLAY: 📉 Value 2: 63.00
I (10583) SENSOR: ✅ Sensor status check from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 30
I (10583) SENSOR: 📈 All sensors operating normally
I (10583) DISPLAY: 📢 Displaying from file: ./managed_components/lab7_components/Display/display.c, line: 15
I (10583) DISPLAY: 📺 Message: Status Check Complete
I (12583) LAB7-2: === Loop 3 ===
I (12583) DISPLAY: 🧹 Screen cleared from file: ./managed_components/lab7_components/Display/display.c, line: 28
I (12583) DISPLAY: ✨ Display ready for new content
I (12583) SENSOR: 📊 Reading sensor data from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 18
I (12583) SENSOR: 🌡️  Temperature: 34.9°C
I (12583) SENSOR: 💧 Humidity: 65.0%
I (12583) DISPLAY: 📊 Data display from file: ./managed_components/lab7_components/Display/display.c, line: 21
I (12583) DISPLAY: 📈 Value 1: 29.50
I (12583) DISPLAY: 📉 Value 2: 64.00
I (14583) LAB7-2: === Loop 4 ===
I (14583) DISPLAY: 🧹 Screen cleared from file: ./managed_components/lab7_components/Display/display.c, line: 28
I (14583) DISPLAY: ✨ Display ready for new content
I (14583) SENSOR: 📊 Reading sensor data from file: ./managed_components/lab7_components/Sensors/sensor.c, line: 18
I (14583) SENSOR: 🌡️  Temperat ure: 30.8°C
I (14583) SENSOR: 💧 Humidity: 68.1%
I (14583) DISPLAY: 📊 Data display from file: ./managed_components/lab7_components/Display/display.c, line: 21
I (14583) DISPLAY: 📈 Value 1: 30.50
I (14583) DISPLAY: 📉 Value 2: 65.00