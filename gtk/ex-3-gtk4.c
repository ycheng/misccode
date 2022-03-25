#include <gtk/gtk.h>

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

  // ex_set_atk_name_description(window, "w_name", "w_desc");

  entry_box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);
  // gtk_container_add (GTK_CONTAINER (window), entry_box); // gtk3
  gtk_window_set_child (GTK_WINDOW (window), entry_box); // gtk4

  entry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(entry),"Email");
  // TODO:
  // gtk_widget_class_set_accessible_role(GTK_WIDGET(entry), GTK_ACCESSIBLE_ROLE_INPUT);

  gtk_box_append(GTK_BOX(entry_box), entry); // gtk4
  // gtk_container_add(GTK_CONTAINER(entry_box), entry);

  // ex_set_atk_name_description(entry, "w_entry", "w_entry");

  // gtk_widget_show_all (window); // gtk3
  gtk_widget_show (window); // gtk4
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
