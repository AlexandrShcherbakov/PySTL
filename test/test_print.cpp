#include "gtest/gtest.h"

#include "print.h"


using namespace PySTL;

TEST(PrintTest, PrintNothing) {
    testing::internal::CaptureStdout();
    print();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(std::string("\n"), output) << "print() must add newline";
}

struct CustomObject {
    friend std::ostream& operator<<(std::ostream& o, const CustomObject&){
        return o << "custom";
    }
};

TEST(PrintTest, MultiplyPrint) {
    testing::internal::CaptureStdout();
    print(1, 'a', "Hello World", CustomObject{});
    std::string output = testing::internal::GetCapturedStdout();
    std::string right_string = "1 a Hello World custom\n";
    ASSERT_EQ(right_string, output)
        << "print must be able handle many arguments";
}

TEST(PrintTest, OptionalParams) {
    std::stringstream ss;
    print("Hello").file(ss);
    std::string result = ss.str();
    EXPECT_EQ(std::string("Hello\n"), result)
        << "print must be able use any stream";

    testing::internal::CaptureStdout();
    print(1,2,3).sep("_").end("^");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(std::string("1_2_3^"), output)
        << "print must be able change default separator and end of line";

    std::stringstream ss2;
    print('a', 'b', 'c')("&", "endline", ss2);
    std::string output2 = ss2.str();
    ASSERT_EQ(std::string("a&b&cendline"), output2)
            << "operator() should work";
}
