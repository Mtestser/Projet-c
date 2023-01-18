// My Application
//
// By (Your name)

// Libraries
#include <gtk/gtk.h> // GTK Library
#include <stdio.h> // C IO Library (Not needed)

// Variables
GtkWidget *window; // Window
GtkLabel *mylabel; // Label

// Main function
int main(int argc, char *argv[])
{
	GtkBuilder *builder; // GTK Builder variable
	gtk_init(&argc, &argv); // Start GTK

	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "myui.glade", NULL); // Load our UI file

	// Assign the Variables
	window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow")); // Load our window named MyWindow
	mylabel = GTK_LABEL(gtk_builder_get_object(builder, "MyLabel")); // Load our label named MyLabel

	// Essential for a GTK based program
	gtk_builder_connect_signals(builder, NULL); 
	g_object_unref(builder);
	
	gtk_widget_show_all(window); // Show our window
	gtk_main(); // Run our program

	return 0; // Necessary for a c main function
}

// Function to exit our app
void exit_app()
{
	printf("Exit app \n"); // Not neccesary
	gtk_main_quit(); // Command to quit a GTK program
}

// Function when our button is pressed
void button_clicked()
{
	printf("Button clicked \n");
	gtk_label_set_text(mylabel, "Hello World");
}
 
