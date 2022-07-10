// Copyright 2022 Alexey Timin
#include <CLI/CLI.hpp>
#include <catch2/catch.hpp>

#include "reduct_cli/app.h"

using reduct::cli::IApp;

TEST_CASE("Should print version", "[controller]") {
  auto app = IApp::Build();
  std::stringstream ss;

  REQUIRE(app->Parse({"-v"}) == 0);
  REQUIRE(app->Run(ss) == 0);

  REQUIRE(ss.str() == "0.1.0");
}
