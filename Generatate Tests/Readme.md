# Tool generate test (ver 20.04.26.1)
- Lưu ý: Chương trình sử dụng hàm system(). Một số chương trình anti-virus có thể nhận diện nó như là virus. Xem thêm tại: http://www.cplusplus.com/articles/j3wTURfi/ . Lỗi này sẽ được fix tại các phiên bản sau.

------------------

### 1. File maketest.txt
File này sử dụng để nhập dữ liệu. Các dữ liệu cụ thể tương ứng với lệnh nhập vào của chương trình như sau (mỗi dòng 1 dữ liệu)

    cin >> filegen;   /// Chương trình tạo input. VD: gen.exe
    cin >> filerun;   /// Chương trình tạo output (code của các bạn). VD: WATER.exe
    cin >> filebai;   /// Tên bài làm. VD: WATER. Đây sẽ là tên thư mục chứa các test
    cin >> fileinp;   /// Tên file input: VD: WATER.inp. Tên file này cần trùng với file dữ liệu đầu vào của code bạn.
    cin >> fileout;   /// Tên file output: VD: WATER.out. Tên file này cần trùng với file dữ liệu đầu ra của code bạn.
    cin >> from;      /// Test bắt đầu từ: VD: 001
    cin >> numoftest; /// Số test. VD: 100
    cin >> timelimit; /// Thời gian chạy cho mỗi test (timelimit chưa áp dụng cho ver 20.04.26.1 nhưng vẫn phải có trong maketest)
    cin >> novalid;   /// Sử dụng validator (dùng testlib.h của Codeforces. Validator chưa áp dụng cho ver 20.04.26.1 nhưng vẫn phải có trong maketest, giá trị nhập vào là 0)
    cin >> nocheck;   /// Sử dụng checker (dùng testlib.h của Codeforces. Checker chưa áp dụng cho ver 20.04.26.1 nhưng vẫn phải có trong maketest, giá trị nhập vào là 0)
    
    
VD: 

    gen.exe
    1258.exe
    1258
    1258.inp
    1258.out
    01
    30
    10
    0
    0

### 2. File generator + solution
Các bạn sẽ copy file generator (là filegen trong maketest) và solution (filerun trong maketest) vào cùng 1 thư mục với maketest.txt và 
Generate Test.exe

### 3. File Generate Test.exe
Sau khi làm 2 bước trên, bạn chỉ cần chạy file này là được. Các test cấu tạo như sau (giả sử from = "001")

    filebai
        Test001
            fileinp
            fileout
        Test002
            fileinp
            fileout
        ...
  
Thư mục filebai nằm trong cùng 1 thư mục với maketest.txt và Generate Test.exe.

!!! Chú ý: 
- Nếu thư mục filebai đã có sẵn, đảm bảo các test in ra không trùng số thứ tự với các test có sẵn
- from cần có số chữ số = số chữ số của test to nhất bạn tạo. VD bạn muốn tạo 30 test từ test 1, from = "01"; tạo 120 test từ test 1, from = "001".
