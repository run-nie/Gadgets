# -#include <iostream>
#include <string>

class ShadowCoder {
private:
    std::string codeName = "零式开发者";
    std::string trueName = "Jecloce";
    std::string origin = "调试的深渊";
    std::string forbiddenSkill = "多线程的咒语";
    std::string secret = "我曾亲手修复过一个遗忘的segmentation fault";

public:
    void awaken() const {
        std::cout << "【系统提示】检测到异常能量波动...\n";
        std::cout << "代号：0" << codeName << "\n";
        std::cout << "真实身份：**特工" << trueName << "，来自&*星球" << origin << "\n";
        std::cout << "掌握禁术：HTML,CSS,JS,C++" << forbiddenSkill << "\n";
        std::cout << "黑历史载入中...\n";
        std::cout << ">> " << secret << "\n";

        std::cout << "\n“我不是为了写代码而存在，\n"
                     "是代码，选择了我。”\n";
    }
};

int main() {
    ShadowCoder me;
    me.awaken();
    return 0;
}
