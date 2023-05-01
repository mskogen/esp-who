#include "wifi.h"
#include "http_server.h"
#include "camera.h"
#include "esp_log.h"

const static char TAG[] = "app_main";

void app_main()
{
    // Initialize Camera on ESP-S3-EYE
    if(ESP_OK != init_camera()) {
        return;
    }

    // // Establish WIFI connection
    app_wifi_main();
    ESP_LOGI(TAG, "WiFi connected");

    // Start HTTP video stream server
    startCameraServer();

    while (1)
    {
        // Everything is setup so now we just loop forever
        vTaskDelay(5000 / portTICK_RATE_MS);
    }
}
