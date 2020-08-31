#include <gmock/gmock.h>

#include <QtCore/QCoreApplication>

int main(int argc, char **argv) {
  QCoreApplication app(argc, argv);

  ::testing::InitGoogleMock(&argc, argv);
  const auto ret_val = RUN_ALL_TESTS();
  return ret_val;
}
