#include <gtk/gtk.h>

static GtkBuilder      *builder; 
static GtkWidget       *window;
static GError          *error;
 
int main(int argc, char *argv[])
{
    /* Init GTK+ */ 
    gtk_init(&argc, &argv);
 
    /* Create new GtkBuilder object */
    builder = gtk_builder_new();

    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if( !gtk_builder_add_from_file( builder, "glade/window_main.glade", &error ) )
    {
        g_warning("%s", error->message);
        g_free(error);
        return(1);
    }
 
    /* Get main window pointer from UI */
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );
 
    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show( window );               

    /* Start main loop */
    gtk_main();
 
    return 0;
}
 
// called when window is closed
void on_window_main_destroy()
{
    /* Destroy builder, since we don't need it anymore */
    g_object_unref( G_OBJECT( builder ) );

    gtk_main_quit();
}