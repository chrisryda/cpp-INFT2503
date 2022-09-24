#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry firstname_entry;
  Gtk::Entry lastname_entry;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
    set_title("Exercise 4");
    set_size_request(400, 400);

    firstname_entry.set_placeholder_text("First name");
    lastname_entry.set_placeholder_text("Last name");

    button.set_label("Combine names");
    button.set_sensitive(false);

    vbox.pack_start(firstname_entry);
    vbox.pack_start(lastname_entry);
    vbox.pack_start(button);
    vbox.pack_start(label);

    add(vbox);
    show_all();

    firstname_entry.signal_changed().connect([this]() {
      if (firstname_entry.get_text().size() == 0) {
        button.set_sensitive(false);
      }
      if (firstname_entry.get_text().size() != 0 && lastname_entry.get_text().size() != 0) {
        button.set_sensitive(true);
      }
    });

    lastname_entry.signal_changed().connect([this]() {
      if (lastname_entry.get_text().size() == 0) {
        button.set_sensitive(false);
      }

      if (firstname_entry.get_text().size() != 0 && lastname_entry.get_text().size() != 0) {
        button.set_sensitive(true);
      }
    });

    button.signal_clicked().connect([this]() {
      label.set_text("Names combined: " + firstname_entry.get_text() + " " + lastname_entry.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
