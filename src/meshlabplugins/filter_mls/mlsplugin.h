/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#ifndef MLSPLUGIN_H
#define MLSPLUGIN_H

#include <QObject>

#include <common/interfaces/filter_plugin_interface.h>

class MlsPlugin : public QObject, public FilterPluginInterface
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_INTERFACE_IID)
	Q_INTERFACES(FilterPluginInterface)

public:

	enum {
		_RIMLS_       = 0x1,
		_APSS_        = 0x2,
		_PROJECTION_  = 0x1000,
		_AFRONT_      = 0x2000,
		_MCUBE_       = 0x4000,
		_COLORIZE_    = 0x8000,

		FP_RIMLS_PROJECTION = _RIMLS_ | _PROJECTION_,
		FP_APSS_PROJECTION	= _APSS_  | _PROJECTION_,

		FP_RIMLS_AFRONT = _RIMLS_ | _AFRONT_,
		FP_APSS_AFRONT  = _APSS_  | _AFRONT_,

		FP_RIMLS_MCUBE = _RIMLS_ | _MCUBE_,
		FP_APSS_MCUBE  = _APSS_  | _MCUBE_,

		FP_RIMLS_COLORIZE = _RIMLS_ | _COLORIZE_,
		FP_APSS_COLORIZE  = _APSS_  | _COLORIZE_,

		FP_RADIUS_FROM_DENSITY       = 0x10000,
		FP_SELECT_SMALL_COMPONENTS   = 0x20000
	};

	MlsPlugin();

	QString pluginName() const;
	virtual QString filterName(FilterIDType filter) const;
	virtual QString filterInfo(FilterIDType filter) const;
	FilterClass getClass(const QAction *a) const;
	virtual void initParameterList(const QAction*, MeshDocument &md, RichParameterList &parent);
    virtual int getRequirements(const QAction* action);
    virtual bool applyFilter(const QAction* filter, MeshDocument &m, std::map<std::string, QVariant>& outputValues, unsigned int& postConditionMask, const RichParameterList &parent, vcg::CallBackPos *cb) ;
	FILTER_ARITY filterArity(const QAction *) const {return SINGLE_MESH;}
};

#endif
