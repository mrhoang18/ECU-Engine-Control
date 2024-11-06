/******************************************************************************
 * @file    Rte_TorqueControl.h
 * @brief   Header file định nghĩa các API RTE cho hệ thống điều khiển mô-men xoắn.
 *
 * @details File này định nghĩa các hàm API RTE dùng để đọc dữ liệu từ các cảm biến
 *          (bàn đạp ga, tốc độ, tải trọng, và mô-men xoắn thực tế) và ghi dữ liệu
 *          mô-men xoắn yêu cầu tới bộ điều khiển động cơ. Nó cũng bao gồm các hàm 
 *          khởi tạo cho từng cảm biến và bộ điều khiển mô-men xoắn.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef RTE_TORQUECONTROL_H
#define RTE_TORQUECONTROL_H

#include "Std_Types.h"  // Bao gồm các kiểu dữ liệu tiêu chuẩn

/******************************************************************************
 * @brief   API để đọc dữ liệu từ cảm biến bàn đạp ga
 *
 * @details Đọc giá trị vị trí bàn đạp ga từ cảm biến, lưu vào biến con trỏ đầu vào.
 *
 * @param   ThrottlePosition - Con trỏ lưu trữ giá trị vị trí bàn đạp ga
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpThrottleSensor_ThrottlePosition(float* ThrottlePosition);

/******************************************************************************
 * @brief   API để đọc dữ liệu từ cảm biến tốc độ
 *
 * @details Đọc giá trị tốc độ xe từ cảm biến, lưu vào biến con trỏ đầu vào.
 *
 * @param   Speed - Con trỏ lưu trữ giá trị tốc độ xe
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpSpeedSensor_Speed(float* Speed);

/******************************************************************************
 * @brief   API để đọc dữ liệu từ cảm biến tải trọng
 *
 * @details Đọc giá trị tải trọng từ cảm biến, lưu vào biến con trỏ đầu vào.
 *
 * @param   LoadWeight - Con trỏ lưu trữ giá trị tải trọng
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpLoadSensor_LoadWeight(float* LoadWeight);

/******************************************************************************
 * @brief   API để đọc mô-men xoắn thực tế từ cảm biến mô-men xoắn
 *
 * @details Đọc giá trị mô-men xoắn thực tế từ cảm biến, lưu vào biến con trỏ đầu vào.
 *
 * @param   ActualTorque - Con trỏ lưu trữ giá trị mô-men xoắn thực tế
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Read_RpTorqueSensor_ActualTorque(float* ActualTorque);

/******************************************************************************
 * @brief   API để ghi dữ liệu mô-men xoắn yêu cầu tới bộ điều khiển động cơ
 *
 * @details Ghi giá trị mô-men xoắn yêu cầu tới bộ điều khiển động cơ.
 *
 * @param   TorqueValue - Giá trị mô-men xoắn yêu cầu
 * @return  Std_ReturnType - Trả về E_OK nếu ghi thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Write_PpMotorDriver_SetTorque(float TorqueValue);

/******************************************************************************
 * @brief   API khởi tạo cảm biến bàn đạp ga
 *
 * @details Thiết lập cấu hình và khởi tạo cảm biến bàn đạp ga.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpThrottleSensor_Init(void);

/******************************************************************************
 * @brief   API khởi tạo cảm biến tốc độ
 *
 * @details Thiết lập cấu hình và khởi tạo cảm biến tốc độ.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpSpeedSensor_Init(void);

/******************************************************************************
 * @brief   API khởi tạo cảm biến tải trọng
 *
 * @details Thiết lập cấu hình và khởi tạo cảm biến tải trọng.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpLoadSensor_Init(void);

/******************************************************************************
 * @brief   API khởi tạo cảm biến mô-men xoắn
 *
 * @details Thiết lập cấu hình và khởi tạo cảm biến mô-men xoắn.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_RpTorqueSensor_Init(void);

/******************************************************************************
 * @brief   API khởi tạo bộ điều khiển mô-men xoắn
 *
 * @details Thiết lập cấu hình và khởi tạo bộ điều khiển mô-men xoắn.
 *
 * @param   void
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType Rte_Call_PpMotorDriver_Init(void);

#endif // RTE_TORQUECONTROL_H
