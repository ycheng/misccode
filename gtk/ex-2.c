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

  entry_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), entry_box);
  // gtk_container_add (GTK_CONTAINER (window), entry_box); // gtk4

  entry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(entry),"Email");

  // gtk_window_set_child (GTK_WINDOW (window), entry); // gtk4
  gtk_container_add(GTK_CONTAINER(entry_box), entry);

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
