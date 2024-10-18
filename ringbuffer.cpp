#include <iostream>
using namespace std;
int MAX_SIZE;

void ringbuffer_init(){
    cout << "Number of elments: ";
        cin >> MAX_SIZE;
}
// Các hàm kiểm tra trạng thái của buffer
int ringbuffer_is_full(int head, int tail) {
    if(head == (tail + 1) % MAX_SIZE){
        cout << "RING BUFFER IS FULL ";
        return 1;
    }else{
        cout << "RING BUFFER IS AVAILABLE ";
        return 0;
    }
}

int ringbuffer_is_empty(int head, int tail) {
    if(head == -1){
        cout << "RING BUFFER IS EMPTY ";
        return 1;
    }else{
        cout << "RING BUFFER IS NOT EMPTY ";
        return 0;
    }
}

// Hàm thêm phần tử vào buffer
int ringbuffer_add(int buffer[], int &head, int &tail) {
    int element;
    cout << "ENTER THE ELEMENT: ";
    cin >> element;

    if (head == (tail + 1) % MAX_SIZE) {
        cout << "RING BUFFER FULL: NO SPACE TO INSERT\n";
        return -1;
    }

    if (head == -1) { // Nếu buffer rỗng
        head = tail = 0;
    } else {
        tail = (tail + 1) % MAX_SIZE;
    }

    buffer[tail] = element;
    cout << "ELEMENT INSERTED SUCCESSFULLY\n";
    return 0;
}

// Hàm xóa phần tử khỏi buffer
int ringbuffer_remove(int buffer[], int &head, int &tail) {
    if (head == -1) {
        cout << "RING BUFFER EMPTY: NO ELEMENT TO DELETE\n";
        return -1;
    }

    int element = buffer[head];
    cout << "DELETED ELEMENT: " << element << "\n";

    if (head == tail) {  // Nếu chỉ còn một phần tử
        head = tail = -1; // Đặt lại buffer về rỗng
    } else {
        head = (head + 1) % MAX_SIZE;
    }

    return 0;
}

int ringbuffer_size(int buffer[], int head, int tail){
    cout<< "NUMBER ELEMENT OF RING BUFFER IS: " << tail - head + 1;
}

int main() {

    ringbuffer_init();
    int ring_buffer[MAX_SIZE];
    int head = -1, tail = -1;  // Khởi tạo buffer rỗng
    int choice;

    do {
        cout << "\n\nMENU:\n";
        cout << "\t1. CHECK EMPTY RB\n";
        cout << "\t2. CHECK FULL RB\n";
        cout << "\t3. INSERT ELEMENT\n";
        cout << "\t4. DELETE ELEMENT\n";
        cout << "\t5. Check_size\n";
        cout << "\t6. EXIT\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ringbuffer_is_empty(head, tail);
                break;
            case 2:
                ringbuffer_is_full(head, tail);
                break;
            case 3:
                ringbuffer_add(ring_buffer, head, tail);
                break;
            case 4:
                ringbuffer_remove(ring_buffer, head, tail);
                break;
            case 5:
                ringbuffer_size(ring_buffer, head, tail);
                break;
            case 6:
                cout << "THANK YOU!!!\n";
                break;
            default:
                cout << "PLEASE ENTER A VALID OPTION\n";
        }
    } while (choice != 6);

    return 0;
}
