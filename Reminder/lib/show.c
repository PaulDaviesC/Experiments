#include <libnotify/notify.h>
#include <glib.h>
#include <unistd.h>
int display(char *title, char* content)
{
        NotifyNotification *n;
        notify_init("Test");
        n = notify_notification_new (title,content, NULL);
        notify_notification_set_timeout (n, 1); 
        if (!notify_notification_show (n, NULL)) 
            return -1;
        g_object_unref(G_OBJECT(n));
	return 0;
}
