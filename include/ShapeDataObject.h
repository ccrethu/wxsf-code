/***************************************************************
 * Name:      ShapeDataObject.h
 * Purpose:   Defines shape data object class
 * Author:    Michal Bližňák (michal.bliznak@tiscali.cz)
 * Created:   2007-07-22
 * Copyright: Michal Bližňák
 * License:   wxWidgets license (www.wxwidgets.org)
 * Notes:
 **************************************************************/

#pragma once

#include "ShapeCanvas.h"

/*!
 * \brief Class encapsulating data object used during clipboard operations with shapes.
 */
class wxSFShapeDataObject : public wxDataObjectSimple
{
public:
    /*!
     * \brief Default constructor
     * \param format Data format
     */
	wxSFShapeDataObject(const wxDataFormat& format);
    /*!
     * \brief User constructor
     * \param format Data format
     * \param selection List of shapes which should be stored in the data object
     * \param canvas Pointer to shape canvas which manages stored shapes
     */
	wxSFShapeDataObject(const wxDataFormat& format, const CShapeList& selection, wxSFShapeCanvas* canvas);
	/*! \brief Destructor */
	virtual ~wxSFShapeDataObject(void);

    /*! \brief Function returns sizes of the data object */
	virtual size_t GetDataSize() const;
	/*!
	 * \brief Function should export data from data object to given buffer.
	 * \param buf External output data buffer
	 * \return TRUE on success, otherwise FALSE
	 */
	virtual bool GetDataHere(void* buf) const;
	/*!
	 * \brief Function should inport data from data object from given buffer.
	 * \param len Data lenght
	 * \param buf External input data buffer
	 * \return TRUE on success, otherwise FALSE
	 */
	virtual bool SetData(size_t len, const void* buf);

	wxTextDataObject m_Data;

protected:

    /*!
     * \brief Serialize shapes to data object.
     * \param selection List of shapes which should be serialized
     * \param canvas Parent shape canvas
     * \return String containing serialized information
     */
	wxString SerializeSelectedShapes(const CShapeList& selection, wxSFShapeCanvas* canvas);

};