/******************************************************************************
 * @file    IoHwAb_SpeedSensor.c
 * @brief   Triển khai các API phần cứng trừu tượng cho cảm biến tốc độ
 *
 * @details File này chứa các hàm để khởi tạo và đọc giá trị từ cảm biến tốc độ.
 *          Các API trong file này cung cấp giao diện phần cứng trừu tượng để 
 *          tương tác với cảm biến tốc độ thông qua MCAL. Bao gồm hàm khởi tạo 
 *          cấu hình cảm biến và đọc giá trị tốc độ từ ADC.
 *
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/
#include "IoHwAb_SpeedSensor.h"
#include "MCAL/Adc.h"   // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 * @brief   Biến cấu hình hiện tại của cảm biến tốc độ
 *
 * @details Biến toàn cục này lưu trữ cấu hình hiện tại của cảm biến tốc độ, bao gồm
 *          kênh ADC và giá trị tốc độ tối đa mà cảm biến có thể đọc. Biến này 
 *          được khởi tạo trong hàm `IoHwAb_SpeedSensor_Init` và được dùng trong các
 *          hàm khác để truy cập cấu hình của cảm biến tốc độ.
 ******************************************************************************/
static SpeedSensor_ConfigType SpeedSensor_CurrentConfig;

/******************************************************************************
 * @brief   Hàm khởi tạo cảm biến tốc độ với cấu hình
 *
 * @details Hàm này nhận vào cấu trúc cấu hình cảm biến tốc độ và thiết lập cảm biến
 *          dựa trên các thông số cấu hình được cung cấp. Cấu hình sẽ được lưu vào
 *          biến toàn cục `SpeedSensor_CurrentConfig`. Hàm cũng sẽ khởi tạo kênh ADC
 *          thông qua API MCAL dựa trên kênh ADC được xác định trong cấu hình.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `SpeedSensor_ConfigType` chứa cấu hình cảm biến
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_SpeedSensor_Init(const SpeedSensor_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_SpeedSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tốc độ vào biến toàn cục
    SpeedSensor_CurrentConfig.SpeedSensor_Channel = ConfigPtr->SpeedSensor_Channel;
    SpeedSensor_CurrentConfig.SpeedSensor_MaxValue = ConfigPtr->SpeedSensor_MaxValue;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = ConfigPtr->SpeedSensor_Channel;
    Adc_Init(&adcConfig);

    // In ra thông tin cấu hình cảm biến tốc độ
    printf("Speed Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", SpeedSensor_CurrentConfig.SpeedSensor_Channel);
    printf(" - Max Speed Value: %d km/h\n", SpeedSensor_CurrentConfig.SpeedSensor_MaxValue);

    return E_OK;
}

/******************************************************************************
 * @brief   Hàm đọc giá trị từ cảm biến tốc độ
 *
 * @details Hàm này đọc giá trị thô từ ADC của cảm biến tốc độ và chuyển đổi nó 
 *          thành giá trị tốc độ trong đơn vị km/h. Quá trình chuyển đổi sử dụng 
 *          giá trị tối đa của cảm biến từ cấu hình để tính toán giá trị tốc độ thực tế.
 *
 * @param   SpeedValue - Con trỏ lưu trữ giá trị tốc độ đọc được từ cảm biến (km/h)
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_SpeedSensor_Read(float* SpeedValue) {
    if (SpeedValue == NULL) {
        return E_NOT_OK;  // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị từ kênh ADC
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(SpeedSensor_CurrentConfig.SpeedSensor_Channel, &adcValue) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang tốc độ (giả lập)
    *SpeedValue = ((float)adcValue / 1023.0f) * SpeedSensor_CurrentConfig.SpeedSensor_MaxValue;

    // In ra giá trị tốc độ
    printf("Reading Speed Sensor (ADC Channel %d): Speed = %.2f km/h\n",
           SpeedSensor_CurrentConfig.SpeedSensor_Channel, *SpeedValue);

    return E_OK;
}
