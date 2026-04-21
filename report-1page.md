# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Thực hiện và kiểm thử hai mã hoá cổ điển: Caesar Cipher và Rail Fence Cipher; xử lý chữ thường/hoa, giữ khoảng trắng, giải mã, kiểm tra đầu vào và đọc thông điệp từ file.

## 2. Cách làm
- Cài đặt hàm mã hoá/giải mã cho Caesar (giữ chữ hoa/thường và khoảng trắng).
- Cài đặt hàm mã hoá/giải mã cho Rail Fence (giữ khoảng trắng, kiểm tra số rail hợp lệ, đọc từ file `data/input.txt`).
- Viết chương trình demo cho từng bài, chạy các test case trong `tests/test_cases.md` và ghi lại `logs/run_log.md`.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | LORYH BRX | Encrypt: giữ khoảng trắng và hoa chữ cái; decrypt đúng |
| hello world | 5 | mjqqt btwqi | Chữ thường được xử lý đúng |
| LORYH BRX | 3 | I LOVE YOU | Decrypt trả về bản rõ gốc |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Mã hoá theo 2 rail (khoảng trắng được giữ nguyên) |
| I LOVE YOU | 4 | I  EYLVOOU | Mã hoá theo 4 rail (cần chú ý vị trí khoảng trắng) |
| ILV O OEYU | 2 | I LOVE YOU | Giải mã đúng với số rail phù hợp |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ: chuỗi có ký tự không phải chữ và khoảng trắng (ví dụ: "HELLO!" hoặc "123") sẽ bị từ chối.
- Trường hợp rail không hợp lệ: số rail <= 0 bị từ chối.
- Kết quả đọc từ `data/input.txt`: nội dung là `I LOVE YOU` (đã dùng cho test đọc file và mã hoá).

## 4. Kết luận
- Hiểu rõ hơn về cách hoạt động của Caesar (dịch vòng trên 26 chữ) và Rail Fence (mô phỏng ray zig-zag).
- Học cách xử lý các trường hợp biên: giữ khoảng trắng, xử lý chữ hoa/thường và kiểm tra đầu vào.
- Việc đọc/ghi file và viết chương trình demo giúp kiểm chứng các hàm mã hoá/giải mã thực tế.
