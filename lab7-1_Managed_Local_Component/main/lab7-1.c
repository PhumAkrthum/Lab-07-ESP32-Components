#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor.h"
#include "display.h" // 👈 เพิ่มส่วนนี้เพื่อเรียกใช้ display

static const char *TAG = "LAB7-1";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 7-1: Local Component Demo Started");
    
    // เรียกใช้ฟังก์ชันจาก local component
    sensor_init();
    display_init(); // 👈 เพิ่มส่วนนี้เพื่อเริ่มต้น Display

    while(1) {
        // อ่านค่าจากเซ็นเซอร์
        sensor_read_data();
        sensor_check_status();
        
        // ส่งข้อมูลไปแสดงผลที่ Display
        float temp = read_temperature(); // สมมติว่ามีฟังก์ชันนี้ใน sensor.h
        float humid = read_humidity();   // สมมติว่ามีฟังก์ชันนี้ใน sensor.h
        display_show_data(temp, humid); // 👈 เพิ่มส่วนนี้เพื่อแสดงผล
        
        ESP_LOGI(TAG, "----------------------------");
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}