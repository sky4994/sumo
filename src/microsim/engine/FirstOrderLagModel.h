/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2019 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    FirstOrderLagModel.h
/// @author  Michele Segata
/// @date    4 Feb 2015
/// @version $Id$
///
// An engine model using a first order lag
/****************************************************************************/

#ifndef FIRSTORDERLAGMODEL_H_
#define FIRSTORDERLAGMODEL_H_

#include "GenericEngineModel.h"

/**
 * This model models actuation lags using a first order lag, i.e., a first order
 * low pass filter with a time constant tau
 */
class FirstOrderLagModel : public GenericEngineModel {

protected:

    //engine lag time constant in seconds
    double tau_s;
    //simulation sampling time
    double dt_s;
    //helper variables
    double alpha, oneMinusAlpha;

    /**
     * Recomputes helper variables after loading parameters
     */
    void computeParameters();

public:
    FirstOrderLagModel();
    virtual ~FirstOrderLagModel();

    /**
     * Computes real vehicle acceleration given current speed, current acceleration,
     * and requested acceleration. Acceleration can be negative as well. The
     * model should handle decelerations as well
     *
     * @param[in] speed_mps current speed in meters per second
     * @param[in] accel_mps2 current acceleration in meters per squared second
     * @param[in] reqAccel_mps2 requested acceleration in meters per squared second
     * @param[in] timeStep current simulation timestep
     * @return the real acceleration that the vehicle applies in meters per
     * squared second
     */
    virtual double getRealAcceleration(double speed_mps, double accel_mps2, double reqAccel_mps2, SUMOTime timeStep = 0);

    /**
     * Load model parameters. This method requires a map of strings to be as
     * flexible as possible, independently from the actual model implementation
     *
     * @param[in] parameters a map of strings (from parameter name to parameter
     * value) including configuration parameters
     */
    virtual void loadParameters(const ParMap& parameters);

    /**
     * Sets a single parameter value
     *
     * @param[in] parameter the name of the parameter
     * @param[in] value the value for the parameter
     */
    virtual void setParameter(const std::string parameter, const std::string& value);
    virtual void setParameter(const std::string parameter, double value);
    virtual void setParameter(const std::string parameter, int value);

};

#endif /* FIRSTORDERLAGMODEL_H_ */
