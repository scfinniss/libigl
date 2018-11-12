// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2014 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_FRAME_TO_CROSS_FIELD_H
#define IGL_FRAME_TO_CROSS_FIELD_H
#include "igl_inline.h"

#include <Eigen/Dense>

namespace igl
{
  // Convert a frame field into its closest cross field
  // Inputs:
  //   V       #V by 3 coordinates of the vertices
  //   F       #F by 3 list of mesh faces (must be triangles)
  //   FF1     #F by 3 the first representative vector of the frame field (up to permutation and sign)
  //   FF2     #F by 3 the second representative vector of the frame field (up to permutation and sign)
  //
  // Outputs:
  //   X       #F by 3 representative vector of the closest cross field
  //

  template <typename DerivedV, typename DerivedF>
  IGL_INLINE void frame_to_cross_field(
          const Eigen::PlainObjectBase<DerivedV>& V,
          const Eigen::PlainObjectBase<DerivedF>& F,
          const Eigen::PlainObjectBase<DerivedV>& FF1,
          const Eigen::PlainObjectBase<DerivedV>& FF2,
          Eigen::PlainObjectBase<DerivedV>& X);

}

#ifndef IGL_STATIC_LIBRARY
#  include "frame_to_cross_field.cpp"
#endif

#endif
