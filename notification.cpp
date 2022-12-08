#include "notification.h"

notification::notification()
{

}


void notification::notification_ajout()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("VOYAGEUR ","nouveauelle VOYAGEUR a  ete ajoutée ",QSystemTrayIcon::Information,15000);

}



void notification::notification_modifier()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("VOYAGEUR ","VOYAGEUR a  ete modifier ",QSystemTrayIcon::Information,15000);

}


void notification::notification_supprimer()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("VOYAGEUR ","VOYAGEUR a  ete supprimer ",QSystemTrayIcon::Information,15000);

}
