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

#ifndef SAMPLEFILTERSPLUGIN_H
#define SAMPLEFILTERSPLUGIN_H

#include <common/interfaces.h>

class FilterScreenedPoissonPlugin : public QObject, public MeshFilterInterface
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(MESH_FILTER_INTERFACE_IID)
	Q_INTERFACES(MeshFilterInterface)
public:

	enum {
		FP_SCREENED_POISSON
	};

	FilterScreenedPoissonPlugin();
	~FilterScreenedPoissonPlugin();

	QString pluginName() const;
	QString filterName(FilterIDType filter) const;
	QString filterInfo(FilterIDType filter) const;

	FilterClass getClass(QAction* a);
	int getRequirements(QAction* a);

	bool applyFilter(
			QAction* filter,
			MeshDocument& md,
			const RichParameterList& params,
			vcg::CallBackPos* cb) ;

	void initParameterSet(QAction* a, MeshModel&, RichParameterList& parlist);
	int postCondition(QAction* filter) const;
	FILTER_ARITY filterArity(QAction*) const;
};


#endif
