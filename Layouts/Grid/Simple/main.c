#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void clicked(GtkWidget *widget,gpointer data)
{
    g_print("Hello World\n");
}

static void activate(GtkApplication *app,gpointer user_data)
{
    GtkWidget *window= gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"Grid");
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_widget_destroy),NULL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    GtkWidget *grid=gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window),grid);

    GtkWidget *button1=gtk_button_new_with_label("Button1");
    g_signal_connect(button1,"clicked",G_CALLBACK(clicked),NULL);
    gtk_grid_attach(GTK_GRID(grid),button1,0,0,1,1);

    GtkWidget *button2=gtk_button_new_with_label("Button2");
    g_signal_connect(button2,"clicked",G_CALLBACK(clicked),NULL);
    gtk_grid_attach(GTK_GRID(grid),button2,1,0,1,1);

    GtkWidget *button3=gtk_button_new_with_label("Quit");
    g_signal_connect(button3,"clicked",G_CALLBACK(gtk_main_quit),NULL);
    gtk_grid_attach(GTK_GRID(grid),button3,0,1,2,1);

    gtk_widget_show_all(window);
}

int main(int argc,char **argv)
{
    GtkApplication *app= gtk_application_new("orh.gtk.example",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app,"activate",G_CALLBACK(activate),NULL);
    int status= g_application_run(G_APPLICATION(app),argc,argv);
    return status;
}

/**<
int main(int argc,char **argv)
{
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid=gtk_grid_new();
    GtkWidget *button1=gtk_button_new_with_label("Button1");
    GtkWidget *button2=gtk_button_new_with_label("Button2");
    GtkWidget *button3=gtk_button_new_with_label("Quit");

    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    gtk_window_set_title(GTK_WINDOW(window),"Grid");
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect(button1,"clicked",G_CALLBACK(clicked),NULL);
    g_signal_connect(button2,"clicked",G_CALLBACK(clicked),NULL);
    g_signal_connect(button3,"clicked",G_CALLBACK(gtk_main_quit),NULL);

    gtk_container_add(GTK_CONTAINER(window),grid);
    gtk_grid_attach(GTK_GRID(grid),button1,0,0,1,1);
    gtk_grid_attach(GTK_GRID(grid),button1,1,0,1,1);
    gtk_grid_attach(GTK_GRID(grid),button1,0,1,2,1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
 */

