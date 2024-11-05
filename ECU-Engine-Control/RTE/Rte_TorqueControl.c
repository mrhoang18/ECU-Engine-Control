/******************************************************************************
 * @file    Rte_TorqueControl.c
 * @brief   Module cung cấp các API RTE cho hệ thống điều khiển mô-men xoắn.
 *
 * @details Module này triển khai các API RTE để đọc và ghi dữ liệu từ các cảm biến 
 *          và bộ điều khiển mô-men xoắn. Nó bao gồm các API để khởi tạo, đọc giá trị 
 *          từ cảm biến bàn đạp ga, tốc độ, tải trọng, và mô-men xoắn thực tế, cũng như
 *          ghi mô-men xoắn yêu cầu tới bộ điều khiển động cơ.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  Tong Xuan Hoang
 ******************************************************************************/

#include "Rte_TorqueControl.h"
#include "IoHwAb_ThrottleSensor.h"  // API IoHwAb để đọc cảm biến bàn đạp ga
#include "IoHwAb_SpeedSensor.h"     // API IoHwAb để đọc cảm biến tốc độ
#include "IoHwAb_LoadSensor.h"      // API IoHwAb để đọc cảm biến tải trọng
#include "IoHwAb_TorqueSensor.h"    // API IoHwAb để đọc mô-men xoắn thực tế
#include "IoHwAb_MotorDriver.h"     // API IoHwAb để điều khiển mô-men xoắn động cơ
#include "Std_Types.h"

