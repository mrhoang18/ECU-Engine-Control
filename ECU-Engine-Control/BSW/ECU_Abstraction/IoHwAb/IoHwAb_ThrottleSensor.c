/******************************************************************************
 * @file    IoHwAb_ThrottleSensor.c
 * @brief   Triển khai các API phần cứng trừu tượng cho cảm biến bàn đạp ga
 *
 * @details File này chứa các hàm để khởi tạo và đọc giá trị từ cảm biến bàn đạp ga.
 *          Các API trong file này cung cấp giao diện phần cứng trừu tượng để 
 *          tương tác với cảm biến bàn đạp ga thông qua MCAL. Bao gồm hàm khởi tạo 
 *          cấu hình cảm biến và đọc giá trị bàn đạp ga từ ADC. Nếu cần, có thể 
 *          sử dụng DIO để kiểm tra trạng thái của cảm biến.
 *
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#include "IoHwAb_ThrottleSensor.h"
#include "MCAL/Adc.h"   // Gọi API từ MCAL để đọc giá trị từ ADC
#include "MCAL/Dio.h"   // Gọi API từ MCAL để kiểm tra trạng thái DIO nếu cần
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 * @brief   Kênh ADC của cảm biến bàn đạp ga
 *
 * @details Định nghĩa kênh ADC mà cảm biến bàn đạp ga sử dụng để đọc giá trị.
 *          Trong trường hợp này, giả sử cảm biến sử dụng kênh ADC 0.
 ******************************************************************************/
#define THROTTLE_SENSOR_ADC_CHANNEL 0  // Kênh ADC cho cảm biến bàn đạp ga

/******************************************************************************
 * @brief   Giá trị thô tối thiểu và tối đa của cảm biến bàn đạp ga
 *
 * @details Định nghĩa phạm vi giá trị thô mà cảm biến bàn đạp ga có thể trả về.
 *          Các giá trị này được lấy trực tiếp từ ADC và cần chuyển đổi để sử dụng
 *          trong ứng dụng.
 ******************************************************************************/
#define THROTTLE_SENSOR_MIN_RAW_VALUE 0    // Giá trị ADC tối thiểu cho cảm biến bàn đạp ga
#define THROTTLE_SENSOR_MAX_RAW_VALUE 1023 // Giá trị ADC tối đa cho cảm biến bàn đạp ga

/******************************************************************************
 * @brief   Phạm vi giá trị của bàn đạp ga sau khi chuyển đổi
 *
 * @details Định nghĩa phạm vi giá trị sau khi chuyển đổi từ giá trị thô ADC. 
 *          Giá trị 0.0f đại diện cho trạng thái bàn đạp ga hoàn toàn thả, 
 *          và 1.0f đại diện cho trạng thái bàn đạp ga hoàn toàn nhấn.
 ******************************************************************************/
#define THROTTLE_POSITION_MIN 0.0f  // Giá trị khi bàn đạp ga hoàn toàn thả 
#define THROTTLE_POSITION_MAX 1.0f  // Giá trị khi bàn đạp ga hoàn toàn nhấn 

/******************************************************************************
 * @brief   Biến cấu hình hiện tại của cảm biến bàn đạp ga
 *
 * @details Biến toàn cục này lưu trữ cấu hình hiện tại của cảm biến bàn đạp ga,
 *          bao gồm kênh ADC được sử dụng để đọc giá trị từ cảm biến. Biến này 
 *          được khởi tạo trong hàm `IoHwAb_ThrottleSensor_Init` và được dùng trong
 *          các hàm khác để truy cập cấu hình của cảm biến bàn đạp ga.
 ******************************************************************************/
static ThrottleSensor_ConfigType ThrottleSensor_CurrentConfig;

/******************************************************************************
 * @brief   Hàm khởi tạo cảm biến bàn đạp ga với cấu hình
 *
 * @details Hàm này nhận vào cấu trúc cấu hình cảm biến bàn đạp ga và thiết lập
 *          cảm biến dựa trên cấu hình được cung cấp. Hàm sẽ lưu trữ cấu hình vào
 *          biến toàn cục `ThrottleSensor_CurrentConfig`, sau đó khởi tạo kênh ADC
 *          thông qua API MCAL. Ngoài ra, nếu cần, hàm sẽ khởi tạo DIO.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `ThrottleSensor_ConfigType` chứa cấu hình cảm biến
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_ThrottleSensor_Init(const ThrottleSensor_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_ThrottleSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến bàn đạp ga vào biến toàn cục
    ThrottleSensor_CurrentConfig.ThrottleSensor_Channel = ConfigPtr->ThrottleSensor_Channel;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = ThrottleSensor_CurrentConfig.ThrottleSensor_Channel;
    Adc_Init(&adcConfig);

    // Gọi API từ MCAL để khởi tạo DIO nếu cần
    Dio_Init();

    // In ra thông tin cấu hình của cảm biến bàn đạp ga
    printf("Throttle Sensor Initialized with ADC Channel %d\n", ThrottleSensor_CurrentConfig.ThrottleSensor_Channel);

    return E_OK;
}

/******************************************************************************
 * @brief   Hàm đọc giá trị bàn đạp ga
 *
 * @details Hàm này đọc giá trị thô từ ADC của cảm biến bàn đạp ga, sau đó chuyển đổi
 *          giá trị này thành giá trị bàn đạp ga trong phạm vi từ 0.0 (hoàn toàn thả)
 *          đến 1.0 (hoàn toàn nhấn). Hàm cũng kiểm tra để đảm bảo giá trị nằm trong
 *          phạm vi hợp lệ và giới hạn nếu cần thiết.
 *
 * @param   ThrottlePosition - Con trỏ lưu trữ giá trị bàn đạp ga sau khi chuyển đổi
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_ThrottleSensor_Read(float* ThrottlePosition) {
    if (ThrottlePosition == NULL) {
        return E_NOT_OK;  // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị ADC từ kênh cảm biến bàn đạp ga
    uint16_t raw_adc_value = 0;
    if (Adc_ReadChannel(ThrottleSensor_CurrentConfig.ThrottleSensor_Channel, &raw_adc_value) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị thô của ADC sang phạm vi từ 0.0 đến 1.0
    *ThrottlePosition = ((float)(raw_adc_value - THROTTLE_SENSOR_MIN_RAW_VALUE) / 
                        (THROTTLE_SENSOR_MAX_RAW_VALUE - THROTTLE_SENSOR_MIN_RAW_VALUE));

    // Đảm bảo giá trị nằm trong phạm vi từ 0.0 đến 1.0
    if (*ThrottlePosition < THROTTLE_POSITION_MIN) {
        *ThrottlePosition = THROTTLE_POSITION_MIN;
    } else if (*ThrottlePosition > THROTTLE_POSITION_MAX) {
        *ThrottlePosition = THROTTLE_POSITION_MAX;
    }

    // In ra giá trị bàn đạp ga sau khi chuyển đổi
    printf("Reading Throttle Sensor (ADC Channel %d): Throttle Position = %.2f\n",
           ThrottleSensor_CurrentConfig.ThrottleSensor_Channel, *ThrottlePosition);

    return E_OK;
}
