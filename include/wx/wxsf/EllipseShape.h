/***************************************************************
 * Name:      EllipseShape.h
 * Purpose:   Defines ellipse shape class
 * Author:    Michal Bližňák (michal.bliznak@tiscali.cz)
 * Created:   2007-07-22
 * Copyright: Michal Bližňák
 * License:   wxWidgets license (www.wxwidgets.org)
 * Notes:
 **************************************************************/

#ifndef _WXSFELLIPSESHAPE_H
#define _WXSFELLIPSESHAPE_H

#include "RectShape.h"

/// <summary> Class encapsulating the ellipse shape. It extends the basic rectangular shape. </summary>
/// <seealso cref="wxSFRectShape"></seealso>
class WXDLLIMPEXP_SF wxSFEllipseShape : public wxSFRectShape
{
public:
    XS_DECLARE_CLONABLE_CLASS(wxSFEllipseShape);

    /// <summary> Default constructor </summary>
    wxSFEllipseShape(void);
    /// <summary> User constructor </summary>
    /// <param name="pos"> Initial position </param>
    /// <param name="size"> Initial size </param>
    /// <param name="manager"> Pointer to parent diagram manager </param>
	wxSFEllipseShape(const wxRealPoint& pos, const wxRealPoint& size, wxSFDiagramManager* manager);
	/// <summary> Copy constructor </summary>
	/// <param name="obj"> Reference to the source shape </param>
	wxSFEllipseShape(const wxSFEllipseShape& obj);
	/// <summary> Destructor </summary>
    virtual ~wxSFEllipseShape();

    // public virtual functions
    /// <summary> Test whether the given point is inside the shape. The function
    /// can be overrided if neccessary. </summary>
    /// <param name="pos"> Examined point </param>
    /// <returns> TRUE if the point is inside the shape area, otherwise FALSE </returns>
    virtual bool IsInside(const wxPoint& pos);
	/// <summary> Get intersection point of the shape border and a line leading from
	/// the shape's center to the given point. The function can be overrided if neccessary. </summary>
	/// <param name="to"> Ending point of the virtual intersection line </param>
	/// <returns> Intersection point </returns>
    virtual wxRealPoint GetBorderPoint(const wxRealPoint& to);

protected:

    // protected virtual functions
	/// <summary> Draw the shape in the normal way. The function can be overrided if neccessary. </summary>
	/// <param name="dc"> Reference to device context where the shape will be drawn to </param>
	virtual void DrawNormal(wxDC& dc);
	/// <summary> Draw the shape in the hower mode (the mouse cursor is above the shape). The function can be overrided if neccessary. </summary>
	/// <param name="dc"> Reference to device context where the shape will be drawn to </param>
	virtual void DrawHover(wxDC& dc);
	/// <summary> Draw the shape in the highlighted mode (another shape is dragged over this shape and this shape will accept the dragged one if it will be dropped on it). The function can be overrided if neccessary. </summary>
	/// <param name="dc"> Reference to device context where the shape will be drawn to </param>
	virtual void DrawHighlighted(wxDC& dc);
	/*!
	 * \brief Draw shadow under the shape. The function can be overrided if neccessary.
	 * \param dc Reference to device context where the shadow will be drawn to
	 */
	virtual void DrawShadow(wxDC& dc);
};

#endif //_WXSFELLIPSESHAPE_H
