/******************************************************************************
 * @file    Mcal_Config.c
 * @brief   Cấu hình và khởi tạo các mô-đun trong MCAL (Microcontroller Abstraction Layer)
 *
 * @details File này chứa các hàm để cấu hình và khởi tạo toàn bộ các mô-đun trong MCAL, 
 *          bao gồm ADC, DIO, PWM, và CAN. Các hàm này được gọi để thiết lập các cấu hình 
 *          cơ bản cho từng mô-đun, chuẩn bị hệ thống cho các tác vụ cần điều khiển và 
 *          truyền thông vi điều khiển. Mỗi hàm cấu hình mô-đun sẽ in ra thông tin quá trình 
 *          để xác nhận rằng quá trình khởi tạo đã hoàn tất.
 *
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#include "Mcal_Config.h"
#include "Adc.h"
#include "Dio.h"
#include "Pwm.h"
#include "Can.h"

/******************************************************************************
 * @brief   Cấu hình và khởi tạo toàn bộ MCAL
 *
 * @details Hàm này thực hiện khởi tạo và cấu hình cho toàn bộ các mô-đun trong MCAL, 
 *          bao gồm ADC, DIO, PWM, và CAN. Mỗi mô-đun được cấu hình bằng cách gọi
 *          các hàm khởi tạo tương ứng. Hàm này in ra thông tin về quá trình khởi tạo
 *          để xác nhận rằng tất cả mô-đun MCAL đã được thiết lập đúng cách.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Mcal_ConfigInit(void) {
    printf("Initializing MCAL configuration...\n");

    // Khởi tạo và cấu hình từng mô-đun
    Adc_ConfigInit();
    Dio_ConfigInit();
    Pwm_ConfigInit();
    Can_ConfigInit();

    printf("MCAL configuration complete.\n");
}

/******************************************************************************
 * @brief   Cấu hình và khởi tạo ADC
 *
 * @details Hàm này khởi tạo mô-đun ADC bằng cách gọi hàm `Adc_Init`. Hàm in ra
 *          thông tin xác nhận quá trình khởi tạo ADC để đảm bảo rằng cấu hình
 *          đã hoàn tất trước khi sử dụng ADC trong hệ thống.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Adc_ConfigInit(void) {
    printf("Configuring ADC...\n");
    Adc_Init();  // Gọi hàm khởi tạo ADC
    printf("ADC configuration complete.\n");
}

/******************************************************************************
 * @brief   Cấu hình và khởi tạo DIO
 *
 * @details Hàm này khởi tạo mô-đun DIO bằng cách gọi hàm `Dio_Init`. Sau khi cấu hình, 
 *          hàm in ra thông tin xác nhận để đảm bảo rằng DIO đã sẵn sàng cho các thao tác
 *          đầu vào và đầu ra số trong hệ thống.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Dio_ConfigInit(void) {
    printf("Configuring DIO...\n");
    Dio_Init();  // Gọi hàm khởi tạo DIO
    printf("DIO configuration complete.\n");
}

/******************************************************************************
 * @brief   Cấu hình và khởi tạo PWM
 *
 * @details Hàm này khởi tạo mô-đun PWM bằng cách gọi hàm `Pwm_Init`. Quá trình khởi tạo
 *          được xác nhận bằng cách in ra thông tin cấu hình hoàn tất, đảm bảo rằng
 *          PWM đã sẵn sàng cho các thao tác điều khiển xung độ rộng.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Pwm_ConfigInit(void) {
    printf("Configuring PWM...\n");
    Pwm_Init();  // Gọi hàm khởi tạo PWM
    printf("PWM configuration complete.\n");
}

/******************************************************************************
 * @brief   Cấu hình và khởi tạo CAN
 *
 * @details Hàm này khởi tạo mô-đun CAN bằng cách gọi hàm `Can_Init`. Quá trình 
 *          khởi tạo CAN được xác nhận qua thông báo để đảm bảo rằng hệ thống 
 *          truyền thông CAN đã được thiết lập và sẵn sàng hoạt động.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Can_ConfigInit(void) {
    printf("Configuring CAN...\n");
    Can_Init();  // Gọi hàm khởi tạo CAN
    printf("CAN configuration complete.\n");
}
