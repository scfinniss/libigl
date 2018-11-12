// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2014 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include "rotate_vectors.h"
template <typename Scalar>
IGL_INLINE Eigen::Matrix<Scalar, Eigen::Dynamic, 3> igl::rotate_vectors(
        const Eigen::Matrix<Scalar, Eigen::Dynamic, 3> V,
        const Eigen::Matrix<Scalar, 1, Eigen::Dynamic>& A,
        const Eigen::Matrix<Scalar, Eigen::Dynamic, 3> B1,
        const Eigen::Matrix<Scalar, Eigen::Dynamic, 3> B2)
{
  Eigen::Matrix<Scalar, Eigen::Dynamic, 3> RV(V.rows(), 3);

  for (unsigned i=0; i<V.rows();++i)
  {
    double norm = V.row(i).norm();
    
    // project onto the tangent plane and convert to angle
    double a = atan2(B2.row(i).dot(V.row(i)),B1.row(i).dot(V.row(i)));

    // rotate
    a += (A.size() == 1) ? A(0) : A(i);

    // move it back to global coordinates
    RV.row(i) = norm*cos(a) * B1.row(i) + norm*sin(a) * B2.row(i);
  }

  return RV;
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
#endif
