// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "escher/shaders/solid_color_shader.h"

namespace escher {
namespace {

constexpr char g_vertex_shader[] = R"GLSL(
  attribute vec3 a_position;
  uniform mat4 u_matrix;

  void main() {
    gl_Position = u_matrix * vec4(a_position, 1.0);
  }
)GLSL";

constexpr char g_fragment_shader[] = R"GLSL(
  precision mediump float;
  uniform vec4 u_color;

  void main() {
    gl_FragColor = u_color;
  }
)GLSL";

}  // namespace

SolidColorShader::SolidColorShader() {
}

SolidColorShader::~SolidColorShader() {
}

bool SolidColorShader::Compile() {
  program_ = MakeUniqueProgram(g_vertex_shader, g_fragment_shader);
  if (!program_)
    return false;
  matrix_ = glGetUniformLocation(program_.id(), "u_matrix");
  ESCHER_DCHECK(matrix_ != -1);
  color_ = glGetUniformLocation(program_.id(), "u_color");
  ESCHER_DCHECK(color_ != -1);
  return true;
}

}  // namespace escher