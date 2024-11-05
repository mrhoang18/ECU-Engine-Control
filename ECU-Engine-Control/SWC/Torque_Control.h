/******************************************************************************
 * @file    Torque_Control.h
 * @brief   Header file cho hệ thống điều khiển mô-men xoắn
 *
 * @details Định nghĩa các hằng số và khai báo các hàm chính cho hệ thống điều
 *          khiển mô-men xoắn, bao gồm hàm khởi tạo và hàm cập nhật.
 *          Giới hạn mô-men xoắn tối đa và tối thiểu cũng được xác định tại đây.
 *
 * @version 1.0
 * @author  Tong Xuan Hoang
 * @date    2024-10-25
 ******************************************************************************/
#ifndef TORQUE_CONTROL_H
#define TORQUE_CONTROL_H

/******************************************************************************
 * @brief   Định nghĩa các giá trị giới hạn cho mô-men xoắn
 *
 * @details MAX_TORQUE và MIN_TORQUE là các giá trị giới hạn mô-men xoắn mà hệ
 *          thống điều khiển mô-men xoắn có thể đạt được. MAX_TORQUE giới hạn 
 *          mô-men xoắn yêu cầu ở mức tối đa để đảm bảo an toàn, trong khi 
 *          MIN_TORQUE đặt giới hạn tối thiểu.
 ******************************************************************************/
#define MAX_TORQUE 100.0f  /**< Giá trị mô-men xoắn tối đa */
#define MIN_TORQUE 0.0f    /**< Giá trị mô-men xoắn tối thiểu */

/******************************************************************************
 * @brief   Hàm khởi tạo hệ thống điều khiển mô-men xoắn
 *
 * @details Hàm này khởi tạo các cảm biến và bộ điều khiển liên quan cho hệ thống 
 *          điều khiển mô-men xoắn.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void TorqueControl_Init(void);

/******************************************************************************
 * @brief   Hàm cập nhật hệ thống điều khiển mô-men xoắn
 *
 * @details Hàm này cập nhật mô-men xoắn yêu cầu dựa trên các giá trị đọc được từ
 *          cảm biến, sau đó gửi mô-men xoắn yêu cầu tới động cơ và điều chỉnh nếu 
 *          cần thiết.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void TorqueControl_Update(void);

#endif // TORQUE_CONTROL_H
