/***************************************************************************
 *   Project TUPI: Magia 2D                                                *
 *   Project Contact: info@maefloresta.com                                 *
 *   Project Website: http://www.maefloresta.com                           *
 *   Project Leader: Gustav Gonzalez <info@maefloresta.com>                *
 *                                                                         *
 *   Developers:                                                           *
 *   2010:                                                                 *
 *    Gustavo Gonzalez                                                     *
 *                                                                         *
 *   KTooN's versions:                                                     * 
 *                                                                         *
 *   2006:                                                                 *
 *    David Cuadrado                                                       *
 *    Jorge Cuadrado                                                       *
 *   2003:                                                                 *
 *    Fernado Roldan                                                       *
 *    Simena Dinas                                                         *
 *                                                                         *
 *   Copyright (C) 2010 Gustav Gonzalez - http://www.maefloresta.com       *
 *   License:                                                              *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#include "tupbrushstatus.h"

TupBrushStatus::TupBrushStatus(const QString &label, const QPixmap &pix, bool bg)
{
    background = bg;
    buttonIsChecked = false;

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(2);
    layout->setSpacing(2);

    brushCell = new TColorCell(TColorCell::Contour, QBrush(Qt::black), QSize(20, 20));
    connect(brushCell, SIGNAL(clicked(TColorCell::FillType)), this, SLOT(updateColour(TColorCell::FillType)));

    QLabel *icon = new QLabel("");
    icon->setToolTip(label);
    icon->setPixmap(pix);

    layout->addWidget(icon);
    layout->addSpacing(3);
    layout->addWidget(brushCell);
}

TupBrushStatus::~TupBrushStatus()
{
}

void TupBrushStatus::setForeground(const QPen &pen)
{
    brushCell->setBrush(pen.brush());
}

void TupBrushStatus::setColor(const QColor &color)
{
    QBrush square(color);
    brushCell->setBrush(square);
}

void TupBrushStatus::updateColour(TColorCell::FillType)
{
    if (background) {
        QColor color = QColorDialog::getColor(brushCell->color(), this);
        if (color.isValid()) {
            setColor(color);
            emit colorUpdated(color);
        }
        brushCell->setChecked(false);
    } else {
        if (buttonIsChecked) {
            brushCell->setChecked(false);
            buttonIsChecked = false;
        } else {
            buttonIsChecked = true;
        }
        emit colorRequested();
    }
}

void TupBrushStatus::setTooltip(const QString &tip)
{
    brushCell->setToolTip(tip);
}

void TupBrushStatus::updateContourColorButton(bool status)
{
    brushCell->setChecked(status);
    buttonIsChecked = status;
}
