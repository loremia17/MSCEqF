// Copyright (C) 2023 Alessandro Fornasier.
// Control of Networked Systems, University of Klagenfurt, Austria.
//
// All rights reserved.
//
// This software is licensed under the terms of the BSD-2-Clause-License with
// no commercial use allowed, the full terms of which are made available
// in the LICENSE file. No license in patents is granted.
//
// You can contact the authors at <alessandro.fornasier@ieee.org>

#ifndef SYMMETRY_HPP
#define SYMMETRY_HPP

#include "msceqf/state/state.hpp"
#include "sensors/sensor_data.hpp"
#include "msceqf/system/system.hpp"
#include "utils/tools.hpp"

namespace msceqf
{
class Symmetry
{
 public:
  /**
   * @brief Implement the right group action phi of the symmetry group, acting on the homogenous space (phi(X, xi))
   *
   * @param X MSCEqF state (symmetry group element)
   * @param xi System state (homogenous space element)
   * @return System state (homogenous space element)
   */
  [[nodiscard]] static const SystemState phi(const MSCEqFState& X, const SystemState& xi);

  /**
   * @brief Implement the lift function. Lift the actual dynamics onto the symmetry group
   *
   * @param xi System state (homogenous space element)
   * @param u Input (Imu)
   * @return Input for the lifted system (Symmetry group Lie algebra element)
   */
  [[nodiscard]] static const SystemState::SystemStateAlgebraMap lift(const SystemState& xi, const Imu& u);

  /**
   * @brief Return the Gamma matrix for the reset / curvature correction
   *
   * @param X MSCEqF state (symmetry group element)
   * @param inn Innovatiation vector
   * @return Gamma matrix
   */
  [[nodiscard]] static const MatrixX curvatureCorrection(const MSCEqFState& X, const VectorX& inn);

  static const Matrix5 D;  //!< The D matrix

 private:
  Symmetry() = default;
};

}  // namespace msceqf

#endif  // SYMMETRY_HPP