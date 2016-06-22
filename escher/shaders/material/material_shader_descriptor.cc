// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "escher/shaders/material/material_shader_factory.h"

namespace escher {

MaterialShaderDescriptor::MaterialShaderDescriptor(
    BindingType color_binding_type,
    Modifier::Mask mask)
    : color_binding_type(color_binding_type), mask(mask) {}

MaterialShaderDescriptor::~MaterialShaderDescriptor() {}

bool MaterialShaderDescriptor::operator==(
    const MaterialShaderDescriptor& other) const {
  return color_binding_type == other.color_binding_type && mask == other.mask;
}

size_t MaterialShaderDescriptor::hash() const {
  return static_cast<int>(color_binding_type) << 2 | static_cast<int>(mask);
}

}  // namespace escher
