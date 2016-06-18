// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "escher/base/macros.h"
#include "escher/gl/unique_program.h"

namespace escher {

class ShadowShader {
 public:
  ShadowShader();
  ~ShadowShader();

  bool Compile();

  const UniqueProgram& program() const { return program_; }

  GLint depth_map() const { return depth_map_; }
  GLint noise() const { return noise_; }
  // TODO(abarth): Add view size information.

  GLint position() const { return position_; }

  // Must match fragment shader.
  static const int kNoiseSize = 5;

 private:
  UniqueProgram program_;

  GLint depth_map_ = 0;
  GLint noise_ = 0;
  GLint position_ = 0;

  ESCHER_DISALLOW_COPY_AND_ASSIGN(ShadowShader);
};

}  // namespace escher
