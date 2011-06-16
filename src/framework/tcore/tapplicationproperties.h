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
 *   the Free Software Foundation; either version 3 of the License, or     *
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

#ifndef KAPPLICATIONPROPERTIES_H
#define KAPPLICATIONPROPERTIES_H

#include <QString>
#include "tglobal.h"

/**
 * @author David Cuadrado
*/

class K_CORE_EXPORT TApplicationProperties
{
    protected:
        TApplicationProperties();
        virtual ~TApplicationProperties();

    public:
        void setShareDir(const QString &path);
        void setDataDir(const QString &path);
        void setHomeDir(const QString &path);
        void setThemeDir(const QString &path);
        void setPluginDir(const QString &path);
        void setCacheDir(const QString &path);
        void setVersion(const QString &path);
        void setCodeName(const QString &path);
        void setRevision(const QString &path);

        virtual QString shareDir() const;
        virtual QString dataDir() const;
        virtual QString homeDir() const;
        virtual QString themeDir() const;
        virtual QString pluginDir() const;
        virtual QString configDir() const;
        virtual QString cacheDir() const;
        virtual QString version() const;
        virtual QString codeName() const;
        virtual QString revision() const;

        static TApplicationProperties *instance();
		
    private:
        static TApplicationProperties *s_instance;

    struct Private;
        Private *const k;
};

#define kAppProp TApplicationProperties::instance()

#endif