/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WIREDDEVICE_H
#define WIREDDEVICE_H

#include "networkdevice.h"

#include <QJsonObject>
#include <QDBusObjectPath>

namespace dde {

namespace network {

class WiredDevice : public NetworkDevice
{
    Q_OBJECT

public:
    explicit WiredDevice(const QJsonObject &info, QObject *parent = 0);

    void setConnections(const QList<QString> &connections);
    const QList<QString> connections() const { return m_connections; }
    inline const QJsonObject activeConnection() const { return m_activeConnection; }
    inline const QString activeConnName() const { return m_activeConnection.value("ConnectionName").toString(); }
    inline const QString activeConnUuid() const { return m_activeConnection.value("ConnectionUuid").toString(); }
    inline const QString activeConnSettingPath() const { return m_activeConnection.value("SettingPath").toString(); }

Q_SIGNALS:
    void connectionsChanged(const QList<QString> &connPaths) const;
    void activeConnectionChanged(const QJsonObject &connInfo) const;

public Q_SLOTS:
    void onActiveConnectionChanged(const QJsonObject &connInfo);

private:
    QJsonObject m_activeConnection;
    QList<QString> m_connections;
};

}

}

#endif // WIREDDEVICE_H