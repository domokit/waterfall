// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <glm/glm.hpp>
#include <math.h>

#include "escher/geometry/size_i.h"

namespace escher {

class ViewingVolume {
 public:
  ViewingVolume();
  ViewingVolume(SizeI size, float near, float far);
  ~ViewingVolume();

  const SizeI& size() const { return size_; }
  float depth() const { return std::abs(near_ - far_); }

  glm::mat4 GetProjectionMatrix() const;

 private:
  SizeI size_;
  float near_ = 0.0f;
  float far_ = 0.0f;
};

}  // namespace escher