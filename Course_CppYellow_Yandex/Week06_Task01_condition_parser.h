#pragma once

#include <memory>
#include <iostream>

#include "Week06_Task01_node.h"

std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();
