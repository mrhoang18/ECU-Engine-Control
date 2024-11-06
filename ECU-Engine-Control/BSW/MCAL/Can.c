/******************************************************************************
 * @file    Can.c
 * @brief   Triển khai các API cho giao tiếp CAN (Controller Area Network)
 *
 * @details File này chứa các hàm để khởi tạo và xử lý giao tiếp CAN, bao gồm việc
 *          gửi và nhận thông điệp CAN trong hệ thống. Các API mô phỏng giao tiếp CAN,
 *          với việc tạo độ trễ và sinh dữ liệu ngẫu nhiên để giả lập quá trình truyền
 *          và nhận thông điệp. Mỗi thông điệp CAN bao gồm ID, dữ liệu, và độ dài.
 *
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#include "Can.h"

/******************************************************************************
 * @brief   Hàm khởi tạo giao tiếp CAN
 *
 * @details Hàm này thiết lập các cấu hình cần thiết để khởi tạo giao tiếp CAN.
 *          Trong mô phỏng này, hàm chỉ đơn giản in ra thông báo để xác nhận
 *          rằng giao tiếp CAN đã được khởi tạo. Hàm giúp chuẩn bị hệ thống cho
 *          việc gửi và nhận các thông điệp CAN.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Can_Init(void) {
    printf("CAN Initialized.\n");
}

/******************************************************************************
 * @brief   Gửi một thông điệp CAN
 *
 * @details Hàm này thực hiện gửi một thông điệp CAN bằng cách nhận vào cấu trúc 
 *          `Can_MessageType` chứa thông tin thông điệp, bao gồm ID, dữ liệu và 
 *          độ dài dữ liệu. Để mô phỏng thời gian gửi, hàm tạo độ trễ 200ms trước 
 *          khi in thông tin của thông điệp được gửi ra màn hình. Thông tin này bao
 *          gồm ID của thông điệp, độ dài dữ liệu và các giá trị dữ liệu.
 *
 * @param   message - Con trỏ tới cấu trúc `Can_MessageType` chứa thông điệp cần gửi
 * @return  void
 ******************************************************************************/
void Can_SendMessage(Can_MessageType* message) {
    // Gọi hàm delay để mô phỏng thời gian gửi CAN
    Can_Delay(200);  // Tạo độ trễ 200ms để mô phỏng

    // In ra thông tin thông điệp được gửi
    printf("CAN Message Sent:\n");
    printf("ID: %d, Data Length: %d, Data: [", message->id, message->length);
    for (int i = 0; i < message->length; i++) {
        printf("%d", message->data[i]);
        if (i < message->length - 1) printf(", ");
    }
    printf("]\n");
}

/******************************************************************************
 * @brief   Nhận một thông điệp CAN (giả lập ngẫu nhiên)
 *
 * @details Hàm này mô phỏng việc nhận một thông điệp CAN. Thời gian nhận được 
 *          mô phỏng bằng cách tạo độ trễ 300ms. Sau đó, hàm tạo dữ liệu ngẫu 
 *          nhiên cho thông điệp CAN, bao gồm ID ngẫu nhiên trong khoảng từ 0 
 *          đến 2047, độ dài dữ liệu ngẫu nhiên từ 0 đến 8 byte, và các giá trị
 *          dữ liệu trong khoảng từ 0 đến 255. Thông tin của thông điệp nhận 
 *          được sẽ được in ra màn hình để xác nhận, bao gồm ID, độ dài và 
 *          nội dung dữ liệu.
 *
 * @param   void
 * @return  Can_MessageType - Trả về cấu trúc `Can_MessageType` chứa thông tin 
 *          thông điệp CAN nhận được
 ******************************************************************************/
Can_MessageType Can_ReceiveMessage(void) {
    Can_MessageType message;

    // Gọi hàm delay để mô phỏng thời gian nhận CAN
    Can_Delay(300);  // Tạo độ trễ 300ms để mô phỏng

    // Giả lập dữ liệu ngẫu nhiên cho thông điệp CAN
    message.id = rand() % 2048;  // Giả lập ID ngẫu nhiên (0 - 2047)
    message.length = rand() % 9; // Giả lập độ dài dữ liệu (0 - 8)
    for (int i = 0; i < message.length; i++) {
        message.data[i] = rand() % 256;  // Giả lập dữ liệu ngẫu nhiên (0 - 255)
    }

    // In ra thông tin thông điệp nhận được
    printf("CAN Message Received:\n");
    printf("ID: %d, Data Length: %d, Data: [", message.id, message.length);
    for (int i = 0; i < message.length; i++) {
        printf("%d", message.data[i]);
        if (i < message.length - 1) printf(", ");
    }
    printf("]\n");

    return message;
}

/******************************************************************************
 * @brief   Hàm tạo độ trễ mô phỏng (tính theo mili giây)
 *
 * @details Hàm này tạo ra một khoảng thời gian trễ dựa trên tham số đầu vào,
 *          được sử dụng để mô phỏng thời gian chờ trong giao tiếp CAN.
 *          Hàm `usleep` nhận vào thời gian tính bằng micro giây, vì vậy tham số
 *          `milliseconds` được nhân với 1000 để chuyển đổi từ mili giây sang
 *          micro giây.
 *
 * @param   milliseconds - Thời gian trễ mong muốn, tính theo mili giây
 * @return  void
 ******************************************************************************/
void Can_Delay(int milliseconds) {
    usleep(milliseconds * 1000); // Hàm usleep tính theo micro giây, nhân với 1000 để thành mili giây
}