/******************************************************************************
 * @brief   API đọc dữ liệu từ cảm biến bàn đạp ga
 *
 * @details Hàm này đọc giá trị vị trí bàn đạp ga từ cảm biến thông qua API của 
 *          IoHwAb. Kiểm tra nếu con trỏ đầu vào là NULL, trả về lỗi.
 *
 * @param   ThrottlePosition - Con trỏ để lưu trữ giá trị vị trí bàn đạp ga đọc được
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpThrottleSensor_ThrottlePosition(float* ThrottlePosition) {
    if (ThrottlePosition == NULL) {
        return E_NOT_OK;  // Trả về lỗi nếu con trỏ NULL
    }
    return IoHwAb_ThrottleSensor_Read(ThrottlePosition);  // Gọi API từ IoHwAb để đọc giá trị từ cảm biến
}

/******************************************************************************
 * @brief   API đọc dữ liệu từ cảm biến tốc độ
 *
 * @details Hàm này đọc giá trị tốc độ xe từ cảm biến thông qua API của IoHwAb.
 *          Kiểm tra nếu con trỏ đầu vào là NULL, trả về lỗi.
 *
 * @param   Speed - Con trỏ để lưu trữ giá trị tốc độ đọc được
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpSpeedSensor_Speed(float* Speed) {
    if (Speed == NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_SpeedSensor_Read(Speed);  // Gọi API từ IoHwAb để đọc giá trị từ cảm biến tốc độ
}

/******************************************************************************
 * @brief   API đọc dữ liệu từ cảm biến tải trọng
 *
 * @details Hàm này đọc giá trị tải trọng từ cảm biến thông qua API của IoHwAb.
 *          Kiểm tra nếu con trỏ đầu vào là NULL, trả về lỗi.
 *
 * @param   LoadWeight - Con trỏ để lưu trữ giá trị tải trọng đọc được
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpLoadSensor_LoadWeight(float* LoadWeight) {
    if (LoadWeight == NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_LoadSensor_Read(LoadWeight);  // Gọi API từ IoHwAb để đọc giá trị từ cảm biến tải trọng
}

/******************************************************************************
 * @brief   API đọc mô-men xoắn thực tế từ cảm biến mô-men xoắn
 *
 * @details Hàm này đọc giá trị mô-men xoắn thực tế từ cảm biến thông qua API của IoHwAb.
 *          Kiểm tra nếu con trỏ đầu vào là NULL, trả về lỗi.
 *
 * @param   ActualTorque - Con trỏ để lưu trữ giá trị mô-men xoắn thực tế đọc được
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpTorqueSensor_ActualTorque(float* ActualTorque) {
    if (ActualTorque == NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_TorqueSensor_Read(ActualTorque);  // Gọi API từ IoHwAb để đọc mô-men xoắn thực tế
}

/******************************************************************************
 * @brief   API ghi mô-men xoắn yêu cầu tới bộ điều khiển động cơ
 *
 * @details Hàm này ghi giá trị mô-men xoắn yêu cầu tới bộ điều khiển động cơ 
 *          thông qua API của IoHwAb.
 *
 * @param   TorqueValue - Giá trị mô-men xoắn yêu cầu
 * @return  Std_ReturnType - Trả về E_OK nếu ghi thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Write_PpMotorDriver_SetTorque(float TorqueValue) {
    return IoHwAb_MotorDriver_SetTorque(TorqueValue);  // Gọi API từ IoHwAb để ghi mô-men xoắn yêu cầu tới động cơ
}

/******************************************************************************
 * @brief   API khởi tạo cảm biến bàn đạp ga
 *
 * @details Hàm này khởi tạo cấu hình cho cảm biến bàn đạp ga và gọi API khởi tạo
 *          từ IoHwAb để thiết lập cảm biến bàn đạp ga.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpThrottleSensor_Init(void) {
    ThrottleSensor_ConfigType throttleSensorConfig = {
        .ThrottleSensor_Channel = 0  // Kênh ADC cho cảm biến bàn đạp ga
    };
    return IoHwAb_ThrottleSensor_Init(&throttleSensorConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến bàn đạp ga
}

/******************************************************************************
 * @brief   API khởi tạo cảm biến tốc độ
 *
 * @details Hàm này thiết lập cấu hình cho cảm biến tốc độ và gọi API khởi tạo
 *          từ IoHwAb để khởi tạo cảm biến tốc độ.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpSpeedSensor_Init(void) {
    // Cấu hình cho cảm biến tốc độ
    SpeedSensor_ConfigType speedSensorConfig = {
        .SpeedSensor_Channel = 1,        // Kênh ADC cho cảm biến tốc độ
        .SpeedSensor_MaxValue = 200      // Tốc độ tối đa giả lập (200 km/h)
    };
    return IoHwAb_SpeedSensor_Init(&speedSensorConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tốc độ
}

/******************************************************************************
 * @brief   API khởi tạo cảm biến tải trọng
 *
 * @details Hàm này thiết lập cấu hình cho cảm biến tải trọng và gọi API khởi tạo
 *          từ IoHwAb để khởi tạo cảm biến tải trọng.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpLoadSensor_Init(void) {
    // Cấu hình cho cảm biến tải trọng
    LoadSensor_ConfigType loadSensorConfig = {
        .LoadSensor_Channel = 2,         // Kênh ADC cho cảm biến tải trọng
        .LoadSensor_MaxValue = 1000      // Tải trọng tối đa giả lập (1000 kg)
    };
    return IoHwAb_LoadSensor_Init(&loadSensorConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tải trọng
}

/******************************************************************************
 * @brief   API khởi tạo cảm biến mô-men xoắn
 *
 * @details Hàm này thiết lập cấu hình cho cảm biến mô-men xoắn và gọi API khởi tạo
 *          từ IoHwAb để khởi tạo cảm biến mô-men xoắn.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpTorqueSensor_Init(void) {
    // Cấu hình cho cảm biến mô-men xoắn
    TorqueSensor_ConfigType torqueSensorConfig = {
        .TorqueSensor_Channel = 3,       // Kênh ADC cho cảm biến mô-men xoắn
        .TorqueSensor_MaxValue = 500     // Mô-men xoắn tối đa giả lập (500 Nm)
    };
    return IoHwAb_TorqueSensor_Init(&torqueSensorConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến mô-men xoắn
}

/******************************************************************************
 * @brief   API khởi tạo bộ điều khiển mô-men xoắn
 *
 * @details Hàm này thiết lập cấu hình cho bộ điều khiển mô-men xoắn và gọi API khởi tạo
 *          từ IoHwAb để khởi tạo bộ điều khiển mô-men xoắn.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_PpMotorDriver_Init(void) {
    // Cấu hình cho bộ điều khiển mô-men xoắn
    MotorDriver_ConfigType motorDriverConfig = {
        .Motor_Channel = 1,              // Kênh điều khiển mô-tơ
        .Motor_MaxTorque = 300           // Mô-men xoắn tối đa giả lập (300 Nm)
    };
    return IoHwAb_MotorDriver_Init(&motorDriverConfig);  // Gọi API từ IoHwAb để khởi tạo bộ điều khiển mô-men xoắn
}
