// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2014 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_COMISO_NROSY_H
#define IGL_COMISO_NROSY_H

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <vector>
#include "../../igl_inline.h"
#include "../../PI.h"

namespace igl
{
  namespace copyleft
  {
  namespace comiso
  {
    // Generate a N-RoSy field from a sparse set of constraints
    //
    // Inputs:
    //   V       #V by 3 list of mesh vertex coordinates
    //   F       #F by 3 list of mesh faces (must be triangles)
    //   b       #B by 1 list of constrained face indices
    //   bc      #B by 3 list of representative vectors for the constrained
    //     faces
    //   b_soft  #S by 1 b for soft constraints
    //   w_soft  #S by 1 weight for the soft constraints (0-1)
    //   bc_soft #S by 3 bc for soft constraints
    //   N       the degree of the N-RoSy vector field
    //   soft    the strength of the soft constraints w.r.t. smoothness
    //           (0 -> smoothness only, 1->constraints only)
    // Outputs:
    //   R       #F by 3 the representative vectors of the interpolated field
    //   S       #V by 1 the singularity index for each vertex (0 = regular)
    template <typename Scalar, typename Index>
    IGL_INLINE void nrosy(
      const Eigen::Matrix<Scalar, Eigen::Dynamic, 3>& V,
      const Eigen::Matrix<Index, Eigen::Dynamic, 3>& F,
      const Eigen::Matrix<Index, Eigen::Dynamic, 1>& b,
      const Eigen::Matrix<Scalar, Eigen::Dynamic, 3>& bc,
      const Eigen::Matrix<Scalar, Eigen::Dynamic, 1>& b_soft,
      const Eigen::Matrix<Scalar, Eigen::Dynamic, 1>& w_soft,
      const Eigen::Matrix<Scalar, Eigen::Dynamic, 3>& bc_soft,
      const int N,
      const double soft,
      Eigen::Matrix<Scalar, Eigen::Dynamic, 3>& R,
      Eigen::Matrix<Scalar, Eigen::Dynamic, 1>& S
      );
    //wrapper for the case without soft constraints
    template <typename Scalar, typename Index>
    IGL_INLINE void nrosy(
     const Eigen::Matrix<Scalar, Eigen::Dynamic, 3>& V,
     const Eigen::Matrix<Index, Eigen::Dynamic, 3>& F,
     const Eigen::Matrix<Index, Eigen::Dynamic, 1>& b,
     const Eigen::Matrix<Scalar, Eigen::Dynamic, 3>& bc,
     const int N,
     Eigen::Matrix<Scalar, Eigen::Dynamic, 3>& R,
     Eigen::Matrix<Scalar, Eigen::Dynamic, 1>& S
      );

  }
}
}

#ifndef IGL_STATIC_LIBRARY
#  include "nrosy.cpp"
#endif

#endif
