#include <gtk/gtk.h>
#include <atk/atk.h>

/**
 * ex_utils_set_atk_name_description:
 * was taken from gedit:gedit_utils_set_atk_name_description.
 * With this one added and set, OSK works on 22.04.
 * @widget: The Gtk widget for which name/description to be set
 * @name: Atk name string
 * @description: Atk description string
 *
 * This function sets up name and description
 * for a specified gtk widget.
 */
void
ex_set_atk_name_description (GtkWidget   *widget,
                                      const gchar *name,
                                      const gchar *description)
{
        AtkObject *aobj;

        aobj = gtk_widget_get_accessible (widget);

        if (!(GTK_IS_ACCESSIBLE (aobj)))
                return;

        if (name)
                atk_object_set_name (aobj, name);

        if (description)
                atk_object_set_description (aobj, description);
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *entry;
  GtkWidget *entry_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  ex_set_atk_name_description(window, "w_name", "w_desc");

  entry_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), entry_box);
  // gtk_container_add (GTK_CONTAINER (window), entry_box); // gtk4

  entry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(entry),"Email");

  // gtk_window_set_child (GTK_WINDOW (window), entry); // gtk4
  gtk_container_add(GTK_CONTAINER(entry_box), entry);

  ex_set_atk_name_description(entry, "w_entry", "w_entry");

  gtk_widget_show_all (window);
  // gtk_widget_show (window); // gtk4?
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
