/**********************************************************
 * Version $Id$
 *********************************************************/

///////////////////////////////////////////////////////////
//                                                       //
//                         SAGA                          //
//                                                       //
//      System for Automated Geoscientific Analyses      //
//                                                       //
//                     Tool Library                      //
//                     Grid_Gridding                     //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//                   TLB_Interface.cpp                   //
//                                                       //
//                 Copyright (C) 2003 by                 //
//                      Olaf Conrad                      //
//                                                       //
//-------------------------------------------------------//
//                                                       //
// This file is part of 'SAGA - System for Automated     //
// Geoscientific Analyses'. SAGA is free software; you   //
// can redistribute it and/or modify it under the terms  //
// of the GNU General Public License as published by the //
// Free Software Foundation; version 2 of the License.   //
//                                                       //
// SAGA is distributed in the hope that it will be       //
// useful, but WITHOUT ANY WARRANTY; without even the    //
// implied warranty of MERCHANTABILITY or FITNESS FOR A  //
// PARTICULAR PURPOSE. See the GNU General Public        //
// License for more details.                             //
//                                                       //
// You should have received a copy of the GNU General    //
// Public License along with this program; if not,       //
// write to the Free Software Foundation, Inc.,          //
// 51 Franklin Street, 5th Floor, Boston, MA 02110-1301, //
// USA.                                                  //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//    e-mail:     oconrad@saga-gis.org                   //
//                                                       //
//    contact:    Olaf Conrad                            //
//                Institute of Geography                 //
//                University of Goettingen               //
//                Goldschmidtstr. 5                      //
//                37077 Goettingen                       //
//                Germany                                //
//                                                       //
///////////////////////////////////////////////////////////

//---------------------------------------------------------


///////////////////////////////////////////////////////////
//														 //
//           The Tool Link Library Interface             //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
// 1. Include the appropriate SAGA-API header...

#include "MLB_Interface.h"


//---------------------------------------------------------
// 2. Place general tool library informations here...

CSG_String Get_Info(int i)
{
	switch( i )
	{
	case TLB_INFO_Name:	default:
		return( _TL("Gridding") );

	case TLB_INFO_Category:
		return( _TL("Grid") );

	case TLB_INFO_Author:
		return( SG_T("O. Conrad (c) 2002-10") );

	case TLB_INFO_Description:
		return( _TL("Tools for the gridding of points and other vector data.") );

	case TLB_INFO_Version:
		return( SG_T("1.0") );

	case TLB_INFO_Menu_Path:
		return( _TL("Grid|Gridding") );
	}
}


//---------------------------------------------------------
// 3. Include the headers of your tools here...

#include "Interpolation_InverseDistance.h"
#include "Interpolation_AngularDistance.h"
#include "Interpolation_NearestNeighbour.h"
#include "Interpolation_NaturalNeighbour.h"
#include "Interpolation_Shepard.h"
#include "Interpolation_Triangulation.h"
#include "Shapes2Grid.h"
#include "kernel_density.h"
#include "grid_cell_polygon_coverage.h"


//---------------------------------------------------------
// 4. Allow your tools to be created here...

CSG_Tool *		Create_Tool(int i)
{
	switch( i )
	{
	case  0:	return( new CShapes2Grid );

	case  1:	return( new CInterpolation_InverseDistance );
	case  7:	return( new CInterpolation_AngularDistance );
	case  2:	return( new CInterpolation_NearestNeighbour );
	case  3:	return( new CInterpolation_NaturalNeighbour );
	case  4:	return( new CInterpolation_Shepard );
	case  5:	return( new CInterpolation_Triangulation );

	case  6:	return( new CKernel_Density );

	case  8:	return( new CGrid_Cell_Polygon_Coverage );

	//-----------------------------------------------------
	case 10:	return( NULL );
	default:	return( TLB_INTERFACE_SKIP_TOOL );
	}
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
//{{AFX_SAGA

	TLB_INTERFACE

//}}AFX_SAGA
