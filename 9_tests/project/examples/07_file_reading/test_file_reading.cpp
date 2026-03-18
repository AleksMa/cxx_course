#include <gtest/gtest.h>
#include "config_reader.h"

TEST(ConfigReaderTest, ReadsPortFromSimpleFile) {
    EXPECT_EQ(read_port_from_file("data/simple_config.txt"), 8080);
}

TEST(ConfigReaderTest, ThrowsForMissingFile) {
    EXPECT_THROW(read_port_from_file("data/no_such_file.txt"), std::runtime_error);
}