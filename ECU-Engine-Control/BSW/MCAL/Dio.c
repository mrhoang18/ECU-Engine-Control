/******************************************************************************
 * @file    Dio.h
 * @brief   Header file cho cấu hình và API của giao diện DIO (Digital Input/Output)
 *
 * @details File này định nghĩa các cấu trúc, enum, và API cần thiết để thực hiện các
 *          thao tác cơ bản với giao diện DIO trên vi điều khiển. Các API bao gồm
 *          hàm khởi tạo DIO, đọc trạng thái từ một chân DIO cụ thể, ghi giá trị
 *          lên chân DIO, và hàm tạo độ trễ để mô phỏng thời gian chờ. Enum `Dio_LevelType`
 *          cung cấp các giá trị cho trạng thái DIO (cao hoặc thấp). File này được sử dụng
 *          để mô phỏng chức năng DIO, hỗ trợ kiểm thử trong quá trình phát triển mà không
 *          cần phần cứng thực tế.
 *
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#include "Dio.h"

/******************************************************************************
 * @brief   Khởi tạo giao diện DIO (Digital Input/Output)
 *
 * @details Hàm này thực hiện khởi tạo giao diện DIO, bao gồm thiết lập seed cho 
 *          hàm tạo số ngẫu nhiên, nhằm hỗ trợ mô phỏng các giá trị đầu vào và đầu ra
 *          của DIO trong quá trình phát triển. Sau khi khởi tạo, hàm sẽ in thông báo 
 *          để xác nhận rằng DIO đã được khởi tạo thành công.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Dio_Init(void) {
    // Khởi tạo seed cho random số ngẫu nhiên
    srand(time(0));
    printf("DIO Initialized.\n");
}

/******************************************************************************
 * @brief   Đọc giá trị từ một chân DIO (giá trị ngẫu nhiên)
 *
 * @details Hàm này mô phỏng việc đọc giá trị từ một chân DIO cụ thể bằng cách tạo 
 *          một giá trị ngẫu nhiên, giúp giả lập trạng thái của chân DIO là cao (HIGH) 
 *          hoặc thấp (LOW). Trước khi đọc, hàm sẽ tạo độ trễ 200ms để mô phỏng thời 
 *          gian lấy mẫu thực tế. Giá trị ngẫu nhiên 0 hoặc 1 được sinh ra để mô phỏng
 *          trạng thái chân DIO, và thông tin sẽ được in ra màn hình.
 *
 * @param   channel - Số kênh DIO cần đọc giá trị
 * @return  Dio_LevelType - Trạng thái của chân DIO (DIO_HIGH hoặc DIO_LOW)
 ******************************************************************************/
Dio_LevelType Dio_ReadChannel(int channel) {
    Dio_LevelType dio_value;

    // Gọi hàm delay để mô phỏng thời gian đọc DIO
    Dio_Delay(200);  // Tạo độ trễ 200ms để mô phỏng

    // Giả lập trạng thái ngẫu nhiên của DIO (0 hoặc 1)
    dio_value = (rand() % 2) ? DIO_HIGH : DIO_LOW;

    // In trạng thái đọc được từ kênh DIO
    printf("Reading DIO Channel %d: Value = %d\n", channel, dio_value);

    return dio_value;
}

/******************************************************************************
 * @brief   Ghi giá trị cho chân DIO
 *
 * @details Hàm này thiết lập giá trị cho một chân DIO cụ thể, cho phép đặt chân đó 
 *          vào trạng thái cao (HIGH) hoặc thấp (LOW) theo giá trị của tham số `level`.
 *          Để mô phỏng thời gian ghi, hàm tạo độ trễ 100ms trước khi thực hiện in 
 *          thông tin về trạng thái đã ghi vào chân DIO ra màn hình, bao gồm số kênh 
 *          và giá trị được thiết lập.
 *
 * @param   channel - Số kênh DIO cần thiết lập giá trị
 * @param   level - Trạng thái mong muốn của chân DIO (DIO_HIGH hoặc DIO_LOW)
 * @return  void
 ******************************************************************************/
void Dio_WriteChannel(int channel, Dio_LevelType level) {
    // Gọi hàm delay để mô phỏng thời gian ghi DIO
    Dio_Delay(100);  // Tạo độ trễ 100ms để mô phỏng

    // In trạng thái được ghi vào kênh DIO
    printf("Writing DIO Channel %d: Value = %d\n", channel, level);
}

/******************************************************************************
 * @brief   Hàm tạo độ trễ mô phỏng (tính theo mili giây)
 *
 * @details Hàm này tạo ra một khoảng thời gian trễ dựa trên tham số đầu vào 
 *          `milliseconds`, hỗ trợ cho việc mô phỏng thời gian chờ khi thực hiện 
 *          các thao tác DIO. Hàm `usleep` nhận vào thời gian tính bằng micro giây,
 *          do đó tham số `milliseconds` được nhân với 1000 để chuyển đổi từ mili giây
 *          sang micro giây.
 *
 * @param   milliseconds - Thời gian trễ mong muốn, tính theo mili giây
 * @return  void
 ******************************************************************************/
void Dio_Delay(int milliseconds) {
    usleep(milliseconds * 1000); // Hàm usleep tính theo micro giây, nhân với 1000 để thành mili giây
}
