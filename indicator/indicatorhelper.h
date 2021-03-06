/*
 * SPDX-FileCopyrightText: 2019 Weixuan XIAO <veyx.shaw@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
 */

#ifndef INDICATORHELPER_H
#define INDICATORHELPER_H

#include <QProcess>
#include <QSplashScreen>

#ifdef QSYSTRAY
#include <QSystemTrayIcon>
#else
#include <KStatusNotifierItem>
#endif

#ifdef Q_OS_WIN
#include <QUrl>
    namespace processes {
            const QString dbus_daemon = QStringLiteral("dbus-daemon.exe");
            const QString kdeconnect_daemon = QStringLiteral("kdeconnectd.exe");
    };
#endif

class IndicatorHelper
{
public:
    IndicatorHelper();
    ~IndicatorHelper();

    void preInit();
    void postInit();

    void iconPathHook();

    int daemonHook(QProcess &kdeconnectd);

#ifdef QSYSTRAY
    void systrayIconHook(QSystemTrayIcon &systray);
#else
    void systrayIconHook(KStatusNotifierItem &systray);
#endif

#ifdef Q_OS_WIN
    /**
     * Terminate processes of KDE Connect like kdeconnectd.exe and dbus-daemon.exe
     *
     * @return True if termination was successful, false otherwise
     */

    bool terminateProcess(const QString &processName, const QUrl &indicatorUrl) const;
#endif

private:
#ifdef Q_OS_MAC
    QSplashScreen *m_splashScreen;
#endif
};

#endif
