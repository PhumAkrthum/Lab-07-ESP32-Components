#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor.h"
#include "display.h"

static const char *TAG = "LAB7-2";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 7-2: Managed Component from GitHub URL Demo Started");
    ESP_LOGI(TAG, "📥 Using components from: https://github.com/APPLICATIONS-OF-MICROCONTROLLERS/Lab7_Components");
    
    // Initialize modules
    sensor_init();
    display_init();
    
    display_show_message("System Starting...");
    
    int counter = 0;
    
    while (1) {
        ESP_LOGI(TAG, "=== Loop %d ===", counter++);
        
        // Clear display every loop
        display_clear_screen();
        
        // Read sensor data
        sensor_read_data();
        
        // Show data on display
        float temp = 25.5 + (float)(counter % 10);
        float humid = 60.0 + (float)(counter % 20);
        display_show_data(temp, humid);
        
        // Check sensor status every 3 loops
        if (counter % 3 == 0) {
            sensor_check_status();
            display_show_message("Status Check Complete");
        }
        
        vTaskDelay(pdMS_TO_TICKS(2000)); // 2 seconds delay
    }
}