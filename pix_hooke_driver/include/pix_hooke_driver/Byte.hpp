// Copyright 2023 Pixmoving, Inc. 
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <iostream>

class Byte
{
private:
    uint8_t byte_t;

public:
    Byte(std::uint8_t byte) noexcept;
    ~Byte() noexcept;

    uint8_t return_byte_t() noexcept;
    inline int32_t get_byte(uint start, uint len) noexcept
    {
      uint8_t mask = (1 << len) - 1;
      return static_cast<int32_t>((byte_t >> start) & mask);
    }
    inline void set_value(uint8_t value, uint start, uint len) noexcept
    {
      uint8_t mask = ((1 << len) - 1) << start;
      byte_t = (byte_t & ~mask) | ((value << start) & mask);
    }
};
