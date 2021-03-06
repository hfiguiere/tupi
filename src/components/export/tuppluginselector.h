/***************************************************************************
 *   Project TUPI: Magia 2D                                                *
 *   Project Contact: info@maefloresta.com                                 *
 *   Project Website: http://www.maefloresta.com                           *
 *   Project Leader: Gustav Gonzalez <info@maefloresta.com>                *
 *                                                                         *
 *   Developers:                                                           *
 *   2010:                                                                 *
 *    Gustavo Gonzalez / xtingray                                          *
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

#ifndef TUPPLUGINSELECTOR_H
#define TUPPLUGINSELECTOR_H

#include "tglobal.h"
#include "tupexportinterface.h"
#include "tupexportwizard.h"

#include <QListWidget>
#include <QListWidgetItem>

class TUPI_EXPORT TupPluginSelector : public TupExportWizardPage
{
    Q_OBJECT

    public:
        TupPluginSelector();
        ~TupPluginSelector();

        bool isComplete() const;
        const char *extension;

        void reset();
        void addPlugin(const QString &plugin);
        void setFormats(TupExportInterface::Formats formats);

    public slots:
        void selectedPluginItem(QListWidgetItem *);
        void selectFirstItem();
        void selectedFormatItem(QListWidgetItem *);
        const char* getFileExtension();

    signals:
        void selectedPlugin(const QString &plugin);
        void animationFormatSelected(int format, const QString &extension);
        void animatedImageFormatSelected(int format, const QString &extension);
        void imagesArrayFormatSelected(int format, const QString &extension);

    private:
        QListWidget *m_exporterList;
        QListWidget *m_formatList;
        const char* getFormatExtension(const QString format);
};

#endif
