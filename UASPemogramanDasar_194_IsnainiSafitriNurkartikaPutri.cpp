#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Task {
public:
    string title;
    string dueDate;

    Task(string t, string d) : title(t), dueDate(d) {}
};

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Belum ada tugas yang ditambahkan." << endl;
        return;
    }
    cout << "\nDaftar Tugas Kuliah:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].title << " - Batas Waktu: " << tasks[i].dueDate << endl;
    }
}

void addTask(vector<Task>& tasks) {
    string title, dueDate;
    cout << "\nMasukkan judul tugas: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input sebelumnya
    getline(cin, title);
    cout << "Masukkan batas waktu (dd/mm/yyyy): ";
    getline(cin, dueDate);
    tasks.push_back(Task(title, dueDate));
    cout << "Tugas berhasil ditambahkan!" << endl;
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Belum ada tugas yang bisa dihapus." << endl;
        return;
    }
    displayTasks(tasks);
    int index;
    cout << "Masukkan nomor tugas yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Tugas berhasil dihapus!" << endl;
    } else {
        cout << "Nomor tugas tidak valid." << endl;
    }
}

void editTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Belum ada tugas yang bisa diedit." << endl;
        return;
    }
    displayTasks(tasks);
    int index;
    cout << "Masukkan nomor tugas yang ingin diedit: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        string newTitle, newDueDate;
        cout << "Masukkan judul tugas baru: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newTitle);
        cout << "Masukkan batas waktu baru (dd/mm/yyyy): ";
        getline(cin, newDueDate);
        tasks[index - 1].title = newTitle;
        tasks[index - 1].dueDate = newDueDate;
        cout << "Tugas berhasil diedit!" << endl;
    } else {
        cout << "Nomor tugas tidak valid." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\nAplikasi Pengingat Tugas Kuliah" << endl;
        cout << "1. Tambah Tugas" << endl;
        cout << "2. Lihat Tugas" << endl;
        cout << "3. Hapus Tugas" << endl;
        cout << "4. Edit Tugas" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            displayTasks(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            editTask(tasks);
            break;
        case 5:
            cout << "Keluar dari aplikasi." << endl;
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}
