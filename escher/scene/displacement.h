// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <glm/glm.hpp>

#include "escher/scene/binding.h"

namespace escher {

// Texture and shading properties to apply to a surface.
class Displacement {
 public:
  enum class Type {
    kNone,
    kWave,
    // TODO(abarth): The client should be able to use a texture.
  };

  Displacement();
  ~Displacement();

  static Displacement MakeWave(const glm::vec2& start,
                               const glm::vec2& end,
                               float max);

  Type type() const { return type_; }
  float max() const { return max_; }

  // For Type::kWave.
  glm::vec2 start() const { return glm::vec2(parameters_.x, parameters_.y); }
  glm::vec2 end() const { return glm::vec2(parameters_.z, parameters_.w); }

 private:
  Type type_ = Type::kNone;
  glm::vec4 parameters_;
  float max_ = 0.0;
};

}  // namespace escher
