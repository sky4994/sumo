/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2020 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GNEGeometryPointDialog.h
/// @author  Pablo Alvarez Lopez
/// @date    Jan 2021
///
// A dialog for set Geometry Points
/****************************************************************************/
#pragma once
#include <config.h>

#include <fx.h>
#include <vector>
#include <utils/xml/SUMOXMLDefinitions.h>

// ===========================================================================
// class declarations
// ===========================================================================

class GNEAdditional;
class GNEUndoList;

// ===========================================================================
// class definitions
// ===========================================================================

/**
 * @class GNEGeometryPointDialog
 * @brief Dialog to edit sequences, parameters, etc.. of Additionals
 */
class GNEGeometryPointDialog : protected FXTopWindow {
    /// @brief FOX-declaration abstract
    FXDECLARE_ABSTRACT(GNEGeometryPointDialog)

public:
    /// @brief constructor
    GNEGeometryPointDialog(GNEViewNet* viewNet, Position* pos);

    /// @brief destructor
    ~GNEGeometryPointDialog();

    /// @name FOX-callbacks
    /// @{
    /// @brief event after press accept button
    long onCmdAccept(FXObject* sender, FXSelector sel, void* ptr);

    /// @brief event after press cancel button
    long onCmdCancel(FXObject* sender, FXSelector sel, void* ptr);

    /// @brief event after press cancel button
    long onCmdReset(FXObject*, FXSelector, void*);

    /// @brief event after press a key
    long onKeyPress(FXObject* sender, FXSelector sel, void* ptr);

    /// @brief event after release a key
    long onKeyRelease(FXObject* sender, FXSelector sel, void* ptr);

    /// @}

protected:
    /// @brief FOX need this
    FOX_CONSTRUCTOR(GNEGeometryPointDialog)

    /// @brief viewNet
    GNEViewNet* myViewNet;

    /// @brief position to be edited
    Position* myPos;

    /// @brief original position (used for reset)
    const Position myOriginalPos;

    /// @brief execute dialog as modal
    FXint openAsModalDialog(FXuint placement = PLACEMENT_CURSOR);

private:
    /// @brief accept button
    FXButton* myAcceptButton;

    /// @brief cancel button
    FXButton* myCancelButton;

    /// @brief cancel button
    FXButton* myResetButton;

    /// @brief Invalidated copy constructor
    GNEGeometryPointDialog(const GNEGeometryPointDialog&) = delete;

    /// @brief Invalidated assignment operator
    GNEGeometryPointDialog& operator=(const GNEGeometryPointDialog&) = delete;
};
