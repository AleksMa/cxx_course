#include <gtest/gtest.h>

#include <fstream>
#include <string>

class FileTest : public ::testing::Test {

protected:
    std::string filename = "temp_test_file.txt";

    void SetUp() override {
        std::ofstream out(filename);
        out << "hello\n";
        out << "world\n";
    }

    void TearDown() override {
        std::remove(filename.c_str());
    }
};

TEST_F(FileTest, FirstLineIsHello) {
    std::ifstream in(filename);

    std::string line;
    std::getline(in, line);

    EXPECT_EQ(line, "hello");
}
