#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"



void codeForTask1_core( void * parameter )
{
   for (;;)
   {
      printf("codeForTask1 is running on Core: ");
      printf("%d\n", xPortGetCoreID());
      vTaskDelay(2000 / portTICK_PERIOD_MS);
   }

}
void codeForTask2_core( void * parameter )
{
   for (;;)
   {
      printf("codeForTask2 is running on Core: ");
      printf("%d\n", xPortGetCoreID());
      vTaskDelay(2000 / portTICK_PERIOD_MS);
   }

}

void app_main(void)
{
	   xTaskCreatePinnedToCore(codeForTask1_core, "core0", 1024*2, NULL, 2, NULL, 0);
	   xTaskCreatePinnedToCore(codeForTask2_core, "core1", 1024*2, NULL, 2, NULL, 1);
}

