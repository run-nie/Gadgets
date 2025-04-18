#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstddef> // for offsetof

using namespace std;

// 描述结构体中每个成员的名称、偏移和大小
struct Field {
    string name;
    size_t offset;
    size_t size;
    char symbol; // 用哪个字符代表该字段
};

// 可视化函数
void visualizeStructLayout(size_t structSize, const vector<Field>& fields) {
    vector<char> layout(structSize, 'P');  // 默认全部是 padding（P）

    for (const auto& field : fields) {
        for (size_t i = 0; i < field.size; ++i) {
            if (field.offset + i < structSize)
                layout[field.offset + i] = field.symbol;
        }
    }

    // 打印图形
    cout << "Offset | ";
    for (size_t i = 0; i < structSize; ++i)
        cout << setw(2) << i << " ";
    cout << "\n--------+--------------------------\n";

    cout << "Field  | ";
    for (char ch : layout)
        cout << " " << ch << " ";
    cout << "\n\n";

    // 说明
    for (const auto& field : fields)
        cout << field.symbol << " = " << field.name << " (" << field.size << " bytes at offset " << field.offset << ")\n";
    cout << "P = Padding\n";
}

struct MyStruct {
    char a;
    int b;
    short c;
};

int main() {
    vector<Field> fields = {
        {"a", offsetof(MyStruct, a), sizeof(char), 'A'},
        {"b", offsetof(MyStruct, b), sizeof(int),  'B'},
        {"c", offsetof(MyStruct, c), sizeof(short),'C'}
    };

    visualizeStructLayout(sizeof(MyStruct), fields);

	cin.get();
}
