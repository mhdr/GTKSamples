#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void clicked(GtkWidget *widget,gpointer data)
{
    g_print("Hello World\n");
}

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
